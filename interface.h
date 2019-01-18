#ifndef INTERFACE_H_
#define INTERFACE_H_

#include<stdlib.h>
#include<graph.h>
#include<stdio.h>
#include<unistd.h>
#include<time.h>

#define Fx 1000
#define Fy 550
#define white CouleurParNom("white")
#define black CouleurParNom("black")
#define green CouleurParNom("green")
#define red CouleurParNom("red")
#define purple CouleurParNom("purple")

typedef struct Serpent Serpent;

struct Serpent {
  int coord_x;
  int coord_y;
  Serpent* suivant;
  Serpent* precedent;
};

int Menu(int, int, int, int, int, int, int, int);
int Config(int, int, int, int, int, int, int, int);
int Pause(int, int, int, int, int, int, int, int, Serpent*, Serpent*, Serpent*, Serpent*, int, char);
int Over(int, int);
int Next(int, int, int, int, int, int, int, int);

#endif
