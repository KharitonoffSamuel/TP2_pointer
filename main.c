#include "stdio.h"
#include "stdlib.h"

//Structure du monome
typedef struct monome
{
  int coeff ;
  int exp ;
  struct monome *suivant;
} Monome ;

typedef struct
{
  Monome *premier;
} Polynome ;

typedef struct ELement ELement;
struct Element
{
  int nombre;
  ELement *suivant;
};

typedef struct Liste Liste
{
  
}

int main(void){

  
  Liste *maListe = initialisation();
  
  afficherListe(maListe);

  return 1;
}

Polynome *newPolynome()
{
    //ALlocation mémoire du polynome et du premier terme
    Polynome *polynome = (Polynome*) malloc (sizeof(Polynome)) ;
    Monome *m =(Monome*) malloc(sizeof(*m));

    //Problème d'allocation
    if(polynome == NULL || m == NULL) exit(EXIT_FAILURE) ;

    //Coefficient du monome = 0
    m->coeff = 0; 
    //Exposant = 0 
    m->exp = 0;

    m->suivant = NULL;

    //Premier terme du polynome
    polynome->premier = m;

    return polynome;
}

//Construction d’un nouveau Monome aX^n dont le suivant est NULL
Monome* newMonome ()
{
  //Allocation memoire d’un monome
  Monome *m =(Monome*) malloc(sizeof(*m));
  //cas d’un problème d’allocation
  if(m == NULL || m == NULL) exit(EXIT_FAILURE) ;

  //Saisir m−>coeff et m−>exp
  printf("Saisir le coefficient du monome :") ; 
  scanf("%d", &m->coeff);
  printf("Saisir l'exposant du monome :") ; 
  scanf("%d", &m->exp);
  m->suivant = NULL;

  return m;
}

void insersion(Polynome *polynome)
{
  //Allocation memoire d’un monome
  Monome *m = newMonome();
  //cas d’un problème d’allocation
  if(m == NULL || m == NULL) exit(EXIT_FAILURE) ;

  //Insertion d'un monome au debut de la liste polynomiale
  m->suivant = polynome->premier;
  polynome->premier = m;
}

void suppression(Polynome *polynome)
{
  if(polynome==NULL)
  {
    exit(EXIT_FAILURE);
  }

  Monome *aSupprimer = polynome->premier;
  polynome->premier=polynome->premier->suivant;
  free(aSupprimer);
}


void destruction(Polynome *polynome)
{
  if(polynome==NULL)
  {
    exit(EXIT_FAILURE);
  }
  while(polynome->premier!=NULL)
  {
    suppression(polynome);
  }
}

Polynome *initialisation()
{
  Polynome *polynome = malloc(sizeof(*polynome));
  Monome *monome = malloc(sizeof(*monome));

  if(polynome==NULL || monome==NULL)
  {
    exit(EXIT_FAILURE);
  }

  monome->coeff = 0;
  monome->suivant = NULL;
  polynome->premier = monome;

  return polynome;
}


int Puissance(int X, int N)
{
  if(N==0){
      return 1;
  }
  else if(N%2==0)
  {
    return Puissance(X,(N/2))*Puissance(X,(N/2));
  }
  else if(N%2!=0)
  {
    return Puissance(X,((N-1)/2))*Puissance(X,((N-1)/2))*X;
  }
}


void afficherPolynome(Polynome *polynome)
{
  if(polynome==NULL)
  {
    exit(EXIT_FAILURE);
  }

  Monome *actuel = polynome->premier;

  while (actuel != NULL)
  {
    printf("%d x^ %d ",actuel->coeff, actuel->exp);
    actuel = actuel->suivant;
  }
  printf("NULL\n");
}

int Valeur(Polynome *polynome, int x0){
    if(polynome==NULL)
        exit(EXIT_FAILURE);
      Monome next;
      int res;
    do{
      res = polynome->premier->coeff*Puissance(x0,polynome->premier->exp);
      polynome->premier=polynome->premier->suivant;
      next.exp = polynome->premier->suivant;
    }while(next.exp != NULL);
}

int main(void){
  
  /*Polynome *polynome = initialisation();
  insersion(polynome);
  insersion(polynome);
  insersion(polynome);
  afficherPolynome(polynome);
  suppression(polynome);suppression(polynome);
  afficherPolynome(polynome);
  destruction(polynome);
  free(polynome);
  printf("Fin !");*/

  printf("%d", Puissance(2,2));


  return 1;
}
