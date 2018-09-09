#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define count 3
//#include<conio.h>

typedef struct emp {
	int empid;
	char name[20];
	double salary;
	char position[20];
	int joindate;
};

struct emp emps[100];
int total = 0;

void create();
void display();
void update();
void delet();

void main() {
	int choice = 5;
	int counter1 = 0;


	printf("\n\t\t\tWelcome to Employee Management Program\n\n");
	printf("\n\t1] Create new employee");
	printf("\n\t2] Display all employees");
	printf("\n\t3] Edit employee details");
	printf("\n\t4] Delete employee record");
	printf("\n\t5] Exit");


	while(1) {
		printf("\n\nEnter your choice");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				create();
			break;
			case 2:
				display();
			break;
			case 3:
				update();
			break;
			case 4:
				delet();
			break;
			case 5:
				exit(0);
		}
	}
}

void create() {
	int counter2 = 0;

	printf("\nEnter the number of employees that you want to create:");
	scanf("%d", &total);
	printf("\n\tCreating new employee record(s)");
	for(counter2=0;counter2<total;counter2++) {
		printf("\n Enter employee id: ");
		scanf("%d", &emps[counter2].empid);
		printf("\n Enter employee name: ");
		scanf("%s", emps[counter2].name);
		printf("\n Enter Salary: ");
		scanf("%ld", &emps[counter2].salary);
		printf("\nEnter position: ");
		scanf("%s", emps[counter2].position);
	}
}

void display() {
	int counter3 = 0;

	printf("\n\n\tDisplaying all employee details: ");
	printf("\nempid \t emp name \t position \t salary\n");
	for(counter3=0;counter3<total;counter3++) {
		printf("\n%d \t %s \t %s \t %ld", emps[counter3].empid, 
			emps[counter3].name, emps[counter3].position, 
			emps[counter3].salary);
	}
}

void update() {
	int updid = 0;
	int counter4 = 0;
	int found = 0;
	
	printf("\n\nEnter employee id to edit: ");
	scanf("%d", &updid);
	for(counter4=0;counter4<3;counter4++) {
		if(emps[counter4].empid == updid) {
			found = 1;
			break;
		}
	}
	
	if (found == 1) {
		printf("\nEnter name to update: ");
		scanf("%s", emps[updid-1].name);
		printf("\n Enter Salary: \t");
		scanf("%ld", &emps[updid-1].salary);
		printf("\nEnter position: \t");
		scanf("%s", emps[updid-1].position);
	}
}

void delet() {
	int deleid = 0;
	int counter4 = 0;
	int found = 0;
	struct emp *delemp;
	
	printf("\n\nEnter employee id to edit: ");
	scanf("%d", &deleid);

	
		for(counter4=deleid - 1;counter4<total - 1;counter4++) {
			emps[counter4] = emps[counter4 + 1];
		}
		
		printf("\n\nList of remaining employees:");
		for(counter4=0;counter4<total - 1;counter4++) {
			printf("\n%d\t%s", emps[counter4].empid, emps[counter4].name);
		}
		total = total - 1;		
}
