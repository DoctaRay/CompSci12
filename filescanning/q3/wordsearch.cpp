//#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main() {
	ifstream file;
	ifstream words;
	file.open("file.txt");
	words.open("words.txt");
	int size;
	string str;

	file >> size;

	string lines [size];

	//to do: read the line. 
	while(file >> str) {
			
	}


		
}
