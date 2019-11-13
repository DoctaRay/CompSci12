/*
- Implement quick sort
- Implement binary search
- 
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

using namespace std;

int main(int argc, const char** argv) {
    clock_t start = clock();
    ifstream myFile;
    myFile.open("data11.txt");


    vector<string> unique;
    string email;
    string first = "";
    string second ="";
    int plusLoc;
    bool isInside = false;
    int count = 0;

    while(!myFile.eof()){
        //usleep(3000000);


        int num;
        myFile >> num;
        //printf("%d\n", num);

        for (int c = 0; c < num; c++) {
            //printf("*********\n");

                myFile >> email;

                for (int i = 0; i < email.length(); i++) {
                    email[i] = tolower(email[i]);
                }
                //printf("lowercase email %s\n", email.c_str());


                for (int i = 0; i < email.length(); i++) {
                    if (email[i] == '@') {
                        //first.push_back(email[i]);
                        break;
                    }
                    first.push_back(email[i]);
                }
                //printf("pre email %s\n", first.c_str());

                for (int i = first.length() + 1; i < email.length(); i++) {
                    second.push_back(email[i]);
                }
                //printf("post email %s\n", second.c_str());

                for (int i = 0; i < first.length(); i++) {
                    if (first[i] == '.') {

                        //printf("yeet %c \n", first[i]);
                        first.erase(i, 1);
                        //break;
                    }
                }
                //printf("removing dots %s\n", first.c_str());






                for (int i = 0; i < first.length(); i++) {
                    if (first[i] == '+') {
                        plusLoc = i;
                 //       //printf("found + at %d\n", plusLoc);
                        break;
                    }
                }

                if(plusLoc> 0) {
                    string temp = "";
                    //first="";
                    //first = first.substr(0, plusLoc);
                    for (int i = 0; i < plusLoc; i++) {
                        temp.push_back(first[i]);
                    }
                 //   //printf("%d, %s\n", plusLoc, temp.c_str());
                    first = temp;
                }

                for (int i = 0; i < unique.size(); i++) {
                    if (unique[i].compare(first+second) ==0) {
                        isInside = true;
                        break;
                    }
                ////printf("%s, %s\n", unique[i].c_str(), (first+second).c_str());
                ////printf(isInside ? "true\n" : "false\n");
                }

                if(!isInside) {
                    //printf("final %s \n", (first + second).c_str());
                    unique.push_back(first+second);
                } else {
                    //printf("else %s \n", (first + second).c_str());
                }
                //printf("joop \n");
//        }
            first="";
            second = "";
            isInside = false;
            plusLoc = -1;
            //printf("%zu\n", unique.size());
        }

        printf("founded %d\n", (int)unique.size());
        printf("------------------------------\n");


        unique.clear();

        // count++;
        // if (count == 3) break;
    }
    printf("Time taken: %.2fs\n", (double)(clock() - start)/CLOCKS_PER_SEC);
    return 0;
}