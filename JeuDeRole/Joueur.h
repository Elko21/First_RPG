/*MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWM
v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v
[0]		Objet : Codage de la classe Joueur pour le programme du JeuDeRole															[0]
[0]		Date : 22/05/2020																											[1]
[1]		Mise à jour : 22/05/2020																									[0]
[1]		Auteur : RAMBELONOSOAVINA Elko, étudiant en Licence SPI - EEAPR à l'Université de Lorraine									[1]
v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v
MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMW*/

#ifndef Joueur_h
#define Joueur_h

/* ########## IMPORT DES BIBLIOTHEQUES UTILES ########## */
#include "Archer.h"
#include "Barbare.h"
#include "Guerrier.h"
#include <stdlib.h>
#include <time.h>


class Joueur{
	// Données membres
	private :
		Personnage** ptj;		// Double pointeurs de personnage en l'ocurrence ennemi du joueur au JeuDeRole
		unsigned short T;		// Taille du tableau d'Ennemi

	// Fonctions membres
	public :
		// Constructeur vide de Ennemi
		Joueur(){
			T = 5;
			ptj = new Personnage*[T];
			
			ptj[0] = new Archer;
			ptj[1] = new Barbare;
			ptj[2] = new Guerrier;
		};			
		

		// SETTERS et GETTERS
		Personnage *getPersonnage(unsigned short i){ return(ptj[i]); };		// Renvoie un pointeur d'élément de décor utile pour utiliser 

		// Destructeurs
		~Joueur(){ 
			for(unsigned short i = 0; i < T; i++){
				delete ptj[i];
			}
			delete [] ptj;
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