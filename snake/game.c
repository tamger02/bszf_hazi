/*
 * game.c
 *
 *  Created on: 13 Nov 2024
 *      Author: dbura
 */

#include "game.h"
#include "Objects.h"
#include "em_device.h"
#include "em_cmu.h"
#include "init_LCD.h"
#include "stdlib.h"
#include "math.h"
#include "stdio.h"
#include "time.h"
#include "randomnumbers.h"

void MoveSnake(kigyo* snake)
{
  //Kigyo osszes szegmensenek mozgatasa
  if(JustAte)
    {
      (*snake).hossz += 1;
      for(int i=(*snake).hossz; i>0; i--) //i=1-tol kezdodik, mert a fejet (0.) külön kezeljük
            {
                (*snake).koordinatak[i]=(*snake).koordinatak[i-1]; //Mindegyik testresz az elotte levo helyet veszi at
            }
    }

  if(!JustAte)
  {
      for(int i=(*snake).hossz; i>0; i--) //i=1-tol kezdodik, mert a fejet (0.) külön kezeljük
                  {
                      (*snake).koordinatak[i]=(*snake).koordinatak[i-1]; //Mindegyik testresz az elotte levo helyet veszi at
                  }
  }
  JustAte = 0;
  //Kigyo fejenek iranyvaltasa
  switch(*((*snake).elozoirany))
  {
  case RIGHT:
  {
    switch(*((*snake).irany))
    {
      case RIGHT:
        {
          if((*snake).koordinatak[0].x == 6)
          {
              (*snake).koordinatak[0].x = 0;
          }
          else if((*snake).koordinatak[0].y != 1 || (*snake).koordinatak[0].y != 3 || (*snake).koordinatak[0].y != 5 || (*snake).koordinatak[0].y != 6)
          {
            (*snake).koordinatak[0].x +=1;
          }
        }break;
      case DOWN:
        {
          if((*snake).koordinatak[0].x==6)
            {
              if((*snake).koordinatak[0].y == 0)
                {
                  (*snake).koordinatak[0].y=5;
                }
              else if((*snake).koordinatak[0].y == 4)
                {
                (*snake).koordinatak[0].y=5;
                }
              else
                {
                  (*snake).koordinatak[0].y=6;
                }
            }
          else
            {
            if((*snake).koordinatak[0].y == 4 ||(*snake).koordinatak[0].y ==0)
              {
                (*snake).koordinatak[0].y = 1;
              }
            else if((*snake).koordinatak[0].y == 2)
              {
                (*snake).koordinatak[0].y = 3;
              }

            (*snake).koordinatak[0].x +=1;

            }
        }break;
      case UP:
        {
          if((*snake).koordinatak[0].x==6)
            {
              if((*snake).koordinatak[0].y == 0 || (*snake).koordinatak[0].y == 4)
                {
                  (*snake).koordinatak[0].y=6;
                }
              else
                {
                  (*snake).koordinatak[0].y = 5;
                }
            }
            else
              {
              if((*snake).koordinatak[0].y == 0 ||(*snake).koordinatak[0].y == 4)
                {
                  (*snake).koordinatak[0].y = 3;
                }
              else if((*snake).koordinatak[0].y == 2)
                {
                  (*snake).koordinatak[0].y = 1;
                }

              (*snake).koordinatak[0].x +=1;
              }
        }break;
    default: break;
   }break;
   case LEFT:
   {
      switch(*((*snake).irany))
      {
      case LEFT:
        {
          if((*snake).koordinatak[0].x == 0)
            {
              (*snake).koordinatak[0].x = 6;
            }
          else if((*snake).koordinatak[0].y != 1 || (*snake).koordinatak[0].y != 3 || (*snake).koordinatak[0].y != 5 || (*snake).koordinatak[0].y != 6)
          {
              (*snake).koordinatak[0].x -= 1;
          }
        }break;
      case DOWN:
        {
          if((*snake).koordinatak[0].y == 4)
            {
              (*snake).koordinatak[0].y = 1;
            }
          else
            {
              (*snake).koordinatak[0].y += 1;
            }
        }break;
      case UP:
        {
          if((*snake).koordinatak[0].y == 0)
            {
              (*snake).koordinatak[0].y = 3;
            }
          else
            {
              (*snake).koordinatak[0].y -= 1;
            }
        }break;
      default: break;}
   } break;
   case DOWN:
   {
      switch(*((*snake).irany))
      {
      case RIGHT:
        {
          if((*snake).koordinatak[0].x == 6 && (*snake).koordinatak[0].y == 5)
          {
            (*snake).koordinatak[0].x = 0;
            (*snake).koordinatak[0].y = 2;
          }
          else if((*snake).koordinatak[0].x == 6 && (*snake).koordinatak[0].y == 6)
          {
                (*snake).koordinatak[0].x = 0;
                (*snake).koordinatak[0].y = 4;
          }
          else
            {
              (*snake).koordinatak[0].y += 1;
            }
        }break;
      case LEFT:
        {
          if((*snake).koordinatak[0].x == 0 && (*snake).koordinatak[0].y == 1)
          {
            (*snake).koordinatak[0].x=6;
            (*snake).koordinatak[0].y=2;
          }
          else if((*snake).koordinatak[0].x == 0 && (*snake).koordinatak[0].y == 3)
          {
            (*snake).koordinatak[0].x=6;
            (*snake).koordinatak[0].y=4;
          }
          else if((*snake).koordinatak[0].x == 6 && (*snake).koordinatak[0].y == 6)
          {
              (*snake).koordinatak[0].y=4;
          }
          else if((*snake).koordinatak[0].x == 6 && (*snake).koordinatak[0].y == 5)
          {
              (*snake).koordinatak[0].y=2;
          }
          else
          {
            (*snake).koordinatak[0].x -=1;
            (*snake).koordinatak[0].y +=1;
          }
        }break;
       case DOWN:
         {
           if((*snake).koordinatak[0].x == 6)
             {
               if((*snake).koordinatak[0].y == 5)
                 (*snake).koordinatak[0].y = 6;
               else if((*snake).koordinatak[0].y == 6)
                 (*snake).koordinatak[0].y = 5;
               else //!!!!
                 {
                 if((*snake).koordinatak[0].y == 1)
                   (*snake).koordinatak[0].y = 3;
                 else
                   (*snake).koordinatak[0].y = 1;
                 }
             }
           else
             if((*snake).koordinatak[0].y == 1)
               {
                 (*snake).koordinatak[0].y = 3;
               }
             else
               {
                 (*snake).koordinatak[0].y = 1;
               }
         }break ;
    default: break;}
   }break;
   case UP:
   {
      switch(*((*snake).irany))
      {
        case RIGHT:
          {
            if((*snake).koordinatak[0].x == 6 && (*snake).koordinatak[0].y == 5)
              {
                (*snake).koordinatak[0].x = 0;
                (*snake).koordinatak[0].y = 0;
              }
            else if((*snake).koordinatak[0].x == 6 && (*snake).koordinatak[0].y == 6)
              {
                (*snake).koordinatak[0].x = 0;
                (*snake).koordinatak[0].y = 2;
              }
            else
              {
                (*snake).koordinatak[0].y -= 1;
              }
          }break;
        case LEFT:
          {
            if((*snake).koordinatak[0].x == 0 && (*snake).koordinatak[0].y == 1)
              {
                (*snake).koordinatak[0].x = 6;
                (*snake).koordinatak[0].y = 0;
              }
            else if((*snake).koordinatak[0].x == 0 && (*snake).koordinatak[0].y == 3)
              {
                (*snake).koordinatak[0].x=6;
                (*snake).koordinatak[0].y =2;
              }
            else if((*snake).koordinatak[0].x == 6 && (*snake).koordinatak[0].y == 5)
              {
                (*snake).koordinatak[0].x = 6;
                (*snake).koordinatak[0].y = 0;
              }
            else if((*snake).koordinatak[0].x == 6 && (*snake).koordinatak[0].y == 6)
              {
                            (*snake).koordinatak[0].x = 6;
                            (*snake).koordinatak[0].y = 2;
              }
            else
              {
                (*snake).koordinatak[0].x -= 1;
                (*snake).koordinatak[0].y -= 1;
              }
          }break;
        case UP:
          {
            if((*snake).koordinatak[0].x == 6)
              {
                if((*snake).koordinatak[0].y == 6)
                  {
                    (*snake).koordinatak[0].y = 5;
                  }
                else if((*snake).koordinatak[0].y == 5)
                  {
                    (*snake).koordinatak[0].y = 6;
                  }
                else
                  if((*snake).koordinatak[0].y == 1)
                      {
                      (*snake).koordinatak[0].y = 3;
                      }
                  else
                      {
                      (*snake).koordinatak[0].y = 1;
                      }
              }
            else
              if((*snake).koordinatak[0].y == 1)
                {
                  (*snake).koordinatak[0].y = 3;
                }
              else
                {
                  (*snake).koordinatak[0].y = 1;
                }
          }break;
         default: break;}
   }break;
   default: break;
   }break;
  }
  refreshSnake(*snake);
}


void NewApplePosition(alma* apple, kigyo* snake)
{

  //Random szam generalas
  int newx;
  int newy;
  if(iterate == 49)
    {
      iterate=0;
    }
  newx = randomnumbers[iterate];
  iterate += 1;
      if(iterate == 49)
          {
            iterate=0;
          }
  newy = randomnumbers[iterate];
  iterate +=1;
  apple->x=newx;
  apple->y=newy;
  //Megnezzuk hogy a random szam az a kigyora esik-e, vagy a kigyo feje elott van-e, ha igen, akkor uj szam generalasa
  for(int i=0; i<=snake->hossz; i++)
      {
        if(snake->koordinatak[i].x==apple->x && snake->koordinatak[i].y==apple->y)
          {
            NewApplePosition(apple, snake);
          }
        if((snake->koordinatak[i].x+1)==apple->x && (snake->koordinatak[i].y+1)==apple->y)
                  {
                    NewApplePosition(apple, snake);
                  }
      }
}

void AppleIsEated(kigyo* snake, alma* apple)
{
  for(int i=0; i<(*snake).hossz; i++)
    {
      if((*snake).koordinatak[i].x==(*apple).x && (*snake).koordinatak[i].y==apple->y)
        {
          JustAte = 1;
          NewApplePosition(apple, snake);
          refreshSnake(snake, apple);
        }
    }
}

void HitDetect(alma apple, kigyo* snake)
{
  for(int i = 1; i<(*snake).hossz; i++)
    {

      if(((*snake).koordinatak[i].x == (*snake).koordinatak[0].x) && ((*snake).koordinatak[i].y == (*snake).koordinatak[0].y))
        {
          //HIT!
          //Pontok villogtatasa + felso kijelzon hossz kiirasa
          //Itt mar nem is ter vissza a program a fo menetebe
          while(1)
            {
              clearLCD();
              SegmentLCD_Symbol(LCD_SYMBOL_DP2,1);
              SegmentLCD_Symbol(LCD_SYMBOL_DP3,1);
              SegmentLCD_Symbol(LCD_SYMBOL_DP4,1);
              SegmentLCD_Symbol(LCD_SYMBOL_DP5,1);
              SegmentLCD_Symbol(LCD_SYMBOL_DP6,1);
              sl_udelay_wait(500000);
              SegmentLCD_Symbol(LCD_SYMBOL_DP2,0);
              SegmentLCD_Symbol(LCD_SYMBOL_DP3,0);
              SegmentLCD_Symbol(LCD_SYMBOL_DP4,0);
              SegmentLCD_Symbol(LCD_SYMBOL_DP5,0);
              SegmentLCD_Symbol(LCD_SYMBOL_DP6,0);
              sl_udelay_wait(500000);

            }
        }
     }
      /*
      else
        {
          for(int i = 1; i<(*snake).hossz; i++)
            {
              switch(*((*snake).irany))
              {
                case UP:
                  {
                    if(((* snake).koordinatak[i - 1].y==(* snake).koordinatak[i].y)&&(((* snake).koordinatak[i - 1].x==(* snake).koordinatak[0].x)||((* snake).koordinatak[i].x==(* snake).koordinatak[0].x)))
                    {

                        //HIT!
                        //Pontok villogtatasa + felso kijelzon hossz kiirasa
                        //Itt mar nem is ter vissza a program a fo menetebe
                    }
                    else if(((*snake).koordinatak[i-1].x == 6 && (*snake).koordinatak[i].x==0)||(*snake).koordinatak[i-1].x == 0 && (*snake).koordinatak[i].x==6)
                    {
                        if(((*snake).koordinatak[i].y==0||(*snake).koordinatak[i].y==4) && (*snake).koordinatak[0].y==5)
                          {
                            //HIT!
                            //Pontok villogtatasa + felso kijelzon hossz kiirasa
                            //Itt mar nem is ter vissza a program a fo menetebe
                          }
                        else if((*snake).koordinatak[i].y==2 && (*snake).koordinatak[0].y==6)
                          {
                            //HIT!
                            //Pontok villogtatasa + felso kijelzon hossz kiirasa
                            //Itt mar nem is ter vissza a program a fo menetebe
                          }
                   }


                  }break;
                case DOWN:
                  {
                    if(((* snake).koordinatak[i - 1].y==(* snake).koordinatak[i].y)&&(((* snake).koordinatak[i - 1].x==(* snake).koordinatak[0].x)||((* snake).koordinatak[i].x==(* snake).koordinatak[0].x)))
                    {
                        //HIT!
                        //Pontok villogtatasa + felso kijelzon hossz kiirasa
                        //Itt mar nem is ter vissza a program a fo menetebe
                        //itt ha a szelen van akkor nem erzekeli
                    }
                    else if(((*snake).koordinatak[i-1].x == 6 && (*snake).koordinatak[i].x==0)||(*snake).koordinatak[i-1].x == 0 && (*snake).koordinatak[i].x==6)
                    {
                    if((*snake).koordinatak[i].y==0 && (*snake).koordinatak[0].y==5)
                    {
                        //HIT!
                        //Pontok villogtatasa + felso kijelzon hossz kiirasa
                        //Itt mar nem is ter vissza a program a fo menetebe
                    }
                    else if((*snake).koordinatak[i].y==2 && (*snake).koordinatak[0].y==6)
                    {
                        //HIT!
                        //Pontok villogtatasa + felso kijelzon hossz kiirasa
                        //Itt mar nem is ter vissza a program a fo menetebe
                    }
                    }

                  }break;
                case LEFT:
                  {
                    if(((* snake).koordinatak[0].y==2)) //Ha kozepen van, amugy szelen amugy is belemegy a kigyoba
                      {
                        if((* snake).koordinatak[i - 1].x==(* snake).koordinatak[i].x) //Ha egy szegmenshataron fuggolegesen
                            {
                               if(((* snake).koordinatak[i - 1].x==1 && (* snake).koordinatak[i].x==3)||((* snake).koordinatak[i - 1].x==3 && (* snake).koordinatak[i].x==1))
                                 {
                                   //HIT!
                                   //Pontok villogtatasa + felso kijelzon hossz kiirasa
                                   //Itt mar nem is ter vissza a program a fo menetebe
                                 }
                       }
                     }
                  }break;
                case RIGHT:
                  {
                    if(((* snake).koordinatak[0].y==2)) //Ha kozepen van, amugy szelen amugy is belemegy a kigyoba
                      {
                         if((* snake).koordinatak[i - 1].x==(* snake).koordinatak[i].x) //Ha egy szegmenshataron fuggolegesen
                         {
                             if(((* snake).koordinatak[i - 1].x==1 && (* snake).koordinatak[i].x==3)||((* snake).koordinatak[i - 1].x==3 && (* snake).koordinatak[i].x==1))
                               {
                                 //HIT!
                                 //Pontok villogtatasa + felso kijelzon hossz kiirasa
                                 //Itt mar nem is ter vissza a program a fo menetebe
                               }
                         }
                      }
                  }break;
                default: break;
              }break;
            }
        }*/


}

void initrandomnumbers()
{
  randomnumbers[0] = 2;
  randomnumbers[1] = 2;
  randomnumbers[2] = 5;
  randomnumbers[3] = 0;
  randomnumbers[4] = 0;
  randomnumbers[5] = 1;
  randomnumbers[6] = 3;
  randomnumbers[7] = 2;
  randomnumbers[8] = 2;
  randomnumbers[9] = 4;
  randomnumbers[10] = 6;
  randomnumbers[11] = 0;
  randomnumbers[12] = 2;
  randomnumbers[13] = 3;
  randomnumbers[14] = 4;
  randomnumbers[15] = 1;
  randomnumbers[16] = 5;
  randomnumbers[17] = 2;
  randomnumbers[18] = 3;
  randomnumbers[19] = 0;
  randomnumbers[20] = 4;
  randomnumbers[21] = 4;
  randomnumbers[22] = 1;
  randomnumbers[23] = 2;
  randomnumbers[24] = 2;
  randomnumbers[25] = 0;
  randomnumbers[26] = 3;
  randomnumbers[27] = 3;
  randomnumbers[28] = 4;
  randomnumbers[29] = 1;
  randomnumbers[30] = 2;
  randomnumbers[31] = 3;
  randomnumbers[32] = 2;
  randomnumbers[33] = 0;
  randomnumbers[34] = 0;
  randomnumbers[35] = 1;
  randomnumbers[36] = 0;
  randomnumbers[37] = 2;
  randomnumbers[38] = 4;
  randomnumbers[39] = 3;
  randomnumbers[40] = 3;
  randomnumbers[41] = 1;
  randomnumbers[42] = 0;
  randomnumbers[43] = 4;
  randomnumbers[44] = 4;
  randomnumbers[45] = 3;
  randomnumbers[46] = 2;
  randomnumbers[47] = 0;
  randomnumbers[48] = 0;
  randomnumbers[49] = 0;

}


void gameInit(irany* irany, kigyo* snake, alma* apple)
{
    //Inicializalasok:
    //Kigyo osszes testresztarolojanak kiuritese
    for (int i = 0; i < 50; i++)
      {
        snake->koordinatak[i].x=0;
        snake->koordinatak[i].y=0;
      }
    //Peldanyositott kigyo inicializalasa
    snake->hossz=1; //Kigyo kezdo hossza 1
    snake->koordinatak[0].x=0; //Kigyo kezdo x koordinataja 0
    snake->koordinatak[0].y=2; //Kigyo kezdo y koordinataja 0
    NewApplePosition(apple, snake);
    refreshSnake(*snake, *apple);
    refreshPoints(*snake);
    delaysome();
}

void delaysome()
{
  sl_udelay_wait(600000);
  }
