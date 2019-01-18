#ifndef SERPENT_H_
#define SERPENT_H_

void Color_s(Serpent*);
Serpent* Delete_end(Serpent*);
Serpent* Right(Serpent*);
Serpent* Left(Serpent*);
Serpent* Up(Serpent*);
Serpent* Down(Serpent*);
Serpent* Eat(Serpent*);
Serpent* Less_food(Serpent*, int, int);

int Move(int, int, int, int, int, int, int, int, Serpent*, Serpent*, Serpent*, Serpent*, int, char);

#endif
