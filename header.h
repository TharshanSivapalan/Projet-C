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

typedef User * Liste;
typedef ListeUser * ListeArray;

const char* getfield(char* line, int num);
void afficher(ListeArray listeArray);
ListeArray ajouterUser(ListeArray ListeArray, int id, char nom[], char prenom[], char metier[], char numero[]);
void sauvegarder(ListeArray listeArray,char cheminFichier[]);
ListeArray charger(char cheminFichier[]);
