#ifndef PILE_C
#define PILE_C
#include "pile.h"

void initPileVide(Pile *p){
	p->st=-1;
}

int estPileVide(Pile p){
	return p.st==-1;
}

void empiler(Pile *p, int x){
	p->st++;
	p->e[p->st] = x;
}

void depiler(Pile *p){
	p->st--;
}

int elementSommetPile(Pile p){
	return p.e[p.st];
}
#endif
