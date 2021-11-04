/*MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWM
v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v
[0]		Objet : Codage de la classe Archer fille de Personnage pour le programme du JeuDeRole										[0]
[0]		Date : 20/05/2020																											[1]
[1]		Mise à jour : 22/05/2020																									[0]
[1]		Auteur : RAMBELONOSOAVINA Elko, étudiant en Licence SPI - EEAPR à l'Université de Lorraine									[1]
v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v
MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMW*/

#ifndef Archer_h
#define Archer_h

/* ########## IMPORT DES BIBLIOTHEQUES UTILES ########## */
#include "Personnage.h"



class Archer : public Personnage{
	/* ######### DONNEES MEMBRES ########### */
	private :

	/* ######### FONCTIONS MEMBRES ########### */
	public :
		/* ######### CONSTRUCTEURS ########### */
		Archer():Personnage(100,40,0,5,60,3,"Robin"){};						// Constructeur de base: force=40, PV=PVMax=100, EXP=0, VIT=60,nb potion=3 nom = "Robin" comme Robin des Bois
		
		/* ######### GETTERS ET SETTERS ########### */
		

		/* ######### FONCTIONS UTILES ########### */
		// Affiche l'avatar du personnage, de la même facon que les éléments de décor		
		void Affiche(unsigned short i){
			switch(i){
					case 1:
						cout << "        ";
						break;
					case 2:
						cout << "     .  ";
						break;
					case 3:
						cout << " _0_ /) ";
						break;
					case 4:
						cout << "/_D====>";
						break;
					case 5:
						cout << " )_( \\) ";
						break;
					case 6:
						cout << " \\  \\\'  ";
						break;
					case 7:
						cout << " |  /   ";
						break;
			}
		}; 

		/* ######### DESTRUCTEURS ########### */
		~Archer(){};				//Si necessaire
};

#endif


/*--------------------[ Signature ]-------------------->/
	============================================
	 ___  |  |    ___   ___|  ___    |[0][1][0]|
	|___| |  |_/ |  /| |   | |___|   |[0][0][1]|
	|_____|__| \_|/__| |___|_|____   |[1][1][1]|
	============================================
/<-------------------------------------------------------*/