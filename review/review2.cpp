#include <iostream>
#include <string>

using namespace std;

int main() 
{
	string name;

	cout << "Please enter vote sequence" << endl;

	getline(cin, name);
	cout << "Hello " << name << ".\n";

	return 0;
}

