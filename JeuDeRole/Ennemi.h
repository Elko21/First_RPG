/*MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWM
v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v
[0]		Objet : Codage de la classe Ennemi pour le programme du JeuDeRole															[0]
[0]		Date : 22/05/2020																											[1]
[1]		Mise à jour : 22/05/2020																									[0]
[1]		Auteur : RAMBELONOSOAVINA Elko, étudiant en Licence SPI - EEAPR à l'Université de Lorraine									[1]
v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v
MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMW*/

#ifndef Ennemi_h
#define Ennemi_h

/* ########## IMPORT DES BIBLIOTHEQUES UTILES ########## */
#include "BunnyBoxer.h"
#include "ChauveSouris.h"
#include "Cyclope.h"
#include "GardienChapeaute.h"
#include "Yeti.h"
#include <stdlib.h>
#include <time.h>


class Ennemi{
	// Données membres
	private :
		Personnage** pte;		// Double pointeurs de personnage en l'ocurrence ennemi du joueur au JeuDeRole
		unsigned short T;		// Taille du tableau d'Ennemi

	// Fonctions membres
	public :
		// Constructeur vide de Ennemi 
		Ennemi(){
			T = 5;
			pte = new Personnage*[T];
			
			pte[0] = new BunnyBoxer;
			pte[1] = new ChauveSouris;
			pte[2] = new GardienChapeaute;
			pte[3] = new Yeti;
			pte[4] = new Cyclope;
		};			
		

		// SETTERS et GETTERS
		Personnage *getPersonnage(unsigned short i){ return(pte[i]); };		// Renvoie un pointeur d'élément de décor utile pour utiliser 

		// Destructeurs
		~Ennemi(){ 
			for(unsigned short i = 0; i < T; i++){
				delete pte[i];
			}
			delete [] pte;
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