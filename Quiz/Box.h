#pragma once
class Box {
private:
	string name;
public:

	Box() = default;

	Box(string name)
	{	
		this->name = name;
	}

	void write_To_file(fstream& f) {
		f << name << "\n";
	}

	void set_Settings(string name) {
		this->name = name;
	}


};

