#include "header.h"


int main()
{
    int choix, temp, status;
    
    int id;
    PUser PUser = NULL;
    char nom[50];
    char prenom[50];
    char metier[50];
    char numero[12];
    PListeUser PListeUser = chargerUser(PATH_FILE);
    
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
                sauvegarderUser(PListeUser, PATH_FILE);
                
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
                    
                    sauvegarderUser(PListeUser, PATH_FILE);
                } else {
                    printf("\nUser non trouvé");
                }
                
                break;
            case 3 :
                printf("C'est le choix 3");
                break;
            case 4 :
                printf("C'est le choix 4");
                break;
                
            case 5 :
                printf("C'est le choix 5");
                break;
            case 6 :
                printf("C'est le choix 6");
                
                break;
            case 7 :
                printf("C'est le choix 7");
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
