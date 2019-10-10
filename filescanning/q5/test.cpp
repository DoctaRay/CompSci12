#include<string>
#include<vector>
#include<fstream>
#include<iostream>

using namespace std;

struct Employee {
	int number;
	string name;
	bool married;
	int age;
	int salary;
};

int main() {
	vector<Employee> list;
	string waste;
	ofstream file;
	string line;
	file.open("data.txt");

	file >> waste;

	while(getline(file, line)){
		Employee test;
		stringstream linestream(line);
		string value;

		while (getline(linestream, value, ",") {
								
		}
		
	}	
	
	cout << "***Menu*** \n 1. Open file \n 2. Save file \n 3. Add a record \n 4. Delete a record \n 5. Modify a record \n 6. Display all \n 7. Quit" << endl;
	
}
