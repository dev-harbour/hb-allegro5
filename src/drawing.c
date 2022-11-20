/*
 * Allegro5 library: drawing.c
 * version 5.2.8.0-2
 *
 * Copyright 2022 Rafał Jopek ( rafaljopek at hotmail com )
 * Copyright 2022 dev-harbour
 *
 */

#include "hballegro5.h"

// AL_FUNC(void, al_clear_to_color, (ALLEGRO_COLOR color));
HB_FUNC( AL_CLEAR_TO_COLOR )
{
   PHB_ITEM pArray;

   if( ( pArray = hb_param( 1, HB_IT_ARRAY ) ) != NULL )
   {
      ALLEGRO_COLOR color;
      color.r = ( float ) hb_arrayGetND( pArray, 1 );
      color.g = ( float ) hb_arrayGetND( pArray, 2 );
      color.b = ( float ) hb_arrayGetND( pArray, 3 );
      color.a = ( float ) hb_arrayGetND( pArray, 4 );

      al_clear_to_color( color );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// AL_FUNC(void, al_clear_depth_buffer, (float x));
// AL_FUNC(void, al_draw_pixel, (float x, float y, ALLEGRO_COLOR color));
