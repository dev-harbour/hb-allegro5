/*
 * Allegro5 library: system.c
 * version 5.2.8.0-2
 *
 * Copyright 2022 Rafał Jopek ( rafaljopek at hotmail com )
 * Copyright 2022 dev-harbour
 *
 */

#include "hballegro5.h"

// al_init() ( al_install_system( ALLEGRO_VERSION_INT, atexit ) )
HB_FUNC( AL_INIT )
{
   hb_retl( al_init() );
}
