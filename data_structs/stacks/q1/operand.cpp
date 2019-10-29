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

void showstackChar(stack <string> s)
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
    stack <string> ops;
    stringstream ss;
    string exp;
    string final;

    cout << "Input an expression to evaluate" << endl;
    //getline(cin, exp);
    exp = "3+5/3+2^3";

    exp.erase(remove_if(exp.begin(), exp.end(), ::isspace), exp.end());

    cout << exp << endl;

    bool marked = false;


    //cout << exp[1] << endl;

    for (int x = 0; x < exp.size(); x++) {
      std::string s;
      s = exp[x];
      if (s != "+" || s != "+" || s != "/" || s != "*" || s != "^") {
        cout << "if" << s << endl;
        int n;
        ss >> s;
        ss << n;
        nums.push(n);
        if (marked) {
          cout << "marked" << endl;
          if (ops.top() == "/") {
            int second = nums.top();
            nums.pop();
            int first = nums.top();
            cout << first << " / " << second << endl;
            ops.pop();
            nums.push(first / second);
          } else if (ops.top() == "*") {
            int second = nums.top();
            nums.pop();
            int first = nums.top();
            ops.pop();
            cout << first << " * " << second << endl;
            nums.push(first * second);
          } else if (ops.top() == "^") {
            int second = nums.top();
            nums.pop();
            int first = nums.top();
            ops.pop();
            cout << first << " ^ " << second << endl;
            nums.push(pow(first, second));
          }
        }
      } else {
        cout << "else" << s << endl;
        ops.push(s);
        marked = true;
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