#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() 
{
	string name;

	cout << "Please enter vote sequence" << endl;

	getline(cin, name);
	cout << "Hello " << name << ".\n";

	transform(name.begin(), name.end(), name.begin(), [](unsigned char c){ return tolower(c); });

	size_t n = count(name.begin(), name.end(), "a");

	cout << n << endl;

}

