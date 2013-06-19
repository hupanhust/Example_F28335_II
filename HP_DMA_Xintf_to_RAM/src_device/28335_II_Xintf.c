//###########################################################################
// $TI Release: DSP2833x Header Files V1.01 $
// $Release Date: September 26, 2007 $
//###########################################################################

#include "28335_II_Device.h"     // DSP2833x Headerfile Include File
#include "DMA_Xintf_to_RAM.h"   // DSP2833x Examples Include File

//---------------------------------------------------------------------------
// InitXINTF:
// This function initializes the External Interface the default reset state.
// Do not modify the timings of the XINTF while running from the XINTF.  
// Doing so can yield unpredictable results
// Any changes to XINTF timing should only be made by code running outside of the XINTF.
//---------------------------------------------------------------------------

void InitXintf(void)
{
	EALLOW;    
 
	// Step 1: Init the XINTF itself
	// All Zones ---------------------------------------------------
	// Wait for XINTF Write Buffer Empty
	while(XintfRegs.XINTCNF2.bit.WLEVEL != 0)
	{;}
	// Timing for all zones based on XTIMCLK = SYSCLKOUT
	XintfRegs.XINTCNF2.bit.XTIMCLK = 0;
	// ?? write buffering 3
	XintfRegs.XINTCNF2.bit.WRBUFF = 3;
	// XCLKOUT = XTIMCLK
	XintfRegs.XINTCNF2.bit.CLKMODE = 0;
	// XCLKOUT is enabled
	XintfRegs.XINTCNF2.bit.CLKOFF = 0;
	
	// Step 2: Init all the Zones separately
	
	// Zone0: CPLD mapped to Zone0 ------------------------------------------
	// 16 bit mode for Zone 0	
	XintfRegs.XTIMING0.bit.XSIZE = 3;
	
    // Zone 6 EXTERAL RAM mapped to Zone6------------------------------------
    // 16 bit data bus
    XintfRegs.XTIMING6.bit.XSIZE = 3;
    // Zone will not sample XREADY signal  
    // XREADY signal ignored
    XintfRegs.XTIMING6.bit.USEREADY = 0;
    // XREADY signal synchronous for the zone
    XintfRegs.XTIMING6.bit.READYMODE = 0;
    // don't double all Zone read/write lead/active/trail timing 
    XintfRegs.XTIMING6.bit.X2TIMING = 0;
    // When not using ready, LEAD must always be 1 or greater 
    // Zone write timing
    XintfRegs.XTIMING6.bit.XWRLEAD = 1;
    XintfRegs.XTIMING6.bit.XWRACTIVE = 3;
    XintfRegs.XTIMING6.bit.XWRTRAIL = 0;
    // Zone read timing
    XintfRegs.XTIMING6.bit.XRDLEAD = 1;
    XintfRegs.XTIMING6.bit.XRDACTIVE = 3; // ?? here the XRDACTIVE value should be 1 or greater!! not as it's mentioned in the datasheet 
    XintfRegs.XTIMING6.bit.XRDTRAIL = 0;   

    // Zone 7------------------------------------
	// Not used here

	EDIS;
	// Wait 8 cycles after configuration
	asm(" RPT #7 || NOP");

}

//===========================================================================
// No more.
//===========================================================================
