#include "pch.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "ControlesDaTela.cpp"
#include <string.h>

struct
{
	char nome[150];
	char end[200];
	char tel[15];
}agenda[4],aux;

int menu();
void cadastrar();
void ordenar();
void imprimir();
void sair();
void salvar();
void carregar();
void pesquisar();
int sel;

void main()
{
	setlocale(LC_ALL, "");
	while (1)
	{
		system("cls");
		sel = menu();
		switch (sel)
		{

		case 1: cadastrar();
			break;
		case 2: imprimir();
			break;
		case 3: ordenar();
			break;
		case 4: salvar();
			break;
		case 5: carregar();
			break;
		case 6 : pesquisar();
			break;
		//case 7: excluir();
			//break;
		case 8 : sair();
			break;

		default: 
			system("cls");
			gotoxy(30, 12);
			printf("Digite um item incorreto!");
			gotoxy(20, 13);
			printf("Digite um valor de acordo com o menu!");
			_getch();
			break;
		}
	}
}

int menu()
{
	int valor_sel;
	gotoxy(30, 5); printf("Agenda");
	gotoxy(30, 10); printf("1.Cadastrar");
	gotoxy(30, 11); printf("2.Imprimir");
	gotoxy(30, 12); printf("3.Fim");
	gotoxy(30, 13);
	printf("4.Ordenar");
	gotoxy(30, 14);
	printf("Digite a op��o desejada:");
	fflush(stdin);
	scanf_s("%i", &valor_sel);
	return valor_sel;
}

void cadastrar()
{
	int x;
	system("cls");
	for (x = 0; x < 4; x++)
	{
		if (x == 0)
			gets_s(agenda[x].nome);

		gotoxy(20, 5);
		printf("Cadastro:");
		gotoxy(20, 10);
		printf("Nome: ");
		gotoxy(20, 12);
		printf("Telefone: ");
		gotoxy(20, 11);
		printf("Endere�o: ");

		fflush(stdin);

		gotoxy(27, 10);
		gets_s(agenda[x].nome, sizeof(agenda[x].nome));
		gotoxy(31, 11);
		gets_s(agenda[x].end);
		gotoxy(31, 12);
		gets_s(agenda[x].tel);

		system("cls");

		//fgets(agenda[x].tel, 15, stdin);
		//setbuf(stdin,NULL);
	}
}

void imprimir()
{
	int x;
	for (x = 0; x < 4; x++)
	{
		system("cls");
		gotoxy(20, 5);
		printf("Cadastro:");

		gotoxy(20, 10);
		printf("Nome: ");
		gotoxy(27, 10);
		puts(agenda[x].nome);

		gotoxy(20, 11);
		printf("Endere�o: ");
		gotoxy(31, 11);
		puts(agenda[x].end);

		gotoxy(20, 12);
		printf("Telefone: ");
		gotoxy(31, 12);
		puts(agenda[x].tel);
		_getch();
	}
}


void ordenar() {
	
	int k, w;
	
	for (k = 0; k < 4 - 1; k++) {
		for (w = k + 1; w < 4; w++) {
			if (_strcmpi(agenda[k].nome, agenda[w].nome) > 0) {
				aux = agenda[k];
				agenda[k] = agenda[w];
				agenda[w] = aux;
			}
		}

	}

}

void salvar()
{
	int j;
	FILE *tp;
	errno_t err;
	if ((err = fopen_s(&tp, "cadastro.txt", "w")) != NULL) 
	{
		system("cls");
		gotoxy(30, 18);
		printf("N�o foi poss�vel salvar o arquivo");
		_getch();
	}
	else
	{
		for (j = 0; j < 4; j++) 
		{
			fwrite(&agenda[j], sizeof(agenda), 1, tp);
			fclose(tp);
		}
		system("cls");
		gotoxy(35, 18);
		printf("Sucesso!!!!");
		_getch();
		system("cls");
	}
}


void carregar()
{
	int j;
	FILE *tp;
	errno_t err;
	if ((err = fopen_s(&tp, "cadastro.txt", "r")) != NULL)
	{
		system("cls");
		gotoxy(30, 18);
		printf("N�o foi poss�vel ler o arquivo");
		_getch();
	}
	else
	{
		for (j = 0; j < 4; j++)
		{
			fread(&agenda[j], sizeof(agenda), 1, tp);
			fclose(tp);
		}
		system("cls");
		gotoxy(35, 18);
		printf("Sucesso!!!!");
		_getch();
		system("cls");
	}
}
void sair()
{
	exit(1);
}