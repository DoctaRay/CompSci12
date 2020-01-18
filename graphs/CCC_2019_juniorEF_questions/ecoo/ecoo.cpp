#include <vector>
#include <cstdlib>
#include <fstream>
#include <unordered_set>
#include <iostream>
#include <map>
#include <iterator>

using namespace std;

struct Node {
	Node *motherNode;
	string name;
	int numSisters = 0;
	int numCousins = 0;
};

bool isSister(Node one, Node two) {
	Node temp = *(one.motherNode);
	Node temp2 = *(two.motherNode);
	if (temp.name == temp2.name) {
		return true;
	} else {
		return false;
	}
}

bool isCousin(Node one, Node two) {
	Node temp = *(one.motherNode);
	Node temp2 = *(two.motherNode);
	Node temp3 = *(temp.motherNode);
	Node temp4 = *(temp2.motherNode);
	if (temp3.name == temp4.name) {
		return true;
	} else {
		return false;
	}
}

void quickSort(vector<string>& a, int start, int end)
{

	int i = start;
	int j = end;


	if (j - i >= 1)
	{
		string pivot = a[i];
		//cout << "comparing " << start << " with " << pivot << endl;
		while (j > i)
		{
			while (a[i].compare(pivot) <= 0 && i <= end && j > i) {
				i++;
			}
			while (a[j].compare(pivot) >= 0 && j >= start && j >= i) {
				j--;
			}
			if (j > i)
				swap(a[i], a[j]);
		}

		swap(a[start], a[j]);
		quickSort(a, start, j - 1);
		quickSort(a, j + 1, end);
	}
}

int binarySearch(vector<string>& vec, string x, int n) {

	//cout << "string comparing " << x << endl;
	int l = 0;
	int r = n - 1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		int res = x.compare(vec[m]);
		//cout << "string being compared: " << vec[m].curr << " with index " << m << endl;

		// if (x == (vec[m])) {
		//     //cout << "t1 " << vec[m] << endl;
		//     res = 0;
		// }

		// Check if x is present at mid
		if (res == 0) {
			////cout << "t2" << vec[m] << endl;
			//wordsf.push_back(vec[m]);
			return m;
		}

		// If x greater, ignore left half
		if (res > 0) {
			////cout << "t3" << vec[m] << endl;
			l = m + 1;
		}

		// If x is smaller, ignore right half
		else {
			////cout << "t4" << vec[m] << endl;
			r = m - 1;
			////cout << vec[m].compare(x) << endl;
			/*//cout << l << endl;
			//cout << r << endl;
			//cout << m << endl;
			//cout << res << endl;
			//cout << x << endl;
			//cout << x.compare(vec[m]) << endl;*/
			//if(x.compare(vec[m]) == 0) return m;
		}

	}

	return -1;
}

int main(int argc, char const *argv[])
{
	ifstream file;
	file.open("ECOO_DATA20.txt");

	unordered_set<string> uniqueNames;


	int nodeNum;

	file >> nodeNum;

	//cout << "rurr" << endl;

	//cout << nodeNum << endl << endl;
	map<string, vector<string> > list;

	//Node ansArr [10];
	string ansArr[10];

	//Node nodeArr [nodeNum];
	//vector<Node> nodeVec;


	for (int i = 0; i < nodeNum; i++) {
		Node mother;
		Node daughter;
		file >> mother.name;
		file >> daughter.name;

		list[mother.name].push_back(daughter.name);


	}


	// for (auto x : list) {
	// 	cout << x.first << "-->";
	// 	for (auto y : x.second) {
	// 		cout << y << ", ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	for (int i = 0; i < 10; i++) {
		file >> ansArr[i];
		//cout << ansArr[i] << endl;
	}
	//cout << endl;


	map<string, vector<string> >::iterator itr;
	for (itr = list.begin(); itr != list.end(); ++itr) {
		//cout << "sorting " << itr->first << endl; 
		quickSort(itr->second, 0, itr->second.size() - 1);
		// for (auto y : itr->second) {
		// 	cout << y << ", ";
		// }
		// cout << endl;
	}
	//cout << endl;

	// for (auto x : list) {
	// 	cout << x.first << "-->";
	// 	for (auto y : x.second) {
	// 		cout << y << ", ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	for (int j = 0; j < 10; j++) {
		//cout << endl << "searching for " << ansArr[j] << endl;
		for (auto x : list) {
			//if you find one of the ten names in a child vector of mother
			if (binarySearch(x.second, ansArr[j], x.second.size()) != -1) {
				//cout << ansArr[j] << ": sisters -> " << x.second.size() - 1 << ", ";
				//finding mother of mother
				for (auto y : list) {
					if (binarySearch(y.second, x.first, y.second.size()) != -1) {
						int count = 0;
						for (auto w : y.second) {
							//w = aunt name
							if (w == x.first) {
								continue;
							} else {
								//cout << "aunt " << w << endl;
								//cout << "cousins -> " << y.second.size() << " ";
								//trying to find aunt name in list
								
								for (auto l : list) {
									//cout << "l: " << l.first << endl;
								 	if (l.first == w) {
								 		//cout << "cousins -> " << l.second.size() << " ";
								 		//cout << "from " << l.first << endl;
								 		count+= l.second.size();
								 		//cout << "count: " << count << endl;
								 		//goto aa;
								 	}
								}

								//goto aa;
							}
						}
						cout << "Cousins: " << count;
					}

				}
				aa: {
					cout << ", Sisters: " << x.second.size() - 1 << ", " << endl;
				}
			}
		}
		
	}



}