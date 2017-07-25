#include "header.h"


int main()
{
    
    // Crée le fichier s'il n'existe pas
    FILE *test = fopen(PATH_FILE_USER, "a");
    fclose(test);
    
    // Crée le fichier s'il n'existe pas
    test = fopen(PATH_FILE_COMPTE, "a");
    fclose(test);
    
    // Crée le fichier s'il n'existe pas
    test = fopen(PATH_FILE_HISTO, "a");
    fclose(test);
    
    int choix, temp, status;
    
    int id;
    PUser PUser = NULL;
    char nom[50];
    char prenom[50];
    char metier[50];
    char numero[12];
    PListeUser PListeUser = chargerUser(PATH_FILE_USER);
    
    int idCompte;
    int idUser;
    int solde;
    int taux;
    int duree;
    PListeCompte PListeCompte = chargerCompte(PATH_FILE_COMPTE);
    
    char historyBuffer[1024];
    
    
    
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
            printf("\t 9) Retrait\n");
            printf("\t 10) Virement\n\n");
            
            printf("\t 11) Afficher l'historique\n\n");
            
            printf("0 pour exit");
            
            printf("\nVeuillez entrer votre choix : ");
            status = scanf("%d",&choix);
        
        } while((status!=1) && (((temp=getchar()) != EOF) &&(temp != '\n')) || (choix<0) || (choix>11));
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
                
                // ajoute dans l'historique
                snprintf(historyBuffer, sizeof(historyBuffer), "Add new user : %s %s \n", nom, prenom);
                addInHistory(historyBuffer);
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
                    
                    // ajoute dans l'historique
                    snprintf(historyBuffer, sizeof(historyBuffer), "Edit user id : %d \n", PUser->id);
                    addInHistory(historyBuffer);
                } else {
                    printf("\nUser non trouvé");
                }
                
                break;
            case 3 :
                
                printf("\nID : ");
                scanf("%d",&id);
                
                PListeUser = supprimerUser(id, PListeUser);
                sauvegarderUser(PListeUser, PATH_FILE_USER);
                
                // ajoute dans l'historique
                snprintf(historyBuffer, sizeof(historyBuffer), "Remove user id : %d \n", PUser->id);
                addInHistory(historyBuffer);
                
                break;
            case 4 :
                printf("Non fait donc affiche tous les utilisateurs\n");
                printf("-------------------------------------------\n");
                afficherUserList(PListeUser);
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
                
                // ajoute dans l'historique
                snprintf(historyBuffer, sizeof(historyBuffer), "New compte for user id : %d \n", idUser);
                addInHistory(historyBuffer);
                
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
                
                // ajoute dans l'historique
                snprintf(historyBuffer, sizeof(historyBuffer), "Remove compte id : %d \n", id);
                addInHistory(historyBuffer);
                break;
                
                
            case 8 :
                
                printf("\nID Compte : ");
                scanf("%d", &idCompte);
                
                printf("\n Somme ajouté : ");
                scanf("%d", &solde);
                
                depot(idCompte, PListeCompte, solde);
                sauvegarderCompte(PListeCompte, PATH_FILE_COMPTE);
                
                // ajoute dans l'historique
                snprintf(historyBuffer, sizeof(historyBuffer), "Add %d in compte id : %d \n", solde, idCompte);
                addInHistory(historyBuffer);
                break;
            case 9 :
                
                printf("\nID Compte : ");
                scanf("%d", &idCompte);
                
                printf("\n Somme retiré : ");
                scanf("%d", &solde);
                
                retrait(idCompte, PListeCompte, solde);
                sauvegarderCompte(PListeCompte, PATH_FILE_COMPTE);
                
                // ajoute dans l'historique
                snprintf(historyBuffer, sizeof(historyBuffer), "Withdraw %d in compte id : %d \n", solde, idCompte);
                addInHistory(historyBuffer);
                break;
            case 10 :
                
                printf("\nID Compte retrait : ");
                scanf("%d", &id);
                
                printf("\nID Compte soldé : ");
                scanf("%d", &idCompte);
                
                printf("\n Somme viré : ");
                scanf("%d", &solde);
                
                virement(id, idCompte, PListeCompte, solde);
                sauvegarderCompte(PListeCompte, PATH_FILE_COMPTE);
                
                // ajoute dans l'historique
                snprintf(historyBuffer, sizeof(historyBuffer), "Transfer %d from compte %d to compte %d\n", solde, id, idCompte);
                addInHistory(historyBuffer);
                break;
                
            case 11 :
                displayHistory();
                break;

                
        }
    }
    return 0;
}
