#ifndef C
#define C

typedef struct{
	char last_name[255];
	char name[255];
	char tel[255];
	char email[255];
	char adress[255];
	char date[255];
	char place[255];
	char bacc[255];
	char sex[255];
	char CIN[255];
	char git[255];
}student_data;

int enter(int line, student_data* val, char* path, int* lines);
int line_number(char* path);
student_data getDataE();
student_data* scan_data(int line, student_data* val, char* path);
void trie(student_data* val,int line);
void print_data(student_data* val, int line);
#endif
