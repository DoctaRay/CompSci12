#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Department {
    string name;
    vector<int> admin;
    vector<int> teacher;
    vector<int> student;
};

int main() {
    ifstream infile;
    infile.open("data.txt");
    string delimit = ",";
    string line;
    vector<Department> total;
    int count;
    string tempStr;
    int num;


    while(getline(infile, line)) {

            Department temp;

            ///get name
            count = line.find(delimit);
            string token = line.substr(0, count);
            temp.name = token;
            line.erase(0, count + 1);

            //get admin
            count = line.find(delimit);
            token = line.substr(0, count);
            stringstream s1(token);
            s1 >> num;
            temp.admin.push_back(num);
            line.erase(0, count + 1);
            count = line.find(delimit);
            token = line.substr(0, count);
            stringstream s2(token);
            s2 >> num;
            temp.admin.push_back(num);
            line.erase(0, count + 1);


            //get teacher
            count = line.find(delimit);
            token = line.substr(0, count);
            stringstream s3(token);
            s3 >> num;
            temp.teacher.push_back(num);
            line.erase(0, count + 1);

            count = line.find(delimit);
            token = line.substr(0, count);
            stringstream s4(token);
            s4 >> num;
            temp.teacher.push_back(num);
            line.erase(0, count + 1);

            //get student

            count = line.find(delimit);
            token = line.substr(0, count);
            stringstream s5(token);
            s5 >> num;
            temp.student.push_back(num);
            line.erase(0, count + 1);

            count = line.find(delimit);
            token = line.substr(0, count);
            stringstream s6(token);
            s6 >> num;
            temp.student.push_back(num);
            line.erase(0, count + 1);

            total.push_back(temp);

    }

    int choice;

    while(choice != 5) {
        cout << "Department menu " << endl;
        cout << "Dep\tAdmin(I, C)\tTeacher(I, C)\tStudent(I,C)" << endl;
        for (auto x: total) {
            cout << x.name << "\t" << x.admin[0]  << " " << x.admin[1]  << "\t" << x.teacher[0]  << " " << x.teacher[1] << "\t" << x.student[0] << " " << x.student[1] << endl;
        }
        cout << "1. Add Record\n2. Display total number of iPads\n3. Total for each column\n4. Display Department Totals\n5. Quit" << endl;
        cout << "Choice: " << endl;
        cin >> choice;
        //cout << "end" << endl;

        if (choice == 1) {
            Department temp;
            string name;
            int a;


            cout << "Enter department name: ";
            cin >> temp.name;
            cout << endl;

            cout << "# of admin iPads: ";
            cin >> a;
            temp.admin.push_back(a);
            cout << endl;

            cout << "# of admin computers: ";
            cin >> a;
            temp.admin.push_back(a);
            cout << endl;

            cout << "# of teacher iPads: ";
            cin >> a;
            temp.teacher.push_back(a);
            cout << endl;

            cout << "# of teacher computers: ";
            cin >> a;
            temp.teacher.push_back(a);
            cout << endl;

            cout << "# of student iPads: ";
            cin >> a;
            temp.student.push_back(a);
            cout << endl;

            cout << "# of student computers: ";
            cin >> a;
            temp.student.push_back(a);
            cout << endl;


            total.push_back(temp);
        }

        else if (choice == 2) {
            vector<int> col;
            vector<int> temp;
            int x, y = 0;


            for (int i = 0; i < total.size(); i++) {
                //adding admin
                x += total[i].admin[0] + total[i].teacher[0] + total[i].student[0];
                y += total[i].admin[1] + total[i].teacher[1] + total[i].student[1];

            }


            cout << "iPads - " << x << endl;
            cout << "Computers - " << y << endl;
        }

        else if (choice == 3) {
            vector<vector<int> > rows;
            vector<int> admin = {0 ,0};
            vector<int> teacher= {0 ,0};
            vector<int> student = {0 ,0};
            vector<int> temp;
            rows.push_back(temp);
            rows.push_back(temp);
            rows.push_back(temp);


            for (int i = 0; i < total.size(); i++) {
                //adding admin
                vector<int> temp = {0, 0};

                admin[0] += total[i].admin[0];
                admin[1] += total[i].admin[1];

                //adding teacher
                teacher[0] += total[i].teacher[0];
                teacher[1] += total[i].teacher[1];

                //adding student
                student[0] += total[i].student[0];
                student[1] += total[i].student[1];

            }

                cout << "Admin" << "- " << admin[0] << " ipads," << admin[1] << " computers" << "\n Teacher" <<  teacher[0] <<  " ipads" << teacher[1] << " computers"<< "\nStudent" <<student[0] << " ipads" << student[1] << " computers" << endl;

        }

        else if (choice == 4) {
            for (auto x: total) {
                cout << x.name << "- " << (x.admin[0] + x.teacher[0] + x.student[0]) << " iPads, " << (x.admin[1] + x.teacher[1] + x.student[1]) << " computers" << endl;
            }
        }

        else {
            cout << "Choose a number please" << endl;
        }
    }
}