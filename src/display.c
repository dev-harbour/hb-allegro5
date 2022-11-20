/*
 * Allegro5 library: display.c
 * version 5.2.8.0-2
 *
 * Copyright 2022 Rafał Jopek ( rafaljopek at hotmail com )
 * Copyright 2022 dev-harbour
 *
 */

#include "hballegro5.h"

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/* ALLEGRO_DISPLAY */
static HB_GARBAGE_FUNC( hb_display_Destructor )
{
   ALLEGRO_DISPLAY **ppDisplay = ( ALLEGRO_DISPLAY **) Cargo;

   if( *ppDisplay )
   {
      ALLEGRO_DISPLAY *pDisplay = *ppDisplay;
      al_destroy_display( pDisplay);
      *ppDisplay = NULL;
   }
}

static const HB_GC_FUNCS s_gcDisplayFuncs =
{
   hb_display_Destructor,
   hb_gcDummyMark
};

ALLEGRO_DISPLAY *hb_display_Param( int iParam )
{
   ALLEGRO_DISPLAY **ppDisplay = ( ALLEGRO_DISPLAY **) hb_parptrGC( &s_gcDisplayFuncs, iParam );

   if( ppDisplay && *ppDisplay )
   {
      return *ppDisplay;
   }
   else
   {
      HB_ERR_ARGS();
      return NULL;
   }
}

ALLEGRO_DISPLAY *hb_display_ParamGet( int iParam )
{
   ALLEGRO_DISPLAY **ppDisplay = ( ALLEGRO_DISPLAY **) hb_parptrGC( &s_gcDisplayFuncs, iParam );

   return ppDisplay ? *ppDisplay : NULL;
}

ALLEGRO_DISPLAY *hb_display_ItemGet( PHB_ITEM pItem )
{
   ALLEGRO_DISPLAY **ppDisplay = ( ALLEGRO_DISPLAY **) hb_itemGetPtrGC( pItem, &s_gcDisplayFuncs );

   return ppDisplay ? *ppDisplay : NULL;
}

PHB_ITEM hb_display_ItemPut( PHB_ITEM pItem, ALLEGRO_DISPLAY *pDisplay )
{
   ALLEGRO_DISPLAY **ppDisplay = ( ALLEGRO_DISPLAY **) hb_gcAllocate( sizeof( ALLEGRO_DISPLAY *), &s_gcDisplayFuncs );
   *ppDisplay = pDisplay;
   return hb_itemPutPtrGC( pItem, ppDisplay );
}

void hb_display_ItemClear( PHB_ITEM pItem )
{
   ALLEGRO_DISPLAY **ppDisplay = ( ALLEGRO_DISPLAY **) hb_itemGetPtrGC( pItem, &s_gcDisplayFuncs );

   if( ppDisplay )
   {
      *ppDisplay = NULL;
   }
}

void hb_display_Return( ALLEGRO_DISPLAY *pDisplay )
{
   if( pDisplay )
   {
      hb_display_ItemPut( hb_param( -1, HB_IT_ANY ), pDisplay );
   }
   else
   {
      hb_ret();
   }
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

// AL_FUNC(void, al_set_new_display_refresh_rate, (int refresh_rate));

// AL_FUNC(void, al_set_new_display_flags, (int flags));
HB_FUNC( AL_SET_NEW_DISPLAY_FLAGS )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      al_set_new_display_flags( hb_parni( 1 ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// AL_FUNC(int,  al_get_new_display_refresh_rate, (void));
// AL_FUNC(int,  al_get_new_display_flags, (void));
// AL_FUNC(void, al_set_new_window_title, (const char *title));
// AL_FUNC(const char *, al_get_new_window_title, (void));
// AL_FUNC(int, al_get_display_width,  (ALLEGRO_DISPLAY *display));
// AL_FUNC(int, al_get_display_height, (ALLEGRO_DISPLAY *display));
// AL_FUNC(int, al_get_display_format, (ALLEGRO_DISPLAY *display));
// AL_FUNC(int, al_get_display_refresh_rate, (ALLEGRO_DISPLAY *display));
// AL_FUNC(int, al_get_display_flags,  (ALLEGRO_DISPLAY *display));
// AL_FUNC(int, al_get_display_orientation, (ALLEGRO_DISPLAY* display));
// AL_FUNC(bool, al_set_display_flag, (ALLEGRO_DISPLAY *display, int flag, bool onoff));

// AL_FUNC(ALLEGRO_DISPLAY*, al_create_display, (int w, int h));
HB_FUNC( AL_CREATE_DISPLAY )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL  )
   {
      hb_display_Return( al_create_display( hb_parni( 1 ), hb_parni( 2 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// AL_FUNC( void,             al_destroy_display, (ALLEGRO_DISPLAY *display));
HB_FUNC( AL_DESTROY_DISPLAY )
{
   ALLEGRO_DISPLAY **ppDisplay = ( ALLEGRO_DISPLAY **) hb_parptrGC( &s_gcDisplayFuncs, 1 );

   if( ppDisplay && *ppDisplay )
   {
      al_destroy_display( *ppDisplay );
      *ppDisplay = NULL;
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// AL_FUNC(ALLEGRO_DISPLAY*, al_get_current_display, (void));
// AL_FUNC(void,            al_set_target_bitmap, (ALLEGRO_BITMAP *bitmap));

// AL_FUNC(void,            al_set_target_backbuffer, (ALLEGRO_DISPLAY *display));
HB_FUNC( AL_SET_TARGET_BACKBUFFER )
{
   ALLEGRO_DISPLAY *pDisplay = hb_display_Param( 1 );

   if( pDisplay )
   {
      al_set_target_backbuffer( pDisplay );
   }
   else
   {
      HB_ERR_ARGS();
   }
}


// AL_FUNC(ALLEGRO_BITMAP*, al_get_backbuffer,    (ALLEGRO_DISPLAY *display));
// AL_FUNC(ALLEGRO_BITMAP*, al_get_target_bitmap, (void));
// AL_FUNC(bool, al_acknowledge_resize, (ALLEGRO_DISPLAY *display));
// AL_FUNC(bool, al_resize_display,     (ALLEGRO_DISPLAY *display, int width, int height));

// AL_FUNC(void, al_flip_display,       (void));
HB_FUNC( AL_FLIP_DISPLAY )
{
   al_flip_display();
}
// AL_FUNC(void, al_update_display_region, (int x, int y, int width, int height));
// AL_FUNC(bool, al_is_compatible_bitmap, (ALLEGRO_BITMAP *bitmap));
// AL_FUNC(bool, al_wait_for_vsync, (void));

// AL_FUNC(ALLEGRO_EVENT_SOURCE *, al_get_display_event_source, (ALLEGRO_DISPLAY *display));
HB_FUNC( AL_GET_DISPLAY_EVENT_SOURCE )
{
   ALLEGRO_DISPLAY *pDisplay = hb_display_Param( 1 );

   if( pDisplay )
   {
      hb_retptr( al_get_display_event_source( pDisplay ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// AL_FUNC(void, al_set_display_icon, (ALLEGRO_DISPLAY *display, ALLEGRO_BITMAP *icon));
// AL_FUNC(void, al_set_display_icons, (ALLEGRO_DISPLAY *display, int num_icons, ALLEGRO_BITMAP *icons[]));
// AL_FUNC(int, al_get_new_display_adapter, (void));

// AL_FUNC(void, al_set_new_display_adapter, (int adapter));
HB_FUNC( AL_SET_NEW_DISPLAY_ADAPTER )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      al_set_new_display_adapter( hb_parni( 1 ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// AL_FUNC(void, al_set_new_window_position, (int x, int y));
// AL_FUNC(void, al_get_new_window_position, (int *x, int *y));
// AL_FUNC(void, al_set_window_position, (ALLEGRO_DISPLAY *display, int x, int y));
// AL_FUNC(void, al_get_window_position, (ALLEGRO_DISPLAY *display, int *x, int *y));
// AL_FUNC(bool, al_set_window_constraints, (ALLEGRO_DISPLAY *display, int min_w, int min_h, int max_w, int max_h));
// AL_FUNC(bool, al_get_window_constraints, (ALLEGRO_DISPLAY *display, int *min_w, int *min_h, int *max_w, int *max_h));
// AL_FUNC(void, al_apply_window_constraints, (ALLEGRO_DISPLAY *display, bool onoff));

// AL_FUNC(void, al_set_window_title, (ALLEGRO_DISPLAY *display, const char *title));
HB_FUNC( AL_SET_WINDOW_TITLE )
{
   ALLEGRO_DISPLAY *pDisplay = hb_display_Param( 1 );

   if( pDisplay && hb_param( 2, HB_IT_STRING ) != NULL )
   {
      al_set_window_title( pDisplay, hb_parc( 2 ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// AL_FUNC(void, al_set_new_display_option, (int option, int value, int importance));
HB_FUNC( AL_SET_NEW_DISPLAY_OPTION )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL && hb_param( 3, HB_IT_INTEGER ) != NULL )
   {
      al_set_new_display_option( hb_parni( 1 ), hb_parni( 2 ), hb_parni( 3 ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// AL_FUNC(int, al_get_new_display_option, (int option, int *importance));
// AL_FUNC(void, al_reset_new_display_options, (void));
// AL_FUNC(void, al_set_display_option, (ALLEGRO_DISPLAY *display, int option, int value));
// AL_FUNC(int, al_get_display_option, (ALLEGRO_DISPLAY *display, int option));
// AL_FUNC(void, al_hold_bitmap_drawing, (bool hold));
// AL_FUNC(bool, al_is_bitmap_drawing_held, (void));
// AL_FUNC(void, al_acknowledge_drawing_halt, (ALLEGRO_DISPLAY *display));
// AL_FUNC(void, al_acknowledge_drawing_resume, (ALLEGRO_DISPLAY *display));

// #if defined(ALLEGRO_UNSTABLE) || defined(ALLEGRO_INTERNAL_UNSTABLE) || defined(ALLEGRO_SRC)
// AL_FUNC(void, al_backup_dirty_bitmaps, (ALLEGRO_DISPLAY *display));
// #endif

