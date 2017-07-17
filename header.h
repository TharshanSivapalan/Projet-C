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
#include <errno.h>

static const char PATH_FILE[] = "/Users/camille/Dropbox/test.csv";


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

typedef User * LUser;
typedef ListeUser * PListeUser;


// compte struct
typedef struct Compte
{
    int id;
    char nom[50];
    char prenom[50];
    char metier[50];
    char numero[12];
}Compte;

typedef struct ListeCompte
{
    Compte *compte;
    struct ListeCompte *suivant;
}ListeCompte;

typedef Compte * LCompte;
typedef ListeCompte * PListeCompte;


/********************* FUNCTION *************************/


// global function
const char* getfield(char* line, int num);

// user function
void displayUser(User *user);
void afficherAllUserList(PListeUser PListeUser);
int newId(PListeUser PListeUser);
PListeUser ajouterUser(PListeUser PListeUser, int id, char nom[], char prenom[], char metier[], char numero[]);
void sauvegarder(PListeUser PListeUser,char cheminFichier[]);
PListeUser charger(char cheminFichier[]);

// compte function


