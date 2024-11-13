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
#include <sl_udelay.h>
#include "objects.h"


SegmentLCD_LowerCharSegments_TypeDef lowerCharSegments[SEGMENT_LCD_NUM_OF_LOWER_CHARS];

void testLCD(void){
  kigyo snake1;
  alma apple1;
  snake1.koordinatak[0].x = 0;
  snake1.koordinatak[0].y = 0;
  snake1.koordinatak[1].x = 0;
  snake1.koordinatak[1].y = 1;
  snake1.hossz=2;
  apple1.x = 3;
  apple1.y = 2;
  refreshSnake(snake1, apple1);
}

void refreshSnake(kigyo snake, alma apple)
{
  clearLCD();

  for (uint8_t i = 0; i < snake.hossz; i++)
    {
      uint8_t p = snake.koordinatak[i].x;
      switch (snake.koordinatak[i].y)
      {
        case 0: { lowerCharSegments[p].a = 1; } break;
        case 1: { lowerCharSegments[p].f = 1; } break;
        case 2: { lowerCharSegments[p].g = 1; lowerCharSegments[p].m = 1;} break;
        case 3: { lowerCharSegments[p].e = 1; } break;
        case 4: { lowerCharSegments[p].d = 1; } break;
        case 5: { lowerCharSegments[p].b = 1; } break;
        case 6: { lowerCharSegments[p].c = 1; } break;
      }
    }
  uint8_t q = apple.x;
  switch (apple.y)
        {
          case 0: { lowerCharSegments[q].a = 1; } break;
          case 1: { lowerCharSegments[q].f = 1; } break;
          case 2: { lowerCharSegments[q].g = 1; lowerCharSegments[q].m = 1;} break;
          case 3: { lowerCharSegments[q].e = 1; } break;
          case 4: { lowerCharSegments[q].d = 1; } break;
          case 5: { lowerCharSegments[q].b = 1; } break;
          case 6: { lowerCharSegments[q].c = 1; } break;
        }

  SegmentLCD_LowerSegments(lowerCharSegments);
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

void clearLCD(void)
{
  for (uint8_t p = 0; p < SEGMENT_LCD_NUM_OF_LOWER_CHARS; p++) {
        lowerCharSegments[p].raw = 0;
        SegmentLCD_LowerSegments(lowerCharSegments);
     }
}}
