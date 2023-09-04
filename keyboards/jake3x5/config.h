// Copyright 2023 Jacob Kausler (@jakekausler)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define TAPPING_TERM 175

#define ENCODERS_PAD_A { GP18 }
#define ENCODERS_PAD_B { GP19 }
#define ENCODER_RESOLUTIONS { 4 }
#define ENCODERS_PAD_A_RIGHT { GP20 }
#define ENCODERS_PAD_B_RIGHT { GP21 }
#define ENCODER_RESOLUTIONS_RIGHT { 4 }

#define LEADER_NO_TIMEOUT
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 250

#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define PMW33XX_CS_PIN 1
#define PMW33XX_CPI 2000

#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE

#define OLED_COLUMN_OFFSET 1

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
