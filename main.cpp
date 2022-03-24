#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>
typedef struct
{
char nom[12];
char prenom[12];
char adresse[30];
char tel[20];
char age[20];
char num_compte[10];
 int solde;
} client;


int credit(int nombre){
    FILE *fp;
    fp = fopen("Banque.txt", "a+");

    int chx, m, x;

    printf("\nCredit :");
    printf("\n1 - 10000 Dhs en 12 moins");
    printf("\n2 - 10000 Dhs en 6 mois");
    printf("\n3 - 20000 Dhs en 12 mois");
    printf("\n4 - 20000 Dhs en 6 mois");

    printf("\nChoisissez :\t");
    scanf("%d", &chx);
    
    switch (chx)
    {
    case 1:
        {
        nombre += 10000;
        x = 10000;
        m = 12;
        break;
        }
    case 2:
       {
        nombre += 10000;
        x = 10000;
        m = 6;
        break;
        }
    case 3:
        {
        nombre += 20000;
        x = 20000;
        m = 12;
        break;
        }
    case 4:
       {
        nombre += 20000;
        x = 20000;
        m = 6;
        break;
        }
    default:
        break;
    }
    
    printf("\nVous avez choisis un credit de %d Dhs de %d mois, vous avez %d", x, m, nombre);
    fprintf(fp, "\nVous avez choisis un credit de %d Dhs de %d mois, vous avez %d", x, m, nombre);

    fclose(fp);

    return nombre;
}

int ajout(client T){
int i;
FILE *fp;
fp=fopen("Banque.txt","a+");


printf("Veuillez saisir les informations du client ");
printf("\nTaper le nom : ");
scanf("%s",&T.nom);
fprintf(fp,"le nom : %s\n ",T.nom);
printf("\nTaper le prenom : ");
scanf("%s",&T.prenom);
fprintf(fp,"le prenom : %s\n",T.prenom);
printf("\nTaper le numero de telephone : ");
scanf("%s",&T.tel);
fprintf(fp,"le tel : %s\n",T.tel);
printf("\nTaper l'age du client : ");
scanf("%s",&T.age);
fprintf(fp,"l'age : %s\n\n",T.age);
printf("\nTaper le numero de compte:");
scanf("%s",&T.num_compte);
fprintf(fp,"numero de compte : %s\n",T.num_compte);
printf("\nTaper le solde:");
scanf("%d",&T.solde);
fprintf(fp,"le solde est : %d\n",T.solde);
 fclose(fp);
 return T.solde;
 }

 void affichagelisteclient (client T)
{char c;
FILE *fp;
fp=fopen("Banque.txt","r");
do{
c=getc(fp);
printf("%c",c);
}while(c!=EOF);

}

int deposer(int x)
{	
FILE *fp;
fp=fopen("Banque.txt","r");
int montant,solde;   

	printf("Saisir le montant a deposer: ");
	scanf("%d",&montant); 
	x=x+montant;
	printf("Vous avez deposer %d Dhs, vous avez %d Dhs", montant, x);
    fprintf(fp, "Vous avez deposer %d Dhs, vous avez %d Dhs", montant, x);
    fclose(fp);
    return x;
}

int retrait(int x)
{ 
FILE *fp;
fp=fopen("Banque.txt","a+");
int retirer;

	printf("Saisir le montant a retirer :");
	scanf("%d",&retirer);
	
	if(retirer<=x){
		x=x-retirer;
        printf("Vous avre retirez %d Dhs, vous avez %d Dhs", retirer, x);
		fprintf(fp, "\nvous avez retirer %d Dhs, vous avez %d Dhs", retirer, x);
	}	else 
	printf("le solde est insuffisant !");	

fclose(fp);
return x;
}



int main()
{

client T;
int N;

FILE *fp,*nouveau;
fp=fopen("Banque.txt","a+");
int choix, choix2;
 do{
 printf("\n1 - ajouter");
 printf("\n2 - afficher ");
 printf("\n3 - quiter");
 printf("\n\tEntrez votre choix");
 scanf("%d", &choix);
 
 int variable;
 switch(choix){
 	case 1:{
		
 		variable = ajout(T);
        T.solde = variable;
 		do{
 			printf("\n1 - Deposer");
 			printf("\n2 - retirer");
 			printf("\n3 - consultation du solde");
 			printf("\n4 -credit");
 			printf("\n5 - quiter");
 			printf("\n\tEntrez votre choix");
 			scanf("%d", &choix2);
 			switch(choix2){
 				case 1 : 
 					variable = deposer(T.solde);
                     T.solde = variable;
 					break;
 				case 2 :
                    variable = retrait(T.solde); 
 					T.solde = variable;
 					break;
 				case 3:
 					printf("le solde est : %d",T.solde);
 					break;
 				case 4:
                    variable = credit(T.solde);
 					T.solde = variable;
 					break;
 				case 5 :
 					break;
 				default:
 					printf("Entrez le bon choix.");
			 }
		 }while(choix2 != 5);
	 }
		break;
	 case 2:
	 	affichagelisteclient(T);
	 	break;
	case 3 : 
		break;
	default:
		printf("Saisissez le bon numero");
 }
}while(choix!=3);

fclose(fp);
return 0;
}

