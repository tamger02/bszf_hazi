\mainpage TODO
\image feladat.jpg

Feladat:
========

### Kígyós játék (soros port)
Írjátok meg az alábbi játékot az STK3700-as kártyára! A feladat minél több ennivaló felfalása egy kígyóval.
### Általános szabályok
A pálya az LCD kijelző alfanumerikus részének az ábrán beszínezett szegmenseiből áll. A kígyó a játékkezdetekor egy szegmens hosszú (a középső vízszintes pozíciók esetén a két kis szegmens (G + M)együttesen ér fel egy szegmenssel). A kezdeti pozíció legyen a pálya bal szélének két középső szegmense (azábrán pirossal színezve)! A játék kezdetén helyezzetek el egy véletlenszerűen kiválasztott szegmenset a kígyótestén kívül. Ez jelképezi az ennivalót.

<img src="/Users/gergelytamasy/Documents/bszf_hazi/feladat.jpg">
### A játék meneteA kígyó egy megadott sebességgel induljon el jobbra!A soros porton érkező b karakterrel a kígyófeje forduljon 90°-ot balra, a j karakterrel pedig 90°-ot jobbra!Ha bekapta az ételt, akkor egyszegmenssel növekedjen a kígyó hossza, és gyulladjon ki egy másik, véletlenszerűen választott szegmens akígyó testén kívül. A kijelzőről való lemenetel esetén az átellenes oldalon jöjjön vissza a kígyó!Ellenőrizzétek, hogy a kígyó nem harap-e a saját testébe (nem lép-e arra a pozícióra, ahol már van). Ha igen,megáll a játék, és villogtassa a tizedes pontokat. A kígyó aktuális hosszát mindig jelezzétek ki aszámkijelzőn! (Szorgalmi feladatként az is ellenőrizhető, hogy a kígyó keresztbe nem harapja-e meg magát.)

# TODO:

- UART init [x]
- keys 'b' and 'j' []
- LCD init []
- Game mech []
- 