#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ta 10000
#include "student_b.h"

int enter(int line, student_data* val, char* path, int* lines){
	int choice = 0;
	printf("Choisir ce que vous voulez faire:\n1-Recuperer des donnees dans un fichier pour ajouter au fichier des informations des etudiants\n2-Recupere des donnees complets aux entrees standars\n3-Ajouter ou modifier d'autres informations d'un eleve\n4-Connaitre le numero d'un eleve avec son nom\n=>");
	scanf("%d", &choice);
	*lines = choice;
	if(choice==1){
		printf("Entrer le chemin complet du fichier: ");
		scanf("%s", path);
		line = line_number(path);
		val = scan_data(line, val, path);
	}
	else if(choice==2){
		int nbr_std = 0;
		printf("Enter le nombre d'etudiant a entrer: ");
		scanf("%d", &nbr_std);
		strcpy(path, "/home/safidison/Documents/student_info.csv");
		line = line_number(path);
		val = scan_data(line, val, path);
		for(int i=line;i<line+nbr_std;i++){
			val[i] = getDataE();
		}
		line+=nbr_std;
	}
	else if(choice==3){
		int fidy = 0, c=-1;
		char anarana[50];
		strcpy(path, "/home/safidison/Documents/student_info.csv");
		line = line_number(path);
		val = scan_data(line, val, path);
		while(c<0){
			printf("1-Chercher avec le nom\n2-Chercher avec le numero\n=>");
			int saf = 0;
			scanf("%d", &saf);
			if(saf==1){
				printf("Donner le nom d'eleve pour y ajouter des informations: ");
				scanf("%s", anarana);
				for(int i=0;i<line;i++){
					if(strcmp(val[i].last_name,anarana)==0){
						c=i;
						break;
					}
				}
			}
			else if(saf==2){
				printf("Donner le numero: ");
				int num;
				scanf("%d", &num);
				c = (num>0&&num<=line)?num:0;
			}
			else{
				printf("Mauvais choix\n");
			}
			if(c<0||c>line)printf("Le nom ou le numero n'existe pas dans le fichier\n");
		}
		printf("Quelle information voulez-vous ajouter: \n1-Tel\n2-Email\n3-Adresse\n4-Date de naissance\n5-Lieu de naissance\n6-Annee d'obtention bacc\n7-Genre\n8-CIN\n9-Lien github\n10-Nom\n11-Prenom\n=>");
		char valiny[50];
		scanf("%d", &fidy);
		switch(fidy){
			case 1:
				printf("Tel: ");
				scanf("%s", valiny);
				strcpy(val[c].tel,valiny);
				break;
			case 2:
				printf("Email: ");
				scanf("%s", valiny);
				strcpy(val[c].email,valiny);
				break;
			case 3:
				printf("Adressse: ");
				scanf("%s", valiny);
				strcpy(val[c].adress,valiny);
				break;
			case 4:
				printf("Date de naissance: ");
				scanf("%s", valiny);
				strcpy(val[c].date,valiny);
				break;
			case 5:
				printf("Lieu de naissance: ");
				scanf("%s", valiny);
				strcpy(val[c].place,valiny);
				break;
			case 6:
				printf("Date d'obtention bacc: ");
				scanf("%s", valiny);
				strcpy(val[c].bacc,valiny);
				break;
			case 7:
				printf("Genre: ");
				scanf("%s", valiny);
				strcpy(val[c].sex,valiny);
				break;
			case 8:
				printf("CIN: ");
				scanf("%s", valiny);
				strcpy(val[c].CIN,valiny);
				break;
			case 9:
				printf("Lien github: ");
				scanf("%s", valiny);
				strcpy(val[c].git,valiny);
				break;
			case 10:
				printf("Nom : ");
				scanf("%s", valiny);
				strcpy(val[c].last_name,valiny);
				break;
			case 11:
				printf("Prenomh : ");
				scanf("%s", valiny);
				strcpy(val[c].name,valiny);
				break;
			default:
				printf("Mauvais choix\n");
				break;
		}
	}
	else if(choice==4){
		char anarana[50];
		int c=0;
		strcpy(path, "/home/safidison/Documents/student_info.csv");
		line = line_number(path);
		val = scan_data(line, val, path);
		printf("Donner le nom de l'eleve: ");
		scanf("%s", anarana);
		for(int i=0;i<line;i++){
			if(strcmp(val[i].last_name,anarana)==0){
				c=i;
				break;
			}
		}
		printf("%s est numero %d\n", anarana, c);
	}
	else {
		printf("Votre choix n'est pas valide\n");
	}
	return line;
	
}

student_data getDataE(){
    student_data etd;
    printf("Entrer nom: ");
    scanf("%s",etd.last_name);
    printf("Entrer prenom: ");
    scanf("%s",etd.name);
    printf("Entrer numero tel: ");
    scanf("%s",etd.tel);
    printf("Entrer mail: ");
    scanf("%s",etd.email);
    printf("Entrer addresse: ");
    scanf("%s",etd.adress);
    printf("Entrer date de naissance: ");
    scanf("%s",etd.date);
    printf("Entrer lieu de naissance: ");
    scanf("%s",etd.place);
    printf("Entrer date d'obtention bacc: ");
    scanf("%s",etd.bacc);
    printf("Entrer sexe: ");
    scanf("%s",etd.sex);
    printf("Entrer CIN: ");
    scanf("%s",etd.CIN);
    printf("Entrer le lien github: ");
    scanf("%s", etd.git);
    return etd;
}

void trie(student_data* val,int line){
    student_data tmp;
    int stop = 0;
    while (stop==0){
        stop = 1;
        for (int i=1;i<line-1;i++){
            if (strcmp(val[i].last_name,val[i+1].last_name)>0){
                tmp = val[i];
                val[i] = val[i+1];
                val[i+1] = tmp; 
                stop = 0;
            }
        }
    }
    printf("Loading sort.....\n");
}

int line_number(char* path){
	char isa[255];
	//~ char s[50] = "/home/safidison/Documents/sinfo.csv";
	char ad[ta] = "cat ";
	FILE *asa = popen((strcat(strcat(ad,path),"| wc -l")), "r");
	fgets(isa, 255,  asa);
	int a = atoi(isa);
	return a;
}

student_data* scan_data(int line, student_data* val, char* path){
	FILE* spc = NULL;
	spc = fopen(path,"r");
	for(int i=0;i<line;i++){
		char ch[255];
		fgets(ch,255,spc);
		sscanf(ch,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",val[i].last_name,val[i].name,val[i].tel,val[i].email,val[i].adress,val[i].date,val[i].place,val[i].bacc,val[i].sex,val[i].CIN,val[i].git);
		//printf("%s, %s, %s", val[i].pc,val[i].mac,val[i].label);
	}
	fclose(spc);
	return val;
}

void print_data(student_data* val, int line){
	FILE* fpc = NULL;
	fpc = fopen("/home/safidison/Documents/student_info.csv","w+");
	for(int i=0;i<line;i++){
		fprintf(fpc, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", val[i].last_name,val[i].name,val[i].tel,val[i].email,val[i].adress,val[i].date,val[i].place,val[i].bacc,val[i].sex,val[i].CIN,val[i].git);
	}
	fclose(fpc);
}
