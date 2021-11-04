/*MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWM
v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v
[0]		Objet : Codage de la classe BunnyBoxer fille de Personnage pour le programme du JeuDeRole									[0]
[0]		Date : 21/05/2020																											[1]
[1]		Mise à jour : 22/05/2020																									[0]
[1]		Auteur : RAMBELONOSOAVINA Elko, étudiant en Licence SPI - EEAPR à l'Université de Lorraine									[1]
v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v
MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMW*/

#ifndef BunnyBoxer_h
#define BunnyBoxer_h

/* ########## IMPORT DES BIBLIOTHEQUES UTILES ########## */
#include "Personnage.h"



class BunnyBoxer : public Personnage{
	/* ######### DONNEES MEMBRES ########### */
	private :

	/* ######### FONCTIONS MEMBRES ########### */
	public :
		/* ######### CONSTRUCTEURS ########### */
		BunnyBoxer():Personnage(50,30,0,3,20,3,"Hungry Bunny"){};							// Constructeur de base: force=30, PV=PVMax=50, EXP=0, VIT=20,nb potion=3 et nom = "Hungry Bunny"
		
		/* ######### GETTERS ET SETTERS ########### */
				

		/* ######### FONCTIONS UTILES ########### */
		// Affiche l'avatar du personnage, de la même facon que les éléments de décor		
		void Affiche(unsigned short i){
			switch(i){
					case 1:
						cout << "       ";
						break;
					case 2:
						cout << "       ";
						break;
					case 3:
						cout << "       ";
						break;
					case 4:
						cout << "  (\\/) ";
						break;
					case 5:
						cout << " (-.-) ";
						break;
					case 6:
						cout << "o(. )Q)";
						break;
					case 7:
						cout << " (_(_/*";
						break;
			}
		}; 

		/* ######### DESTRUCTEURS ########### */
		~BunnyBoxer(){};				//Si necessaire
};

#endif


/*--------------------[ Signature ]-------------------->/
	============================================
	 ___  |  |    ___   ___|  ___    |[0][1][0]|
	|___| |  |_/ |  /| |   | |___|   |[0][0][1]|
	|_____|__| \_|/__| |___|_|____   |[1][1][1]|
	============================================
/<-------------------------------------------------------*/