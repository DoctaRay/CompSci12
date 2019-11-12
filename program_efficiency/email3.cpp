// package email;

// import java.io.*;
// import java.util.*;
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

using namespace std;

//refactor
void ReplaceAll(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
}

// public class Email {
int main(int argc, const char** argv) {
    clock_t start = clock();

//     public static void main(String[] args) throws FileNotFoundException {
//       Scanner input = new Scanner(new File("data11.txt"));  //data.txt  for test data
    ifstream myFile;
    myFile.open("data11.txt");

//       ArrayList<String> unique = new ArrayList<String>();
    vector<string> unique;
    string email;
    string first = "";
    string second ="";
    int plusLoc;
    bool isInside = false;
//        while(input.hasNext()){
    while(!myFile.eof()){
        //usleep(3000000);

//        int num = input.nextInt();
        int num;
        myFile >> num;
        printf("%d\n", num);
        //cout << num << endl;


//        for(int c=0;c<num;c++){
        for (int c = 0; c < num; c++) {
//            String email = input.next().toLowerCase();           //case insensitive
                myFile >> email;
                //transform(email.begin(), email.end(), email.begin(), [](unsigned char c){ return std::tolower(c); });
                for (int i = 0; i < email.length(); i++) {
                    email[i] = tolower(email[i]);
                }
                //printf("lowercase email %s\n", email.c_str());
//            String first=email.substring(0,email.indexOf("@"));  //email before the @ symbol
                //first = email.substr(0, email.find("@"));
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

//            first=first.replaceAll("\\.", "");                   //dots before @ ignored
                //ReplaceAll(first, ".", "");
                for (int i = 0; i < first.length(); i++) {
                    if (first[i] == '.') {

                        //printf("yeet %c \n", first[i]);
                        first.erase(i, 1);
                        //break;
                    }
                }
                //printf("removing dots %s\n", first.c_str());
                //cout << first << endl;
//            String second = email.substring(email.indexOf("@")); //email after the @ symbol
                //second = email.substr(email.find("@"));
                // cout << second << endl;
                // cout << first + second << endl;


//            int plusLoc=first.indexOf("+");                      //+ before @ location in string
                //plusLoc = first.find("+");
                for (int i = 0; i < first.length(); i++) {
                    if (email[i] == '+') {
                        plusLoc = i;
                        break;
                    }
                }
//            if(plusLoc>=0)first=first.substring(0,plusLoc);     //+ and string after ignored
                if(plusLoc>= 0) {
                    first = first.substr(0, plusLoc);
                    for (int i = 0; i < plusLoc; i++) {
                        first.push_back(email[i]);
                    }
                }
//            if(!unique.contains(first+second))unique.add(first+second);  //track unique emails in an array
                for (int i = 0; i < unique.size(); i++) {
                    if (unique[i].compare(first+second) ==0) {
                        isInside = true;
                        break;
                    }
                }

                if(!isInside) {
                    //cout << "works!" << endl;
                    unique.push_back(first+second);
                }
                second = "";
                //printf("joop \n");
//        }
        }
//        System.out.println(unique.size());  //number of unique emails is the amount in the array
        //cout << unique.size() << endl;
        //int n = (int)unique.size();
        printf("found %d\n", (int)unique.size());
        //cout << "--------------------" << endl;
//        unique.clear();  //clear the array for next data set
        unique.clear();
//        }

//     }
// }
        //break;
    }
    printf("Time taken: %.2fs\n", (double)(clock() - start)/CLOCKS_PER_SEC);
    return 0;
}