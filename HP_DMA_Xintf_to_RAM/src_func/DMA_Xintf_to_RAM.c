//###########################################################################
// Original source by: M.P.
//
// $TI Release: DSP2833x Header Files V1.01 $
// $Release Date: September 26, 2007 $
//###########################################################################

#include "28335_II_Device.h"     // DSP2833x Headerfile Include File
#include "DMA_Xintf_to_RAM.h"   // DSP2833x Examples Include File


#pragma DATA_SECTION(DMABuf1,"DMARAML4");
#pragma DATA_SECTION(DMABuf2,"ZONE6DATA");

volatile Uint16 DMABuf1[BUF_SIZE];
volatile Uint16 DMABuf2[BUF_SIZE];

volatile Uint16 *DMADest;
volatile Uint16 *DMASource;

void main(void)
{
   	Uint16 i;
	
	// Step 1. Initialize System clk and peripheral clk 
   	InitSysCtrl();
   	
   	// Step 2. Initalize Xintf RAM - Zone6
   	InitXintf();
    InitGpio();
   	for (i=0; i<BUF_SIZE; i++)
   	{
    	DMABuf1[i] = 0;
	 	DMABuf2[i] = i;
   	}
   	DMADest   = &DMABuf1[0];
	DMASource = &DMABuf2[0];
   	
   	// Step 3. Initialize all the PIE vector 
   	InitPieVectTable();                            
   	
   	// Step 4. Stop Timer0 for now
   	CpuTimer0Regs.TCR.bit.TSS  = 1;               

	// Step 5. Configure DMA  
	DMAInitialize();
   	DMACH1AddrConfig(DMADest,DMASource);
	DMACH1BurstConfig(31,2,2);         //Will set up to use 32-bit datasize, pointers are based on 16-bit words
	DMACH1TransferConfig(31,2,2);      //so need to increment by 2 to grab the correct location
	DMACH1WrapConfig(0xFFFF,0,0xFFFF,0);	// Diable wrap function
	// Use timer0 to start the x-fer.  
	// Since this is a static copy use one shot mode, so only one trigger is needed
	// Also using 32-bit mode to decrease x-fer time
    DMACH1ModeConfig(DMA_TINT0,PERINT_ENABLE,ONESHOT_ENABLE,CONT_DISABLE,SYNC_DISABLE,SYNC_SRC,OVRFLOW_DISABLE,THIRTYTWO_BIT,CHINT_END,CHINT_ENABLE); 
	StartDMACH1();
    
   	// Step 6. Init Timer 0
   	//directly modify the current 32-bit counter of the timer
   	CpuTimer0Regs.TIM.half.LSW = 0x0001;   // LOW 16 bit for sysclk multiply
   	CpuTimer0Regs.TIM.half.MSW = 0x0000;   // HIGH 16 bit for timerclk multiply
   	CpuTimer0Regs.TPR.bit.TDDR = 0x0001;
   	CpuTimer0Regs.TPRH.bit.TDDRH = 0x0000;	
   	
   	CpuTimer0Regs.TCR.bit.SOFT = 1;      //Allow to free run even if halted
   	CpuTimer0Regs.TCR.bit.FREE = 1; 
   	CpuTimer0Regs.TCR.bit.TSS  = 0;      //restart the timer 0
   	
   	// Step 7. Enable Interrupts
   	EnableInterrupts();
   	
   	for(;;);
}


//===========================================================================
// No more.
//===========================================================================
