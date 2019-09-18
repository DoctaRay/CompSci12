#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <sstream>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h>
#include <iomanip>

using namespace std;

struct Student 
{
	string name;
	vector<int> grades;

};

vector<int> insertSort(vector<int> a) {
	cout << "var does not init" << endl;
	int j;
	cout << "for loop does not init" << endl;
	for (int i = 0; i < a.size(); i++) {
		cout << j << "j does not = i" << endl;
		j = i;
		cout << "while loop does not init" << endl;
		while (j > 0 && a[j] < a[j + 1]) {
			cout << a[j] << " iter swap does not init" << endl;
			iter_swap(a.begin() + j, a.begin() + j + 1);
			cout << j << " J does not - " << endl;
			j--;	
		}
	}
	cout << "does not return" << endl;
	return a;
}


/* vector<int> histogram;
for (int i = 0; i < 101; ++i)
		histogram.push_back(0);
int m = 0;
*/
int mode(vector<int> a) {
	vector<int> histogram;
	vector<int> modes;
	vector<int> fail = { 999 }; 
	int highest = 0;
	int count = 0;
	bool check = false;
	for (int i = 0; i < 101; ++i)
		histogram.push_back(0);
	int m = 0;


	for( int i=0; i<a.size(); ++i )
		++histogram[a[i]];
	
	for (int i =0; i < a.size(); ++i) {
		if (histogram[a[i]] >= m) {
			highest = histogram[a[i]];
			m = a[i];
			// modes.push_back(m);			
			
		}
	}
	cout << highest << endl;

	vector<int> tempo = histogram;
	tempo.erase(remove(tempo.begin(), tempo.end(), 0), tempo.end());


	/*for (int t = 0; t < tempo.size() - 1; t++) {
		cout << tempo[t] << endl;
	}*/
	for (int x: tempo) {
		 if (x == highest) {
			cout << x << endl;
			check = true;	
		}
		else {
			cout << x << endl;
			check == false;
			break;
		}
	}

	if (check) {
		return 999;
	}

	for (int i = 0; i < a.size(); ++i) {
		if (histogram[a[i]] == 1) {
			count++;
		}
		else if (histogram[a[i]] != 1) {
			cout << "gets value " << histogram[a[i]] << " " << a[i] <<  endl;
			if (histogram[a[i]] == highest && !(find(begin(modes), end(modes), a[i])!=end(modes))) {
				cout << "test runs" << endl;
				modes.push_back(a[i]);
			} 
			
		} 
	}

	/* if (count == a.size()) {
		return fail;
		cout << " no mode " << endl;
	} */	
	cout << "Modes: ";
	for (int x: modes) {
		cout << x << " ";
	}
	cout << endl;

	return 1;	
}

int median(vector<int> a) {
	cout << "insert sort " << endl;
	a = insertSort(a);
	for (int i = 0; i < a.size(); i++) {
			cout << a[i] << "-";
		}
		cout << endl;
	//a.erase(a.begin());
	cout << "modulo does not work " << endl;

	if (a.size() % 2 == 0) {
		cout << "median one not works" << endl;
		// a.erase(a.begin());

		for (int i = 0; i < a.size(); i++) {
			cout << a[i] << "-";
		}
		cout << endl;
	
		return (int)((a[(a.size() / 2) - 1] + a[a.size() / 2]) / 2); 
	}
	else {
		cout << "median two not works" << endl;
		return (int)(a[(a.size() - 1) / 2]);
	}
}

float mean(vector<int> a) {
	float total = 0;
	for (int x: a) {
		total += x;
	}
	return(total / a.size());
}
int main() {
	vector<Student> marks;
	string name;
	string smark;
	int mark;
	bool valid = false;

	for (int n = 0; n >= 0; n++) {
			cout << "Enter name: ";
			cin >> name;
			 	
			marks.push_back(Student());
			marks[n].name = name;
			if (marks[n].name == "-1") {
				marks.pop_back();
				break;
			}
	
				// write over here. finish valid check for grades 0-100
		
		cout << "Enter marks" << endl;
		for (int a = 0; a >= 0; a++) {
			cin >> smark;
			stringstream(smark) >> mark;
			if (mark == (6 - 7)) {
				break;
			}

			if (mark < 0 ||  mark > 100) {
				cout << "Enter mark again: " << endl;
			      	continue;	
			}
			marks[n].grades.push_back(mark);
		}
	}

/*
	for (Student x: marks) {
		cout << x.name << endl;
		for (int y: x.grades) {
			cout << y << endl;;
		}
	}
*/
	cout << "Here are the respective stats. 999 for median means that there is not median." << endl;
	
int total = 0;
	/* for (int x: marks[0].grades) {
		total += x;
	}
	int mean = (int)(total / marks[0].grades.size()); 
	*/
	for (int i = 0; i < marks.size(); i++) {
	cout << "Mode, median and mean of student " << i << "(" << marks[i].name <<  ") are " << mode(marks[i].grades) << ", "; 
		cout << median(marks[i].grades) << ", "; 
		cout << setprecision(3) << mean(marks[i].grades) << "." << endl;  
	
	/* cout << mode(marks[0].grades) << endl;
       	cout << median(marks[0].grades) << endl; 
	cout << mean(marks[0].grades) << endl;
	cout << "The size of array is " << marks[0].grades.size() << endl;
	*/
	}
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
