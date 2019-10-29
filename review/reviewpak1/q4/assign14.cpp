#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cctype>

using namespace std;

int main() 
{
	srand (time(NULL));
	
	vector<int> nums;
	string sequence = "";
	int biggo = 0;
	
	for (int a = 0; a < 10; a++) {
		nums.push_back(rand() % 30 + 1);
		cout << nums.back() << endl;
	}
	cout << "--------" << endl;

	for (auto x: nums) {
		cout << x << endl;
		sequence += to_string(x);

	}

	cout << "--------" << endl;

	for (int b = 0; b < sequence.size(); b += 2) {
		cout << sequence[b] << endl;
		biggo += int(sequence[b]) - 48;
		cout << biggo << "---" << endl;
	}

	cout << "The new number is " << biggo << "!" << endl;

}
