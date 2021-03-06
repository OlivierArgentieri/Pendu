// Pendu.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "windows.h"
#include <conio.h>
using namespace std;


bool gameOver;
string departWord;
char departWordTab[1024];
char userWordTab[1024];
int error;

bool firstLoop = true;

void Init() {
	gameOver = false;
	while (empty(departWord)) {
		cout << "Entrez ce qu'il faut trouver : ";
		getline(std::cin, departWord);
		strcpy_s(departWordTab, departWord.c_str());
	}
	for (int i = 0; departWordTab[i] != 'þ'&& departWordTab[i] != '\0'; i++)
	{
		if (departWordTab[i] != ' ') {
			userWordTab[i] = '_';
		}
		else {
			userWordTab[i] = ' ';
		}
	}
}

void Draw() {
	system("cls");

	switch (error) {
	case 0:
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		break;
	case 1:
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "_______________" << endl;
		break;
	case 2:
		cout << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "_______________" << endl;
		break;
	case 3:
		cout << "______________________________" << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "_______________" << endl;
		break;
	case 4:
		cout << "______________________________" << endl;
		cout << "      ||                  | " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "_______________" << endl;
		break;
	case 5:
		cout << "______________________________" << endl;
		cout << "      ||                  | " << endl;
		cout << "      ||                  O " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "_______________" << endl;
		break;
	case 6:
		cout << "______________________________" << endl;
		cout << "      ||                  | " << endl;
		cout << "      ||                  O " << endl;
		cout << "      ||                  |      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "_______________" << endl;
		break;
	case 7:
		cout << "______________________________" << endl;
		cout << "      ||                  | " << endl;
		cout << "      ||                  O " << endl;
		cout << "      ||                  |      " << endl;
		cout << "      ||                   \\ " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "_______________" << endl;
		break;
	case 8:
		cout << "______________________________" << endl;
		cout << "      ||                  | " << endl;
		cout << "      ||                  O " << endl;
		cout << "      ||                  |      " << endl;
		cout << "      ||                 / \\ " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "_______________" << endl;
		break;
	case 9:
		cout << "______________________________" << endl;
		cout << "      ||                  | " << endl;
		cout << "      ||                  O " << endl;
		cout << "      ||                 -|- " << endl;
		cout << "      ||                 / \\ " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "      ||      " << endl;
		cout << "_______________" << endl;
		break;
	}

	cout << endl << endl;
	for (int i = 0; departWordTab[i] != 'þ'; i++)
	{
		cout << userWordTab[i];
	}
	cout << endl << endl << "Nombre essai : " << error << " / 9";
	if (error == 9)
	{
		cout << endl << " GAME OVER : YOU LOOSE !!";
	}

	if (userWordTab == departWord) {
		cout << endl << " YOU WIN !! ";
		gameOver = true;
	}
}

void Input() {
	if (!firstLoop)
	{
		char c = _getch();
		if (c != '\0') {
			bool trouver = false;
			for (int i = 0; departWordTab[i] != 'þ'; i++)
			{
				if (c == departWordTab[i] && c != userWordTab[i]) {
					userWordTab[i] = departWordTab[i];
					trouver = true;
				}
			}
			if (!trouver) {
				error++;
			}
		}
	}
}

void Logic() {
	firstLoop = false;
	if (error == 9) {
		gameOver = true;
	}
}

int main()
{
	Init();
	while (!gameOver)
	{
		Input();
		Draw();
		Logic();
	}
	string str;
	getline(cin, str);
	return 0;
}