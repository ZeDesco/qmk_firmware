#include QMK_KEYBOARD_H

#include <math.h> // sqrtf, powf

#ifdef CONSOLE_ENABLE

#include <print.h>

#endif

enum ctrl_keycodes {
<<<<<<< HEAD
    L_BRI = SAFE_RANGE, //LED Brightness Increase
    L_BRD,              //LED Brightness Decrease
    L_PTN,              //LED Pattern Select Next
    L_PTP,              //LED Pattern Select Previous
    L_PSI,              //LED Pattern Speed Increase
    L_PSD,              //LED Pattern Speed Decrease
    L_T_MD,             //LED Toggle Mode
    L_T_ONF,            //LED Toggle On / Off
    L_ON,               //LED On
    L_OFF,              //LED Off
    L_T_BR,             //LED Toggle Breath Effect
    L_T_PTD,            //LED Toggle Scrolling Pattern Direction
    U_T_AGCR,           //USB Toggle Automatic GCR control
    DBG_TOG,            //DEBUG Toggle On / Off
    DBG_MTRX,           //DEBUG Toggle Matrix Prints
    DBG_KBD,            //DEBUG Toggle Keyboard Prints
    DBG_MOU,            //DEBUG Toggle Mouse Prints
    MD_BOOT,            //Restart into bootloader after hold timeout
=======
    L_BRI = SAFE_RANGE, //LED Brightness Increase                                   //Working
    L_BRD,              //LED Brightness Decrease                                   //Working
    L_PTN,              //LED Pattern Select Next                                   //Working
    L_PTP,              //LED Pattern Select Previous                               //Working
    L_PSI,              //LED Pattern Speed Increase                                //Working
    L_PSD,              //LED Pattern Speed Decrease                                //Working
    L_T_MD,             //LED Toggle Mode                                           //Working
    L_T_ONF,            //LED Toggle On / Off                                       //Broken
    L_ON,               //LED On                                                    //Broken
    L_OFF,              //LED Off                                                   //Broken
    L_T_BR,             //LED Toggle Breath Effect                                  //Working
    L_T_PTD,            //LED Toggle Scrolling Pattern Direction                    //Working
    U_T_AGCR,           //USB Toggle Automatic GCR control                          //Working
    DBG_TOG,            //DEBUG Toggle On / Off                                     //
    DBG_MTRX,           //DEBUG Toggle Matrix Prints                                //
    DBG_KBD,            //DEBUG Toggle Keyboard Prints                              //
    DBG_MOU,            //DEBUG Toggle Mouse Prints                                 //
    MD_BOOT,            //Restart into bootloader after hold timeout                //Working

>>>>>>> upstream/master

    L_SP_PR,            //LED Splash Pattern Select Previous
    L_SP_NE,            //LED Splash Pattern Select Next

    L_SP_WD,            //LED Splash Widen Wavefront width
    L_SP_NW,            //LED Splash Narrow Wavefront width

    L_SP_FA,            //LED Splash wave travel speed faster (shorter period)
    L_SP_SL,            //LED Splash wave travel speed slower (longer period)

    L_CP_PR,            //LED Color Pattern Select Previous
    L_CP_NX,            //LEB Color Pattern Select Next

    S_RESET            // reset all parameters
};

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN, \
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                              KC_UP, \
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(1),   KC_APP,  KC_RCTL,            KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            KC_MUTE, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_MPLY, KC_MSTP, KC_VOLU, \
        L_T_BR,  L_PSD,   L_BRI,   L_PSI,   _______, _______, _______, _______, U_T_AGCR,_______, MO(2),   _______, _______, _______,   KC_MPRV, KC_MNXT, KC_VOLD, \
        L_T_PTD, L_PTP,   L_BRD,   L_PTN,   _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, L_T_MD,  L_T_ONF, _______, _______, MD_BOOT, NK_TOGG, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
    [2] = LAYOUT(
        S_RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        S_RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        L_CP_NX, L_SP_SL, L_SP_WD, L_SP_FA, _______, _______, L_CP_NX, L_SP_SL, L_SP_WD, L_SP_FA, _______, _______, _______, _______,   _______, _______, _______, \
        L_CP_PR, L_SP_PR, L_SP_NW, L_SP_NE, _______, _______, L_CP_PR, L_SP_PR, L_SP_NW, L_SP_NE, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    )
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
    */
};

#define DISTANCE_NORAMLIZING_PARAMETER 3
struct {
    uint8_t PATTERN_INDEX;
    float WAVE_WIDTH;
    float WAVE_SPEED;
    int COLOR_PATTERN_INDEX;
    float TRAVEL_DISTANCE;
} USER_CONFIG = {
    .PATTERN_INDEX = 1,
    .WAVE_WIDTH = 10, // width of the wave in keycaps
    .WAVE_SPEED = 15, // travel how many keycaps per second
    .COLOR_PATTERN_INDEX = 0,
    .TRAVEL_DISTANCE = 25,
};

<<<<<<< HEAD
uint8_t ktli(uint16_t keycode){
    if(keycode < 256){
        // the array is initialized in `matrix_init_user()`
        return KEYCODE_TO_LED_ID[keycode];
    }
    switch(keycode){
    // definition of MO(layer): quantum/quantum_keycodes.h: line 614
    case MO(1): return 82;
    }
    return 0;
};

// Runs just one time when the keyboard initializes.
static void init_keycode_to_led_map(void){
    uint16_t LED_MAP[MATRIX_ROWS][MATRIX_COLS] = LAYOUT(
            1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,
            20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,
            36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,
            52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,
#if KEY_LED_COUNT >= 87
            68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87
#endif
    );

    uint16_t key = 0;
    for(uint8_t y = 0; y < MATRIX_ROWS; ++y){
        for(uint8_t x = 0; x < MATRIX_COLS; ++x){
            key = keymaps[0][y][x];
            if(key < 256){
                KEYCODE_TO_LED_ID[key] = LED_MAP[y][x];
            }
        }
    }
}
// https://docs.qmk.fm/#/feature_terminal
#define KEY_POSITION_MAP_ROWS 6
#define KEY_POSITION_MAP_COLUMNS 20
static void init_distance_map(void){
    uint16_t KEY_POSITION_MAP[KEY_POSITION_MAP_ROWS][KEY_POSITION_MAP_COLUMNS] = {
        { KC_NO,   KC_ESC,  KC_NO,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_NO,  KC_F5,  KC_F6,   KC_F7,  KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_PSCR, KC_SLCK, KC_PAUS,  },
        // { KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,  KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    },
        { KC_NO,   KC_GRV,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,   KC_0,    KC_MINS,  KC_EQL,  KC_BSPC, KC_BSPC, KC_NO,   KC_INS,  KC_HOME, KC_PGUP,  },
        { KC_NO,   KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS, KC_BSLS, KC_NO,   KC_DEL,  KC_END,  KC_PGDN,  },
        { KC_NO,   KC_CAPS, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT,  KC_ENT,  KC_ENT,  KC_ENT,  KC_NO,   KC_NO,   KC_NO,   KC_NO,    },
        { KC_NO,   KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,  KC_RSFT, KC_RSFT, KC_RSFT, KC_NO,   KC_NO,   KC_UP,   KC_NO,    },
        { KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_RALT, KC_NO,  MO(1),   KC_APP,   KC_RCTL, KC_RCTL, KC_RCTL, KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT, },
    };
    uint8_t columns = KEY_POSITION_MAP_COLUMNS;
    uint8_t rows = KEY_POSITION_MAP_ROWS;

    for(uint8_t y = 0; y < rows; ++y){
        for(uint8_t x = 0; x < columns; ++x){
            uint8_t id1 = ktli(KEY_POSITION_MAP[y][x]);

            for(uint8_t j = y; j < rows; ++j){
                for(uint8_t i = 0; i < columns; ++i){
                    uint8_t id2 = ktli(KEY_POSITION_MAP[j][i]);

                    if(id1 == id2) continue;

                    uint8_t dx = abs(i - x);
                    uint8_t dy = abs(j - y);
                    uint8_t dis = dx + dy;
                    if(i < x && j > y){
                        dis -= min(dx, dy);
                    }

                    uint8_t _dis = DISTANCE_MAP[id1][id2];
                    if(_dis && _dis <= dis) continue;
                    DISTANCE_MAP[id1][id2] = dis;
                    DISTANCE_MAP[id2][id1] = dis;
                }
            }
        }
    }
}
void matrix_init_user(void) {
    init_keycode_to_led_map();
    init_distance_map();
};

// /tmk_core/protocol/arm_atsam/led_matrix.c: line 244
float led_animation_speed;
uint8_t led_animation_direction;
uint8_t led_animation_orientation;
uint8_t led_animation_breathing;
uint8_t led_animation_breathe_cur;
uint8_t breathe_step;
uint8_t breathe_dir;
uint64_t led_next_run;

uint8_t led_animation_id;
uint8_t led_lighting_mode;

issi3733_led_t *led_cur;
uint8_t led_per_run;
float breathe_mult;

// overrided /tmk_core/protocol/arm_atsam/led_matrix.c: line 484
void rgb_matrix_init_user(void){
    led_animation_speed = ANIMATION_SPEED_STEP * 15;
    led_per_run = 15;
}

// overrided /tmk_core/protocol/arm_atsam/led_matrix.c: line 262
void led_matrix_run(void)
{
    float ro;
    float go;
    float bo;
    float po;
    uint8_t led_this_run = 0;
    led_setup_t *f = (led_setup_t*)led_setups[led_animation_id];

    if (led_cur == 0) //Denotes start of new processing cycle in the case of chunked processing
    {
        led_cur = led_map;

        breathe_mult = 1;

        if (led_animation_breathing)
        {
            led_animation_breathe_cur += breathe_step * breathe_dir;

            if (led_animation_breathe_cur >= BREATHE_MAX_STEP)
                breathe_dir = -1;
            else if (led_animation_breathe_cur <= BREATHE_MIN_STEP)
                breathe_dir = 1;

            //Brightness curve created for 256 steps, 0 - ~98%
            breathe_mult = 0.000015 * led_animation_breathe_cur * led_animation_breathe_cur;
            if (breathe_mult > 1) breathe_mult = 1;
            else if (breathe_mult < 0) breathe_mult = 0;
        }
    }

    uint8_t fcur = 0;
    uint8_t fmax = 0;

    //Frames setup
    while (f[fcur].end != 1)
    {
        fcur++; //Count frames
    }

    fmax = fcur; //Store total frames count

    struct user_led_t user_led_cur;
    while (led_cur < lede && led_this_run < led_per_run)
    {
        ro = 0;
        go = 0;
        bo = 0;

        uint8_t led_index = led_cur - led_map;                  // only this part differs from the original function.
        if(led_index < KEY_LED_COUNT){                          //
            user_led_cur = USER_LED[led_index];                 // `struct user_led_t USER_LED[]` is stored globally.
        }                                                       //
                                                                //
        if(led_index < KEY_LED_COUNT && user_led_cur.state){    // `user_led_cur` is just for convenience
            ro = user_led_cur.r;                                //
            go = user_led_cur.g;                                //
            bo = user_led_cur.b;                                //
        }                                                       //
        else if (led_lighting_mode == LED_MODE_KEYS_ONLY && led_cur->scan == 255)
        {
            //Do not act on this LED
        }
        else if (led_lighting_mode == LED_MODE_NON_KEYS_ONLY && led_cur->scan != 255)
        {
            //Do not act on this LED
        }
        else if (led_lighting_mode == LED_MODE_INDICATORS_ONLY)
        {
            //Do not act on this LED (Only show indicators)
        }
        else
        {
            //Act on LED
            for (fcur = 0; fcur < fmax; fcur++)
            {

                if (led_animation_orientation)
                {
                  po = led_cur->py;
                }
                else
                {
                  po = led_cur->px;
                }

                float pomod;
                pomod = (float)(led_matrix_get_tick() % (uint32_t)(1000.0f / led_animation_speed)) / 10.0f * led_animation_speed;

                //Add in any moving effects
                if ((!led_animation_direction && f[fcur].ef & EF_SCR_R) || (led_animation_direction && (f[fcur].ef & EF_SCR_L)))
                {
                    pomod *= 100.0f;
                    pomod = (uint32_t)pomod % 10000;
                    pomod /= 100.0f;

                    po -= pomod;

                    if (po > 100) po -= 100;
                    else if (po < 0) po += 100;
                }
                else if ((!led_animation_direction && f[fcur].ef & EF_SCR_L) || (led_animation_direction && (f[fcur].ef & EF_SCR_R)))
                {
                    pomod *= 100.0f;
                    pomod = (uint32_t)pomod % 10000;
                    pomod /= 100.0f;
                    po += pomod;

                    if (po > 100) po -= 100;
                    else if (po < 0) po += 100;
                }

                //Check if LED's po is in current frame
                if (po < f[fcur].hs) continue;
                if (po > f[fcur].he) continue;
                //note: < 0 or > 100 continue

                //Calculate the po within the start-stop percentage for color blending
                po = (po - f[fcur].hs) / (f[fcur].he - f[fcur].hs);

                //Add in any color effects
                if (f[fcur].ef & EF_OVER)
                {
                    ro = (po * (f[fcur].re - f[fcur].rs)) + f[fcur].rs;// + 0.5;
                    go = (po * (f[fcur].ge - f[fcur].gs)) + f[fcur].gs;// + 0.5;
                    bo = (po * (f[fcur].be - f[fcur].bs)) + f[fcur].bs;// + 0.5;
                }
                else if (f[fcur].ef & EF_SUBTRACT)
                {
                    ro -= (po * (f[fcur].re - f[fcur].rs)) + f[fcur].rs;// + 0.5;
                    go -= (po * (f[fcur].ge - f[fcur].gs)) + f[fcur].gs;// + 0.5;
                    bo -= (po * (f[fcur].be - f[fcur].bs)) + f[fcur].bs;// + 0.5;
                }
                else
                {
                    ro += (po * (f[fcur].re - f[fcur].rs)) + f[fcur].rs;// + 0.5;
                    go += (po * (f[fcur].ge - f[fcur].gs)) + f[fcur].gs;// + 0.5;
                    bo += (po * (f[fcur].be - f[fcur].bs)) + f[fcur].bs;// + 0.5;
                }
            }
        }

        //Clamp values 0-255
        if (ro > 255) ro = 255; else if (ro < 0) ro = 0;
        if (go > 255) go = 255; else if (go < 0) go = 0;
        if (bo > 255) bo = 255; else if (bo < 0) bo = 0;

        if (led_animation_breathing)
        {
            ro *= breathe_mult;
            go *= breathe_mult;
            bo *= breathe_mult;
        }

        *led_cur->rgb.r = (uint8_t)ro;
        *led_cur->rgb.g = (uint8_t)go;
        *led_cur->rgb.b = (uint8_t)bo;

#ifdef USB_LED_INDICATOR_ENABLE
        if (keyboard_leds())
        {
            uint8_t kbled = keyboard_leds();
            if (
                #if USB_LED_NUM_LOCK_SCANCODE != 255
                (led_cur->scan == USB_LED_NUM_LOCK_SCANCODE && kbled & (1<<USB_LED_NUM_LOCK)) ||
                #endif //NUM LOCK
                #if USB_LED_CAPS_LOCK_SCANCODE != 255
                (led_cur->scan == USB_LED_CAPS_LOCK_SCANCODE && kbled & (1<<USB_LED_CAPS_LOCK)) ||
                #endif //CAPS LOCK
                #if USB_LED_SCROLL_LOCK_SCANCODE != 255
                (led_cur->scan == USB_LED_SCROLL_LOCK_SCANCODE && kbled & (1<<USB_LED_SCROLL_LOCK)) ||
                #endif //SCROLL LOCK
                #if USB_LED_COMPOSE_SCANCODE != 255
                (led_cur->scan == USB_LED_COMPOSE_SCANCODE && kbled & (1<<USB_LED_COMPOSE)) ||
                #endif //COMPOSE
                #if USB_LED_KANA_SCANCODE != 255
                (led_cur->scan == USB_LED_KANA_SCANCODE && kbled & (1<<USB_LED_KANA)) ||
                #endif //KANA
                (0))
            {
                if (*led_cur->rgb.r > 127) *led_cur->rgb.r = 0;
                else *led_cur->rgb.r = 255;
                if (*led_cur->rgb.g > 127) *led_cur->rgb.g = 0;
                else *led_cur->rgb.g = 255;
                if (*led_cur->rgb.b > 127) *led_cur->rgb.b = 0;
                else *led_cur->rgb.b = 255;
            }
        }
#endif //USB_LED_INDICATOR_ENABLE

        led_cur++;
        led_this_run++;
    }
}

#define KEY_STROKES_LENGTH 20
struct {
    bool alive;
    uint8_t led_id;
    uint32_t time;
} KEY_STROKES[KEY_STROKES_LENGTH] = {{}};




void set_led_rgb(uint8_t led_id, uint8_t r, uint8_t g, uint8_t b){
    issi3733_led_t *target_led = (led_map + led_id);
    *target_led->rgb.r = r;
    *target_led->rgb.g = g;
    *target_led->rgb.b = b;
}


uint8_t DISTANCE_FROM_LAST_KEYSTROKE[KEY_LED_COUNT+1];
void calculate_keystroke_distance(void){
    bool alive;
    uint8_t led_id, period_passed;
    uint32_t t;


    for(uint8_t i = 0; i <= KEY_LED_COUNT; ++i){
        DISTANCE_FROM_LAST_KEYSTROKE[i] = 0;
    }

    for(uint8_t i = 0; i < KEY_STROKES_LENGTH; ++i){
        if(KEY_STROKES[i].alive){
            t = timer_elapsed32(KEY_STROKES[i].time);
            alive = 0;
            led_id = KEY_STROKES[i].led_id;
            period_passed = t / USER_CONFIG.WAVE_PERIOD;

            uint8_t delta_period;
            for(uint8_t j = 1; j <= KEY_LED_COUNT; ++j){
                delta_period = period_passed - DISTANCE_MAP[led_id][j];
                if(( delta_period < USER_CONFIG.WAVE_FRONT_WIDTH) && (
                    DISTANCE_MAP[led_id][j] <= USER_CONFIG.TRAVEL_DISTANCE
                )){
                    switch(USER_CONFIG.PATTERN_INDEX){
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                        DISTANCE_FROM_LAST_KEYSTROKE[j] += delta_period;
                        break;
                    default:
                        DISTANCE_FROM_LAST_KEYSTROKE[j] = 1;
                        break;
                    }
                    alive = 1;
                }
            }
            KEY_STROKES[i].alive = alive;
        }
    }
}
=======
>>>>>>> upstream/master

#define COLOR_PATTERN_RGB_COUNT 18
static uint8_t COLOR_PATTERNS[][COLOR_PATTERN_RGB_COUNT][3] = {
    { // default rainbow color
        {255,   0,   0}, {255,   0,   0}, {255, 127,   0},
        {255, 127,   0}, {255, 255,   0}, {255, 255,   0},
        {120, 255,   0}, {120, 255,   0}, {  0, 255,   0},
        {  0, 255,   0}, {  0, 255, 120}, {  0, 255, 120},
        {  0,   0, 255}, {  0,   0, 255}, { 75,   0, 130},
        { 75,   0, 130}, { 43,   0, 130}, { 43,   0, 130},
    }, { // light rainbow color
        {248,  12,  18}, {238,  17,   0}, {255,  51,  17},
        {255,  68,  32}, {255, 102,  68}, {255, 153,  51},
        {254, 174,  45}, {204, 187,  51}, {208, 195,  16},
        {170, 204,  34}, {105, 208,  37}, { 34, 204, 170},
        { 18, 189, 185}, { 17, 170, 187}, { 68,  68, 221},
        { 51,  17, 187}, { 59,  12, 189}, { 68,  34, 153},
    }, { // white flat
        {255, 255, 255}, {255, 255, 255}, {255, 255, 255},
        {255, 255, 255}, {255, 255, 255}, {255, 255, 255},
        {255, 255, 255}, {255, 255, 255}, {255, 255, 255},
        {255, 255, 255}, {255, 255, 255}, {255, 255, 255},
        {255, 255, 255}, {255, 255, 255}, {255, 255, 255},
        {255, 255, 255}, {255, 255, 255}, {255, 255, 255},
    }, { // white fade, cos curve
        {255, 255, 255}, {255, 255, 255}, {252, 252, 252},
        {247, 247, 247}, {240, 240, 240}, {232, 232, 232},
        {221, 221, 221}, {209, 209, 209}, {196, 196, 196},
        {181, 181, 181}, {164, 164, 164}, {147, 147, 147},
        {128, 128, 128}, {108, 108, 108}, { 88,  88,  88},
        { 66,  66,  66}, { 45,  45,  45}, { 23,  23,  23},
    },
};
static const uint8_t COLOR_PATTERNS_COUNT = (
        sizeof(COLOR_PATTERNS) / sizeof(COLOR_PATTERNS[0]));

/**
 * trimed down version of `ISSI3733_LED_MAP`:
 *
 * `ISSI3733_LED_MAP` is defined in keyboards/massdrop/ctrl/config_led.h is not directly usable,
 * the numbers inside this map could probably be related to the PCB layout instead of
 * the actual physical layout,
 *
 * this `ISSI3733_LED_MAP` is used somewhere in protocol/ but is not globally accessible
 * so one is created here
 *
 * x and y are coordinates of the physical layout
 * KC_ESC is (0, 0), gap between function keys and number rows is 1.5
 * +y is downwards
 * 1 unit is width/height of 1 standard keycap
 */
#define MAX_LED_ID ISSI3733_LED_COUNT
typedef struct led_info_s {
    uint16_t id;
    uint16_t scan;
    float x;
    float y;
    uint8_t distance_to[MAX_LED_ID + 1];
} led_info_t;
led_info_t led_info[MAX_LED_ID + 1] = {
 { .id = 0 },
 { .id = 1,     .x = 0.0,       .y = 0.0,   .scan = 41  }, // ESC
 { .id = 2,     .x = 2.0,       .y = 0.0,   .scan = 58  }, // F1
 { .id = 3,     .x = 3.0,       .y = 0.0,   .scan = 59  }, // F2
 { .id = 4,     .x = 3.5,       .y = 0.0,   .scan = 60  }, // F3
 { .id = 5,     .x = 5.0,       .y = 0.0,   .scan = 61  }, // F4
 { .id = 6,     .x = 6.5,       .y = 0.0,   .scan = 62  }, // F5
 { .id = 7,     .x = 7.5,       .y = 0.0,   .scan = 63  }, // F6
 { .id = 8,     .x = 8.5,       .y = 0.0,   .scan = 64  }, // F7
 { .id = 9,     .x = 9.5,       .y = 0.0,   .scan = 65  }, // F8
 { .id = 10,    .x = 11,        .y = 0.0,   .scan = 66  }, // F9
 { .id = 11,    .x = 12,        .y = 0.0,   .scan = 67  }, // F10
 { .id = 12,    .x = 13,        .y = 0.0,   .scan = 68  }, // F11
 { .id = 13,    .x = 14,        .y = 0.0,   .scan = 69  }, // F12
 { .id = 14,    .x = 15.5,      .y = 0.0,   .scan = 70  }, // Print
 { .id = 15,    .x = 16.5,      .y = 0.0,   .scan = 71  }, // Scoll Lock
 { .id = 16,    .x = 17.5,      .y = 0.0,   .scan = 72  }, // Pause
 { .id = 17,    .x = 0.0,       .y = 1.5,   .scan = 53  }, // `
 { .id = 18,    .x = 1.0,       .y = 1.5,   .scan = 30  }, // 1
 { .id = 19,    .x = 2.0,       .y = 1.5,   .scan = 31  }, // 2
 { .id = 20,    .x = 3.0,       .y = 1.5,   .scan = 32  }, // 3
 { .id = 21,    .x = 3.5,       .y = 1.5,   .scan = 33  }, // 4
 { .id = 22,    .x = 5.0,       .y = 1.5,   .scan = 34  }, // 5
 { .id = 23,    .x = 6.0,       .y = 1.5,   .scan = 35  }, // 6
 { .id = 24,    .x = 7.0,       .y = 1.5,   .scan = 36  }, // 7
 { .id = 25,    .x = 8.0,       .y = 1.5,   .scan = 37  }, // 8
 { .id = 26,    .x = 9.0,       .y = 1.5,   .scan = 38  }, // 9
 { .id = 27,    .x = 10.0,      .y = 1.5,   .scan = 39  }, // 0
 { .id = 28,    .x = 11.0,      .y = 1.5,   .scan = 45  }, // -
 { .id = 29,    .x = 12.0,      .y = 1.5,   .scan = 46  }, // =
 { .id = 30,    .x = 13.5,      .y = 1.5,   .scan = 42  }, // Backspace
 { .id = 31,    .x = 15.5,      .y = 1.5,   .scan = 73  }, // Insert
 { .id = 32,    .x = 16.6,      .y = 1.5,   .scan = 74  }, // Home
 { .id = 33,    .x = 17.5,      .y = 1.5,   .scan = 75  }, // Page Up
 { .id = 34,    .x = 0.2,       .y = 2.5,   .scan = 43  }, // Tab
 { .id = 35,    .x = 1.5,       .y = 2.5,   .scan = 20  }, // Q
 { .id = 36,    .x = 2.5,       .y = 2.5,   .scan = 26  }, // W
 { .id = 37,    .x = 3.5,       .y = 2.5,   .scan = 8   }, // E
 { .id = 38,    .x = 4.5,       .y = 2.5,   .scan = 21  }, // R
 { .id = 39,    .x = 5.5,       .y = 2.5,   .scan = 23  }, // T
 { .id = 40,    .x = 6.5,       .y = 2.5,   .scan = 28  }, // Y
 { .id = 41,    .x = 7.5,       .y = 2.5,   .scan = 24  }, // U
 { .id = 42,    .x = 8.5,       .y = 2.5,   .scan = 12  }, // I
 { .id = 43,    .x = 9.5,       .y = 2.5,   .scan = 18  }, // O
 { .id = 44,    .x = 10.5,      .y = 2.5,   .scan = 19  }, // P
 { .id = 45,    .x = 11.5,      .y = 2.5,   .scan = 47  }, // [
 { .id = 46,    .x = 12.5,      .y = 2.5,   .scan = 48  }, // ]
 { .id = 47,    .x = 13.75,     .y = 2.5,   .scan = 49  }, /* \ */
 { .id = 48,    .x = 15.5,      .y = 2.5,   .scan = 76  }, // Delete
 { .id = 49,    .x = 16.5,      .y = 2.5,   .scan = 77  }, // End
 { .id = 50,    .x = 17.5,      .y = 2.5,   .scan = 78  }, // Page Down
 { .id = 51,    .x = 0.4,       .y = 3.5,   .scan = 57  }, // Caps Lock
 { .id = 52,    .x = 2.5,       .y = 3.5,   .scan = 4   }, // A
 { .id = 53,    .x = 3.5,       .y = 3.5,   .scan = 22  }, // S
 { .id = 54,    .x = 4.5,       .y = 3.5,   .scan = 7   }, // D
 { .id = 55,    .x = 5.5,       .y = 3.5,   .scan = 9   }, // F
 { .id = 56,    .x = 6.5,       .y = 3.5,   .scan = 10  }, // G
 { .id = 57,    .x = 7.5,       .y = 3.5,   .scan = 11  }, // H
 { .id = 58,    .x = 8.5,       .y = 3.5,   .scan = 13  }, // J
 { .id = 59,    .x = 9.5,       .y = 3.5,   .scan = 14  }, // K
 { .id = 60,    .x = 10.5,      .y = 3.5,   .scan = 15  }, // L
 { .id = 61,    .x = 11.5,      .y = 3.5,   .scan = 51  }, // ;
 { .id = 62,    .x = 12.5,      .y = 3.5,   .scan = 52  }, // '
 { .id = 63,    .x = 13.5,      .y = 3.5,   .scan = 40  }, // Enter
 { .id = 64,    .x = 0.5,       .y = 4.5,   .scan = 225 }, // LSHIFT
 { .id = 65,    .x = 2.25,      .y = 4.5,   .scan = 29  }, // Z
 { .id = 66,    .x = 3.25,      .y = 4.5,   .scan = 27  }, // X
 { .id = 67,    .x = 4.25,      .y = 4.5,   .scan = 6   }, // C
 { .id = 68,    .x = 5.25,      .y = 4.5,   .scan = 25  }, // V
 { .id = 69,    .x = 6.25,      .y = 4.5,   .scan = 5   }, // B
 { .id = 70,    .x = 7.25,      .y = 4.5,   .scan = 17  }, // N
 { .id = 71,    .x = 8.25,      .y = 4.5,   .scan = 16  }, // M
 { .id = 72,    .x = 9.25,      .y = 4.5,   .scan = 54  }, // COMMA
 { .id = 73,    .x = 10.25,     .y = 4.5,   .scan = 55  }, // DOT
 { .id = 74,    .x = 11.25,     .y = 4.5,   .scan = 56  }, // SLASH
 { .id = 75,    .x = 13.2,      .y = 4.5,   .scan = 229 }, // RSHIFT
 { .id = 76,    .x = 16.5,      .y = 4.5,   .scan = 82  }, // UP
 { .id = 77,    .x = 0.1,       .y = 5.5,   .scan = 224 }, // LCTRL
 { .id = 78,    .x = 1.25,      .y = 5.5,   .scan = 227 }, // WIN
 { .id = 79,    .x = 2.5,       .y = 5.5,   .scan = 226 }, // LALT
 { .id = 80,    .x = 6.25,      .y = 5.5,   .scan = 44  }, // SPACE

#define MAX_CACHED_SCAN_CODE 231
 { .id = 81,    .x = 10.25,     .y = 5.5,   .scan = 230 }, // RALT

#define FN_KEY_LED_ID 82
#define FN_KEY_SCAN_CODE 20737
 { .id = 82,    .x = 11.5,      .y = 5.5,   .scan = 20737 }, // FN
 { .id = 83,    .x = 12.7,      .y = 5.5,   .scan = 101 }, // APP
 { .id = 84,    .x = 13.75,     .y = 5.5,   .scan = 228 }, // RCTRL
 { .id = 85,    .x = 15.5,      .y = 5.5,   .scan = 80  }, // LEFT
 { .id = 86,    .x = 16.5,      .y = 5.5,   .scan = 81  }, // DOWN
 { .id = 87,    .x = 17.5,      .y = 5.5,   .scan = 79  }, // RIGHT

#define MAX_LED_ID_WITH_SCANCODE 87

 { .id = 88,    .x = 18.5,      .y = 6.5,   .scan = 255 },
 { .id = 89,    .x = 16.917,    .y = 6.5,   .scan = 255 },
 { .id = 90,    .x = 15.333,    .y = 6.5,   .scan = 255 },
 { .id = 91,    .x = 13.75,     .y = 6.5,   .scan = 255 },
 { .id = 92,    .x = 12.167,    .y = 6.5,   .scan = 255 },
 { .id = 93,    .x = 10.583,    .y = 6.5,   .scan = 255 },
 { .id = 94,    .x = 9,         .y = 6.5,   .scan = 255 },
 { .id = 95,    .x = 7.417,     .y = 6.5,   .scan = 255 },
 { .id = 96,    .x = 5.833,     .y = 6.5,   .scan = 255 },
 { .id = 97,    .x = 4.25,      .y = 6.5,   .scan = 255 },
 { .id = 98,    .x = 2.667,     .y = 6.5,   .scan = 255 },
 { .id = 99,    .x = 1.083,     .y = 6.5,   .scan = 255 },
 { .id = 100,   .x = -0.5,      .y = 6.5,   .scan = 255 },
 { .id = 101,   .x = -0.5,      .y = 4.75,  .scan = 255 },
 { .id = 102,   .x = -0.5,      .y = 3,     .scan = 255 },
 { .id = 103,   .x = -0.5,      .y = 1.25,  .scan = 255 },
 { .id = 104,   .x = -0.5,      .y = -0.5,  .scan = 255 },
 { .id = 105,   .x = 1.083,     .y = -0.5,  .scan = 255 },
 { .id = 106,   .x = 2.667,     .y = -0.5,  .scan = 255 },
 { .id = 107,   .x = 4.25,      .y = -0.5,  .scan = 255 },
 { .id = 108,   .x = 5.833,     .y = -0.5,  .scan = 255 },
 { .id = 109,   .x = 7.417,     .y = -0.5,  .scan = 255 },
 { .id = 110,   .x = 9,         .y = -0.5,  .scan = 255 },
 { .id = 111,   .x = 10.583,    .y = -0.5,  .scan = 255 },
 { .id = 112,   .x = 12.167,    .y = -0.5,  .scan = 255 },
 { .id = 113,   .x = 13.75,     .y = -0.5,  .scan = 255 },
 { .id = 114,   .x = 15.333,    .y = -0.5,  .scan = 255 },
 { .id = 115,   .x = 16.917,    .y = -0.5,  .scan = 255 },
 { .id = 116,   .x = 18.5,      .y = 1.25,  .scan = 255 },
 { .id = 117,   .x = 18.5,      .y = 3,     .scan = 255 },
 { .id = 118,   .x = 18.5,      .y = 4.75,  .scan = 255 },
 { .id = 119,   .x = 18.5,      .y = 6.5,   .scan = 255 },
};

/**
 * there are a few variables are used here
 * keycode, scancode, led id
 *
 * scancode relates to actual physical key press
 *
 * keycode is software key press, or scancode with modifiers (shift, ctrl, alt, etc.),
 * keycode with the value less than 255 are usually the same with scan code (I hope so)
 *
 * the led pattern are running based on led id, because led on the keyboard
 * are not limited to keys only
 */
led_info_t* get_led_info_by_scancode(uint16_t scancode){
    static bool init = false;
    static led_info_t* scancode_to_led_info[MAX_CACHED_SCAN_CODE + 1];
    if(!init){
        for(int i = 1; i <= MAX_LED_ID_WITH_SCANCODE; ++i){
            uint16_t scan = led_info[i].scan;
            if(scan <= MAX_CACHED_SCAN_CODE){
                scancode_to_led_info[scan] = (led_info + i);
            }
        }
        init = true;
    }

    if(scancode <= MAX_CACHED_SCAN_CODE){
        return scancode_to_led_info[scancode];
    } else if(scancode == FN_KEY_SCAN_CODE){ // FN
        return (led_info + FN_KEY_LED_ID);
    }
    return led_info;
}



void init_led_info(void){
    for(int i = 1; i <= MAX_LED_ID; ++i){
        led_info_t *entry1 = led_info + i;
        for(int j = i; j <= MAX_LED_ID; ++j){
            led_info_t *entry2 = led_info + j;
            /**
             * distance is tripled because
             * convertion from float to int reduces accuracy
             *
             */
            uint8_t distance = (uint8_t)sqrtf(
                    powf(entry1->x - entry2->x, 2.0) +
                    powf(entry1->y - entry2->y, 2.0)) *
                    DISTANCE_NORAMLIZING_PARAMETER;
            entry1->distance_to[j] = distance;
            entry2->distance_to[i] = distance;
        }
    }
};


// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    init_led_info();
};

typedef struct keystroke_s {
    uint16_t scancode;
    uint32_t timer;
    bool active;
} keystroke_t;

#define MAX_ACTIVE_KEYSTORKES 10
keystroke_t ACTIVE_KEYSTROKES[MAX_ACTIVE_KEYSTORKES];

void reset_led_for_instruction(int led_instruction_index){
    led_instructions[led_instruction_index].id0 = 0;
    led_instructions[led_instruction_index].id1 = 0;
    led_instructions[led_instruction_index].id2 = 0;
    led_instructions[led_instruction_index].id3 = 0;
};
void add_led_to_instruction(int led_instruction_index, int led_id){
    if(32 >= led_id && led_id >= 1){
        led_instructions[led_instruction_index].id0 += ( 1 << (led_id - 1) );
    } else if(64 >= led_id){
        led_instructions[led_instruction_index].id1 += ( 1 << (led_id - 33) );
    } else if(96 >= led_id){
        led_instructions[led_instruction_index].id2 += ( 1 << (led_id - 65) );
    } else if(128 >= led_id){
        led_instructions[led_instruction_index].id3 += ( 1 << (led_id - 97) );
    }
};


void wave_effect(void);
void set_wave_color(int);
// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    wave_effect();
    set_wave_color(USER_CONFIG.PATTERN_INDEX);
};


#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

void register_keystroke(uint16_t keycode){
    if(get_led_info_by_scancode(keycode)->id){
        uint32_t oldest_keystroke_lifespan = 0;
        int8_t oldest_keystroke_index = -1;
        bool registered = false;

        keystroke_t *keystroke = ACTIVE_KEYSTROKES;
        for(int i = 0; i < MAX_ACTIVE_KEYSTORKES; ++i){
            if(!keystroke->active){
                keystroke->scancode = keycode;
                keystroke->timer = timer_read32();
                keystroke->active = true;
                registered = true;
                break;
            }

            uint32_t lifespan = timer_elapsed32(keystroke->timer);
            if(lifespan > oldest_keystroke_lifespan){
                oldest_keystroke_index = i;
                oldest_keystroke_lifespan = lifespan;
            }

            ++keystroke;
        }

        // override the oldest keystroke
        if(!registered){
            keystroke = ACTIVE_KEYSTROKES + oldest_keystroke_index;
            keystroke->scancode = keycode;
            keystroke->timer = timer_read32();
            keystroke->active = true; // presumably active already
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case L_BRI:
            if (record->event.pressed) {
                if (LED_GCR_STEP > LED_GCR_MAX - gcr_desired) gcr_desired = LED_GCR_MAX;
                else gcr_desired += LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_BRD:
            if (record->event.pressed) {
                if (LED_GCR_STEP > gcr_desired) gcr_desired = 0;
                else gcr_desired -= LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_PTN:
            if (record->event.pressed) {
                if (led_animation_id == led_setups_count - 1) led_animation_id = 0;
                else led_animation_id++;
            }
            return false;
        case L_PTP:
            if (record->event.pressed) {
                if (led_animation_id == 0) led_animation_id = led_setups_count - 1;
                else led_animation_id--;
            }
            return false;
        case L_PSI:
            if (record->event.pressed) {
                led_animation_speed += ANIMATION_SPEED_STEP;
            }
            return false;
        case L_PSD:
            if (record->event.pressed) {
                led_animation_speed -= ANIMATION_SPEED_STEP;
                if (led_animation_speed < 0) led_animation_speed = 0;
            }
            return false;
        case L_T_MD:
            if (record->event.pressed) {
                led_lighting_mode++;
                if (led_lighting_mode > LED_MODE_MAX_INDEX) led_lighting_mode = LED_MODE_NORMAL;
            }
            return false;
        case L_T_ONF:
            if (record->event.pressed) {
                I2C3733_Control_Set(!I2C3733_Control_Get());
            }
            return false;
        case L_ON:
            if (record->event.pressed) {
                I2C3733_Control_Set(1);
            }
            return false;
        case L_OFF:
            if (record->event.pressed) {
                I2C3733_Control_Set(0);
            }
            return false;
        case L_T_BR:
            if (record->event.pressed) {
                led_animation_breathing = !led_animation_breathing;
                if (led_animation_breathing) {
                    gcr_breathe = gcr_desired;
                    led_animation_breathe_cur = BREATHE_MIN_STEP;
                    breathe_dir = 1;
                }
            }
            return false;
        case L_T_PTD:
            if (record->event.pressed) {
                led_animation_direction = !led_animation_direction;
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;



        case S_RESET:
            // reset all parameters

            USER_CONFIG.PATTERN_INDEX = 1;
            USER_CONFIG.WAVE_WIDTH = 10;
            USER_CONFIG.WAVE_SPEED = 15;
            USER_CONFIG.COLOR_PATTERN_INDEX = 0;
            USER_CONFIG.TRAVEL_DISTANCE = 25;

            return false;
        case L_SP_PR: // previous dripple pattern
        case L_SP_NE: // next dripple pattern
            if (record->event.pressed) {
#define PATTERN_COUNT 7
                uint8_t incre = keycode == L_SP_PR ? PATTERN_COUNT-1 : 1;
                USER_CONFIG.PATTERN_INDEX += incre;
                USER_CONFIG.PATTERN_INDEX %= PATTERN_COUNT;

                if(USER_CONFIG.PATTERN_INDEX <= 4){
                    USER_CONFIG.TRAVEL_DISTANCE = 25;
                    USER_CONFIG.COLOR_PATTERN_INDEX = 0;
                    USER_CONFIG.WAVE_SPEED = 10;
                }

                switch(USER_CONFIG.PATTERN_INDEX){
                case 0: // None
                    break;
                case 1: // background off, wave on
                    USER_CONFIG.WAVE_WIDTH = 2;
                    break;
                case 2: // background on, wave off
                    USER_CONFIG.WAVE_WIDTH = 5;
                    break;
                case 3: // background off, rainbow wave
                    USER_CONFIG.WAVE_WIDTH = 10;
                    break;
                case 4: // background on, rainbow wave
                    USER_CONFIG.WAVE_WIDTH = 10;
                    break;
                case 5:
                    USER_CONFIG.WAVE_WIDTH = 10;

                    USER_CONFIG.COLOR_PATTERN_INDEX = 2;
                    USER_CONFIG.TRAVEL_DISTANCE = 0;
                    USER_CONFIG.WAVE_SPEED = 10;
                    break;
                case 6:
                    USER_CONFIG.WAVE_WIDTH = 10;

                    USER_CONFIG.COLOR_PATTERN_INDEX = 3;
                    USER_CONFIG.TRAVEL_DISTANCE = 2;
                    USER_CONFIG.WAVE_SPEED = 10;
                    break;
                }

                // remove effect after changing pattern
                for(int i = 0; i < MAX_ACTIVE_KEYSTORKES; ++i){
                    ACTIVE_KEYSTROKES[i].active = 0;
                }
            }
            return false;
        case L_SP_WD:
        case L_SP_NW:
            if(record->event.pressed){
                short incre = keycode == L_SP_WD ? 1 : -1;
                USER_CONFIG.WAVE_WIDTH += incre;
                if(USER_CONFIG.WAVE_WIDTH < 1){
                    USER_CONFIG.WAVE_WIDTH = 1;
                }
            }
            return false;
        case L_SP_FA:
        case L_SP_SL:
            if(record->event.pressed){
                short incre = keycode == L_SP_FA ? -1 : 1;

                USER_CONFIG.WAVE_SPEED += incre;
                if(USER_CONFIG.WAVE_SPEED > 50){
                    USER_CONFIG.WAVE_SPEED = 50;
                } else if(USER_CONFIG.WAVE_SPEED < 1){
                    USER_CONFIG.WAVE_SPEED = 1;
                }
            }
            return false;
        // these are the keys not in range 0x04 - 0x52
        case L_CP_PR:
        case L_CP_NX:
            if(record->event.pressed){
                uint8_t incre = keycode == L_CP_PR ? COLOR_PATTERNS_COUNT - 1 : 1;
                USER_CONFIG.COLOR_PATTERN_INDEX += incre;
                USER_CONFIG.COLOR_PATTERN_INDEX %= COLOR_PATTERNS_COUNT;
                set_wave_color(USER_CONFIG.COLOR_PATTERN_INDEX);
            }
            return false;

        default:


            if(record->event.pressed){
                register_keystroke(keycode);

#ifdef CONSOLE_ENABLE
                led_info_t *entry = get_led_info_by_scancode(keycode);
                uprintf(("KL: kc: %u, led id: %u, x: %f, y: %f, "
                        "col: %u, row: %u, pressed: %u, time: %u\n"),
                        keycode, entry->id, entry->x, entry->y,
                        record->event.key.col, record->event.key.row,
                        record->event.pressed, record->event.time);
#endif
            }
            return true; //Process all other keycodes normally
    }
}

led_instruction_t led_instructions[] = {
    //LEDs are normally inactive, no processing is performed on them
    //Flags are used in matching criteria for an LED to be active and indicate how to color it
    //Flags can be found in tmk_core/protocol/arm_atsam/led_matrix.h (prefixed with LED_FLAG_)
    //LED IDs can be found in config_led.h in the keyboard's directory
    //Examples are below

    //All LEDs use the user's selected pattern (this is the factory default)
    { .flags = LED_FLAG_USE_ROTATE_PATTERN },

    //Specific LEDs use the user's selected pattern while all others are off
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id0 = 0xFFFFFFFF, .id1 = 0xAAAAAAAA, .id2 = 0x55555555, .id3 = 0x11111111 },

    //Specific LEDs use specified RGB values while all others are off
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0xFF, .id1 = 0x00FF, .id2 = 0x0000FF00, .id3 = 0xFF000000, .r = 75, .g = 150, .b = 225 },

    //All LEDs use the user's selected pattern
    //On layer 1, all key LEDs (except the top row which keeps active pattern) are red while all edge LEDs are green
    //When layer 1 is active, key LEDs use red    (id0  32 -  17: 1111 1111 1111 1111 0000 0000 0000 0000 = 0xFFFF0000) (except top row 16 - 1)
    //When layer 1 is active, key LEDs use red    (id1  64 -  33: 1111 1111 1111 1111 1111 1111 1111 1111 = 0xFFFFFFFF)
    //When layer 1 is active, key LEDs use red    (id2  87 -  65: 0000 0000 0111 1111 1111 1111 1111 1111 = 0x007FFFFF)
    //When layer 1 is active, edge LEDs use green (id2  95 -  88: 1111 1111 1000 0000 0000 0000 0000 0000 = 0xFF800000)
    //When layer 1 is active, edge LEDs use green (id3 119 -  96: 0000 0000 1111 1111 1111 1111 1111 1111 = 0x00FFFFFF)
    // { .flags = LED_FLAG_USE_ROTATE_PATTERN },

    #define WAVE_LED_INSTRUCTION_START 1
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0, .id1 = 0, .id2 = 0, .g = 255 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0, .id1 = 0, .id2 = 0, .g = 255 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0, .id1 = 0, .id2 = 0, .g = 255 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0, .id1 = 0, .id2 = 0, .g = 255 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0, .id1 = 0, .id2 = 0, .g = 255 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0, .id1 = 0, .id2 = 0, .g = 255 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0, .id1 = 0, .id2 = 0, .g = 255 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0, .id1 = 0, .id2 = 0, .g = 255 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0, .id1 = 0, .id2 = 0, .g = 255 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0, .id1 = 0, .id2 = 0, .g = 255 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0, .id1 = 0, .id2 = 0, .g = 255 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0, .id1 = 0, .id2 = 0, .g = 255 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0, .id1 = 0, .id2 = 0, .g = 255 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0, .id1 = 0, .id2 = 0, .g = 255 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0, .id1 = 0, .id2 = 0, .g = 255 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0, .id1 = 0, .id2 = 0, .g = 255 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0, .id1 = 0, .id2 = 0, .g = 255 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0, .id1 = 0, .id2 = 0, .g = 255 },
    #define WAVE_LED_INSTRUCTION_END 18

    //All key LEDs use red while edge LEDs use the active pattern
    //All key LEDs use red     (id0  32 -   1: 1111 1111 1111 1111 1111 1111 1111 1111 = 0xFFFFFFFF)
    //All key LEDs use red     (id1  64 -  33: 1111 1111 1111 1111 1111 1111 1111 1111 = 0xFFFFFFFF)
    //All key LEDs use red     (id2  87 -  65: 0000 0000 0111 1111 1111 1111 1111 1111 = 0x007FFFFF)
    //Edge uses active pattern (id2  95 -  88: 1111 1111 1000 0000 0000 0000 0000 0000 = 0xFF800000)
    //Edge uses active pattern (id3 119 -  96: 0000 0000 1111 1111 1111 1111 1111 1111 = 0x00FFFFFF)
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0xFFFFFFFF, .id1 = 0xFFFFFFFF, .id2 = 0x007FFFFF, .r = 255 },
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN , .id2 = 0xFF800000, .id3 = 0x00FFFFFF },

     { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_MATCH_LAYER,
     .id1 = 0b00001111001111000000011110011110,
     .r = 0, .g = 255, .b = 60, .layer = 2 },

    //end must be set to 1 to indicate end of instruction set
     { .end = 1 }
};


void set_wave_color(int color_pattern_index){
    for(int i = WAVE_LED_INSTRUCTION_START; i < WAVE_LED_INSTRUCTION_END; ++i){
        for(int j = 0; j < COLOR_PATTERN_RGB_COUNT; ++j){
            led_instructions[i].r = COLOR_PATTERNS[color_pattern_index][i][0];
            led_instructions[i].g = COLOR_PATTERNS[color_pattern_index][i][1];
            led_instructions[i].b = COLOR_PATTERNS[color_pattern_index][i][2];
        }
    }
};

void wave_effect(void){
    for(int i = WAVE_LED_INSTRUCTION_START; i < WAVE_LED_INSTRUCTION_END; ++i){
        reset_led_for_instruction(i);
    }
    int wave_led_instruction_span = WAVE_LED_INSTRUCTION_END - WAVE_LED_INSTRUCTION_START;


    keystroke_t *keystroke = ACTIVE_KEYSTROKES;
    for(int i = 0; i < MAX_ACTIVE_KEYSTORKES; ++i, ++keystroke){
        if(!keystroke->active) continue;
        bool active = false;

        uint16_t keystroke_led_id = get_led_info_by_scancode(keystroke->scancode)->id;

        float elapsed_s = timer_elapsed32(keystroke->timer) / 1000.0f;
        float travel = elapsed_s * USER_CONFIG.WAVE_SPEED;

        for(uint16_t id = 1; id <= MAX_LED_ID; ++id){
            float normalized_distance =
                    led_info[id].distance_to[keystroke_led_id] /
                    (float)DISTANCE_NORAMLIZING_PARAMETER;

            if(travel >= normalized_distance && travel - normalized_distance >= 0 &&
                    normalized_distance >= travel - USER_CONFIG.WAVE_WIDTH){
                int portion = (travel - normalized_distance) *
                        wave_led_instruction_span / USER_CONFIG.WAVE_WIDTH;
                add_led_to_instruction(portion, id);

                active = true;
            }
        }

        keystroke->active = active;
    }
};
