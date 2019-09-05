#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  vector<string> sequence;
  string stuff = " ";
  char letter;
  int count;
  char ch;
  int factor;

  cout << "Enter logo pics. Enter :q when you're done." << endl;

	//cin >> stuff;
	//sequence.push_back(stuff);

  
  while (stuff != ":q") {
	  /*if (cin.get() == '\n'){
	  	cin >> stuff;
		sequence.push_back(stuff);
	  }*/

	getline(cin, stuff);
	sequence.push_back(stuff);	
  }

  cout << "Enter scaling factor: ";

  cin >> factor;
  
	sequence.pop_back();


  for (auto x : sequence) {
        //cout << x << endl;
	  for (int a = 0; a < factor; a++) {
	  for (int d = 0; d <= x.size(); d++) {
		//cout << x[d] <<endl;  
		if (letter != x[d] || letter == '\n') {
			for (int b = 0; b <= count * factor + 2; b++) {
				cout << letter;
			}
			letter = x[d];
			count = 0;
		}
		else if (letter == x[d]) {
			count++;
		}
	}
  cout << "" << endl << "";
  }
  }
}
