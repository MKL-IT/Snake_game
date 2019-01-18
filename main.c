
#include "interface.h"

int main(){

InitialiserGraphique();
CreerFenetre(0, 0, Fx, Fy);

int length=60, width=40, apple=5, size=10, score=0, level=1, block=0, speed=200000;

Menu(length, width, apple, size, score, level, block, speed);

FermerGraphique();
return EXIT_SUCCESS;

}
