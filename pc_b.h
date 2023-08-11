#ifndef C
#define C
typedef struct pc_data{
	char label[255];
	char pc[255];
	char mac[255];
	char git_link[255];
}pc_data;

int line_number();
pc_data* scan_data(int line, pc_data* val);
void trie(pc_data* val,int line);
void print_data(pc_data* val, int line);
#endif
