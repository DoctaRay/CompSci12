#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void palindrome(string str, int strcount, int count = 1, string check1="", int forcount = 0) {

    //don't use for loops
    //checking for palindrome
    //for (int i = 0; i < count; i++) {
        //reversing string
        check1=str.substr(forcount, strcount);
        string check2(check1.rbegin(), check1.rend());
        //check2=check2.substr(forcount, strcount);
        string temp = check1;
        //cout << check2 << endl;

        //REMOVE SPACE
        check1.erase(remove(check1.begin(), check1.end(), ' '), check1.end());

        check2.erase(remove(check2.begin(), check2.end(), ' '), check2.end());

        // lowering letters
        transform(check1.begin(), check1.end(), check1.begin(),
        [](unsigned char c){ return std::tolower(c); });

        transform(check2.begin(), check2.end(), check2.begin(),
        [](unsigned char c){ return std::tolower(c); });

        if (check1.compare(check2) == 0) {
            cout << check1 << "|" << check2 << endl;
            //cout << check1[0] << " / " << check2[0];
            cout << "Sentence is palindrome." << endl;
            temp.erase(temp.begin(), std::find_if(temp.begin(), temp.end(), std::bind1st(std::not_equal_to<char>(), ' ')));
            cout << "It was <" << temp << ">";
            return;
        }
        else {
            cout << check1 << "|" << "<" << check2 << ">" << endl;
            //cout << check1[0] << " / " << check2[0];
            cout <<"Sentence IS NOT palindrome" << endl;
            forcount++;
        }
    //}
    if (forcount == count) {
        strcount--;
        count++;
        forcount = 0;
        cout << "----------------------------" << endl;
    }

    //cout << "-----------------" << endl;
   // cout << check1 << endl;
    //cout << check2 << endl;

    palindrome(str, strcount, count, check1, forcount);
}

int main() {
    string str;
    cout << "Enter string to check for palindromes: ";
    getline(cin, str);

    //str="Racecar likes race car";

    int temp = str.length();
    palindrome(str, temp);

}