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

// supprime un user
PListeUser supprimerUser(int id, PListeUser PListeUser)
{
    ListeUser *FirstList = PListeUser;
    User *FirstUser = FirstList->user;
    if (id == FirstUser->id){
        PListeUser = PListeUser->suivant;
        return PListeUser;
    }
    ListeUser *CurrentList = FirstList->suivant;
    
    while(CurrentList != NULL)
    {
        
        User *CurrentUser = CurrentList->user;
        
        if (id == CurrentUser->id){
            FirstList->suivant = CurrentList->suivant;
            return PListeUser;
        }
        
        FirstList = CurrentList;
        CurrentList = FirstList->suivant;
        
    }
    
    return PListeUser;
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


PListeCompte ajouterCompte(PListeCompte PListeCompte, int id, int idUser, int solde, int taux, int duree)
{
    ListeCompte *listeNouveau = NULL;
    listeNouveau = malloc(sizeof(*listeNouveau));
    Compte *nouveau = NULL;
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
    nouveau->idUser = idUser;
    nouveau->solde = solde;
    nouveau->taux = taux;
    nouveau->duree = duree;
    
    listeNouveau->compte = nouveau;
    listeNouveau->suivant = NULL;
    if(PListeCompte == NULL)
    {
        return listeNouveau;
    }
    else
    {
        //Sinon, on parcourt la liste jusqu'au dernier élement
        ListeCompte *curseur = PListeCompte;
        while(curseur->suivant != NULL)
        {
            curseur = curseur->suivant;
        }
        //On positionne le nouvel élément comme le dernier
        curseur->suivant = listeNouveau;
        //On retourne la liste
        return PListeCompte;
    }
}


//Sauvegarde la liste de compte dans un fichier
void sauvegarderCompte(PListeCompte PListeCompte, char cheminFichier[])
{
    FILE * fichier =fopen(cheminFichier,"w");
    if(fichier == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    ListeCompte *ListeCompte = PListeCompte;
    while(ListeCompte != NULL)
    {
        Compte *nouveau = ListeCompte->compte;
        fprintf(fichier, "%d;", nouveau->id);
        fprintf(fichier, "%d;", nouveau->idUser);
        fprintf(fichier, "%d;", nouveau->solde);
        fprintf(fichier, "%d;", nouveau->taux);
        fprintf(fichier, "%d\n", nouveau->duree);
        ListeCompte = ListeCompte->suivant;
    }
    fclose(fichier);
    printf("Sauvegarde reussi!");
}

// supprime un Compte
PListeCompte supprimerCompte(int id, PListeCompte PListeCompte)
{
    ListeCompte *FirstList = PListeCompte;
    Compte *FirstCompte = FirstList->compte;
    if (id == FirstCompte->id){
        PListeCompte = PListeCompte->suivant;
        return PListeCompte;
    }
    ListeCompte *CurrentList = FirstList->suivant;
    
    while(CurrentList != NULL)
    {
        
        Compte *CurrentCompte = CurrentList->compte;
        
        if (id == CurrentCompte->id){
            FirstList->suivant = CurrentList->suivant;
            return PListeCompte;
        }
        
        FirstList = CurrentList;
        CurrentList = FirstList->suivant;
        
    }
    
    return PListeCompte;
}

//Charge une liste de compte à partir d'un fichier
PListeCompte chargerCompte(char cheminFichier[])
{
    PListeCompte PListeCompte = NULL;
    FILE * fichier =fopen(cheminFichier,"r");
    if(fichier == NULL)
    {
        printf("Fichier vide ou introuvable");
        exit(EXIT_FAILURE);
    }
    rewind(fichier);
    
    int id;
    int idUser;
    int solde;
    int taux;
    int duree;
    
    char line[1024];
    while (fgets(line, 1024, fichier))
    {
        char* tmp = strdup(line);
        id =  atoi(getfield(tmp, 1));
        
        tmp = strdup(line);
        idUser =  atoi(getfield(tmp, 2));
        
        tmp = strdup(line);
        solde =  atoi(getfield(tmp, 3));
        
        tmp = strdup(line);
        taux =  atoi(getfield(tmp, 4));
        
        tmp = strdup(line);
        duree =  atoi(getfield(tmp, 5));
        
        
        PListeCompte=ajouterCompte( PListeCompte, id, idUser, solde, taux, duree);
        free(tmp);
    }
    
    fclose(fichier);
    return PListeCompte;
}

// return new id
int newIdCompte(PListeCompte PListeCompte)
{
    int max = 0;
    
    ListeCompte *ListeCompte = PListeCompte;
    
    while(ListeCompte != NULL)
    {
        Compte *compte = ListeCompte->compte;
        if (compte->id > max){
            max = compte->id;
        }
        ListeCompte = ListeCompte->suivant;
    }
    return ++max;
}

void displayCompteByUser(int idUser,PListeCompte PListeCompte)
{
    ListeCompte *ListeCompte = PListeCompte;
    int i=0;
    while(ListeCompte != NULL)
    {
        Compte *compte = ListeCompte->compte;
        if (compte->idUser == idUser){
            displayCompte(compte);
            i++;
        }
        ListeCompte = ListeCompte->suivant;
    }
    
    printf("\(%d Compte trouves)\n",i);
}

void displayCompte(Compte *compte)
{
    printf("Compte id : %d", compte->id);
    printf("\t solde : %d", compte->solde);
    printf("\n");
}

PCompte findCompte(int id, PListeCompte PListeCompte)
{
    ListeCompte *ListeCompte = PListeCompte;
    while(ListeCompte != NULL)
    {
        Compte *compte = ListeCompte->compte;
        if (id == compte->id){
            return compte;
        }
        ListeCompte = ListeCompte->suivant;
    }
    
    return NULL;
}

// Operation compte

void depot(int id, PListeCompte PListeCompte, int solde)
{
    PCompte PCompte = NULL;
    if ((PCompte = findCompte(id, PListeCompte)) != NULL){
        PCompte->solde += solde;
    } else {
        printf("Compte non trouvé");
    }
    
}

void retrait(int id, PListeCompte PListeCompte, int solde)
{
    PCompte PCompte = NULL;
    if ((PCompte = findCompte(id, PListeCompte)) != NULL){
        PCompte->solde -= solde;
    } else {
        printf("Compte non trouvé");
    }
    
}

void virement(int idRetrait, int idSolde, PListeCompte PListeCompte, int solde)
{
    PCompte compteRetrait = NULL;
    PCompte compteSolde = NULL;
    
    if ((compteRetrait = findCompte(idRetrait, PListeCompte)) != NULL && (compteSolde = findCompte(idSolde, PListeCompte)) != NULL ){
        printf("pourtant\n");
        compteRetrait->solde -= solde;
        compteSolde->solde += solde;
        printf("%d", compteSolde->solde);
    } else {
        printf("Compte non trouvé");
    }
}
