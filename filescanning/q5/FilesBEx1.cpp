#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

struct Employee {
	int number;
	string name;
	string married;
	int age;
	int salary;
};

int main() {
	vector<Employee> list;
	string waste;
	ifstream file;
    istringstream ss;
	string line;
    int choice;
    int value;
    string delimiter = ",";
    size_t count = 0;

	file.open("data.txt");

	getline(file, waste);

	while(getline(file, line)){
		Employee test;

        count = line.find(delimiter);
        string token = line.substr(0, count);

        ss >> value;
        test.number = value;

        line.erase(0, count);

        token = line.substr(0, count);

        test.married = token;

        line.erase(0, count);

        token = line.substr(0, count);

        ss >> value;
        test.age = value;

        line.erase(0, count);

        token = line.substr(0, count);

        ss >> value;
        test.salary = value;

        line.erase(0, count);

        token = line.substr(0, count);

        test.name = token;

        line.erase(0, count);

        token = line.substr(0, count);

        test.name = token;

        line.erase(0, count);

        list.push_back(test);
	}

	cout << "***Menu*** \n 1. Open file \n 2. Save file \n 3. Add a record \n 4. Delete a record \n 5. Modify a record \n 6. Display all \n 7. Quit" << endl;

    cin >> choice;

    if (choice == 1) {
        cout << "***Menu*** \n 1. Open file \n 2. Save file \n 3. Add a record \n 4. Delete a record \n 5. Modify a record \n 6. Display all \n 7. Quit" << endl;
        cin >> choice;
        if (choice == 6) {
            for (auto x: list) {
                cout << x.number << " " << x.name << " " << x.married << " " << x.age << " " << x.salary << endl;
            }
        }
    }

    return 0;
}
