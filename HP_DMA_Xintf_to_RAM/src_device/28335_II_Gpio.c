// TI File $Revision: /main/1 $
// Checkin $Date: August 18, 2006   13:46:25 $
//###########################################################################
//
// FILE:	DSP2833x_Gpio.c
//
// TITLE:	DSP2833x General Purpose I/O Initialization & Support Functions.
//
//###########################################################################
// $TI Release: DSP2833x Header Files V1.01 $
// $Release Date: September 26, 2007 $
//###########################################################################

#include "28335_II_Device.h"     // DSP2833x Headerfile Include File
#include "DMA_Xintf_to_RAM.h"   // DSP2833x Examples Include File

//---------------------------------------------------------------------------
// InitGpio: 
//---------------------------------------------------------------------------
// This function initializes the Gpio to a known (default) state.
//
// For more details on configuring GPIO's as peripheral functions,
// refer to the individual peripheral examples and/or GPIO setup example. 
void InitGpio(void)
{
	// Step 1: Init the Gpio use for 16 bit mode XINTF  
	EALLOW;

	InitXintf32Gpio();	

   	EDIS;
}	

void InitXintf32Gpio()
{
	EALLOW;
	
	// Configure the GPIO for the use for high-16 XINTF Data Bus
	GpioCtrlRegs.GPBMUX2.bit.GPIO48 = 3;  // XD31
	GpioCtrlRegs.GPBMUX2.bit.GPIO49 = 3;  // XD30
	GpioCtrlRegs.GPBMUX2.bit.GPIO50 = 3;  // XD29
	GpioCtrlRegs.GPBMUX2.bit.GPIO51 = 3;  // XD28
	GpioCtrlRegs.GPBMUX2.bit.GPIO52 = 3;  // XD27
	GpioCtrlRegs.GPBMUX2.bit.GPIO53 = 3;  // XD26
	GpioCtrlRegs.GPBMUX2.bit.GPIO54 = 3;  // XD25
	GpioCtrlRegs.GPBMUX2.bit.GPIO55 = 3;  // XD24
	GpioCtrlRegs.GPBMUX2.bit.GPIO56 = 3;  // XD23
	GpioCtrlRegs.GPBMUX2.bit.GPIO57 = 3;  // XD22
	GpioCtrlRegs.GPBMUX2.bit.GPIO58 = 3;  // XD21
	GpioCtrlRegs.GPBMUX2.bit.GPIO59 = 3;  // XD20
	GpioCtrlRegs.GPBMUX2.bit.GPIO60 = 3;  // XD19
	GpioCtrlRegs.GPBMUX2.bit.GPIO61 = 3;  // XD18
	GpioCtrlRegs.GPBMUX2.bit.GPIO62 = 3;  // XD17
	GpioCtrlRegs.GPBMUX2.bit.GPIO63 = 3;  // XD16
	
	GpioCtrlRegs.GPBQSEL2.bit.GPIO48 = 3;  // XD31 asynchronous input
	GpioCtrlRegs.GPBQSEL2.bit.GPIO49 = 3;  // XD30 asynchronous input
	GpioCtrlRegs.GPBQSEL2.bit.GPIO50 = 3;  // XD29 asynchronous input
	GpioCtrlRegs.GPBQSEL2.bit.GPIO51 = 3;  // XD28 asynchronous input
	GpioCtrlRegs.GPBQSEL2.bit.GPIO52 = 3;  // XD27 asynchronous input
	GpioCtrlRegs.GPBQSEL2.bit.GPIO53 = 3;  // XD26 asynchronous input
	GpioCtrlRegs.GPBQSEL2.bit.GPIO54 = 3;  // XD25 asynchronous input
	GpioCtrlRegs.GPBQSEL2.bit.GPIO55 = 3;  // XD24 asynchronous input
	GpioCtrlRegs.GPBQSEL2.bit.GPIO56 = 3;  // XD23 asynchronous input
	GpioCtrlRegs.GPBQSEL2.bit.GPIO57 = 3;  // XD22 asynchronous input
	GpioCtrlRegs.GPBQSEL2.bit.GPIO58 = 3;  // XD21 asynchronous input
	GpioCtrlRegs.GPBQSEL2.bit.GPIO59 = 3;  // XD20 asynchronous input
	GpioCtrlRegs.GPBQSEL2.bit.GPIO60 = 3;  // XD19 asynchronous input
	GpioCtrlRegs.GPBQSEL2.bit.GPIO61 = 3;  // XD18 asynchronous input
	GpioCtrlRegs.GPBQSEL2.bit.GPIO62 = 3;  // XD17 asynchronous input
	GpioCtrlRegs.GPBQSEL2.bit.GPIO63 = 3;  // XD16 asynchronous input
	
	// Configure the GPIO for the use for low 16 bit XINTF: data bus, addr bus, contrl signals etc.
	InitXintf16Gpio();
	EDIS;
}

void InitXintf16Gpio()
{
	EALLOW;
	GpioCtrlRegs.GPCMUX1.bit.GPIO64 = 3;  // XD15
	GpioCtrlRegs.GPCMUX1.bit.GPIO65 = 3;  // XD14
	GpioCtrlRegs.GPCMUX1.bit.GPIO66 = 3;  // XD13
	GpioCtrlRegs.GPCMUX1.bit.GPIO67 = 3;  // XD12
	GpioCtrlRegs.GPCMUX1.bit.GPIO68 = 3;  // XD11
	GpioCtrlRegs.GPCMUX1.bit.GPIO69 = 3;  // XD10
	GpioCtrlRegs.GPCMUX1.bit.GPIO70 = 3;  // XD19
	GpioCtrlRegs.GPCMUX1.bit.GPIO71 = 3;  // XD8
	GpioCtrlRegs.GPCMUX1.bit.GPIO72 = 3;  // XD7
	GpioCtrlRegs.GPCMUX1.bit.GPIO73 = 3;  // XD6
	GpioCtrlRegs.GPCMUX1.bit.GPIO74 = 3;  // XD5
	GpioCtrlRegs.GPCMUX1.bit.GPIO75 = 3;  // XD4
	GpioCtrlRegs.GPCMUX1.bit.GPIO76 = 3;  // XD3
	GpioCtrlRegs.GPCMUX1.bit.GPIO77 = 3;  // XD2
	GpioCtrlRegs.GPCMUX1.bit.GPIO78 = 3;  // XD1
	GpioCtrlRegs.GPCMUX1.bit.GPIO79 = 3;  // XD0

	GpioCtrlRegs.GPBMUX1.bit.GPIO40 = 3;  // XA0/XWE1n
	GpioCtrlRegs.GPBMUX1.bit.GPIO41 = 3;  // XA1
	GpioCtrlRegs.GPBMUX1.bit.GPIO42 = 3;  // XA2
	GpioCtrlRegs.GPBMUX1.bit.GPIO43 = 3;  // XA3
	GpioCtrlRegs.GPBMUX1.bit.GPIO44 = 3;  // XA4
	GpioCtrlRegs.GPBMUX1.bit.GPIO45 = 3;  // XA5
	GpioCtrlRegs.GPBMUX1.bit.GPIO46 = 3;  // XA6
	GpioCtrlRegs.GPBMUX1.bit.GPIO47 = 3;  // XA7
	GpioCtrlRegs.GPCMUX2.bit.GPIO80 = 3;  // XA8
	GpioCtrlRegs.GPCMUX2.bit.GPIO81 = 3;  // XA9
	GpioCtrlRegs.GPCMUX2.bit.GPIO82 = 3;  // XA10
	GpioCtrlRegs.GPCMUX2.bit.GPIO83 = 3;  // XA11
	GpioCtrlRegs.GPCMUX2.bit.GPIO84 = 3;  // XA12
	GpioCtrlRegs.GPCMUX2.bit.GPIO85 = 3;  // XA13
	GpioCtrlRegs.GPCMUX2.bit.GPIO86 = 3;  // XA14
	GpioCtrlRegs.GPCMUX2.bit.GPIO87 = 3;  // XA15
	GpioCtrlRegs.GPBMUX1.bit.GPIO39 = 3;  // XA16
	GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 3;  // XA17
	GpioCtrlRegs.GPAMUX2.bit.GPIO30 = 3;  // XA18
	GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 3;  // XA19
	GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 3;  // XREADY
	GpioCtrlRegs.GPBMUX1.bit.GPIO35 = 3;  // XRNW
	GpioCtrlRegs.GPBMUX1.bit.GPIO38 = 3;  // XWE0
	GpioCtrlRegs.GPBMUX1.bit.GPIO36 = 3;  // XZCS0
	GpioCtrlRegs.GPBMUX1.bit.GPIO37 = 3;  // XZCS7
	GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 3;  // XZCS6
	EDIS;
}
	
//===========================================================================
// End of file.
//===========================================================================
