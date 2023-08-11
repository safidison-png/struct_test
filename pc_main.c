#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ta 10000
#include "pc_b.h"

int main(){
	pc_data* val = NULL;
	int line = line_number();
	val = malloc(sizeof(pc_data)*line);
	val = scan_data(line, val);
	trie(val, line);
	print_data(val, line);
	printf("SUCCESS");
	
	return 0;
}
