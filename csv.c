//
//  csv.c
//  Projet_C
//
//  Created by Camille LAURENT on 22/05/2017.
//  Copyright © 2017 Camille LAURENT. All rights reserved.
//

#include "header.h"

/** GLOBAL function **/
const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ";");
         tok && *tok;
         tok = strtok(NULL, ";\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

/** User function **/

//Ajouter un user
PListeUser ajouterUser(PListeUser PListeUser, int id, char nom[], char prenom[], char metier[], char numero[])
{
    ListeUser *listeNouveau = NULL;
    listeNouveau = malloc(sizeof(*listeNouveau));
    User *nouveau = NULL;
    nouveau = malloc(sizeof(*nouveau));
    if(listeNouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    if(nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    nouveau->id = id;
    strcpy(nouveau->nom, nom);
    strcpy(nouveau->prenom, prenom);
    strcpy(nouveau->metier, metier);
    strcpy(nouveau->numero, numero);
    
    listeNouveau->user = nouveau;
    listeNouveau->suivant = NULL;
    if(PListeUser == NULL)
    {
        return listeNouveau;
    }
    else
    {
        //Sinon, on parcourt la liste jusqu'au dernier élement
        ListeUser *curseur = PListeUser;
        while(curseur->suivant != NULL)
        {
            curseur = curseur->suivant;
        }
        //On positionne le nouvel élément comme le dernier
        curseur->suivant = listeNouveau;
        //On retourne la liste
        return PListeUser;
    }
}

PUser findUser(int id, PListeUser PListeUser)
{
    ListeUser *ListeUser = PListeUser;
    while(ListeUser != NULL)
    {
        User *user = ListeUser->user;
        if (id == user->id){
            return user;
        }
        ListeUser = ListeUser->suivant;
    }

    return NULL;
}

//Afficher les annonces contenue dans la liste chainée
void afficherUserList(PListeUser PListeUser)
{
    ListeUser *ListeUser = PListeUser;
    int i=0;
    while(ListeUser != NULL)
    {
        User *nouveau = ListeUser->user;
        displayUser(nouveau);
        ListeUser = ListeUser->suivant;
        i++;
    }
    
    printf("\(%d User trouves)\n",i);
}

void displayUser(User *user)
{
    printf("%d\t", user->id);
    printf("%s\t", user->nom);
    printf("%s\t", user->prenom);
    printf("%s\t", user->metier);
    printf("%s\t", user->numero);
    printf("\n");

}

// return new id
int newIdUser(PListeUser PListeUser)
{
    int max = 0;
    
    ListeUser *ListeUser = PListeUser;
    
    while(ListeUser != NULL)
    {
        User *user = ListeUser->user;
        if (user->id > max){
            max = user->id;
        }
        ListeUser = ListeUser->suivant;
    }
    return ++max;
}

//Sauvegarde la liste d'user dans un fichier
void sauvegarderUser(PListeUser PListeUser, char cheminFichier[])
{
    FILE * fichier =fopen(cheminFichier,"w");
    if(fichier == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    ListeUser *listeUser = PListeUser;
    while(listeUser != NULL)
    {
        User *nouveau = listeUser->user;
        fprintf(fichier, "%d;", nouveau->id);
        fprintf(fichier, "%s;", nouveau->nom);
        fprintf(fichier, "%s;", nouveau->prenom);
        fprintf(fichier, "%s;", nouveau->metier);
        fprintf(fichier, "%s\n", nouveau->numero);
        listeUser = listeUser->suivant;
    }
    fclose(fichier);
    printf("Sauvegarde reussi!");
}

//Charge une liste d'user à partir d'un fichier
PListeUser chargerUser(char cheminFichier[])
{
    PListeUser PListeUser = NULL;
    FILE * fichier =fopen(cheminFichier,"r");
    if(fichier == NULL)
    {
        printf("Fichier vide ou introuvable");
        exit(EXIT_FAILURE);
    }
    rewind(fichier);
    
    int id;
    char nom[50];
    char prenom[50];
    char metier[50];
    char numero[12];
    
    char line[1024];
    while (fgets(line, 1024, fichier))
    {
        char* tmp = strdup(line);
        id =  atoi(getfield(tmp, 1));
        
        tmp = strdup(line);
        strcpy(nom, getfield(tmp, 2));
        
        tmp = strdup(line);
        strcpy(prenom, getfield(tmp, 3));
        
        tmp = strdup(line);
        strcpy(metier, getfield(tmp, 4));
        
        tmp = strdup(line);
        strcpy(numero, getfield(tmp, 5));
        
        
        PListeUser=ajouterUser( PListeUser, id, nom, prenom, metier, numero);
        free(tmp);
    }
    
    fclose(fichier);
    return PListeUser;
}

/** Compte function **/
