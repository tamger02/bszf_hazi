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
/**************************************************************************//**
 * @brief
 * Defines each text symbol's segment in terms of COM and BIT numbers,
 * in a way that we can enumerate each bit for each text segment in the
 * following bit pattern:
 * @verbatim
 *  -------0------
 *
 * |   \7  |8  /9 |
 * |5   \  |  /   |1
 *
 *  --6---  ---10--
 *
 * |    /  |  \11 |
 * |4  /13 |12 \  |2
 *
 *  -------3------
 * @endverbatim
 * E.g.: First text character bit pattern #3 (above) is
 * Segment 1D for Display
 * Location COM 3, BIT 0
 *****************************************************************************/
#include "init_LCD.h"
#include <sl_udelay.h>
#include "objects.h"


SegmentLCD_LowerCharSegments_TypeDef lowerCharSegments[SEGMENT_LCD_NUM_OF_LOWER_CHARS];
SegmentLCD_UpperCharSegments_TypeDef upperCharSegments[SEGMENT_LCD_NUM_OF_UPPER_CHARS];

void testLCD(void)    // Tester, legacy
{
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

void refreshPoints(kigyo snake)
{
  SegmentLCD_Number(snake.hossz);
}

void refreshSnake(kigyo snake, alma apple)        // prints the snake and the apples on LCD
{
  clearLCD();   // clear all data from LCD

  for (uint8_t i = 0; i < snake.hossz; i++)     // iterate the whole snake
    {
      uint8_t p = snake.koordinatak[i].x;
      switch (snake.koordinatak[i].y)     // turn on segments for snake
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
  switch (apple.y)                        // turn on segments for apple
        {
          case 0: { lowerCharSegments[apple.x].a = 1; } break;
          case 1: { lowerCharSegments[apple.x].f = 1; } break;
          case 2: { lowerCharSegments[apple.x].g = 1; lowerCharSegments[apple.x].m = 1;} break;
          case 3: { lowerCharSegments[apple.x].e = 1; } break;
          case 4: { lowerCharSegments[apple.x].d = 1; } break;
          case 5: { lowerCharSegments[apple.x].b = 1; } break;
          case 6: { lowerCharSegments[apple.x].c = 1; } break;
        }

  SegmentLCD_LowerSegments(lowerCharSegments);    // refresh lower segments
}
void demoSegments(void)	    // LCD tester function
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

void demoUpperSegments() {
   // Turn on all segments one-by-one
   // Only one segment is turned on at any given time
   // Using 7 bit binary (raw) value
   for (uint8_t p = 0; p < SEGMENT_LCD_NUM_OF_UPPER_CHARS; p++) {
      for (uint8_t s = 0; s < 8; s++) {
         upperCharSegments[p].raw = 1 << s;
         SegmentLCD_UpperSegments(upperCharSegments);
         sl_udelay_wait(100000);
      }
   }

   // Turn on all segments one-by-one
   // All the previous segments are left turned on
   // Using dedicated (bit field) values
   for (uint8_t p = 0; p < SEGMENT_LCD_NUM_OF_UPPER_CHARS; p++) {
      upperCharSegments[p].a = 1;
      SegmentLCD_UpperSegments(upperCharSegments);
      sl_udelay_wait(100000);

      upperCharSegments[p].b = 1;
      SegmentLCD_UpperSegments(upperCharSegments);
      sl_udelay_wait(100000);

      upperCharSegments[p].c = 1;
      SegmentLCD_UpperSegments(upperCharSegments);
      sl_udelay_wait(100000);

      upperCharSegments[p].d = 1;
      SegmentLCD_UpperSegments(upperCharSegments);
      sl_udelay_wait(100000);

      upperCharSegments[p].e = 1;
      SegmentLCD_UpperSegments(upperCharSegments);
      sl_udelay_wait(100000);

      upperCharSegments[p].f = 1;
      SegmentLCD_UpperSegments(upperCharSegments);
      sl_udelay_wait(100000);

      upperCharSegments[p].g = 1;
      SegmentLCD_UpperSegments(upperCharSegments);
      sl_udelay_wait(100000);
   }

   // Clear all segments
   for (uint8_t p = 0; p < SEGMENT_LCD_NUM_OF_UPPER_CHARS; p++) {
      upperCharSegments[p].raw = 0;
      SegmentLCD_UpperSegments(upperCharSegments);
   }
}

void clearLCD(void)         // Clears all the segments
{
  for (uint8_t p = 0; p < SEGMENT_LCD_NUM_OF_LOWER_CHARS; p++) {
        lowerCharSegments[p].raw = 0;
        SegmentLCD_LowerSegments(lowerCharSegments);
     }
}
