#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <math.h>

using namespace std;

void showstack(stack <int> s)
{
    while (!s.empty())
    {
        cout << '\t' << s.top();
        s.pop();
    }
    cout << '\n';
}

void showstackChar(stack <char> s)
{
    while (!s.empty())
    {
        cout << '\t' << s.top();
        s.pop();
    }
    cout << '\n';
}

int main() {
    stack <int> nums;
    stack <char> ops;
    stringstream ss;
    string exp;
    string final;

    cout << "Input an expression to evaluate" << endl;
    //getline(cin, exp);
    exp = "3+5/3+2^3";

    exp.erase(remove_if(exp.begin(), exp.end(), ::isspace), exp.end());


    cout << exp << endl;

    int x = 0;

    for (int x = 0; x < exp.size(); x++) {
        if (exp[x] != '+' || exp[x] != '-' || exp[x] != '/' || exp[x] != '*' || exp[x] != '^') {
            nums.push(exp[x] - '0');
        } else {
            ops.push(exp[x]);
            if (ops.top() == '/') {
                int second = nums.top();
                nums.pop();
                int first = nums.top();
                cout << first << " / " << second << endl;
                nums.push(first / second);
            }
            else if (ops.top() == '*') {
                int second = nums.top();
                nums.pop();
                int first = nums.top();
                cout << first << " * " << second << endl;
                nums.push(first * second);
            }
            else if (ops.top() == '^') {
                int second = nums.top();
                nums.pop();
                int first = nums.top();
                cout << first << " ^ " << second << endl;
                nums.push(pow(first, second));
            }
        }
    }

    showstack(nums);
    showstackChar(ops);




    // for (int i = 1; i < exp.size(); i++) {
    //     switch (exp[i]) {
    //         case '*': {
    //             ops.push('*');
    //             break;
    //         }
    //         case '/': {
    //             ops.push('/');
    //             break;
    //         }
    //         case '^': {
    //             ops.push('^');
    //             break;
    //         }
    //         case '+': {
    //             ops.push('+');
    //             break;
    //         }
    //         case '-': {
    //             ops.push('-');
    //             break;
    //         }

    //         default : {
    //             nums.push(exp[i]);
    //             for (int j = 0; j < ops.size(); j++) {
    //             switch (ops) {
    //                 case '*': {
    //                     int x = nums.top();
    //                     nums.pop();
    //                     int y = nums.top();
    //                     nums.push(y * x);
    //                     break;
    //                 }
    //                 case '/': {
    //                     int x = nums.top();
    //                     nums.pop();
    //                     int y = nums.top();
    //                     nums.push((y / x));
    //                     break;
    //                 }
    //                 case '^': {
    //                     int x = nums.top();
    //                     nums.pop();
    //                     int y = nums.top();
    //                     nums.push(pow(y, x));
    //                     break;
    //                 }
    //                 case '+': {
    //                     int x = nums.top();
    //                     nums.pop();
    //                     int y = nums.top();
    //                     nums.push(y + x);
    //                     break;
    //                 }
    //                 case '-': {
    //                     int x = nums.top();
    //                     nums.pop();
    //                     int y = nums.top();
    //                     nums.push(y - x);
    //                     break;
    //                 }
    //             }
    //             }
    //         }
    //     }
    // }

}