#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

/* void getTag(const string &str)
{
	string & ptag = "<p>";
	size_t posptag = string::npos;
	while (( posptag = str.find(ptag) ) != string::npos) {
		str.erase(posptag, ptag.size());		
	}
	

	string::size_type start = str.find("<p>");
	
		if (start != str.npos) {
				    string::size_type end = str.find("<p>", start + 1);
				
				    if (end != str.npos){
					   ++start;
		        		   std::string::size_type count = end - start;
			                   return str.substr(start, count);						      }
		}
		return ""; 
} */

int main() {
	ifstream file("text.txt");
	string test;
	//string test = "<p> Hello World <p><p> He he hoo hoo <p><br><p> Giggity goo <p><hr>";
	// getTag(test);
	if (file) {
		getline(file, test);
	//	file.close();
	}
	else cout << "yikers\n";

	vector<size_t> pposits;
	vector<size_t> brposits;
	vector<size_t> hrposits;
	int size;
	string para = "<p>";
	string br = "<br>";
	string hr = "<hr>";
	size_t npos = test.find(para);

	cout << "Enter line character limit(>28): ";
	cin >> size;
	cout << endl;
	
	while (npos != string::npos) {
		pposits.push_back(npos);
		npos = test.find(para, npos + para.size());
	}

	//test.replace(posits[0], 3, " ");

	for (int i = 0; i < pposits.size(); i++) {
		test.replace(pposits[i] - i*3 + i*2, 3, "\n\n");
		//cout << x << endl;
	}
//	cout << test << endl;
	for (auto x: pposits) {
		cout << x << endl;
	}
//	return 0;

	/*for (int i = 0; i < (int)(test.size() / 35); i++) {
		test.replace(i*35, 0, "\n");
	}*/

	npos = test.find(br);
	while (npos != string::npos){
		brposits.push_back(npos);
		npos = test.find(br, npos + br.size());
	}


	for (int i = 0; i < brposits.size(); i++) {
		test.replace(brposits[i] - i*4 + i, 4, "\n");
		//cout << x << endl;
	}
	
	npos = test.find(hr);
	while (npos != string::npos){
		hrposits.push_back(npos);
		npos = test.find(hr, npos + hr.size());
	}

	for (int i = 0; i < hrposits.size(); i++) {
		test.replace(hrposits[i] - i*4 + i, 4, "------------------------------");
		//cout << x << endl;
	}

//	cout << test << endl;
//	return 0;
//	cout << test << endl;

	int l = 0;
	string temp;

	for (int i = 1; i < test.size(); i++) {
		l++;
		if (l > size) {
			//cout << "bucktee" << endl;
			for (int j = i; j > 0; j--){

				if(test.substr(j-1, 1).compare(" ") == 0) {
					// cout << "xd";
					// cout << "doot";
					temp = test.substr(0,j);
					temp += "\n";
					temp += test.substr(j, test.size() - j);
					test = temp;
					i = j + 1;
					break;
				}		
			}	
		}

		if(test.substr(i-1,1).compare("\n") == 0) {
		       	//cout << "doot";
			l = 0;
		}
	}

	cout << test << endl;
	file.close();
	return 0;
	
}
//<p>(.+?)<p>
