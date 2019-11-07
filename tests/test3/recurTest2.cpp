#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string check2(string input, int icount, string cipher, string alpha, string encrypt = "") {
    //encrypt+= "";
    if (icount == input.length()) return encrypt;

    else {
        encrypt+=cipher.substr(alpha.find(input.substr(icount, 1)),1
         //cipher.size() - alpha.find(input.substr(icount, 1))+1
         );
        //cout << encrypt << endl;
        }
    icount++;

    return check2(input, icount, cipher, alpha, encrypt);

    // string alphabet = "abcdefghijklmnopqrstuvwxyz ";
    // if (incount == input.size()) {
    //     cout << "Encrypted text is " << encrypted << endl;
    //     return;
    // }

    // if (input[incount] == cipher[cicount]) {
    //     encrypted.push_back(cipher[cicount]);
    //     incount++;
    //     check(input, cipher, incount, cicount, encrypted);
    // } else {
    //     cicount++;
    //     check(input, cipher, incount, cicount, encrypted);
    // }
}

int main(int argc, const char** argv) {
    ifstream myFile;
    myFile.open("data.txt");
    string cipher;
    string input;
    string alphabet = "abcdefghijklmnopqrstuvwxyz ";


    getline(myFile, cipher);

    cipher+= " ";
    cout << cipher.size() << endl;
    cout << cipher << endl;

    // cout << "Enter text to be encrypted" << endl;
    // getline(cin, input);

    input = "have a nice day";

    cout << "text is " << check2(input, 0, cipher, alphabet) << endl;

    //return 0;
}