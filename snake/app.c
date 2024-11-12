/***************************************************************************//**
 * @file
 * @brief Top level application functions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
void app_init(void)
{
  //Inicializalasok:

  //Peldanyositott kigyo inicializalasa
  snake.hossz=1; //Kigyo kezdo hossza 1
  snake.irany = RIGHT; //Kigyo kezdo iranya jobbra
  snake.koordinatak[0].x=0; //Kigyo kezdo x koordinataja 0
  snake.koordinatak[0].y=0; //Kigyo kezdo y koordinataja 0
  score = 0; //Jatekos kezdo pontszama 0

  //Kijelzo tisztitasa
}

void MoveSnake()
{
  //Kigyo osszes szegmensenek mozgatasa
  for(int i=1; i<snake.hossz; i++) //i=1-tol kezdodik, mert a fejet (0.) külön kezeljük
    {
      snake.koordinatak[i]=snake.koordinatak[i-1]; //Mindegyik testresz az elotte levo helyet veszi at
    }
  //Kigyo fejenek iranyvaltasa
  switch(snake.irany)
  case RIGHT: snake.koordinatak[0].x += 1 ; //Ha jobbra megy, akkor a fej x koordinatajat növeljuk eggyel
  case LEFT: snake.koordinatak[0].x -= 1;//Ha balra megy, akkor a fej x koordinatajat csökkentjük eggyel
  case DOWN: snake.koordinatak[0].y -= 1;//Ha lefele megy, akkor a fej y koordinatajat csökkentjük eggyel
  case UP: snake.koordinatak[0].y += 1;//Ha jobbra megy, akkor a fej y koordinatajat növeljuk eggyel
  default: break;
}

void AppleIsEated()
{

  score += 1;
}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
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

}
