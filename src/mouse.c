/*
 * Allegro5 library: mouse.c
 * version 5.2.8.0-2
 *
 * Copyright 2022 Rafał Jopek ( rafaljopek at hotmail com )
 * Copyright 2022 dev-harbour
 *
 */

#include "hballegro5.h"

// AL_FUNC(bool,           al_is_mouse_installed,  (void));

// AL_FUNC(bool,           al_install_mouse,       (void));
HB_FUNC( AL_INSTALL_MOUSE )
{
   hb_retl( al_install_mouse() );
}

// AL_FUNC(void,           al_uninstall_mouse,     (void));
// AL_FUNC(unsigned int,   al_get_mouse_num_buttons, (void));
// AL_FUNC(unsigned int,   al_get_mouse_num_axes,  (void));
// AL_FUNC(bool,           al_set_mouse_xy,        (struct ALLEGRO_DISPLAY *display, int x, int y));
// AL_FUNC(bool,           al_set_mouse_z,         (int z));
// AL_FUNC(bool,           al_set_mouse_w,         (int w));
// AL_FUNC(bool,           al_set_mouse_axis,      (int axis, int value));
// AL_FUNC(void,           al_get_mouse_state,     (ALLEGRO_MOUSE_STATE *ret_state));
// AL_FUNC(bool,           al_mouse_button_down,   (const ALLEGRO_MOUSE_STATE *state, int button));
// AL_FUNC(int,            al_get_mouse_state_axis, (const ALLEGRO_MOUSE_STATE *state, int axis));
// AL_FUNC(bool, al_get_mouse_cursor_position, (int *ret_x, int *ret_y));
// AL_FUNC(bool, al_grab_mouse, (struct ALLEGRO_DISPLAY *display));
// AL_FUNC(bool, al_ungrab_mouse, (void));

// AL_FUNC(void, al_set_mouse_wheel_precision, (int precision));
HB_FUNC( AL_SET_MOUSE_WHEEL_PRECISION )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      al_set_mouse_wheel_precision( hb_parni( 1 ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// AL_FUNC(int, al_get_mouse_wheel_precision, (void));

// AL_FUNC(ALLEGRO_EVENT_SOURCE *, al_get_mouse_event_source, (void));
HB_FUNC( AL_GET_MOUSE_EVENT_SOURCE )
{
   hb_retptr( al_get_mouse_event_source() );
}
