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

void MoveSnake(kigyo* snake)
{
  //Kigyo osszes szegmensenek mozgatasa
  if(!JustAte)
  {
      for(int i=1; i<(*snake).hossz; i++) //i=1-tol kezdodik, mert a fejet (0.) külön kezeljük
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
              (*snake).koordinatak[0].x +=1;
            }
          if((*snake).koordinatak[0].y == 4)
            {
              (*snake).koordinatak[0].y = 1;
            }
          else if((*snake).koordinatak[0].x!=6)
            {
              (*snake).koordinatak[0].y += 1;
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
              (*snake).koordinatak[0].x +=1;
            }
          if((*snake).koordinatak[0].y == 0)
            {
              (*snake).koordinatak[0].y = 3;
            }
          else if((*snake).koordinatak[0].x!=6)
            {
              (*snake).koordinatak[0].y -= 1;
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
void NewApplePosition(alma apple, kigyo snake)
{
  //Random szam generalas
  int newx;
  int newy;
  int xmax = 6;
  int ymax = 6;
  newx = rand() % (xmax+1);
  newy = rand() % (ymax +1);
  apple.x=newx;
  apple.y=newy;
  //Megnezzuk hogy a random szam az a kigyora esik-e, vagy a kigyo feje elott van-e, ha igen, akkor uj szam generalasa
  for(int i=0; i<=snake.hossz; i++)
      {
        if(snake.koordinatak[i].x==apple.x && snake.koordinatak[i].y==apple.y)
        {
            NewApplePosition(apple, snake);
        }
        if((snake.koordinatak[i].x+1)==apple.x && (snake.koordinatak[i].y+1)==apple.y)
        {
            NewApplePosition(apple, snake);
        }
      }

}

void AppleIsEated(alma apple, kigyo snake)
{
  for(int i=0; i<=snake.hossz; i++)
    {
      if(snake.koordinatak[i].x==apple.x && snake.koordinatak[i].y==apple.y)
        {
          JustAte = 1;
          NewApplePosition(apple, snake);
        }
    }
}

void HitDetect(alma apple, kigyo snake)
{
  for(int i = 1; i<snake.hossz; i++)
    {
      //EZ IGY NEM JO!!!!
      if((snake.koordinatak[i].x == snake.koordinatak[0].x) && (snake.koordinatak[i].y == snake.koordinatak[0].y))
        {
          //HIT!
          //Pontok villogtatasa + felso kijelzon hossz kiirasa
          //Itt mar nem is ter vissza a program a fo menetebe
        }
    }
}

void gameInit(irany* irany, kigyo* snake)
{
    //Inicializalasok:
    for (int i = 0; i < 50; i++)
      {
        snake->koordinatak[i].x=0;
        snake->koordinatak[i].y=0;
      }
    //Peldanyositott kigyo inicializalasa
    snake->hossz=1; //Kigyo kezdo hossza 1
    //snake->irany = &irany; //Kigyo kezdo iranya jobbra

    snake->koordinatak[0].x=0; //Kigyo kezdo x koordinataja 0
    snake->koordinatak[0].y=2; //Kigyo kezdo y koordinataja 0
    //score = 0; //Jatekos kezdo pontszama 0

    //Kijelzo tisztitasa
    //SegmentLCD_Init(false);
    refreshSnake(*snake);
}

void game(kigyo* snake)
{
  //A jatek itt egy teljesen statikus allapotbol indul
    //*Kigyonak van kiterjedese
    //*Kigyonak van iranya
    //Almanak van helye
    //*Jatekosnak van egy pontszama
    //Ezeket mind frissiteni kell

    //Kigyo mozgatasa az aktualis irany szerint, ami ha nem erkezett uj adat, akkor a regi irany
      MoveSnake(&snake);
      //Talalat erzekelese
      //HitDetect();
      //Alma talalat ellenorzese
      //AppleIsEated();
}

void delaygeci()
{
  sl_udelay_wait(2000000);
  }
