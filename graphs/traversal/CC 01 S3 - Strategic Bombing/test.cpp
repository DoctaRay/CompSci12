// C++ program to demonstrate functionality of unordered_map 
#include <iostream> 
#include <unordered_map> 
#include <vector>

using namespace std; 
  
int main() 
{ 
    // Declaring umap to be of <string, int> type 
    // key will be of string type and mapped value will 
    // be of double type 
    unordered_map<string, vector<int> > umap; 
  
    // inserting values by using [] operator 
    umap["GeeksforGeeks"].push_back(10); 
    umap["Practice"].push_back(20); 
    umap["Contribute"].push_back(30); 
  
    // Traversing an unordered map 
    for (auto x : umap) 
      cout << x.first << " " << x.second[0] << endl; 
  
} 