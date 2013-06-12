//###########################################################################
//
// FILE:   DSP2833x_Examples.h
//
// TITLE:  DSP2833x Device Definitions.
//
//###########################################################################

#ifndef LED_FLASH_H
#define LED_FLASH_H


#ifdef __cplusplus
extern "C" {
#endif


/*-----------------------------------------------------------------------------
      Specify the PLL control register (PLLCR) and divide select (DIVSEL) value.
-----------------------------------------------------------------------------*/
// Enable /2 for SYSCLKOUT
#define DSP28_DIVSEL  2 

// 0: PLL is bypassed in this mode
#define DSP28_PLLCR   10	
//----------------------------------------------------------------------------


/*-----------------------------------------------------------------------------
      Specify the clock rate of the CPU (SYSCLKOUT) in nS.

      Take into account the input clock frequency and the PLL multiplier
      selected in step 1.

      Use one of the values provided, or define your own.
      The trailing L is required tells the compiler to treat
      the number as a 64-bit value.

      Only one statement should be uncommented.

      Example 1:150 MHz devices:
                CLKIN is a 30MHz crystal.

                In step 1 the user specified PLLCR = 0xA for a
                150Mhz CPU clock (SYSCLKOUT = 150MHz).

                In this case, the CPU_RATE will be 6.667L
                Uncomment the line:  #define CPU_RATE  6.667L

      Example 2:  100 MHz devices:
                  CLKIN is a 20MHz crystal.

	              In step 1 the user specified PLLCR = 0xA for a
	              100Mhz CPU clock (SYSCLKOUT = 100MHz).

	              In this case, the CPU_RATE will be 10.000L
                  Uncomment the line:  #define CPU_RATE  10.000L
-----------------------------------------------------------------------------*/
#define CPU_RATE    6.667L   // for a 150MHz CPU clock speed (SYSCLKOUT)

#include "28335_II_GlobalPrototypes.h"         // Prototypes for global functions within the .c files.

#define PARTNO_28335  0xFA


// Include files not used with DSP/BIOS
#ifndef DSP28_BIOS
#include "28335_II_DefaultISR.h"
#endif


// DO NOT MODIFY THIS LINE.
#define DELAY_US(A)  DSP28x_usDelay(((((long double) A * 1000.0L) / (long double)CPU_RATE) - 9.0L) / 5.0L)


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2833x_EXAMPLES_H definition


//===========================================================================
// End of file.
//===========================================================================
