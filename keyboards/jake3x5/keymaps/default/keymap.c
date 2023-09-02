// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "action.h"
#include "keycodes.h"
#include "quantum.h"
#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "keymap_us.h"
#include "quantum_keycodes.h"
#include "features/sentence_case.h"
#include "features/layer_lock.h"

// TODO: OLED setup and information
//  - Name of Layer
//  - Minimap of Layer
// TODO: Encoder changes cpi (separate slow/fast) on layer
// TODO: Encoder changes scroll speed on layer
// TODO: Encoder changes nav speed (trackball) on layer

/*
 * LAYERS
 */

enum layer_names {
    _ALP,
    _GRK,
    _MOU,
    _SYM,
    _NAV,
    _NUM,
    _FUN
};

/*
 * KEYCODES
 */

enum extra_keys {
    PLUS_EQUAL = SAFE_RANGE,
    MINUS_EQUAL,
    LL_TOGG
};

enum tap_dances {
    TD_QU,
    TD_W,
    TD_F,
    TD_P,
    TD_B,
    TD_A,
    TD_R,
    TD_S,
    TD_T,
    TD_G,
    TD_Z,
    TD_X,
    TD_C,
    TD_D,
    TD_V,
    TD_J,
    TD_L,
    TD_U,
    TD_Y,
    TD_WH,
    TD_M,
    TD_N,
    TD_E,
    TD_I,
    TD_O,
    TD_K,
    TD_H,
    TD_TH,
    TD_CH,
    TD_SH,
    TD_BSPC,
    TD_SPC,
    TD_RPT,
    TD_DEL,
    TD_TAB,
    TD_1SS,
    TD_ENT,
    TD_LDR,
    TD_NUML,
    TD_SYML,
    TD_NAVL,
    TD_FUNL,
    TD_MAC1,
    TD_MAC2
};

enum unicode_names {
    GK_QUES,
    GK_SEMI,
    GK_A_L,
    GK_A_U,
    GK_AS_L,
    GK_AS_U,
    GK_ASA_L,
    GK_ASA_U,
    GK_ASAI_L,
    GK_ASAI_U,
    GK_ASG_L,
    GK_ASG_U,
    GK_ASGI_L,
    GK_ASGI_U,
    GK_ASC_L,
    GK_ASC_U,
    GK_ASCI_L,
    GK_ASCI_U,
    GK_ASI_L,
    GK_ASI_U,
    GK_AR_L,
    GK_AR_U,
    GK_ARA_L,
    GK_ARA_U,
    GK_ARAI_L,
    GK_ARAI_U,
    GK_ARG_L,
    GK_ARG_U,
    GK_ARGI_L,
    GK_ARGI_U,
    GK_ARC_L,
    GK_ARC_U,
    GK_ARCI_L,
    GK_ARCI_U,
    GK_ARI_L,
    GK_ARI_U,
    GK_AA_L,
    GK_AA_U,
    GK_AAI_L,
    GK_AAI_U,
    GK_AG_L,
    GK_AG_U,
    GK_AGI_L,
    GK_AGI_U,
    GK_AB_L,
    GK_AB_U,
    GK_AC_L,
    GK_AC_U,
    GK_ACI_L,
    GK_ACI_U,
    GK_AL_L,
    GK_AL_U,
    GK_AI_L,
    GK_AI_U,
    GK_B_L,
    GK_B_U,
    GK_G_L,
    GK_G_U,
    GK_D_L,
    GK_D_U,
    GK_E_L,
    GK_E_U,
    GK_ES_L,
    GK_ES_U,
    GK_ESA_L,
    GK_ESA_U,
    GK_ESG_L,
    GK_ESG_U,
    GK_ER_L,
    GK_ER_U,
    GK_ERA_L,
    GK_ERA_U,
    GK_ERG_L,
    GK_ERG_U,
    GK_EA_L,
    GK_EA_U,
    GK_EG_L,
    GK_EG_U,
    GK_Z_L,
    GK_Z_U,
    GK_H_L,
    GK_H_U,
    GK_HS_L,
    GK_HS_U,
    GK_HSA_L,
    GK_HSA_U,
    GK_HSAI_L,
    GK_HSAI_U,
    GK_HSG_L,
    GK_HSG_U,
    GK_HSGI_L,
    GK_HSGI_U,
    GK_HSC_L,
    GK_HSC_U,
    GK_HSCI_L,
    GK_HSCI_U,
    GK_HSI_L,
    GK_HSI_U,
    GK_HR_L,
    GK_HR_U,
    GK_HRA_L,
    GK_HRA_U,
    GK_HRAI_L,
    GK_HRAI_U,
    GK_HRG_L,
    GK_HRG_U,
    GK_HRGI_L,
    GK_HRGI_U,
    GK_HRC_L,
    GK_HRC_U,
    GK_HRCI_L,
    GK_HRCI_U,
    GK_HRI_L,
    GK_HRI_U,
    GK_HA_L,
    GK_HA_U,
    GK_HAI_L,
    GK_HAI_U,
    GK_HG_L,
    GK_HG_U,
    GK_HGI_L,
    GK_HGI_U,
    GK_HC_L,
    GK_HC_U,
    GK_HCI_L,
    GK_HCI_U,
    GK_HI_L,
    GK_HI_U,
    GK_TH_L,
    GK_TH_U,
    GK_I_L,
    GK_I_U,
    GK_IS_L,
    GK_IS_U,
    GK_ISA_L,
    GK_ISA_U,
    GK_ISG_L,
    GK_ISG_U,
    GK_ISC_L,
    GK_ISC_U,
    GK_IR_L,
    GK_IR_U,
    GK_IRA_L,
    GK_IRA_U,
    GK_IRG_L,
    GK_IRG_U,
    GK_IRC_L,
    GK_IRC_U,
    GK_IA_L,
    GK_IA_U,
    GK_IG_L,
    GK_IG_U,
    GK_IB_L,
    GK_IB_U,
    GK_IC_L,
    GK_IC_U,
    GK_ID_L,
    GK_ID_U,
    GK_IDG_L,
    GK_IDG_U,
    GK_IDA_L,
    GK_IDA_U,
    GK_IDC_L,
    GK_IDC_U,
    GK_IL_L,
    GK_IL_U,
    GK_K_L,
    GK_K_U,
    GK_L_L,
    GK_L_U,
    GK_M_L,
    GK_M_U,
    GK_N_L,
    GK_N_U,
    GK_XI_L,
    GK_XI_U,
    GK_O_L,
    GK_O_U,
    GK_OS_L,
    GK_OS_U,
    GK_OSA_L,
    GK_OSA_U,
    GK_OSG_L,
    GK_OSG_U,
    GK_OR_L,
    GK_OR_U,
    GK_ORA_L,
    GK_ORA_U,
    GK_ORG_L,
    GK_ORG_U,
    GK_OA_L,
    GK_OA_U,
    GK_OG_L,
    GK_OG_U,
    GK_P_L,
    GK_P_U,
    GK_R_L,
    GK_R_U,
    GK_S_L,
    GK_S_U,
    GK_SS_L,
    GK_SS_U,
    GK_T_L,
    GK_T_U,
    GK_U_L,
    GK_U_U,
    GK_US_L,
    GK_US_U,
    GK_USA_L,
    GK_USA_U,
    GK_USG_L,
    GK_USG_U,
    GK_USC_L,
    GK_USC_U,
    GK_UR_L,
    GK_UR_U,
    GK_URA_L,
    GK_URA_U,
    GK_URG_L,
    GK_URG_U,
    GK_URC_L,
    GK_URC_U,
    GK_UA_L,
    GK_UA_U,
    GK_UG_L,
    GK_UG_U,
    GK_UB_L,
    GK_UB_U,
    GK_UC_L,
    GK_UC_U,
    GK_UD_L,
    GK_UD_U,
    GK_UDG_L,
    GK_UDG_U,
    GK_UDA_L,
    GK_UDA_U,
    GK_UDC_L,
    GK_UDC_U,
    GK_UL_L,
    GK_UL_U,
    GK_PH_L,
    GK_PH_U,
    GK_X_L,
    GK_X_U,
    GK_PS_L,
    GK_PS_U,
    GK_W_L,
    GK_W_U,
    GK_WS_L,
    GK_WS_U,
    GK_WSA_L,
    GK_WSA_U,
    GK_WSAI_L,
    GK_WSAI_U,
    GK_WSG_L,
    GK_WSG_U,
    GK_WSGI_L,
    GK_WSGI_U,
    GK_WSC_L,
    GK_WSC_U,
    GK_WSCI_L,
    GK_WSCI_U,
    GK_WSI_L,
    GK_WSI_U,
    GK_WR_L,
    GK_WR_U,
    GK_WRA_L,
    GK_WRA_U,
    GK_WRAI_L,
    GK_WRAI_U,
    GK_WRG_L,
    GK_WRG_U,
    GK_WRGI_L,
    GK_WRGI_U,
    GK_WRC_L,
    GK_WRC_U,
    GK_WRCI_L,
    GK_WRCI_U,
    GK_WRI_L,
    GK_WRI_U,
    GK_WA_L,
    GK_WA_U,
    GK_WAI_L,
    GK_WAI_U,
    GK_WG_L,
    GK_WG_U,
    GK_WGI_L,
    GK_WGI_U,
    GK_WC_L,
    GK_WC_U,
    GK_WCI_L,
    GK_WCI_U,
    GK_WI_L,
    GK_WI_U,
    GK_KO_L,
    GK_KO_U,
    GK_ST_L,
    GK_ST_U,
    GK_SP_L,
    GK_SP_U
};

/*
 * GREEK UNICODE
 */

const uint32_t unicode_map[] PROGMEM = {
    [GK_QUES] = 0x37E, // question
    [GK_SEMI] = 0x0387, // semicolon
    [GK_A_L] = 0x03B1, // alpha lower
	[GK_A_U] = 0x0391, // alpha upper
	[GK_AS_L] = 0x1F00, // alpha smooth lower
	[GK_AS_U] = 0x1F08, // alpha smooth upper
	[GK_ASA_L] = 0x1F04, // alpha smooth acute lower
	[GK_ASA_U] = 0x1F0C, // alpha smooth acute upper
	[GK_ASAI_L] = 0x1F84, // alpha smooth acute iota lower
	[GK_ASAI_U] = 0x1F8C, // alpha smooth acute iota upper
	[GK_ASG_L] = 0x1F02, // alpha smooth grave lower
	[GK_ASG_U] = 0x1F0A, // alpha smooth grave upper
	[GK_ASGI_L] = 0x1F82, // alpha smooth grave iota lower
	[GK_ASGI_U] = 0x1F8A, // alpha smooth grave iota upper
	[GK_ASC_L] = 0x1F06, // alpha smooth circumflex lower
	[GK_ASC_U] = 0x1F0E, // alpha smooth circumflex upper
	[GK_ASCI_L] = 0x1F86, // alpha smooth circumflex iota lower
	[GK_ASCI_U] = 0x1F8E, // alpha smooth circumflex iota upper
	[GK_ASI_L] = 0x1F80, // alpha smooth iota lower
	[GK_ASI_U] = 0x1F88, // alpha smooth iota upper
	[GK_AR_L] = 0x1F01, // alpha rough lower
	[GK_AR_U] = 0x1F09, // alpha rough upper
	[GK_ARA_L] = 0x1F05, // alpha rough acute lower
	[GK_ARA_U] = 0x1F0D, // alpha rough acute upper
	[GK_ARAI_L] = 0x1F85, // alpha rough acute iota lower
	[GK_ARAI_U] = 0x1F8D, // alpha rough acute iota upper
	[GK_ARG_L] = 0x1F03, // alpha rough grave lower
	[GK_ARG_U] = 0x1F0B, // alpha rough grave upper
	[GK_ARGI_L] = 0x1F83, // alpha rough grave iota lower
	[GK_ARGI_U] = 0x1F8B, // alpha rough grave iota upper
	[GK_ARC_L] = 0x1F07, // alpha rough cirumflex lower
	[GK_ARC_U] = 0x1F0F, // alpha rough cirumflex upper
	[GK_ARCI_L] = 0x1F87, // alpha rough cirumflex iota lower
	[GK_ARCI_U] = 0x1F8F, // alpha rough cirumflex iota upper
	[GK_ARI_L] = 0x1F81, // alpha rough iota lower
	[GK_ARI_U] = 0x1F89, // alpha rough iota upper
	[GK_AA_L] = 0x03AC, // alpha acute lower
	[GK_AA_U] = 0x0386, // alpha acute upper
	[GK_AAI_L] = 0x1FB4, // alpha acute iota lower
	[GK_AAI_U] = 0x1FB4, // alpha acute iota upper
	[GK_AG_L] = 0x1F70, // alpha grave lower
	[GK_AG_U] = 0x1FBA, // alpha grave upper
	[GK_AGI_L] = 0x1FB2, // alpha grave iota lower
	[GK_AGI_U] = 0x1FB2, // alpha grave iota upper
	[GK_AB_L] = 0x1FB0, // alpha breve lower
	[GK_AB_U] = 0x1FB8, // alpha breve upper
	[GK_AC_L] = 0x1FB6, // alpha circumflex lower
	[GK_AC_U] = 0x1FB6, // alpha circumflex upper
	[GK_ACI_L] = 0x1FB7, // alpha circumflex iota lower
	[GK_ACI_U] = 0x1FB7, // alpha circumflex iota upper
	[GK_AL_L] = 0x1FB1, // alpha long lower
	[GK_AL_U] = 0x1FB9, // alpha long upper
	[GK_AI_L] = 0x1FB3, // alpha iota lower
	[GK_AI_U] = 0x1FBC, // alpha iota upper
	[GK_B_L] = 0x03B2, // beta lower
	[GK_B_U] = 0x0392, // beta upper
	[GK_G_L] = 0x03B3, // gamma lower
	[GK_G_U] = 0x0393, // gamma upper
	[GK_D_L] = 0x03B4, // delta lower
	[GK_D_U] = 0x0394, // delta upper
	[GK_E_L] = 0x03F5, // epsilon lower
	[GK_E_U] = 0x0395, // epsilon upper
	[GK_ES_L] = 0x1F10, // epsilon smooth lower
	[GK_ES_U] = 0x1F18, // epsilon smooth upper
	[GK_ESA_L] = 0x1F14, // epsilon smooth acute lower
	[GK_ESA_U] = 0x1F1C, // epsilon smooth acute upper
	[GK_ESG_L] = 0x1F12, // epsilon smooth grave lower
	[GK_ESG_U] = 0x1F1A, // epsilon smooth grave upper
	[GK_ER_L] = 0x1F11, // epsilon rough lower
	[GK_ER_U] = 0x1F19, // epsilon rough upper
	[GK_ERA_L] = 0x1F15, // epsilon rough acute lower
	[GK_ERA_U] = 0x1F1D, // epsilon rough acute upper
	[GK_ERG_L] = 0x1F13, // epsilon rough grave lower
	[GK_ERG_U] = 0x1F1B, // epsilon rough grave upper
	[GK_EA_L] = 0x1F73, // epsilon acute lower
	[GK_EA_U] = 0x1FC9, // epsilon acute upper
	[GK_EG_L] = 0x1F72, // epsilon grave lower
	[GK_EG_U] = 0x1FC8, // epsilon grave upper
	[GK_Z_L] = 0x03B6, // zeta lower
	[GK_Z_U] = 0x0396, // zeta upper
	[GK_H_L] = 0x03B7, // eta lower
	[GK_H_U] = 0x0397, // eta upper
	[GK_HS_L] = 0x1F20, // eta smooth lower
	[GK_HS_U] = 0x1F28, // eta smooth upper
	[GK_HSA_L] = 0x1F24, // eta smooth acute lower
	[GK_HSA_U] = 0x1F2C, // eta smooth acute upper
	[GK_HSAI_L] = 0x1F94, // eta smooth acute iota lower
	[GK_HSAI_U] = 0x1F9C, // eta smooth acute iota upper
	[GK_HSG_L] = 0x1F22, // eta smooth grave lower
	[GK_HSG_U] = 0x1F2A, // eta smooth grave upper
	[GK_HSGI_L] = 0x1F92, // eta smooth grave iota lower
	[GK_HSGI_U] = 0x1F9A, // eta smooth grave iota upper
	[GK_HSC_L] = 0x1F26, // eta smooth circumflex lower
	[GK_HSC_U] = 0x1F2E, // eta smooth circumflex upper
	[GK_HSCI_L] = 0x1F96, // eta smooth circumflex iota lower
	[GK_HSCI_U] = 0x1F9E, // eta smooth circumflex iota upper
	[GK_HSI_L] = 0x1F90, // eta smooth iota lower
	[GK_HSI_U] = 0x1F98, // eta smooth iota upper
	[GK_HR_L] = 0x1F21, // eta rough lower
	[GK_HR_U] = 0x1F29, // eta rough upper
	[GK_HRA_L] = 0x1F25, // eta rough acute lower
	[GK_HRA_U] = 0x1F2D, // eta rough acute upper
	[GK_HRAI_L] = 0x1F95, // eta rough acute iota lower
	[GK_HRAI_U] = 0x1F9D, // eta rough acute iota upper
	[GK_HRG_L] = 0x1F23, // eta rough grave lower
	[GK_HRG_U] = 0x1F2B, // eta rough grave upper
	[GK_HRGI_L] = 0x1F93, // eta rough grave iota lower
	[GK_HRGI_U] = 0x1F9B, // eta rough grave iota upper
	[GK_HRC_L] = 0x1F27, // eta rough cirumflex lower
	[GK_HRC_U] = 0x1F2F, // eta rough cirumflex upper
	[GK_HRCI_L] = 0x1F97, // eta rough cirumflex iota lower
	[GK_HRCI_U] = 0x1F9F, // eta rough cirumflex iota upper
	[GK_HRI_L] = 0x1F91, // eta rough iota lower
	[GK_HRI_U] = 0x1F99, // eta rough iota upper
	[GK_HA_L] = 0x1F75, // eta acute lower
	[GK_HA_U] = 0x1FCB, // eta acute upper
	[GK_HAI_L] = 0x1FC4, // eta acute iota lower
	[GK_HAI_U] = 0x1FC4, // eta acute iota upper
	[GK_HG_L] = 0x1F74, // eta grave lower
	[GK_HG_U] = 0x1FCA, // eta grave upper
	[GK_HGI_L] = 0x1FC2, // eta grave iota lower
	[GK_HGI_U] = 0x1FC2, // eta grave iota upper
	[GK_HC_L] = 0x1FC6, // eta circumflex lower
	[GK_HC_U] = 0x1FC6, // eta circumflex upper
	[GK_HCI_L] = 0x1FC7, // eta circumflex iota lower
	[GK_HCI_U] = 0x1FC7, // eta circumflex iota upper
	[GK_HI_L] = 0x1FC3, // eta iota lower
	[GK_HI_U] = 0x1FCC, // eta iota upper
	[GK_TH_L] = 0x03B8, // theta lower
	[GK_TH_U] = 0x0398, // theta upper
	[GK_I_L] = 0x03B9, // iota lower
	[GK_I_U] = 0x0399, // iota upper
	[GK_IS_L] = 0x1F30, // iota smooth lower
	[GK_IS_U] = 0x1F38, // iota smooth upper
	[GK_ISA_L] = 0x1F34, // iota smooth acute lower
	[GK_ISA_U] = 0x1F3C, // iota smooth acute upper
	[GK_ISG_L] = 0x1F32, // iota smooth grave lower
	[GK_ISG_U] = 0x1F3A, // iota smooth grave upper
	[GK_ISC_L] = 0x1F36, // iota smooth circumflex lower
	[GK_ISC_U] = 0x1F3E, // iota smooth circumflex upper
	[GK_IR_L] = 0x1F31, // iota rough lower
	[GK_IR_U] = 0x1F39, // iota rough upper
	[GK_IRA_L] = 0x1F35, // iota rough acute lower
	[GK_IRA_U] = 0x1F3D, // iota rough acute upper
	[GK_IRG_L] = 0x1F33, // iota rough grave - lower
	[GK_IRG_U] = 0x1F3B, // iota rough grave - upper
	[GK_IRC_L] = 0x1F37, // iota rough circumflex lower
	[GK_IRC_U] = 0x1F3F, // iota rough circumflex upper
	[GK_IA_L] = 0x1F77, // iota acute lower
	[GK_IA_U] = 0x1FDB, // iota acute upper
	[GK_IG_L] = 0x1F76, // iota grave lower
	[GK_IG_U] = 0x1FDA, // iota grave upper
	[GK_IB_L] = 0x1FD0, // iota breve lower
	[GK_IB_U] = 0x1FD8, // iota breve upper
	[GK_IC_L] = 0x1FD6, // iota circumflex lower
	[GK_IC_U] = 0x1FD6, // iota circumflex upper
	[GK_ID_L] = 0x03CA, // iota diacritic lower
	[GK_ID_U] = 0x03AA, // iota diacritic upper
	[GK_IDG_L] = 0x1FD3, // iota diacritic grave lower
	[GK_IDG_U] = 0x1FD3, // iota diacritic grave upper
	[GK_IDA_L] = 0x1FD2, // iota diacritic acute lower
	[GK_IDA_U] = 0x1FD2, // iota diacritic acute upper
	[GK_IDC_L] = 0x1FD7, // iota diacritic circumflex lower
	[GK_IDC_U] = 0x1FD7, // iota diacritic circumflex upper
	[GK_IL_L] = 0x1FD1, // iota long lower
	[GK_IL_U] = 0x1FD9, // iota long upper
	[GK_K_L] = 0x03BA, // kappa lower
	[GK_K_U] = 0x039A, // kappa upper
	[GK_L_L] = 0x03BB, // lambda lower
	[GK_L_U] = 0x039B, // lambda upper
	[GK_M_L] = 0x03BC, // mu lower
	[GK_M_U] = 0x039C, // mu upper
	[GK_N_L] = 0x03BD, // nu lower
	[GK_N_U] = 0x039D, // nu upper
	[GK_XI_L] = 0x03BE, // xi lower
	[GK_XI_U] = 0x039E, // xi upper
	[GK_O_L] = 0x03BF, // omicron lower
	[GK_O_U] = 0x039F, // omicron upper
	[GK_OS_L] = 0x1F40, // omicron smooth lower
	[GK_OS_U] = 0x1F48, // omicron smooth upper
	[GK_OSA_L] = 0x1F44, // omicron smooth acute lower
	[GK_OSA_U] = 0x1F4C, // omicron smooth acute upper
	[GK_OSG_L] = 0x1F42, // omicron smooth grave lower
	[GK_OSG_U] = 0x1F4A, // omicron smooth grave upper
	[GK_OR_L] = 0x1F41, // omicron rough lower
	[GK_OR_U] = 0x1F49, // omicron rough upper
	[GK_ORA_L] = 0x1F45, // omicron rough acute lower
	[GK_ORA_U] = 0x1F4D, // omicron rough acute upper
	[GK_ORG_L] = 0x1F43, // omicron rough grave lower
	[GK_ORG_U] = 0x1F4B, // omicron rough grave upper
	[GK_OA_L] = 0x1F79, // omicron acute lower
	[GK_OA_U] = 0x1FF9, // omicron acute upper
	[GK_OG_L] = 0x1F78, // omicron grave lower
	[GK_OG_U] = 0x1FF8, // omicron grave upper
	[GK_P_L] = 0x03C0, // pi lower
	[GK_P_U] = 0x03A0, // pi upper
	[GK_R_L] = 0x03C1, // ro lower
	[GK_R_U] = 0x03A1, // ro upper
	[GK_S_L] = 0x03C3, // sigma lower
	[GK_S_U] = 0x03A3, // sigma upper
	[GK_SS_L] = 0x03C2, // final sigma lower
	[GK_SS_U] = 0x03A3, // final sigma upper
	[GK_T_L] = 0x03C4, // tau lower
	[GK_T_U] = 0x03A4, // tau upper
	[GK_U_L] = 0x03C5, // upsilon lower
	[GK_U_U] = 0x03A5, // upsilon upper
	[GK_US_L] = 0x1F50, // upsilon smooth lower
	[GK_US_U] = 0x1F50, // upsilon smooth upper
	[GK_USA_L] = 0x1F54, // upsilon smooth acute lower
	[GK_USA_U] = 0x1F54, // upsilon smooth acute upper
	[GK_USG_L] = 0x1F52, // upsilon smooth grave lower
	[GK_USG_U] = 0x1F52, // upsilon smooth grave upper
	[GK_USC_L] = 0x1F56, // upsilon smooth circumflex lower
	[GK_USC_U] = 0x1F56, // upsilon smooth circumflex upper
	[GK_UR_L] = 0x1F51, // upsilon rough lower
	[GK_UR_U] = 0x1F59, // upsilon rough upper
	[GK_URA_L] = 0x1F55, // upsilon rough acute lower
	[GK_URA_U] = 0x1F5D, // upsilon rough acute upper
	[GK_URG_L] = 0x1F53, // upsilon rough grave lower
	[GK_URG_U] = 0x1F5B, // upsilon rough grave upper
	[GK_URC_L] = 0x1F57, // upsilon rough circumflex lower
	[GK_URC_U] = 0x1F5F, // upsilon rough circumflex upper
	[GK_UA_L] = 0x1F7B, // upsilon acute lower
	[GK_UA_U] = 0x1FEB, // upsilon acute upper
	[GK_UG_L] = 0x1F7A, // upsilon grave lower
	[GK_UG_U] = 0x1FEA, // upsilon grave upper
	[GK_UB_L] = 0x1FE0, // upsilon breve lower
	[GK_UB_U] = 0x1FE8, // upsilon breve upper
	[GK_UC_L] = 0x1FE6, // upsilon circumflex lower
	[GK_UC_U] = 0x1FE6, // upsilon circumflex upper
	[GK_UD_L] = 0x03CB, // upsilon diacritic lower
	[GK_UD_U] = 0x03AB, // upsilon diacritic upper
	[GK_UDG_L] = 0x1FE3, // upsilon diacritic grave lower
	[GK_UDG_U] = 0x1FE3, // upsilon diacritic grave upper
	[GK_UDA_L] = 0x1FE2, // upsilon diacritic acute lower
	[GK_UDA_U] = 0x1FE2, // upsilon diacritic acute upper
	[GK_UDC_L] = 0x1FE7, // upsilon diacritic circumflex lower
	[GK_UDC_U] = 0x1FE7, // upsilon diacritic circumflex upper
	[GK_UL_L] = 0x1FE1, // upsilon long lower
	[GK_UL_U] = 0x1FE9, // upsilon long upper
	[GK_PH_L] = 0x03C6, // phi lower
	[GK_PH_U] = 0x03A6, // phi upper
	[GK_X_L] = 0x03C7, // chi lower
	[GK_X_U] = 0x03A7, // chi upper
	[GK_PS_L] = 0x03C8, // psi lower
	[GK_PS_U] = 0x03A8, // psi upper
	[GK_W_L] = 0x03C9, // omega lower
	[GK_W_U] = 0x03A9, // omega upper
	[GK_WS_L] = 0x1F60, // omega smooth lower
	[GK_WS_U] = 0x1F68, // omega smooth upper
	[GK_WSA_L] = 0x1F64, // omega smooth acute lower
	[GK_WSA_U] = 0x1F6C, // omega smooth acute upper
	[GK_WSAI_L] = 0x1FA4, // omega smooth acute iota lower
	[GK_WSAI_U] = 0x1FAC, // omega smooth acute iota upper
	[GK_WSG_L] = 0x1F62, // omega smooth grave lower
	[GK_WSG_U] = 0x1F6A, // omega smooth grave upper
	[GK_WSGI_L] = 0x1FA2, // omega smooth grave iota lower
	[GK_WSGI_U] = 0x1FAA, // omega smooth grave iota upper
	[GK_WSC_L] = 0x1F66, // omega smooth circumflex lower
	[GK_WSC_U] = 0x1F6E, // omega smooth circumflex upper
	[GK_WSCI_L] = 0x1FA6, // omega smooth circumflex iota lower
	[GK_WSCI_U] = 0x1FAE, // omega smooth circumflex iota upper
	[GK_WSI_L] = 0x1FA0, // omega smooth iota lower
	[GK_WSI_U] = 0x1FA8, // omega smooth iota upper
	[GK_WR_L] = 0x1F61, // omega rough lower
	[GK_WR_U] = 0x1F69, // omega rough upper
	[GK_WRA_L] = 0x1F65, // omega rough acute lower
	[GK_WRA_U] = 0x1F6D, // omega rough acute upper
	[GK_WRAI_L] = 0x1FA5, // omega rough acute iota lower
	[GK_WRAI_U] = 0x1FAD, // omega rough acute iota upper
	[GK_WRG_L] = 0x1F63, // omega rough grave lower
	[GK_WRG_U] = 0x1F6B, // omega rough grave upper
	[GK_WRGI_L] = 0x1FA3, // omega rough grave iota lower
	[GK_WRGI_U] = 0x1FAB, // omega rough grave iota upper
	[GK_WRC_L] = 0x1F67, // omega rough cirumflex lower
	[GK_WRC_U] = 0x1F6F, // omega rough cirumflex upper
	[GK_WRCI_L] = 0x1FA7, // omega rough cirumflex iota lower
	[GK_WRCI_U] = 0x1FAF, // omega rough cirumflex iota upper
	[GK_WRI_L] = 0x1FA1, // omega rough iota lower
	[GK_WRI_U] = 0x1FA9, // omega rough iota upper
	[GK_WA_L] = 0x03CE, // omega acute lower
	[GK_WA_U] = 0x038F, // omega acute upper
	[GK_WAI_L] = 0x1FF4, // omega acute iota lower
	[GK_WAI_U] = 0x1FF4, // omega acute iota upper
	[GK_WG_L] = 0x1F7C, // omega grave lower
	[GK_WG_U] = 0x1FFA, // omega grave upper
	[GK_WGI_L] = 0x1FF2, // omega grave iota lower
	[GK_WGI_U] = 0x1FF2, // omega grave iota upper
	[GK_WC_L] = 0x1FF6, // omega circumflex lower
	[GK_WC_U] = 0x1FF6, // omega circumflex upper
	[GK_WCI_L] = 0x1FF7, // omega circumflex iota lower
	[GK_WCI_U] = 0x1FF7, // omega circumflex iota upper
	[GK_WI_L] = 0x1FF3, // omega iota lower
	[GK_WI_U] = 0x1FFC, // omega iota upper
	[GK_KO_L] = 0x03DF, // koppa lower
	[GK_KO_U] = 0x03DE, // koppa upper
	[GK_ST_L] = 0x03DB, // stigma lower
	[GK_ST_U] = 0x03DA, // stigma upper
	[GK_SP_L] = 0x03E1, // sampi lower
	[GK_SP_U] = 0x03E0, // sampi upper
};

/*
 * GREEK ACCENTS
 */

enum letter {
    LETTER_NONE,
    ALPHA,
    EPSILON,
    ETA,
    IOTA,
    OMICRON,
    UPSILON,
    OMEGA
};

enum cas {
    CAS_NONE,
    LOWER,
    UPPER
};

enum breath {
    BREATH_NONE,
    SMOOTH,
    ROUGH
};

enum accent {
    ACCENT_NONE,
    GRAVE,
    ACUTE,
    CIRCUMFLEX
};

enum length {
    LENGTH_NONE,
    LONG,
    BREVE
};

enum mark {
    MARK_NONE,
    DIACRITIC
};

const int SMOOTH_KEY = GK_Z_L;
const int ROUGH_KEY = GK_X_L;
const int GRAVE_KEY = GK_QUES;
const int ACUTE_KEY = GK_SS_L;
const int CIRCUMFLEX_KEY = GK_PH_L;
const int LONG_KEY = GK_PS_L;
const int BREVE_KEY = GK_D_L;
const int DIACRITIC_KEY = GK_P_L;
const int ALPHA_LOWER_KEY = GK_A_L;
const int ALPHA_UPPER_KEY = GK_A_U;
const int EPSILON_LOWER_KEY = GK_E_L;
const int EPSILON_UPPER_KEY = GK_E_U;
const int ETA_LOWER_KEY = GK_H_L;
const int ETA_UPPER_KEY = GK_H_U;
const int IOTA_LOWER_KEY = GK_I_L;
const int IOTA_UPPER_KEY = GK_I_U;
const int OMICRON_LOWER_KEY = GK_O_L;
const int OMICRON_UPPER_KEY = GK_O_U;
const int UPSILON_LOWER_KEY = GK_U_L;
const int UPSILON_UPPER_KEY = GK_U_U;
const int OMEGA_LOWER_KEY = GK_W_L;
const int OMEGA_UPPER_KEY = GK_W_U;

/*
 * TRACKBALL
 */

enum trackmode {
    NORMAL,
    SLOW,
    SCROLL,
    NAV
} trackmode_t;

bool trackball_navigating = false;
bool trackball_scrolling = false;

int TRACKBALL_NAV_THRESHOLD = 8;

/*
 * TAP DANCE
 */

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  TRIPLE_TAP = 5,
  TRIPLE_HOLD = 6
};

/*
 * LAYOUTS
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ALP] = LAYOUT_split_3x5(
// ┌───────────┬───────────┬───────────┬───────────┬───────────┐                          ┌───────────┬───────────┬───────────┬───────────┬───────────┐
    TD(TD_QU),  TD(TD_W),   TD(TD_F),   TD(TD_P),   TD(TD_B),                              TD(TD_J),   TD(TD_L),   TD(TD_U),   TD(TD_Y),   TD(TD_WH),
// ├───────────┼───────────┼───────────┼───────────┼───────────┤                          ├───────────┼───────────┼───────────┼───────────┼───────────┤
    TD(TD_A),   TD(TD_R),   TD(TD_S),   TD(TD_T),   TD(TD_G),                              TD(TD_M),   TD(TD_N),   TD(TD_E),   TD(TD_I),   TD(TD_O),
// ├───────────┼───────────┼───────────┼───────────┼───────────┤┌───────────┐┌───────────┐├───────────┼───────────┼───────────┼───────────┼───────────┤
    TD(TD_Z),   TD(TD_X),   TD(TD_C),   TD(TD_D),   TD(TD_V),    TD(TD_MAC1),TD(TD_MAC2),  TD(TD_K),   TD(TD_H),   TD(TD_TH),  TD(TD_CH),  TD(TD_SH),
// └───────────┴───────────┴───────────┴───────────┴───────────┘└───────────┘└───────────┘└───────────┴───────────┴───────────┴───────────┴───────────┘
//                         ┌───────────┬───────────┬───────────┐                          ┌───────────┬───────────┬───────────┐
                            TD(TD_1SS), TD(TD_ENT), TD(TD_DEL),                            TD(TD_BSPC),TD(TD_SPC), TD(TD_RPT),
//                         └───────────┼───────────┼───────────┤                          └───────────┴───────────┴───────────┘
                                        TD(TD_TAB), TD(TD_LDR)
//                                     └───────────┴───────────┘
//
//
    ),
    [_GRK] = LAYOUT_split_3x5(
// ┌───────────────────┬───────────────────┬───────────────────┬───────────────────┬───────────────────┐                          ┌───────────────────┬───────────────────┬───────────────────┬───────────────────┬───────────────────┐
    UM(GK_QUES),        UP(GK_SS_L, GK_SS_U),UP(GK_PH_L, GK_PH_U),UP(GK_P_L, GK_P_U),UP(GK_B_L, GK_B_U),                           UP(GK_XI_L, GK_XI_U),UP(GK_L_L, GK_L_U),UP(GK_U_L, GK_U_U), UP(GK_SP_L, GK_SP_U),UM(GK_SEMI),
// ├───────────────────┼───────────────────┼───────────────────┼───────────────────┼───────────────────┤                          ├───────────────────┼───────────────────┼───────────────────┼───────────────────┼───────────────────┤
    UP(GK_A_L, GK_A_U), UP(GK_R_L, GK_R_U), UP(GK_S_L, GK_S_U), UP(GK_T_L, GK_T_U), UP(GK_G_L, GK_G_U),                            UP(GK_M_L, GK_M_U), UP(GK_N_L, GK_N_U), UP(GK_E_L, GK_E_U), UP(GK_I_L, GK_I_U), UP(GK_O_L, GK_O_U),
// ├───────────────────┼───────────────────┼───────────────────┼───────────────────┼───────────────────┤┌───────────┐┌───────────┐├───────────────────┼───────────────────┼───────────────────┼───────────────────┼───────────────────┤
    UP(GK_Z_L, GK_Z_U), UP(GK_X_L, GK_X_U), UP(GK_PS_L, GK_PS_U),UP(GK_D_L, GK_D_U),UP(GK_W_L, GK_W_U),  _______,     _______,     UP(GK_K_L, GK_K_U), UP(GK_H_L, GK_H_U), UP(GK_TH_L, GK_TH_U),UP(GK_KO_L, GK_KO_U),UP(GK_ST_L, GK_ST_U),
// └───────────────────┴───────────────────┴───────────────────┴───────────────────┴───────────────────┘└───────────┘└───────────┘└───────────────────┴───────────────────┴───────────────────┴───────────────────┴───────────────────┘
//                                         ┌───────────────────┬───────────────────┬───────────────────┐                          ┌───────────────────┬───────────────────┬───────────────────┐
                                            TD_1SS,             TD_ENT,             TD_DEL,                                        TD_BSPC,            TD_SPC,             TD_RPT,
//                                         └───────────────────┼───────────────────┼───────────────────┤                          └───────────────────┴───────────────────┴───────────────────┘
                                                                TD_TAB,             TD_LDR
//                                                             └───────────────────┴───────────────────┘
//
//
    ),
    [_MOU] = LAYOUT_split_3x5(
// ┌───────────┬───────────┬───────────┬───────────┬───────────┐                          ┌───────────┬───────────┬───────────┬───────────┬───────────┐
    _______,    _______,    _______,    _______,    _______,                               _______,    _______,    _______,    _______,    _______,
// ├───────────┼───────────┼───────────┼───────────┼───────────┤                          ├───────────┼───────────┼───────────┼───────────┼───────────┤
    _______,    _______,    _______,    _______,    _______,                               _______,    _______,    _______,    _______,    _______,
// ├───────────┼───────────┼───────────┼───────────┼───────────┤┌───────────┐┌───────────┐├───────────┼───────────┼───────────┼───────────┼───────────┤
    _______,    _______,    _______,    _______,    _______,     _______,     _______,     _______,    _______,    _______,    _______,    _______,
// └───────────┴───────────┴───────────┴───────────┴───────────┘└───────────┘└───────────┘└───────────┴───────────┴───────────┴───────────┴───────────┘
//                         ┌───────────┬───────────┬───────────┐                          ┌───────────┬───────────┬───────────┐
                            KC_BTN2,    KC_BTN1,    _______,                               _______,    _______,    _______,
//                         └───────────┼───────────┼───────────┤                          └───────────┴───────────┴───────────┘
                                        KC_BTN3,    _______
//                                     └───────────┴───────────┘
//
//
    ),
    [_SYM] = LAYOUT_split_3x5(
// ┌─────────────────────┬─────────────────────┬─────────────────────┬─────────────────────┬───────────┐                          ┌───────────┬─────────────────────┬─────────────────────┬─────────────────────┬─────────────────────┐
    KC_GRAVE,             KC_TILDE,             KC_AMPR,              KC_PIPE,              PLUS_EQUAL,                            KC_DLR,     KC_AT,                KC_CIRC,              KC_DQT,               KC_PLUS,
// ├─────────────────────┼─────────────────────┼─────────────────────┼─────────────────────┼───────────┤                          ├───────────┼─────────────────────┼─────────────────────┼─────────────────────┼─────────────────────┤
    MT(MOD_LGUI, KC_LCBR),MT(MOD_LALT, KC_RCBR),MT(MOD_LSFT, KC_LPRN),MT(MOD_LCTL, KC_RPRN),TD(TD_SYML),                           KC_ASTR,    MT(MOD_LCTL, KC_LBRC),MT(MOD_LSFT, KC_LBRC),MT(MOD_LALT, KC_UNDS),MT(MOD_LGUI, KC_MINUS),
// ├─────────────────────┼─────────────────────┼─────────────────────┼─────────────────────┼───────────┤┌───────────┐┌───────────┐├───────────┼─────────────────────┼─────────────────────┼─────────────────────┼─────────────────────┤
    KC_EXLM,              KC_EQUAL,             KC_LT,                KC_GT,                MINUS_EQUAL, _______,     _______,     KC_PERC,    KC_DOT,               KC_COMM,              KC_QUOT,              KC_SLSH,
// └─────────────────────┴─────────────────────┴─────────────────────┴─────────────────────┴───────────┘└───────────┘└───────────┘└───────────┴─────────────────────┴─────────────────────┴─────────────────────┴─────────────────────┘
//                                             ┌─────────────────────┬─────────────────────┬───────────┐                          ┌───────────┬─────────────────────┬─────────────────────┐
                                                KC_SCLN,              KC_COLN,              KC_SLSH,                               _______,    _______,              _______,
//                                             └─────────────────────┼─────────────────────┼───────────┤                          └───────────┴─────────────────────┴─────────────────────┘
                                                                      KC_HASH,              KC_BSLS
//                                                                   └─────────────────────┴───────────┘
//
//
    ),
    [_NAV] = LAYOUT_split_3x5(
// ┌───────────┬───────────┬───────────┬───────────┬───────────┐                          ┌───────────┬───────────┬───────────┬───────────┬───────────┐
    LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_Y),                            LCTL(KC_Y), LCTL(KC_V), LCTL(KC_C), LCTL(KC_X), LCTL(KC_Z),
// ├───────────┼───────────┼───────────┼───────────┼───────────┤                          ├───────────┼───────────┼───────────┼───────────┼───────────┤
    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   TD(TD_NAVL),                           _______,    KC_LCTL,    KC_LSFT,    KC_LALT,    KC_LGUI,
// ├───────────┼───────────┼───────────┼───────────┼───────────┤┌───────────┐┌───────────┐├───────────┼───────────┼───────────┼───────────┼───────────┤
    KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_INS,      _______,     _______,     LCTL(KC_Y), LCTL(KC_V), LCTL(KC_C), LCTL(KC_X), LCTL(KC_Z),
// └───────────┴───────────┴───────────┴───────────┴───────────┘└───────────┘└───────────┘└───────────┴───────────┴───────────┴───────────┴───────────┘
//                         ┌───────────┬───────────┬───────────┐                          ┌───────────┬───────────┬───────────┐
                            _______,    _______,    _______,                               _______,    _______,    _______,
//                         └───────────┼───────────┼───────────┤                          └───────────┴───────────┴───────────┘
                                        _______,    _______
//                                     └───────────┴───────────┘
//
//
    ),
    [_NUM] = LAYOUT_split_3x5(
// ┌─────────────────────┬─────────────────────┬─────────────────────┬─────────────────────┬───────────┐                          ┌───────────┬─────────────────────┬─────────────────────┬─────────────────────┬─────────────────────┐
    KC_GRAVE,             KC_TILDE,             KC_AMPR,              KC_PIPE,              PLUS_EQUAL,                            KC_DLR,     KC_7,                 KC_8,                 KC_9,                 KC_PLUS,
// ├─────────────────────┼─────────────────────┼─────────────────────┼─────────────────────┼───────────┤                          ├───────────┼─────────────────────┼─────────────────────┼─────────────────────┼─────────────────────┤
    MT(MOD_LGUI, KC_LCBR),MT(MOD_LALT, KC_RCBR),MT(MOD_LSFT, KC_LPRN),MT(MOD_LCTL, KC_RPRN),TD(TD_NUML),                           KC_ASTR,    MT(MOD_LCTL, KC_4),   MT(MOD_LSFT, KC_5),   MT(MOD_LALT, KC_6),   MT(MOD_LGUI, KC_MINUS),
// ├─────────────────────┼─────────────────────┼─────────────────────┼─────────────────────┼───────────┤┌───────────┐┌───────────┐├───────────┼─────────────────────┼─────────────────────┼─────────────────────┼─────────────────────┤
    KC_EXLM,              KC_EQUAL,             KC_LT,                KC_GT,                MINUS_EQUAL, _______,     _______,     KC_PERC,    KC_1,                 KC_2,                 KC_3,                 KC_SLSH,
// └─────────────────────┴─────────────────────┴─────────────────────┴─────────────────────┴───────────┘└───────────┘└───────────┘└───────────┴─────────────────────┴─────────────────────┴─────────────────────┴─────────────────────┘
//                                             ┌─────────────────────┬─────────────────────┬───────────┐                          ┌───────────┬─────────────────────┬─────────────────────┐
                                                _______,              _______,              _______,                               KC_COMM,    KC_0,                 KC_DOT,
//                                             └─────────────────────┼─────────────────────┼───────────┤                          └───────────┴─────────────────────┴─────────────────────┘
                                                                      _______,              _______
//                                                                   └─────────────────────┴───────────┘
//
//
    ),
    [_FUN] = LAYOUT_split_3x5(
// ┌───────────┬───────────┬───────────┬───────────┬───────────┐                          ┌───────────┬─────────────────────┬─────────────────────┬─────────────────────┬─────────────────────┐
    LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_Y),                            KC_F12,     KC_F7,                KC_F8,                KC_F9,                KC_F15,
// ├───────────┼───────────┼───────────┼───────────┼───────────┤                          ├───────────┼─────────────────────┼─────────────────────┼─────────────────────┼─────────────────────┤
    KC_LGUI,    KC_LALT,    KC_LSFT,    KC_LCTL,    TD(TD_FUNL),                           KC_F11,     MT(MOD_LCTL, KC_F4),  MT(MOD_LSFT, KC_F5),  MT(MOD_LALT, KC_F6),  MT(MOD_LGUI, KC_F14),
// ├───────────┼───────────┼───────────┼───────────┼───────────┤┌───────────┐┌───────────┐├───────────┼─────────────────────┼─────────────────────┼─────────────────────┼─────────────────────┤
    LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_Y),  _______,     _______,     KC_F10,     KC_F1,                KC_F2,                KC_F3,                KC_F13,
// └───────────┴───────────┴───────────┴───────────┴───────────┘└───────────┘└───────────┘└───────────┴─────────────────────┴─────────────────────┴─────────────────────┴─────────────────────┘
//                         ┌───────────┬───────────┬───────────┐                          ┌───────────┬─────────────────────┬─────────────────────┐
                            _______,    _______,    _______,                               KC_F16,     KC_F17,               KC_F18,
//                         └───────────┼───────────┼───────────┤                          └───────────┴─────────────────────┴─────────────────────┘
                                        _______,    _______
//                                     └───────────┴───────────┘
//
//
    ),
};

/*
 * ENCODERS
 */

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_ALP] =   { ENCODER_CCW_CW(KC_F19, KC_F21), ENCODER_CCW_CW(KC_F22, KC_F24)  },
    [_GRK] =   { ENCODER_CCW_CW(KC_F19, KC_F21), ENCODER_CCW_CW(KC_F22, KC_F24)  },
    [_MOU] =   { ENCODER_CCW_CW(KC_F19, KC_F21), ENCODER_CCW_CW(KC_F22, KC_F24)  },
    [_SYM] =   { ENCODER_CCW_CW(KC_F19, KC_F21), ENCODER_CCW_CW(KC_F22, KC_F24)  },
    [_NAV] =   { ENCODER_CCW_CW(KC_F19, KC_F21), ENCODER_CCW_CW(KC_F22, KC_F24)  },
    [_NUM] =   { ENCODER_CCW_CW(KC_F19, KC_F21), ENCODER_CCW_CW(KC_F22, KC_F24)  },
    [_FUN] =   { ENCODER_CCW_CW(KC_F19, KC_F21), ENCODER_CCW_CW(KC_F22, KC_F24)  }
};
#endif

/*
 * OLEDS
 */
 #ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return OLED_ROTATION_90;
}

 bool oled_task_user(void) {
    if (is_keyboard_master()) {

    } else {

    }
    return false;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    //Sentence Case
  if (!process_sentence_case(keycode, record)) { return false; }
  //Layuer Lock
  if (!process_layer_lock(keycode, record, LL_TOGG)) { return false; }
  switch (keycode) {
    /*
    * MACROS
    */
    case PLUS_EQUAL:
        if (record->event.pressed) {
            SEND_STRING("+=");
        }
        return false;
    case MINUS_EQUAL:
        if (record->event.pressed) {
            SEND_STRING("-=");
        }
        return false;
  }
  return true;
}

/*
 * COMBOS
 */

// Capsword with home thumbs
const uint16_t PROGMEM capsword[] = {KC_ENT, KC_SPC, COMBO_END};
const uint16_t PROGMEM autocorrect[] = {KC_DEL, KC_BSPC, COMBO_END};
combo_t key_combos[] = {
    COMBO(capsword, CW_TOGG),
    COMBO(autocorrect, AC_TOGG)
};

void trackball_mode_on(int mode) {
    switch (mode) {
        case NORMAL:
            pointing_device_set_cpi(2000);
            trackball_navigating = false;
            trackball_scrolling = false;
            break;
        case SLOW:
            trackball_mode_on(NORMAL);
            pointing_device_set_cpi(1000);
            break;
        case SCROLL:
            trackball_mode_on(NORMAL);
            trackball_scrolling = true;
            break;
        case NAV:
            trackball_mode_on(NORMAL);
            trackball_navigating = true;
            break;
    }
}

void pointing_device_init_user(void) {
    set_auto_mouse_layer(_MOU);
    set_auto_mouse_enable(true);
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (trackball_navigating) {
        if (mouse_report.x > TRACKBALL_NAV_THRESHOLD) {
            tap_code(KC_RIGHT);
        } else if (mouse_report.y < -TRACKBALL_NAV_THRESHOLD) {
            tap_code(KC_LEFT);
        }
        if (mouse_report.y > TRACKBALL_NAV_THRESHOLD) {
            tap_code(KC_UP);
        } else if (mouse_report.y < -TRACKBALL_NAV_THRESHOLD) {
            tap_code(KC_DOWN);
        }
        mouse_report.x = 0;
        mouse_report.y = 0;
        mouse_report.h = 0;
        mouse_report.v = 0;
    } else if (trackball_scrolling) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

/*
 * HYPER
 */

void hyper_on(void) {
    register_code(KC_LCTL);
    register_code(KC_LALT);
    register_code(KC_LSFT);
    register_code(KC_LGUI);
}

void hyper_off(void) {
    unregister_code(KC_LCTL);
    unregister_code(KC_LALT);
    unregister_code(KC_LSFT);
    unregister_code(KC_LGUI);
}

uint16_t check_greek_sequence(void) {
    enum letter lt = LETTER_NONE;
    enum cas ca = CAS_NONE;
    enum breath br = BREATH_NONE;
    enum accent ac = ACCENT_NONE;
    enum length ln = LENGTH_NONE;
    enum mark mk = MARK_NONE;
    bool has_iota = false;
    uint16_t *seq = get_leader_sequence();
    // memcpy(seq, get_leader_sequence(), 5);
    for (int i=0; i<5; i++) {
        int s = *(seq+i);
        if (s != 0) {
            switch (s) {
            case SMOOTH_KEY:
                br = SMOOTH;
                break;
            case ROUGH_KEY:
                br = ROUGH;
                break;
            case GRAVE_KEY:
                ac = GRAVE;
                break;
            case ACUTE_KEY:
                ac = ACUTE;
                break;
            case CIRCUMFLEX_KEY:
                ac = CIRCUMFLEX;
                break;
            case LONG_KEY:
                ln = LONG;
                break;
            case BREVE_KEY:
                ln = BREVE;
                break;
            case DIACRITIC_KEY:
                mk = DIACRITIC;
                break;
            case ALPHA_LOWER_KEY:
                lt = ALPHA;
                ca = LOWER;
                break;
            case ALPHA_UPPER_KEY:
                lt = ALPHA;
                ca = UPPER;
                break;
            case EPSILON_LOWER_KEY:
                lt = EPSILON;
                ca = LOWER;
                break;
            case EPSILON_UPPER_KEY:
                lt = EPSILON;
                ca = UPPER;
                break;
            case ETA_LOWER_KEY:
                lt = ETA;
                ca = LOWER;
                break;
            case ETA_UPPER_KEY:
                lt = ETA;
                ca = UPPER;
                break;
            case IOTA_LOWER_KEY:
                has_iota = true;
                lt = IOTA;
                ca = LOWER;
                break;
            case IOTA_UPPER_KEY:
                has_iota = true;
                lt = IOTA;
                ca = UPPER;
                break;
            case OMICRON_LOWER_KEY:
                lt = OMICRON;
                ca = LOWER;
                break;
            case OMICRON_UPPER_KEY:
                lt = OMICRON;
                ca = UPPER;
                break;
            case UPSILON_LOWER_KEY:
                lt = UPSILON;
                ca = LOWER;
                break;
            case UPSILON_UPPER_KEY:
                lt = UPSILON;
                ca = UPPER;
                break;
            case OMEGA_LOWER_KEY:
                lt = OMEGA;
                ca = LOWER;
                break;
            case OMEGA_UPPER_KEY:
                lt = OMEGA;
                ca = UPPER;
                break;
            default:
                return -1;
            }
        }
    }
    switch (lt) {
    case ALPHA:
        if (ln == LONG) {
            if (ca == LOWER) {
                return GK_AL_L;
            } else {
                return GK_AL_U;
            }
        } else if (ln == BREVE) {
            if (ca == LOWER) {
                return GK_AB_L;
            } else {
                return GK_AB_U;
            }
        }
        switch (br) {
        case SMOOTH:
            switch (ac) {
            case ACUTE:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_ASAI_L;
                    } else {
                        return GK_ASAI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_ASA_L;
                    } else {
                        return GK_ASA_U;
                    }
                }
                break;
            case GRAVE:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_ASGI_L;
                    } else {
                        return GK_ASGI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_ASG_L;
                    } else {
                        return GK_ASG_U;
                    }
                }
                break;
            case CIRCUMFLEX:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_ASCI_L;
                    } else {
                        return GK_ASCI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_ASC_L;
                    } else {
                        return GK_ASC_U;
                    }
                }
                break;
            default:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_ASI_L;
                    } else {
                        return GK_ASI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_AS_L;
                    } else {
                        return GK_AS_U;
                    }
                }
                break;
            }
            break;
        case ROUGH:
            switch (ac) {
            case ACUTE:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_ARAI_L;
                    } else {
                        return GK_ARAI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_ARA_L;
                    } else {
                        return GK_ARA_U;
                    }
                }
                break;
            case GRAVE:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_ARGI_L;
                    } else {
                        return GK_ARGI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_ARG_L;
                    } else {
                        return GK_ARG_U;
                    }
                }
                break;
            case CIRCUMFLEX:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_ARCI_L;
                    } else {
                        return GK_ARCI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_ARC_L;
                    } else {
                        return GK_ARC_U;
                    }
                }
                break;
            default:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_ARI_L;
                    } else {
                        return GK_ARI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_AR_L;
                    } else {
                        return GK_AR_U;
                    }
                }
                break;
            }
            break;
        case BREATH_NONE:
            switch (ac) {
            case ACUTE:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_AAI_L;
                    } else {
                        return GK_AAI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_AA_L;
                    } else {
                        return GK_AA_U;
                    }
                }
                break;
            case GRAVE:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_AGI_L;
                    } else {
                        return GK_AGI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_AG_L;
                    } else {
                        return GK_AG_U;
                    }
                }
                break;
            case CIRCUMFLEX:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_AC_L;
                    } else {
                        return GK_AC_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_A_L;
                    } else {
                        return GK_A_U;
                    }
                }
                break;
            default:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_AI_L;
                    } else {
                        return GK_AI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_A_L;
                    } else {
                        return GK_A_U;
                    }
                }
                break;
            }
            break;
        }
        break;
    case EPSILON:
        switch (br) {
        case SMOOTH:
            switch (ac) {
            case ACUTE:
                if (ca == LOWER) {
                    return GK_ESA_L;
                } else {
                    return GK_ESA_U;
                }
                break;
            case GRAVE:
                if (ca == LOWER) {
                    return GK_ESG_L;
                } else {
                    return GK_ESG_U;
                }
                break;
            default:
                if (ca == LOWER) {
                    return GK_ES_L;
                } else {
                    return GK_ES_U;
                }
                break;
            }
            break;
        case ROUGH:
            switch (ac) {
            case ACUTE:
                if (ca == LOWER) {
                    return GK_ERA_L;
                } else {
                    return GK_ERA_U;
                }
                break;
            case GRAVE:
                if (ca == LOWER) {
                    return GK_ERG_L;
                } else {
                    return GK_ERG_U;
                }
                break;
            default:
                if (ca == LOWER) {
                    return GK_ER_L;
                } else {
                    return GK_ER_U;
                }
                break;
            }
            break;
        case BREATH_NONE:
            switch (ac) {
            case ACUTE:
                if (ca == LOWER) {
                    return GK_EA_L;
                } else {
                    return GK_EA_U;
                }
                break;
            case GRAVE:
                if (ca == LOWER) {
                    return GK_EG_L;
                } else {
                    return GK_EG_U;
                }
                break;
            default:
                if (ca == LOWER) {
                    return GK_E_L;
                } else {
                    return GK_E_U;
                }
                break;
            }
            break;
        }
        break;
    case ETA:
        switch (br) {
        case SMOOTH:
            switch (ac) {
            case ACUTE:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_HSAI_L;
                    } else {
                        return GK_HSAI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_HSA_L;
                    } else {
                        return GK_HSA_U;
                    }
                }
                break;
            case GRAVE:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_HSGI_L;
                    } else {
                        return GK_HSGI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_HSG_L;
                    } else {
                        return GK_HSG_U;
                    }
                }
                break;
            case CIRCUMFLEX:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_HSCI_L;
                    } else {
                        return GK_HSCI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_HSC_L;
                    } else {
                        return GK_HSC_U;
                    }
                }
                break;
            default:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_HSI_L;
                    } else {
                        return GK_HSI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_HS_L;
                    } else {
                        return GK_HS_U;
                    }
                }
                break;
            }
            break;
        case ROUGH:
            switch (ac) {
            case ACUTE:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_HRAI_L;
                    } else {
                        return GK_HRAI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_HRA_L;
                    } else {
                        return GK_HRA_U;
                    }
                }
                break;
            case GRAVE:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_HRGI_L;
                    } else {
                        return GK_HRGI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_HRG_L;
                    } else {
                        return GK_HRG_U;
                    }
                }
                break;
            case CIRCUMFLEX:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_HRCI_L;
                    } else {
                        return GK_HRCI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_HRC_L;
                    } else {
                        return GK_HRC_U;
                    }
                }
                break;
            default:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_HRI_L;
                    } else {
                        return GK_HRI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_HR_L;
                    } else {
                        return GK_HR_U;
                    }
                }
                break;
            }
            break;
        case BREATH_NONE:
            switch (ac) {
            case ACUTE:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_HAI_L;
                    } else {
                        return GK_HAI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_HA_L;
                    } else {
                        return GK_HA_U;
                    }
                }
                break;
            case GRAVE:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_HGI_L;
                    } else {
                        return GK_HGI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_HG_L;
                    } else {
                        return GK_HG_U;
                    }
                }
                break;
            case CIRCUMFLEX:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_HCI_L;
                    } else {
                        return GK_HCI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_HC_L;
                    } else {
                        return GK_HC_U;
                    }
                }
                break;
            default:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_HI_L;
                    } else {
                        return GK_HI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_H_L;
                    } else {
                        return GK_H_U;
                    }
                }
                break;
            }
            break;
        }
        break;
    case IOTA:
        if (ln == LONG) {
            if (ca == LOWER) {
                return GK_IL_L;
            } else {
                return GK_IL_U;
            }
        } else if (ln == BREVE) {
            if (ca == LOWER) {
                return GK_IB_L;
            } else {
                return GK_IB_U;
            }
        }
        switch (br) {
        case SMOOTH:
            switch (ac) {
            case ACUTE:
                if (ca == LOWER) {
                    return GK_ISA_L;
                } else {
                    return GK_ISA_U;
                }
                break;
            case GRAVE:
                if (ca == LOWER) {
                    return GK_ISG_L;
                } else {
                    return GK_ISG_U;
                }
                break;
            case CIRCUMFLEX:
                if (ca == LOWER) {
                    return GK_ISC_L;
                } else {
                    return GK_ISC_U;
                }
                break;
            default:
                if (ca == LOWER) {
                    return GK_IS_L;
                } else {
                    return GK_IS_U;
                }
                break;
            }
            break;
        case ROUGH:
            switch (ac) {
            case ACUTE:
                if (ca == LOWER) {
                    return GK_IRA_L;
                } else {
                    return GK_IRA_U;
                }
                break;
            case GRAVE:
                if (ca == LOWER) {
                    return GK_IRG_L;
                } else {
                    return GK_IRG_U;
                }
                break;
            case CIRCUMFLEX:
                if (ca == LOWER) {
                    return GK_IRC_L;
                } else {
                    return GK_IRC_U;
                }
                break;
            default:
                if (ca == LOWER) {
                    return GK_IR_L;
                } else {
                    return GK_IR_U;
                }
                break;
            }
            break;
        case BREATH_NONE:
            switch (ac) {
            case ACUTE:
                if (mk == DIACRITIC) {
                    if (ca == LOWER) {
                        return GK_IDA_L;
                    } else {
                        return GK_IDA_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_IA_L;
                    } else {
                        return GK_IA_U;
                    }
                }
                break;
            case GRAVE:
                if (mk == DIACRITIC) {
                    if (ca == LOWER) {
                        return GK_IDG_L;
                    } else {
                        return GK_IDG_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_IG_L;
                    } else {
                        return GK_IG_U;
                    }
                }
                break;
            case CIRCUMFLEX:
                if (mk == DIACRITIC) {
                    if (ca == LOWER) {
                        return GK_IDC_L;
                    } else {
                        return GK_IDC_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_IC_L;
                    } else {
                        return GK_IC_U;
                    }
                }
                break;
            default:
                if (mk == DIACRITIC) {
                    if (ca == LOWER) {
                        return GK_ID_L;
                    } else {
                        return GK_ID_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_I_L;
                    } else {
                        return GK_I_U;
                    }
                }
                break;
            }
            break;
        }
        break;
    case OMICRON:
        switch (br) {
        case SMOOTH:
            switch (ac) {
            case ACUTE:
                if (ca == LOWER) {
                    return GK_OSA_L;
                } else {
                    return GK_OSA_U;
                }
                break;
            case GRAVE:
                if (ca == LOWER) {
                    return GK_OSG_L;
                } else {
                    return GK_OSG_U;
                }
                break;
            default:
                if (ca == LOWER) {
                    return GK_OS_L;
                } else {
                    return GK_OS_U;
                }
                break;
            }
            break;
        case ROUGH:
            switch (ac) {
            case ACUTE:
                if (ca == LOWER) {
                    return GK_ORA_L;
                } else {
                    return GK_ORA_U;
                }
                break;
            case GRAVE:
                if (ca == LOWER) {
                    return GK_ORG_L;
                } else {
                    return GK_ORG_U;
                }
                break;
            default:
                if (ca == LOWER) {
                    return GK_OR_L;
                } else {
                    return GK_OR_U;
                }
                break;
            }
            break;
        case BREATH_NONE:
            switch (ac) {
            case ACUTE:
                if (ca == LOWER) {
                    return GK_OA_L;
                } else {
                    return GK_OA_U;
                }
                break;
            case GRAVE:
                if (ca == LOWER) {
                    return GK_OG_L;
                } else {
                    return GK_OG_U;
                }
                break;
            default:
                if (ca == LOWER) {
                    return GK_O_L;
                } else {
                    return GK_O_U;
                }
                break;
            }
            break;
        }
        break;
    case UPSILON:
        if (ln == LONG) {
            if (ca == LOWER) {
                return GK_UL_L;
            } else {
                return GK_UL_U;
            }
        } else if (ln == BREVE) {
            if (ca == LOWER) {
                return GK_UB_L;
            } else {
                return GK_UB_U;
            }
        }
        switch (br) {
        case SMOOTH:
            switch (ac) {
            case ACUTE:
                if (ca == LOWER) {
                    return GK_USA_L;
                } else {
                    return GK_USA_U;
                }
                break;
            case GRAVE:
                if (ca == LOWER) {
                    return GK_USG_L;
                } else {
                    return GK_USG_U;
                }
                break;
            case CIRCUMFLEX:
                if (ca == LOWER) {
                    return GK_USC_L;
                } else {
                    return GK_USC_U;
                }
                break;
            default:
                if (ca == LOWER) {
                    return GK_US_L;
                } else {
                    return GK_US_U;
                }
                break;
            }
            break;
        case ROUGH:
            switch (ac) {
            case ACUTE:
                if (ca == LOWER) {
                    return GK_URA_L;
                } else {
                    return GK_URA_U;
                }
                break;
            case GRAVE:
                if (ca == LOWER) {
                    return GK_URG_L;
                } else {
                    return GK_URG_U;
                }
                break;
            case CIRCUMFLEX:
                if (ca == LOWER) {
                    return GK_URC_L;
                } else {
                    return GK_URC_U;
                }
                break;
            default:
                if (ca == LOWER) {
                    return GK_UR_L;
                } else {
                    return GK_UR_U;
                }
                break;
            }
            break;
        case BREATH_NONE:
            switch (ac) {
            case ACUTE:
                if (mk == DIACRITIC) {
                    if (ca == LOWER) {
                        return GK_UDA_L;
                    } else {
                        return GK_UDA_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_UA_L;
                    } else {
                        return GK_UA_U;
                    }
                }
                break;
            case GRAVE:
                if (mk == DIACRITIC) {
                    if (ca == LOWER) {
                        return GK_UDG_L;
                    } else {
                        return GK_UDG_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_UG_L;
                    } else {
                        return GK_UG_U;
                    }
                }
                break;
            case CIRCUMFLEX:
                if (mk == DIACRITIC) {
                    if (ca == LOWER) {
                        return GK_UDC_L;
                    } else {
                        return GK_UDC_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_UC_L;
                    } else {
                        return GK_UC_U;
                    }
                }
                break;
            default:
                if (mk == DIACRITIC) {
                    if (ca == LOWER) {
                        return GK_UD_L;
                    } else {
                        return GK_UD_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_U_L;
                    } else {
                        return GK_U_U;
                    }
                }
                break;
            }
            break;
        }
        break;
    case OMEGA:
        switch (br) {
        case SMOOTH:
            switch (ac) {
            case ACUTE:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_WSAI_L;
                    } else {
                        return GK_WSAI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_WSA_L;
                    } else {
                        return GK_WSA_U;
                    }
                }
                break;
            case GRAVE:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_WSGI_L;
                    } else {
                        return GK_WSGI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_WSG_L;
                    } else {
                        return GK_WSG_U;
                    }
                }
                break;
            case CIRCUMFLEX:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_WSCI_L;
                    } else {
                        return GK_WSCI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_WSC_L;
                    } else {
                        return GK_WSC_U;
                    }
                }
                break;
            default:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_WSI_L;
                    } else {
                        return GK_WSI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_WS_L;
                    } else {
                        return GK_WS_U;
                    }
                }
                break;
            }
            break;
        case ROUGH:
            switch (ac) {
            case ACUTE:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_WRAI_L;
                    } else {
                        return GK_WRAI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_WRA_L;
                    } else {
                        return GK_WRA_U;
                    }
                }
                break;
            case GRAVE:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_WRGI_L;
                    } else {
                        return GK_WRGI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_WRG_L;
                    } else {
                        return GK_WRG_U;
                    }
                }
                break;
            case CIRCUMFLEX:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_WRCI_L;
                    } else {
                        return GK_WRCI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_WRC_L;
                    } else {
                        return GK_WRC_U;
                    }
                }
                break;
            default:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_WRI_L;
                    } else {
                        return GK_WRI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_WR_L;
                    } else {
                        return GK_WR_U;
                    }
                }
                break;
            }
            break;
        case BREATH_NONE:
            switch (ac) {
            case ACUTE:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_WAI_L;
                    } else {
                        return GK_WAI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_WA_L;
                    } else {
                        return GK_WA_U;
                    }
                }
                break;
            case GRAVE:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_WGI_L;
                    } else {
                        return GK_WGI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_WG_L;
                    } else {
                        return GK_WG_U;
                    }
                }
                break;
            case CIRCUMFLEX:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_WCI_L;
                    } else {
                        return GK_WCI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_WC_L;
                    } else {
                        return GK_WC_U;
                    }
                }
                break;
            default:
                if (has_iota) {
                    if (ca == LOWER) {
                        return GK_WI_L;
                    } else {
                        return GK_WI_U;
                    }
                } else {
                    if (ca == LOWER) {
                        return GK_W_L;
                    } else {
                        return GK_W_U;
                    }
                }
                break;
            }
            break;
        }
        break;
    default:
        return -1;
    }
    return -1;
}



/*
 * LEADERS
 */

void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_Q, KC_U)) {
        SEND_STRING("jakekausler@gmail.com");
        return;
    } else if (leader_sequence_one_key(KC_W)) {
        SEND_STRING("jakekausler");
        return;
    } else if (leader_sequence_one_key(KC_F)) {
        SEND_STRING("Jake021f2f1!");
        return;
    }
    uint16_t kc = check_greek_sequence();
    if (kc != -1) {
        tap_code(kc);
    }
}

int cur_dance (tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}


void modifier_tap_codes(int8_t modifiers[], int len, int8_t kc) {
    for (int m=0; m < len; m++) {
        register_code(modifiers[m]);
    }
    tap_code(kc);
    for (int m=len-1; m >= 0; m--) {
        unregister_code(modifiers[m]);
    }
}

void tap_multiple(int8_t kc[], int len) {
    tap_code(kc[0]);
    if (len == 1) {
        return;
    }
    bool l_shift_active = get_mods() & MOD_BIT(KC_LSFT);
    bool r_shift_active = get_mods() & MOD_BIT(KC_RSFT);
    if (l_shift_active) {
        unregister_mods(KC_LSFT);
    }
    if (r_shift_active) {
        unregister_mods(KC_RSFT);
    }
    for (int i=1; i < len; i++) {
        tap_code(kc[i]);
    }
    if (l_shift_active) {
        register_mods(KC_LSFT);
    }
    if (r_shift_active) {
        register_mods(KC_RSFT);
    }
}

void td_qu_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr[] = {KC_Q, KC_U};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_multiple(arr, 2);
            break;
        case DOUBLE_TAP:
            tap_code(KC_Q);
            reset_tap_dance(state);
            break;
    }
}
void td_w_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr[] = {KC_LCTL};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_W);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes(arr, 1, KC_W);
            reset_tap_dance(state);
            break;
    }
}
void td_f_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr[] = {KC_LCTL};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_F);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes(arr, 1, KC_T);
            reset_tap_dance(state);
            break;
    }
}
void td_p_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr[] = {KC_LCTL};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_P);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes(arr, 1, KC_PGUP);
            reset_tap_dance(state);
            break;
    }
}
void td_b_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_B);
            break;
        case DOUBLE_TAP:
            reset_tap_dance(state);
            break;
    }
}
void td_a_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr[] = {KC_LCTL, KC_LSFT};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_A);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes(arr, 2, KC_LEFT);
            reset_tap_dance(state);
            break;
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            register_code(KC_LGUI);
            break;
    }
}
void td_a_reset(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            unregister_code(KC_LGUI);
            break;
    }
}
void td_r_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr[] = {KC_LCTL, KC_LSFT};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_R);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes(arr, 2, KC_DOWN);
            reset_tap_dance(state);
            break;
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            register_code(KC_LALT);
            break;
    }
}
void td_r_reset(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            unregister_code(KC_LALT);
            break;
    }
}
void td_s_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr[] = {KC_LCTL, KC_LSFT};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_S);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes(arr, 2, KC_UP);
            reset_tap_dance(state);
            break;
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            register_code(KC_LSFT);
            break;
    }
}
void td_s_reset(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            unregister_code(KC_LSFT);
            break;
    }
}
void td_t_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr[] = {KC_LCTL, KC_LSFT};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_T);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes(arr, 2, KC_RIGHT);
            reset_tap_dance(state);
            break;
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            register_code(KC_LCTL);
            break;
    }
}
void td_t_reset(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            unregister_code(KC_LCTL);
            break;
    }
}
void td_g_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr[] = {KC_G, KC_H};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_G);
            break;
        case DOUBLE_TAP:
            tap_multiple(arr, 2);
            reset_tap_dance(state);
            break;
    }
}
void td_z_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr0[] = {KC_LCTL};
    int8_t arr1[] = {KC_LCTL, KC_LSFT};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_Z);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes(arr0, 1, KC_Z);
            break;
        case TRIPLE_TAP:
            modifier_tap_codes(arr1, 2, KC_Z);
            reset_tap_dance(state);
            break;
    }
}
void td_x_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr[] = {KC_LCTL};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_X);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes(arr, 1, KC_X);
            reset_tap_dance(state);
            break;
    }
}
void td_c_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr[] = {KC_LCTL};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_C);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes(arr, 1, KC_C);
            reset_tap_dance(state);
            break;
    }
}
void td_d_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr[] = {KC_LCTL};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_D);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes(arr, 1, KC_D);
            reset_tap_dance(state);
            break;
    }
}
void td_v_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr[] = {KC_LCTL};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_V);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes(arr, 1, KC_V);
            reset_tap_dance(state);
            break;
    }
}
void td_j_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr[] = {KC_LALT,KC_LSFT};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_J);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes(arr, 2, KC_TAB);
            reset_tap_dance(state);
            break;
    }
}
void td_l_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr[] = {KC_LALT};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_L);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes(arr, 1, KC_TAB);
            reset_tap_dance(state);
            break;
    }
}
void td_u_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr0[] = {KC_LCTL};
    int8_t arr1[] = {KC_LCTL,KC_LSFT};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_U);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes(arr0, 1, KC_F);
            break;
        case TRIPLE_TAP:
            modifier_tap_codes(arr1, 2, KC_F);
            reset_tap_dance(state);
            break;
    }
}
void td_y_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr0[] = {KC_LCTL};
    int8_t arr1[] = {KC_LCTL,KC_LSFT};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_Y);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes(arr0, 1, KC_H);
            break;
        case TRIPLE_TAP:
            modifier_tap_codes(arr1, 2, KC_H);
            reset_tap_dance(state);
            break;
    }
}
void td_wh_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr0[] = {KC_W, KC_H};
    int8_t arr1[] = {KC_O, KC_U};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_multiple(arr0, 2);
            break;
        case DOUBLE_TAP:
            tap_multiple(arr1, 2);
            reset_tap_dance(state);
            break;
    }
}
void td_m_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr0[] = {KC_LCTL};
    int8_t arr1[] = {KC_LCTL, KC_LSFT};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_M);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes(arr0, 1, KC_P);
            break;
        case TRIPLE_TAP:
            modifier_tap_codes(arr1, 2, KC_P);
            reset_tap_dance(state);
            break;
    }
}
void td_n_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr[] = {KC_LCTL};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_N);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes(arr, 1, KC_LEFT);
            reset_tap_dance(state);
            break;
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            register_code(KC_LCTL);
            break;
    }
}
void td_n_reset(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            unregister_code(KC_LCTL);
            break;
    }
}
void td_e_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr[] = {KC_LCTL};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_E);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes(arr, 1, KC_UP);
            reset_tap_dance(state);
            break;
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            register_code(KC_LSFT);
            break;
    }
}
void td_e_reset(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            unregister_code(KC_LSFT);
            break;
    }
}
void td_i_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr[] = {KC_LCTL};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_I);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes(arr, 1, KC_DOWN);
            reset_tap_dance(state);
            break;
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            register_code(KC_LALT);
            break;
    }
}
void td_i_reset(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            unregister_code(KC_LALT);
            break;
    }
}
void td_o_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr[] = {KC_LCTL};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_O);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes(arr, 1, KC_RIGHT);
            reset_tap_dance(state);
            break;
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            register_code(KC_LGUI);
            break;
    }
}
void td_o_reset(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            unregister_code(KC_LGUI);
            break;
    }
}
void td_k_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr[] = {KC_LCTL,KC_LSFT};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_K);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes(arr, 2, KC_K);
            reset_tap_dance(state);
            break;
    }
}
void td_h_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr[] = {KC_LCTL};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_H);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes(arr, 1, KC_L);
            reset_tap_dance(state);
            break;
    }
}
void td_th_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr0[] = {KC_T, KC_H};
    int8_t arr1[] = {KC_T, KC_H, KC_E};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_multiple(arr0, 2);
            break;
        case DOUBLE_TAP:
            tap_multiple(arr1, 3);
            reset_tap_dance(state);
            break;
    }
}
void td_ch_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr0[] = {KC_C, KC_H};
    int8_t arr1[] = {KC_A, KC_N, KC_D};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_multiple(arr0, 2);
            break;
        case DOUBLE_TAP:
            tap_multiple(arr1, 3);
            reset_tap_dance(state);
            break;
    }
}
void td_sh_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr0[] = {KC_S, KC_H};
    int8_t arr1[] = {KC_I, KC_N, KC_G};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_multiple(arr0, 2);
            break;
        case DOUBLE_TAP:
            tap_multiple(arr1, 3);
            reset_tap_dance(state);
            break;
    }
}
void td_bspc_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_BSPC);
            break;
        case DOUBLE_TAP:
            tap_code(KC_COMM);
            break;
        case TRIPLE_TAP:
            tap_code(KC_COMM);tap_code(KC_SPC);
            reset_tap_dance(state);
            break;
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            hyper_on();
    }
}
void td_bspc_reset(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            hyper_off();
    }
}

void td_spc_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_SPC);
            break;
        case DOUBLE_TAP:
            tap_code(KC_DOT);
            break;
        case TRIPLE_TAP:
            tap_code(KC_DOT);tap_code(KC_SPC);
            reset_tap_dance(state);
            break;
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            layer_on(_SYM);
    }
}
void td_spc_reset(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            layer_off(_SYM);
    }
}

void td_rpt_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code16(QK_REP);
            reset_tap_dance(state);
            break;
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            layer_on(_NAV);
    }
}
void td_rpt_reset(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            layer_off(_NAV);
    }
}

void td_del_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_DEL);
            break;
        case DOUBLE_TAP:
            tap_code(KC_ESC);
            reset_tap_dance(state);
            break;
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            trackball_mode_on(SLOW);
    }
}
void td_del_reset(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            trackball_mode_on(NORMAL);
    }
}

void td_tab_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr[] = {KC_LSFT};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_TAB);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes(arr, 1, KC_TAB);
            reset_tap_dance(state);
            break;
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            trackball_mode_on(SCROLL);
    }
}
void td_tab_reset(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            trackball_mode_on(NORMAL);
    }
}

void td_1ss_finished(tap_dance_state_t *state, void *user_data) {
    int8_t arr[] = {KC_LSFT};
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            set_oneshot_mods(MOD_LSFT);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes(arr, 1, KC_QUOT);
            reset_tap_dance(state);
            break;
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            trackball_mode_on(NAV);
    }
}
void td_1ss_reset(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            trackball_mode_on(NORMAL);
    }
}

void td_ent_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_ENT);
            break;
        case DOUBLE_TAP:
            tap_code(KC_QUOT);
            reset_tap_dance(state);
            break;
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            layer_on(_NUM);
    }
}
void td_ent_reset(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            layer_off(_NUM);
    }
}

void td_ldr_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            leader_start();
            break;
        case DOUBLE_TAP:
            layer_invert(_GRK);
            reset_tap_dance(state);
            break;
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            layer_on(_FUN);
    }
}
void td_ldr_reset(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case TRIPLE_HOLD:
            layer_off(_FUN);
    }
}
void td_numl_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code16(KC_QUES);
            break;
        case DOUBLE_TAP:
            layer_lock_invert(get_highest_layer(layer_state));
            reset_tap_dance(state);
            break;
    }
}
void td_syml_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code16(KC_QUES);
            break;
        case DOUBLE_TAP:
            layer_lock_invert(get_highest_layer(layer_state));
            reset_tap_dance(state);
            break;
    }
}
void td_navl_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code16(KC_PSCR);
            break;
        case DOUBLE_TAP:
            layer_lock_invert(get_highest_layer(layer_state));
            reset_tap_dance(state);
            break;
    }
}
void td_funl_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case DOUBLE_TAP:
            layer_lock_invert(get_highest_layer(layer_state));
            reset_tap_dance(state);
            break;
    }
}
void td_mac1_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            register_code16(QK_DYNAMIC_MACRO_PLAY_1);
            unregister_code16(QK_DYNAMIC_MACRO_PLAY_1);
        case DOUBLE_TAP:
            register_code16(QK_DYNAMIC_MACRO_RECORD_START_1);
            unregister_code16(QK_DYNAMIC_MACRO_RECORD_START_1);
            reset_tap_dance(state);
            break;
    }
}
void td_mac2_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            register_code16(QK_DYNAMIC_MACRO_PLAY_2);
            unregister_code16(QK_DYNAMIC_MACRO_PLAY_2);
        case DOUBLE_TAP:
            register_code16(QK_DYNAMIC_MACRO_RECORD_START_2);
            unregister_code16(QK_DYNAMIC_MACRO_RECORD_START_2);
            reset_tap_dance(state);
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_QU] = ACTION_TAP_DANCE_FN(td_qu_finished),
    [TD_W] = ACTION_TAP_DANCE_FN(td_w_finished),
    [TD_F] = ACTION_TAP_DANCE_FN(td_f_finished),
    [TD_P] = ACTION_TAP_DANCE_FN(td_p_finished),
    [TD_B] = ACTION_TAP_DANCE_FN(td_b_finished),
    [TD_A] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_a_finished, td_a_reset),
    [TD_R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_r_finished, td_r_reset),
    [TD_S] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_s_finished, td_s_reset),
    [TD_T] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_t_finished, td_t_reset),
    [TD_G] = ACTION_TAP_DANCE_FN(td_g_finished),
    [TD_Z] = ACTION_TAP_DANCE_FN(td_z_finished),
    [TD_X] = ACTION_TAP_DANCE_FN(td_x_finished),
    [TD_C] = ACTION_TAP_DANCE_FN(td_c_finished),
    [TD_D] = ACTION_TAP_DANCE_FN(td_d_finished),
    [TD_V] = ACTION_TAP_DANCE_FN(td_v_finished),
    [TD_J] = ACTION_TAP_DANCE_FN(td_j_finished),
    [TD_L] = ACTION_TAP_DANCE_FN(td_l_finished),
    [TD_U] = ACTION_TAP_DANCE_FN(td_u_finished),
    [TD_Y] = ACTION_TAP_DANCE_FN(td_y_finished),
    [TD_WH] = ACTION_TAP_DANCE_FN(td_wh_finished),
    [TD_M] = ACTION_TAP_DANCE_FN(td_m_finished),
    [TD_N] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_n_finished, td_n_reset),
    [TD_E] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_e_finished, td_e_reset),
    [TD_I] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_i_finished, td_i_reset),
    [TD_O] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_o_finished, td_o_reset),
    [TD_K] = ACTION_TAP_DANCE_FN(td_k_finished),
    [TD_H] = ACTION_TAP_DANCE_FN(td_h_finished),
    [TD_TH] = ACTION_TAP_DANCE_FN(td_th_finished),
    [TD_CH] = ACTION_TAP_DANCE_FN(td_ch_finished),
    [TD_SH] = ACTION_TAP_DANCE_FN(td_sh_finished),
    [TD_BSPC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_bspc_finished, td_bspc_reset),
    [TD_SPC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_spc_finished, td_spc_reset),
    [TD_RPT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_rpt_finished, td_rpt_reset),
    [TD_DEL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_del_finished, td_del_reset),
    [TD_TAB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_tab_finished, td_tab_reset),
    [TD_1SS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_1ss_finished, td_1ss_reset),
    [TD_ENT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_ent_finished, td_ent_reset),
    [TD_LDR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_ldr_finished, td_ldr_reset),
    [TD_NUML] = ACTION_TAP_DANCE_FN(td_numl_finished),
    [TD_SYML] = ACTION_TAP_DANCE_FN(td_syml_finished),
    [TD_NAVL] = ACTION_TAP_DANCE_FN(td_navl_finished),
    [TD_FUNL] = ACTION_TAP_DANCE_FN(td_funl_finished),
    [TD_MAC1] = ACTION_TAP_DANCE_FN(td_mac1_finished),
    [TD_MAC2] = ACTION_TAP_DANCE_FN(td_mac2_finished),
};
