#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include <typeinfo>

using namespace std;

int main() {
	locale loc;
	vector<vector<int> > rows;
	vector<int> temp = { 0, 0, 0, 0, 0, 0, 0, 0 };
	bool play = true;
	bool win = false;
	int player = 1;
	char input;
	int choice = 0;
	vector<char> letters = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

	
	for (int i = 0; i <=7; ++i) {
		rows.push_back(temp);
	}
	while(play) {
	
	for (int b = 0; b<= rows.size() - 1; b++) {
		for (int a = 0; a <= rows[b].size() - 1; a++) {
			cout << rows[b][a] << " ";
		}
		cout << endl;
	}
	cout << "---------------" << endl;
	cout << "A B C D E F G H" << endl;
	if (win) {
		cout << "Player " << player << " wins!" << endl;
		break;
	}

	cout << "Player " << player << ", make your move." << endl;
	cin.get(input);
	cin.get();
	cout << "<" << input << ">" <<endl;
	cout << typeid(input).name() << endl;
	input = toupper(input, loc);

	cout << input << endl;
	cout << "test 1" << endl;
	
	for (int a = 0; a <= letters.size() - 1; a++) {
		if (letters[a] == input) {
			choice = a;
			break;
		}
	}

	cout << "test 2" << endl;
	cout << choice << endl;
	for (int i = rows.size() - 1; i >= 0; i--) {	
		cout << "test 3 " << endl;
		if (rows[i][choice] == 0) {
			cout << "test 4" << endl;
			rows[i][choice] = player;
			break;	
		}
	}
	
	cout << "test 5" << endl;
	
	for (int a = rows.size()-1; a>=0; a--){
		/*if (a==0 || a==7 || a==1 || a==6) 
			continue;*/
		for (int b=0; b<= rows[a].size() - 1; b++) {
			if (rows[a][b] == player && rows[a-1][b-1] == player && rows[a-1][b+1] == player && rows[a-2][b-2] == player && rows[a-2][b+2] == player) {
				win = true;
		}
	}
	}

	cout << "test 6 " << endl;

	for (int a = 0; a<= rows.size() - 1; a++){
			if (a==0 || a==7 || a==1 || a==6) 
				continue;
		for(int b=0; b<= rows[a].size() - 1; b++) {
			if (rows[a][b] == player && rows[a+1][b-1] == player && rows[a+1][b+1] == player && rows[a+2][b-2] == player && rows[a+2][b+2] == player)
				win=true;
		}
	}
	cout << "test 7" << endl;

	if (win == false && player == 1) {
		player++;	
	} else if (win == false && player == 2){
		player--;
	}

	
	}


/*
	for (auto x: rows) {
		for (int a = 0; a <=8; ++a) {
			x.push_back(1);
		}
	}
*/
	
}
