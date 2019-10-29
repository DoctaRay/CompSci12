#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


int main() {
	stringstream ss;
	string s;
	vector<int> test(101, 0);
	
	for (int x: test) {
		ss << x;
		ss >> s;
		cout << s << endl;	
	}	
}
