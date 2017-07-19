#include "header.h"


int main()
{
    
    // Crée le fichier s'il n'existe pas
    FILE *test = fopen(PATH_FILE_USER, "a");
    fclose(test);
    
    // Crée le fichier s'il n'existe pas
    test = fopen(PATH_FILE_COMPTE, "a");
    fclose(test);
    
    int choix, temp, status;
    
    int id;
    PUser PUser = NULL;
    char nom[50];
    char prenom[50];
    char metier[50];
    char numero[12];
    PListeUser PListeUser = chargerUser(PATH_FILE_USER);
    
    int idUser;
    int solde;
    int taux;
    int duree;
    PListeCompte PListeCompte = chargerCompte(PATH_FILE_COMPTE);
    
    while(1!=0)
    {
        do {
            printf("\n\t\tBanque\n\n");
            printf("Gestion des clients: \n");
            printf("\t 1) Ajouter\n");
            printf("\t 2) Modifier\n");
            printf("\t 3) Supprimer\n");
            printf("\t 4) Recherche\n\n");
            
            printf("Gestion des comptes:\n");
            printf("\t 5) Nouveau\n");
            printf("\t 6) Consulter\n");
            printf("\t 7) Fermeture\n\n");
            
            printf("Gestion des operations:\n");
            printf("\t 8) Depot\n");
            printf("\t 7) Retrait\n");
            printf("\t 9) Virement\n\n");
            
            printf("0 pour exit");
            
            printf("\nVeuillez entrer votre choix : ");
            status = scanf("%d",&choix);
            // test avec linux
            //system("clear");
        } while((status!=1) && (((temp=getchar()) != EOF) &&(temp != '\n')) || (choix<0) || (choix>10));
        switch(choix)
        {
            case 0 :
                printf("Au revoir :)\n");
                return 0;
                break;
            case 1 :
                
                printf("\nNom : ");
                scanf("%s",nom);
                
                printf("\nPrenom : ");
                scanf("%s",prenom);
                
                printf("\nMetier : ");
                scanf("%s", metier);
                
                printf("\nNumero : ");
                scanf("%s", numero);
                
                PListeUser = ajouterUser(PListeUser, newIdUser(PListeUser), nom, prenom, metier, numero);
                sauvegarderUser(PListeUser, PATH_FILE_USER);
                
                break;
            case 2 :
                
                printf("\nID : ");
                scanf("%d",&id);
                
                if ((PUser = findUser(id, PListeUser)) != NULL){
                    
                    printf("\nNom[%s] : ", PUser->nom);
                    scanf("%s", PUser->nom);
                    
                    printf("\nPrenom[%s] : ", PUser->prenom);
                    scanf("%s", PUser->prenom);
                    
                    printf("\nMetier[%s] : ", PUser->metier);
                    scanf("%s", PUser->metier);
                    
                    printf("\nNumero[%s] : ", PUser->numero);
                    scanf("%s", PUser->numero);
                    
                    sauvegarderUser(PListeUser, PATH_FILE_USER);
                } else {
                    printf("\nUser non trouvé");
                }
                
                break;
            case 3 :
                
                printf("\nID : ");
                scanf("%d",&id);
                
                PListeUser = supprimerUser(id, PListeUser);
                sauvegarderUser(PListeUser, PATH_FILE_USER);
                
                break;
            case 4 :
                printf("C'est le choix 4");
                break;
                
                
            case 5 :
                
                printf("\nID user : ");
                scanf("%d", &idUser);
                
                if (findUser(idUser, PListeUser) == NULL){
                    printf("Pas de user avec cette id");
                    break;
                }
                
                printf("\nSolde : ");
                scanf("%d", &solde);
                
                printf("\nTaux : ");
                scanf("%d", &taux);
                
                printf("\nDuree : ");
                scanf("%d", &duree);
                
                PListeCompte = ajouterCompte(PListeCompte, newIdCompte(PListeCompte), idUser, solde, taux, duree);
                sauvegarderCompte(PListeCompte, PATH_FILE_COMPTE);
                
                break;
            case 6 :
                printf("\nID user : ");
                scanf("%d", &idUser);
                
                if (findUser(idUser, PListeUser) == NULL){
                    printf("Pas de user avec cette id");
                    break;
                }
                
                displayCompteByUser(idUser, PListeCompte);
                break;
            case 7 :
                printf("\nID du compte : ");
                scanf("%d",&id);
                
                PListeCompte = supprimerCompte(id, PListeCompte);
                sauvegarderCompte(PListeCompte, PATH_FILE_COMPTE);
                break;
                
                
            case 8 :
                printf("C'est le choix 8");
                break;
            case 9 :
                printf("C'est le choix 9");
                break;
            case 10 :
                printf("C'est le choix 10");
                break;
                
        }
    }
    return 0;
}
