#include <iostream>
#include <string>
#include <cstring>

#include <sstream>
#include <vector>

using namespace std;

int main() {
    string num;
    stringstream ss;
    vector<string> bin = {"0000", "0001", "0010","0011","0100", "0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111",};
    vector<string> hex = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
    int choice;

    cout << bin.size() << endl;
    cout << hex.size() << endl;

    // cout << "Enter number" << endl;
    // cin >> num;

    // 110 1111 0011
    //num = "11011110011";
    num = "2EF8";

    cout << "1. Binary to hex. \n2. Hex to binary" << endl;
    cin >> choice;

    //binary to hex
    int index = 0;
    string result = "";

    if (choice == 1) {
        if (num.size() % 4 != 0) {
            //num.erase(0, 1);
            num.insert(0, 4 - num.size() % 4, '0');
        }
        cout << "Binary to hex" << endl;
        //cout << num.size() << endl;
        cout << num.size() << endl;
        cout << num << endl;
        for (int i = 0; i + 4 <= num.size(); i+=4) {
            cout << i << endl;
            string temp = num.substr(i, 4);
            cout << temp << "<>" << endl;
            //cout << bin[index] << endl;
            for (int j = 0; j < bin.size();j++ ) {
                if (temp.compare(bin[j]) == 0) {
                    //cout << "t2" << endl;
                    result += hex[j];
                }
            }
        }
    }

    //hex to binary
    else if (choice == 2) {
        cout << "Hex to binary" << endl;
        for (int i = 0; i <= num.size(); i++) {
            //cout << i << endl;
            string temp = num.substr(i, 1);
            cout << temp << "<>" << endl;
            //cout << bin[index] << endl;
            for (int j = 0; j < hex.size();j++ ) {
                if (temp.compare(hex[j]) == 0) {
                    cout << bin[j] << endl;
                    result += bin[j];
                }
            }
        }
    }

    else {
        cout << "Enter a right choice" << endl;
    }
   cout << result << endl;


}