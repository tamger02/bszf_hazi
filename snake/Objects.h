
/*
 * Objects.h
 *
 *  Created on: 12 Nov 2024
 *      Author: dbura
 */

#ifndef GECKO_SDK_4_4_4_OBJECTS_H_
#define GECKO_SDK_4_4_4_OBJECTS_H_

typedef struct{
    int x;
    int y;
}koordinatak;

typedef enum irany
{
  UP=0,
  RIGHT=1,
  DOWN=2,
  LEFT=3,
}irany;

typedef struct{
  irany irany; // Kigyo fejenek iranya
  koordinatak koordinatak[50]; //0. a fej
  int hossz; //Kigyo hossza
  //Elozo irany?
}kigyo;

typedef struct{
  int x;
  int y;
}alma;

#endif /* GECKO_SDK_4_4_4_OBJECTS_H_ */
