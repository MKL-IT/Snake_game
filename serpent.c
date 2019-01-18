
#include "interface.h"
#include "serpent.h"
#include "init.h"

void Color_s(Serpent* dessin){

  ChoisirCouleurDessin(green);

  while(dessin->suivant != NULL){
  
    RemplirRectangle(dessin->coord_x, dessin->coord_y, 10, 10);
    dessin = dessin->suivant; 
  }
}


Serpent* Delete_end(Serpent* sp){

  Serpent* tmp = sp;
  Serpent* ptmp = sp;

  while(tmp->suivant != NULL){
    ptmp = tmp;
    tmp = tmp->suivant;
  }
  ptmp->suivant = NULL;
  free(tmp);

  return sp;
}


Serpent* Right(Serpent* sp){

  Serpent* n = malloc(sizeof(Serpent));
  sp = Delete_end(sp);

  n->suivant = sp;
  n->precedent = NULL;
  n->coord_x = sp->coord_x + 11;
  n->coord_y = sp->coord_y;
   
  sp->precedent = n;
  return n;
}

Serpent* Left(Serpent* sp){

  Serpent* n = malloc(sizeof(Serpent));
  sp = Delete_end(sp);

  n->suivant = sp;
  n->precedent = NULL;
  n->coord_x = sp->coord_x - 11;
  n->coord_y = sp->coord_y;
   
  sp->precedent = n;
  return n;
}

Serpent* Up(Serpent* sp){

  Serpent* n = malloc(sizeof(Serpent));
  sp = Delete_end(sp);

  n->suivant = sp;
  n->precedent = NULL;
  n->coord_x = sp->coord_x;
  n->coord_y = sp->coord_y - 11;
  
  sp->precedent = n;
  return n;  
}


Serpent* Down(Serpent* sp){

  Serpent* n = malloc(sizeof(Serpent));
  sp = Delete_end(sp);

  n->suivant = sp;
  n->precedent = NULL;
  n->coord_x = sp->coord_x;
  n->coord_y = sp->coord_y + 11;
   
  sp->precedent = n;
  return n;
  
}

//ajout de 2 segments
Serpent* Eat(Serpent* sp){

  Serpent* tete = sp;

  while(sp->suivant != NULL){
    sp=sp->suivant;
  }

  Serpent* avant = sp->precedent;
  
  Serpent* end1 = malloc(sizeof(Serpent));
  Serpent* end2 = malloc(sizeof(Serpent));

  end1->suivant = end2;
  end2->suivant = NULL;

  end1->precedent = sp;
  end2->precedent = end1;

  sp->suivant = end1;

	//queue du serpent à la verticale allant vers le haut 
  if(avant->coord_x == sp->coord_x && avant->coord_y > sp->coord_y){
    end1->coord_x = sp->coord_x;
    end1->coord_y = sp->coord_y-11;

    end2->coord_x = sp->coord_x;
    end2->coord_y = sp->coord_y-22;
  }

	//queue du serpent à la verticale allant vers le bas 
  if(avant->coord_x == sp->coord_x && avant->coord_y < sp->coord_y){
    end1->coord_x = sp->coord_x;
    end1->coord_y = sp->coord_y+11;

    end2->coord_x = sp->coord_x;
    end2->coord_y = sp->coord_y+22;
  }

	//queue du serpent à la horizontale allant vers la droite 
  if(avant->coord_x > sp->coord_x && avant->coord_y == sp->coord_y){
    end1->coord_x = sp->coord_x-11;
    end1->coord_y = sp->coord_y;

    end2->coord_x = sp->coord_x-22;
    end2->coord_y = sp->coord_y;
  }

	//queue du serpent à la horizontale allant vers la gauche 
  if(avant->coord_x < sp->coord_x && avant->coord_y == sp->coord_y){
    end1->coord_x = sp->coord_x+11;
    end1->coord_y = sp->coord_y;

    end2->coord_x = sp->coord_x+22;
    end2->coord_y = sp->coord_y;
  }
  return tete;  
}

//pastilles mangées
Serpent* Less_food(Serpent* liste, int x, int y){
  
  Serpent* n = malloc(sizeof(Serpent));
  n->suivant = liste;
  n->precedent = NULL;
  n->coord_x = x;
  n->coord_y = y;

  if(liste != NULL){
    liste->precedent = n;
  }
  return n;
} 



int Move(int length, int width, int apple, int size, int score, int level, int block, int speed, Serpent* sp, Serpent* food, Serpent* death, Serpent* no_food, int rest, char Direc){

  int go_on = 1;
  int touch = 0;
  int app;

	//nombre de pastiles mangées
  if(rest == 0)
    app = apple;
  else
    app = rest;

  Serpent* blank = NULL;
  int x = length, y = width;
  x = x*11;
  y = y*11;

  char lv[3];
  char sc[3];

	//effacer nivau et score
  ChoisirCouleurDessin(black);
  RemplirRectangle(10, 40, 70, 20);
  RemplirRectangle(10, 125, 70, 20);

	//affichage niveau et score
  ChoisirCouleurDessin(green);
  sprintf(lv, "%d", level);
  EcrireTexte(20,60,lv,2);
  ChoisirCouleurDessin(red);
  sprintf(sc, "%d", score);
  EcrireTexte(20,145,sc,2);

  while(go_on){

    if(ToucheEnAttente() == 1)
      touch = Touche();
		
		//fermeture de la fenêtre graphique
    if(touch == XK_Escape)
      break;

		//mode pause
    if(touch == XK_space){
      CopierZone(0, 1, 0, 0, Fx, Fy, 0, 0);
      return Pause(length, width, apple, size, score, level, block, speed, sp, food, death, no_food, app, Direc);
    }

		//definir la direction
    if(touch == XK_Right && Direc != 'L'){
      Direc = 'R';
    }else if(touch == XK_Left && Direc != 'R' && Direc != 0){
      Direc = 'L';
    }else if(touch == XK_Up && Direc != 'D'){
      Direc = 'U';
    }else if(touch == XK_Down && Direc != 'U'){
      Direc = 'D';
    }

		//ajout d'un segment en tête selon la direction
    if(Direc == 'R'){
      sp = Right(sp);
    }else if(Direc == 'L'){
      sp = Left(sp);
    }else if(Direc == 'D'){
      sp = Down(sp);
    }else if(Direc == 'U'){
      sp = Up(sp);
    }

		//tête en dehors des limites
    if(sp->coord_x < (Fx-x)/2 || sp->coord_x >= (Fx-x)/2 + x || sp->coord_y < (Fy-y)/2 || sp->coord_y >= (Fy-y)/2 + y){

      EffacerEcran(white);
      return Over(level, score);
    }

		//tête touche le reste de son corps
    if(Match(sp->coord_x, sp->coord_y, sp->suivant)){
      EffacerEcran(white);
      return Over(level, score);
    }

		//tête touche un obstacle
    if(death != NULL && Match(sp->coord_x, sp->coord_y, death)){
      EffacerEcran(white);
      return Over(level, score);
    }

		//serpent mange une pastille
    if(Match(sp->coord_x, sp->coord_y, food) && Match(sp->coord_x, sp->coord_y, no_food) == 0){
      no_food = Less_food(no_food, sp->coord_x, sp->coord_y);
      ChoisirCouleurDessin(black);
      RemplirRectangle(10, 125, 50, 20);
      ChoisirCouleurDessin(red);
      score = score + 5;
      app--;
      sprintf(sc, "%d", score);
      EcrireTexte(20, 145,sc,2);
      sp=Eat(sp);
    }

		//efface le dernier segment
    blank = sp;
    while(blank->suivant != NULL){
      blank = blank->suivant;
    }

    ChoisirCouleurDessin(white);
    RemplirRectangle(blank->coord_x, blank->coord_y, 10, 10);
		
		//dessine le serpent
    Color_s(sp);

		//aucune pastille restante sur terrain: lancement du niveau suivant
    if(app == 0){
      EffacerEcran(black);
      return Next(length, width, apple, size, score, level, block, speed);
    }
    usleep(speed);
		
  }
  return 0;
}
