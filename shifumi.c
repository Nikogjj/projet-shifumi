#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void enregistrement(char* joueur1,char* joueur2);
void jeu1(char* jeujoueur1);
void jeu2(char* jeujoueur2);
int chartohand1 (char* jeujoueur1,char* joueur1);
int chartohand2 (char* jeujoueur2,char* joueur2);
void shifumi (char* jeujoueur1,char* jeujoueur2, char* joueur1, char* joueur2,int* scorejoueur1,int* scorejoueur2);

int main(){
    char joueur1 [255];
    char joueur2 [255];
    char jeujoueur1 [255];
    char jeujoueur2 [255];
    enregistrement(joueur1,joueur2);
    int hand_joueur_1 = 1;
    int hand_joueur_2 = 1;
    int scorejoueur1 =0;
    int scorejoueur2 =0;
    while (hand_joueur_1!=0 && hand_joueur_2!=0 )
    {
        printf("%s ?\n1.Pierre\n2.Feuille\n3.Ciseaux\n0.Quitter\n\n",joueur1);
        jeu1(jeujoueur1);
        hand_joueur_1 = chartohand1(jeujoueur1,joueur1);
        if(hand_joueur_1 == 0) continue;

        printf("%s ?\n1.Pierre\n2.Feuille\n3.Ciseaux\n0.Quitter\n\n",joueur2);
        jeu2(jeujoueur2);

        hand_joueur_2 = chartohand2(jeujoueur2,joueur2);
        
        if(hand_joueur_2 == 0) continue;

        shifumi(jeujoueur1,jeujoueur2,joueur1, joueur2,&scorejoueur1,&scorejoueur2);
    }
};


void enregistrement(char* joueur1,char* joueur2){
    printf("--------------- Shifumi ! ---------------\nEntrez le nom du Joueur 1\n");
    memset(joueur1,0,255);
    fgets(joueur1,255,stdin);
    joueur1[strlen(joueur1)-1]=0;
    printf("Entrez le nom du Joueur 2\n");
    memset(joueur2,0,255);
    fgets(joueur2,255,stdin);
    joueur2[strlen(joueur2)-1]=0;
};


void jeu1(char* jeujoueur1){
    int i;
    int k=1;
    for (i = 0; k !=0 ; i++)
    {
        memset(jeujoueur1,0,255);
        fgets(jeujoueur1,255,stdin);
        jeujoueur1[strlen(jeujoueur1)-1]=0;
        printf("\n");
        if (strcmp(jeujoueur1,"1")!=0 && strcmp(jeujoueur1,"2")!=0 && strcmp(jeujoueur1,"3")!=0 && strcmp(jeujoueur1,"0")!=0)
        {
            printf("Veuillez entrer une reponse valide\n");
        }
        else{
            k=0;
        }   
    }
}


void jeu2(char* jeujoueur2){
    int i;
    int k=1;
    for (int i = 0; k !=0 ; i++)
    {
        memset(jeujoueur2,0,255);
        fgets(jeujoueur2,255,stdin);
        jeujoueur2[strlen(jeujoueur2)-1]=0;
        printf("\n");
        if (strcmp(jeujoueur2,"1")!=0 && strcmp(jeujoueur2,"2")!=0 && strcmp(jeujoueur2,"3")!=0 && strcmp(jeujoueur2,"0")!=0)
        {
            printf("Veuillez entrer une reponse valide\n");
        }
        else{
            k=0;
        }   
    }
}


int chartohand1 (char* jeujoueur1,char* joueur1){
    while (1)
    {
        if (strcmp(jeujoueur1,"1")==0)
        {
            printf("%s a joué Pierre !\n\n",joueur1);
            return 1;
        }
        else if (strcmp(jeujoueur1,"2")==0){
            printf("%s a joué Feuille !\n\n",joueur1);
            return 2;
        }
        else if (strcmp(jeujoueur1,"3")==0){
            printf("%s a joué Ciseaux !\n\n",joueur1);
            return 3;
        }
        else if(strcmp(jeujoueur1,"0")==0){
            printf("%s quitte le jeu ! Aurevoir.\n\n",joueur1);
            return 0;
        }
        else{
            printf("Veuillez rentrer une reponse valide\n");
        }
    }
}


int chartohand2 (char* jeujoueur2,char* joueur2){
    if (strcmp(jeujoueur2,"1")==0)
    {
        printf("%s a joué Pierre !\n\n",joueur2);
        return 1;
    }
    else if (strcmp(jeujoueur2,"2")==0){
        printf("%s a joué Feuille !\n\n",joueur2);
        return 2;
    }
    else if (strcmp(jeujoueur2,"3")==0){
        printf("%s a joué Ciseaux !\n\n",joueur2);
        return 3;
    }
    else if(strcmp(jeujoueur2,"0")==0){
        printf("%s quitte le jeu ! Aurevoir.\n\n",joueur2);
        return 0;
    }
}


void shifumi (char* jeujoueur1,char* jeujoueur2, char* joueur1, char* joueur2,int* scorejoueur1,int* scorejoueur2){
    if (strcmp(jeujoueur1,"1")==0 && strcmp(jeujoueur2,"3")==0)
    {
        printf("La pierre bat le ciseaux !\n%s a gagné\n\n",joueur1);
        (*scorejoueur1)++;
        printf("Score:\n%s : %d\n%s : %d\n\n",joueur1,(*scorejoueur1),joueur2,(*scorejoueur2));

    }
    else if(strcmp(jeujoueur1,"1")==0 && strcmp(jeujoueur2,"2")==0)
    {
        printf("La feuille bat la pierre !\n%s a gagné\n\n",joueur2);
        (*scorejoueur2)++;
        printf("Score:\n%s : %d\n%s : %d\n\n",joueur1,(*scorejoueur1),joueur2,(*scorejoueur2));
    }
    else if(strcmp(jeujoueur1,"2")==0 && strcmp(jeujoueur2,"1")==0)
    {
        printf("La feuille bat la pierre !\n%s a gagné\n\n",joueur1);
        (*scorejoueur1)++;
        printf("Score:\n%s : %d\n%s : %d\n\n",joueur1,(*scorejoueur1),joueur2,(*scorejoueur2));
    }
    else if(strcmp(jeujoueur1,"2")==0 && strcmp(jeujoueur2,"3")==0)
    {
        printf("Le ciseaux bat la feuille !\n%s a gagné\n\n",joueur2);
        (*scorejoueur2)++;
        printf("Score:\n%s : %d\n%s : %d\n\n",joueur1,(*scorejoueur1),joueur2,(*scorejoueur2));
    }
    else if(strcmp(jeujoueur1,"3")==0 && strcmp(jeujoueur2,"1")==0)
    {
        printf("La pierre bat le ciseaux !\n%s a gagné\n\n",joueur2);
        (*scorejoueur2)++;
        printf("Score:\n%s : %d\n%s : %d\n\n",joueur1,(*scorejoueur1),joueur2,(*scorejoueur2));
    }
    else if(strcmp(jeujoueur1,"3")==0 && strcmp(jeujoueur2,"2")==0)
    {
        printf("Le ciseaux bat la feuille !\n%s a gagné\n\n",joueur1);
        (*scorejoueur1)++;
        printf("Score:\n%s : %d\n%s : %d\n\n",joueur1,(*scorejoueur1),joueur2,(*scorejoueur2));
    }
    else if(strcmp(jeujoueur1,jeujoueur2)==0)
    {
        printf("Egalité !\n\n");
        printf("Score:\n%s : %d\n%s : %d\n\n",joueur1,(*scorejoueur1),joueur2,(*scorejoueur2));
    }
    
}
