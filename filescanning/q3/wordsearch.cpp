#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct Point {
	int x;
	int y;
};

string reverseStr(string str) {
	int n = str.length();
	for (int i = 0; i < n / 2; i++) {
		swap(str[i], str[n - i - 1]);
	}
	return str;
}

int main() {
	ifstream file;
	ifstream filewords;
	file.open("file.txt");
	filewords.open("words.txt");
	int size;
	string str;
	string check= "";
	vector<string> crosswordx;
	vector<string> crosswordy;
	string ye = "";
	vector<string> words;
	vector<string> foundwords;
	vector<string> diagonals;
	vector<string> diagonals2;
	vector<string> found;

	vector<vector<Point> > points;
	vector<vector<Point> > points2;



	//file >> size;

	//string lines [size];

	//to do: read the line. 
	file >> size;
	while(file >> str) {
		crosswordx.push_back(str);
	}

	while (filewords >> str){
		words.push_back(str);	
	}

	for (string x: crosswordx) {
		cout << x << endl;
	}
	cout << endl;

	for (string x: words) {
		cout << x << " ";
	}
	cout << endl;

	int x = 0;
	int y = 0;
	int tmpSize = 0;

	//putting in values for FIRST half of crossword, top right to bottom left
	for (int i = 0; i <= crosswordx.size() - 1; i++) {
		x = 0;
		y = i;
		tmpSize = y;
		Point tmpPoint;
		vector<Point> tmpVec;
		string tmpStr = "";
		for (int j = 0; j <= tmpSize; j++){
			tmpPoint.x = x;
			tmpPoint.y = y;
			cout << "(" << x << " " << y << ")" << endl;
			tmpStr += crosswordx[tmpPoint.x][tmpPoint.y];
			tmpVec.push_back(tmpPoint);
			x++;
			y--;	
		}
		cout << "-----------------" << endl;
		points.push_back(tmpVec);
		diagonals.push_back(tmpStr);
	}


	//putting in values for next half of crossword, top right to bottom left
	cout << crosswordx.size() << endl;
	for (int i = crosswordx.size() - 1; i > 0; i--) {
		x = crosswordx.size() - 1;
		y = i;
		tmpSize = x;
		Point tmpPoint;
		vector<Point> tmpVec;
		string tmpStr = "";
		for (int j = y; j <= tmpSize; j++){
			tmpPoint.x = x;
			tmpPoint.y = y;
			cout << "(" << x << " " << y << ")" << endl;
			tmpStr += crosswordx[tmpPoint.x][tmpPoint.y];
			tmpVec.push_back(tmpPoint);
			x--;
			y++;	
		}
		cout << "-----------------" << endl;
		points.push_back(tmpVec);
		diagonals.push_back(tmpStr);
	}

	int counter = 0;
	while(true) {
		for (int i = 0; i < crosswordx.size(); i++) {
			ye = ye + crosswordx[i][counter];	
		}
		crosswordy.push_back(ye);
		ye="";
		counter++;
		if (crosswordy.size() == size){
			break;
		}

	}

	for (auto x: crosswordy) {
		cout << x << endl;
	}

	cout << endl;

	
	//other side of crossword.
	for (int i = 0; i <= crosswordx.size() - 1; i++) {
		x = i;
		y = crosswordx.size() - 1;
		tmpSize = x;
		Point tmpPoint;
		vector<Point> tmpVec;
		string tmpStr = "";
		for (int j = 0; j <= tmpSize; j++){
			tmpPoint.x = x;
			tmpPoint.y = y;
			cout << "(" << x << " " << y << ")" << endl;
			tmpStr += crosswordx[tmpPoint.x][tmpPoint.y];
			tmpVec.push_back(tmpPoint);
			x--;
			y--;	
		}
		cout << "-----------------" << endl;
		points2.push_back(tmpVec);
		diagonals2.push_back(tmpStr);
	}


	for (int i = 0; i < crosswordx.size() - 1; i++) {
		x = crosswordx.size() - 1;
		y = i;
		tmpSize = y;
		Point tmpPoint;
		vector<Point> tmpVec;
		string tmpStr = "";
		for (int j = 0; j <= tmpSize; j++){
			tmpPoint.x = x;
			tmpPoint.y = y;
			cout << "(" << x << " " << y << ")" << endl;
			tmpStr += crosswordx[tmpPoint.x][tmpPoint.y];
			tmpVec.push_back(tmpPoint);
			x--;
			y--;	
		}
		cout << "-----------------" << endl;
		points2.push_back(tmpVec);
		diagonals2.push_back(tmpStr);
	}


	for (auto x: diagonals){
		cout << x << endl;
	}
	cout << endl;

	for (auto x: diagonals) {
		cout << reverseStr(x) << endl;
	}
	cout << endl;
	for (auto x: diagonals2) {
		cout << x << endl;
	}

	cout << endl;	
	
	for (int i = 0; i < crosswordx.size(); i++) {
		for (auto x: words) {
                       
			if (crosswordx[i].find(x) != string::npos || crosswordy[i].find(x) != string::npos || reverseStr(crosswordx[i]).find(x) != string::npos || reverseStr(crosswordy[i]).find(x) != string::npos ) {
				cout << x << " was found." << endl;
				found.push_back(x);
			}
			else if (i == words.size() - 1) {
				// cout << x << " was not found." << endl;
			}
		}
		
	}

	for (int i = 0; i < diagonals.size(); i++) {
		for (auto x: words) {
			if (diagonals[i].find(x) != string::npos || reverseStr(diagonals[i]).find(x) != string::npos || diagonals2[i].find(x) != string::npos || reverseStr(diagonals2[i]).find(x) != string::npos) {
				cout << x << " was found." << endl;
				found.push_back(x);
			}	
		}
	}

	for (int i = 0; i < words.size(); i++) {
		bool verify = false;
		for (auto x: found) {
			if (words[i].compare(x) == 0){
				verify = true;
			}	
		}
		if (!verify) {
			cout << words[i] << " was not found." << endl;
		}
	}
		

	//use regex
/*	for (int i = 0; i < crossword.size(); i++) {
		for (int j = 0; j < crossword[i].size(); j++){
			while(true){

				check = check + crossword[i][j];
				for (string x: words) {
					if (check.compare(x) == 0) {
						foundwords.push_back(x);
						found = true;
					}
				}
				if (found) break;
				
			if (found) break;
			}
		if (found) break;	
		}	
	}
*/



		
}
