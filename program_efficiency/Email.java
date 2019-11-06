package email;

import java.io.*;
import java.util.*;

public class Email {

    public static void main(String[] args) throws FileNotFoundException {
      Scanner input = new Scanner(new File("data11.txt"));  //data.txt  for test data
      ArrayList<String> unique = new ArrayList<String>();
       while(input.hasNext()){
       int num = input.nextInt();

       for(int c=0;c<num;c++){
           String email = input.next().toLowerCase();           //case insensitive
           String first=email.substring(0,email.indexOf("@"));  //email before the @ symbol
           String second = email.substring(email.indexOf("@")); //email after the @ symbol
           first=first.replaceAll("\\.", "");                   //dots before @ ignored
           int plusLoc=first.indexOf("+");                      //+ before @ location in string
           if(plusLoc>=0)first=first.substring(0,plusLoc);     //+ and string after ignored
           if(!unique.contains(first+second))unique.add(first+second);  //track unique emails in an array
       }
       System.out.println(unique.size());  //number of unique emails is the amount in the array
       unique.clear();  //clear the array for next data set

       }

    }
}