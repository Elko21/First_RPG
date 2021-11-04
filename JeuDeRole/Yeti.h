/*MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWM
v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v
[0]		Objet : Codage de la classe Yeti fille de Personnage pour le programme du JeuDeRole											[0]
[0]		Date : 21/05/2020																											[1]
[1]		Mise à jour : 22/05/2020																									[0]
[1]		Auteur : RAMBELONOSOAVINA Elko, étudiant en Licence SPI - EEAPR à l'Université de Lorraine									[1]
v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v
MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMW*/

#ifndef Yeti_h
#define Yeti_h

/* ########## IMPORT DES BIBLIOTHEQUES UTILES ########## */
#include "Personnage.h"



class Yeti : public Personnage{
	/* ######### DONNEES MEMBRES ########### */
	private :

	/* ######### FONCTIONS MEMBRES ########### */
	public :
		/* ######### CONSTRUCTEURS ########### */
		Yeti():Personnage(90,50,0,5,45,3,"Sully"){};							// Constructeur de base: force=50, PV=PVMax=90, EXP=0, VIT=45,nb potion=3 et nom = "Sully" comme Sully dans Monstre et Compagnie
		
		/* ######### GETTERS ET SETTERS ########### */
				

		/* ######### FONCTIONS UTILES ########### */
		// Affiche l'avatar du personnage, de la même facon que les éléments de décor		
		void Affiche(unsigned short i){
			switch(i){
					case 1:
						cout << "    /U\\   ,  ";
						break;
					case 2:
						cout << "Q  _\\\"/_(>|<)";
						break;
					case 3:
						cout << " \\/(_ _)\\_D  ";
						break;
					case 4:
						cout << "   ((.))  |  ";
						break;
					case 5:
						cout << "   // \\\\  |  ";
						break;
					case 6:
						cout << "  ||   || °  ";
						break;
					case 7:
						cout << "  \"\'   \'\"    ";
						break;
			}
		}; 

		/* ######### DESTRUCTEURS ########### */
		~Yeti(){};				//Si necessaire
};

#endif


/*--------------------[ Signature ]-------------------->/
	============================================
	 ___  |  |    ___   ___|  ___    |[0][1][0]|
	|___| |  |_/ |  /| |   | |___|   |[0][0][1]|
	|_____|__| \_|/__| |___|_|____   |[1][1][1]|
	============================================
/<-------------------------------------------------------*/