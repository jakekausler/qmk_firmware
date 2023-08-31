
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

uint8_t SMOOTH_KEY = GK_Z;
uint8_t ROUGH_KEY = GK_X;
uint8_t GRAVE_KEY = GK_QUES;
uint8_t ACUTE_KEY = GK_SS;
uint8_t CIRCUMFLEX_KEY = GK_PH;
uint8_t LONG_KEY = GK_PS;
uint8_t BREVE_KEY = GK_D;
uint8_t DIACRITIC_KEY = GK_P;
uint8_t ALPHA_LOWER_KEY = GK_A_L;
uint8_t ALPHA_UPPER_KEY = GK_A_U;
uint8_t EPSILON_LOWER_KEY = GK_E_L;
uint8_t EPSILON_UPPER_KEY = GK_E_U;
uint8_t ETA_LOWER_KEY = GK_H_L;
uint8_t ETA_UPPER_KEY = GK_H_U;
uint8_t IOTA_LOWER_KEY = GK_I_L;
uint8_t IOTA_UPPER_KEY = GK_I_U;
uint8_t OMICRON_LOWER_KEY = GK_O_L;
uint8_t OMICRON_UPPER_KEY = GK_O_U;
uint8_t UPSILON_LOWER_KEY = GK_U_L;
uint8_t UPSILON_UPPER_KEY = GK_U_U;
uint8_t OMEGA_LOWER_KEY = GK_W_L;
uint8_t OMEGA_UPPER_KEY = GK_W_U;

uint16_t check_greek_sequence() {
    enum letter lt = LETTER_NONE;
    enum cas ca = CAS_NONE;
    enum breath br = BREATH_NONE;
    enum accent ac = ACCENT_NONE;
    enum length ln = LENGTH_NONE;
    enum mark mk = MARK_NONE;
    bool has_iota = false;
    uint16_t * seq = get_leader_sequence();
    for (int i=0; i<seq.length; i++) {
        if (seq[i] != 0) {
            switch (seq[i]) {
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
            case ACCENT_NONE:
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
            case ACCENT_NONE:
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
            case ACCENT_NONE:
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
            case ACCENT_NONE:
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
            case ACCENT_NONE:
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
            case ACCENT_NONE:
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
            case ACCENT_NONE:
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
            case ACCENT_NONE:
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
            case ACCENT_NONE:
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
            case ACCENT_NONE:
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
            case ACCENT_NONE:
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
            case ACCENT_NONE:
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
            case ACCENT_NONE:
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
            case ACCENT_NONE:
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
            case ACCENT_NONE:
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
            case ACCENT_NONE:
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
            case ACCENT_NONE:
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
            case ACCENT_NONE:
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
            case ACCENT_NONE:
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
            case ACCENT_NONE:
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
            case ACCENT_NONE:
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
    }
    return -1;
}

void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_Q, KC_U)) {
        SEND_STRING('jakekausler@gmail.com');
        return;
    } else if (leader_sequence_one_key(KC_W)) {
        SEND_STRING('jakekausler');
        return;
    } else if (leader_sequence_one_key(KC_F)) {
        SEND_STRING('Jake021f2f1!');
        return;
    }
    uint16_t kc = check_greek_sequence();
    if (kc != -1) {
        tap_code(kc);
    }
}
