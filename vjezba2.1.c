#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MAX_NAME_BUFFER (1024)

typedef struct Osoba * Pozicija;
typedef struct Osoba{
	
	char Ime[MAX_NAME_BUFFER];
	char Prezime[MAX_NAME_BUFFER];
	int Godina;
	Pozicija Next;
} Osoba;

int DodajElementNaPocetak(char *, char *, int, Pozicija );
int DodajElementNaKraj(char*, char*, int, Pozicija );
int IspisiListu(Pozicija );
Pozicija TraziPoPrezimenu( char *, Pozicija );
Pozicija TraziPret(char *, char *, int, Pozicija );
int BrisiElement(char*, char *, int, Pozicija );

int main(void)
{
	Osoba Head;
	Pozicija TrazeniElement;
	char ime1[MAX_NAME_BUFFER] = "Ivan";
	char prezime1[MAX_NAME_BUFFER] = "Mladina";
	char ime2[MAX_NAME_BUFFER] = "Jozo";
	char prezime2[MAX_NAME_BUFFER] = "Krstanovic";			//Radimo na omogucavanju unosa s tipkovnice
	char ime3[MAX_NAME_BUFFER] = "Ante";
	char prezime3[MAX_NAME_BUFFER] = "Antic";
	char traziprezime[MAX_NAME_BUFFER] = "Mladina";
	
	int godina1 = 1999;
	int godina2 = 2000;
	int godina3 = 2001;


	Head.Next = NULL;
	
	DodajElementNaPocetak(ime1, prezime1, godina1, &Head);
	DodajElementNaKraj(ime2, prezime2, godina2, &Head);				//Dodavanje nekoliko elemenata
	DodajElementNaKraj(ime3, prezime3, godina3, &Head); 
	IspisiListu(&Head);
	
	TrazeniElement = TraziPoPrezimenu( traziprezime, &Head );										//Poziv funkcije za trazenje elementa
	printf("\n %s %s %d", TrazeniElement->Ime, TrazeniElement->Prezime, TrazeniElement->Godina);	//Provjera ispravnosti funkcije trazenielement

	printf("\n\nnakon brisanja:");
	BrisiElement(ime3, prezime3, godina3, &Head);		//Brisanje jednog elementa
	IspisiListu(&Head);									//Ispis liste poslije brisanja



	return 0;

}
 
int DodajElementNaPocetak(char *ime, char *prezime, int godina, Pozicija P )
{
	Pozicija q;
	q = (Pozicija)malloc(sizeof(Osoba));
	strcpy(q->Ime, ime);
	strcpy(q->Prezime, prezime);
	q->Godina = godina;
	q->Next = P->Next;
	P->Next = q;
	
	return 0;
}

int IspisiListu( Pozicija P)
{
	P = P->Next;
	while(P!=NULL)
	{
		printf("\n %s %s  %d", P->Ime, P->Prezime, P->Godina);
		P = P->Next;
	}

	return 0;
}

int DodajElementNaKraj(char* ime, char* prezime, int godina, Pozicija P)
{
	Pozicija q;
	q = (Pozicija)malloc(sizeof(Osoba));
	strcpy(q->Ime, ime);
	strcpy(q->Prezime, prezime);
	q->Godina = godina;
	while (P->Next != NULL)
		P = P->Next;
	q->Next = P->Next;
	P->Next = q;

		return 0;
}

Pozicija TraziPoPrezimenu( char *prezime, Pozicija P )
{
	while( P != NULL && strcmp(P->Prezime, prezime) != 0 )			//algoritam koji sam nasao da radi, moguce su promjene i poboljsanja
		{
			P = P->Next;							
		}
	if( P == NULL )
		printf("Nema tog prezimena");		//provjera u slucaju da nema tog elementa liste
	
	return P;
	
}

Pozicija TraziPret(char* ime, char* prezime, int godina, Pozicija P) 
{
	Pozicija Pret = P;
	P = P->Next;
	while ((P != NULL) && ( strcmp(P->Ime, ime) != 0 || strcmp(P->Prezime, prezime) != 0 || P->Godina != godina)) 
	{
		Pret = P;
		P = P->Next;
	}
	if (P == NULL){
		printf("GRESKA");
		return NULL;
	}
	else 
		return Pret;
}

int BrisiElement(char* ime, char* prezime, int godina, Pozicija P) 
{
	Pozicija temp;
	P = TraziPret(ime, prezime, godina, P);

	temp = P->Next;										
	P->Next = P->Next->Next;
	free(temp);
	return 0;
}