/****************************************************************************
 * boards/arm/s32k1xx/s32k146evb/src/s32k146evb.h
 *
 *   Copyright (C) 2019 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#ifndef __BOARDS_ARM_S32K1XX_S32K146EVB_SRC_S32K146EVB_H
#define __BOARDS_ARM_S32K1XX_S32K146EVB_SRC_S32K146EVB_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <nuttx/compiler.h>

#include <stdint.h>

#include "hardware/s32k1xx_pinmux.h"
#include "s32k1xx_periphclocks.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Configuration ************************************************************/

/* S32K146EVB GPIOs *********************************************************/

/* LEDs.  The S32K146EVB has one RGB LED:
 *
 *   RedLED   PTD15 (FTM0 CH0)
 *   GreenLED PTD16 (FTM0 CH1)
 *   BlueLED  PTD0  (FTM0 CH2)
 */

#define GPIO_LED_R     (PIN_PTD15 | GPIO_LOWDRIVE | GPIO_OUTPUT_ONE)
#define GPIO_LED_G     (PIN_PTD16 | GPIO_LOWDRIVE | GPIO_OUTPUT_ONE)
#define GPIO_LED_B     (PIN_PTE8  | GPIO_LOWDRIVE | GPIO_OUTPUT_ONE)

/* Buttons.  The S32K146EVB supports two buttons:
 *
 *   SW2  PTC12
 *   SW3  PTC13
 */

#define GPIO_SW2       (PIN_PTC12 | PIN_INT_BOTH)
#define GPIO_SW3       (PIN_PTC13 | PIN_INT_BOTH)

/* SPI chip selects */


/* Count of peripheral clock user configurations */

#define NUM_OF_PERIPHERAL_CLOCKS_0 11

/****************************************************************************
 * Public Types
 ****************************************************************************/

/****************************************************************************
 * Public data
 ****************************************************************************/

#ifndef __ASSEMBLY__

/* User peripheral configuration structure 0 */

extern const struct peripheral_clock_config_s g_peripheral_clockconfig0[];

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: s32k146_bringup
 *
 * Description:
 *   Perform architecture-specific initialization
 *
 *   CONFIG_BOARD_LATE_INITIALIZE=y :
 *     Called from board_late_initialize().
 *
 *   CONFIG_BOARD_LATE_INITIALIZE=y && CONFIG_LIB_BOARDCTL=y :
 *     Called from the NSH library
 *
 ****************************************************************************/

int s32k146_bringup(void);

/****************************************************************************
 * Name: s32k146_spidev_initialize
 *
 * Description:
 *   Called to configure SPI chip select GPIO pins for the s32k146evb
 *   board.
 *
 ****************************************************************************/

#ifdef CONFIG_S32K1XX_SPI
void s32k146_spidev_initialize(void);
#endif

#endif /* __ASSEMBLY__ */
#endif /* __BOARDS_ARM_S32K1XX_S32K146EVB_SRC_S32K146EVB_H */
