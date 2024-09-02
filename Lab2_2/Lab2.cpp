#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    vector<string> electiveList;
public:
    // Add constructors, setters, getters, and any functions you may need
    Student() {
        name = "";
        electiveList = vector<string>();
    }

    // setter
	void setName(string name) {
		this->name = name;
	}

	void setElectiveList(vector<string> electiveList) {
		this->electiveList = electiveList;
	}

    // getter
	string getName() {
		return name;
	}
	vector<string> getElectiveList() {
		return electiveList;
	}

};

int main() {

	cout << "===================    Student List    ======================" << endl;
	cout << "-------------------------------------------------------------" << endl;
	vector<string> uniqueElectives();
	ifstream file1("student.txt");

	// Read the file line by line, set name to be first substring in line, and the rest in electiveList
	string name, class_1, class_2, class_3;
	// getline(file1, name);
	
	Student student;
	student.setName(name);
	
	//getline(file1, class_1, ',');
	//getline(file1, class_2, ',');
	//getline(file1, class_3, ',');
	
	//cout << student.getName() << endl;

    return EXIT_SUCCESS;
}