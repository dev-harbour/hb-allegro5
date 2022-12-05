/*
 *
 */

#include "hballegro5.ch"

PROCEDURE Main()

   LOCAL nWidth := 720, nHeight := 450
   LOCAL pDisplay
   LOCAL pEvent_queue
   LOCAL timeout
   LOCAL lGet_event
   LOCAL nEvent

   IF( ! al_init() )
      OutStd( e"failed to initialize allegro5!\n" )
      RETURN
   ENDIF

   al_install_mouse()
   al_set_mouse_wheel_precision( 150 )
   al_install_keyboard()
   IF( al_is_keyboard_installed() )
      OutStd( e"Keyboard instaled!\n" )
   ELSE
      OutStd( e"Keyboard instaled error...\n" )
   ENDIF

   al_set_new_display_flags( ALLEGRO_WINDOWED + ALLEGRO_RESIZABLE + ALLEGRO_OPENGL )
   al_set_new_display_option( ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST )
   al_set_new_display_option( ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST )

   pDisplay := al_create_display( nWidth, nHeight )
   IF( pDisplay == NIL )
      OutStd( e"failed to create pDisplay!\n" )
      RETURN
   ENDIF

   pEvent_queue := al_create_event_queue()
   IF( pEvent_queue == NIL )
      OutStd( e"failed to create pEvent_queue!\n" )
      al_destroy_display( pDisplay )
      RETURN
   ENDIF

   al_set_window_title( pDisplay, "Harbour .AND. Allegro5" )

   al_register_event_source( pEvent_queue, al_get_display_event_source( pDisplay ) )
   al_register_event_source( pEvent_queue, al_get_mouse_event_source() )
   al_register_event_source( pEvent_queue, al_get_keyboard_event_source() )

   WHILE( nEvent != ALLEGRO_EVENT_DISPLAY_CLOSE  .AND. nEvent != ALLEGRO_KEY_ESCAPE )

      al_init_timeout( @timeout, 0.06 )

      lGet_event := al_wait_for_event_until( pEvent_queue, @nEvent, @timeout )

      IF( lGet_event )
         SWITCH nEvent
            CASE ALLEGRO_EVENT_KEY_DOWN
               OutStd( e"Down\n" )
               EXIT
            CASE ALLEGRO_EVENT_KEY_UP
               OutStd( e"Up\n" )
               EXIT
         ENDSWITCH

         WHILE( lGet_event )
            lGet_event := al_get_next_event( pEvent_queue, @nEvent )
         ENDDO

      ENDIF

      al_clear_to_color( { 30 / 255, 69 / 255, 34 / 255, 1.0 } )

      al_flip_display()

   ENDDO

   al_destroy_display( pDisplay )
   al_destroy_event_queue( pEvent_queue )
   al_uninstall_keyboard();

   RETURN
