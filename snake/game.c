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
#include "math.h"

void MoveSnake()
{
  //Kigyo osszes szegmensenek mozgatasa
  for(int i=1; i<snake.hossz; i++) //i=1-tol kezdodik, mert a fejet (0.) külön kezeljük
  {
      snake.koordinatak[i]=snake.koordinatak[i-1]; //Mindegyik testresz az elotte levo helyet veszi at
  }
  //Kigyo fejenek iranyvaltasa
//  switch(snake.irany)
//  case RIGHT: snake.koordinatak[0].x += 1 ; //Ha jobbra megy, akkor a fej x koordinatajat növeljuk eggyel
//  case LEFT: snake.koordinatak[0].x -= 1;//Ha balra megy, akkor a fej x koordinatajat csökkentjük eggyel
//  case DOWN: snake.koordinatak[0].y -= 1;//Ha lefele megy, akkor a fej y koordinatajat csökkentjük eggyel
//  case UP: snake.koordinatak[0].y += 1;//Ha jobbra megy, akkor a fej y koordinatajat növeljuk eggyel
//  default: break;
}

void NewApplePosition()
{
  //Random szam generalas
  int newx;
  int newy;

  apple.x=newx;
  apple.y=newy;
  //Megnezzuk hogy a random szam az a kigyora esik-e, vagy a kigyo feje elott van-e, ha igen, akkor uj szam generalasa
  for(int i=0; i<=snake.hossz; i++)
      {
        if(snake.koordinatak[i].x==apple.x && snake.koordinatak[i].y==apple.y)
          {
            NewApplePosition();
          }
      }

}

void AppleIsEated()
{
  for(int i=0; i<=snake.hossz; i++)
    {
      if(snake.koordinatak[i].x==apple.x && snake.koordinatak[i].y==apple.y)
        {
          //score += 1;
          NewApplePosition();
        }
    }
}

void gameInit(){
    //Inicializalasok:

    //Peldanyositott kigyo inicializalasa
    snake.hossz=1; //Kigyo kezdo hossza 1
    snake.irany = RIGHT; //Kigyo kezdo iranya jobbra
    snake.koordinatak[0].x=0; //Kigyo kezdo x koordinataja 0
    snake.koordinatak[0].y=0; //Kigyo kezdo y koordinataja 0
    //score = 0; //Jatekos kezdo pontszama 0

    //Kijelzo tisztitasa
    SegmentLCD_Init(false);

    //demoSegments();
    //demoFasz();

}
void game(){
  //A jatek itt egy teljesen statikus allapotbol indul
    //*Kigyonak van kiterjedese
    //*Kigyonak van iranya
    //Almanak van helye
    //*Jatekosnak van egy pontszama
    //Ezeket mind frissiteni kell

    //Uart beolvasas, hogy irany valtozott-e

    //ITT LEHET VARAKOZTATNI IS KELL, HOGY NE LEPKEDJEN ms-onkent A KIGYO

    //Kigyo mozgatasa az aktualis irany szerint, ami ha nem erkezett uj adat, akkor a regi irany
      MoveSnake();
      //Alma talalat ellenorzese
      AppleIsEated();
      //Kijelzo frissitese az uj adatokkal
      LcdUpdate(snake);
}