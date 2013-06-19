//###########################################################################
//
// FILE:   DSP2833x_SysCtrl.c
//
// TITLE:  DSP2833x Device System Control Initialization & Support Functions.
//
// DESCRIPTION:
//
//         Example initialization of system resources.
//
//###########################################################################


#include "28335_II_Device.h"     // Headerfile Include File
#include "DMA_Xintf_to_RAM.h"   // DSP2833x Examples Include File

// Functions that will be run from RAM need to be assigned to
// a different section.  This section will then be mapped to a load and
// run address using the linker cmd file.

#pragma CODE_SECTION(InitFlash, "ramfuncs");

//---------------------------------------------------------------------------
// InitSysCtrl:
//---------------------------------------------------------------------------
// This function initializes the System Control registers to a known state.
// - Disables the watchdog
// - Set the PLLCR for proper SYSCLKOUT frequency
// - Set the pre-scaler for the high and low frequency peripheral clocks
// - Enable the clocks to the peripherals

void InitSysCtrl(void)
{

   // Disable the watchdog
   DisableDog();

   // Initialize the PLL control: PLLCR and DIVSEL
   // DSP28_PLLCR and DSP28_DIVSEL are defined in DSP2833x_Examples.h
   InitPll(DSP28_PLLCR,DSP28_DIVSEL);

   // Initialize the peripheral clocks
   InitPeripheralClocks();
}


//---------------------------------------------------------------------------
// Example: InitFlash:
//---------------------------------------------------------------------------
// This function initializes the Flash Control registers

//                   CAUTION
// This function MUST be executed out of RAM. Executing it
// out of OTP/Flash will yield unpredictable results

void InitFlash(void)
{
   EALLOW;
   //Enable Flash Pipeline mode to improve performance
   //of code executed from Flash.
   FlashRegs.FOPT.bit.ENPIPE = 1;

   //                CAUTION
   //Minimum waitstates required for the flash operating
   //at a given CPU rate must be characterized by TI.
   //Refer to the datasheet for the latest information.
#if CPU_FRQ_150MHZ
   //Set the Paged Waitstate for the Flash
   FlashRegs.FBANKWAIT.bit.PAGEWAIT = 5;

   //Set the Random Waitstate for the Flash
   FlashRegs.FBANKWAIT.bit.RANDWAIT = 5;

   //Set the Waitstate for the OTP
   FlashRegs.FOTPWAIT.bit.OTPWAIT = 8;
#endif

#if CPU_FRQ_100MHZ
   //Set the Paged Waitstate for the Flash
   FlashRegs.FBANKWAIT.bit.PAGEWAIT = 3;

   //Set the Random Waitstate for the Flash
   FlashRegs.FBANKWAIT.bit.RANDWAIT = 3;

   //Set the Waitstate for the OTP
   FlashRegs.FOTPWAIT.bit.OTPWAIT = 5;
#endif
   //                CAUTION
   //ONLY THE DEFAULT VALUE FOR THESE 2 REGISTERS SHOULD BE USED
   FlashRegs.FSTDBYWAIT.bit.STDBYWAIT = 0x01FF;
   FlashRegs.FACTIVEWAIT.bit.ACTIVEWAIT = 0x01FF;
   EDIS;

   //Force a pipeline flush to ensure that the write to
   //the last register configured occurs before returning.

   asm(" RPT #7 || NOP");
}


//---------------------------------------------------------------------------
// Example: ServiceDog
//---------------------------------------------------------------------------
// This function resets the watchdog timer.
// Enable this function for using ServiceDog in the application

void ServiceDog(void)
{
    EALLOW;
    SysCtrlRegs.WDKEY = 0x0055;
    SysCtrlRegs.WDKEY = 0x00AA;
    EDIS;
}

//---------------------------------------------------------------------------
// Example: DisableDog
//---------------------------------------------------------------------------
void DisableDog(void)
{
    EALLOW;
	// Function	 : 000	for	WDPS	(bit0 - bit2) 
	//			   101 	for	WDCHK	(bit3 - bit5: You must ALWAYS write 1,0,1 to these bits unless you want to reset the device)  
	//			   1   	for	WDDIS	(bit6: To disable the watchdog)
	//             0   	for	WDFLAG	(bit7: reset status Flag bit = 0)
    SysCtrlRegs.WDCR= 0x0068;  
    EDIS;
}


//---------------------------------------------------------------------------
// Example: InitPll:
// This function initializes the PLLCR register following the sequence in the TI datesheet
//---------------------------------------------------------------------------
void InitPll(Uint16 val, Uint16 divsel)
{
   // Step 1: Check if the OSCCLK input signal is missing -- PLL in limp mode(MCLKSTS = 1)
   if (SysCtrlRegs.PLLSTS.bit.MCLKSTS != 0)
   {
      asm(" ESTOP0");	// Replace this line with a call to an appropriate SystemShutdown(); function.
   }

   // Step 2: DIVSEL MUST be 0 before PLLCR can be changed from 0x0000, if not, clear DIVSEL through software
   if (SysCtrlRegs.PLLSTS.bit.DIVSEL != 0)
   {
       EALLOW;
       SysCtrlRegs.PLLSTS.bit.DIVSEL = 0;
       EDIS;
   }

	// Step 3: Set new PLLCR value
	EALLOW;
	SysCtrlRegs.PLLSTS.bit.MCLKOFF = 1;	// Before setting PLLCR turn off missing clock detect logic
	SysCtrlRegs.PLLCR.bit.DIV = val;
	EDIS;
	
	// Wait for the PLL lock bit to be set.
	// The watchdog should be disabled before this loop, or fed within the loop via ServiceDog().
	DisableDog();  // Option 1: Disable the Watchdog 
	
	while(SysCtrlRegs.PLLSTS.bit.PLLLOCKS != 1)
	{
		// ServiceDog();  // Option2: Feed the dog with the waiting loop;
	}

	EALLOW;
	SysCtrlRegs.PLLSTS.bit.MCLKOFF = 0;  // After PLLCR changing success, turn on missing clock detect logic
	EDIS;

    // Step 4: If required, can change the DIVSEL 
	if((divsel == 0) || (divsel == 1) || (divsel == 2))
	{
		EALLOW;
	    SysCtrlRegs.PLLSTS.bit.DIVSEL = divsel;
	    EDIS;
	}

	// ?? Question: DIVSEL = 3 can only be used when PLL is off or bypassed, should PLLCR.DIV be set to 
	// 0x0000, or PLLSTS.bit.PLLOFF be set to 1?
	// If switching to 1/1, first go to 1/2 and let the power settle, then switch to 1/1
	// The time required will depend on the system, this is only an example
	if(divsel == 3)
	{
		EALLOW;
	    SysCtrlRegs.PLLSTS.bit.DIVSEL = 2;
	    DELAY_US(50L);
	    SysCtrlRegs.PLLSTS.bit.DIVSEL = 3;
	    EDIS;
    }
}

//--------------------------------------------------------------------------
// Example: InitPeripheralClocks:
//---------------------------------------------------------------------------
// This function initializes the clocks to the peripheral modules.
// First the high and low clock prescalers are set
// Second the clocks are enabled to each peripheral.
// To reduce power, leave clocks to unused peripherals disabled
//
// Note: If a peripherals clock is not enabled then you cannot
// read or write to the registers for that peripheral

void InitPeripheralClocks(void)
{
   	EALLOW;

   	SysCtrlRegs.PCLKCR3.bit.CPUTIMER0ENCLK = 1; // CPU Timer 0
   	SysCtrlRegs.PCLKCR3.bit.DMAENCLK = 1;       // DMA Clock
   	SysCtrlRegs.PCLKCR3.bit.XINTFENCLK = 1;     // XTIMCLK

   	EDIS;
}

//===========================================================================
// End of file.
//===========================================================================
