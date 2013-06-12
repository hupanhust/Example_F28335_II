// TI File $Revision: /main/5 $
// Checkin $Date: August 16, 2007   11:06:26 $
//###########################################################################
//
// FILE:   DSP2833x_Xintf.c
//
// TITLE:   DSP2833x Device External Interface Init & Support Functions.
//
// DESCRIPTION:
//
//          Example initialization function for the external interface (XINTF).
//          This example configures the XINTF to its default state.  For an
//          example of how this function being used refer to the
//          examples/run_from_xintf project.
//
//###########################################################################
// $TI Release: DSP2833x Header Files V1.01 $
// $Release Date: September 26, 2007 $
//###########################################################################

#include "28335_II_Device.h"     // DSP2833x Headerfile Include File
#include "LED_Flash.h"   // DSP2833x Examples Include File

//---------------------------------------------------------------------------
// InitXINTF:
//---------------------------------------------------------------------------
// This function initializes the External Interface the default reset state.
//
// Do not modify the timings of the XINTF while running from the XINTF.  Doing
// so can yield unpredictable results


/////////////////////////////////////
void InitXintf(void)
{
	// Step 1: Init the XINTF itself
	EALLOW;
	// All Zones ---------------------------------------------------
	// Wait for XINTF Write Buffer Empty
	while(XintfRegs.XINTCNF2.bit.WLEVEL != 0)
	{;}
	// close write buffering
	XintfRegs.XINTCNF2.bit.WRBUFF = 0;
	// XCLKOUT is disabled
	XintfRegs.XINTCNF2.bit.CLKOFF = 1;
	// Zone0: CPLD mapped to Zone0 ---------------------------------
	// 16 bit mode for Zone 0	
	XintfRegs.XTIMING0.bit.XSIZE = 3;
	EDIS;
	// Wait 8 cycles after configuration
	asm(" RPT #7 || NOP");
}

//===========================================================================
// No more.
//===========================================================================
