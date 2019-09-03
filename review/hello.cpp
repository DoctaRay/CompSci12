#include <iostream>
using namespace std;
 
int main()
{
	  float bmi = 0;
	  float weight = 0;
	  float height = 0;
	        
	  cout << "Input height in m:" << endl;
	  
	  cin >> height;
	  
	  cout << "Input weight in kg: " << endl;

	  cin >> weight;
		    
	  float denom = height * height;

	  bmi = weight / denom;
		      
	
	  if (bmi > 25) {

		  cout << "Overweight";

	  } else if (bmi <= 25 && bmi >= 18.5){
		  
		  cout << "Normal weight";

	  } else if (bmi < 18.5) {

		  cout << "Underweight";

	  } else {

		  cout << "You dun messed up";  

	  }
}

