/**************************************************************************************************
  Revised:        $Date: 2007-07-06 11:19:00 -0700 (Fri, 06 Jul 2007) $
  Revision:       $Revision: 13579 $

  Copyright 2010 Texas Instruments Incorporated.  All rights reserved.

  IMPORTANT: Your use of this Software is limited to those specific rights granted under
  the terms of a software license agreement between the user who downloaded the software,
  his/her employer (which must be your employer) and Texas Instruments Incorporated (the
  "License"). You may not use this Software unless you agree to abide by the terms of the
  License. The License limits your use, and you acknowledge, that the Software may not be
  modified, copied or distributed unless embedded on a Texas Instruments microcontroller
  or used solely and exclusively in conjunction with a Texas Instruments radio frequency
  transceiver, which is integrated into your product. Other than for the foregoing purpose,
  you may not use, reproduce, copy, prepare derivative works of, modify, distribute,
  perform, display or sell this Software and/or its documentation for any purpose.

  YOU FURTHER ACKNOWLEDGE AND AGREE THAT THE SOFTWARE AND DOCUMENTATION ARE PROVIDED �AS IS�
  WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY
  WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
  IN NO EVENT SHALL TEXAS INSTRUMENTS OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT,
  NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE
  THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY
  INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST
  DATA, COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY
  THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

  Should you have any questions regarding your right to use this Software,
  contact Texas Instruments Incorporated at www.TI.com.
**************************************************************************************************/

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 *   BSP (Board Support Package)
 *   Target : Texas Instruments Stellaris Launchpad
 *   Button definition file.
 * =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 */

#ifndef BSP_BUTTON_DEFS_H
#define BSP_BUTTON_DEFS_H

/* ------------------------------------------------------------------------------------------------
 *                                           Includes
 * ------------------------------------------------------------------------------------------------
 */
#include "bsp_board_defs.h"
#include "bsp_macros.h"

/* ------------------------------------------------------------------------------------------------
 *                                      Stellaris-specific headers
 * ------------------------------------------------------------------------------------------------
 */
#include "inc/hw_gpio.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"

/* ------------------------------------------------------------------------------------------------
 *                                      Button Configuration
 * ------------------------------------------------------------------------------------------------
 */
#define __bsp_NUM_BUTTONS__                   1
#define __bsp_BUTTON_DEBOUNCE_WAIT__(expr)    st( int i; for(i=0; i<500; i++) { if (!(expr)) i = 0; } )


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *                 BUTTON #1
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *   Schematic   :  SW1
 *   Description :  Push Button
 *   Polarity    :  Active Low
 *   GPIO        :  PF4
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
#define __bsp_BUTTON1_BIT__             4
#define __bsp_BUTTON1_PORT__            HWREG(GPIO_PORTF_BASE + (GPIO_O_DATA + BV(__bsp_BUTTON1_BIT__ + 2)))
#define __bsp_BUTTON1_IS_ACTIVE_LOW__   1

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *          Extended Configuration
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
/* Do all button configuration via this macro since we need to do more than
 * one register write to configure each GPIO.
 */
#define __bsp_BUTTON_EXTENDED_CONFIG__() st(                                 \
        MAP_GPIODirModeSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_DIR_MODE_IN);   \
        MAP_GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_STRENGTH_2MA, \
                             GPIO_PIN_TYPE_STD_WPU);)

/* ------------------------------------------------------------------------------------------------
 *                                Include Generic Button Macros
 * ------------------------------------------------------------------------------------------------
 */
#include "code/bsp_generic_buttons.h"

/**************************************************************************************************
 */
#endif
