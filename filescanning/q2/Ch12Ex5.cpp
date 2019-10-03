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
	ifstream first2;
	ifstream second;
	ifstream second2;
	ofstream third;
	int n1, n2, test1, test2;
	vector<int> numbers;

	first.open("file1.txt");
	second.open("file2.txt");
	third.open("file3.txt");

	if (!first || !second) {
		cout << "Error";
		exit(1);
	}
	while (first >> test1) {
		cout << test1 << " ";
	}
	cout << endl;

	while (second >> test2){
		cout << test2 << " ";
	}
	cout << endl;
	first.close();
	second.close();
	//first >> n1;
	//cout << n1 << endl;
	
	first2.open("file1.txt");
	second2.open("file2.txt");
	
	first2 >> n1;
	second2 >> n2;

	while(!second2.eof() && !first2.eof()) {
		
			if (n1 > n2) {
				numbers.push_back(n2);
				cout << n2 << endl;
				second2 >> n2;
				continue;	
			} else if (n1 <= n2) {
				numbers.push_back(n1);
				cout << n1 << endl;
				first2 >> n1;
				continue;
			} 
			
			if (first2.eof()){
				n1 = 2147483647;
			}
			if(second2.eof()) {
				n2 = 2147483647;
			}

			if (n1 == 2147483647 && n2 == 2147483647) {
				break;
			}
			/*else {
				first2 >> n1;
				second2 >> n2;
				continue;
			}*/
		//numbers.push_back(num);
		//cout << num << " ";	
	}
	
	/*cout << endl << "File 2: ";

	while (second >> num) {
		numbers.push_back(num);
		cout << num << " ";
	}
	cout << endl;

	numbers = insertSort(numbers);*/

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
