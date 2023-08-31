enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  TRIPLE_TAP = 5,
  TRIPLE_HOLD = 6
};

enum {
    TD_QU = SAFE_RANGE,
    TD_W = SAFE_RANGE,
    TD_F = SAFE_RANGE,
    TD_P = SAFE_RANGE,
    TD_B = SAFE_RANGE,
    TD_A = SAFE_RANGE,
    TD_R = SAFE_RANGE,
    TD_S = SAFE_RANGE,
    TD_T = SAFE_RANGE,
    TD_G = SAFE_RANGE,
    TD_Z = SAFE_RANGE,
    TD_X = SAFE_RANGE,
    TD_C = SAFE_RANGE,
    TD_D = SAFE_RANGE,
    TD_V = SAFE_RANGE,
    TD_J = SAFE_RANGE,
    TD_L = SAFE_RANGE,
    TD_U = SAFE_RANGE,
    TD_Y = SAFE_RANGE,
    TD_WH = SAFE_RANGE,
    TD_M = SAFE_RANGE,
    TD_N = SAFE_RANGE,
    TD_E = SAFE_RANGE,
    TD_I = SAFE_RANGE,
    TD_O = SAFE_RANGE,
    TD_K = SAFE_RANGE,
    TD_H = SAFE_RANGE,
    TD_TH = SAFE_RANGE,
    TD_CH = SAFE_RANGE,
    TD_SH = SAFE_RANGE,
    TD_BSPC = SAFE_RANGE,
    TD_SPC = SAFE_RANGE,
    TD_RPT = SAFE_RANGE,
    TD_DEL = SAFE_RANGE,
    TD_TAB = SAFE_RANGE,
    TD_1SS = SAFE_RANGE,
    TD_ENT = SAFE_RANGE,
    TD_LDR = SAFE_RANGE
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_QU] = ACTION_TAP_DANCE_FN(td_qu_finished),
    [TD_W] = ACTION_TAP_DANCE_FN(td_w_finished),
    [TD_F] = ACTION_TAP_DANCE_FN(td_f_finished),
    [TD_P] = ACTION_TAP_DANCE_FN(td_p_finished),
    [TD_B] = ACTION_TAP_DANCE_FN(td_b_finished),
    [TD_A] = ACTION_TAP_DANCE_FN(td_a_finished),
    [TD_R] = ACTION_TAP_DANCE_FN(td_r_finished),
    [TD_S] = ACTION_TAP_DANCE_FN(td_s_finished),
    [TD_T] = ACTION_TAP_DANCE_FN(td_t_finished),
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
    [TD_N] = ACTION_TAP_DANCE_FN(td_n_finished),
    [TD_E] = ACTION_TAP_DANCE_FN(td_e_finished),
    [TD_I] = ACTION_TAP_DANCE_FN(td_i_finished),
    [TD_O] = ACTION_TAP_DANCE_FN(td_o_finished),
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
};

enum trackmode {
    NORMAL,
    SLOW,
    SCROLL,
    NAV
}

bool trackball_navigating = false;
bool trackball_scrolling = false;

void trackball_mode_on(trackmode mode) {
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

int TRACKBALL_NAV_THRESHOLD = 8;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (trackball_navigating) {
        if (mouse_report.x > TRACKBALL_NAV_THRESHOLD) {
            tap_code(KC_RIGHT);
        } else if (mouse_report.y < -TRACKBALL_NAV_THRESHOLD) {
            tap_code(KC_LEFT);
        }
        if (trackball_navigating) {
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

void hyper_on() {
    register_code(KC_LCTL);
    register_code(KC_LALT);
    register_code(KC_LSFT);
    register_code(KC_LGUI);
}

void hyper_off() {
    unregister_code(KC_LCTL);
    unregister_code(KC_LALT);
    unregister_code(KC_LSFT);
    unregister_code(KC_LGUI);
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


void modifier_tap_codes(int8_t modifiers[], int8_t kc) {
    for (int m=0; m < modifiers.length; m++) {
        register_code(modifiers[m]);
    }
    tap_code(kc);
    for (int m=modifiers.length-1; m >= 0; m--) {
        unregister_code(modifiers[m]);
    }
}

void tap_multiple(int8_t kc[]) {
    if (kc.length <= 0) {
        return;
    }
    tap_code(kc[0]);
    if (kc.length == 1) {
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
    for (int i=1; i < kc.length; i++) {
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
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_multiple([KC_Q, KC_U]);
            break;
        case DOUBLE_TAP:
            tap_code(KC_Q);
            reset_tap_dance(state);
            break;
    }
}
void td_w_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_W);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes([KC_LCTL], KC_W);
            reset_tap_dance(state);
            break;
    }
}
void td_f_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_F);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes([KC_LCTL], KC_T);
            reset_tap_dance(state);
            break;
    }
}
void td_p_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_P);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes([KC_LCTL], KC_PGUP);
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
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_A);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes([KC_LCTL, KC_LSFT], KC_LEFT);
            reset_tap_dance(state);
            break;
    }
}
void td_r_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_R);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes([KC_LCTL, KC_LSFT], KC_DOWN);
            reset_tap_dance(state);
            break;
    }
}
void td_s_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_S);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes([KC_LCTL, KC_LSFT], KC_UP);
            reset_tap_dance(state);
            break;
    }
}
void td_t_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_T);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes([KC_LCTL, KC_LSFT], KC_RIGHT);
            reset_tap_dance(state);
            break;
    }
}
void td_g_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_G);
            break;
        case DOUBLE_TAP:
            tap_code(KC_G); tap_code(KC_H);
            reset_tap_dance(state);
            break;
    }
}
void td_z_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_Z);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes([KC_LCTL], KC_Z);
            break;
        case TRIPLE_TAP:
            modifier_tap_codes([KC_LCTL,KC_LSFT], KC_Z);
            reset_tap_dance(state);
            break;
    }
}
void td_x_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_X);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes([KC_LCTL], KC_X);
            reset_tap_dance(state);
            break;
    }
}
void td_c_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_C);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes([KC_LCTL], KC_C);
            reset_tap_dance(state);
            break;
    }
}
void td_d_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_D);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes([KC_LCTL], KC_D);
            reset_tap_dance(state);
            break;
    }
}
void td_v_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_V);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes([KC_LCTL], KC_V);
            reset_tap_dance(state);
            break;
    }
}
void td_j_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_J);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes([KC_LALT,KC_LSFT], KC_TAB);
            reset_tap_dance(state);
            break;
    }
}
void td_l_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_L);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes([KC_LALT], KC_TAB);
            reset_tap_dance(state);
            break;
    }
}
void td_u_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_U);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes([KC_LCTL], KC_F);
            break;
        case TRIPLE_TAP:
            modifier_tap_codes([KC_LCTL,KC_LSFT], KC_F);
            reset_tap_dance(state);
            break;
    }
}
void td_y_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_Y);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes([KC_LCTL], KC_H);
            break;
        case TRIPLE_TAP:
            modifier_tap_codes([KC_LCTL,KC_LSFT], KC_H);
            reset_tap_dance(state);
            break;
    }
}
void td_wh_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_multiple([KC_W, KC_H]);
            break;
        case DOUBLE_TAP:
            tap_multiple([KC_O, KC_U]);
            reset_tap_dance(state);
            break;
    }
}
void td_m_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_M);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes([KC_LCTL], KC_P);
            break;
        case TRIPLE_TAP:
            modifier_tap_codes([KC_LCTL,KC_LSFT], KC_P);
            reset_tap_dance(state);
            break;
    }
}
void td_n_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_N);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes([KC_LCTL], KC_LEFT);
            reset_tap_dance(state);
            break;
    }
}
void td_e_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_E);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes([KC_LCTL], KC_UP);
            reset_tap_dance(state);
            break;
    }
}
void td_i_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_I);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes([KC_LCTL], KC_DOWN);
            reset_tap_dance(state);
            break;
    }
}
void td_o_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_O);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes([KC_LCTL], KC_RIGHT);
            reset_tap_dance(state);
            break;
    }
}
void td_k_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_K);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes([KC_LCTL,KC_LSFT], KC_K);
            reset_tap_dance(state);
            break;
    }
}
void td_h_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_H);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes([KC_LCTL], KC_L);
            reset_tap_dance(state);
            break;
    }
}
void td_th_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_multiple([KC_T, KC_H]);
            break;
        case DOUBLE_TAP:
            tap_multiple([KC_T, KC_H, KC_E]);
            reset_tap_dance(state);
            break;
    }
}
void td_ch_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_multiple([KC_C, KC_H]);
            break;
        case DOUBLE_TAP:
            tap_multiple([KC_A, KC_N, KC_D]);
            reset_tap_dance(state);
            break;
    }
}
void td_sh_finished(tap_dance_state_t *state, void *user_data) {
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_multiple([KC_S, KC_H]);
            break;
        case DOUBLE_TAP:
            tap_multiple([KC_I, KC_N, KC_G]);
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
            tap_code(QK_REP);
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
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            tap_code(KC_TAB);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes([KC_LSFT], KC_TAB);
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
    switch (cur_dance(state)) {
        case SINGLE_TAP:
            set_oneshot_mods(MOD_LSFT);
            break;
        case DOUBLE_TAP:
            modifier_tap_codes([KC_LSFT], KC_QUOT);
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

