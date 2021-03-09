#include <string>
#include <vector>
#include <cmath>

using namespace std;

enum lv4{lX , l0 , l1 , lZ};

lv4 ANDlv4 (lv4   , lv4  , lv4  , int  , int  , int );	//AND
lv4 ORlv4  (lv4   , lv4  , lv4  , int  , int  , int );	//OR
lv4 NANDlv4(lv4   , lv4  , lv4  , int  , int  , int );	//NAND
lv4 NORlv4 (lv4   , lv4  , lv4  , int  , int  , int ); 	//NOR
lv4 XORlv4 (lv4   , lv4  , lv4  , int  , int  , int ); 	//XOR
int time(int  , int  , int  , lv4 ); //time
int string_to_integer(string ); //convert string to integer
int find(vector<string>  , string ); //find the string in vector
string drop_3_(string );  // The function that drop this ' # ' character
char select_2_(string , int );
lv4 string_to_lv4_(string );
lv4 initial();
int ConvertStringOfNumbersToInteger(string );


//functions

int current_time = 0;
lv4 flag_state = lX;




lv4 ANDlv4(lv4 a , lv4 b , lv4 flag_state_in_funcion , int current_time_in_function , int delay_to_one , int delay_to_zero)	//AND
{
	lv4 w;
	if (a==lX || b==lX || a==lZ || b==lZ) w==lX;
	else if (a == l1 && b==l1) w=l1;
	else w=l0;
	
	if(flag_state_in_funcion != w)		//for timing and update satate
	{
		flag_state = w;
		current_time = time(current_time_in_function , delay_to_one , delay_to_zero , w);
	}
	
	return w;
}

lv4 ORlv4(lv4 a , lv4 b , lv4 flag_state_in_funcion , int current_time_in_function , int delay_to_one , int delay_to_zero)	//OR
{
	lv4 w;
	if (a==lX || b==lX || a==lZ || b==lZ) w==lX;
	else if (a == l0 && b==l0) w=l0;
	else {w=l1;}
	
	if(flag_state_in_funcion != w)		//for timing and update satate
	{
		flag_state = w;
		current_time = time(current_time_in_function , delay_to_one , delay_to_zero , w);
		
	}
	
	return w;
}

lv4 NANDlv4(lv4 a , lv4 b , lv4 flag_state_in_funcion , int current_time_in_function , int delay_to_one , int delay_to_zero) //NAND
{
	lv4 w;
	if (a==lX || b==lX || a==lZ || b==lZ) w==lX;
	else if (a == l1 && b==l1) w=l0;
	else {w=l1;}
	
	if(flag_state_in_funcion != w)		//for timing and update satate
	{
		flag_state = w;
		current_time = time(current_time_in_function , delay_to_one , delay_to_zero , w);
		
	}
	
	return w;
}

lv4 NORlv4(lv4 a , lv4 b , lv4 flag_state_in_funcion , int current_time_in_function , int delay_to_one , int delay_to_zero) //NOR
{
	lv4 w;
	if (a==lX || b==lX || a==lZ || b==lZ) w==lX;
	else if (a == l0 && b==l0) w=l1;
	else {w=l0;}

	if(flag_state != w)		//for timing and update satate
	{
		flag_state = w;
		current_time = time(current_time_in_function , delay_to_one , delay_to_zero , w);
		
	}

	return w;
}

lv4 XORlv4(lv4 a , lv4 b , lv4 flag_state_in_funcion , int current_time_in_function , int delay_to_one , int delay_to_zero) //XOR
{
	lv4 w;
	if (a==lX || b==lX || a==lZ || b==lZ) w==lX;
	else if (a == l1 && b==l0) w=l1;
	else if (a == l0 && b==l1) w=l1;
	else {w=l0;}
	
	if(flag_state_in_funcion != w)		//for timing and update satate
	{
		flag_state = w;
		current_time = time(current_time_in_function , delay_to_one , delay_to_zero , w);
		
	}	
	
	return w;
}

int time(int current_time , int delay_to_one , int delay_to_zero , lv4 flag_one_or_zero) //time
{
	int next_time;
	if(flag_one_or_zero == l1) next_time = current_time + delay_to_one;
	else if(flag_one_or_zero == l0) next_time = current_time + delay_to_zero;
	else next_time = current_time;
	return next_time;
}

int string_to_integer(string str)
{
	if(str == "0")return 0;
	else if(str == "1")return 1;
	else if(str == "2")return 2;
	else if(str == "3")return 3;
	else if(str == "4")return 4;
	else if(str == "5")return 5;
	else if(str == "6")return 6;
	else if(str == "7")return 7;
	else if(str == "8")return 8;
	else if(str == "9")return 9;
}





lv4 string_to_lv4_(string str)
{
	if(str == "0")return l0;
	else if(str == "1")return l1;
	else if(str == "Z" || str == "z")return lZ;
	else if(str == "X" || str == "x")return lX;
}

int find(vector<string> vect , string str)
{
int flag=0;
int findingIndex;
for(int index=0 ; index < vect.size() ; index++)
	{

		if(str == vect[index])
		{
		flag=1;
		findingIndex=index;
		}
	}
	if (flag==1) return findingIndex;
	else if(flag == 0) return -1;
}


string drop_3_(string word) // The function that drop this ' # ' character
{
	string outWord = "";
	for(int index=0 ; index<word.size() ; index++)
	{
		if(word[index] != '#' )
		{
			outWord = outWord + word[index];
		}
	}
	return outWord;
}

char select_2_(string word , int sel)
{
	return word[sel];
}



lv4 initial()
{
	return lX;
}




int ConvertStringOfNumbersToInteger(string str)
{
	string tempString = *(&str);
	int tempInt;
	int output=0;
	int index;
	string tempString_2_;

	for(index=0 ; index < tempString.size() ; index ++)
	{
		
		tempString_2_ = tempString[index];
		tempInt = string_to_integer(tempString_2_);
		output = output + tempInt * pow(10 , tempString.size() - index -1);;
	}
	return output;
}

























