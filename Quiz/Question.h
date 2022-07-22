#pragma once

class Question {
public:

	string text;
	string answer1;
	string answer2;
	string answer3 = "empty";
	string answer4 = "empty";
	char correct;
	size_t turn = 0;

	Question() = default;

	Question(string text, char correct, string answer1, string answer2, string answer3 = " ", string answer4 = " ")
	{
		this->text = text;
		this->correct = correct;
		this->answer1 = answer1;
		this->answer2 = answer2;
		this->answer3 = answer3;
		this->answer4 = answer4;
	}

	void writeToFile(fstream& box) {
		box << text << "\n";
		box << answer1 << "\n";
		box << answer2 << "\n";
		box << answer3 << "\n";
		box << answer4 << "\n";
		box << correct << "\n";
	}

	void MainMenu(short& UserWiew, short oop) {
		int controller = 0;
		while (true)
		{
			system("cls");
			if (controller == 0)
				cout << ">> Join as Admin" << endl;
			else
				cout << "Join as Admin" << endl;

			if (controller == 1)
				cout << ">> Join as Player" << endl;
			else
				cout << "Join as Player" << endl;
			if (controller == 2)
				cout << ">> Register" << endl;
			else
				cout << "Register" << endl;
			if (controller == 3)
				cout << ">> Join as Guest" << endl;
			else
				cout << "Join as Guest" << endl;


			oop = _getch();
			if (oop == 115)
				if (controller == 3)
					controller = 0;
				else
					controller++;
			else if (oop == 119)
				if (controller == 0)
					controller = 3;
				else
					controller--;
			else if (oop == 13) {
				if (controller == 0)
					UserWiew = 1;
				else if (controller == 1)
					UserWiew = 2;
				else if (controller == 2)
					UserWiew = 3;
				else if (controller == 3)
					UserWiew = 5;

				break;
			}

		}
	}


	bool LogIn(string name, string password, fstream& admins) {
		string data;
		admins.seekg(ios::beg);

		while (!admins.eof())
		{
			getline(admins, data);
			if (data == name) {
				getline(admins, data);
				if (data == password)
					return true;
			}
		}
		return false;
	}

	void Register(short& UserWiew, short oop, string temp_name, string temp_password) {
		int controller = 0;
		while (true) {
			system("cls");
			if (controller == 0)
				cout << ">> Register as Admin" << endl;
			else
				cout << "Register as Admin" << endl;

			if (controller == 1)
				cout << ">> Register as User" << endl;
			else
				cout << "Register as User" << endl;
			if (controller == 2) {
				SetConsoleTextAttribute(hConsole, red);
				cout << endl << endl << endl << endl << endl << setw(100) << ">> (return to main menu) Return back  ";
				SetConsoleTextAttribute(hConsole, white);
			}
			else
				cout << endl << endl << endl << endl << endl << setw(100) << "Return back" << endl;


			oop = _getch();
			if (oop == 115) {
				if (controller == 2)
					controller = 0;
				else
					controller++;
			}
			else if (oop == 119)
				if (controller == 0)
					controller = 2;
				else
					controller--;
			else if (oop == 13) {
				if (controller == 0) {
					system("cls");
					cout << "Enter your name: ";
					cin >> temp_name;
					cout << "Enter your password: ";
					cin >> temp_password;
					fstream admins("Admins.txt", ios::app);
					Admin admin(JuniorAdmin, temp_name, temp_password, 0);
					admin.WriteToFile(admins);
					UserWiew = 4;
				}
				else if (controller == 1) {
					system("cls");
					cout << "Enter your name: ";
					cin >> temp_name;
					cout << "Enter your password: ";
					cin >> temp_password;
					fstream players("Players.txt", ios::app);
					Player player(temp_name, temp_password, 0);
					player.WriteToFile(players);
					UserWiew = 4;
				}
				else if (controller == 2) {
					UserWiew = 0;
					break;
				}
			}
		}

	}

	void showBoxes() {
		system("cls");
		fstream names("BoxNames.txt", ios::in);
		string data;
		names.seekg(ios::beg);
		while (!names.eof()) {
			getline(names, data);
			if (data != "")
				cout << "Name: " << data << endl;
		}
	}

	void AdminWiew(short& UserWiew, short oop, string temp_name) {
		string fileName;
		size_t size = 0;
		Box QuestionBox;
		int controller = 1;

		while (true)
		{
			system("cls");
			if (controller == 0) 
				cout << ">> Add Question Box" << endl;
			else
				cout << "Add Question Box" << endl;
			if (controller == 1)
				cout << ">>  Add Question to Box" << endl;
			else
				cout << "Add Question to Box" << endl;
			if (controller == 2)
				cout << ">>  Boxes" << endl;
			else
				cout << "Boxes" << endl;
			if (controller == 3) {
				SetConsoleTextAttribute(hConsole, red);
				cout << endl << endl << endl << endl << endl << setw(100) << ">> (return to main menu) Return back  ";
				SetConsoleTextAttribute(hConsole, white);
			}
			else
				cout << endl << endl << endl << endl << endl << setw(100) << "Return back" << endl;

			oop = _getch();
			if (oop == 115)
				if (controller == 3)
					controller = 0;
				else
					controller++;
			else if (oop == 119)
				if (controller == 0)
					controller = 3;
				else
					controller--;
			else if (oop == 13) {
				if (controller == 0) {
					system("cls");
					fstream names("BoxNames.txt", ios::app);
					cout << "Enter box name: ";
					cin >> fileName;
					QuestionBox.set_Settings(fileName);
					QuestionBox.write_To_file(names);
					fileName.append(".txt");
					fstream box(fileName, ios::out);
				}
				else if (controller == 1) {
					system("cls");
					showBoxes();
					cout << "Enter name of box(cancel - return back): ";
					cin >> fileName;
					cout << "How much answer will u use? ";
					cin >> size;
					fileName.append(".txt");
					if (fileName == "cancel" || fileName == "Cancel" || fileName == "CANCEL") {
						return;
					}
					fstream box(fileName, ios::app, ios::_Nocreate);
					Question question;
					cin.ignore();
					cout << "Question: "; // muellimden sorus
					getline(cin, question.text);
					question.text.insert(question.text.begin(), '-');
					cout << "Answer(A): ";
					getline(cin, question.answer1);
					cout << "Answer(B): ";
					getline(cin, question.answer2);
					if (size == 3) {
						cout << "Answer(C): ";
						getline(cin, question.answer3);
					}
					else if (size == 4) {
						cout << "Answer(C): ";
						getline(cin, question.answer3);
						cout << "Answer(D): ";
						getline(cin, question.answer4);
					}
					cout << "Which one is the Correct ";
					question.correct = _getch();
					while (question.correct != 'a' && question.correct != 'b' && question.correct != 'c' && question.correct != 'd') {
						question.correct = _getch();
					}

					question.writeToFile(box);
				}
				else if (controller == 2) {
					showBoxes();
					Sleep(5000);
				}
				else {
					UserWiew = 0;
					break;
				}
			}
		}
	}

	void checkQuestion(fstream& s, int& count) {
		s.seekg(ios::beg);
		string data;
		if (count != 2 && count != 1) {
			for (size_t i = 0; i < count - 2; i++)
			{
				while (true)
				{
					getline(s, data);
					if (data == "a" || data == "b" || data == "c" || data == "d")
						break;
				}
			}
			count -= 2;
		}
	}

	void finishTheGame(short& UserWiew, size_t& correct, size_t& wrong, size_t& passed, size_t score, int oop, fstream& topOf, string names) {
		string name;
		string scores;


		topOf << name << ": " << scores << "\n";

		cout << " Congratulations " << endl;
		cout << "Your score" << endl;
		cout << "     correct: " << correct << endl;
		cout << "     wrong: " << wrong << endl;
		cout << "     passed: " << passed << endl;
		exit(0);
	}

	void bringQuestion(short& UserWiew, fstream& box, int oop, size_t& correct, size_t& wrong, size_t& passed, fstream& topOf, int& currentQuestion, string data) {
		system("cls");
		vector<string> answers;
		getline(box, data);

		while (data == "empty" || data == "")
		{
			finishTheGame(UserWiew, correct, wrong, passed, oop, correct * 10, topOf, "Emin");
		}
		cout << setw(12) << "| " << data << " | " << endl;
		for (size_t i = 0; i < 4; i++)
		{
			getline(box, data);
			if (data != "empty")
				answers.push_back(data);
		}


		char k = 65;
		int buttonCount = 0;
		if (answers[0] != "") {

			for (size_t i = 0; i < answers.size(); i++, k++)
			{
				if (answers[i] != "empty") {
					cout << k << ": " << answers[i] << endl;
					buttonCount++;
				}
			}
		}


		string names = "Emin";
		cout << "Next[N]" << endl;
		cout << "Submit[S]" << endl;
		cout << "Previous[P]" << endl;
		string answer;


		getline(box, data);
		while (true)
		{
			answer = _getch();
			if (buttonCount == 2) {
				if (answer == "a" || answer == "A" || answer == "b" || answer == "B" || answer == "S" || answer == "s" || answer == "N" || answer == "n" || answer == "p" || answer == "P") {
					break;
				}
			}
			if (buttonCount == 3) {
				if (answer == "c" || answer == "C" || answer == "a" || answer == "A" || answer == "b" || answer == "B" || answer == "S" || answer == "s" || answer == "N" || answer == "n" || answer == "p" || answer == "P") {
					break;
				}
			}
			if (buttonCount == 4) {
				if (answer == "d" || answer == "D" || answer == "c" || answer == "C" || answer == "a" || answer == "A" || answer == "b" || answer == "B" || answer == "S" || answer == "s" || answer == "N" || answer == "n" || answer == "p" || answer == "P") {
					break;
				}
			}
		}
		if (answer == "N" || answer == "n")
			passed++;
		else if (answer == "S" || answer == "s")
			finishTheGame(UserWiew, correct, wrong, passed, oop, correct * 10, topOf, names);
		else if (answer == "P" || answer == "p")
			checkQuestion(box, currentQuestion);
		else if (answer == data)
			correct++;
		else if (answer != data)
			wrong++;
		else 
			cout << "\a" << endl;
	}
	
	string printQuestionBoxes(fstream& boxes) {
		string data;
		string choose;
		while (!boxes.eof())
		{
			getline(boxes, data);
			cout << "Size: " << data << endl;
			getline(boxes, data);
			cout << "Name: " << data << endl;
		}
		cin >> choose;
		choose.append(".txt");
		return choose;
	}


	void PlayerWiew(short& UserWiew, int oop, size_t& correct, size_t& wrong, size_t& passed, fstream& topOf) {
		short controller = 0;
		string data;
		string names = "Emin";
		while (true)
		{
			system("cls");
			if (controller == 0)
				cout << ">> Play with random questions" << endl;
			else
				cout << "Play with random questions" << endl;
			if (controller == 1)
				cout << ">> Play with own questions" << endl;
			else
				cout << "Play with own questions[2]" << endl;
			if (controller == 2)
				cout << ">> Top 10[3]" << endl;
			else
				cout << "Top 10[3]" << endl;
			if (controller == 3) {
				SetConsoleTextAttribute(hConsole, red);
				cout << endl << endl << endl << endl << endl << setw(100) << ">> EXIT  ";
				SetConsoleTextAttribute(hConsole, white);
			}
			else
				cout << endl << endl << endl << endl << endl << setw(100) << "EXIT" << endl;
			oop = _getch();

			if (oop == 115) {
				if (controller == 3)
					controller = 0;
				else
					controller++;
			}
			else if (oop == 119) {
				if (controller == 0)
					controller = 3;
				else
					controller--;
			}
			else if (oop == 13) {
				if (controller == 0) {
					NULL;
				}
				else if (controller == 1) {
					system("cls");
					int currentQuestion = 0;
					cout << "Enter name of the box: ";
					cin >> data;
					data.append(".txt");
					fstream f(data, ios::in);
					while (!f.eof())
					{
						currentQuestion++;
						bringQuestion(UserWiew, f, oop, correct, wrong, passed, topOf, currentQuestion, data);
					}
					fstream fout("TopOf.txt", ios::out);
					finishTheGame(UserWiew, correct, wrong, passed, correct * 10, oop, topOf, names);
				}
				else if (controller == 2) {
					system("cls");
					fstream topOf("TopOf.txt", ios::in);
					int i = 0;
					while (!topOf.eof())
					{
						i++;
						getline(topOf, data);
						cout << i << ": " << data;
						getline(topOf, data);
						cout << right << setw(25) << data << endl;
					}
				}
				else
					UserWiew = 0;
			}
		}
	}
};
