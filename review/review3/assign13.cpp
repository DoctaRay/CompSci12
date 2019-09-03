#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  vector<string> sequence;
  string stuff = " ";

  cout << "Enter logo pics. Enter :q when you're done." << endl;

  while (stuff != ":q") {
    cin >> stuff;
    sequence.push_back(stuff);
  }
  for (auto x : sequence) {
    for (int d = 0; d < x.size(); d++) {
      cout << x[d];
    }

  }

}
