#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_b.h"
#define ta 10000

int main(){
	student_data* val = NULL;
	int line = 0, lines;
	char* path= malloc(ta);
	val = malloc(sizeof(student_data)*ta);
	line = enter(line, val, path, &lines);
	if(lines>0&&lines<4){
		trie(val, line);
		print_data(val, line);
		printf("SUCCESS");
	}
	
	return 0;
}
