#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void palindrome(string str, int count = 1, string check1="") {
    check1=str.substr(0, count);
    string check2(str.rbegin(), str.rend());
    check2=check2.substr(0, count);
    count++;

    //cout << "-----------------" << endl;
   // cout << check1 << endl;
    //cout << check2 << endl;

        if (check1.length() == str.length()) {
            if (check1.compare(check2) == 0) {
            cout << "Sentence is palindrome.";
            return;
            }
            else {
                cout <<"Sentence IS NOT palindrome";
                return;
            }
        }

    palindrome(str, count, check1);
}

int main() {
    string str;
    cout << "Enter string to check for palindromes: ";
    cin >> str;

    palindrome(str);

}