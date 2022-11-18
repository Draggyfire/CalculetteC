#ifndef PILE_H
#define PILE_H
#define MAXSP 100

typedef struct {
  int e[MAXSP];
  int st;
} Pile;

void initPileVide(Pile *);
int estPileVide(Pile );
void empiler(Pile *, int );
void depiler(Pile *);
int elementSommetPile(Pile );
#endif
