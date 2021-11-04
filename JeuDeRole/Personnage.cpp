/*MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWM
v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v
[0]		Objet : Codage des fonctions de la classe Personnage pour le programme du JeuDeRole											[0]
[0]		Date : 06/05/2020																											[1]
[1]		Mise à jour : 22/05/2020																									[0]
[1]		Auteur : RAMBELONOSOAVINA Elko, étudiant en Licence SPI - EEAPR à l'Université de Lorraine									[1]
v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v
MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMW*/

/* ########## IMPORT DES BIBLIOTHEQUES UTILES ########## */
#include <iostream>
#include <math.h>
#include "Personnage.h"

using namespace std;

//Constructeur de personnage avec choix personnalisés
Personnage::Personnage(int nPV, unsigned int nForce, unsigned int nExp, unsigned short nNiv, unsigned int nVit, unsigned short nPot, char * nNom){
	pvMax = nPV;
	pv = pvMax;
	force = nForce;
	vit = nVit;
	exp = nExp;
	niv = nNiv;
	nb_potion = nPot;
	strcpy_s(nom,nNom);
}

// Fonction donnerCoup qui calcule en comparant la force d'ennemi des points de degats (par exemple degats = 10*Force/ennemi.Force) qui seront retires a PV d'ennemi (c'est pourquoi on a besoin d'un passage par reference). On pourra ecrire un message special dans chaque personnage (attaque pour le personnage et "ouille" pour ennemi.)
void Personnage::donnerCoup(Personnage &ennemi, unsigned short coupCritique){
	unsigned short degats;
	
	if (coupCritique == 6) {
		// Quand probabilité de coup critique est satisfait l'ennemi prend 3 fois de dégats que sans coup critique
		degats = 3*(ceil(10*(float)force/(float)ennemi.getForce()));
	}
	else {
		// Nombre de dégats normal infligés à l'ennemi
		degats = ceil(10*(float)force/(float)ennemi.getForce());
	}

	ennemi.prendreDegat(degats);

	setMessage("AAAH!");
	ennemi.setMessage("OUCH!");
}

// Fonction fuite qui permet de quitter un combat selon une certaine probabilite en comparant la VIT de l'ennemi. Chance de Reussite = VIT/ennemi.VIT*50%. On ne peut pas avoir plus de 90% de chance de fuir.
bool Personnage::fuite(const Personnage &ennemi){
	float reussite;

	reussite = (float)vit/(float)ennemi.getVitesse()*0.5;
	if (reussite >= 0.8){
		return true;
	}
	else{
		return false;
	}

}

// Fonction win qui, lors de la victoire du personnage, permet de voler les potions de l'ennemi. La force et la vitesse augmentent d'un certain pourcentage : par exemple, Force=Force+ (ennemi.Force/Force)*Force/100; VIT=VIT+ (ennemi.VIT/VIT)*VIT/100 (la force augmente de 3% si l'ennemi etait 3 fois plus fort)
void Personnage::win(Personnage &ennemi){
	// Étonnament cette fonction ne fait pas augmenter les stats à partir du moment où on a commencé à intégrer la notion de niveau et expérience du joueur
	if (ennemi.getPV() == 0) {
		// Calcul des acquis du personnage qui a gagné le combat
		nb_potion = nb_potion + ennemi.getNbPotion();
		force = force + ceil(((float)ennemi.getForce()/(float)force)*((float)force/100));
		vit = vit + ceil(((float)ennemi.getVitesse()/(float)vit)*((float)vit/100));

		/*  
		// Augmentation de l'exp en fonction de la force de l'adversaire vaincu
		exp = exp + ceil(0.8 * (float)ennemi.getForce());

		// Vérification si montée de niveau ou pas
		if (exp >= ceil(0.8*(float)pow(niv,3))) {			
			niv++;
			pvMax = pvMax + 10;
			pv = pv + 10; 

			// Les autres stats sont déjà augmentés  à chaque fois qu'un adversaire est vaincu
		}
		*/

		// Calcul des pertes de l'ennemi ayant perdu  le combat à savoir les potions
		ennemi.setNbPotion(0);
	}
}


// Fonction soin qui remonte les PV du personnage d'un certain pourcentage (on choisira 20%) des PVmax. Decremente le nombre de potions
void Personnage::soin(){
	// Vérification du nombre de potion en possession du personnage
	if (nb_potion > 0){
		// Vérification si le pv est différent de pvMax (dégâts infligés au personnage) et de '0' (personnage incapable de continuer à combattre : K.O)
		if (pv != pvMax && pv != 0) {
			pv = pv + 0.2*pvMax;
			cout << "Glouglouglou ..." << endl;
			nb_potion = nb_potion - 1;
		
			// Vérification au cas où après le soin le pv dépasse le pvMax ce qui n'est pas normal
			if (pv > pvMax) {
				pv = pvMax;
			}
		}
		else {
			cout << "Oups! Vous avez tout vos PV ou vous etes deje K.O ..." << endl;
		}
	}
	else {
		cout << "Oups! Pas de potion ..." << endl;
	}
}


/*--------------------[ Signature ]-------------------->/
	============================================
	 ___  |  |    ___   ___|  ___    |[0][1][0]|
	|___| |  |_/ |  /| |   | |___|   |[0][0][1]|
	|_____|__| \_|/__| |___|_|____   |[1][1][1]|
	============================================
/<-------------------------------------------------------*/