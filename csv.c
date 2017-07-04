//
//  csv.c
//  Projet_C
//
//  Created by Camille LAURENT on 22/05/2017.
//  Copyright © 2017 Camille LAURENT. All rights reserved.
//

#include "header.h"


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


//Ajouter une annonce
ListeArray ajouterUser(ListeArray ListeArray, int id, char nom[], char prenom[], char metier[], char numero[])
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
    if(ListeArray == NULL)
    {
        return listeNouveau;
    }
    else
    {
        //Sinon, on parcourt la liste jusqu'au dernier élement
        ListeUser *curseur = ListeArray;
        while(curseur->suivant != NULL)
        {
            curseur = curseur->suivant;
        }
        //On positionne le nouvel élément comme le dernier
        curseur->suivant = listeNouveau;
        //On retourne la liste
        return ListeArray;
    }
}

//Afficher les annonces contenue dans la liste chainée
void afficher(ListeArray listeArray)
{
    ListeUser *ListeUser = listeArray;
    int i=0;
    printf("Id\tNom\tPrenom\tMetier\tNumero\n");
    while(ListeUser != NULL)
    {
        User *nouveau = ListeUser->user;
        printf("%d\t", nouveau->id);
        printf("%s\t", nouveau->nom);
        printf("%s\t", nouveau->prenom);
        printf("%s\t", nouveau->metier);
        printf("%s\t", nouveau->numero);
        ListeUser = ListeUser->suivant;
        printf("\n");
        i++;
    }
    
    printf("\(%d Annonces trouves)\n",i);
}

//Sauvegarde la liste d'annonce dans un fichier
void sauvegarder(ListeArray listeArray,char cheminFichier[])
{
    
//    FILE * fichier =fopen(cheminFichier,"w");
//    if(fichier == NULL)
//    {
//        exit(EXIT_FAILURE);
//    }
//    //rewind(fichier);
//    ListeAnnonce *listeAnnonce = listeArray;
//    while(listeAnnonce != NULL)
//    {
//        Annonce *nouveau = listeAnnonce->annonce;
//        fprintf(fichier, "%u ", nouveau->numero);
//        fprintf(fichier, "%s ", nouveau->type);
//        fprintf(fichier, "%hu ", nouveau->nombre_piece);
//        fprintf(fichier, "%lu ", nouveau->surface);
//        fprintf(fichier, "%lu ", nouveau->loyer);
//        fprintf(fichier, "%lu\n", nouveau->charge);
//        listeAnnonce = listeAnnonce->suivant;
//    }
//    fclose(fichier);
//    printf("Sauvegarde reussi!");
}

//Charge une liste d'annonce à partir d'un fichier
ListeArray charger(char cheminFichier[])
{
    ListeArray listeArray = NULL;
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
        
        
        listeArray=ajouterUser( listeArray, id, nom, prenom, metier, numero);
        free(tmp);
    }
    
    fclose(fichier);
    return listeArray;
}
