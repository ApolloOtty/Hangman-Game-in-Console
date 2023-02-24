#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<conio.h>
#include<time.h>
#include <windows.h>
#define GREEN 2
#define BLUE 3
#define RED 12
#define YELLOW 14
#define WHITE 15
#define CYAN 3
#define BROWN 6
#define LIGHTGREEN 10
#define MAGENTA 13



void set_color(int color_code) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color_code);
}

struct Clasament{
        char nume[50];
        int scor;
    }clas[30];


void citire_clasament(){
    FILE* fp = fopen("clasament.txt", "r");
    FILE* player_count = fopen("player_count.txt", "r");
    int player_number;
    fscanf(player_count, "%d", &player_number);
    int i=-1;
    while (i<player_number){
        ++i;
        fscanf(fp, "%s %d",clas[i].nume, &clas[i].scor);
    }
}


void verificare_duplicat(char *n, int s){
    clasament();
    char nume[50];
    int numar;
    FILE* fp2 = fopen("clasament2.txt", "w");
    FILE* fp = fopen("clasament.txt", "r+");
        for(int i=0; i<30; i++){
            fprintf(fp2, "%s\n", clas[i].nume);
            if (strcmp(clas[i].nume, n)==0){
                clas[i].scor=s;
                fprintf(fp, "%s\n%d", clas[i].nume, s);
            }
        }
    fclose(fp);
    fclose(fp2);

}



void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void swap_str(char *str1, char *str2)
{
  char *temp = (char *)malloc((strlen(str1) + 1) * sizeof(char));
  strcpy(temp, str1);
  strcpy(str1, str2);
  strcpy(str2, temp);
  free(temp);
}



const char * cuvant_random(char* cuvant){
    srand ( time(NULL) );
    int r = rand() % 34;
    int contor=-1;
    FILE* fp = fopen("Cuvinte.txt", "r");
    while (fgets(cuvant, 100, fp) && contor<=r){
        ++contor;
        if (contor==r){
                return cuvant;
            }
    }
    return cuvant;
}


void clasament(){
    int player_number;
    FILE* player_count = fopen("player_count.txt", "r");
    FILE* fp = fopen("clasament.txt", "r");
    fscanf(player_count, "%d", &player_number);
    int i=-1;
    while (i<player_number){
        ++i;
        fscanf(fp, "%s %d",clas[i].nume, &clas[i].scor);
}
if (i==0){
    printf("Nu exista niciun scor salvat!\n");
}else{
     for (i = 0; i < player_number; i++)
       for (int j = 0; j < player_number; j++)
           if (clas[j].scor < clas[j+1].scor){
              swap(&clas[j].scor, &clas[j+1].scor);
              swap_str(clas[j].nume, clas[j+1].nume);
           }

    for(int j=0; j<player_number; j++){
        set_color(GREEN);
        printf("%d.", j+1);
        set_color(WHITE);
        printf("%s", clas[j].nume);
        set_color(BLUE);
        printf(" %d\n", clas[j].scor);
    }
}
    set_color(WHITE);
    fclose(fp);
    fclose(player_count);
}


int meniu_principal(){
    fflush(stdin);
    int choice=0;
    int numread=0;
    while(1!=0) {
        set_color(RED);
        printf("<== Spanzuratoarea ==>\n\n");
        set_color(GREEN);
        printf("(1) ");
        set_color(WHITE);
        printf("Start\n");
        set_color(GREEN);
        printf("(2) ");
        set_color(WHITE);
        printf("Vizualizare clasament\n");
        set_color(GREEN);
        printf("(3) ");
        set_color(WHITE);
        printf("Istoric jocuri\n");
        set_color(GREEN);
        printf("(4) ");
        set_color(WHITE);
        printf("Iesire\n");
        printf("Introdu optiunea dorita: ");
        set_color(GREEN);
        numread=scanf("%d", &choice);
        if (choice!=1 || choice!=2 || choice!=3 || choice!=4) {
            while(choice < 1 || choice > 4) {
                    if (numread!=1){
                        set_color(WHITE);
                        printf("Nu ai introdus o cifra, incearca din nou: ");
                        fflush(stdin);
                         set_color(GREEN);
                        numread=scanf("%d", &choice);
                    }else{
            set_color(WHITE);
            printf("Introdu optiunea dorita: ");
            fflush(stdin);
             set_color(GREEN);
            numread=scanf("%d", &choice);
            }}
        }
        set_color(WHITE);
        system("cls");
        return choice;
}
}

void  choice_2(){
    set_color(RED);
    printf("<-- Clasament -->\n");
    set_color(WHITE);
    clasament();
    system("pause");
    system("cls");
    main();
}


void choice_3(){
    char nume_jucator[30];
    char line[50];
    int i=0;
    int gasit=0;
    printf("Introdu numele jucatorului caruia doresti sa ii vezi istoricul : ");
    set_color(CYAN);
    scanf("%s", nume_jucator);
     set_color(WHITE);
    system("cls");
    FILE* istoric = fopen("istoric.txt", "r");
    while(fgets(line, 50, istoric)){
        fflush(stdin);
        if(strstr(line, nume_jucator)){
            i++;
            if (i==1){
            printf("Istoric jocuri ");
            set_color(CYAN);
            printf("%s :\n", nume_jucator);
            set_color(WHITE);
            }
            set_color(GREEN);
            printf("%s\n", line);
            gasit=1;
        }
    }
        if (gasit==0){
        set_color(RED);
        printf("Nu exista un jucator cu acest nume!\n");
        }
    set_color(WHITE);
    fclose(istoric);
    system("pause");
    system("cls");
    main();
}


void choice_1(){
    citire_clasament();
    int player_number;
    int runda=0;
    int scor_player=0;
    char cuvant[100];
    int scor=5;
    durere:
    system("cls");
    strcpy(cuvant, cuvant_random(cuvant));
            int lungime_cuvant=strlen(cuvant)+1;
            char cuvant_ascuns[lungime_cuvant];
            strcpy(cuvant_ascuns, cuvant);
            for (int i=0; i<strlen(cuvant_ascuns)-1;i++){
                cuvant_ascuns[i]='_';
            }
            char litera;
            int idk=0;
            int ver=1;
            int gresit=1;
            int if_letter=1;
            int if_notsingle=1;
            for (int i=0; i<strlen(cuvant);i++){
                    if (i==0 || i==strlen(cuvant)-2){
                        cuvant_ascuns[i]=cuvant[i];
                        //printf("%c", cuvant[i]);
                    }else if (cuvant[i]==cuvant[0]  || cuvant[i]==cuvant[strlen(cuvant)-2]){
                        cuvant_ascuns[i]=cuvant[i];
                        //printf("%c", cuvant[i]);
                    }
            }
            while (scor>=0){
                switch (scor){
                case 5:
                    printf("%s\n", cuvant);
                    printf("Numarul de incercari este: ");
                    set_color(RED);
                    printf("%d\n\n", scor);
                    set_color(WHITE);
                    if (runda==0){
                    set_color(YELLOW);
                    printf("Daca introduci mai mult de o litera, programul o va lua in calcul doar pe prima!\n");}
                    set_color(WHITE);
                    set_color(BROWN);
                    printf("\n  |-----\n  |     |\n  |     |\n  |   \n  |\n  |\n  |\n  |\n  |\n  |\n");
                    printf("-----\n");
                    set_color(WHITE);
                    set_color(MAGENTA);
                    printf("%s", cuvant_ascuns);
                    set_color(WHITE);
                    break;
                case 4:;
                    printf("Numarul de incercari este: ");
                    set_color(RED);
                    printf("%d\n\n", scor);
                    set_color(WHITE);
                    set_color(BROWN);
                    printf("\n  |-----\n  |     |\n  |     |\n  |   (   )  \n  |\n  |\n  |\n  |\n  |\n  |\n");
                    printf("-----\n");
                    set_color(WHITE);
                    set_color(MAGENTA);
                    printf("%s", cuvant_ascuns);
                    set_color(WHITE);
                    break;
                case 3:
                    printf("Numarul de incercari este: ");
                    set_color(RED);
                    printf("%d\n\n", scor);
                    set_color(WHITE);
                    set_color(BROWN);
                    printf("\n  |-----\n  |     |\n  |     |\n  |   (   )  \n  |     |\n  |     |\n  |\n  |\n  |\n  |\n");
                    printf("-----\n");
                    set_color(WHITE);
                    set_color(MAGENTA);
                    printf("%s", cuvant_ascuns);
                    set_color(WHITE);
                    break;
                case 2:
                    printf("Numarul de incercari este: ");
                    set_color(RED);
                    printf("%d\n\n", scor);
                    set_color(WHITE);
                    set_color(BROWN);
                    printf("\n  |-----\n  |     |\n  |     |\n  |   (   )  \n  |     |\n  |    \\|/\n  |     |\n  |\n  |\n  |\n");
                    printf("-----\n");
                    set_color(WHITE);
                    set_color(MAGENTA);
                    printf("%s", cuvant_ascuns);
                    set_color(WHITE);
                    break;
                case 1:
                    printf("Numarul de incercari este: ");
                    set_color(RED);
                    printf("%d\n\n", scor);
                    set_color(WHITE);
                    set_color(BROWN);
                    printf("\n  |-----\n  |     |\n  |     |\n  |   (   )  \n  |     |\n  |    \\|/\n  |     |\n  |    / \\\n  |\n  |\n");
                    printf("-----\n");
                    set_color(WHITE);
                    set_color(MAGENTA);
                    printf("%s", cuvant_ascuns);
                    set_color(WHITE);
                    break;
                case 0:
                    printf("Numarul de incercari este: ");
                    set_color(RED);
                    printf("%d\n\n", scor);
                    set_color(WHITE);
                    set_color(BROWN);
                    printf("\n  |-----\n  |     |\n  |     |\n  |   (x x)  \n  |     |\n  |    \\|/\n  |     |\n  |    / \\\n  |\n  |\n");
                    printf("-----\n");
                    set_color(WHITE);
                    set_color(RED);
                    printf("Ai pierdut!\n");
                    set_color(WHITE);
                    printf("Scorul tau final este : ");
                    set_color(RED);
                    printf("%d\n", scor_player);
                    set_color(WHITE);
                    char nume[30];
                    printf("Introdu numele: ");
                    set_color(CYAN);
                    scanf("%s", &nume);
                    set_color(WHITE);
                    FILE* player_count = fopen("player_count.txt", "r");
                    fscanf(player_count, "%d", &player_number);
                    player_number++;
                    fclose(player_count);
                    player_count = fopen("player_count.txt", "w");
                    fprintf(player_count, "%d", player_number);
                    fclose(player_count);
                    if (player_number<30){
                        time_t t;
                        t=time(NULL);
                        struct tm tm=*localtime(&t);
                        strcpy(clas[player_number].nume, nume);
                        clas[player_number].scor=scor_player;
                        FILE* istoric = fopen("istoric.txt", "a");
                        fprintf(istoric, "[%d/%d/%d] %s : %d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, clas[player_number].nume, clas[player_number].scor);
                        FILE* fp = fopen("clasament.txt", "a");
                        fprintf(fp, "%s\n%d\n", clas[player_number].nume,  clas[player_number].scor);
                        fclose(fp);
                        fclose(istoric);
                    }else{
                        player_count = fopen("player_count.txt", "w");
                        fprintf(player_count, "%d", 0);
                        fclose(player_count);
                        FILE* fp = fopen("clasament.txt", "w");
                        fprintf(fp, "%s\n%d\n", nume, scor_player);
                        fclose(fp);
                    }

                    system("cls");
                    printf("Scorul a fost salvat!\n");
                    system("pause");
                    system("cls");
                    main();
                    break;
                }
                    if(gresit==0){
                        set_color(RED);
                        printf("\n\nGresit, incearca din nou");
                        set_color(WHITE);
                    }
                    if (if_letter==0){
                        set_color(RED);
                        printf("\n\nNu ati introdus o litera, incercati din nou");
                        set_color(WHITE);
                    }
                    gresit=1;
                    if_letter=1;
                    set_color(GREEN);
                    printf("\n\n(1)");
                    set_color(WHITE);
                    printf("Inapoi\n");
                    printf("\nIntrodu o litera: ");
                    set_color(MAGENTA);
                    scanf(" %c", &litera);
                    set_color(WHITE);
                    litera=tolower(litera);
                    ++runda;
                    ver=strlen(cuvant);
                    int contor=0;
                    if (isalpha(litera)){
                        for (int i=0; i<=strlen(cuvant);i++){
                            if (litera==cuvant[i]){
                                cuvant_ascuns[i]=cuvant[i];
                            }
                            else if (litera!=cuvant[i]){
                                ver--;
                            }
                            if (strcmp(cuvant, cuvant_ascuns)==0){
                                    scor_player+=strlen(cuvant_ascuns)-1;
                                    goto durere;
                                }
                        }
                    if (ver==-1){
                        scor--;
                        gresit=0;
                    }

                    system("cls");


                    }else if (litera=='1'){
                        system("cls");
                        main();
                        break;
                    }else{
                        if_letter=0;
                    }
                    system("cls");
                fflush(stdin);
            }

}

int main(){
    int choice=meniu_principal();
        if (choice==1) {
            choice_1();
            //system("pause");
        } else if (choice==2) {
            choice_2();
        } else if (choice==3){
            choice_3();
        } else {
            exit(0);
        }
        system("cls");

    return 0;
}
