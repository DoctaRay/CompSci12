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
	int j;
	for (int i = 0; i < a.size(); i++) {
		j = i;
		while (j >= 0 && a[j] < a[j + 1]) {
			iter_swap(a.begin() + j, a.begin() + j + 1);
			j--;	
		}
	}
	return a;
}


/* vector<int> histogram;
for (int i = 0; i < 101; ++i)
		histogram.push_back(0);
int m = 0;
*/
int mode(vector<int> a) {
	vector<int> histogram;
	for (int i = 0; i < 101; ++i)
		histogram.push_back(0);
	int m = 0;


	for( int i=0; i<a.size(); ++i )
		++histogram[a[i]];
	
	for (int i =0; i < a.size(); ++i) {
		if (histogram[a[i]] >= m) {
			m = a[i];			
			
		}
	}
	for (int i = 0; i < a.size(); ++i) {
		if (histogram[a[i]] == histogram[m] && a[i] != m)
			return 999;
	}	
	
	return (int)m;	
}

int median(vector<int> a) {
	insertSort(a);

	if (a.size() % 2 == 0) {
		return (int)((a[a.size() / 2 - 1] + a[a.size() / 2]) / 2); 
	}
	else {
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
	cout << "Mode, median and mean of student " << i << "(" << marks[i].name <<  ") are " << mode(marks[i].grades) << ", " << median(marks[i].grades) << ", " << setprecision(3) << mean(marks[i].grades) << "." << endl;  
	
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
