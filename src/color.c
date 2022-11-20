/*
 * Allegro5 library: color.c
 * version 5.2.8.0-2
 *
 * Copyright 2022 Rafał Jopek ( rafaljopek at hotmail com )
 * Copyright 2022 dev-harbour
 *
 */

#include "hballegro5.h"

// AL_FUNC(ALLEGRO_COLOR, al_map_rgb, (unsigned char r, unsigned char g, unsigned char b));
HB_FUNC( AL_MAP_RGB )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL && hb_param( 3, HB_IT_INTEGER ) != NULL )
   {
      ALLEGRO_COLOR rgb = al_map_rgb( ( unsigned char ) hb_parni( 1 ), ( unsigned char ) hb_parni( 2 ), ( unsigned char ) hb_parni( 3 ) );

      PHB_ITEM pArray = hb_itemArrayNew( 3 );

      hb_arraySetND( pArray, 1, rgb.r );
      hb_arraySetND( pArray, 2, rgb.g );
      hb_arraySetND( pArray, 3, rgb.b );

      hb_itemReturnRelease( pArray );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// AL_FUNC(ALLEGRO_COLOR, al_map_rgba, (unsigned char r, unsigned char g, unsigned char b, unsigned char a));
// AL_FUNC(ALLEGRO_COLOR, al_map_rgb_f, (float r, float g, float b));
// AL_FUNC(ALLEGRO_COLOR, al_map_rgba_f, (float r, float g, float b, float a));
// AL_FUNC(ALLEGRO_COLOR, al_premul_rgba, (unsigned char r, unsigned char g, unsigned char b, unsigned char a));
// AL_FUNC(ALLEGRO_COLOR, al_premul_rgba_f, (float r, float g, float b, float a));
// AL_FUNC(void, al_unmap_rgb, (ALLEGRO_COLOR color, unsigned char *r, unsigned char *g, unsigned char *b));
// AL_FUNC(void, al_unmap_rgba, (ALLEGRO_COLOR color, unsigned char *r, unsigned char *g, unsigned char *b, unsigned char *a));
// AL_FUNC(void, al_unmap_rgb_f, (ALLEGRO_COLOR color, float *r, float *g, float *b));
// AL_FUNC(void, al_unmap_rgba_f, (ALLEGRO_COLOR color, float *r, float *g, float *b, float *a));
// AL_FUNC(int, al_get_pixel_size, (int format));
// AL_FUNC(int, al_get_pixel_format_bits, (int format));
// AL_FUNC(int, al_get_pixel_block_size, (int format));
// AL_FUNC(int, al_get_pixel_block_width, (int format));
// AL_FUNC(int, al_get_pixel_block_height, (int format));

