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

void fchoice(int choice, vector<Employee> list, vector<Employee> temp = {}) {
    if (choice == 0) {
        cout << "***Menu*** \n 1. Open file \n 2. Save file \n 3. Add a record \n 4. Delete a record \n 5. Modify a record \n 6. Display all \n 7. Quit" << endl;
        cin >> choice;
        fchoice(choice, list, temp);
    }

    else if (choice == 1) {
        cout << "File opened \n***Menu*** \n 1. Open file \n 2. Save file \n 3. Add a record \n 4. Delete a record \n 5. Modify a record \n 6. Display all \n 7. Quit" << endl;
        cin >> choice;
        fchoice(choice, list, temp);
    }
    else if (choice == 2) {
        ofstream outfile;
        ifstream infile;
        string line;
        string waste;
        string delimiter = ",";
        int count;
        vector<vector<string> > inputs;
        outfile.open("data.txt", std::ofstream::out | std::ofstream::trunc);

        list = temp;

        outfile << "Employee#,Name,Marital Status,Age,Salary\n";
        outfile << "0128,B.Smith,M,19,11000\n";
        for (auto x: list) {
            outfile << x.number << "," << x.name << "," << x.married << "," << x.age << "," << x.salary << endl;
        }

        temp = {};
        list = {};
        outfile.close();

        infile.open("data.txt");

        getline(infile, waste);
        while(getline(infile, line)){
        vector<string> tempStr;
        for (int i = 0; i < 5; i++) {
            count = line.find(delimiter);
            string token = line.substr(0, count);
            tempStr.push_back(token);

            line.erase(0, count + 1);
        }
        inputs.push_back(tempStr);
	}
    infile.close();

    for (int i = 0; i < inputs.size(); i++) {
        Employee test;
        test.number = inputs[i][0];
        test.name = inputs[i][1];
        test.married = inputs[i][2];
        test.age = inputs[i][3];
        test.salary = inputs[i][4];

        list.push_back(test);
    }
        cout << "File saved \n***Menu*** \n 1. Open file \n 2. Save file \n 3. Add a record \n 4. Delete a record \n 5. Modify a record \n 6. Display all \n 7. Quit" << endl;
        cin >> choice;
        fchoice(choice, list, temp);
    }
    else if (choice == 3) {
        Employee tempEmp;
        cout << "Enter employee number: ";
        cin >> tempEmp.number;
        cout << endl;
        cout << "Enter employee name: ";
        cin >> tempEmp.name;
        cout << endl;
        cout << "Enter employee marital status (S or M): ";
        cin >> tempEmp.married;
        cout << endl;
        cout << "Enter employee age:";
        cin >> tempEmp.age;
        cout << endl;
        cout << "Enter employee salary: ";
        cin >> tempEmp.salary;
        cout << endl;
        temp.push_back(tempEmp);
        cout << "Employee added " << endl;
        if (temp != list) {
            cout << "(MUST SAVE)";
        }
        cout << "\n***Menu*** \n 1. Open file \n 2. Save file \n 3. Add a record \n 4. Delete a record \n 5. Modify a record \n 6. Display all \n 7. Quit" << endl;
        cin >> choice;

        fchoice(choice, list, temp);
    }
    else if (choice == 4) {
        string num;
        temp = list;
        for (auto x: list) {
            cout << x.number << " " << x.name << " " << x.married << " " << x.age << " " << x.salary << endl;
        }

        cout << "\nWhich employee would you like to remove? Enter employee number (q to exit):";
        cin >> num;
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i].number == num) {
                temp.erase(temp.begin() + i - 1);
            }
        }

        if (temp != list) {
            cout << "(MUST SAVE)";
        }
        cout << "\n***Menu*** \n 1. Open file \n 2. Save file \n 3. Add a record \n 4. Delete a record \n 5. Modify a record \n 6. Display all \n 7. Quit" << endl;
        cin >> choice;
        fchoice(choice, list, temp);
    }

    else if (choice == 5) {
        string num;
        for (auto x: list) {
            cout << x.number << " " << x.name << " " << x.married << " " << x.age << " " << x.salary << endl;
        }

        cout << "Which employee would you like to modify? Enter employee number (q to exit):";
        cin >> num;
        for (int i = 0; i < list.size(); i++) {
            if (list[i].number == num) {
                Employee tempEmp;
                temp = list;
                cout << "Enter employee number: ";
                cin >> tempEmp.number;
                cout << endl;
                cout << "Enter employee name: ";
                cin >> tempEmp.name;
                cout << endl;
                cout << "Enter employee marital status (S or M): ";
                cin >> tempEmp.married;
                cout << endl;
                cout << "Enter employee age:";
                cin >> tempEmp.age;
                cout << endl;
                cout << "Enter employee salary: ";
                cin >> tempEmp.salary;
                cout << endl;
                temp[i] = tempEmp;
                if (temp != list) {
                    cout << "(MUST SAVE)";
                }
                cout << "\n***Menu*** \n 1. Open file \n 2. Save file \n 3. Add a record \n 4. Delete a record \n 5. Modify a record \n 6. Display all \n 7. Quit" << endl;
                cin >> choice;
                fchoice(choice, list, temp);
            }
        }
    }
    else if (choice == 6) {
        for (auto x: list) {
            cout << x.number << " " << x.name << " " << x.married << " " << x.age << " " << x.salary << endl;
        }
        if (temp != list) {
            cout << "(MUST SAVE)";
        }
        cout << "\n***Menu*** \n 1. Open file \n 2. Save file \n 3. Add a record \n 4. Delete a record \n 5. Modify a record \n 6. Display all \n 7. Quit" << endl;
        cin >> choice;
        fchoice(choice, list, temp);
    }
    else {

    }
}

int main() {
	vector<Employee> list;
	string waste;
	ifstream file;
    istringstream ss;
	string line;
    vector<vector<string> > inputs;
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

    fchoice(0, list);

    return 0;
}
