#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    stack <int> nums;
    stack <string> ops;
    stringstream ss;
    string exp;

    cout << "Input an expression to evaluate" << endl;
    getline(cin, exp);

    exp.erase(remove_if(exp.begin(), exp.end(), ::isspace), exp.end());

    cout << exp;

    for (int i = 0; i < exp.size(); i++) {

    }

}