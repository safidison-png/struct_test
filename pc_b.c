#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ta 10000
#include "pc_b.h"

void trie(pc_data* val,int line){
    pc_data tmp;
    int stop = 0;
    while (stop==0){
        stop = 1;
        for (int i=1;i<line-1;i++){
            if (strcmp(val[i].label,val[i+1].label)>0){
                tmp = val[i];
                val[i] = val[i+1];
                val[i+1] = tmp; 
                stop = 0;
            }
        }
    }
    printf("Loading sort.....\n");
}

int line_number(){
	char isa[255];
	FILE *asa = popen("cat /home/safidison/Documents/pc_info.csv | wc -l", "r");
	fgets(isa, 255,  asa);
	int a = atoi(isa);
	return a;
}

pc_data* scan_data(int line, pc_data* val){
	FILE* spc = NULL;
	spc = fopen("/home/safidison/Documents/pc_info.csv","r");
	for(int i=0;i<line;i++){
		char ch[255];
		fgets(ch,255,spc);
		sscanf(ch,"%[^,],%[^,],%[^,],%[^\n]",val[i].pc,val[i].mac,val[i].label,val[i].git_link);
		//printf("%s, %s, %s", val[i].pc,val[i].mac,val[i].label);
	}
	fclose(spc);
	return val;
}
void print_data(pc_data* val, int line){
	FILE* fpc = NULL;
	fpc = fopen("/home/safidison/Documents/pc_label.csv","w+");
	for(int i=0;i<line;i++){
		fprintf(fpc, "%s,%s,%s,%s\n", val[i].label, val[i].pc, val[i].mac, val[i].git_link);
	}
	fclose(fpc);
}
