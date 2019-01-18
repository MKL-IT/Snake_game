
#include "interface.h"
#include "serpent.h"
#include "init.h"

int Menu(int length, int width, int apple, int size, int score, int level, int block, int speed){

  ChargerImage("menu_x.jpg", 0, 0, 0, 0, 1000, 550);

  int go_on =  1;
  int touch = 0;

  while(go_on){

    if(ToucheEnAttente() == 1)
      touch = Touche();
    
		//fermeture de la fenêtre graphique
    if(touch == XK_Escape){
      break;

		//initialisation du terrain et lancement du jeu
    }else if(touch == XK_s){
      EffacerEcran(black);
      return Area(length, width, apple, size, score, level, block, speed);
		
		//page de configuration
    }else if(touch == XK_c){
      EffacerEcran(black);
      return Config(length, width, apple, size, score, level, block, speed);
    }
    
  }
  return 0;
}


int Config(int length, int width, int apple, int size, int score, int level, int block, int speed){

  ChargerImage("config.jpg", 0, 0, 0, 0, 1000, 550);
  ChargerImage("back.png", 5, 0, 0, 0, 120, 85);
  
  int a, b;
  int h = length, i = width, j = apple, k = size;
  char lg[3];
  char wd[3];
  char app[3];
  char sz[3];
  int touch = 0;

  ChoisirCouleurDessin(white);

  //length
  sprintf(lg, "%d", h);
  EcrireTexte(538,203,lg,2);

  //width
  sprintf(wd, "%d", i);
  EcrireTexte(538,275,wd,2);

  //apple
  sprintf(app, "%d", j);
  EcrireTexte(538,340,app,2);

  //size
  sprintf(sz, "%d", k);
  EcrireTexte(540,405,sz,2);



  int go_on = 1;

  while(go_on) {   

    if(ToucheEnAttente() == 1)
      touch = Touche();

		//fermeture de la fenêtre
    if(touch == XK_Escape)
      break;

		//réduction de la taille du serpent en fonction du nombre de colonnes
    if(k > h/2){
      while(k >= h/2){
				k--;
      }

      ChoisirCouleurDessin(black);
      RemplirRectangle(530,377,50,40);
      k++;
      sprintf(sz, "%d", k);
      ChoisirCouleurDessin(white);
      EcrireTexte(540,405,sz,2);
    }

    if(SourisCliquee()) {
      SourisPosition();
      a = _X;
      b = _Y;
      
      //length--
      if(a < 506 && a > 470 && b < 220 && b > 172){

	if(h-1 >= 15){
	  ChoisirCouleurDessin(black);
	  RemplirRectangle(530,175,50,40);
	  h--;
	  sprintf(lg, "%d", h);
	  ChoisirCouleurDessin(white);
	  EcrireTexte(538,203,lg,2);
	}
			
	//length++
      }else if(a < 630 && a > 595 && b < 220 && b > 172){

	if( h+1 <= 70){
	  ChoisirCouleurDessin(black);
	  RemplirRectangle(530,175,50,40);
	  h++;
	  sprintf(lg, "%d", h);
	  ChoisirCouleurDessin(white);
	  EcrireTexte(538,203,lg,2);
	}
	
	
	//width--
      }else if(a < 504 && a > 467 && b < 290 && b > 242){

	if(i-1 >= 10){
	  ChoisirCouleurDessin(black);
	  RemplirRectangle(530,245,50,40);
	  i--;
	  sprintf(wd, "%d", i);
	  ChoisirCouleurDessin(white);
	  EcrireTexte(538,275,wd,2);
	}

	
	//width++
      }else if(a < 630 && a > 595 && b < 290 && b > 242){

	if(i+1 <= 42){
	  ChoisirCouleurDessin(black);
	  RemplirRectangle(530,245,50,40);
	  i++;
	  sprintf(wd, "%d", i);
	  ChoisirCouleurDessin(white);
	  EcrireTexte(538,275,wd,2);
	}

	//apple--
      }else if(a < 506 && a > 470 && b < 355 && b > 307){

	if(j-1 >= 1){
	  ChoisirCouleurDessin(black);
	  RemplirRectangle(530,309,50,40);
	  j--;
	  sprintf(app, "%d", j);
	  ChoisirCouleurDessin(white);
	  EcrireTexte(538,340,app,2);
	}

	
	//apple++
      }else if(a < 630 && a > 595 && b < 355 && b > 306){
	
	if(j+1 <= 15){
	  ChoisirCouleurDessin(black);
	  RemplirRectangle(530,309,50,40);
	  j++;
	  sprintf(app, "%d", j);
	  ChoisirCouleurDessin(white);
	  EcrireTexte(538,340,app,2);
	}
	
	//size--
      }else if(a < 503 && a > 469 && b < 420 && b > 372){

	if(k-1 >= 1){
	  ChoisirCouleurDessin(black);
	  RemplirRectangle(530,377,50,40);
	  k--;
	  sprintf(sz, "%d", k);
	  ChoisirCouleurDessin(white);
	  EcrireTexte(540,405,sz,2);
	}
	
	//size++
      }else if(a < 630 && a > 595 && b < 416 && b > 370){
	
	if(k+1 <= 20 && k < (h/2) ){
	  ChoisirCouleurDessin(black);
	  RemplirRectangle(530,377,50,40);
	  k++;
	  sprintf(sz, "%d", k);
	  ChoisirCouleurDessin(white);
	  EcrireTexte(540,405,sz,2);
	}
    
	//play
      }else if(a < 546 && a > 406 && b < 506 && b > 445){
	EffacerEcran(black);
	Area(h, i, j, k, score, level, block, speed);


	//back
      }else if(a < 120 && a > 10 && b < 85 && b > 5){
	EffacerEcran(black);
	Menu(h, i, j, k, score, level, block, speed);
      }
      
    }
      
  }
  return 0;
}



int Pause(int length, int width, int apple, int size, int score, int level, int block, int speed, Serpent* sp, Serpent* food, Serpent* death, Serpent* no_food, int rest, char Direc){

  ChargerImage("pause_x.jpg", (Fx-426)/2, (Fy-426)/2, 0, 0, 426, 426);

  int go_on = 1;
  int touch = 0; 

  while(go_on){

    touch = Touche();

		//fermeture de la fenêtre
    if(touch == XK_Escape)
      break;

		//retour sur le menu
    if(touch == XK_m)
      return Menu(60, 40, 5, 10, 0, 1, 0, 1000000);
		
		//retour sur le jeu
    if(touch == XK_space){
      EffacerEcran(black);
      CopierZone(1, 0, 0, 0, Fx, Fy, 0, 0);
      ChoisirEcran(1);
      EffacerEcran(black);
      ChoisirEcran(0);
      return Move(length, width, apple, size, score, level, block, speed, sp, food, death, no_food, rest, Direc);
    }
  }
  return 0;

}


int Over(int level, int score){

  ChargerImage("over.jpg", 0, 0, 0, 0, Fx, Fy);

  int go_on=1, touch=0;

  char lv[3];
  char sc[3];

	//affichage niveau et score
  ChoisirCouleurDessin(green);
  sprintf(lv, "%d", level);
  EcrireTexte(555,275,lv,2);
  ChoisirCouleurDessin(red);
  sprintf(sc, "%d", score);
  EcrireTexte(560, 330,sc,2);


  while(go_on){

    if(ToucheEnAttente() == 1)
      touch = Touche();

		//fermeture de la fenêtre
    if(touch == XK_Escape)
      break;
		
		//retour sur le menu
    if(touch == XK_m)
      return Menu(60, 40, 5, 10, 0, 1, 0, 1000000);
  }
  return 0;
}


int Next(int length, int width, int apple, int size, int score, int level, int block, int speed){

  ChargerImage("next_level.jpg", 0, 0, 0, 0, Fx, Fy);
	
  char lv[3];
  char sc[3];

	//affichage niveau et score
  ChoisirCouleurDessin(red);
  sprintf(lv, "%d", level);
  EcrireTexte(460,250,lv,2);
  ChoisirCouleurDessin(green);
  sprintf(sc, "%d", score);
  EcrireTexte(540,305,sc,2);

  int go_on = 1, touch;

  while(go_on){
	
    touch = Touche();
	
		//fermeture de la fenêtre
    if(touch == XK_Escape)
      break;

		//initialisation du terrain et lancement du niveau supérieur
    if(touch == XK_space){
      EffacerEcran(black);
      Area(length, width, apple+1, size, score, level+1, block+1, speed-(2*speed)/5 );
    }
  }
  return 0;
}
