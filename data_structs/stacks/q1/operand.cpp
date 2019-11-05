#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <math.h>
#include <typeinfo>

using namespace std;

void showstack(stack <int> s)
{
    stack<int> temp = s;
    while (!temp.empty())
    {
        cout << '\t' << temp.top();
        temp.pop();
    }
    cout << '\n';
}

void showstackChar(stack <string> s)
{
    stack<string> temp = s;
    while (!temp.empty())
    {
        cout << '\t' << temp.top();
        temp.pop();
    }
    cout << '\n';
}

int main() {
    stack <int> nums;
    stack <string> ops;
    string exp;
    string final;

    cout << "Input an expression to evaluate" << endl;
    //getline(cin, exp);
    //exp = "3 + 6/3 * 2^3 - 1";
    exp = "6 ^ 2 / 9 + 5";

    exp.erase(remove_if(exp.begin(), exp.end(), ::isspace), exp.end());

    cout << exp << endl;

    bool marked = false;
    bool found = false;

    string t = "lelelel";

    vector<string> signs = {"/", "*", "^"};
    vector<string> bin = {"+", "-"};

    cout << exp[0] << endl;

    //get first char before search loop
    string temp = exp.substr(0, 1);
    stringstream tt(temp);
    int x = 0;
    tt >> x;
    nums.push(x);
    cout << exp.size() << endl;

    //start search
    for (int x = 1; x < exp.size(); x++) {
      std::string s(1, exp[x]);
      cout << "yo" << s << endl;
    //   cout << typeid(s).name() << endl;
    //   cout << typeid(exp).name() << endl;
    //   cout << typeid("+").name()<< endl;

    //checking if it's multiplication, division or exponents
      for (auto y: signs) {
          //cout << y << endl;
          if (s == y) {
            cout << "else" << s << endl;
            ops.push(s);
            marked = true;
            //found = true;
            goto aa;
          }

      }

    //checking if its add or subtract
      for (auto y: bin) {
          if (s == y) {
            cout << "else" << s << endl;
            ops.push(s);
            marked = true;
            //found = true;
            goto aa;
          }
      }


      if (marked) {
            stringstream ss(s);
            int n = 0;
            ss >> n;
            cout << "if " << s << endl;
            nums.push(n);

                cout << "marked" << endl;
                if (ops.top() == "/") {
                    int second = nums.top();
                    nums.pop();
                    int first = nums.top();
                    nums.pop();
                    cout << first << " / " << second << endl;
                    ops.pop();
                    nums.push(first / second);
                    showstack(nums);
                    showstackChar(ops);
                } else if (ops.top() == "*") {
                    int second = nums.top();
                    nums.pop();
                    int first = nums.top();
                    nums.pop();
                    ops.pop();
                    cout << first << " * " << second << endl;
                    nums.push(first * second);
                    showstack(nums);
                    showstackChar(ops);
                } else if (ops.top() == "^") {
                    int second = nums.top();
                    nums.pop();
                    int first = nums.top();
                    nums.pop();
                    ops.pop();
                    cout << first << " ^ " << second << endl;
                    nums.push(pow(first, second));
                    showstack(nums);
                    showstackChar(ops);
                }

            marked = false;
        }

        aa: {
            // if (ops.top() == "+") {
            //     int second = nums.top();
            //     nums.pop();
            //     int first = nums.top();
            //     nums.pop();
            //     cout << first << " + " << second << endl;
            //     ops.pop();
            //     nums.push(first + second);
            // } else if (ops.top() == "-") {
            //     int second = nums.top();
            //     nums.pop();
            //     int first = nums.top();
            //     nums.pop();
            //     ops.pop();
            //     cout << first << " - " << second << endl;
            //     nums.push(first - second);
            // }

        }

    //end of loop
    }

    for (int i = 0; i < ops.size(); i++) {
         if (ops.top() == "+") {
                int second = nums.top();
                nums.pop();
                int first = nums.top();
                nums.pop();
                cout << first << " + " << second << endl;
                ops.pop();
                nums.push(first + second);
            } else if (ops.top() == "-") {
                int second = nums.top();
                nums.pop();
                int first = nums.top();
                nums.pop();
                ops.pop();
                cout << first << " - " << second << endl;
                nums.push(first - second);
            }
    }

    showstack(nums);
    showstackChar(ops);

    cout << "The answer is " << nums.top() << endl;



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