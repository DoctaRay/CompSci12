#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void palindrome(string str, int strcount, int count = 1, string check1="") {

    //checking for palindrome
    for (int i = 0; i < count; i++) {
        //reversing string
        check1=str.substr(i, strcount);
        string check2(str.rbegin(), str.rend());
        check2=check2.substr(i, strcount);

        //REMOVE SPACE
        int tempcount = 0;
        for (int t = 0; check1[t]; t++)
            if (check1[t] != ' ')
                check1[tempcount++] = check1[t];
        check1[tempcount] = '\0';

        tempcount = 0;
        for (int t = 0; check2[t]; t++)
            if (check2[t] != ' ')
                check2[tempcount++] = check2[t];
        check2[tempcount] = '\0';

        // lowering letters
        transform(check1.begin(), check1.end(), check1.begin(),
        [](unsigned char c){ return std::tolower(c); });

        transform(check2.begin(), check2.end(), check2.begin(),
        [](unsigned char c){ return std::tolower(c); });

        if (check1.compare(check2) == 0) {
            cout << check1 << "|" << check2 << endl;
            cout << "Sentence is palindrome." << endl;
            return;
        }
        else {
            cout << check1 << "|" << check2 << endl;
            cout <<"Sentence IS NOT palindrome" << endl;;
        }
    }
    strcount--;
    count++;

    //cout << "-----------------" << endl;
   // cout << check1 << endl;
    //cout << check2 << endl;

    palindrome(str, strcount, count, check1);
}

int main() {
    string str;
    //cout << "Enter string to check for palindromes: ";
    //cin >> str;

    str="I prefer pie.";

    int temp = str.length() - 1;
    palindrome(str, temp);

}