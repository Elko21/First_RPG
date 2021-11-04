/*MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWM
v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v
[0]		Objet : Codage de la classe Escargot pour le programme du JeuDeRole															[0]
[0]		Date : 29/04/2020																											[1]
[1]		Mise à jour : 06/05/2020																									[0]
[1]		Auteur : RAMBELONOSOAVINA Elko, étudiant en Licence SPI - EEAPR à l'Université de Lorraine									[1]
v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v
MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMW*/

#ifndef Escargot_h
#define Escargot_h

/* ########## IMPORT DES BIBLIOTHEQUES UTILES ########## */
#include "ElementDecor.h"

class Escargot : public ElementDecor{
	// Données membres
	private :


	// Fonctions membres
	public :
		// Pas de constructeurs ni de destructeurs car pas de données membres

		// Fonctions utiles
		void Affiche(unsigned short i){
			switch(i){
				case 1:
					cout << "     ";
					break;
				case 2:
					cout << "     ";
					break;
				case 3:
					cout << "     ";
					break;
				case 4:
					cout << "     ";
					break;
				case 5:
					cout << "_Y@)_";
					break;
			}
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