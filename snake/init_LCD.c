/*
 * init_LCD.c
 *
 *  Created on: 12 Nov 2024
 *      Author: gergelytamasy
 */

/**************************************************************************//**
 * @brief
 *   Typedef to store the segment data of a 14-segment alphanumeric
 *   character.
 *
 * @details
 *   The typedef uses a 16 bit integer to store the data. As we need only 14
 *   segments, the upper two bits are unused. The bits are mapped to the
 *   segments in the following way:
 *
 *    --------- 0,a --------
 *
 *   |     \7,h  |8,j  /    |
 *   |5,f   \    |    /9,k  |1,b
 *   |       \   |   /      |
 *
 *    --- 6,g --   -- 10,m --
 *
 *   |      /    |    \11,n |
 *   |4,e  /13,q |12,p \    |2,c
 *   |    /      |      \   |
 *
 *    --------- 3,d --------
 *
 *   The bits can be accessed in two ways:
 *
 *    1. Using a single, 16 bit value (raw).
 *    2. Accessing individual bits using bit fields (a..q).
 *
 *
 *
 * lowerCharSegments[p].a = 1; p: 0-6ig a 7db karakter, a betűk a szegmensek
 * SegmentLCD_LowerSegments(lowerCharSegments);
 *
 *****************************************************************************/
#include "init_LCD.h"
//#include <sl_udelay.h>


SegmentLCD_LowerCharSegments_TypeDef lowerCharSegments[SEGMENT_LCD_NUM_OF_LOWER_CHARS];

void refreshSnake(kigyo snake)
{

}

void demoSegments(void)
{
  for (uint8_t p = 0; p < SEGMENT_LCD_NUM_OF_LOWER_CHARS; p++) {
        lowerCharSegments[p].a = 1;
        SegmentLCD_LowerSegments(lowerCharSegments);
        //sl_udelay_wait(100000);

        lowerCharSegments[p].b = 1;
        SegmentLCD_LowerSegments(lowerCharSegments);
        //sl_udelay_wait(100000);

        lowerCharSegments[p].c = 1;
        SegmentLCD_LowerSegments(lowerCharSegments);
        //sl_udelay_wait(100000);

        lowerCharSegments[p].d = 1;
        SegmentLCD_LowerSegments(lowerCharSegments);
        //sl_udelay_wait(100000);

        lowerCharSegments[p].e = 1;
        SegmentLCD_LowerSegments(lowerCharSegments);
        //sl_udelay_wait(100000);

        lowerCharSegments[p].f = 1;
        SegmentLCD_LowerSegments(lowerCharSegments);
        //sl_udelay_wait(100000);

        lowerCharSegments[p].g = 1;
        SegmentLCD_LowerSegments(lowerCharSegments);
        //sl_udelay_wait(100000);

        lowerCharSegments[p].h = 1;
        SegmentLCD_LowerSegments(lowerCharSegments);
        //sl_udelay_wait(100000);

        lowerCharSegments[p].j = 1;
        SegmentLCD_LowerSegments(lowerCharSegments);
        //sl_udelay_wait(100000);

        lowerCharSegments[p].k = 1;
        SegmentLCD_LowerSegments(lowerCharSegments);
        //sl_udelay_wait(100000);

        lowerCharSegments[p].m = 1;
        SegmentLCD_LowerSegments(lowerCharSegments);
        //sl_udelay_wait(100000);

        lowerCharSegments[p].n = 1;
        SegmentLCD_LowerSegments(lowerCharSegments);
        //sl_udelay_wait(100000);

        lowerCharSegments[p].p = 1;
        SegmentLCD_LowerSegments(lowerCharSegments);
        //sl_udelay_wait(100000);

        lowerCharSegments[p].q = 1;
        SegmentLCD_LowerSegments(lowerCharSegments);
        //sl_udelay_wait(100000);
   }

   // Clear all segments
   for (uint8_t p = 0; p < SEGMENT_LCD_NUM_OF_LOWER_CHARS; p++) {
      lowerCharSegments[p].raw = 0;
      SegmentLCD_LowerSegments(lowerCharSegments);
   }
}

void demoFasz(void)
{
  lowerCharSegments[0].a = 1;
  lowerCharSegments[0].f = 1;
  lowerCharSegments[0].g = 1;
  lowerCharSegments[0].m = 1;
  lowerCharSegments[0].e = 1;

  lowerCharSegments[1].a = 1;
  lowerCharSegments[1].f = 1;
  lowerCharSegments[1].g = 1;
  lowerCharSegments[1].m = 1;
  lowerCharSegments[1].e = 1;
  lowerCharSegments[1].b = 1;
  lowerCharSegments[1].c = 1;

  lowerCharSegments[2].a = 1;
  lowerCharSegments[2].f = 1;
  lowerCharSegments[2].g = 1;
  lowerCharSegments[2].m = 1;
  lowerCharSegments[2].c = 1;
  lowerCharSegments[2].d = 1;

  lowerCharSegments[3].a = 1;
  lowerCharSegments[3].k = 1;
  lowerCharSegments[3].q = 1;
  lowerCharSegments[3].d = 1;

  lowerCharSegments[4].a = 1;
  lowerCharSegments[4].b = 1;
  lowerCharSegments[4].c = 1;
  lowerCharSegments[4].d = 1;
  lowerCharSegments[4].e = 1;
  lowerCharSegments[4].f = 1;

  lowerCharSegments[5].h = 1;
  lowerCharSegments[5].k = 1;
  lowerCharSegments[5].b = 1;
  lowerCharSegments[5].f = 1;
  lowerCharSegments[5].e = 1;
  lowerCharSegments[5].c = 1;



  SegmentLCD_LowerSegments(lowerCharSegments);
}

