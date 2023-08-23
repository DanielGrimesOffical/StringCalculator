#include <iostream>
#include <string>
#include "CalcFunctions.hpp"
using std::cout, std::endl, std::string;

unsigned int AlphaToInt(char a){
	if ((a < '0') || ( a > '9')){throw std::invalid_argument("in AlphaToInt Function a non numerial value was used as parameter. Only values from 1 to 9 can be used as parmeters");}
	
	return (int)a - '0';
}

char IntToAlpha(unsigned int a){
	if (( a > 9)){throw std::invalid_argument("in IntToAlpha Function a non numerial value was used as parameter. Only values from 1 to 9 can be used as parmeters");}
	a += 48;
	return a;
}

std::string AddEqualLens(std::string lhs, std::string rhs){
	//check lengths 
	if(lhs.length() != rhs.length()){throw std::invalid_argument("AddEqualLens parameters are differnt lengths");}
	
	string result = "";
	unsigned int carryOver = 0;
	unsigned int holder;
	
	for (int i = lhs.length() - 1; i >= 0; i--){
		holder = AlphaToInt(lhs[i]) + AlphaToInt(rhs[i]) + carryOver;
		carryOver = holder/10;
		result = IntToAlpha(holder%10) + result;
	}
	
	if(carryOver == 1){result = '1' + result;}
	
	
	return result;
}

void AddLeadingZeros(std::string &lhs,std::string &rhs){
	while(lhs.length() != rhs.length()){
		if(lhs.length() < rhs.length()){ lhs = '0' + lhs;}
		if(rhs.length() < lhs.length()){ rhs = '0' + rhs;}
	}
}

std::string Add(std::string lhs, std::string rhs){
	string l = lhs;
	string r = rhs;
	while(l.length() != r.length()){
		if(l.length() < r.length()){ l = '0' + l;}
		if(r.length() < l.length()){ r = '0' + r;}
	}
	
	return AddEqualLens(l,r);
}




std::string MultiplyOneDigit(std::string Top, int a){
	string product = "";
	int carryOver = 0;
	
	for (int i = Top.length() - 1; i >= 0; i--){
		product = IntToAlpha( (a * AlphaToInt(Top[i]) + carryOver)%10 )+ product;
		carryOver = (a * AlphaToInt(Top[i]) + carryOver)/10;
	}
	if(carryOver > 0){ product = IntToAlpha(carryOver) + product;}
	
	return product;
}

std::string Multiply(std::string Top, std::string Bot){
	string product, sum = "0";
	string Zeros = "";
	
	for (int i = Bot.length() - 1; i >= 0; i--){
		product = MultiplyOneDigit(Top, AlphaToInt(Bot[i])) + Zeros;
		sum = Add(sum, product);
		Zeros += "0";
	}
	return sum;
}


std::string Subtract(std::string Top, std::string Bot){
	//Top must be greater than bottom
	
	//add zeros to bot to equal top
	string T = Top;
	string B = Bot;
	while(T.length() != B.length()){
		if(T.length() < B.length()){ T = '0' + T;}
		if(B.length() < T.length()){ B = '0' + B;}
	}
	
	string result;//will carry the retruned result
	int takeAway = 0;//represents the takeaway alu from the next digit in tradional subtraction
	
	for(int i = B.length() - 1; i >= 0; i--){
		if (AlphaToInt(B[i]) >  AlphaToInt(T[i]) - takeAway){
			result = IntToAlpha( AlphaToInt(T[i]) - takeAway + 10 - AlphaToInt(B[i]) ) + result;
			takeAway = 1;
		}
		else{
			result = IntToAlpha( AlphaToInt(T[i]) - takeAway - AlphaToInt(B[i]) ) + result;
			takeAway = 0;
		}
	}
	
	return result;
	
	
}




















