/*******************************************************************************
 * Size: 20 px
 * Bpp: 1
 * Opts: --bpp 1 --size 20 --font /Users/mah/Ballon/src/BalloonWare/flowsensor/squareline-ui/assets/Montserrat-Bold.ttf -o /Users/mah/Ballon/src/BalloonWare/flowsensor/squareline-ui/assets/ui_font_Font2.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_FONT2
#define UI_FONT_FONT2 1
#endif

#if UI_FONT_FONT2

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xee, 0xee, 0xee, 0xee, 0xe0, 0x0, 0xff,

    /* U+0022 "\"" */
    0xef, 0xdf, 0xbf, 0x7e, 0xe0,

    /* U+0023 "#" */
    0xc, 0x60, 0x31, 0x80, 0xc6, 0x1f, 0xff, 0x7f,
    0xfc, 0x71, 0x81, 0xce, 0x7, 0x38, 0x18, 0xe3,
    0xff, 0xef, 0xff, 0x86, 0x30, 0x18, 0xc0, 0x63,
    0x0,

    /* U+0024 "$" */
    0x6, 0x0, 0xc0, 0x3c, 0x1f, 0xe7, 0xfd, 0xec,
    0xb9, 0x87, 0xb0, 0xfe, 0xf, 0xf8, 0x7f, 0x3,
    0xf0, 0x6f, 0x8d, 0xff, 0xff, 0xfe, 0x3f, 0x80,
    0xc0, 0x18, 0x0,

    /* U+0025 "%" */
    0x38, 0xc, 0x6c, 0x18, 0xc6, 0x30, 0xc6, 0x30,
    0xc6, 0x60, 0xec, 0xc0, 0x38, 0xc0, 0x1, 0x9e,
    0x3, 0x33, 0x7, 0x33, 0x6, 0x33, 0xc, 0x33,
    0x1c, 0x33, 0x18, 0x1e,

    /* U+0026 "&" */
    0xf, 0x0, 0xfe, 0xe, 0x70, 0x73, 0x83, 0xbc,
    0xf, 0xc0, 0x78, 0xf, 0xe6, 0xf3, 0xbf, 0x1f,
    0xb8, 0x7d, 0xe3, 0xe7, 0xff, 0x9f, 0x88,

    /* U+0027 "'" */
    0xff, 0xfe,

    /* U+0028 "(" */
    0x39, 0xdc, 0xe7, 0x73, 0x9c, 0xe7, 0x39, 0xce,
    0x71, 0xce, 0x71, 0xce,

    /* U+0029 ")" */
    0xe7, 0x1c, 0xe7, 0x1c, 0xe7, 0x39, 0xce, 0x73,
    0x9d, 0xce, 0x77, 0x38,

    /* U+002A "*" */
    0x18, 0x18, 0xff, 0x7e, 0x7e, 0xff, 0x18, 0x18,

    /* U+002B "+" */
    0x1c, 0x7, 0x1, 0xc3, 0xff, 0xff, 0xc7, 0x1,
    0xc0, 0x70, 0x1c, 0x0,

    /* U+002C "," */
    0x6f, 0xf7, 0x66, 0xc0,

    /* U+002D "-" */
    0xff, 0xf0,

    /* U+002E "." */
    0x6f, 0xf6,

    /* U+002F "/" */
    0x1, 0xc0, 0xe0, 0x38, 0xe, 0x7, 0x1, 0xc0,
    0x60, 0x38, 0xe, 0x3, 0x1, 0xc0, 0x70, 0x18,
    0xe, 0x3, 0x80, 0xc0, 0x70, 0x1c, 0x6, 0x0,

    /* U+0030 "0" */
    0xf, 0x3, 0xfc, 0x79, 0xe7, 0xe, 0xe0, 0x7e,
    0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x7e, 0x7, 0x70,
    0xe7, 0xe, 0x3f, 0xc1, 0xf8,

    /* U+0031 "1" */
    0xff, 0xf1, 0xc7, 0x1c, 0x71, 0xc7, 0x1c, 0x71,
    0xc7, 0x1c, 0x70,

    /* U+0032 "2" */
    0x1f, 0x87, 0xfc, 0x71, 0xe0, 0xe, 0x0, 0xe0,
    0xe, 0x1, 0xe0, 0x3c, 0x7, 0x80, 0xf0, 0x1e,
    0x3, 0xc0, 0x7f, 0xf7, 0xff,

    /* U+0033 "3" */
    0x7f, 0xef, 0xfc, 0xf, 0x1, 0xc0, 0x70, 0x1e,
    0x3, 0xf0, 0x7f, 0x1, 0xe0, 0x1c, 0x3, 0xb0,
    0xf7, 0xfc, 0x7e, 0x0,

    /* U+0034 "4" */
    0x1, 0xc0, 0x1c, 0x1, 0xe0, 0x1e, 0x0, 0xe0,
    0xf, 0x0, 0xf3, 0x8f, 0x1c, 0x70, 0xe7, 0xff,
    0xff, 0xfe, 0x1, 0xc0, 0xe, 0x0, 0x70,

    /* U+0035 "5" */
    0x3f, 0xc7, 0xf8, 0xe0, 0x38, 0x7, 0x0, 0xff,
    0x1f, 0xf0, 0xf, 0x0, 0xe0, 0x1d, 0x3, 0xb0,
    0xef, 0xfc, 0x7e, 0x0,

    /* U+0036 "6" */
    0xf, 0xc7, 0xf9, 0xe1, 0x38, 0xe, 0x1, 0xdf,
    0x3f, 0xf7, 0x8f, 0xe0, 0xfc, 0x1f, 0x83, 0xb8,
    0xf3, 0xfc, 0x3e, 0x0,

    /* U+0037 "7" */
    0xff, 0xff, 0xff, 0x87, 0xf0, 0xe0, 0x3c, 0x7,
    0x0, 0xe0, 0x3c, 0x7, 0x1, 0xe0, 0x38, 0x7,
    0x1, 0xe0, 0x38, 0x0,

    /* U+0038 "8" */
    0x1f, 0x83, 0xfc, 0x70, 0xe7, 0xe, 0x70, 0xe3,
    0xfc, 0x7f, 0xef, 0xf, 0xe0, 0x7e, 0x7, 0xe0,
    0x7f, 0xe, 0x7f, 0xe1, 0xf8,

    /* U+0039 "9" */
    0x1f, 0xf, 0xf3, 0xc7, 0x70, 0x6e, 0xf, 0xe3,
    0xdf, 0xf9, 0xf7, 0x0, 0xe0, 0x1c, 0x7, 0x21,
    0xe7, 0xf8, 0xfc, 0x0,

    /* U+003A ":" */
    0x6f, 0xf6, 0x0, 0x6, 0xff, 0x60,

    /* U+003B ";" */
    0x6f, 0xf6, 0x0, 0x6, 0xff, 0x76, 0x6c,

    /* U+003C "<" */
    0x0, 0xc0, 0xf1, 0xff, 0xf8, 0xf0, 0x3c, 0x7,
    0xe0, 0x7f, 0x3, 0xc0, 0x30,

    /* U+003D "=" */
    0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x3f, 0xff,
    0xfc,

    /* U+003E ">" */
    0x80, 0x3c, 0xf, 0xe0, 0x7e, 0x7, 0xc1, 0xf3,
    0xfb, 0xf0, 0xf0, 0x20, 0x0,

    /* U+003F "?" */
    0x1f, 0x8f, 0xf9, 0xc7, 0x90, 0x70, 0xe, 0x3,
    0xc0, 0xf0, 0x3c, 0xf, 0x1, 0xc0, 0x0, 0x0,
    0x0, 0xf0, 0x1e, 0x0,

    /* U+0040 "@" */
    0x3, 0xf8, 0x1, 0xff, 0xc0, 0x78, 0x1c, 0x1c,
    0x1, 0xc7, 0x1e, 0xec, 0xcf, 0xfd, 0xb1, 0xc7,
    0x9e, 0x70, 0x73, 0xce, 0xe, 0x79, 0xc1, 0xcf,
    0x38, 0x39, 0xe3, 0x8f, 0x36, 0x7f, 0xfc, 0xe3,
    0xcf, 0xe, 0x0, 0x0, 0xf0, 0x20, 0xf, 0xfc,
    0x0, 0x7f, 0x0,

    /* U+0041 "A" */
    0x3, 0x80, 0x7, 0xc0, 0x7, 0xc0, 0xf, 0xe0,
    0xe, 0xe0, 0xe, 0xf0, 0x1c, 0x70, 0x1c, 0x78,
    0x3c, 0x38, 0x3f, 0xfc, 0x7f, 0xfc, 0x70, 0x1c,
    0xf0, 0x1e, 0xe0, 0xe,

    /* U+0042 "B" */
    0xff, 0xc7, 0xff, 0x38, 0x3d, 0xc0, 0xee, 0x7,
    0x70, 0x7b, 0xff, 0x9f, 0xfe, 0xe0, 0x7f, 0x1,
    0xf8, 0xf, 0xc0, 0xff, 0xff, 0x7f, 0xf0,

    /* U+0043 "C" */
    0x7, 0xe0, 0xff, 0xce, 0x1c, 0xe0, 0xf, 0x0,
    0x70, 0x3, 0x80, 0x1c, 0x0, 0xe0, 0x7, 0x80,
    0x1c, 0x0, 0x70, 0xe1, 0xff, 0x87, 0xf0,

    /* U+0044 "D" */
    0xff, 0x83, 0xff, 0x8e, 0xf, 0x38, 0xe, 0xe0,
    0x3f, 0x80, 0x7e, 0x1, 0xf8, 0x7, 0xe0, 0x1f,
    0x80, 0xfe, 0x3, 0xb8, 0x3c, 0xff, 0xe3, 0xff,
    0x0,

    /* U+0045 "E" */
    0xff, 0xff, 0xff, 0x80, 0x70, 0xe, 0x1, 0xc0,
    0x3f, 0xf7, 0xfe, 0xe0, 0x1c, 0x3, 0x80, 0x70,
    0xf, 0xff, 0xff, 0xc0,

    /* U+0046 "F" */
    0xff, 0xff, 0xff, 0x80, 0x70, 0xe, 0x1, 0xc0,
    0x38, 0x7, 0xfe, 0xff, 0xdc, 0x3, 0x80, 0x70,
    0xe, 0x1, 0xc0, 0x0,

    /* U+0047 "G" */
    0x7, 0xe0, 0xff, 0xce, 0xc, 0xe0, 0xf, 0x0,
    0x70, 0x3, 0x80, 0x1c, 0x7, 0xe0, 0x3f, 0x81,
    0xdc, 0xe, 0x70, 0x71, 0xff, 0x87, 0xf0,

    /* U+0048 "H" */
    0xe0, 0x3f, 0x1, 0xf8, 0xf, 0xc0, 0x7e, 0x3,
    0xf0, 0x1f, 0xff, 0xff, 0xff, 0xe0, 0x3f, 0x1,
    0xf8, 0xf, 0xc0, 0x7e, 0x3, 0xf0, 0x1c,

    /* U+0049 "I" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,

    /* U+004A "J" */
    0x7f, 0xbf, 0xc0, 0xe0, 0x70, 0x38, 0x1c, 0xe,
    0x7, 0x3, 0x81, 0xd0, 0xf8, 0xff, 0xf3, 0xf0,

    /* U+004B "K" */
    0xe0, 0x77, 0x7, 0x38, 0x71, 0xc7, 0x8e, 0x78,
    0x77, 0x83, 0xf8, 0x1f, 0xe0, 0xff, 0x87, 0x9e,
    0x38, 0x71, 0xc3, 0xce, 0xf, 0x70, 0x3c,

    /* U+004C "L" */
    0xe0, 0x1c, 0x3, 0x80, 0x70, 0xe, 0x1, 0xc0,
    0x38, 0x7, 0x0, 0xe0, 0x1c, 0x3, 0x80, 0x70,
    0xf, 0xff, 0xff, 0xc0,

    /* U+004D "M" */
    0xe0, 0x7, 0xf0, 0xf, 0xf0, 0xf, 0xf8, 0x1f,
    0xf8, 0x1f, 0xfc, 0x3f, 0xfe, 0x77, 0xee, 0x77,
    0xe7, 0xe7, 0xe7, 0xe7, 0xe3, 0xc7, 0xe1, 0x87,
    0xe1, 0x87, 0xe0, 0x7,

    /* U+004E "N" */
    0xe0, 0x3f, 0x81, 0xfe, 0xf, 0xf8, 0x7f, 0xc3,
    0xff, 0x1f, 0xbc, 0xfc, 0xf7, 0xe3, 0xff, 0xf,
    0xf8, 0x7f, 0xc1, 0xfe, 0x7, 0xf0, 0x1c,

    /* U+004F "O" */
    0x7, 0xc0, 0x3f, 0xe0, 0xf1, 0xe3, 0x80, 0xef,
    0x1, 0xfc, 0x1, 0xf8, 0x3, 0xf0, 0x7, 0xe0,
    0xf, 0xe0, 0x3d, 0xc0, 0x71, 0xe3, 0xc1, 0xff,
    0x0, 0xf8, 0x0,

    /* U+0050 "P" */
    0xff, 0x8f, 0xfe, 0xe0, 0xee, 0x7, 0xe0, 0x7e,
    0x7, 0xe0, 0x7e, 0xe, 0xff, 0xef, 0xf8, 0xe0,
    0xe, 0x0, 0xe0, 0xe, 0x0,

    /* U+0051 "Q" */
    0x7, 0xc0, 0x1f, 0xf0, 0x38, 0x38, 0x70, 0x1c,
    0xf0, 0xe, 0xe0, 0xe, 0xe0, 0xe, 0xe0, 0xe,
    0xe0, 0xe, 0xf0, 0x1e, 0x78, 0x3c, 0x3f, 0xfc,
    0x1f, 0xf8, 0xf, 0xe0, 0x1, 0xe2, 0x0, 0xff,
    0x0, 0x3c,

    /* U+0052 "R" */
    0xff, 0x8f, 0xfe, 0xe0, 0xee, 0x7, 0xe0, 0x7e,
    0x7, 0xe0, 0x7e, 0xe, 0xff, 0xef, 0xf8, 0xe1,
    0xce, 0x1e, 0xe0, 0xee, 0x7,

    /* U+0053 "S" */
    0x1f, 0x8f, 0xfb, 0xc3, 0x70, 0xe, 0x1, 0xf8,
    0x1f, 0xe1, 0xfe, 0xf, 0xe0, 0x3c, 0x3, 0xf0,
    0xff, 0xfc, 0xfe, 0x0,

    /* U+0054 "T" */
    0xff, 0xff, 0xff, 0x7, 0x0, 0x70, 0x7, 0x0,
    0x70, 0x7, 0x0, 0x70, 0x7, 0x0, 0x70, 0x7,
    0x0, 0x70, 0x7, 0x0, 0x70,

    /* U+0055 "U" */
    0xe0, 0x3f, 0x1, 0xf8, 0xf, 0xc0, 0x7e, 0x3,
    0xf0, 0x1f, 0x80, 0xfc, 0x7, 0xe0, 0x3f, 0x1,
    0xfc, 0x1e, 0xe0, 0xe3, 0xfe, 0x7, 0xe0,

    /* U+0056 "V" */
    0xf0, 0xf, 0xe0, 0x39, 0xc0, 0x73, 0xc1, 0xe3,
    0x83, 0x87, 0x87, 0x7, 0x1c, 0xf, 0x38, 0x1e,
    0xe0, 0x1d, 0xc0, 0x3f, 0x80, 0x3e, 0x0, 0x7c,
    0x0, 0x70, 0x0,

    /* U+0057 "W" */
    0x70, 0x38, 0xe, 0xe0, 0x78, 0x39, 0xe1, 0xf0,
    0x71, 0xc3, 0xe0, 0xe3, 0x87, 0xe3, 0x87, 0x9d,
    0xc7, 0x7, 0x3b, 0x8e, 0xe, 0x73, 0xb8, 0x1f,
    0xc7, 0x70, 0x1f, 0x8e, 0xe0, 0x3f, 0xf, 0x80,
    0x7c, 0x1f, 0x0, 0x78, 0x3e, 0x0, 0xf0, 0x38,
    0x0,

    /* U+0058 "X" */
    0x70, 0x3d, 0xe1, 0xe3, 0xc7, 0x7, 0x38, 0xf,
    0xe0, 0x3f, 0x0, 0x78, 0x1, 0xf0, 0xf, 0xc0,
    0x7f, 0x81, 0xcf, 0xe, 0x1c, 0x78, 0x7b, 0xc0,
    0xf0,

    /* U+0059 "Y" */
    0xe0, 0x3f, 0x83, 0xdc, 0x1c, 0x71, 0xc3, 0xce,
    0xe, 0xe0, 0x7f, 0x1, 0xf0, 0x7, 0x0, 0x38,
    0x1, 0xc0, 0xe, 0x0, 0x70, 0x3, 0x80,

    /* U+005A "Z" */
    0xff, 0xff, 0xff, 0x1, 0xe0, 0x1e, 0x3, 0xc0,
    0x78, 0xf, 0x0, 0xf0, 0x1e, 0x3, 0xc0, 0x78,
    0x7, 0x80, 0xff, 0xff, 0xff,

    /* U+005B "[" */
    0xff, 0xfe, 0x38, 0xe3, 0x8e, 0x38, 0xe3, 0x8e,
    0x38, 0xe3, 0x8e, 0x38, 0xe3, 0xff, 0xc0,

    /* U+005C "\\" */
    0xe0, 0x18, 0x7, 0x1, 0xc0, 0x30, 0xe, 0x3,
    0x80, 0x70, 0x1c, 0x7, 0x0, 0xe0, 0x38, 0xe,
    0x1, 0xc0, 0x70, 0xc, 0x3, 0x80, 0xe0, 0x18,

    /* U+005D "]" */
    0xff, 0xf1, 0xc7, 0x1c, 0x71, 0xc7, 0x1c, 0x71,
    0xc7, 0x1c, 0x71, 0xc7, 0x1f, 0xff, 0xc0,

    /* U+005E "^" */
    0xc, 0x7, 0x81, 0xe0, 0xfc, 0x33, 0xc, 0xc7,
    0x39, 0x86, 0xe1, 0xc0,

    /* U+005F "_" */
    0xff, 0xff, 0xf0,

    /* U+0060 "`" */
    0xf0, 0xc1, 0x80,

    /* U+0061 "a" */
    0x3f, 0x1f, 0xe6, 0x3c, 0x7, 0x1, 0xcf, 0xff,
    0xff, 0x87, 0xe3, 0xff, 0xf3, 0xdc,

    /* U+0062 "b" */
    0xe0, 0xe, 0x0, 0xe0, 0xe, 0x0, 0xef, 0x8f,
    0xfc, 0xf0, 0xee, 0x7, 0xe0, 0x7e, 0x7, 0xe0,
    0x7e, 0x7, 0xf0, 0xef, 0xfc, 0xef, 0x80,

    /* U+0063 "c" */
    0x1f, 0x87, 0xf9, 0xc7, 0x70, 0x4e, 0x1, 0xc0,
    0x38, 0x7, 0x4, 0x71, 0xc7, 0xf8, 0x7e, 0x0,

    /* U+0064 "d" */
    0x0, 0x70, 0x7, 0x0, 0x70, 0x7, 0x1f, 0x73,
    0xff, 0x70, 0xfe, 0x7, 0xe0, 0x7e, 0x7, 0xe0,
    0x7e, 0x7, 0x70, 0xf3, 0xff, 0x1f, 0x70,

    /* U+0065 "e" */
    0x1f, 0x7, 0xf9, 0xc7, 0x70, 0x7f, 0xff, 0xff,
    0xf8, 0x7, 0x80, 0x70, 0x87, 0xf8, 0x7e, 0x0,

    /* U+0066 "f" */
    0xf, 0x1e, 0x38, 0x38, 0xfe, 0xfe, 0x38, 0x38,
    0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38,

    /* U+0067 "g" */
    0x1f, 0x77, 0xff, 0x70, 0xfe, 0x7, 0xe0, 0x7e,
    0x7, 0xe0, 0x77, 0xf, 0x7f, 0xf1, 0xf7, 0x0,
    0x70, 0x7, 0x60, 0xe7, 0xfc, 0x3f, 0x80,

    /* U+0068 "h" */
    0xe0, 0x1c, 0x3, 0x80, 0x70, 0xe, 0xf9, 0xff,
    0xbc, 0x7f, 0x7, 0xe0, 0xfc, 0x1f, 0x83, 0xf0,
    0x7e, 0xf, 0xc1, 0xf8, 0x38,

    /* U+0069 "i" */
    0xff, 0x0, 0xe, 0xee, 0xee, 0xee, 0xee, 0xee,

    /* U+006A "j" */
    0x1e, 0x3c, 0x0, 0x0, 0x3, 0x87, 0xe, 0x1c,
    0x38, 0x70, 0xe1, 0xc3, 0x87, 0xe, 0x1c, 0x3b,
    0xe7, 0x80,

    /* U+006B "k" */
    0xe0, 0xe, 0x0, 0xe0, 0xe, 0x0, 0xe1, 0xee,
    0x3c, 0xe7, 0x8e, 0xf0, 0xfe, 0xf, 0xe0, 0xff,
    0xf, 0x78, 0xe3, 0xce, 0x1e, 0xe1, 0xe0,

    /* U+006C "l" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf8,

    /* U+006D "m" */
    0xef, 0x8f, 0x9f, 0xff, 0xfb, 0xc7, 0xc7, 0xf0,
    0x70, 0x7e, 0xe, 0xf, 0xc1, 0xc1, 0xf8, 0x38,
    0x3f, 0x7, 0x7, 0xe0, 0xe0, 0xfc, 0x1c, 0x1f,
    0x83, 0x83, 0x80,

    /* U+006E "n" */
    0xef, 0x9f, 0xfb, 0xc7, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xfc, 0x1f, 0x83, 0x80,

    /* U+006F "o" */
    0x1f, 0x83, 0xfc, 0x70, 0xee, 0x7, 0xe0, 0x7e,
    0x7, 0xe0, 0x7e, 0x7, 0x70, 0xe3, 0xfc, 0x1f,
    0x80,

    /* U+0070 "p" */
    0xef, 0x8f, 0xfc, 0xf0, 0xee, 0x7, 0xe0, 0x7e,
    0x7, 0xe0, 0x7e, 0x7, 0xf0, 0xef, 0xfc, 0xef,
    0x8e, 0x0, 0xe0, 0xe, 0x0, 0xe0, 0x0,

    /* U+0071 "q" */
    0x1f, 0x73, 0xff, 0x70, 0xfe, 0x7, 0xe0, 0x7e,
    0x7, 0xe0, 0x7e, 0x7, 0x70, 0xf3, 0xff, 0x1f,
    0x70, 0x7, 0x0, 0x70, 0x7, 0x0, 0x70,

    /* U+0072 "r" */
    0xef, 0xff, 0xc7, 0xe, 0x1c, 0x38, 0x70, 0xe1,
    0xc3, 0x80,

    /* U+0073 "s" */
    0x3f, 0x3f, 0xb8, 0x5c, 0xf, 0xe3, 0xf8, 0xfe,
    0x7, 0xc3, 0xff, 0x9f, 0x80,

    /* U+0074 "t" */
    0x38, 0x38, 0x38, 0xfe, 0xfe, 0x38, 0x38, 0x38,
    0x38, 0x38, 0x38, 0x38, 0x1e, 0xf,

    /* U+0075 "u" */
    0xe0, 0xfc, 0x1f, 0x83, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xf1, 0xef, 0xfc, 0xfb, 0x80,

    /* U+0076 "v" */
    0xe0, 0x7f, 0xf, 0x70, 0xe7, 0xe, 0x39, 0xc3,
    0x9c, 0x1f, 0x81, 0xf8, 0x1f, 0x80, 0xf0, 0xf,
    0x0,

    /* U+0077 "w" */
    0xe0, 0xe0, 0xec, 0x1c, 0x39, 0xc7, 0xc7, 0x38,
    0xf8, 0xc3, 0x9b, 0x38, 0x77, 0x77, 0xe, 0xee,
    0xc0, 0xf8, 0xf8, 0x1f, 0x1f, 0x3, 0xc3, 0xc0,
    0x38, 0x38, 0x0,

    /* U+0078 "x" */
    0x70, 0xe7, 0x9e, 0x3d, 0xc1, 0xf8, 0xf, 0x0,
    0xf0, 0x1f, 0x1, 0xf8, 0x39, 0xc7, 0x9e, 0xf0,
    0xe0,

    /* U+0079 "y" */
    0xe0, 0x7f, 0x7, 0x70, 0xe7, 0xe, 0x39, 0xc3,
    0x9c, 0x3d, 0x81, 0xf8, 0x1f, 0x80, 0xf0, 0xf,
    0x0, 0xe0, 0xe, 0xf, 0xc0, 0xf8, 0x0,

    /* U+007A "z" */
    0xff, 0xff, 0xf0, 0x78, 0x1c, 0xf, 0x7, 0x83,
    0xc1, 0xe0, 0x78, 0x3f, 0xff, 0xfc,

    /* U+007B "{" */
    0xe, 0x3c, 0xe1, 0xc3, 0x87, 0xe, 0x1c, 0x39,
    0xe3, 0xc1, 0xc3, 0x87, 0xe, 0x1c, 0x38, 0x7c,
    0x78,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80,

    /* U+007D "}" */
    0xe1, 0xe0, 0xe1, 0xc3, 0x87, 0xe, 0x1c, 0x38,
    0x3c, 0xf9, 0xc3, 0x87, 0xe, 0x1c, 0x39, 0xf3,
    0x80,

    /* U+007E "~" */
    0x78, 0xff, 0x3c, 0xfb, 0x1e
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 91, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 92, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 8, .adv_w = 140, .box_w = 7, .box_h = 5, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 13, .adv_w = 230, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 38, .adv_w = 204, .box_w = 11, .box_h = 19, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 65, .adv_w = 281, .box_w = 16, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 93, .adv_w = 233, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 116, .adv_w = 74, .box_w = 3, .box_h = 5, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 118, .adv_w = 114, .box_w = 5, .box_h = 19, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 130, .adv_w = 115, .box_w = 5, .box_h = 19, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 142, .adv_w = 139, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 150, .adv_w = 192, .box_w = 10, .box_h = 9, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 162, .adv_w = 84, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 166, .adv_w = 124, .box_w = 6, .box_h = 2, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 168, .adv_w = 84, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 170, .adv_w = 125, .box_w = 10, .box_h = 19, .ofs_x = -1, .ofs_y = -2},
    {.bitmap_index = 194, .adv_w = 217, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 215, .adv_w = 125, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 226, .adv_w = 189, .box_w = 12, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 247, .adv_w = 189, .box_w = 11, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 267, .adv_w = 220, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 290, .adv_w = 190, .box_w = 11, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 310, .adv_w = 204, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 330, .adv_w = 198, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 350, .adv_w = 211, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 371, .adv_w = 204, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 391, .adv_w = 84, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 397, .adv_w = 84, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 404, .adv_w = 192, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 417, .adv_w = 192, .box_w = 10, .box_h = 7, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 426, .adv_w = 192, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 439, .adv_w = 188, .box_w = 11, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 459, .adv_w = 331, .box_w = 19, .box_h = 18, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 502, .adv_w = 245, .box_w = 16, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 530, .adv_w = 245, .box_w = 13, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 553, .adv_w = 235, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 576, .adv_w = 264, .box_w = 14, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 601, .adv_w = 215, .box_w = 11, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 621, .adv_w = 204, .box_w = 11, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 641, .adv_w = 247, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 664, .adv_w = 259, .box_w = 13, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 687, .adv_w = 105, .box_w = 3, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 693, .adv_w = 173, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 709, .adv_w = 237, .box_w = 13, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 732, .adv_w = 193, .box_w = 11, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 752, .adv_w = 306, .box_w = 16, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 780, .adv_w = 259, .box_w = 13, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 803, .adv_w = 270, .box_w = 15, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 830, .adv_w = 234, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 851, .adv_w = 270, .box_w = 16, .box_h = 17, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 885, .adv_w = 235, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 906, .adv_w = 204, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 926, .adv_w = 198, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 947, .adv_w = 252, .box_w = 13, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 970, .adv_w = 239, .box_w = 15, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 997, .adv_w = 372, .box_w = 23, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1038, .adv_w = 228, .box_w = 14, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1063, .adv_w = 216, .box_w = 13, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1086, .adv_w = 215, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1107, .adv_w = 118, .box_w = 6, .box_h = 19, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 1122, .adv_w = 125, .box_w = 10, .box_h = 19, .ofs_x = -1, .ofs_y = -2},
    {.bitmap_index = 1146, .adv_w = 118, .box_w = 6, .box_h = 19, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 1161, .adv_w = 192, .box_w = 10, .box_h = 9, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 1173, .adv_w = 160, .box_w = 10, .box_h = 2, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1176, .adv_w = 192, .box_w = 6, .box_h = 3, .ofs_x = 2, .ofs_y = 12},
    {.bitmap_index = 1179, .adv_w = 197, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1193, .adv_w = 221, .box_w = 12, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1216, .adv_w = 189, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1232, .adv_w = 221, .box_w = 12, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1255, .adv_w = 202, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1271, .adv_w = 124, .box_w = 8, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1286, .adv_w = 224, .box_w = 12, .box_h = 15, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1309, .adv_w = 221, .box_w = 11, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1330, .adv_w = 96, .box_w = 4, .box_h = 16, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1338, .adv_w = 98, .box_w = 7, .box_h = 20, .ofs_x = -2, .ofs_y = -4},
    {.bitmap_index = 1356, .adv_w = 211, .box_w = 12, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1379, .adv_w = 96, .box_w = 3, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1385, .adv_w = 336, .box_w = 19, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1412, .adv_w = 221, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1428, .adv_w = 210, .box_w = 12, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1445, .adv_w = 221, .box_w = 12, .box_h = 15, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1468, .adv_w = 221, .box_w = 12, .box_h = 15, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1491, .adv_w = 138, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1501, .adv_w = 170, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1514, .adv_w = 139, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1528, .adv_w = 220, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1544, .adv_w = 191, .box_w = 12, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1561, .adv_w = 300, .box_w = 19, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1588, .adv_w = 190, .box_w = 12, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1605, .adv_w = 191, .box_w = 12, .box_h = 15, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 1628, .adv_w = 174, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1642, .adv_w = 125, .box_w = 7, .box_h = 19, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1659, .adv_w = 99, .box_w = 3, .box_h = 19, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 1667, .adv_w = 125, .box_w = 7, .box_h = 19, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1684, .adv_w = 192, .box_w = 10, .box_h = 4, .ofs_x = 1, .ofs_y = 5}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 1, 2, 0, 3, 4, 5,
    2, 6, 7, 8, 9, 10, 9, 10,
    11, 12, 0, 13, 14, 15, 16, 17,
    18, 19, 12, 20, 20, 0, 0, 0,
    21, 22, 23, 24, 25, 22, 26, 27,
    28, 29, 29, 30, 31, 32, 29, 29,
    22, 33, 34, 35, 3, 36, 30, 37,
    37, 38, 39, 40, 41, 42, 43, 0,
    44, 0, 45, 46, 47, 48, 49, 50,
    51, 45, 52, 52, 53, 48, 45, 45,
    46, 46, 54, 55, 56, 57, 51, 58,
    58, 59, 58, 60, 41, 0, 0, 9
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 0, 1, 2, 0, 3, 4, 5,
    2, 6, 7, 8, 9, 10, 9, 10,
    11, 12, 13, 14, 15, 16, 17, 12,
    18, 19, 20, 21, 21, 0, 0, 0,
    22, 23, 24, 25, 23, 25, 25, 25,
    23, 25, 25, 26, 25, 25, 25, 25,
    23, 25, 23, 25, 3, 27, 28, 29,
    29, 30, 31, 32, 33, 34, 35, 0,
    36, 0, 37, 38, 39, 39, 39, 0,
    39, 38, 40, 41, 38, 38, 42, 42,
    39, 42, 39, 42, 43, 44, 45, 46,
    46, 47, 46, 48, 0, 0, 35, 9
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, 2, 0, 0, 0, 0, 0, 0,
    0, 2, 0, 0, 3, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    2, 14, 0, 8, -5, 0, 0, 0,
    0, -18, -19, 1, 14, 5, 4, -13,
    1, 13, 1, 12, 3, 9, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 19, 4, -1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -10, 0, 0, 0, 0, 0, -6,
    4, 6, 0, 0, -3, 0, -1, 3,
    0, -3, 0, -3, -2, -6, 0, 0,
    0, 0, -3, 0, 0, -4, -5, 0,
    0, -3, 0, -6, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -3, -3, 0,
    0, -8, 0, -40, 0, 0, -6, 0,
    6, 10, 0, 0, -6, 3, 3, 10,
    6, -4, 6, 0, 0, -17, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -11, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -4, -13, 0, -13, -1, 0, 0, 0,
    0, -1, 10, 0, -10, -4, -2, 2,
    0, -4, 0, 0, -3, -21, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -26, -4, 7, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 12, 0, 3, 0, 0, -6,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 14, 4, 2, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -11, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    3, 6, 3, 10, -3, 0, 0, 6,
    -3, -12, -42, 1, 8, 6, 0, -4,
    0, 8, 0, 9, 0, 9, 0, -31,
    0, -4, 10, 0, 10, -3, 6, 3,
    0, 0, 2, -3, 0, 0, -4, 26,
    0, 26, 0, 10, 0, 12, 5, 4,
    0, 0, 0, -11, 0, 0, 0, 0,
    2, -3, 0, 1, -7, -5, -6, 1,
    0, -3, 0, 0, 0, -13, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -21, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    2, -18, 0, -21, 0, 0, 0, 0,
    -3, 0, 29, -4, -5, 3, 3, 0,
    0, -5, 3, 0, 0, -18, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -30, 0, 3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 19, 0, 0, -11, 0, 12, 0,
    -23, -30, -23, -6, 10, 0, 0, -20,
    0, 2, -8, 0, -5, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 4, 10, -37, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 1,
    1, -4, -6, 0, -2, -2, -3, 0,
    0, -1, 0, 0, 0, -6, 0, -4,
    0, -8, -6, 0, -8, -12, -12, -5,
    0, -6, 0, -6, 0, 0, 0, 0,
    -3, 0, 0, 3, 0, 1, -3, 0,
    0, 0, 0, 3, -1, 0, 0, 0,
    -1, 3, 3, -1, 0, 0, 0, -3,
    0, -1, 0, 0, 0, 0, 0, 2,
    0, 5, -1, 0, -4, 0, -6, 0,
    0, -1, 0, 10, 0, 0, -3, 0,
    0, 0, 0, 0, -1, 1, -1, -1,
    0, -3, 0, -3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -2, -2, 0,
    -3, -3, 0, 0, 0, 0, 0, 1,
    0, 0, -3, 0, -3, -3, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, 0, 0, 0, 0, -3, -5, 0,
    0, -10, -1, -10, 6, 0, 0, -6,
    3, 6, 8, 0, -8, -1, -2, 0,
    -1, -13, 3, -1, 3, -18, 3, 0,
    0, 2, -17, 0, -18, -4, -28, -1,
    0, -16, 0, 6, 9, 0, 5, 0,
    0, 0, 0, 1, 0, -7, -5, 0,
    0, 0, 0, -3, 0, 0, 0, -3,
    0, 0, 0, 0, 0, -2, -2, 0,
    -2, -4, 0, 0, 0, 0, 0, 0,
    0, -3, -3, 0, -3, -4, -2, 0,
    0, -3, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -4, -4, 0,
    0, -1, 0, -6, 3, 0, 0, -2,
    2, 3, 3, 0, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 0, 0, 1,
    0, 0, -3, 0, -3, -1, -2, 0,
    0, 0, 0, 0, 0, 0, 2, 0,
    -3, 0, 0, 0, 0, -5, -5, 0,
    0, 10, -1, 2, -9, 0, 0, 8,
    -16, -16, -12, -6, 3, 0, -2, -21,
    -5, 0, -5, 0, -6, 5, -5, -19,
    0, -8, 0, 0, 2, -1, 4, -1,
    0, 3, 3, -10, -12, 0, -16, -6,
    -7, -6, -10, -2, -8, 1, -3, -7,
    0, 1, 0, -3, 0, 0, 0, 1,
    0, 3, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -3, 0, -2,
    0, -1, -3, 0, -6, -7, -7, -1,
    0, -10, 0, 0, 0, 0, 0, 0,
    -3, 0, 0, 0, 0, 0, -3, 0,
    0, 3, 0, 0, 0, 0, 0, 0,
    0, 0, 17, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, -3, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -7, 0, 3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -1, 0, 0, 0, -3, 0, 0, 0,
    0, -16, -10, 0, 0, 0, -5, -16,
    0, 0, -3, 3, 0, -5, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -3, 0, 0, -5, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -5, 0, 0, 0, 0, 2, 0,
    1, -6, -6, 0, -3, -3, -4, 0,
    0, 0, 0, 0, 0, -10, 0, -3,
    0, -5, -3, 0, -7, -8, -10, -2,
    0, -6, 3, -10, 0, 0, 0, 0,
    26, 0, 0, 2, 0, 0, -5, 0,
    0, -13, 0, 0, 0, 0, 0, -31,
    -7, 10, 10, -4, -14, 0, 3, -5,
    0, -16, -2, -4, 3, -22, -3, 7,
    0, 5, -11, -5, -12, -12, -14, 0,
    0, -19, 0, 17, 0, 0, -2, 0,
    0, 0, -2, -2, -3, -9, -12, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -3, 0, -2, -3, -5, 0,
    0, -6, 0, -3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 0, -6, 0, 0, 6,
    -2, 4, 0, -6, 3, -1, -1, -4,
    -3, 0, -4, -3, -3, 0, -5, -4,
    0, 0, -2, -2, -1, -4, -2, 0,
    0, -3, 0, 3, -1, 0, -6, 0,
    0, 0, -6, 0, -4, 0, -4, -4,
    0, 0, 0, 0, 0, 0, 0, 0,
    -6, 3, 0, -3, 0, -1, -2, -5,
    -1, -1, -1, -1, -1, -2, -1, 0,
    0, 0, 0, 0, -3, -2, -2, 0,
    0, 0, 0, 2, -1, 0, -1, 0,
    0, 0, -1, -2, -1, -2, -2, -2,
    4, 13, -1, 0, -7, 0, -1, 6,
    0, -3, -12, -4, 5, 2, 0, -13,
    -4, 3, -4, 3, 0, 1, -2, -9,
    0, -5, 2, 0, 0, -4, 0, 0,
    0, 3, 3, -6, -5, 0, -4, -3,
    -5, -3, -3, 0, -4, 2, -5, -4,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 3, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -4, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -5,
    0, 0, -4, 0, 0, -3, -3, 0,
    0, 0, 0, -3, 0, 0, 0, 0,
    -2, 0, 0, 0, 0, 0, -1, 0,
    0, 0, -5, 0, -6, 0, 0, 0,
    -12, 0, 1, -7, 6, 1, -1, -14,
    0, 0, -7, -3, 0, -13, -8, -10,
    0, 0, -15, -3, -13, -13, -16, 0,
    -4, 0, 4, 20, -4, 0, -7, -3,
    -1, -3, -4, -8, -5, -12, -14, -8,
    0, 0, -1, 0, 2, 0, 0, -22,
    0, 10, 5, -5, -11, 0, 2, -5,
    0, -16, -1, -3, 6, -28, -4, 2,
    0, 0, -21, -3, -16, -3, -23, 0,
    0, -22, 0, 16, 2, 0, -1, 0,
    0, 0, 0, -2, -1, -12, -1, 0,
    0, 0, 0, 0, -9, 0, -2, 0,
    -2, -9, -14, 0, 0, -2, -5, -10,
    -3, 0, -3, 0, 0, 0, 0, -14,
    -3, -10, -9, -4, -6, -8, -3, -4,
    0, -6, -2, -12, -5, 0, -4, -3,
    -3, -3, 0, 2, 0, -1, -10, 0,
    0, -5, 0, 0, 0, 0, 2, 0,
    1, -6, 16, 0, -3, -3, -4, 0,
    0, 0, 0, 0, 0, -10, 0, -3,
    0, -5, -3, 0, -7, -8, -10, -2,
    0, -6, 4, 13, 0, 0, 0, 0,
    26, 0, 0, 2, 0, 0, -5, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -1, 0, 0, 0, 0, 0, -1, -6,
    0, 0, 0, 0, 0, -2, 0, 0,
    0, -3, -3, 0, 0, -6, -3, 0,
    0, -6, 0, 4, -2, 0, 0, 0,
    0, 0, 0, 2, 0, 0, 0, 0,
    6, 4, -2, 0, -9, -3, 0, 10,
    -12, -11, -6, -6, 13, 7, 3, -27,
    -3, 6, -3, 0, -3, 6, -3, -11,
    0, -3, 3, -4, -4, -10, -4, 0,
    0, 10, 6, 0, -9, 0, -18, -4,
    14, -4, -12, 2, -4, -10, -10, -3,
    3, 0, -5, 0, -8, 0, 4, 10,
    -8, -12, -13, -8, 10, 0, 2, -24,
    -4, 3, -6, -3, -8, 0, -7, -12,
    -5, -5, -4, 0, 0, -8, -8, -3,
    0, 10, 8, -3, -18, 0, -18, -2,
    0, -11, -20, -2, -11, -6, -10, -10,
    0, 0, -4, 0, -6, -2, 0, -3,
    -7, 0, 4, -12, 3, 0, 0, -18,
    0, -3, -7, -6, -3, -10, -8, -12,
    -7, 0, -10, -3, -8, -3, -10, -3,
    0, 0, 2, 14, -6, 0, -10, -3,
    0, -3, -6, -8, -9, -11, -14, -5,
    6, 0, -5, 0, -16, -2, 3, 6,
    -11, -12, -6, -12, 12, -3, 2, -31,
    -7, 6, -7, -6, -12, 0, -10, -14,
    -2, -3, -4, -3, -8, -10, -2, 0,
    0, 10, 11, -1, -21, 0, -19, -3,
    12, -12, -23, -6, -11, -14, -16, -12,
    0, 0, 0, 0, -2, 0, 0, 3,
    -2, 6, 1, -5, 6, 0, 0, -5,
    -1, 0, -1, 0, 2, 2, -2, 0,
    0, 0, 0, 0, 0, -3, 0, 0,
    0, 0, 4, 10, 1, 0, -2, 0,
    0, 0, 0, -1, -1, -2, 0, 0,
    2, 4, 0, 0, 0, 0, 4, 0,
    -1, 0, 14, 0, 7, 2, 2, -5,
    0, 6, 0, 0, 0, 4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 10, 0, 11, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -19, 0, -3, 4, 0, 10, 0,
    0, 29, 2, -6, -6, 3, 3, -1,
    2, -16, 0, 0, 17, -19, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -23, 14, 45, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -3, 0, 0, -3, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, 0, -8, 0, 0, 2, 0,
    0, 3, 38, -6, -2, 9, 8, -8,
    3, 0, 0, 3, 3, -6, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -42, 11, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -9, 0, 0, 0, -8,
    0, 0, 0, 0, -6, -2, 0, 0,
    0, -6, 0, -2, 0, -14, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -20, 0, 0, 0, 0, 2, 0,
    0, 0, 0, 0, 0, -3, 0, 0,
    0, -5, 0, -8, 0, 0, 0, -4,
    3, -2, 0, 0, -8, -3, -7, 0,
    0, -8, 0, -3, 0, -14, 0, -6,
    0, 0, -21, -3, -13, -6, -13, 0,
    0, -20, 0, -8, -3, 0, 0, 0,
    0, 0, 0, 0, 0, -5, -5, -2,
    0, 0, 0, 0, -5, 0, -7, 5,
    -6, 6, 0, -1, -7, -1, -4, -3,
    0, -2, -2, -1, 3, -8, -2, 0,
    0, 0, -23, -4, -8, 0, -12, 0,
    -1, -14, -2, 0, 0, -1, -2, 0,
    0, 0, 0, 3, 0, -3, -4, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 12, 0, 0, 0, 0,
    0, -5, 0, -1, 0, 0, 0, -6,
    3, 0, 0, 0, -8, -3, -6, 0,
    0, -9, 0, -3, 0, -14, 0, 0,
    0, 0, -30, 0, -6, -12, -16, 0,
    0, -20, 0, -3, -5, 0, 0, 0,
    0, 0, 0, 0, 0, -3, -5, -2,
    2, 0, 0, 4, -5, 0, 13, 13,
    -3, -3, -10, 2, 13, 4, 5, -8,
    2, 12, 2, 8, 5, 8, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 20, 14, -7, -3, 0, -2, 26,
    15, 26, 0, 0, 0, 3, 0, 0,
    0, 0, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 8, 0, 0,
    0, 0, -20, -2, -4, -11, -13, 0,
    0, -20, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 8, 0, 0,
    0, 0, -20, -2, -4, -11, -13, 0,
    0, -5, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -4, 0, 0, 0,
    -8, 3, 0, -3, 4, 7, 3, -10,
    0, 1, -4, 3, 0, 4, 0, 0,
    0, 0, -3, 0, -2, -1, -6, 0,
    -2, -13, 0, 18, -3, 0, -7, -1,
    0, -1, -6, 0, -3, -10, -6, -4,
    0, 0, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 8, 0, 0,
    0, 0, -20, -2, -4, -11, -13, 0,
    0, -20, 0, 0, 0, 0, 0, 0,
    16, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -3, 0, -9, -2, -2, 10,
    -3, -3, -13, 2, 2, 2, -1, -7,
    1, 7, 1, 4, 2, 4, -6, -14,
    -2, 0, -7, -3, -8, -12, -11, 0,
    -3, -6, -2, -5, -2, -1, -3, -1,
    0, -1, -1, 5, 0, 5, -1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -1, -3, -3, 0,
    0, -8, 0, -2, 0, -4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -19, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -3, -3, 0,
    0, 0, 0, 0, -2, 0, 0, -4,
    -3, 3, 0, -4, -5, -1, 0, -6,
    -1, -5, -3, -2, 0, -4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -20, 0, 9, 0, 0, -5, 0,
    0, 0, 0, -4, 0, -3, 0, 0,
    0, 0, -1, 0, -8, 0, 0, 12,
    -5, -10, -11, 1, 6, 6, 1, -11,
    1, 5, 1, 10, 1, 12, -1, -9,
    0, 0, -5, 0, 0, -10, -8, 0,
    0, -6, 0, -5, -6, 0, -5, 0,
    -5, 0, -3, 5, 0, -4, -10, -3,
    0, 0, -2, 0, -6, 0, 0, 5,
    -8, 0, 3, -3, 4, 3, 0, -12,
    0, -1, -2, 0, -3, 6, -4, 0,
    0, 0, -7, -2, -7, 0, -10, 0,
    0, -14, 0, 11, -3, 0, -5, 0,
    8, 0, -3, 0, -3, -10, 0, -3,
    0, 0, 0, 0, -1, 0, 0, 3,
    -4, 2, 0, 0, -2, -1, 0, -2,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -18, 0, 5, 0, 0, -2, 0,
    0, 0, 0, 1, 0, -3, -3, 0
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 60,
    .right_class_cnt     = 48,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 1,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t ui_font_Font2 = {
#else
lv_font_t ui_font_Font2 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 21,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UI_FONT_FONT2*/

