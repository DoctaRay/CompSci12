#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

vector<int> insertSort(vector<int> a) {
	unsigned int i, j;
        int max;
	vector<int> sortedArray = {a.size()};
	sortedArray = a;

	for (int i = 0; i < a.size(); i++){
		for (j=i; j < a.size(); j++){
			if (sortedArray[i] < sortedArray[j]){
				int tmp;
				tmp = sortedArray[i];
				sortedArray[i]=sortedArray[j];
				sortedArray[j]=tmp;
			}
		}
	}
	
	reverse(begin(sortedArray), end(sortedArray));
	return sortedArray;
}

			

int main() {
	ifstream first;
	ifstream second;
	ofstream third;
	int num;
	vector<int> numbers;

	first.open("file1.txt");
	second.open("file2.txt");
	third.open("file3.txt");

	if (!first || !second) {
		cout << "Error";
		exit(1);
	}
	
	cout << "File 1: ";
	while(first >> num) {
		numbers.push_back(num);
		cout << num << " ";	
	}
	cout << endl << "File 2: ";

	while (second >> num) {
		numbers.push_back(num);
		cout << num << " ";
	}
	cout << endl;

	numbers = insertSort(numbers);

	cout << "Final numbers are: ";
	for (int x: numbers){
		cout << x << " ";
	}
	cout << endl;

	if(third.is_open()) {
		for (int x: numbers){
			third << x << " ";
		}
		third.close();
	}

	else cout << "Unable to open file" << endl;
}
