
#include <gfx/icon.hpp>
#include <bitset>

using namespace gfx;

const icon<14, 8> battery_empty({
    std::bitset<14>("00111111111111"),
    std::bitset<14>("00100000000001"),
    std::bitset<14>("11100000000001"),
    std::bitset<14>("11100000000001"),
    std::bitset<14>("11100000000001"),
    std::bitset<14>("11100000000001"),
    std::bitset<14>("00100000000001"),
    std::bitset<14>("00111111111111"),
});

const icon<14, 8> battery_1_4({
    std::bitset<14>("00111111111111"),
    std::bitset<14>("00100000000001"),
    std::bitset<14>("11100000011101"),
    std::bitset<14>("11100000011101"),
    std::bitset<14>("11100000011101"),
    std::bitset<14>("11100000011101"),
    std::bitset<14>("00100000000001"),
    std::bitset<14>("00111111111111"),
});

const icon<14, 8> battery_2_4({
    std::bitset<14>("00111111111111"),
    std::bitset<14>("00100000000001"),
    std::bitset<14>("11100001111101"),
    std::bitset<14>("11100001111101"),
    std::bitset<14>("11100001111101"),
    std::bitset<14>("11100001111101"),
    std::bitset<14>("00100000000001"),
    std::bitset<14>("00111111111111"),
});

const icon<14, 8> battery_3_4({
    std::bitset<14>("00111111111111"),
    std::bitset<14>("00100000000001"),
    std::bitset<14>("11100011111101"),
    std::bitset<14>("11100011111101"),
    std::bitset<14>("11100011111101"),
    std::bitset<14>("11100011111101"),
    std::bitset<14>("00100000000001"),
    std::bitset<14>("00111111111111"),
});

const icon<14, 8> battery_full({
    std::bitset<14>("00111111111111"),
    std::bitset<14>("00100000000001"),
    std::bitset<14>("11101111111101"),
    std::bitset<14>("11101111111101"),
    std::bitset<14>("11101111111101"),
    std::bitset<14>("11101111111101"),
    std::bitset<14>("00100000000001"),
    std::bitset<14>("00111111111111"),
});

/* ============================
 * Wireless icons (14 × 10)
 * ============================ */



const icon<14, 10> wireless_1({
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000110000000"),
    std::bitset<14>("00000110000000"),
});

const icon<14, 10> wireless_2({
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00001111000000"),
    std::bitset<14>("00010000100000"),
    std::bitset<14>("00000110000000"),
    std::bitset<14>("00000110000000"),
});

const icon<14, 10> wireless_3({
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00000000000000"),
    std::bitset<14>("00011111100000"),
    std::bitset<14>("00100000010000"),
    std::bitset<14>("00100000010000"),
    std::bitset<14>("00001111000000"),
    std::bitset<14>("00010000100000"),
    std::bitset<14>("00000110000000"),
    std::bitset<14>("00000110000000"),
});

const icon<14, 10> wireless_4({
    std::bitset<14>("00111111110000"),
    std::bitset<14>("01000000001000"),
    std::bitset<14>("10000000000100"),
    std::bitset<14>("10011111100100"),
    std::bitset<14>("00100000010000"),
    std::bitset<14>("00100000010000"),
    std::bitset<14>("00001111000000"),
    std::bitset<14>("00010000100000"),
    std::bitset<14>("00000110000000"),
    std::bitset<14>("00000110000000"),
});


/* PC monitor ikona (10 × 8) */
const icon<10, 8> pc_monitor({
	std::bitset<10>("1111111111"),
	std::bitset<10>("1000000001"),
	std::bitset<10>("1000000001"),
	std::bitset<10>("1000000001"),
	std::bitset<10>("1111111111"),
	std::bitset<10>("0000110000"),
	std::bitset<10>("0000110000"),
	std::bitset<10>("0011111100"),
});

/* Kulicka (puntik vybrano) */
const icon<7, 7> dot_filled({
    std::bitset<7>("0011100"),
    std::bitset<7>("0111110"),
    std::bitset<7>("1111111"),
    std::bitset<7>("1111111"),
    std::bitset<7>("1111111"),
    std::bitset<7>("0111110"),
    std::bitset<7>("0011100"),
});

/* Kulicka obrys (puntik nevybrano) */
const icon<7, 7> dot_outline({
    std::bitset<7>("0011100"),
    std::bitset<7>("0100010"),
    std::bitset<7>("1000001"),
    std::bitset<7>("1000001"),
    std::bitset<7>("1000001"),
    std::bitset<7>("0100010"),
    std::bitset<7>("0011100"),
});

/* Sipka nahoru */
const icon<7, 7> arrow_up({
    std::bitset<7>("0001000"),
    std::bitset<7>("0011100"),
    std::bitset<7>("0011100"),
    std::bitset<7>("0111110"),
    std::bitset<7>("0111110"),
    std::bitset<7>("1111111"),
    std::bitset<7>("1111111"),
});

/* Sipka dolu */
const icon<7, 7> arrow_down({
    std::bitset<7>("1111111"),
    std::bitset<7>("1111111"),
    std::bitset<7>("0111110"),
    std::bitset<7>("0111110"),
    std::bitset<7>("0011100"),
    std::bitset<7>("0011100"),
    std::bitset<7>("0001000"),
});

/* Sipka vlevo prazdna */
const icon<8, 9> arrow_left_empty({
    std::bitset<8>("00000100"),
    std::bitset<8>("00011100"),
    std::bitset<8>("00111010"),
    std::bitset<8>("01110001"),
    std::bitset<8>("11000001"),
    std::bitset<8>("01110001"),
    std::bitset<8>("00111010"),
    std::bitset<8>("00011100"),
    std::bitset<8>("00000100"),
});

/* Sipka vlevo plna */
const icon<8, 9> arrow_left_filled({
    std::bitset<8>("00000100"),
    std::bitset<8>("00011100"),
    std::bitset<8>("00111110"),
    std::bitset<8>("01111111"),
    std::bitset<8>("11111111"),
    std::bitset<8>("01111111"),
    std::bitset<8>("00111110"),
    std::bitset<8>("00011100"),
    std::bitset<8>("00000100"),
});

/* Sipka zpet plna (arrow_up otocena doleva) */
const icon<7, 7> back_filled({
    std::bitset<7>("0000011"),
    std::bitset<7>("0001111"),
    std::bitset<7>("0111111"),
    std::bitset<7>("1111111"),
    std::bitset<7>("0111111"),
    std::bitset<7>("0001111"),
    std::bitset<7>("0000011"),
});

/* Sipka zpet obrys */
const icon<7, 7> back_outline({
    std::bitset<7>("0000011"),
    std::bitset<7>("0001101"),
    std::bitset<7>("0110001"),
    std::bitset<7>("1000001"),
    std::bitset<7>("0110001"),
    std::bitset<7>("0001101"),
    std::bitset<7>("0000011"),
});

/* Checkbox nevybrany */
const icon<9, 9> checkbox_empty({
    std::bitset<9>("111111111"),
    std::bitset<9>("100000001"),
    std::bitset<9>("100000001"),
    std::bitset<9>("100000001"),
    std::bitset<9>("100000001"),
    std::bitset<9>("100000001"),
    std::bitset<9>("100000001"),
    std::bitset<9>("100000001"),
    std::bitset<9>("111111111"),
});

/* Checkbox nevybrany – checked */
const icon<9, 9> checkbox_empty_checked({
    std::bitset<9>("111111111"),
    std::bitset<9>("100000001"),
    std::bitset<9>("100000001"),
    std::bitset<9>("100111001"),
    std::bitset<9>("100111001"),
    std::bitset<9>("100111001"),
    std::bitset<9>("100000001"),
    std::bitset<9>("100000001"),
    std::bitset<9>("111111111"),
});

/* Checkbox vybrany */
const icon<9, 9> checkbox_filled({
    std::bitset<9>("111111111"),
    std::bitset<9>("111111111"),
    std::bitset<9>("110000011"),
    std::bitset<9>("110000011"),
    std::bitset<9>("110000011"),
    std::bitset<9>("110000011"),
    std::bitset<9>("110000011"),
    std::bitset<9>("111111111"),
    std::bitset<9>("111111111"),
});

/* Checkbox vybrany – checked */
const icon<9, 9> checkbox_filled_checked({
    std::bitset<9>("111111111"),
    std::bitset<9>("111111111"),
    std::bitset<9>("110000011"),
    std::bitset<9>("110111011"),
    std::bitset<9>("110111011"),
    std::bitset<9>("110111011"),
    std::bitset<9>("110000011"),
    std::bitset<9>("111111111"),
    std::bitset<9>("111111111"),
});

// Player buttons (21x13): normal and inverted (= selected)
/* Stop button */
const icon<21, 13> btn_stop_normal({
    std::bitset<21>("011111111111111111110"),
    std::bitset<21>("100000000000000000001"),
    std::bitset<21>("100000000000000000001"),
    std::bitset<21>("100000011111110000001"),
    std::bitset<21>("100000011111110000001"),
    std::bitset<21>("100000011111110000001"),
    std::bitset<21>("100000011111110000001"),
    std::bitset<21>("100000011111110000001"),
    std::bitset<21>("100000011111110000001"),
    std::bitset<21>("100000011111110000001"),
    std::bitset<21>("100000000000000000001"),
    std::bitset<21>("100000000000000000001"),
    std::bitset<21>("011111111111111111110"),
});

/* Stop button, selected (inverted) */
const icon<21, 13> btn_stop_selected({
    std::bitset<21>("011111111111111111110"),
    std::bitset<21>("111111111111111111111"),
    std::bitset<21>("111111111111111111111"),
    std::bitset<21>("111111100000001111111"),
    std::bitset<21>("111111100000001111111"),
    std::bitset<21>("111111100000001111111"),
    std::bitset<21>("111111100000001111111"),
    std::bitset<21>("111111100000001111111"),
    std::bitset<21>("111111100000001111111"),
    std::bitset<21>("111111100000001111111"),
    std::bitset<21>("111111111111111111111"),
    std::bitset<21>("111111111111111111111"),
    std::bitset<21>("011111111111111111110"),
});

/* Repeat button (add verse) */
const icon<21, 13> btn_repeat_normal({
    std::bitset<21>("011111111111111111110"),
    std::bitset<21>("100000000000000000001"),
    std::bitset<21>("100000000000000000001"),
    std::bitset<21>("100000000000010000001"),
    std::bitset<21>("100000111111111000001"),
    std::bitset<21>("100001000000010000001"),
    std::bitset<21>("100001000000000100001"),
    std::bitset<21>("100000010000000100001"),
    std::bitset<21>("100000111111111000001"),
    std::bitset<21>("100000010000000000001"),
    std::bitset<21>("100000000000000000001"),
    std::bitset<21>("100000000000000000001"),
    std::bitset<21>("011111111111111111110"),
});

/* Repeat button, selected (inverted) */
const icon<21, 13> btn_repeat_selected({
    std::bitset<21>("011111111111111111110"),
    std::bitset<21>("111111111111111111111"),
    std::bitset<21>("111111111111111111111"),
    std::bitset<21>("111111111111101111111"),
    std::bitset<21>("111111000000000111111"),
    std::bitset<21>("111110111111101111111"),
    std::bitset<21>("111110111111111011111"),
    std::bitset<21>("111111101111111011111"),
    std::bitset<21>("111111000000000111111"),
    std::bitset<21>("111111101111111111111"),
    std::bitset<21>("111111111111111111111"),
    std::bitset<21>("111111111111111111111"),
    std::bitset<21>("011111111111111111110"),
});

/* Play button */
const icon<21, 13> btn_play_normal({
    std::bitset<21>("011111111111111111110"),
    std::bitset<21>("100000000000000000001"),
    std::bitset<21>("100000000000000000001"),
    std::bitset<21>("100000001000000000001"),
    std::bitset<21>("100000001100000000001"),
    std::bitset<21>("100000001110000000001"),
    std::bitset<21>("100000001111000000001"),
    std::bitset<21>("100000001110000000001"),
    std::bitset<21>("100000001100000000001"),
    std::bitset<21>("100000001000000000001"),
    std::bitset<21>("100000000000000000001"),
    std::bitset<21>("100000000000000000001"),
    std::bitset<21>("011111111111111111110"),
});

/* Play button, selected (inverted) */
const icon<21, 13> btn_play_selected({
    std::bitset<21>("011111111111111111110"),
    std::bitset<21>("111111111111111111111"),
    std::bitset<21>("111111111111111111111"),
    std::bitset<21>("111111110111111111111"),
    std::bitset<21>("111111110011111111111"),
    std::bitset<21>("111111110001111111111"),
    std::bitset<21>("111111110000111111111"),
    std::bitset<21>("111111110001111111111"),
    std::bitset<21>("111111110011111111111"),
    std::bitset<21>("111111110111111111111"),
    std::bitset<21>("111111111111111111111"),
    std::bitset<21>("111111111111111111111"),
    std::bitset<21>("011111111111111111110"),
});
