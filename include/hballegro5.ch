#ifndef HBALLEGRO5_CH_
#define HBALLEGRO5_CH_

/* color.h*/
#define  ALLEGRO_PIXEL_FORMAT_ANY                    0
#define  ALLEGRO_PIXEL_FORMAT_ANY_NO_ALPHA           1
#define  ALLEGRO_PIXEL_FORMAT_ANY_WITH_ALPHA         2
#define  ALLEGRO_PIXEL_FORMAT_ANY_15_NO_ALPHA        3
#define  ALLEGRO_PIXEL_FORMAT_ANY_16_NO_ALPHA        4
#define  ALLEGRO_PIXEL_FORMAT_ANY_16_WITH_ALPHA      5
#define  ALLEGRO_PIXEL_FORMAT_ANY_24_NO_ALPHA        6
#define  ALLEGRO_PIXEL_FORMAT_ANY_32_NO_ALPHA        7
#define  ALLEGRO_PIXEL_FORMAT_ANY_32_WITH_ALPHA      8
#define  ALLEGRO_PIXEL_FORMAT_ARGB_8888              9
#define  ALLEGRO_PIXEL_FORMAT_RGBA_8888              10
#define  ALLEGRO_PIXEL_FORMAT_ARGB_4444              11
#define  ALLEGRO_PIXEL_FORMAT_RGB_888                12 /* 24 bit format */
#define  ALLEGRO_PIXEL_FORMAT_RGB_565                13
#define  ALLEGRO_PIXEL_FORMAT_RGB_555                14
#define  ALLEGRO_PIXEL_FORMAT_RGBA_5551              15
#define  ALLEGRO_PIXEL_FORMAT_ARGB_1555              16
#define  ALLEGRO_PIXEL_FORMAT_ABGR_8888              17
#define  ALLEGRO_PIXEL_FORMAT_XBGR_8888              18
#define  ALLEGRO_PIXEL_FORMAT_BGR_888                19 /* 24 bit format */
#define  ALLEGRO_PIXEL_FORMAT_BGR_565                20
#define  ALLEGRO_PIXEL_FORMAT_BGR_555                21
#define  ALLEGRO_PIXEL_FORMAT_RGBX_8888              22
#define  ALLEGRO_PIXEL_FORMAT_XRGB_8888              23
#define  ALLEGRO_PIXEL_FORMAT_ABGR_F32               24
#define  ALLEGRO_PIXEL_FORMAT_ABGR_8888_LE           25
#define  ALLEGRO_PIXEL_FORMAT_RGBA_4444              26
#define  ALLEGRO_PIXEL_FORMAT_SINGLE_CHANNEL_8       27
#define  ALLEGRO_PIXEL_FORMAT_COMPRESSED_RGBA_DXT1   28
#define  ALLEGRO_PIXEL_FORMAT_COMPRESSED_RGBA_DXT3   29
#define  ALLEGRO_PIXEL_FORMAT_COMPRESSED_RGBA_DXT5   30
#define  ALLEGRO_NUM_PIXEL_FORMATS
/* End color.h */

/* display.h */
/* Possible bit combinations for the flags parameter of al_create_display. */
#define ALLEGRO_WINDOWED                    1
#define ALLEGRO_FULLSCREEN                  2
#define ALLEGRO_OPENGL                      4
#define ALLEGRO_DIRECT3D_INTERNAL           8
#define ALLEGRO_RESIZABLE                   16
#define ALLEGRO_FRAMELESS                   32
#define ALLEGRO_NOFRAME                     ALLEGRO_FRAMELESS /* older synonym */
#define ALLEGRO_GENERATE_EXPOSE_EVENTS      64
#define ALLEGRO_OPENGL_3_0                  128
#define ALLEGRO_OPENGL_FORWARD_COMPATIBLE   256
#define ALLEGRO_FULLSCREEN_WINDOW           512
#define ALLEGRO_MINIMIZED                   1024
#define ALLEGRO_PROGRAMMABLE_PIPELINE       2048
#define ALLEGRO_GTK_TOPLEVEL_INTERNAL       4096
#define ALLEGRO_MAXIMIZED                   8192
#define ALLEGRO_OPENGL_ES_PROFILE           16384

#define ALLEGRO_OPENGL_CORE_PROFILE         32768

/* Possible parameters for al_set_display_option.
 * Make sure to update ALLEGRO_EXTRA_DISPLAY_SETTINGS if you modify
 * anything here.
 */
#define ALLEGRO_RED_SIZE                 0
#define ALLEGRO_GREEN_SIZE               1
#define ALLEGRO_BLUE_SIZE                2
#define ALLEGRO_ALPHA_SIZE               3
#define ALLEGRO_RED_SHIFT                4
#define ALLEGRO_GREEN_SHIFT              5
#define ALLEGRO_BLUE_SHIFT               6
#define ALLEGRO_ALPHA_SHIFT              7
#define ALLEGRO_ACC_RED_SIZE             8
#define ALLEGRO_ACC_GREEN_SIZE           9
#define ALLEGRO_ACC_BLUE_SIZE            10
#define ALLEGRO_ACC_ALPHA_SIZE           11
#define ALLEGRO_STEREO                   12
#define ALLEGRO_AUX_BUFFERS              13
#define ALLEGRO_COLOR_SIZE               14
#define ALLEGRO_DEPTH_SIZE               15
#define ALLEGRO_STENCIL_SIZE             16
#define ALLEGRO_SAMPLE_BUFFERS           17
#define ALLEGRO_SAMPLES                  18
#define ALLEGRO_RENDER_METHOD            19
#define ALLEGRO_FLOAT_COLOR              20
#define ALLEGRO_FLOAT_DEPTH              21
#define ALLEGRO_SINGLE_BUFFER            22
#define ALLEGRO_SWAP_METHOD              23
#define ALLEGRO_COMPATIBLE_DISPLAY       24
#define ALLEGRO_UPDATE_DISPLAY_REGION    25
#define ALLEGRO_VSYNC                    26
#define ALLEGRO_MAX_BITMAP_SIZE          27
#define ALLEGRO_SUPPORT_NPOT_BITMAP      28
#define ALLEGRO_CAN_DRAW_INTO_BITMAP     29
#define ALLEGRO_SUPPORT_SEPARATE_ALPHA   30
#define ALLEGRO_AUTO_CONVERT_BITMAPS     31
#define ALLEGRO_SUPPORTED_ORIENTATIONS   32
#define ALLEGRO_OPENGL_MAJOR_VERSION     33
#define ALLEGRO_OPENGL_MINOR_VERSION     34
#define ALLEGRO_DISPLAY_OPTIONS_COUNT    35

#define ALLEGRO_DONTCARE 0
#define ALLEGRO_REQUIRE  1
#define ALLEGRO_SUGGEST  2

/* Bitflags so they can be used for the ALLEGRO_SUPPORTED_ORIENTATIONS option. */
#define ALLEGRO_DISPLAY_ORIENTATION_UNKNOWN       0
#define ALLEGRO_DISPLAY_ORIENTATION_0_DEGREES     1
#define ALLEGRO_DISPLAY_ORIENTATION_90_DEGREES    2
#define ALLEGRO_DISPLAY_ORIENTATION_180_DEGREES   4
#define ALLEGRO_DISPLAY_ORIENTATION_270_DEGREES   8
#define ALLEGRO_DISPLAY_ORIENTATION_PORTRAIT      5
#define ALLEGRO_DISPLAY_ORIENTATION_LANDSCAPE     10
#define ALLEGRO_DISPLAY_ORIENTATION_ALL           15
#define ALLEGRO_DISPLAY_ORIENTATION_FACE_UP       16
#define ALLEGRO_DISPLAY_ORIENTATION_FACE_DOWN     32

/* Formally part of the primitives addon. */
#define ALLEGRO_PRIM_MAX_USER_ATTR                10

#define ALLEGRO_NEW_WINDOW_TITLE_MAX_SIZE 255
/* End display.h */

/* events.h */
#define ALLEGRO_EVENT_JOYSTICK_AXIS               1
#define ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN        2
#define ALLEGRO_EVENT_JOYSTICK_BUTTON_UP          3
#define ALLEGRO_EVENT_JOYSTICK_CONFIGURATION      4

#define ALLEGRO_EVENT_KEY_DOWN                    10
#define ALLEGRO_EVENT_KEY_CHAR                    11
#define ALLEGRO_EVENT_KEY_UP                      12

#define ALLEGRO_EVENT_MOUSE_AXES                  20
#define ALLEGRO_EVENT_MOUSE_BUTTON_DOWN           21
#define ALLEGRO_EVENT_MOUSE_BUTTON_UP             22
#define ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY         23
#define ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY         24
#define ALLEGRO_EVENT_MOUSE_WARPED                25

#define ALLEGRO_EVENT_TIMER                       30

#define ALLEGRO_EVENT_DISPLAY_EXPOSE              40
#define ALLEGRO_EVENT_DISPLAY_RESIZE              41
#define ALLEGRO_EVENT_DISPLAY_CLOSE               42
#define ALLEGRO_EVENT_DISPLAY_LOST                43
#define ALLEGRO_EVENT_DISPLAY_FOUND               44
#define ALLEGRO_EVENT_DISPLAY_SWITCH_IN           45
#define ALLEGRO_EVENT_DISPLAY_SWITCH_OUT          46
#define ALLEGRO_EVENT_DISPLAY_ORIENTATION         47
#define ALLEGRO_EVENT_DISPLAY_HALT_DRAWING        48
#define ALLEGRO_EVENT_DISPLAY_RESUME_DRAWING      49

#define ALLEGRO_EVENT_TOUCH_BEGIN                 50
#define ALLEGRO_EVENT_TOUCH_END                   51
#define ALLEGRO_EVENT_TOUCH_MOVE                  52
#define ALLEGRO_EVENT_TOUCH_CANCEL                53

#define ALLEGRO_EVENT_DISPLAY_CONNECTED           60
#define ALLEGRO_EVENT_DISPLAY_DISCONNECTED        61
/* End events.h*/


/* keycodes.h */
#define ALLEGRO_KEY_A      1
#define ALLEGRO_KEY_B      2
#define ALLEGRO_KEY_C      3
#define ALLEGRO_KEY_D      4
#define ALLEGRO_KEY_E      5
#define ALLEGRO_KEY_F      6
#define ALLEGRO_KEY_G      7
#define ALLEGRO_KEY_H      8
#define ALLEGRO_KEY_I      9
#define ALLEGRO_KEY_J      10
#define ALLEGRO_KEY_K      11
#define ALLEGRO_KEY_L      12
#define ALLEGRO_KEY_M      13
#define ALLEGRO_KEY_N      14
#define ALLEGRO_KEY_O      15
#define ALLEGRO_KEY_P      16
#define ALLEGRO_KEY_Q      17
#define ALLEGRO_KEY_R      18
#define ALLEGRO_KEY_S      19
#define ALLEGRO_KEY_T      20
#define ALLEGRO_KEY_U      21
#define ALLEGRO_KEY_V      22
#define ALLEGRO_KEY_W      23
#define ALLEGRO_KEY_X      24
#define ALLEGRO_KEY_Y      25
#define ALLEGRO_KEY_Z      26

#define ALLEGRO_KEY_0      27
#define ALLEGRO_KEY_1      28
#define ALLEGRO_KEY_2      29
#define ALLEGRO_KEY_3      30
#define ALLEGRO_KEY_4      31
#define ALLEGRO_KEY_5      32
#define ALLEGRO_KEY_6      33
#define ALLEGRO_KEY_7      34
#define ALLEGRO_KEY_8      35
#define ALLEGRO_KEY_9      36

#define ALLEGRO_KEY_PAD_0  37
#define ALLEGRO_KEY_PAD_1  38
#define ALLEGRO_KEY_PAD_2  39
#define ALLEGRO_KEY_PAD_3  40
#define ALLEGRO_KEY_PAD_4  41
#define ALLEGRO_KEY_PAD_5  42
#define ALLEGRO_KEY_PAD_6  43
#define ALLEGRO_KEY_PAD_7  44
#define ALLEGRO_KEY_PAD_8  45
#define ALLEGRO_KEY_PAD_9  46

#define ALLEGRO_KEY_F1     47
#define ALLEGRO_KEY_F2     48
#define ALLEGRO_KEY_F3     49
#define ALLEGRO_KEY_F4     50
#define ALLEGRO_KEY_F5     51
#define ALLEGRO_KEY_F6     52
#define ALLEGRO_KEY_F7     53
#define ALLEGRO_KEY_F8     54
#define ALLEGRO_KEY_F9     55
#define ALLEGRO_KEY_F10    56
#define ALLEGRO_KEY_F11    57
#define ALLEGRO_KEY_F12    58

#define ALLEGRO_KEY_ESCAPE     59
#define ALLEGRO_KEY_TILDE      60
#define ALLEGRO_KEY_MINUS      61
#define ALLEGRO_KEY_EQUALS     62
#define ALLEGRO_KEY_BACKSPACE  63
#define ALLEGRO_KEY_TAB        64
#define ALLEGRO_KEY_OPENBRACE  65
#define ALLEGRO_KEY_CLOSEBRACE 66
#define ALLEGRO_KEY_ENTER      67
#define ALLEGRO_KEY_SEMICOLON  68
#define ALLEGRO_KEY_QUOTE      69
#define ALLEGRO_KEY_BACKSLASH  70
#define ALLEGRO_KEY_BACKSLASH2 71 /* DirectInput calls this DIK_OEM_102: "< > | on UK/Germany keyboards" */
#define ALLEGRO_KEY_COMMA      72
#define ALLEGRO_KEY_FULLSTOP   73
#define ALLEGRO_KEY_SLASH      74
#define ALLEGRO_KEY_SPACE      75

#define ALLEGRO_KEY_INSERT     76
#define ALLEGRO_KEY_DELETE     77
#define ALLEGRO_KEY_HOME       78
#define ALLEGRO_KEY_END        79
#define ALLEGRO_KEY_PGUP       80
#define ALLEGRO_KEY_PGDN       81
#define ALLEGRO_KEY_LEFT       82
#define ALLEGRO_KEY_RIGHT      83
#define ALLEGRO_KEY_UP         84
#define ALLEGRO_KEY_DOWN       85

#define ALLEGRO_KEY_PAD_SLASH      86
#define ALLEGRO_KEY_PAD_ASTERISK   87
#define ALLEGRO_KEY_PAD_MINUS      88
#define ALLEGRO_KEY_PAD_PLUS       89
#define ALLEGRO_KEY_PAD_DELETE     90
#define ALLEGRO_KEY_PAD_ENTER      91

#define ALLEGRO_KEY_PRINTSCREEN    92
#define ALLEGRO_KEY_PAUSE          93

#define ALLEGRO_KEY_ABNT_C1        94
#define ALLEGRO_KEY_YEN            95
#define ALLEGRO_KEY_KANA           96
#define ALLEGRO_KEY_CONVERT        97
#define ALLEGRO_KEY_NOCONVERT      98
#define ALLEGRO_KEY_AT             99
#define ALLEGRO_KEY_CIRCUMFLEX     100
#define ALLEGRO_KEY_COLON2         101
#define ALLEGRO_KEY_KANJI          102

#define ALLEGRO_KEY_PAD_EQUALS     103   /* MacOS X */
#define ALLEGRO_KEY_BACKQUOTE      104   /* MacOS X */
#define ALLEGRO_KEY_SEMICOLON2     105   /* MacOS X -- TODO: ask lillo what this should be */
#define ALLEGRO_KEY_COMMAND        106   /* MacOS X */

#define ALLEGRO_KEY_BACK           107   /* Android back key */
#define ALLEGRO_KEY_VOLUME_UP      108
#define ALLEGRO_KEY_VOLUME_DOWN    109

/* Android game keys */
#define ALLEGRO_KEY_SEARCH         110
#define ALLEGRO_KEY_DPAD_CENTER    111
#define ALLEGRO_KEY_BUTTON_X       112
#define ALLEGRO_KEY_BUTTON_Y       113
#define ALLEGRO_KEY_DPAD_UP        114
#define ALLEGRO_KEY_DPAD_DOWN      115
#define ALLEGRO_KEY_DPAD_LEFT      116
#define ALLEGRO_KEY_DPAD_RIGHT     117
#define ALLEGRO_KEY_SELECT         118
#define ALLEGRO_KEY_START          119
#define ALLEGRO_KEY_BUTTON_L1      120
#define ALLEGRO_KEY_BUTTON_R1      121
#define ALLEGRO_KEY_BUTTON_L2      122
#define ALLEGRO_KEY_BUTTON_R2      123
#define ALLEGRO_KEY_BUTTON_A       124
#define ALLEGRO_KEY_BUTTON_B       125
#define ALLEGRO_KEY_THUMBL         126
#define ALLEGRO_KEY_THUMBR         127

ALLEGRO_KEY_UNKNOWN                128

/* All codes up to before ALLEGRO_KEY_MODIFIERS can be freely
 * assignedas additional unknown keys, like various multimedia
 * and application keys keyboards may have.
 */

 #define ALLEGRO_KEY_MODIFIERS     215

#define ALLEGRO_KEY_LSHIFT         215
#define ALLEGRO_KEY_RSHIFT         216
#define ALLEGRO_KEY_LCTRL          217
#define ALLEGRO_KEY_RCTRL          218
#define ALLEGRO_KEY_ALT            219
#define ALLEGRO_KEY_ALTGR          220
#define ALLEGRO_KEY_LWIN           221
#define ALLEGRO_KEY_RWIN           222
#define ALLEGRO_KEY_MENU           223
#define ALLEGRO_KEY_SCROLLLOCK     224
#define ALLEGRO_KEY_NUMLOCK        225
#define ALLEGRO_KEY_CAPSLOCK       226

#define ALLEGRO_KEY_MAX            227
/* End keycodes.h */

/* mouse.h */
/* Allow up to four extra axes for future expansion. */
#define ALLEGRO_MOUSE_MAX_EXTRA_AXES    4
/* End mouse.h */

#endif /* HBALLEGRO5_CH_ */
