#include <stdio.h>
#include <process.h>

typedef struct student {
int roll;
char name[20];
float marks;

} stud;

void sort(int n)
{
	FILE *fp_index, *fp_record;
	int i, j, r1, r2, r3;
	stud s1, s2, s3;

	fp_index = fopen("index.txt", "r+b");
	fp_record = fopen("record.txt", "r+b");

		for (i = 0; i < n-1; i++)
		{
			for (j = 0; j < n-1; j++)
			{

				fseek(fp_record, sizeof(s1) * j, SEEK_SET);
				fseek(fp_index, sizeof(int) * j, SEEK_SET);

				fread(&r1, sizeof(int), 1, fp_index);
		
				fread(&r2, sizeof(int), 1, fp_index);

				if (r1 > r2) //swap record and index
				{
					fread(&s1, sizeof(s1), 1, fp_record);
					fread(&s2, sizeof(s2), 1, fp_record);

					fseek(fp_record, (sizeof(s1)) * j, SEEK_SET);
					fseek(fp_index, (sizeof(int)) * j, SEEK_SET);
					fwrite(&r2, sizeof(int), 1, fp_index);
					fwrite(&r1, sizeof(int), 1, fp_index);

					fwrite(&s2, sizeof(s1), 1, fp_record);
					fwrite(&s1, sizeof(s1), 1, fp_record);
				}
			}
		}

		fclose(fp_index);
		fclose(fp_record);

}

void add()
{
	int n = 0;
	float temp;
	FILE *fp_index, *fp_record;
	stud s1;
	fp_index = fopen("index.txt", "r+b");
	fp_record = fopen("record.txt", "r+b");

	printf("\n\nEnter roll no: ");
	scanf("%d", &s1.roll);
	printf("\nEnter Name: ");
	scanf("%s", s1.name);
	printf("\nEnter marks: ");
	scanf("%f", &temp);
	s1.marks = temp;

	fseek(fp_record, 0, SEEK_END);

	if (fwrite(&s1, sizeof(s1), 1, fp_record))
	{
		fseek(fp_index, 0, SEEK_END);
		fwrite(&(s1.roll), sizeof(int), 1, fp_index);
	}
	else
	{
		printf("\n\nCould NOT add !!!");
	}
	rewind(fp_index);
	while ((fread(&s1, sizeof(int), 1, fp_index)))
		n++;

	fclose(fp_index);
	fclose(fp_record);

	if (n > 1)
		sort(n);
}

void edit(int r_n)
{
	int r, loc, rec, flag = 0;
	float temp;
	FILE *fp_index, *fp_record;
	stud s2;

	fp_index = fopen("index.txt", "r+b");
	fp_record = fopen("record.txt", "r+b");

	while (fread(&r, sizeof(int), 1, fp_index))
	{
		if (r == r_n)
		{
			flag = 1;

			break;
		}
	}
	if (!flag)
	{
		printf("\n\nRecord NOT found !!!");
	}
	else
	{
		fseek(fp_index, (-1) * sizeof(int), SEEK_CUR);
		loc = ftell(fp_index);

		fseek(fp_record, loc / sizeof(int) * sizeof(s2), SEEK_SET);

		fread(&s2, sizeof(s2), 1, fp_record);

		printf("\n\nRoll :%d", s2.roll);
		printf("\n\nName :%s", s2.name);
		printf("\n\nMarks :%f", s2.marks);

		printf("\nEnter New Name : ");
		scanf("%s", &s2.name);
		printf("\nEnter New marks : ");
		scanf("%f", &temp);
		s2.marks = temp;

		fseek(fp_record, (-1) * sizeof(s2), SEEK_CUR);

		if(!(fwrite(&s2, sizeof(s2), 1, fp_record)))
			printf("\n\nCould NOT modified !!!");

	}

	printf("\n\n");
	fclose(fp_index);
	fclose(fp_record);

}

void search(int r_n)
{
	int r, loc, flag = 0;
	float temp;
	FILE *fp_index, *fp_record;
	stud s2;

	fp_index = fopen("index.txt", "r+b");
	fp_record = fopen("record.txt", "r+b");

	while (fread(&r, sizeof(int), 1, fp_index))
	{
		if (r == r_n)
		{
			flag = 1;

			break;
		}
	}
	if (!flag)
	{
		printf("\n\nRecord NOT found !!!");
	}
	else
	{
		fseek(fp_index, (-1) * sizeof(int), SEEK_CUR);
		loc = ftell(fp_index);
		fseek(fp_record, loc / sizeof(int) * sizeof(s2), SEEK_SET);
		fread(&s2, sizeof(s2), 1, fp_record);

		printf("\n\nRoll :%d", s2.roll);
		printf("\n\nName :%s", s2.name);
		printf("\n\nMarks :%f", s2.marks);
	}

	printf("\n\n");
	fclose(fp_index);
	fclose(fp_record);
}

void display()
{
	FILE *fp;
	int flag = 1;
	stud s2;
	fp = fopen("record.txt", "rb");

	while (fread(&s2, sizeof(s2), 1, fp))
	{
		if ((s2.roll) != 0)
		{
			if (flag == 1)
				printf("\n\nRoll No Name marks");
			flag = 0;
			printf("\n\n%d", s2.roll);
			printf(" %s", s2.name);
			printf(" %f", s2.marks);
		}
	}
	if (flag == 1)
		printf("\n\nNo record found !!!");
	printf("\n\n");
	fclose(fp);
}
void delet(stud *s2, int r_n)
{
	FILE *temp_fp, *fp;

	fp = fopen("g.txt", "r+b");
	temp_fp = fopen("temp.txt", "r+b");

	while (fread(s2, sizeof(*s2), 1, fp))
	{
		if ((s2->roll) != r_n)
		{
			fseek(temp_fp, sizeof(*s2) * ((s2->roll)-1), 0);
			fwrite(s2, sizeof(*s2), 1, temp_fp);
		}
	}

	fclose(fp);
	unlink("g.txt");
	rename("temp.txt", "g.txt");

	fclose(temp_fp);
	printf("\n\n");
}

int main()
{
	FILE *fp;
	stud s1, s2;
	int choice, roll_no;


	fp = fopen("record.txt", "a+b");
	fclose(fp);
	fp = fopen("temp.txt", "a+b");
	fclose(fp);
	fp = fopen("index.txt", "a+b");
	fclose(fp);

	while (1)
	{
		printf("\n\n1:Add 2:Display 3:Search 4:Edit 5:Delete 6:Exit \n\n");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				add();
				break;
			case 2:

				display();

				break;
			case 3:
				printf("\n\nEnter Roll No To Search Record : ");
				scanf("%d", &roll_no);
				search(roll_no);

				break;
			case 4:
				printf("\n\nEnter Roll No To Edit Record : ");
				scanf("%d", &roll_no);

				edit(roll_no);

				break;
			case 5:
				printf("\n\nEnter Roll No To Delete Record : ");
				scanf("%d", &roll_no);

				delet(&s2, roll_no);

				break;
			case 6:
				exit(0);

			default:
				printf("\n\nInvalid choice !!!");
		}
	}

getch();
return 0;
}
