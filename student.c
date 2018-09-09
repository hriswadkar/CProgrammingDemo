#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define size 200

struct student {
	int id; 
	char *name;
}

*stu1, *stu2;

void display(); 
void create(); 
void update();

FILE *fp, *fp1; int count = 0;

int main(int argc, char **argv) {

	int i, n, ch;

	printf("1] Create a Record\n"); 
	printf("2] Display Records\n"); 
	printf("3] Update Records\n"); 
	printf("4] Exit");

	while (1) {
 		printf("\nEnter your choice : "); scanf("%d", &ch);
		switch (ch) {
			case 1:
				fp = fopen(argv[1], "a"); 
				create();
				break; 
			case 2:
				fp1 = fopen(argv[1],"rb"); 
				display();
				break; 
			case 3:
				fp1 = fopen(argv[1], "r+"); 
				update();
				break; 
			case 4:
				exit(0);
		}
	}
	return 0;
}

void create() {
	int i; char *p;

	stu1= (struct student *)malloc(sizeof(struct student)); 
	stu1->name = (char *)malloc((size)*(sizeof(char))); 
	printf("Enter name of student : ");
	scanf(" %[^\n]s", stu1->name); 
	printf("Enter student id : "); 
	scanf(" %d", &stu1->id);
	fwrite(&stu1->id, sizeof(stu1->id), 1, fp); 
	fwrite(stu1->name, size, 1, fp);
	count++; // count to number of entries of records fclose(fp);
}

void display() {
	stu2=(struct student*)malloc(1*sizeof(struct student)); 
	stu2->name=(char *)malloc(size*sizeof(char));
	int i = 1;

	if (fp1 == NULL)
 		printf("\nFile not opened for reading"); 
		 
 	while (i <= count) {
		fread(&stu2->id, sizeof(stu2->id), 1, fp1); 
		fread(stu2->name, size, 1, fp1); 
		printf("\n%d %s",stu2->id,stu2->name); i++;
	}

	fclose(fp1); 
	free(stu2->name); 
	free(stu2);
}

void update() {
	int id, flag = 0, i = 1; 
	char s[size];

	if (fp1 == NULL) {
		printf("File cant be opened"); return;
	}

	printf("Enter student id to update : "); 
	scanf("%d", &id);
	stu2= (struct student*)malloc(1*sizeof(struct student)); 
	stu2->name=(char *)malloc(size*sizeof(char));

	while(i<=count) {
		fread(&stu2->id, sizeof(stu2->id), 1, fp1); 
		fread(stu2->name,size,1,fp1);
	
		if (id == stu2->id) {
			printf("Enter new name of student to update : "); 
			scanf(" %[^\n]s", s);
			fseek(fp1, -204L, SEEK_CUR); 
			fwrite(&stu2->id, sizeof(stu2->id), 1, fp1); 
			fwrite(s, size, 1, fp1);
			flag = 1; 
			break;
		}
		i++;
	}

	if (flag != 1) {
		printf("No student record found"); flag = 0;
	}
 
	fclose(fp1);
	free(stu2->name);	/* to free allocated memory */ 
	free(stu2);
}

