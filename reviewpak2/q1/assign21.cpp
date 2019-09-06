#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string reverseStr(string str) 
{ 
	    int n = str.length(); 
	      
	        // Swap character starting from two 
		//    corners 
		     
	    for (int i = 0; i < n / 2; i++) 
		    swap(str[i], str[n - i - 1]);
	return str;	    
} 

int main() {
	string word;
	string rword;

	cout << "What's your special word?" << endl;
	cin >> word;

	rword = reverseStr(word);
	int spaces = word.length();

	for (int a = 1; a < word.size(); a++) {
		spaces-=1;
		cout << string(spaces,' ') << word.substr(0, a) << reverseStr(word.substr(0, a- 1)) << string(spaces,' ') << endl;					}
	spaces -= 2;
	for (int b = word.size(); b >= 2; b=b-1) {
		spaces+=1;
		cout << string(spaces,' ') << word.substr(0, b) << reverseStr(word.substr(0, b- 1)) << string(spaces,' ') << endl;					}


	spaces = word.length() % 2 == 0 ? word.length() / 2 + 1: word.length() / 2 + 2;
	
	for (char& x: word) {
		cout << string(spaces, ' ') << x << endl;
	}
}
