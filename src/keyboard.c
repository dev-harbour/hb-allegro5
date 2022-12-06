   /*
 * Allegro5 library: keyboard.c
 * version 5.2.8.0-2
 *
 * Copyright 2022 Rafał Jopek ( rafaljopek at hotmail com )
 * Copyright 2022 dev-harbour
 *
 */

#include "hballegro5.h"

// AL_FUNC(bool,         al_is_keyboard_installed,   (void));

// AL_FUNC(bool,         al_install_keyboard,   (void));
HB_FUNC( AL_INSTALL_KEYBOARD )
{
   hb_retl( al_install_keyboard() );
}

// AL_FUNC(void,         al_uninstall_keyboard, (void));
// AL_FUNC(bool,         al_set_keyboard_leds,  (int leds));
// AL_FUNC(const char *, al_keycode_to_name, (int keycode));
// AL_FUNC(void,         al_get_keyboard_state, (ALLEGRO_KEYBOARD_STATE *ret_state));

// #if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
// AL_FUNC(void,         al_clear_keyboard_state, (ALLEGRO_DISPLAY *display));
// #endif

// AL_FUNC(bool,         al_key_down,           (const ALLEGRO_KEYBOARD_STATE *, int keycode));

// AL_FUNC(ALLEGRO_EVENT_SOURCE *, al_get_keyboard_event_source, (void));
HB_FUNC( AL_GET_KEYBOARD_EVENT_SOURCE )
{
   hb_retptr( al_get_keyboard_event_source() );
}

