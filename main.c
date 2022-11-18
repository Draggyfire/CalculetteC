#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pile.h"

void addition(Pile *p){
    int x,y;
    if(estPileVide(*p)){
        printf("Erreur Pile vide\n");
        exit(-1);
    }
    x=elementSommetPile(*p);
    depiler(p);
    if(estPileVide(*p)){
        printf("Erreur Pile vide\n");
        exit(-1);
    }
    y=elementSommetPile(*p);
    depiler(p);
    empiler(p,x+y);
}

void soustraction(Pile *p){
    int x,y;
    if(estPileVide(*p)){
        printf("Erreur Pile vide\n");
        exit(-1);
    }
    x=elementSommetPile(*p);
    depiler(p);

    if(estPileVide(*p)){
        printf("Erreur Pile vide\n");
        exit(-1);
    }
    y=elementSommetPile(*p);
    depiler(p);
    empiler(p,y-x);
}

void multiplication(Pile *p){
    int x,y;
    if(estPileVide(*p)){
        printf("Erreur Pile vide\n");
        exit(-1);
    }
    x=elementSommetPile(*p);
    depiler(p);
    if(estPileVide(*p)){
        printf("Erreur Pile vide\n");
        exit(-1);
    }
    y=elementSommetPile(*p);
    depiler(p);
    empiler(p,x*y);
}

void division(Pile *p){
    int x,y;
    if(estPileVide(*p)){
        printf("Erreur Pile vide\n");
        exit(-1);
    }
    x=elementSommetPile(*p);
    depiler(p);

    if(estPileVide(*p)){
        printf("Erreur Pile vide\n");
        exit(-1);
    }
    y=elementSommetPile(*p);
    if(x==0){
        printf("Erreur Division par 0\n");
        exit(-1);
    }
    depiler(p);
    empiler(p,y/x);

}

void unaire(Pile *p){
    int x;
    if(estPileVide(*p)){
        printf("Erreur Pile vide\n");
        exit(-1);
    }
    x=elementSommetPile(*p);
    depiler(p);
    empiler(p,x*(-1));
}

int main(int argc, char ** argv) {
    Pile p;
    initPileVide(&p);
    for (int i = 1; i < argc; ++i) {
        //printf("%s\n",argv[i]);
        if(atoi(argv[i])){
            //printf("J'empile %s\n",argv[i]);
            empiler(&p,atoi(argv[i]));
        } else if(strcmp(argv[i],"+")==0){
            //printf("Addition\n");
            addition(&p);
        } else if(strcmp(argv[i],"-")==0){
            //printf("Soustraction\n");
            soustraction(&p);
        } else if(strcmp(argv[i],"/")==0){
            //printf("Division\n");
            division(&p);
        } else if(strcmp(argv[i],"*")==0){
            //printf("Multiplication\n");
            multiplication(&p);
        } else if(strcmp(argv[i],"#")==0){
            //printf("Unaire\n");
            unaire(&p);
        }
    }
    int x;
    if(!estPileVide(p)){
        x = elementSommetPile(p);
        depiler(&p);
    }else{
        x = 0;
    }
    if(!estPileVide(p)){
        printf("Erreur Pile");
        exit(-1);
    }
    printf("%d\n",x);
    return 0;
}