/*MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWM
v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v
[0]		Objet : Codage de la classe Personnage pour le programme du JeuDeRole														[0]
[0]		Date : 06/05/2020																											[1]
[1]		Mise à jour : 22/05/2020																									[0]
[1]		Auteur : RAMBELONOSOAVINA Elko, étudiant en Licence SPI - EEAPR à l'Université de Lorraine									[1]
v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v
MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMW*/

#ifndef Personnage_h
#define Personnage_h

/* ########## IMPORT DES BIBLIOTHEQUES UTILES ########## */
#include <cstring>


class Personnage{
	/* ######### DONNEES MEMBRES ########### */
	protected :
		int pv;								// Représente les points de vie du personnage
		unsigned int pvMax;					// Représente les points de vie max du personnage
		unsigned int exp;					// Représente l'expérience du personnage
		unsigned short niv;					// Représente le niveau du personnage
		unsigned int force;					// Représente la force du personnage
		unsigned int vit;					// Représente la vitesse du personnage
		unsigned short nb_potion;			// Represente le nombre de potions du personnage
		char message[100];					// Permet d'afficher un message pour chaque action
		char nom[100];						// Nom du personnage 

	/* ######### FONCTIONS MEMBRES ########### */
	public :
		/* ######### CONSTRUCTEURS ########### */
		Personnage():force(50),pv(100),pvMax(100),exp(0),niv(5),vit(50),nb_potion(3){};							// Constructeur de base: force=50, PV=PVMax=100, EXP=0, VIT=50,nb potion=3
		Personnage(int nPV, unsigned int nForce, unsigned int nExp, unsigned short nNiv, unsigned int nVit, unsigned short nPot, char * nNom);			// constructeur avec choix personnalises

		/* ######### GETTERS ET SETTERS ########### */
		virtual char *getMessage() { return(message); };									// Retourne le message 
		virtual char *getNom() { return(nom); };											// Retourne le nom
		virtual int getPV() const { return(pv); };											// Retourne les pv
		virtual unsigned int getPVmax() const { return(pvMax); };							// Retourne le pvMax
		virtual unsigned int getVitesse() const { return(vit); };							// Retourne la vitesse
		virtual unsigned int getForce() const { return(force); };							// Retourne la Force
		virtual unsigned short getNbPotion() const { return(nb_potion); };					// Retourne le nombre de potions du personnage
		virtual unsigned int getEXP() const { return(exp); };								// Retourne le nombre d'expériences du personnage
		virtual unsigned short getNiv() const { return(niv); };								// Retourne le niveau du personnage
		virtual void setMessage(char *nMess){ strcpy_s(message,nMess); };					// Permet de copier un message dans message
		virtual void setNbPotion(unsigned short i){ nb_potion = i; };						// Permet de copier un message dans message

		/* ######### FONCTIONS UTILES ########### */
		virtual void donnerCoup(Personnage &ennemi, unsigned short coupCritique); // Calcule en comparant la force d'ennemi des points de degats (par exemple degats = 10*Force/ennemi.Force) qui seront retires a PV d'ennemi (c'est pourquoi on a besoin d'un passage par reference). On pourra ecrire un message special dans chaque personnage (attaque pour le personnage et "ouille" pour ennemi.)
		virtual void prendreDegat(int valeur) { pv = pv - valeur; };				// PV = PV-valeur.
		virtual void soin();		// Remonte les PV du personnage d'un certain pourcentage des PVmax. Decremente le nombre de potions.
		virtual bool fuite(const Personnage &ennemi); // Permet de quitter un combat selon une certaine probabilite en comparant la VIT de l'ennemi. Chance de Reussite = VIT/ennemi.VIT*50%. On ne peut pas avoir plus de 90% de chance de fuir.
		virtual void win(Personnage &ennemi); // Lors de la victoire du personnage, cette fonction permet de voler les potions de l'ennemi. La force et la vitesse augmentent d'un certain pourcentage : par exemple, Force=Force+ (ennemi.Force/Force)*Force/100; VIT=VIT+ (ennemi.VIT/VIT)*VIT/100 (la force augmente de 3% si l'ennemi etait 3 fois plus fort)
		virtual void Affiche(unsigned short i)=0; // Affiche l'avatar du personnage, de la même facon que les decors.
		virtual void reinitPerso(){ pv = pvMax; nb_potion = 3; };		// Réinitialisation des PV du personnage et du nombre de potions 

		/* ######### DESTRUCTEURS ########### */
		~Personnage(){};				//Si necessaire
};

#endif


/*--------------------[ Signature ]-------------------->/
	============================================
	 ___  |  |    ___   ___|  ___    |[0][1][0]|
	|___| |  |_/ |  /| |   | |___|   |[0][0][1]|
	|_____|__| \_|/__| |___|_|____   |[1][1][1]|
	============================================
/<-------------------------------------------------------*/