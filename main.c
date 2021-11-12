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
<<<<<<< HEAD
  
  Liste *maListe = initialisation();
  
  afficherListe(maListe);

=======
  //TEST sam
>>>>>>> 35248e5b0e88bdeac4f8d6a8a021702e8c53a9b9
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
  scanf("%d", m->coeff);
  printf("Saisir l'exposant du monome :") ; 
  scanf("%d", m->exp);
  m->suivant = NULL;

  return m;
}

Liste *initialisation()
{
  Liste *liste = malloc(sizeof(*liste));
  Element *element = malloc(sizeof(*element));

  if(liste==NULL || element==NULL)
  {
    exit(EXIT_FAILURE);
  }

  element->nombre = 0;
  element->suivant = NULL;
  liste->premier = element;
}


void afficherListe(Liste *liste)
{
  if(liste==NULL)
  {
    exit(EXIT_FAILURE);
  }

  Element *actuel = liste->premier;

  while (actuel != NULL)
  {
    printf("%d -> ",actuel->nombre);
    actuel = actuel->suivant;
  }
  printf("NULL\n");
}

