/*
 * stdlib: stdlib.c
 *
 * Copyright 2022 Rafał Jopek ( rafaljopek at hotmail com )
 * Copyright 2022 dev-harbour
 *
 */

#include "hballegro5.h"

HB_FUNC( RAND )
{
   hb_retni( rand() );
}
