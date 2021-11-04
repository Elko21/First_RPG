/*MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWM
v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v
[0]		Objet : Codage de la classe Barbare fille de Personnage pour le programme du JeuDeRole										[0]
[0]		Date : 21/05/2020																											[1]
[1]		Mise à jour : 21/05/2020																									[0]
[1]		Auteur : RAMBELONOSOAVINA Elko, étudiant en Licence SPI - EEAPR à l'Université de Lorraine									[1]
v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v
MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMW*/

#ifndef Cyclope_h
#define Cyclope_h

/* ########## IMPORT DES BIBLIOTHEQUES UTILES ########## */
#include "Personnage.h"



class Cyclope : public Personnage{
	/* ######### DONNEES MEMBRES ########### */
	private :

	/* ######### FONCTIONS MEMBRES ########### */
	public :
		/* ######### CONSTRUCTEURS ########### */
		Cyclope():Personnage(200,100,0,10,100,3,"BIG BOSS"){};							// Constructeur de base: force=100, PV=PVMax=200, EXP=0, VIT=100,nb potion=3 et nom = "BIG BOSS"
				
		/* ######### GETTERS ET SETTERS ########### */
		
		

		/* ######### FONCTIONS UTILES ########### */
		// Affiche l'avatar du personnage, de la même facon que les éléments de décor		
		void Affiche(unsigned short i){
			switch(i){
					case 1:
						cout << "              ";
						break;
					case 2:
						cout << "(Y)__(0)__ /\\ ";
						break;
					case 3:
						cout << " |/\\_ T _// M\\";
						break;
					case 4:
						cout << " Q (__.__)\\ W/";
						break;
					case 5:
						cout << " | (/\\ /\\) \\/ ";
						break;
					case 6:
						cout << " ° \\) V (/    ";
						break;
					case 7:
						cout << "   \"\'   \'\"    ";
						break;
			}
		}; 

		/* ######### DESTRUCTEURS ########### */
		~Cyclope(){};				//Si necessaire
};

#endif


/*--------------------[ Signature ]-------------------->/
	============================================
	 ___  |  |    ___   ___|  ___    |[0][1][0]|
	|___| |  |_/ |  /| |   | |___|   |[0][0][1]|
	|_____|__| \_|/__| |___|_|____   |[1][1][1]|
	============================================
/<-------------------------------------------------------*/