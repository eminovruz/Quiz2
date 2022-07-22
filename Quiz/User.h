#pragma once

class User {
private:

	string name;
	string password;
	size_t score;

public:

	User(string name, string password, size_t score)
	{
		this->name = name;
		this->password = password;
		this->score = score;

	}

	string getName() const { return name; }
	string getPassword() const { return password; }
	size_t getScore() const { return score; }


};