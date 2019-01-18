#include "interface.h"
#include "serpent.h"
#include "init.h"


int Area(int length, int width, int apple, int size, int score, int level, int block, int speed){
  
  ChargerImage("play.jpg", 0, 0, 0, 0, 135, 162);
  ChargerImage("title.jpg", Fx-409, 490, 0, 0, 409, 102);
  
  //dessin du terrain de jeu
  ChoisirCouleurDessin(white);
  RemplirRectangle((Fx-(length*11))/2, (Fy-(width*11))/2, length*11, width*11);
  
  Serpent* a = NULL; //serpent
  Serpent* b = NULL; //pastilles
  Serpent* c = NULL; //obstacles
  Serpent* d = NULL; //pastilles mangées
  
  a = Init(size+1, length, width);
  Color_s(a);

  b = Init_other(apple, length, width, a);
  ChoisirCouleurDessin(red);
  Color(b);
  
  if(block > 0){
    c = Init_other(block, length, width, b);
    ChoisirCouleurDessin(purple);
    Color(c);
  }

  //lancement du jeu
  return Move(length, width, apple, size, score, level, block, speed, a, b, c, d, 0, 0);
  
}


Serpent* Init(int n, int x, int y){
  
  Serpent* a = NULL;
  Serpent* f = NULL;
  Serpent* c = NULL;

  int d, e;
  
  //nombre de colonnes pair ?
  if(x%2 == 0)
    d = Fx/2;
  else
    d = Fx/2 -(Fx/2)%11;
  
  //nombre de lignes pair ?
  if(y%2 == 0)
    e = Fy/2;
  else
    e = Fy/2 - 5;
  
  int i = 0;

  //création de la chaine du serpent en fonctiond de taille n
  while(n > 0){
    a = malloc(sizeof(Serpent));
    a->coord_x = d-(11*i);
    a->coord_y = e;
    a->precedent = f;
    f = a;
    i++;
    n--;
  }
  
  while(f->precedent != NULL){
    
    f->suivant = c;
    c = f;
    f = f->precedent; 
  }
  
  f->suivant = c;
  return f;
}


Serpent* Init_other(int n, int x, int y, Serpent* sp){
  
  srand (time (NULL));
  
  Serpent* a = NULL;
  Serpent* f = NULL;
  Serpent* c = NULL;
  
  int p=(Fx-(x*11))/2;
  int q=(Fy-(y*11))/2;
  int i;
  
  for(; n > 0; n--){
    
    a = malloc(sizeof(Serpent));

    //définir aléatoirement la coordonnée x    
    int X = Random(0, x-1);
    if(x%2 == 0)
      X = p + (11*X);
    else
      X = p + (11*X) + 1;
    
    //définir aléatoirement la coordonnée y 
    int Y = Random(0, y-1);
    if(y%2 == 0)
      Y = q + (11*Y);
    else
      Y = q + (11*Y) + 1;

    //coordonnées déja existantes ?
    if(Match(X, Y, sp) == 0){
      a->coord_x = X;
      a->coord_y = Y;
      a->precedent = f;
      f = a;
      
    }else{
      n++;
    }  
  }
  
  while(f->precedent != NULL){
    
    f->suivant = c;
    c = f;
    f = f->precedent; 
  }
  
  f->suivant = c;
  return f;
}


void Color(Serpent* dessin){
  
  while(dessin->suivant != NULL){
    
    RemplirRectangle(dessin->coord_x, dessin->coord_y, 10, 10);
    dessin = dessin->suivant; 
  }
  RemplirRectangle(dessin->coord_x, dessin->coord_y, 10, 10);
}




int Match(int X, int Y, Serpent* compar){
  
  if(compar == NULL)
    return 0;
  
  for(; compar->suivant != NULL; compar = compar->suivant){
    
    if(X == compar->coord_x  && Y == compar->coord_y){
      return 1;
    }

  }
  
  if(X == compar->coord_x  && Y == compar->coord_y)
    return 1;
  else
    return 0;
}

int Random(int Min, int Max) { 
  return (Min + (rand () % (Max-Min+1))); 
}

