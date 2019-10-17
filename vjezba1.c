#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE (1024)

typedef struct _student{

	char name[MAX_SIZE];
	char surname[MAX_SIZE];
	int absolutepoints;


} student;
typedef struct _student* pstud;

int CountStudentsFromFile(const char *);
int ReadStudentsFromFile(pstud , const char *);
int PrintResults(pstud, int, int);

int main(void)
{
	int count = 0;
	int MaxPoint = 0;
	pstud list = NULL;
	
	char Filename[MAX_SIZE] = "studenti.txt";
	count = CountStudentsFromFile(Filename);
	if( count > 0 )
	{
		list = (pstud)malloc(sizeof(student)*count);
		MaxPoint = ReadStudentsFromFile(list, Filename);
	
	}
	
	PrintResults(list, count, MaxPoint);
		
	
	
	
	return 0;
	
}
int CountStudentsFromFile(const char *Filename)
{
	int count = 0;
	int ch = 0;
	FILE *fp = NULL;
	fp = fopen(Filename,"r");
	
	do
	{
		ch=fgetc(fp);
		if(ch == '\n')
			count++;
	}
	while(ch!=EOF);
	if(ch !='\n' && count != 0)
		count++;
	
	fclose(fp);
	
	return count;
}
int ReadStudentsFromFile(pstud list, const char *Filename)	
{
	int MaxPoint = 0;
	FILE *fp = NULL;
	fp = fopen(Filename, "r");
	
	
	while(!feof(fp))
	{
		fscanf(fp, "%d %s %s",&list->absolutepoints, list->name, list->surname);
		if(list->absolutepoints > MaxPoint)
			MaxPoint = list->absolutepoints;
		list++;
	}
	
	fclose(fp);
	
	return MaxPoint;	
}
int PrintResults(pstud list, int count, int MaxPoint)
{	
	int i = 0;
	printf("\r\n\t\t%15s\t%15s\t%3s   %3s = %7s\r\n","Ime", "Prezime", "Bod", "Max", "RelBod");
	for(i = 0; i<count; i++)
	{
		printf("\r\n\t\t%15s\t%15s\t%3d / %3d = % 6.2f", list->name, list->surname, list->absolutepoints, MaxPoint, ((float)list->absolutepoints/MaxPoint) * 100);
		list++;
	}
	return 0;
}
	
	
	
	
	
	
	
	
	