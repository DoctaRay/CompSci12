#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
	string name;
	int a=0,b=0;

	cout << "Please enter vote sequence" << endl;

	getline(cin, name);

	// boost::algorithm::to_lower(name);

	transform(name.begin(), name.end(), name.begin(), ::tolower);

	// size_t n = count(name.begin(), name.end(), "a");

	for (int i = 0; i < name.size(); i++) {
		if (name[i] == 'a') a++;
		else if (name[i] == 'b') b++;
	}

	if (a > b) {
		cout << "Singer A wins \n";
	} else if (b > a) {
		cout << "Singer B wins \n";
	} else if (a == b) {
		cout << "It was a tie \n";
	} else {
		cout << "Error occurred \n";
	}


}
