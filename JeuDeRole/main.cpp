/*MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWM
v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v
[0]		Objet : Programme principal du JeuDeRole (avec les test �l�mentaires avant la validation du fonctionnement du programme)	[0]
[0]		Date : 29/04/2020																											[1]
[1]		Mise � jour : 22/05/2020																									[0]
[1]		Auteur : RAMBELONOSOAVINA Elko, �tudiant en Licence SPI - EEAPR � l'Universit� de Lorraine									[1]
v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v
MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMW*/

/* ########## IMPORT DES BIBLIOTHEQUES UTILES ########## */
#include <stdlib.h>
#include <conio.h>				// Biblioth�que pour les caract�res
#include <windows.h>
#include "EcranJeu.h"
#include "Joueur.h"
#include "Ennemi.h"

/* ########## PROGRAMME PRINCIPAL ########## */
#define sizeDec 30
#define sizePartDec 20

/* ########## PROGRAMME PRINCIPAL ########## */
int main(){
	unsigned short move = 0;
	unsigned short rndOpp, criticalHit;
	unsigned short typePers = 0;
	char decPlayer = 'c';
	unsigned short decOpponent, mode;
	bool f = false;

	Decor dec(sizeDec);
	Joueur player;
	Ennemi opponent;

	// Choix de race de personnage par le joueur
	do {
		cout << "Bienvenue dans FANTASIA! Le Jeu RPG en mode console que vous adorez." << endl;
		cout << "Veuillez choisir parmi la liste suivante votre heros ...\n\n\n";
		AffichePersonnagesDebut(player.getPersonnage(0),player.getPersonnage(1),player.getPersonnage(2));
		cout << "Entrez le heros avec qui vous voudriez jouer : ";
		decPlayer = getch();
		system("cls");
	} while(decPlayer != '1' && decPlayer != '2' && decPlayer != '3' && decPlayer != 'x');
	
	// Conversion de la d�cision du joueur en entier pour le choix de personnage au d�but
	switch(decPlayer){
		case '1':
			typePers = 0;		// Choix sur l'Archer
			break;
		case '2':
			typePers = 1;		// Choix sur le Barbare
			break;
		case '3':
			typePers = 2;		// Choix sur le Guerrier
			break;
	}

	srand(time(NULL));		// Synchronisation au temps actuel

	while (decPlayer != 'x'){
		system("cls");		// Efface l'�cran du joueur pour en afficher un nouvel �cran par la suite	

		// Affichage de l'ent�te en mode promenade
		AfficheEntetePromenade();

		// Affichage d'une partie de d�cor
		dec.AffichePartieDecor(sizePartDec,move);
		cout << "\n\n\n";

		// Affichage du personnage du joueur en mode promenade
		AffichePersonnagePromenade(player.getPersonnage(typePers));
		
		do {		
			decPlayer = getch();		// Prise de d�cision du joueur
		} while (decPlayer != 'x' && decPlayer != 'q' && decPlayer != 'd' && decPlayer != 's');
			
		switch(decPlayer){
			case 'q':	// Cas o� le joueur veut aller � gauche
				--move; 
				// V�rification pour �viter de d�passer le d�cor
				if(move < 0){ 
					move = 0; 
				} 
				break;
			case 'd':	// Cas o� le joueur veut aller � droite
				++move; 
				// V�rification pour �viter de d�passer le d�cor
				if(sizePartDec+move >= sizeDec){ 
					move = sizeDec - sizePartDec; 
				} 
				break;
			case 's':		// Cas o� le joueur d�cide de se soigner
				(player.getPersonnage(typePers))->soin();;
				break;
		}

		// Si d�cision de quitter le jeu n'est pas choisie
		if (decPlayer != 'x'){
			mode = rand() %6 + 1;		// Lanc� de d� � 6 faces pour d�cider du mode promenade ou combat	si lanc� donne 6 donc mode combat
		}
		
		// Mode combat 
		if (mode == 6) {
			// S�lection al�atoire en fonction du niveau du joueur car Yeti et Cyclope sont plus fort (�viter la difficult� contre Cyclope qui doit �tre le BOSS final)
			if (player.getPersonnage(typePers)->getNiv() >= 10) {
				rndOpp = rand() %5;			// S�lection al�atoire de l'ennemi fesant son apparition 
			}
			else{
				rndOpp = rand() %3;			// S�lection al�atoire de l'ennemi fesant son apparition
			}
			
			cout << "Un ennemi apparait !!!" << endl;
			Sleep(1500);

			do {
				system("cls");			// Effacer l'�cran

				// Affichage des stats de chaque personnage pr�sent sur l'�cran
				AfficheEnteteCombat(player.getPersonnage(typePers), opponent.getPersonnage(rndOpp));

				// Affichage d'une partie de d�cor
				dec.AffichePartieDecor(sizePartDec,move);
				cout << "\n\n\n";

				// Affichage des personnages en mode combat
				AffichePersonnagesCombat(player.getPersonnage(typePers), opponent.getPersonnage(rndOpp));

				// Prise de d�cision du joueur
				do {
					decPlayer = getch();		// Prise de d�cision du joueur
				} while (decPlayer != 'x' && decPlayer != 'a' && decPlayer != 's' && decPlayer != 'f');
				
				// Calcul de la probabilit� de la fuite du joueur
				if (decPlayer == 'f') {
					cout << "Vous tentez de fuir ..." << endl;
					f = (player.getPersonnage(typePers))->fuite(*opponent.getPersonnage(rndOpp));
				}
				
				// Affichage des messages sp�ciaux
				if (decPlayer == 'a') {
					criticalHit = rand() %6 +1;

					(player.getPersonnage(typePers))->donnerCoup(*opponent.getPersonnage(rndOpp),criticalHit);
					cout << (player.getPersonnage(typePers))->getMessage();
					cout << "\t\t\t\t\t";
					cout << (opponent.getPersonnage(rndOpp))->getMessage() << endl;
				}

				// Soigner le joueur si choix de soin avec potion
				if (decPlayer == 's') {
					(player.getPersonnage(typePers))->soin();
				}
				Sleep(500);

				// Traitement de la d�cision pseudo-al�atoire (car on n'a pas d'IA) de l'ennemi qui doit �tre la fonction autocombat(Personnage &ennemi)
				decOpponent = rand() %6 + 1;

				if (opponent.getPersonnage(rndOpp)->getPV() > 0 && decPlayer != 'x' && !f) {
					if (decOpponent != 1 && decOpponent != 3 && decOpponent != 5 && decOpponent != 6 && decOpponent == 4) {
						(opponent.getPersonnage(rndOpp))->soin();
					}
					else {
						criticalHit = 0; // rand() %6 +1;
						(opponent.getPersonnage(rndOpp))->donnerCoup(*player.getPersonnage(typePers), criticalHit);
						cout << (player.getPersonnage(typePers))->getMessage();
						cout << "\t\t\t\t\t";
						cout << opponent.getPersonnage(rndOpp)->getMessage() << endl;
					}	
				}
				(player.getPersonnage(typePers))->win(*opponent.getPersonnage(rndOpp));		
				(opponent.getPersonnage(rndOpp))->win(*player.getPersonnage(typePers));

				Sleep(500);
			} while (decPlayer != 'x' &&  (opponent.getPersonnage(rndOpp))->getPV() > 0 && !f && (player.getPersonnage(typePers))->getPV() > 0);

			// V�rification du propri�taire des PV � '0' si le joueur donc affichage "GAME OVER" sinon 
			if ((player.getPersonnage(typePers))->getPV() <= 0){
				system("cls");			// Effacer l'�cran 

				cout << "--------------GAME OVER--------------" << endl;
				Sleep(3000);
				decPlayer = 'x';
			}
			else {
				opponent.getPersonnage(rndOpp)->reinitPerso();
			}
		}
	}
	system("cls");
	cout << "Vous quittez le jeu ..." << endl;
	
	return 0;
}


/*--------------------[ Signature ]-------------------->/
	============================================
	 ___  |  |    ___   ___|  ___    |[0][1][0]|
	|___| |  |_/ |  /| |   | |___|   |[0][0][1]|
	|_____|__| \_|/__| |___|_|____   |[1][1][1]|
	============================================
/<-------------------------------------------------------*/