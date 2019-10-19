#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;

struct Word {
	string theone;
	int times = 0;
};

int main() {
	ifstream inFile;
	string str;
	string input;
	string result;

	inFile.open("Wordstats.txt");
	vector<Word> words = {};
	vector<string> values;
	vector<string> tester;
	//regex pat("([A-Z])|([a-z])\w+");
	//smatch m;
	if (!inFile) {
		cout << "Error";
	        exit(1);
	}
	/*if (inFile.is_open()) {
		while(getline(inFile, str)){
			regex_search(str, m, pat);
			//string rev(str.rbegin(), str.rend());
			for (auto x: m){
				cout << x << " ";
			}

		}
		inFile.close();
	}*/

	words.push_back(Word());

	while(inFile >> str){
		//tester.push_back(str);
		// cout << "start" << endl;
		cout << str << " ";
		for (int i =0, len = str.size(); i < len; i++) {
			str[i] = tolower(str[i]);
			if (ispunct(str[i])) {
				str.erase(i--, 1);
				len = str.size();
			}
		}
		for (int i = 0; i < words.size(); i++) {
			if (words[i].theone.compare(str) != 0 && i == words.size() - 1){
				words.push_back(Word());
				words[words.size() - 1].theone = str;
				//words[words.size() - 1].times += 1;
			}
			else if (words[i].theone.compare(str) != 0) {
				continue;
			}

			else if (words[i].theone.compare(str) == 0) {
				words[i].times += 1;
				break;
			}



		}


	}

	cout << endl;

	for (auto x: words) {
		values.push_back(x.theone);
	}

	sort(words.begin(), words.end(), [](Word a, Word b) {
		return a.theone < b.theone;
	});





	cout << endl;



	/*for (int i = 0; i < tester.size(); i++){
		for (int j = 0; j < words.size(); j++) {
			if (words[j].theone != tester[i]){
				words.push_back(Word());
				words[j].theone = tester[i];
				words[j].times += 1;
			}
			else if (words[j].theone == tester[i]){
				words[i].times += 1;
			}
		}
	}*/
	//cout << words.size() << endl;
	//cout << tester.size() << endl;

	words.erase(words.begin());
	// words[0].times += 1;
	cout << "Words : Occurences" << endl;
	cout << "------------------" << endl;

	for (int i = 0; i < words.size(); i++) {
		cout << words[i].theone << ": " << words[i].times << endl;
	}

	//cout << "yeet" << endl;

	//return 0;
	//getline(inFile,str);
	/*while (inFile) {
		processLine(str);
		string rev(str.rbegin(), str.rend());
		cout << rev << endl;
		getline(inFile, str);
	}*/


}
