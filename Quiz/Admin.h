#pragma once

enum AdminLevel { JuniorAdmin = 1, SeniorAdmin = 2 };

class Player : public User {



public:

	Player(string name,string password,size_t score) :User(name,password,score){}

	void WriteToFile(fstream& Players) {
		Players << User::getName() << "\n";
		Players << User::getPassword() << "\n";
		Players << User::getScore() << "\n";
	}

};

class Admin : public User {
	
	AdminLevel level; 

public:

	Admin(AdminLevel level, string name, string password, size_t score)
		:User(name, password, score)
	{
		this->level = level;
	}

	void WriteToFile(fstream& admins) {
		admins << User::getName() << "\n";
		admins << User::getPassword() << "\n";
		admins << User::getScore() << "\n";
	}

};