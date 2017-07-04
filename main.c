#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choix, temp, status;
     while(1!=0)
    {
        do {
            printf("\n\t\tBanque\n\n",138);
            printf("Gestion des clients\n",138);

            printf("\tPour ajouter  entrez '1'\n");
            printf("\tPour modifier entrez '2'\n",138);
            printf("\tPour supprimez entrez '3'\n");
            printf("\tPour rechercher entrez '4'\n");
            printf("Gestion des comptes\n",138);
            printf("\tPour un nouveau compte '5'\n",138);
            printf("\tPour consulter '6'\n");
            printf("\tPour fermeture du compte '7'\n");
            printf("Gestion des operations\n",138);
            printf("\tPour faire un depot '8'\n",133);
            printf("\tPour faire un retrait'9'\n",133);
            printf("\tPour efftcuer un virement'10'\n",133);
            printf("\nVeuillez entrer votre choix : ");
            status = scanf("%d",&choix);
            system("cls");
        }
        while((status!=1) && (((temp=getchar()) != EOF) &&(temp != '\n')) || (choix<1) || (choix>10));
        switch(choix)
        {
        case 1 :
                printf("C'est le choix 1");
            break;
        case 2 :
                printf("C'est le choix 2");
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

