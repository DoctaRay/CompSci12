#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

struct Employee {
	string number;
	string name;
	string married;
	string age;
	string salary;
};

int main() {
	vector<Employee> list;
	string waste;
	ifstream file;
    istringstream ss;
	string line;
    vector<vector<string> > inputs;
    int choice;
    int value;
    string delimiter = ",";
    int count = 0;

	file.open("data.txt");

	getline(file, waste);

	while(getline(file, line)){
        vector<string> temp;
        for (int i = 0; i < 5; i++) {
            count = line.find(delimiter);
            string token = line.substr(0, count);
            temp.push_back(token);
            cout << count << endl;
            line.erase(0, count + 1);
        }
        inputs.push_back(temp);
	}

    for (int i = 0; i < inputs.size(); i++) {
        Employee test;
        test.number = inputs[i][0];
        test.name = inputs[i][1];
        test.married = inputs[i][2];
        test.age = inputs[i][3];
        test.salary = inputs[i][4];

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
