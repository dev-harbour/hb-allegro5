/*
 * Allegro5 library: events.c
 * version 5.2.8.0-2
 *
 * Copyright 2022 Rafał Jopek ( rafaljopek at hotmail com )
 * Copyright 2022 dev-harbour
 *
 */

#include "hballegro5.h"

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/* ALLEGRO_EVENT_QUEUE *event_queue */
static HB_GARBAGE_FUNC( hb_event_queue_Destructor )
{
   ALLEGRO_EVENT_QUEUE **ppEvent_queue = ( ALLEGRO_EVENT_QUEUE **) Cargo;

   if( *ppEvent_queue )
   {
      ALLEGRO_EVENT_QUEUE *pEvent_queue = *ppEvent_queue;
      al_destroy_event_queue( pEvent_queue );
      *ppEvent_queue = NULL;
   }
}

static const HB_GC_FUNCS s_gcEvent_queueFuncs =
{
   hb_event_queue_Destructor,
   hb_gcDummyMark
};

ALLEGRO_EVENT_QUEUE *hb_event_queue_Param( int iParam )
{
   ALLEGRO_EVENT_QUEUE **ppEvent_queue = ( ALLEGRO_EVENT_QUEUE **) hb_parptrGC( &s_gcEvent_queueFuncs, iParam );

   if( ppEvent_queue && *ppEvent_queue )
   {
      return *ppEvent_queue;
   }
   else
   {
      HB_ERR_ARGS();
      return NULL;
   }
}

ALLEGRO_EVENT_QUEUE *hb_event_queue_ParamGet( int iParam )
{
   ALLEGRO_EVENT_QUEUE **ppEvent_queue = ( ALLEGRO_EVENT_QUEUE **) hb_parptrGC( &s_gcEvent_queueFuncs, iParam );

   return ppEvent_queue ? *ppEvent_queue : NULL;
}

ALLEGRO_EVENT_QUEUE *hb_event_queue_ItemGet( PHB_ITEM pItem )
{
   ALLEGRO_EVENT_QUEUE **ppEvent_queue = ( ALLEGRO_EVENT_QUEUE **) hb_itemGetPtrGC( pItem, &s_gcEvent_queueFuncs );

   return ppEvent_queue ? *ppEvent_queue : NULL;
}

PHB_ITEM hb_event_queue_ItemPut( PHB_ITEM pItem, ALLEGRO_EVENT_QUEUE *pEvent_queue )
{
   ALLEGRO_EVENT_QUEUE **ppEvent_queue = ( ALLEGRO_EVENT_QUEUE **) hb_gcAllocate( sizeof( ALLEGRO_EVENT_QUEUE *), &s_gcEvent_queueFuncs );
   *ppEvent_queue = pEvent_queue;
   return hb_itemPutPtrGC( pItem, ppEvent_queue );
}

void hb_event_queue_ItemClear( PHB_ITEM pItem )
{
   ALLEGRO_EVENT_QUEUE **ppEvent_queue = ( ALLEGRO_EVENT_QUEUE **) hb_itemGetPtrGC( pItem, &s_gcEvent_queueFuncs );

   if( ppEvent_queue )
   {
      *ppEvent_queue = NULL;
   }
}

void hb_event_queue_Return( ALLEGRO_EVENT_QUEUE *pEvent_queue )
{
   if( pEvent_queue )
   {
      hb_event_queue_ItemPut( hb_param( -1, HB_IT_ANY ), pEvent_queue );
   }
   else
   {
      hb_ret();
   }
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

// AL_FUNC(ALLEGRO_EVENT_QUEUE*, al_create_event_queue, (void));
HB_FUNC( AL_CREATE_EVENT_QUEUE )
{
   hb_event_queue_Return( al_create_event_queue() );
}

// AL_FUNC(void, al_destroy_event_queue, (ALLEGRO_EVENT_QUEUE*));
HB_FUNC( AL_DESTROY_EVENT_QUEUE )
{
   ALLEGRO_EVENT_QUEUE **ppEvent_queue = ( ALLEGRO_EVENT_QUEUE **) hb_parptrGC( &s_gcEvent_queueFuncs, 1 );

   if( ppEvent_queue && *ppEvent_queue )
   {
      al_destroy_event_queue( *ppEvent_queue );
      *ppEvent_queue = NULL;
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// AL_FUNC(bool, al_is_event_source_registered, (ALLEGRO_EVENT_QUEUE *, ALLEGRO_EVENT_SOURCE *));

// AL_FUNC(void, al_register_event_source, (ALLEGRO_EVENT_QUEUE*, ALLEGRO_EVENT_SOURCE*));
HB_FUNC( AL_REGISTER_EVENT_SOURCE )
{
   ALLEGRO_EVENT_QUEUE *pEvent_queue = hb_event_queue_Param( 1 );
   ALLEGRO_EVENT_SOURCE *pEvent_source = hb_parptr( 2 );
   if( pEvent_queue && pEvent_source )
   {
      al_register_event_source( pEvent_queue, pEvent_source );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// AL_FUNC(void, al_unregister_event_source, (ALLEGRO_EVENT_QUEUE*, ALLEGRO_EVENT_SOURCE*));
// AL_FUNC(void, al_pause_event_queue, (ALLEGRO_EVENT_QUEUE*, bool));
// AL_FUNC(bool, al_is_event_queue_paused, (const ALLEGRO_EVENT_QUEUE*));

// AL_FUNC(bool, al_is_event_queue_empty, (ALLEGRO_EVENT_QUEUE*));
HB_FUNC( AL_IS_EVENT_QUEUE_EMPTY )
{
   ALLEGRO_EVENT_QUEUE *pEvent_queue = hb_event_queue_Param( 1 );

   if( pEvent_queue )
   {
      hb_retl( al_is_event_queue_empty( pEvent_queue ) );
    }
   else
   {
      HB_ERR_ARGS();
   }
}

// AL_FUNC(bool, al_get_next_event, (ALLEGRO_EVENT_QUEUE*, ALLEGRO_EVENT *ret_event));
HB_FUNC( AL_GET_NEXT_EVENT )
{
   ALLEGRO_EVENT_QUEUE *pEvent_queue = hb_event_queue_Param( 1 );

   if( pEvent_queue  && hb_param( 2, HB_IT_BYREF ) != NULL )
   {
      ALLEGRO_EVENT event;                                        // union ALLEGRO_EVENT
      hb_retl( al_get_next_event( pEvent_queue, &event ) );
      hb_stornint( event.type, 2 );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// AL_FUNC(bool, al_peek_next_event, (ALLEGRO_EVENT_QUEUE*, ALLEGRO_EVENT *ret_event));
// AL_FUNC(bool, al_drop_next_event, (ALLEGRO_EVENT_QUEUE*));
// AL_FUNC(void, al_flush_event_queue, (ALLEGRO_EVENT_QUEUE*));
// AL_FUNC(void, al_wait_for_event, (ALLEGRO_EVENT_QUEUE*, ALLEGRO_EVENT *ret_event));
// AL_FUNC(bool, al_wait_for_event_timed, (ALLEGRO_EVENT_QUEUE*, ALLEGRO_EVENT *ret_event, float secs));

// AL_FUNC(bool, al_wait_for_event_until, (ALLEGRO_EVENT_QUEUE *queue, ALLEGRO_EVENT *ret_event, ALLEGRO_TIMEOUT *timeout));
HB_FUNC( AL_WAIT_FOR_EVENT_UNTIL )
{
   ALLEGRO_EVENT_QUEUE *pEvent_queue = hb_event_queue_Param( 1 );

   if( pEvent_queue && hb_param( 2, HB_IT_BYREF ) != NULL && hb_param( 3, HB_IT_BYREF ) != NULL )
   {
      ALLEGRO_EVENT event;
      ALLEGRO_TIMEOUT timeout;

      /* NOTE */
      hb_retl( al_wait_for_event_until( pEvent_queue, &event, &timeout ) );
      hb_stornint( event.type, 2 );
   }
   else
   {
      HB_ERR_ARGS();
   }
}
