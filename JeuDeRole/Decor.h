/*MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWM
v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v
[0]		Objet : Codage de la classe Decor pour le programme du JeuDeRole															[0]
[0]		Date : 29/04/2020																											[1]
[1]		Mise à jour : 06/05/2020																									[0]
[1]		Auteur : RAMBELONOSOAVINA Elko, étudiant en Licence SPI - EEAPR à l'Université de Lorraine									[1]
v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v
MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMW*/

#ifndef Decor_h
#define Decor_h

/* ########## IMPORT DES BIBLIOTHEQUES UTILES ########## */
#include "ElementDecor.h"
#include "Maison.h"
#include "Arbre.h"
#include "Escargot.h"
#include <stdlib.h>
#include <time.h>


class Decor{
	// Données membres
	private :
		ElementDecor** ptd;		// Double pointeurs de 
		unsigned short T;		// Taille du décor

	// Fonctions membres
	public :
		// Constructeurs 
		Decor():ptd(0),T(0){};			// Constructeur vide de Decor
		Decor(unsigned short t){
			unsigned short r;		// Variable aléatoire de désignation d'élément de décor
			Maison *m;
			Arbre *a;
			Escargot *e;

			srand(time(NULL));		// Synchronisation au temps actuel
			T = t;
			ptd = new ElementDecor*[T];
			
			for(unsigned short i = 0; i < T; i++){
				r = rand() %3;		// renvoie 0 ou 1 ou 2

				// Affectation du décor en fonction du nombre aléatoire généré
				switch(r){
					case 0:
						m = new Maison;
						ptd[i] = m; 
						break;
					case 1:
						a = new Arbre;
						ptd[i] = a; 
						break;
				   	case 2:
						e = new Escargot;
						ptd[i] = e;  
						break;
				}
			}
		};

		// SETTERS et GETTERS
		ElementDecor *getElementDecor(unsigned short i){ return(ptd[i]); };		// Renvoie un pointeur d'élément de décor utile pour utiliser 

		// Fonctions utiles
		void AffichePartieDecor(unsigned short N, unsigned short k){
			if (N == T && k == 0){
				// Parcours des lignes de chaque élément de décor
				for(unsigned short j = 1; j <= 5; j++){
					// Parcours dans l'ordre de gauche à droite de chaque élément de décor
					for(unsigned short i = 0; i < T; i++){
						ptd[i]->Affiche(j);				// Affichage de chaque ligne j de chaque élément i (sans "virtual" il affichera par défaut celui de ElementDecor les 0 et 1)
					}
					cout << "\n";	// Passage à l'affichage de la ligne suivante
				}			
			}
			else{
				if (N+k <= T && N+k > 0){
					// Parcours des lignes de chaque élément de décor
					for(unsigned short j = 1; j <= 5; j++){
						// Parcours dans l'ordre de gauche à droite de chaque élément de décor
						for(unsigned short i = k; i < N+k; i++){
							ptd[i]->Affiche(j);				// Affichage de chaque ligne j de chaque élément i (sans "virtual" il affichera par défaut celui de ElementDecor les 0 et 1)
						}
						cout << "\n";	// Passage à l'affichage de la ligne suivante
					}	
				}
			}
		};

		// Destructeurs
		~Decor(){ 
			for(unsigned short i = 0; i < T; i++){
				delete ptd[i];
			}
			delete [] ptd;
		};
};

#endif

/*--------------------[ Signature ]-------------------->/
	============================================
	 ___  |  |    ___   ___|  ___    |[0][1][0]|
	|___| |  |_/ |  /| |   | |___|   |[0][0][1]|
	|_____|__| \_|/__| |___|_|____   |[1][1][1]|
	============================================
/<-------------------------------------------------------*/