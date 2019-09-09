#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<vector<int> > rows;
	vector<int> temp = { 0, 0, 0, 0, 0, 0, 0, 0 };
	for (int i = 0; i <=5; ++i) {
		rows.push_back(temp);
	}
/*
	for (auto x: rows) {
		for (int a = 0; a <=8; ++a) {
			x.push_back(1);
		}
	}
*/
	for (auto x: rows) {
		for (int a: x) {
			cout << x.at(a) << "-";
		}
		cout << "-" <<endl;
	}

	
}
