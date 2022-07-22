#include<iostream>
#include<windows.h>
#include<iomanip>
#include<string>
#include<vector>
#include<fstream>
#include<conio.h>

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

enum ConsoleColor
{
	black = 0,
	dark_blue = 1,
	dark_green = 2,
	dark_aqua, dark_cyan = 3,
	dark_red = 4,
	dark_purple = 5, dark_pink = 5, dark_magenta = 5,
	dark_yellow = 6,
	dark_white = 7,
	gray = 8,
	blue = 9,
	green = 10,
	aqua = 11, cyan = 11,
	red = 12,
	purple = 13, pink = 13, magenta = 13,
	yellow = 14,
	white = 15
};
#include"User.h"
#include"Admin.h"
#include"Box.h"
#include"Funktions.h"
#include"Question.h"
// SetConsoleTextAttribute(hConsole, yellow);




int main() {
	short oop = 0;
	short UserWiew = 0;
	string temp_name;
	string temp_password;
	short level = 0;
	vector<int> UserNumbers;
	size_t correct = 0;
	size_t wrong = 0;
	size_t passed = 0;

	while (true)
	{
		Question question;
		
		system("cls");
		if (UserWiew == 0) {
			question.MainMenu(UserWiew, oop);
		}
		else if (UserWiew == 1) {
			fstream admins("Admins.txt", ios::in);
			cout << "Enter your name: ";
			cin >> temp_name;
			cout << "Enter your password: ";
			cin >> temp_password;
			if (question.LogIn(temp_name, temp_password, admins)) {
				UserWiew = 4;
			}
			else {
				cout << "! CANT LOGIN !" << endl;
				UserWiew = 0;
			}
		}
		else if (UserWiew == 2) {
			fstream players("Players.txt", ios::in);
			cout << "Enter your name: ";
			cin >> temp_name;
			cout << "Enter your password: ";
			cin >> temp_password;
			if (question.LogIn(temp_name, temp_password, players))
				UserWiew = 5;
			else
				UserWiew = 0;
		}
		else if (UserWiew == 3)
			question.Register(UserWiew, oop, temp_name, temp_password);
		else if (UserWiew == 4)
			question.AdminWiew(UserWiew, oop, temp_name);
		else if (UserWiew == 5) {
			fstream topOf("TopOf.txt", ios::out);
			question.PlayerWiew(UserWiew, oop, correct, wrong, passed,topOf);
		}
	}








}

