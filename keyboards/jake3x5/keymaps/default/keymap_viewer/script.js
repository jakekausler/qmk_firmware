
const KEY_SIZE = 100;
const PAGE_MARGIN = 100;
const KEY_MARGIN = 10;
const ENCODER_RADIUS = 50;
const ENCODER_TURN_CENTER_MARGIN = 50; //Distance from edge of encoder to center of turn (0,0 for encoder turn labels)
const TRACKBALL_RADIUS = 150;
const OLED_WIDTH = 75;
const OLED_HEIGHT = 300;

// Coordinates relative to top inner key of side
const TRACKBALL_X = 0;
const TRACKBALL_Y = 0;
const ENCODER_X = 0;
const ENCODER_Y = 0;
const OLED_X = 0;
const OLED_Y = 0;
const LEFT_THUMB_KEY_X = [0,0,0,0,0];
const LEFT_THUMB_KEY_Y = [0,0,0,0,0];
const LEFT_THUMB_KEY_ROT = [0,0,0,0,0];
const RIGHT_THUMB_KEY_X = [0,0,0];
const RIGHT_THUMB_KEY_Y = [0,0,0];
const RIGHT_THUMB_KEY_ROT = [0,0,0];

const KEY_CORNER_RADIUS = 8;

const MAIN_KEY_COLORS = ["#","#","#","#","#");
const KEY_ALPHA = "AA";
const HOME_ALPHA = "FF";
const THUMB_COLOR = "#";
const TRACKBALL_COLOR = "#";
const OLED_COLOR = "#";

const MAIN_FONT_SIZE = 32;
const DT_FONT_SIZE = 32;
const TT_FONT_SIZE = 32;
const HOLD_FONT_SIZE = 32;
const GRK_FONT_SIZE = 32;
const GRKACC_FONT_SIZE = 32;
const NUM_FONT_SIZE = 32;
const SYM_FONT_SIZE = 32;
const FUN_FONT_SIZE = 32;
const NAV_FONT_SIZE = 32;
const ENCODER_FONT_SIZE = 32;
const ENCODER_TURN_FONT_SIZE = 32;

const RES_FOLDER = "res/";

//X,Y measured from center od key/encoder/encoder turn to alignment X,center Y of text
const NAV_X = -0;
const NAV_Y = -0;
const NAV_ALIGN = 'left';
const FUN_X = 0;
const FUN_Y = NAV_Y;
const FUN_ALIGN = 'right';
const NUM_X = NAV_X;
const NUM_Y = 0;
const NUM_ALIGN = NAV_ALIGN;
const SYM_X = FUN_X;
const SYM_Y = NAV_Y;
const SYM_ALIGN = FUN_ALIGN;
const MAIN_X = 0;
const MAIN_Y = 0;
const MAIN_ALIGN = "center";
const DT_X = MAIN_X;
const DT_Y = 0;
const DT_ALIGN = MAIN_ALIGN;
const TT_X = MAIN_X;
const TT_Y = DT_Y+0;
const TT_ALIGN = MAIN_ALIGN;
const GRK_X = MAIN_X;
const GRK_Y = -0;
const GRK_ALIGN = MAIN_ALIGN;
const GRKACC_X = MAIN_X;
const GRKACC_Y = GRK_Y-0;;
const GRKACC_ALIGN = MAIN_ALIGN;
const ENC_CW_NAV_X = 0;
const ENC_CW_NAV_Y = 0;
const ENC_CW_FUN_X = 0;
const ENC_CW_FUN_Y = 0;
const ENC_CW_NUM_X = 0;
const ENC_CW_NUM_Y = 0;
const ENC_CW_SYM_X = 0;
const ENC_CW_SYM_Y = 0;
const ENC_CW_MAIN_X = 0;
const ENC_CW_MAIN_Y = 0;
const ENC_CCW_NAV_X = 0;
const ENC_CCW_NAV_Y = 0;
const ENC_CCW_FUN_X = 0;
const ENC_CCW_FUN_Y = 0;
const ENC_CCW_NUM_X = 0;
const ENC_CCW_NUM_Y = 0;
const ENC_CCW_SYM_X = 0;
const ENC_CCW_SYM_Y = 0;
const ENC_CCW_MAIN_X = 0;
const ENC_CCW_MAIN_Y = 0;
const ENC_NAV_X = 0;
const ENC_NAV_Y = 0;
const ENC_FUN_X = 0;
const ENC_FUN_Y = 0;
const ENC_NUM_X = 0;
const ENC_NUM_Y = 0;
const ENC_SYM_X = 0;
const ENC_SYM_Y = 0;
const ENC_MAIN_X = 0;
const ENC_MAIN_Y = 0;
const ENC_DT_NAV_X = 0;
const ENC_DT_NAV_Y = 0;
const ENC_DT_FUN_X = 0;
const ENC_DT_FUN_Y = 0;
const ENC_DT_NUM_X = 0;
const ENC_NUM_Y = 0;
const ENC_SYM_X = 0;
const ENC_SYM_Y = 0;
const ENC_MAIN_X = 0;
const ENC_MAIN_Y = 0;

const icon_map = {
    CTRL: {
        filename: "",
        width: 0,
        height: 0
    }
}

//TODO: Add is_home field to keys

$(function() {
    $.getJSON("key_data.json", function(data) {
        const canvas = document.getElementById("keymap");
        const ctx = canvas.getContext("2d");
        draw_keymap(data, ctx);
    }).fail(function(jqXHR, status, error) {
        console.log("Error loading json: ", status, error);
    });
});

function draw_keymap(data, ctx) {
    draw_left(data.keys.left, data.layout.column_y_offsets, ctx);
    draw_right(data.keys.right, data.layout.column_y_offsets.reverse(), ctx);
}

function draw_left(data, column_offsets, ctx) {
    draw_main(data.main.rows, column_offsets, false, ctx);
    draw_encoder(data.encoder, false, ctx);
    draw_left_thumbs(data.thumbs.keys, ctx);
}

function draw_right(data, column_offsets, ctx) {
    draw_main(data.main.rows, column_offsets, true, ctx);
    draw_encoder(data.encoder, true, ctx);
    draw_right_thumbs(data.thumbs, ctx);
}

function draw_main(rows, column_offsets, is_right, ctx) {
    for (var row=0; row < rows.length; row++) {
        draw_row(row, rows[row].keys, column_offsets, is_right, ctx);
    }
}

function draw_row(rowN, keys, column_offsets, is_right, ctx) {
    for (let key = 0; key < keys.length; key++) {
        draw_key(rowN, key, keys[key], column_offsets[key], is_right, ctx);
    }
}

function draw_key(rowN, colN, key, column_offset, is_right, ctx) {
    if (!is_right) {
        let col = MAIN_KEY_COLORS[colN];
        if (key.is_home) {
            col += HOME_ALPHA;
        } else {
            col += KEY_ALPHA;
        }
        ctx.fillStyle(col);
        ctx.roundedRect(PAGE_MARGIN+KEY_MARGIN+KEY_MARGIN*rowN*2+KEY_SIZE*rowN, PAGE_MARGIN+KEY_MARGIN+KEY_MARGIN*colN*2+KEY_SIZE*colN, KEY_SIZE, KEY_SIZE, KEY_CORNER_RADIUS);
        ctx.fill();
    }
}

function draw_encoder(encoder, is_right, ctx) {

}

function draw_left_thumbs(keys, ctx) {

}

function draw_right_thumbs(keys, ctx) {

}
