#include <queue>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printQ(queue <string> gq)
{
    queue <string> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}

int main(int argc, const char** argv) {
    queue<string> list;
    srand(time(0));
    string name;


    while(true) {
        cout << "Enter a list of names to simulate" << endl;
        cin >> name;
        if (name == "-1") {
            break;
        }
        list.push(name);
    }

    int choice;


    while (true) {
        int r = (rand() % 10) + 1;
            cout << "The random num is " << r << endl;

        if (list.size() == 1) {
            //cout << "lol";
            break;
        }
        printQ(list);
        for (int i = 0; i < r; i++) {
            string front = list.front();
            string back = list.back();

            list.pop();

            list.emplace(front);
            //list.push(back);
        }
        cout << "Player " << list.front() << " has been eliminated" << endl;
        list.pop();

        //cout << list.size() << endl;
        //printQ(list);


        // cout << "Continue?" << endl;
        // cin >> choice;



        // if (choice == 1) {
        //     continue;
        // } else {
        //     break;
        // }
    }

    cout << "Player " << list.front() << " is the winner! " << endl;
}