/*MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWM
v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v
[0]		Objet : Codage de la classe Guerrier fille de Personnage pour le programme du JeuDeRole										[0]
[0]		Date : 20/05/2020																											[1]
[1]		Mise � jour : 22/05/2020																									[0]
[1]		Auteur : RAMBELONOSOAVINA Elko, �tudiant en Licence SPI - EEAPR � l'Universit� de Lorraine									[1]
v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v
MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMW*/

#ifndef Guerrier_h
#define Guerrier_h

/* ########## IMPORT DES BIBLIOTHEQUES UTILES ########## */
#include "Personnage.h"



class Guerrier : public Personnage{
	/* ######### DONNEES MEMBRES ########### */
	private :

	/* ######### FONCTIONS MEMBRES ########### */
	public :
		/* ######### CONSTRUCTEURS ########### */
		Guerrier():Personnage(100,50,0,5,50,3,"Hercule"){};					// Constructeur de base: force=50, PV=PVMax=100, EXP=0, VIT=50,nb potion=3 nom = "Hercule" comme le h�ros de la mythologie grecque 
		
		/* ######### GETTERS ET SETTERS ########### */
				

		/* ######### FONCTIONS UTILES ########### */
		// Affiche l'avatar du personnage, de la m�me facon que les �l�ments de d�cor		
		void Affiche(unsigned short i){
			switch(i){
					case 1:
						cout << "              ";
						break;
					case 2:
						cout << "    <(---q---)>";
						break;
					case 3:
						cout << "    __0__/     ";
						break;
					case 4:
						cout << " /\\/|_T_|      ";
						break;
					case 5:
						cout << "(\\\\) )_(       ";
						break;
					case 6:
						cout << " \\/  \\  \\      ";
						break;
					case 7:
						cout << "     |  /      ";
						break;
			}
		}; 

		/* ######### DESTRUCTEURS ########### */
		~Guerrier(){};				//Si necessaire
};

#endif


/*--------------------[ Signature ]-------------------->/
	============================================
	 ___  |  |    ___   ___|  ___    |[0][1][0]|
	|___| |  |_/ |  /| |   | |___|   |[0][0][1]|
	|_____|__| \_|/__| |___|_|____   |[1][1][1]|
	============================================
/<-------------------------------------------------------*/