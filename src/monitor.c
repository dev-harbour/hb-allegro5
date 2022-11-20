/*
 * Allegro5 library: monitor.c
 * version 5.2.8.0-2
 *
 * Copyright 2022 Rafał Jopek ( rafaljopek at hotmail com )
 * Copyright 2022 dev-harbour
 *
 */

#include "hballegro5.h"

// AL_FUNC(int, al_get_num_video_adapters, (void));
HB_FUNC( AL_GET_NUM_VIDEO_ADAPTERS )
{
   hb_retni( al_get_num_video_adapters() );
}

// AL_FUNC(bool, al_get_monitor_info, (int adapter, ALLEGRO_MONITOR_INFO *info));
// AL_FUNC(int, al_get_monitor_dpi, (int adapter));

// #if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
// AL_FUNC(int, al_get_monitor_refresh_rate, (int adapter));
// #endif
