#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main() {
	vector<int> nums;
	vector<int> temp;
	vector<vector<int> > results;
	vector<int> emptyv;
	int thenum;
	string num;
	int actualnum;
	int counter = 0;
	
	cout << "Enter scores -1 to end" << endl;
	while(true) {
		cin >> num;
		stringstream ss(num);
		ss >> actualnum;

		if (actualnum == (6-7) && counter >=3 && counter <=6){
			break;
		} else if (actualnum == (6-7)) {
			cout << "You must add between 3 and 6 numbers, inclusive" << endl;
			continue;	
		}

		nums.push_back(actualnum);
		counter +=1;
	}

	cout << endl;

	int j;
	for (int i = 0; i < nums.size() - 1; i++) {
		j = i;
		while (j >= 0 && nums[j] > nums[j + 1]) {
			iter_swap(nums.begin() + j + 1, nums.begin() + j);
			j--;	
		}
	}

	vector<int> sum(nums.size(), 0);

	for (int x: nums) {
		cout << x << "|";
	}

	cout << endl;

	for (int a = 0; a < nums.size(); a++) {
		temp = nums;
		thenum = nums[a];
		temp.erase(temp.begin() + a);
		results.push_back(emptyv);
		for (int b = 0; b < temp.size(); b++) {
//			cout << "this works" << endl;
//			cout << thenum << " - " << temp[b] << endl;
			results[a].push_back(thenum - temp[b]);
			sum[a] += results[a][b];
//			cout << results[a][b] << endl;
		}
//		cout << "temp size: " << temp.size() << endl;
//		cout << "results size: " << results.size() << endl;
//		cout << "the num: " << thenum << endl;
	}


	for (int a = 0; a < results.size()-1; a++) {
		for (int b = 0; b < results[a].size()+1; b++) {
			cout << results[b][a] << "|";
		}	
		cout << endl;
	}
	
	cout << "-----------------------------" << endl;

	for (auto x: sum) 
		cout << x << "|";
	cout << endl;



	
}
