#ifndef INIT_H_
#define INIT_H_

int Area(int, int, int, int, int, int, int, int);
Serpent* Init(int, int, int);
Serpent* Init_other(int, int, int, Serpent*);

void Color(Serpent*);

int Match(int, int, Serpent*);
int Random(int, int);

#endif
