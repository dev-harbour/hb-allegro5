/*
 * Allegro5 library: altime.c
 * version 5.2.8.0-2
 *
 * Copyright 2022 Rafał Jopek ( rafaljopek at hotmail com )
 * Copyright 2022 dev-harbour
 *
 */

#include "hballegro5.h"

// AL_FUNC(double, al_get_time, (void));

// AL_FUNC(void, al_rest, (double seconds));
HB_FUNC( AL_REST )
{
   if( hb_param( 1, HB_IT_NUMERIC ) != NULL )
   {
      al_rest( hb_parnd( 1 ) );
   }
   else
   {
      HB_ERR_ARGS();
   }

}

// AL_FUNC(void, al_init_timeout, (ALLEGRO_TIMEOUT *timeout, double seconds));
HB_FUNC( AL_INIT_TIMEOUT )
{
   if( hb_param( 1, HB_IT_BYREF ) != NULL && hb_param( 2, HB_IT_NUMERIC ) != NULL )
   {
      ALLEGRO_TIMEOUT timeout;

      al_init_timeout( &timeout, hb_parnd( 2 ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}
