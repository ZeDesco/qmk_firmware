#ifdef RGB_MATRIX_ENABLE
#include "shift.h"

#include "led_matrix.h"
#include "rgb_matrix.h"
#include "config_led.h"

// TODO: update after layout change
led_config_t g_led_config = {
  {
    {   1,   2,   3,   5,   6,   7,   8,  10,  12,  14,  15,  16,  17 },
    {  22,  23,   4,  27,  29,  30,   9,  11,  13,  18,  19,  20,  21 },
    {  40,  24,  25,  28,  46,  31,  32,  34,  35,  36,  37,  38,  39 },
    {  58,  41,  26,  44,  47,  48,  33,  51,  52,  54,  55,  56,  57 },
    {  75,  42,  43,  45,  64,  49,  50,  68,  53,  71,  72,  73,  74 },
    {  92,  59,  61,  62,  65,  66,  67,  84,  69,  87,  88,  89,  91 },
    {  93,  60,  77,  63,  80,  82,  83,  85,  70,  90, 102,  98,  99 },
    {  94,  76,  78,  79,  95,  81,  96,  97,  86, 100, 101, NO_LED, NO_LED }
  },
  {
    { 6, 5 },
    { 29, 5 },
    { 41, 5 },
    { 52, 5 },
    { 63, 5 },
    { 81, 5 },
    { 92, 5 },
    { 103, 5 },
    { 115, 5 },
    { 132, 5 },
    { 143, 5 },
    { 155, 5 },
    { 166, 5 },
    { 183, 5 },
    { 195, 5 },
    { 206, 5 },
    { 218, 5 },

    { 183, 13 },
    { 195, 13 },
    { 206, 13 },
    { 218, 13 },

    { 6, 22 },
    { 18, 22 },
    { 29, 22 },
    { 41, 22 },
    { 52, 22 },
    { 63, 22 },
    { 75, 22 },
    { 86, 22 },
    { 98, 22 },
    { 109, 22 },
    { 121, 22 },
    { 132, 22 },
    { 143, 22 },
    { 161, 22 },
    { 183, 22 },
    { 195, 22 },
    { 206, 22 },
    { 218, 22 },

    { 9, 31 },
    { 23, 31 },
    { 35, 31 },
    { 46, 31 },
    { 58, 31 },
    { 69, 31 },
    { 81, 31 },
    { 92, 31 },
    { 103, 31 },
    { 115, 31 },
    { 126, 31 },
    { 138, 31 },
    { 149, 31 },
    { 163, 31 },
    { 183, 31 },
    { 195, 31 },
    { 206, 31 },
    { 218, 31 },

    { 11, 40 },
    { 26, 40 },
    { 38, 40 },
    { 49, 40 },
    { 61, 40 },
    { 72, 40 },
    { 83, 40 },
    { 95, 40 },
    { 106, 40 },
    { 118, 40 },
    { 129, 40 },
    { 141, 40 },
    { 159, 40 },
    { 183, 40 },
    { 195, 40 },
    { 206, 40 },
    { 218, 40 },

    { 13, 48 },
    { 32, 48 },
    { 43, 48 },
    { 55, 48 },
    { 66, 48 },
    { 78, 48 },
    { 89, 48 },
    { 101, 48 },
    { 112, 48 },
    { 123, 48 },
    { 135, 48 },
    { 151, 48 },
    { 183, 48 },
    { 195, 48 },
    { 206, 48 },

    { 169, 51 }, // up
    { 218, 53 }, // numpad enter

    { 8, 57 },
    { 22, 57 },
    { 36, 57 },
    { 79, 57 },
    { 123, 57 },
    { 141, 57 },
    { 195, 57 },
    { 206, 57 },

    { 158, 59 },
    { 169, 59 },
    { 181, 59 },

    { 2, 1 },
    { 12, 0 },
    { 32, 0 },
    { 42, 0 },
    { 52, 0 },
    { 62, 0 },
    { 72, 0 },
    { 82, 0 },
    { 92, 0 },
    { 102, 0 },
    { 112, 0 },
    { 122, 0 },
    { 132, 0 },
    { 142, 0 },
    { 152, 0 },
    { 162, 0 },
    { 172, 0 },
    { 182, 0 },
    { 192, 0 },
    { 212, 0 },
    { 222, 1 },
    { 224, 9 },
    { 224, 17 },
    { 224, 24 },
    { 224, 32 },
    { 224, 40 },
    { 224, 47 },
    { 224, 55 },
    { 222, 63 },
    { 212, 64 },
    { 202, 64 },
    { 192, 64 },
    { 182, 64 },
    { 172, 64 },
    { 162, 64 },
    { 152, 64 },
    { 142, 64 },
    { 132, 64 },
    { 122, 64 },
    { 112, 64 },
    { 102, 64 },
    { 92, 64 },
    { 82, 64 },
    { 72, 64 },
    { 62, 64 },
    { 52, 64 },
    { 42, 64 },
    { 32, 64 },
    { 22, 64 },
    { 12, 64 },
    { 2, 63 },
    { 0, 55 },
    { 0, 47 },
    { 0, 40 },
    { 0, 32 },
    { 0, 24 },
    { 0, 17 },
    { 0, 9 }
  },
  {
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4,

    4, 4, 4, 4,

    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    4, 4, 4, 4,

    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4,

    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    4, 4, 4, 4,

    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    4, 4, 4,

    4, // up
    4, // numpad enter

    1, 1, 1, 4, 1, 1, 4, 4,

    4, 4, 4,

    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2
  }
};

#ifdef USB_LED_INDICATOR_ENABLE
void rgb_matrix_indicators_kb(void)
{
  led_matrix_indicators();
}
#endif // USB_LED_INDICATOR_ENABLE

#endif
