
const KEY_SIZE = 50;

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
    console.log(rowN, colN, is_right)
}

function draw_encoder(encoder, is_right, ctx) {

}

function draw_left_thumbs(keys, ctx) {

}

function draw_right_thumbs(keys, ctx) {

}
