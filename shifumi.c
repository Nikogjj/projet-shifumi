#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/random.h>

void enregistrement(char* joueur1);
void jeu1(char* jeujoueur1);
// void jeu2(char* jeujoueur2);
int chartohand1 (char* jeujoueur1,char* joueur1);
int chartohand2 (int random);
void shifumi (char* jeujoueur1,int random, char* joueur1,int* scorejoueur1);
int genEntropicSeed();
float aleatoire(float minimum,float maximum);



int main(){
    genEntropicSeed();
    // int random=aleatoire(1,4);
    int random=0;
    char joueur1 [255];
    // char joueur2 [255];
    char jeujoueur1 [255];
    // char jeujoueur2 [255];
    enregistrement(joueur1);
    int hand_joueur_1 = 1;
    int hand_joueur_2 = 1;
    int scorejoueur1 =0;
    int scorejoueur2 =0;
    while (hand_joueur_1!=0 && hand_joueur_2!=0 )
    {
        random=aleatoire(1,4);
        // printf("%d",random);
        printf("%s ?\n1.Pierre\n2.Feuille\n3.Ciseaux\n0.Quitter\n\n",joueur1);
        jeu1(jeujoueur1);
        hand_joueur_1 = chartohand1(jeujoueur1,joueur1);
        if(hand_joueur_1 == 0) continue;

        shifumi(jeujoueur1,random,joueur1,&scorejoueur1);
    }
};


void enregistrement(char* joueur1){
    printf("--------------- Shifumi ! ---------------\nEntrez le nom du Joueur 1\n");
    memset(joueur1,0,255);
    fgets(joueur1,255,stdin);
    joueur1[strlen(joueur1)-1]=0;
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

int chartohand2 (int random){

    if (random==1)
    {
        printf("PC a joué Pierre !\n\n");
        return 1;
    }
    else if (random==2){
        printf("PC a joué Feuille !\n\n");
        return 2;
    }
    else if (random==3){
        printf("PC a joué Ciseaux !\n\n");
        return 3;
    }
    // else if(strcmp(jeujoueur2,"0")==0){
    //     printf("PC quitte le jeu ! Aurevoir.\n\n");
    //     return 0;
    // }
}


void shifumi (char* jeujoueur1,int random, char* joueur1,int* scorejoueur1){
    char buf[255];
    sprintf(buf,"%d",random);
   
    if (strcmp(jeujoueur1,"1")==0 && random==3)
    {
        printf("La pierre bat le ciseaux !\n%s a gagné\n\n",joueur1);
        (*scorejoueur1)++;
        printf("Score:\n%s : %d\n",joueur1,(*scorejoueur1));

    }
    else if(strcmp(jeujoueur1,"1")==0 && random==2)
    {
        printf("La feuille bat la pierre !\nPC a gagné\n\n");
        printf("Score:\n%s : %d\n",joueur1,(*scorejoueur1));
    }
    else if(strcmp(jeujoueur1,"2")==0 && random==1)
    {
        printf("La feuille bat la pierre !\n%s a gagné\n\n",joueur1);
        (*scorejoueur1)++;
        printf("Score:\n%s : %d\n",joueur1,(*scorejoueur1));
    }
    else if(strcmp(jeujoueur1,"2")==0 && random==3)
    {
        printf("Le ciseaux bat la feuille !\nPC a gagné\n\n");
        printf("Score:\n%s : %d\n",joueur1,(*scorejoueur1));
    }
    else if(strcmp(jeujoueur1,"3")==0 && random==1)
    {
        printf("La pierre bat le ciseaux !\nPC a gagné\n\n");
        printf("Score:\n%s : %d\n",joueur1,(*scorejoueur1));
    }
    else if(strcmp(jeujoueur1,"3")==0 && random==2)
    {
        printf("Le ciseaux bat la feuille !\n%s a gagné\n\n",joueur1);
        (*scorejoueur1)++;
        printf("Score:\n%s : %d\n",joueur1,(*scorejoueur1));
    }
    else if(strcmp(jeujoueur1,buf)==0)
    {
        printf("Egalité !\n\n");
        printf("Score:\n%s : %d\n",joueur1,(*scorejoueur1));
    }
    
}

int genEntropicSeed(){
    int tab[255];
    getentropy(tab,sizeof(tab));
    int seed=0;
    for (int i = 0; i < 255; i++)
    {
        seed=seed+tab[i];
    }
    srand (seed);
}

float aleatoire(float minimum,float maximum){
    int minetmax = minimum+(float)rand()/RAND_MAX*(maximum-minimum); 
    return minetmax;
}