#include <iostream>
#include <string>
#include "CalcFunctions.hpp"
using namespace std;

int main(){
	string top;
	string bot;
	
	cout << "Subtraction Caclulater" << endl;
	cout << "Top: " << endl;
	cin >> top;
	cout << "Bottom: " << endl;
	cin >> bot;
	
	cout << "Answer: " << Subtract(top,bot) << endl;
}