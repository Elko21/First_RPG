/*MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWM
v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v
[0]		Objet : Codage des fonctions d'affichage pour mode du JeuDeRole 															[0]
[0]		Date : 13/05/2020																											[1]
[1]		Mise à jour : 22/05/2020																									[0]
[1]		Auteur : RAMBELONOSOAVINA Elko, étudiant en Licence SPI - EEAPR à l'Université de Lorraine									[1]
v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v
MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMW*/

/* ########## IMPORT DES BIBLIOTHEQUES UTILES ########## */
#include "Decor.h"
#include "Joueur.h"
#include "Ennemi.h"

/* ########## DEFINITION DES FONCTIONS DE GESTION DES MODES D'AFFICHAGE DE L'ECRAN DU JEU ########## */

// Fonction d'affichage de l'entête en mode Combat qui affiche les stats de chaque personnage participant au combat et les actions pouvant être utilisées par le joueur
void AfficheEnteteCombat(Personnage *J, Personnage *E){
	cout << "Nom : " << J->getNom();
	cout << "\t\t\t";
	cout << "Nom : " << E->getNom() << endl;
	cout << "Niveau : " << J->getNiv();
	cout << "\t\t\t";
	cout << "Niveau : " << E->getNiv() << endl;
	cout << "PV : " << J->getPV() << "/" << J->getPVmax();
	cout << "\t\t\t";
	cout << "PV : " << E->getPV() << "/" << E->getPVmax() << endl;
	cout << "Force : " << J->getForce();
	cout << "\t\t\t";
	cout << "Force : " << E->getForce() << endl;
	cout << "Vitesse : " << J->getVitesse();
	cout << "\t\t\t";
	cout << "Vitesse : " << E->getVitesse() << endl;
	cout << "Nb_potion : " << J->getNbPotion();
	cout << "\t\t\t";
	cout << "Nb_potion : " << E->getNbPotion() << endl;
	cout << "EXP : " << J->getEXP();
	cout << "\t\t\t\t";
	cout << "EXP : " << E->getEXP() << endl;
	cout << "===================================================================================================" << endl;
	cout << "a pour attaquer | s pour se soigner avec une potion | f pour tenter de fuir | x pour quitter le jeu" << endl;
	cout << "===================================================================================================" << endl;
	cout << "\n\n";
}

// Fonction d'affichage de l'entête en mode Promenade qui affiche les actions pouvant être utilisées par le joueur
void AfficheEntetePromenade(){
	cout << "d pour aller a droite | q pour aller a gauche | s pour soin | x pour quitter le jeu" << endl;
	cout << "===========================================================================================" << endl;
	cout << "\n\n";
}

// Fonction d'affichage des personnages pouvant être choisis par le joueur au tout début du jeu
void AffichePersonnagesDebut(Personnage *P1, Personnage *P2, Personnage *P3){
	cout << "[1] ARCHER";
	cout << "\t\t\t\t";
	cout << "[2] BARBARE";
	cout << "\t\t\t\t";
	cout << "[3] GUERRIER" << endl;

	for(unsigned short j = 1; j <= 7; j++){
		P1->Affiche(j);
		cout << "\t\t\t\t";
		P2->Affiche(j);
		cout << "\t\t\t\t";
		P3->Affiche(j);
		cout << "\n";	// Passage à l'affichage de la ligne suivante
	}

	cout << "Niveau : " << P1->getNiv();
	cout << "\t\t\t\t";
	cout << "Niveau : " << P2->getNiv();
	cout << "\t\t\t\t";
	cout << "Niveau : " << P3->getNiv() << endl;
	cout << "PV : " << P1->getPV() << "/" << P1->getPVmax();
	cout << "\t\t\t\t";
	cout << "PV : " << P2->getPV() << "/" << P2->getPVmax();
	cout << "\t\t\t\t";
	cout << "PV : " << P3->getPV() << "/" << P3->getPVmax() << endl;
	cout << "Force : " << P1->getForce();
	cout << "\t\t\t\t";
	cout << "Force : " << P2->getForce();
	cout << "\t\t\t\t";
	cout << "Force : " << P3->getForce() << endl;
	cout << "Vitesse : " << P1->getVitesse();
	cout << "\t\t\t\t";
	cout << "Vitesse : " << P2->getVitesse();
	cout << "\t\t\t\t";
	cout << "Vitesse : " << P3->getVitesse() << "\n\n\n";
}

// Fonction d'affichage du personnage du joueur en mode Promenade 
void AffichePersonnagePromenade(Personnage *J){
	for(unsigned short j = 1; j <= 7; j++){
		J->Affiche(j);
		cout << "\n";	// Passage à l'affichage de la ligne suivante
	}
}

// Fonction d'affichage du personnage du joueur en mode Combat avec son ennemi à droite
void AffichePersonnagesCombat(Personnage *J, Personnage *E){
	for(unsigned short j = 1; j <= 7; j++){
		J->Affiche(j);
		cout << "\t\t\t\t";
		E->Affiche(j);
		cout << "\n";	// Passage à l'affichage de la ligne suivante
	}
}
