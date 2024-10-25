#include <stdio.h>
#include <string.h>

#define BUF_SIZE 255

int readLine(FILE* fd,char* buf,int buf_size,int line_index){
    int i;
    for (i = 0; i < line_index; i++)
    {
        fgets(buf,buf_size,fd);
    }

    return i; // renvoi l'index de la ligne
}

int main(){
    // FILE * fd = fopen("test","a+");
    // fclose(fd);
    // Accès Ecriture et Lecture SANS SUPPRESSION DE DONNEES
    FILE * fd = fopen("test","r+");

    char buf[BUF_SIZE];memset(buf,0,BUF_SIZE);

    // Je lis la deuxième ligne
    readLine(fd,buf,BUF_SIZE,2);
    
    char carac_name[255];memset(carac_name,0,255);
    int carac_value = -1;

    // Je récupère les deux premiers tokens
    sscanf(buf,"%s%d",carac_name,&carac_value);
    // Je les affiches à l'écran
    printf("%s : %d\n",carac_name,carac_value);

    return 0;
}