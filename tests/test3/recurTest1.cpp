#include <iostream>
#include <fstream>

using namespace std;

    // 2n + 3
int eq1(int n, int term, int finalTerm, int count) {
    if (term == finalTerm) return count;

    if (finalTerm % 2 != 0) {
        count = count * 2 + 3;
        finalTerm++;
    } else {
        count = count -2;
        finalTerm++;
    }

    return eq1(n, term, finalTerm, count);


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

