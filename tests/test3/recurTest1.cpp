#include <iostream>
#include <fstream>

using namespace std;

    // 2n + 3
int eq1(int n, int term, int finalTerm, int val) {
    if (term == finalTerm) return val;

    if (finalTerm % 2 != 0) {
        val = val * 2 + 3;
        finalTerm++;
    } else {
        val = val -2;
        finalTerm++;
    }

    //return value here if the return type is not a bool or void
    return eq1(n, term, finalTerm, val);


}


int main() {
    int init;
    int term;

    cout << "enter initial term:" << endl;
    cin >> init;

    cout << "enter term" << endl;
    cin >> term;

    cout << "answer is " << eq1(init, term, 1, init);
}

