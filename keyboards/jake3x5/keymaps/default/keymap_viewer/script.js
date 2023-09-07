
const KEY_SIZE = 100;
const PAGE_MARGIN = 50;
const KEY_MARGIN = 10;
const ENCODER_RADIUS = 50;
const ENCODER_TURN_CENTER_MARGIN = 100; //Distance from edge of encoder to center of turn (0,0 for encoder turn labels)
const TRACKBALL_RADIUS = 100;
const OLED_WIDTH = 64;
const OLED_HEIGHT = 256;

let RIGHT_OFFSET = 0;

const LEFT_ENCODER_X = KEY_MARGIN*2*5+KEY_MARGIN+KEY_SIZE*5+ENCODER_RADIUS+ENCODER_TURN_CENTER_MARGIN;
const LEFT_OLED_X = LEFT_ENCODER_X - OLED_WIDTH/2;
const LEFT_OLED_Y = PAGE_MARGIN+KEY_MARGIN;
const LEFT_ENCODER_Y = LEFT_OLED_Y+OLED_HEIGHT+KEY_MARGIN*2+ENCODER_RADIUS;
const LEFT_THUMB_KEY_X = [
    KEY_MARGIN*2*3+KEY_SIZE*3,
    KEY_MARGIN*2*3+KEY_SIZE*4.25,
    KEY_MARGIN*2*3+KEY_SIZE*5.6,
    KEY_MARGIN*2*3+KEY_SIZE*3.92,
    KEY_MARGIN*2*3+KEY_SIZE*5.12
];
const LEFT_THUMB_KEY_Y = [
    PAGE_MARGIN+KEY_MARGIN*2*4+KEY_SIZE*3,
    PAGE_MARGIN+KEY_MARGIN*2*4+KEY_SIZE*3.25,
    PAGE_MARGIN+KEY_MARGIN*2*4+KEY_SIZE*3.65,
    PAGE_MARGIN+KEY_MARGIN*2*4+KEY_SIZE*4.4,
    PAGE_MARGIN+KEY_MARGIN*2*4+KEY_SIZE*4.74
];
const LEFT_THUMB_KEY_ROT = [10,15,25,15,25];

let TRACKBALL_X = 0;
let TRACKBALL_Y = 0;
let RIGHT_ENCODER_X = 0;
let RIGHT_OLED_X = 0;
let RIGHT_OLED_Y = 0;
let RIGHT_ENCODER_Y = 0;
let RIGHT_THUMB_KEY_X = [0,0,0];
let RIGHT_THUMB_KEY_Y = [0,0,0];
let RIGHT_THUMB_KEY_ROT = [0,0,0];

const KEY_CORNER_RADIUS = 16;

const MAIN_KEY_COLORS = ["#AF81C9","#F89A7E","#F2CA85","#54D1F1","#54D1F1"];
const KEY_ALPHA = "66";
const HOME_ALPHA = "BB";
const THUMB_COLOR = "#445569";
const TRACKBALL_COLOR = "#445569";
const TRACKBALL_ALPHA = "22";
const OLED_COLOR = "#445569";
const OLED_ALPHA = "22";
const ENCODER_COLOR = "#445569";
const ENCODER_ALPHA = "88";
const TEXT_COLOR = "#000000";

const FONT = "Inter";

const MAIN_FONT_SIZE = 32;
const DT_FONT_SIZE = 16;
const TT_FONT_SIZE = 12;
const HOLD_FONT_SIZE = 16;
const GRK_FONT_SIZE = 16;
const GRKACC_FONT_SIZE = 24;
const NUM_FONT_SIZE = 18;
const SYM_FONT_SIZE = NUM_FONT_SIZE;
const FUN_FONT_SIZE = NUM_FONT_SIZE;
const NAV_FONT_SIZE = NUM_FONT_SIZE;
const MOU_FONT_SIZE = 24;
const LOCK_FONT_SIZE = NUM_FONT_SIZE;
const ENCODER_FONT_SIZE = 12;

const RES_FOLDER = "res/";

const KEY_PADDING = 8;
//X,Y measured from center od key/encoder/encoder turn to alignment X,center Y of text
const NAV_X = -(KEY_SIZE/2-KEY_PADDING);
const NAV_Y = -(KEY_SIZE/2-KEY_PADDING-NAV_FONT_SIZE/2);
const NAV_ALIGN = 'left';
const FUN_X = KEY_SIZE/2-KEY_PADDING;
const FUN_Y = NAV_Y;
const FUN_ALIGN = 'right';
const NUM_X = NAV_X;
const NUM_Y = KEY_SIZE/2-KEY_PADDING-NUM_FONT_SIZE/2;
const NUM_ALIGN = NAV_ALIGN;
const SYM_X = FUN_X;
const SYM_Y = NUM_Y;
const SYM_ALIGN = FUN_ALIGN;
const MAIN_X = 0;
const MAIN_Y = 0;
const MAIN_ALIGN = "center";
const DT_X = MAIN_X;
const DT_Y = MAIN_FONT_SIZE/2+DT_FONT_SIZE/2;
const DT_ALIGN = MAIN_ALIGN;
const TT_X = MAIN_X;
const TT_Y = DT_Y+DT_FONT_SIZE;
const TT_ALIGN = MAIN_ALIGN;
const HOLD_X = MAIN_X;
const HOLD_Y = KEY_SIZE/2+KEY_PADDING;
const HOLD_ALIGN = MAIN_ALIGN;
const GRK_X = MAIN_X;
const GRK_Y = -(MAIN_FONT_SIZE/2+DT_FONT_SIZE/2);
const GRK_ALIGN = MAIN_ALIGN;
const GRKACC_X = MAIN_X;
const GRKACC_Y = GRK_Y-(GRK_FONT_SIZE/3);
const GRKACC_ALIGN = MAIN_ALIGN;
const MOU_X = MAIN_X - KEY_SIZE/4;
const MOU_Y = MAIN_Y;
const MOU_ALIGN = MAIN_ALIGN;
const LOCK_X = MAIN_X + KEY_SIZE/4;
const LOCK_Y = MAIN_Y;
const LOCK_ALIGN = MAIN_ALIGN;
const ENC_CW_NAV_ALIGN = "center";
const ENC_CW_NAV_X = -(ENCODER_RADIUS/3*2-KEY_MARGIN);
const ENC_CW_NAV_Y = -(ENCODER_RADIUS/3*2-KEY_MARGIN);
const ENC_CW_FUN_ALIGN = "center";
const ENC_CW_FUN_X = ENCODER_RADIUS/3*2-KEY_MARGIN;
const ENC_CW_FUN_Y = ENC_CW_NAV_Y;
const ENC_CW_NUM_ALIGN = "center";
const ENC_CW_NUM_X = ENC_CW_NAV_X;
const ENC_CW_NUM_Y = ENCODER_RADIUS/3*2-KEY_MARGIN;
const ENC_CW_SYM_ALIGN = "center";
const ENC_CW_SYM_X = ENC_CW_FUN_X;
const ENC_CW_SYM_Y = ENC_CW_NUM_Y;
const ENC_CW_MAIN_ALIGN = "center";
const ENC_CW_MAIN_X = 0;
const ENC_CW_MAIN_Y = 0;
const ENC_CCW_NAV_ALIGN = "center";
const ENC_CCW_NAV_X = ENC_CW_NAV_X;
const ENC_CCW_NAV_Y = ENC_CW_NAV_Y;
const ENC_CCW_FUN_ALIGN = "center";
const ENC_CCW_FUN_X = ENC_CW_FUN_X;
const ENC_CCW_FUN_Y = ENC_CW_FUN_Y;
const ENC_CCW_NUM_ALIGN = "center";
const ENC_CCW_NUM_X = ENC_CW_NUM_X;
const ENC_CCW_NUM_Y = ENC_CW_NUM_Y;
const ENC_CCW_SYM_ALIGN = "center";
const ENC_CCW_SYM_X = ENC_CW_SYM_X;
const ENC_CCW_SYM_Y = ENC_CW_SYM_Y;
const ENC_CCW_MAIN_ALIGN = "center";
const ENC_CCW_MAIN_X = ENC_CW_MAIN_X;
const ENC_CCW_MAIN_Y = ENC_CW_MAIN_Y;
const ENC_NAV_ALIGN = "center";
const ENC_NAV_X = -(ENCODER_RADIUS-KEY_MARGIN);
const ENC_NAV_Y = -(ENCODER_RADIUS-KEY_MARGIN)-ENCODER_FONT_SIZE/3*2;
const ENC_FUN_ALIGN = "center";
const ENC_FUN_X = ENCODER_RADIUS-KEY_MARGIN;
const ENC_FUN_Y = ENC_NAV_Y;
const ENC_NUM_ALIGN = "center";
const ENC_NUM_X = ENC_NAV_X;
const ENC_NUM_Y = (ENCODER_RADIUS-KEY_MARGIN)-ENCODER_FONT_SIZE/3*2;
const ENC_SYM_ALIGN = "center";
const ENC_SYM_X = ENC_FUN_X;
const ENC_SYM_Y = ENC_NUM_Y-ENCODER_FONT_SIZE/3*2;
const ENC_MAIN_ALIGN = "center";
const ENC_MAIN_X = 0;
const ENC_MAIN_Y = -ENCODER_FONT_SIZE/3*2;
const ENC_DT_NAV_ALIGN = "center";
const ENC_DT_NAV_X = ENC_NAV_X;
const ENC_DT_NAV_Y = -(ENCODER_RADIUS-KEY_MARGIN)+ENCODER_FONT_SIZE/3*2;
const ENC_DT_FUN_ALIGN = "center";
const ENC_DT_FUN_X = ENC_FUN_X;
const ENC_DT_FUN_Y = ENC_DT_NAV_Y+ENCODER_FONT_SIZE/3*2;
const ENC_DT_NUM_ALIGN = "center";
const ENC_DT_NUM_X = ENC_NUM_X;
const ENC_DT_NUM_Y = (ENCODER_RADIUS-KEY_MARGIN)+ENCODER_FONT_SIZE/3*2;
const ENC_DT_SYM_ALIGN = "center";
const ENC_DT_SYM_X = ENC_SYM_X;
const ENC_DT_SYM_Y = ENC_NUM_Y+ENCODER_FONT_SIZE/3*2;
const ENC_DT_MAIN_ALIGN = "center";
const ENC_DT_MAIN_X = ENC_MAIN_X;
const ENC_DT_MAIN_Y = ENCODER_FONT_SIZE/3*2;

const icon_map = {
    CTRL: {
        filename: "",
        width: 0,
        height: 0
    }
}

$(function() {
    const canvas = document.getElementById("keymap");
    const ctx = canvas.getContext("2d");
    window.addEventListener('resize', resizeCanvas, false);
    function resizeCanvas() {
        canvas.width = window.innerWidth;
        canvas.height = window.innerHeight;
        RIGHT_OFFSET = canvas.width-(PAGE_MARGIN+KEY_MARGIN*2*5+KEY_SIZE*5);
        TRACKBALL_X = -KEY_SIZE*1;
        TRACKBALL_Y = PAGE_MARGIN+KEY_MARGIN*2*4+KEY_SIZE*4;
        RIGHT_ENCODER_X = -(ENCODER_TURN_CENTER_MARGIN+ENCODER_RADIUS);
        RIGHT_OLED_X = RIGHT_ENCODER_X - OLED_WIDTH/2;
        RIGHT_OLED_Y = PAGE_MARGIN+KEY_MARGIN;
        RIGHT_ENCODER_Y = RIGHT_OLED_Y+OLED_HEIGHT+KEY_MARGIN*2+ENCODER_RADIUS;
        RIGHT_THUMB_KEY_X = [
            KEY_MARGIN*2-KEY_SIZE*0.65,
            KEY_MARGIN*2+KEY_SIZE*0.5,
            KEY_MARGIN*2+KEY_SIZE*1.7
        ];
        RIGHT_THUMB_KEY_Y = [
            PAGE_MARGIN+KEY_MARGIN*2*4+KEY_SIZE*4.9,
            PAGE_MARGIN+KEY_MARGIN*2*4+KEY_SIZE*4.0,
            PAGE_MARGIN+KEY_MARGIN*2*4+KEY_SIZE*3.3
        ];
        RIGHT_THUMB_KEY_ROT = [-40,-30,-20];
        ctx.clearRect(0, 0, canvas.width, canvas.height);
        $.getJSON("key_data.json", function(data) {
            draw_keymap(data, ctx);
        }).fail(function(jqXHR, status, error) {
            console.log("Error loading json: ", status, error);
        });
    }
    resizeCanvas();
});

function draw_keymap(data, ctx) {
    resetTransformation(ctx, false);
    draw_left(data.keys.left, data.layout.column_y_offsets, ctx);
    resetTransformation(ctx, true);
    draw_right(data.keys.right, data.layout.column_y_offsets.reverse(), ctx);
}

function draw_left(data, column_offsets, ctx) {
    draw_main(data.main.rows, column_offsets, false, ctx);
    draw_encoder(data.encoder, false, ctx);
    draw_oled(false, ctx);
    draw_left_thumbs(data.thumbs.keys, ctx);
}

function draw_right(data, column_offsets, ctx) {
    draw_main(data.main.rows, column_offsets, true, ctx);
    draw_encoder(data.encoder, true, ctx);
    draw_oled(true, ctx);
    draw_right_thumbs(data.thumbs.keys, ctx);
    draw_trackball(ctx, true);
}

function draw_trackball(ctx, is_right) {
    resetTransformation(ctx, is_right);
    ctx.fillStyle = TRACKBALL_COLOR + TRACKBALL_ALPHA;
    ctx.arc(TRACKBALL_X, TRACKBALL_Y, TRACKBALL_RADIUS, 0, (360*Math.PI) / 180);
    ctx.fill();
    resetTransformation(ctx, is_right);
}

function draw_main(rows, column_offsets, is_right, ctx) {
    for (var row=0; row < rows.length; row++) {
        draw_row(row, rows[row].keys, column_offsets, is_right, ctx);
    }
}

function draw_row(rowN, keys, column_offsets, is_right, ctx) {
    for (let key = 0; key < keys.length; key++) {
        draw_key_main(rowN, key, keys[key], column_offsets[key], is_right, ctx);
    }
}

function draw_key_main(rowN, colN, key, column_offset, is_right, ctx) {
    let col = MAIN_KEY_COLORS[colN];
    if (key.isHome) {
        col += HOME_ALPHA;
    } else {
        col += KEY_ALPHA;
    }
    ctx.translate(KEY_MARGIN+KEY_MARGIN*colN*2+KEY_SIZE*colN+KEY_SIZE/2, PAGE_MARGIN+KEY_MARGIN+KEY_MARGIN*rowN*2+KEY_SIZE*rowN+KEY_SIZE/2);
    ctx.beginPath();
    ctx.fillStyle = col;
    ctx.roundRect(-KEY_SIZE/2, -KEY_SIZE/2, KEY_SIZE, KEY_SIZE, KEY_CORNER_RADIUS);
    ctx.fill();
    ctx.fillStyle = TEXT_COLOR;
    ctx.textBaseline = "middle";
    if (key.main) {
        ctx.textAlign = MAIN_ALIGN;
        ctx.font = MAIN_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(key.main, MAIN_FONT_SIZE, ctx), MAIN_X, MAIN_Y);
    }
    if (key.doubleTap) {
        ctx.textAlign = DT_ALIGN;
        ctx.font = DT_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(key.doubleTap, DT_FONT_SIZE, ctx), DT_X, DT_Y);
    }
    if (key.tripleTap) {
        ctx.textAlign = TT_ALIGN;
        ctx.font = TT_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(key.tripleTap, TT_FONT_SIZE, ctx), TT_X, TT_Y);
    }
    if (key.hold) {
        ctx.textAlign = HOLD_ALIGN;
        ctx.font = HOLD_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(key.hold, HOLD_FONT_SIZE, ctx), HOLD_X, HOLD_Y);
    }
    if (key.grk) {
        ctx.textAlign = GRK_ALIGN;
        ctx.font = GRK_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(key.grk, GRK_FONT_SIZE, ctx), GRK_X, GRK_Y);
    }
    if (key.grkAcc) {
        ctx.textAlign = GRKACC_ALIGN;
        ctx.font = GRKACC_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(key.grkAcc, GRKACC_FONT_SIZE, ctx), GRKACC_X, GRKACC_Y);
    }
    if (key.nav) {
        ctx.textAlign = NAV_ALIGN;
        ctx.font = NAV_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(key.nav, NAV_FONT_SIZE, ctx), NAV_X, NAV_Y);
    }
    if (key.fun) {
        ctx.textAlign = FUN_ALIGN;
        ctx.font = FUN_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(key.fun, FUN_FONT_SIZE, ctx), FUN_X, FUN_Y);
    }
    if (key.num) {
        ctx.textAlign = NUM_ALIGN;
        ctx.font = NUM_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(key.num, NUM_FONT_SIZE, ctx), NUM_X, NUM_Y);
    }
    if (key.sym) {
        ctx.textAlign = SYM_ALIGN;
        ctx.font = SYM_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(key.sym, SYM_FONT_SIZE, ctx), SYM_X, SYM_Y);
    }
    if (key.locksLayer) {
        ctx.textAlign = LOCK_ALIGN;
        ctx.font = LOCK_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText("[1F512]", LOCK_FONT_SIZE, ctx), LOCK_X, LOCK_Y);
    }
    resetTransformation(ctx, is_right);
}

function fixText(text, size, ctx) {
    return text.replace(/\[(.+)\]/, function(a, b) {
        try {
            let s = String.fromCodePoint(Number("0x"+b));
            ctx.font = size + "px Noto Emoji";
            return s;
        } catch {
            return a;
        }
    });
}

function draw_key_independent(x, y, rot, col, key, is_right, ctx) {
    resetTransformation(ctx, is_right);
    console.log(x, y, is_right);
    if (key.isHome) {
        col += HOME_ALPHA;
    } else {
        col += KEY_ALPHA;
    }
    ctx.beginPath();
    rotateCanvas(x, y, rot, ctx);
    ctx.fillStyle = col;
    ctx.roundRect(0, 0, KEY_SIZE, KEY_SIZE, KEY_CORNER_RADIUS);
    ctx.fill();
    // console.log(x, y, rot);
    // console.log(KEY_SIZE/2*Math.cos(rot), KEY_SIZE/2*Math.sin(rot));
    // ctx.translate(KEY_SIZE/2*Math.cos(rot), KEY_SIZE/2*Math.sin(rot));
    ctx.translate(KEY_SIZE/2, KEY_SIZE/2);
    ctx.fillStyle = TEXT_COLOR;
    ctx.textBaseline = "middle";
    if (key.main) {
        ctx.textAlign = MAIN_ALIGN;
        ctx.font = MAIN_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(key.main, MAIN_FONT_SIZE, ctx), MAIN_X, MAIN_Y);
    }
    if (key.doubleTap) {
        ctx.textAlign = DT_ALIGN;
        ctx.font = DT_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(key.doubleTap, DT_FONT_SIZE, ctx), DT_X, DT_Y);
    }
    if (key.tripleTap) {
        ctx.textAlign = TT_ALIGN;
        ctx.font = TT_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(key.tripleTap, TT_FONT_SIZE, ctx), TT_X, TT_Y);
    }
    if (key.hold) {
        ctx.textAlign = HOLD_ALIGN;
        ctx.font = HOLD_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(key.hold, HOLD_FONT_SIZE, ctx), HOLD_X, HOLD_Y);
    }
    if (key.mou) {
        ctx.textAlign = MOU_ALIGN;
        ctx.font = MOU_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(key.mou, MOU_FONT_SIZE, ctx), MOU_X, MOU_Y);
    }
    if (key.grk) {
        ctx.textAlign = GRK_ALIGN;
        ctx.font = GRK_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(key.grk, GRK_FONT_SIZE, ctx), GRK_X, GRK_Y);
    }
    if (key.grkAcc) {
        ctx.textAlign = GRKACC_ALIGN;
        ctx.font = GRKACC_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(key.grkAcc, GRKACC_FONT_SIZE, ctx), GRKACC_X, GRKACC_Y);
    }
    if (key.nav) {
        ctx.textAlign = NAV_ALIGN;
        ctx.font = NAV_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(key.nav, NAV_FONT_SIZE, ctx), NAV_X, NAV_Y);
    }
    if (key.fun) {
        ctx.textAlign = FUN_ALIGN;
        ctx.font = FUN_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(key.fun, FUN_FONT_SIZE, ctx), FUN_X, FUN_Y);
    }
    if (key.num) {
        ctx.textAlign = NUM_ALIGN;
        ctx.font = NUM_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(key.num, NUM_FONT_SIZE, ctx), NUM_X, NUM_Y);
    }
    if (key.sym) {
        ctx.textAlign = SYM_ALIGN;
        ctx.font = SYM_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(key.sym, SYM_FONT_SIZE, ctx), SYM_X, SYM_Y);
    }
    if (key.locksLayer) {
        ctx.textAlign = LOCK_ALIGN;
        ctx.font = LOCK_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText("[1F512]", LOCK_FONT_SIZE, ctx), LOCK_X, LOCK_Y);
    }
    resetTransformation(ctx, is_right);
}

function rotateCanvas(x, y, rot, ctx) {
    ctx.translate(x, y);
    ctx.rotate((rot*Math.PI)/180);
}

function resetTransformation(ctx, is_right) {
    ctx.setTransform(1, 0, 0, 1, 0, 0);
    if (is_right) {
        ctx.translate(RIGHT_OFFSET, 0);
    } else {
        ctx.translate(PAGE_MARGIN, 0);
    }
}

function draw_encoder(encoder, is_right, ctx) {
    if (!is_right) {
        ctx.translate(LEFT_ENCODER_X, LEFT_ENCODER_Y);
    } else {
        ctx.translate(RIGHT_ENCODER_X, RIGHT_ENCODER_Y);
    }
    ctx.beginPath();
    ctx.fillStyle = ENCODER_COLOR + ENCODER_ALPHA;
    ctx.arc(0, 0, ENCODER_RADIUS, 0, (360*Math.PI) / 180);
    ctx.fill();
    ctx.fillStyle = TEXT_COLOR;
    if (encoder.main.tap) {
        ctx.textAlign = ENC_MAIN_ALIGN;
        ctx.font = ENCODER_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(encoder.main.tap, ENCODER_FONT_SIZE, ctx), ENC_MAIN_X, ENC_MAIN_Y);
    }
    if (encoder.nav.tap) {
        ctx.textAlign = ENC_NAV_ALIGN;
        ctx.font = ENCODER_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(encoder.nav.tap, ENCODER_FONT_SIZE, ctx), ENC_NAV_X, ENC_NAV_Y);
    }
    if (encoder.fun.tap) {
        ctx.textAlign = ENC_FUN_ALIGN;
        ctx.font = ENCODER_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(encoder.fun.tap, ENCODER_FONT_SIZE, ctx), ENC_FUN_X, ENC_FUN_Y);
    }
    if (encoder.num.tap) {
        ctx.textAlign = ENC_NUM_ALIGN;
        ctx.font = ENCODER_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(encoder.num.tap, ENCODER_FONT_SIZE, ctx), ENC_NUM_X, ENC_NUM_Y);
    }
    if (encoder.sym.tap) {
        ctx.textAlign = ENC_SYM_ALIGN;
        ctx.font = ENCODER_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(encoder.sym.tap, ENCODER_FONT_SIZE, ctx), ENC_SYM_X, ENC_SYM_Y);
    }
    if (encoder.main.doubleTap) {
        ctx.textAlign = ENC_DT_MAIN_ALIGN;
        ctx.font = ENCODER_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(encoder.main.doubleTap, ENCODER_FONT_SIZE, ctx), ENC_DT_MAIN_X, ENC_DT_MAIN_Y);
    }
    if (encoder.nav.doubleTap) {
        ctx.textAlign = ENC_DT_NAV_ALIGN;
        ctx.font = ENCODER_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(encoder.nav.doubleTap, ENCODER_FONT_SIZE, ctx), ENC_DT_NAV_X, ENC_DT_NAV_Y);
    }
    if (encoder.fun.doubleTap) {
        ctx.textAlign = ENC_DT_FUN_ALIGN;
        ctx.font = ENCODER_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(encoder.fun.doubleTap, ENCODER_FONT_SIZE, ctx), ENC_DT_FUN_X, ENC_DT_FUN_Y);
    }
    if (encoder.num.doubleTap) {
        ctx.textAlign = ENC_DT_NUM_ALIGN;
        ctx.font = ENCODER_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(encoder.num.doubleTap, ENCODER_FONT_SIZE, ctx), ENC_DT_NUM_X, ENC_DT_NUM_Y);
    }
    if (encoder.sym.doubleTap) {
        ctx.textAlign = ENC_DT_SYM_ALIGN;
        ctx.font = ENCODER_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(encoder.sym.doubleTap, ENCODER_FONT_SIZE, ctx), ENC_DT_SYM_X, ENC_DT_SYM_Y);
    }
    ctx.translate(-ENCODER_TURN_CENTER_MARGIN,0);
    ctx.beginPath();
    ctx.fillStyle = ENCODER_COLOR + ENCODER_ALPHA;
    ctx.arc(0, 0, ENCODER_RADIUS/2, 0, (360*Math.PI) / 180);
    ctx.fill();
    ctx.fillStyle = TEXT_COLOR;
    // ctx.font = (ENCODER_FONT_SIZE*2)+"px " + FONT;
    // ctx.textAlign = ENC_CCW_MAIN_ALIGN;
    // ctx.fillText(fixText("[]", ENCODER_FONT_SIZE, ctx), 0, 0);
    if (encoder.main.counterClockwise) {
        ctx.textAlign = ENC_CCW_MAIN_ALIGN;
        ctx.font = ENCODER_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(encoder.main.counterClockwise, ENCODER_FONT_SIZE, ctx), ENC_CCW_MAIN_X, ENC_CCW_MAIN_Y);
    }
    if (encoder.nav.counterClockwise) {
        ctx.textAlign = ENC_CCW_NAV_ALIGN;
        ctx.font = ENCODER_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(encoder.nav.counterClockwise, ENCODER_FONT_SIZE, ctx), ENC_CCW_NAV_X, ENC_CCW_NAV_Y);
    }
    if (encoder.fun.counterClockwise) {
        ctx.textAlign = ENC_CCW_FUN_ALIGN;
        ctx.font = ENCODER_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(encoder.fun.counterClockwise, ENCODER_FONT_SIZE, ctx), ENC_CCW_FUN_X, ENC_CCW_FUN_Y);
    }
    if (encoder.num.counterClockwise) {
        ctx.textAlign = ENC_CCW_NUM_ALIGN;
        ctx.font = ENCODER_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(encoder.num.counterClockwise, ENCODER_FONT_SIZE, ctx), ENC_CCW_NUM_X, ENC_CCW_NUM_Y);
    }
    if (encoder.sym.counterClockwise) {
        ctx.textAlign = ENC_CCW_SYM_ALIGN;
        ctx.font = ENCODER_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(encoder.sym.counterClockwise, ENCODER_FONT_SIZE, ctx), ENC_CCW_SYM_X, ENC_CCW_SYM_Y);
    }
    ctx.translate(ENCODER_TURN_CENTER_MARGIN*2,0);
    ctx.beginPath();
    ctx.fillStyle = ENCODER_COLOR + ENCODER_ALPHA;
    ctx.arc(0, 0, ENCODER_RADIUS/2, 0, (360*Math.PI) / 180);
    ctx.fill();
    ctx.fillStyle = TEXT_COLOR;
    if (encoder.main.clockwise) {
        ctx.textAlign = ENC_CW_MAIN_ALIGN;
        ctx.font = ENCODER_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(encoder.main.clockwise, ENCODER_FONT_SIZE, ctx), ENC_CW_MAIN_X, ENC_CW_MAIN_Y);
    }
    if (encoder.nav.clockwise) {
        ctx.textAlign = ENC_CW_NAV_ALIGN;
        ctx.font = ENCODER_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(encoder.nav.clockwise, ENCODER_FONT_SIZE, ctx), ENC_CW_NAV_X, ENC_CW_NAV_Y);
    }
    if (encoder.fun.clockwise) {
        ctx.textAlign = ENC_CW_FUN_ALIGN;
        ctx.font = ENCODER_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(encoder.fun.clockwise, ENCODER_FONT_SIZE, ctx), ENC_CW_FUN_X, ENC_CW_FUN_Y);
    }
    if (encoder.num.clockwise) {
        ctx.textAlign = ENC_CW_NUM_ALIGN;
        ctx.font = ENCODER_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(encoder.num.clockwise, ENCODER_FONT_SIZE, ctx), ENC_CW_NUM_X, ENC_CW_NUM_Y);
    }
    if (encoder.sym.clockwise) {
        ctx.textAlign = ENC_CW_SYM_ALIGN;
        ctx.font = ENCODER_FONT_SIZE+"px " + FONT;
        ctx.fillText(fixText(encoder.sym.clockwise, ENCODER_FONT_SIZE, ctx), ENC_CW_SYM_X, ENC_CW_SYM_Y);
    }
    resetTransformation(ctx, is_right);
}

function draw_oled(is_right, ctx) {
    ctx.fillStyle = OLED_COLOR + OLED_ALPHA;
    if (!is_right) {
        ctx.fillRect(LEFT_OLED_X, LEFT_OLED_Y, OLED_WIDTH, OLED_HEIGHT);
    } else {
        ctx.fillRect(RIGHT_OLED_X, RIGHT_OLED_Y, OLED_WIDTH, OLED_HEIGHT);
    }
}

function draw_left_thumbs(keys, ctx) {
    for (let key = 0; key < keys.length; key++) {
        draw_key_independent(LEFT_THUMB_KEY_X[key], LEFT_THUMB_KEY_Y[key], LEFT_THUMB_KEY_ROT[key], THUMB_COLOR, keys[key], false, ctx);
    }
}

function draw_right_thumbs(keys, ctx) {
    for (let key = 0; key < keys.length; key++) {
        draw_key_independent(RIGHT_THUMB_KEY_X[key], RIGHT_THUMB_KEY_Y[key], RIGHT_THUMB_KEY_ROT[key], THUMB_COLOR, keys[key], true, ctx);
    }
}
