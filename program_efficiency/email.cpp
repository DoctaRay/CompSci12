// package email;

// import java.io.*;
// import java.util.*;
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

//refactor
std::string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

// public class Email {
int main(int argc, const char** argv) {

//     public static void main(String[] args) throws FileNotFoundException {
//       Scanner input = new Scanner(new File("data11.txt"));  //data.txt  for test data
    ifstream myFile;
    myFile.open("data11.txt");
//       ArrayList<String> unique = new ArrayList<String>();
    vector<string> unique;
    string email;
    string first;
    string second;
    int plusLoc;
//        while(input.hasNext()){
    while(!myFile.eof()){


//        int num = input.nextInt();
        int num;
        myFile >> num;


//        for(int c=0;c<num;c++){
        for (int c = 0; c < num; c++) {
//            String email = input.next().toLowerCase();           //case insensitive
                myFile >> email;
                transform(email.begin(), email.end(), email.begin(), [](unsigned char c){ return std::tolower(c); });
//            String first=email.substring(0,email.indexOf("@"));  //email before the @ symbol
                first = email.substr(0, email.find("@"));
//            String second = email.substring(email.indexOf("@")); //email after the @ symbol
                second = email.substr(email.find("@"));
//            first=first.replaceAll("\\.", "");                   //dots before @ ignored
                ReplaceAll(first, "\\.", "");
//            int plusLoc=first.indexOf("+");                      //+ before @ location in string
                plusLoc = first.find("+");
//            if(plusLoc>=0)first=first.substring(0,plusLoc);     //+ and string after ignored
                if(plusLoc>= 0) first = first.substr(0, plusLoc);
//            if(!unique.contains(first+second))unique.add(first+second);  //track unique emails in an array
                if(find(unique.begin(), unique.end(), first+second) != unique.end()) unique.push_back(first+second);
//        }
        }
//        System.out.println(unique.size());  //number of unique emails is the amount in the array
        cout << unique.size() << endl;
//        unique.clear();  //clear the array for next data set
        unique.clear();
//        }

//     }
// }

    }
    return 0;
}