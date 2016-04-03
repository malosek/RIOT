/*
 * Copyright (C) 2013, 2014 INRIA
 *               2015 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @defgroup    boards_telosb ts430pm64
 * @ingroup     boards
 * @brief       Support for the TelosB board
 *
 * <h2>Compontents</h2>
 * \li MSP430
 * \li CC2420
 *
 * @{
 *
 * @file
 * @brief       Basic definitions for the ts430pm64 board
 *
 * @author      Oliver Hahm <oliver.hahm@inria.fr>
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 */

#ifndef TS430PM64_BOARD_H_
#define TS430PM64_BOARD_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Xtimer configuration
 * @{
 */
#define XTIMER                      (0)
#define XTIMER_CHAN                 (0)
#define XTIMER_MASK                 (0xffff0000)
#define XTIMER_SHIFT_ON_COMPARE     (4)
#define XTIMER_BACKOFF              (40)
/** @} */

/* TelosB core */
#define MSP430_INITIAL_CPU_SPEED    8000000uL
#define F_CPU                       MSP430_INITIAL_CPU_SPEED
#define F_RC_OSCILLATOR             32768
#define MSP430_HAS_DCOR             0
#define MSP430_HAS_EXTERNAL_CRYSTAL 0

/* LEDs ports MSB430 */
#define LEDS_PxDIR P1DIR
#define LEDS_PxOUT P1OUT
#define LEDS_CONF_RED       0x01

#define LED_RED_ON          LEDS_PxOUT &=~LEDS_CONF_RED
#define LED_RED_OFF         LEDS_PxOUT |= LEDS_CONF_RED
#define LED_RED_TOGGLE      LEDS_PxOUT ^= LEDS_CONF_RED

/**
 * @name Define the interface to the AT86RF233 radio
 * @{
 */
#define AT86RF2XX_PARAM_SPI         SPI_0
#define AT86RF2XX_PARAM_CS          GPIO_PIN(P1,4)
#define AT86RF2XX_PARAM_INT         GPIO_PIN(P1,6)
#define AT86RF2XX_PARAM_RESET       GPIO_PIN(P1,5)
#define AT86RF2XX_PARAM_SLEEP       GPIO_PIN(P1,2)
#define AT86RF2XX_PARAM_SPI_SPEED   SPI_SPEED_5MHZ

#ifdef __cplusplus
}
#endif

#include <stdint.h>

/** @} */
#endif /*  TS430PM64_BOARD_H_ */
