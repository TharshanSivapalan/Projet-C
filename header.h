//
//  csv.h
//  Projet_C
//
//  Created by Camille LAURENT on 22/05/2017.
//  Copyright © 2017 Camille LAURENT. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h> /* malloc...*/
#include <string.h> /* strtok...*/
#include <ctype.h>
#include <time.h>
#include <errno.h>

static const char PATH_FILE_USER[] = "/Users/camille/Dropbox/user.csv";
static const char PATH_FILE_COMPTE[] = "/Users/camille/Dropbox/compte.csv";
static const char PATH_FILE_HISTO[] = "/Users/camille/Dropbox/historique.txt";


/********************* STRUCTURE *************************/

// user struct
typedef struct User
{
    int id;
    char nom[50];
    char prenom[50];
    char metier[50];
    char numero[12];
}User;

typedef struct ListeUser
{
    User *user;
    struct ListeUser *suivant;
}ListeUser;

typedef User * PUser;
typedef ListeUser * PListeUser;


// compte struct
typedef struct Compte
{
    int id;
    int idUser;
    int solde;
    int taux;
    int duree;
}Compte;

typedef struct ListeCompte
{
    Compte *compte;
    struct ListeCompte *suivant;
}ListeCompte;

typedef Compte * PCompte;
typedef ListeCompte * PListeCompte;


/********************* FUNCTION *************************/


// global function
const char* getfield(char* line, int num);

// user function
void displayUser(User *user);
PUser findUser(int id, PListeUser PListeUser);
void afficherUserList(PListeUser PListeUser);
int newIdUser(PListeUser PListeUser);
PListeUser ajouterUser(PListeUser PListeUser, int id, char nom[], char prenom[], char metier[], char numero[]);
void sauvegarderUser(PListeUser PListeUser,char cheminFichier[]);
PListeUser chargerUser(char cheminFichier[]);
PListeUser supprimerUser(int id, PListeUser PListeUser);

// compte function
PListeCompte ajouterCompte(PListeCompte PListeCompte, int id, int idUser, int solde, int taux, int duree);
void sauvegarderCompte(PListeCompte PListeCompte, char cheminFichier[]);
PListeCompte supprimerCompte(int id, PListeCompte PListeCompte);
PListeCompte chargerCompte(char cheminFichier[]);
int newIdCompte(PListeCompte PListeCompte);
void displayCompteByUser(int idUser,PListeCompte PListeCompte);
void displayCompte(Compte *compte);
PCompte findCompte(int id, PListeCompte PListeCompte);

// operation
void depot(int id, PListeCompte PListeCompte, int solde);
void retrait(int id, PListeCompte PListeCompte, int solde);
void virement(int id, int idCompte, PListeCompte PListeCompte, int solde);

// history
void addInHistory(char sentence[]);
void displayHistory();
