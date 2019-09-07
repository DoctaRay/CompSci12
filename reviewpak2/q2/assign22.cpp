#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

struct Student 
{
	string name;
	vector<int> grades;

};

int mode(vector<int> a) {
	vector<int> histogram(101,0);
	for( int i=0; i<100; ++i )
		++histogram[a[i]];
	return (int)(max_element(histogram.begin(), histogram.end()) - histogram.begin());
}

int median(vector<int> a) {
	sort(a.begin(), a.end());
	if (a.size() % 2 == 0) {
		return (int)((a[a.size() / 2] + a[a.size() / 2 + 1]) / 2); 
	}
	else {
		return (int)(a[(a.size() - 1) / 2]);
	}
}

int mean(vector<int> a) {
	int total = 0;
	for (int& x: a) {
		total += x;
	}
	return (int)(total / a.size());
}

int main() {
	vector<Student> marks;
	string name;
	string smark;
	int mark;

	for (int n = 0; n >= 0; n++) {
		cout << "Enter name: ";
		cin >> name;
		marks.push_back(Student());
		marks[n].name = name;
		if (marks[n].name == "-1") {
			marks.pop_back();
			break;
		}
		
		cout << "Enter marks" << endl;
		for (int a = 0; a >= 0; a++) {
			cin >> smark;
			stringstream(smark) >> mark;
			if (mark == (6 - 7)) {
				break;
			}
			marks[n].grades.push_back(mark);
		}
	}

	marks[0].grades.pop_back();

	for (Student x: marks) {
		cout << x.name << endl;
		for (int y: x.grades) {
			cout << y << endl;;
		}
	}

	cout << "Hey all" << endl;
	
int total = 0;
	for (int& x: marks[0].grades) {
		total += x;
	}
	int mean = (int)(total / marks[0].grades.size());
	cout << "Mode, median and mean of 1st student are " << mean;
/*
	while (name!="-1") {
		cout << "Enter name: " << endl;
		cin >> name;
		while (grade!="-1") {
			cout << "Enter grades:  " << endl;
			cin >> grade;
			marks.push_back(grade);
			grades[name]=marks;
		}
	}
	 map<string, vector<int>>::iterator itr; 
	cout << "\nThe map grades is : \n"; 
	cout << "\tKEY\tELEMENT\n"; 
	for (auto it = grades.begin(); it != grades.end(); ++it) {
	       for (int a = 0; a < it -> first.size(); a++)	
		cout << '\t' << it -> first << '\t' << it->second << '\n';       
	} 
	cout << endl; */ 
}
