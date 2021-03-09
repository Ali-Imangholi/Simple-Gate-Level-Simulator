using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

string drop_1_(string );
string drop_2_(string );
char select(string , int );
string findIntegerInStirng(string );
string findIntegerInCahr(string );
vector<string> findToOneAndToZeroDelay(string );
vector <string> delay_to_1_to_0_;
main()
{	

vector <string> totalCleanWords(0);
vector <string> ImportantWords(0);
vector <string> final(0);
int index_1_=0;
string tempWord_1_;
string tempWord_2_;
string tempWord_3_;
string tempWord_4_;
string tempWord_5_;
string tempWord_6_;
string tempWord_7_;

ifstream svFile("svFile.txt");
if(!svFile)
{
	cout<<"failure!"<<endl;
}
/*--------------------------------------------------------------------------*/
while (svFile>>tempWord_1_)
{ 
	tempWord_2_ = drop_1_(tempWord_1_);
//	cout<<tempWord_1_<<" ";
	totalCleanWords.push_back(tempWord_2_);
//	cout<<totalCleanWords[index_1_]<<" ";
	index_1_= index_1_ + 1;
}
/*--------------------------------------------------------------------------*/
for(int index_2_=0 ; index_2_ < totalCleanWords.size() ;  index_2_ ++ )
{
	
	tempWord_3_ = totalCleanWords[index_2_];
	
	if(tempWord_3_ == "module")
	{ 
	ImportantWords.push_back(totalCleanWords[index_2_]);
	ImportantWords.push_back(totalCleanWords[index_2_ + 1]); 
	}
	else if(tempWord_3_ == "input")
	{ 
	ImportantWords.push_back(totalCleanWords[index_2_]);
	ImportantWords.push_back(totalCleanWords[index_2_ + 1]); 
	}
	else if(tempWord_3_ == "output")
	{ 
	ImportantWords.push_back(totalCleanWords[index_2_]);
	ImportantWords.push_back(totalCleanWords[index_2_ + 1]); 
	}
	else if(tempWord_3_ == "wire")
	{ 
	ImportantWords.push_back(totalCleanWords[index_2_]);
	ImportantWords.push_back(totalCleanWords[index_2_ + 1]); 
	}
	else if(tempWord_3_ == "and") //and
	{ 
	ImportantWords.push_back(totalCleanWords[index_2_]);
	
	tempWord_4_ = totalCleanWords[index_2_ + 1];
	delay_to_1_to_0_ = findToOneAndToZeroDelay(tempWord_4_);
	tempWord_5_ = delay_to_1_to_0_[0];
	tempWord_6_ = delay_to_1_to_0_[1];
	
	ImportantWords.push_back(tempWord_5_);
	ImportantWords.push_back(tempWord_6_);
		
	ImportantWords.push_back(totalCleanWords[index_2_ + 3]);
	ImportantWords.push_back(totalCleanWords[index_2_ + 4]);
	ImportantWords.push_back(totalCleanWords[index_2_ + 5]);  
	}
	else if(tempWord_3_ == "nand") //nand
	{ 

	ImportantWords.push_back(totalCleanWords[index_2_]);
	
	tempWord_4_ = totalCleanWords[index_2_ + 1];


	
	delay_to_1_to_0_ = findToOneAndToZeroDelay(tempWord_4_);
	tempWord_5_ = delay_to_1_to_0_[0];
	tempWord_6_ = delay_to_1_to_0_[1];



	ImportantWords.push_back(tempWord_5_);
	ImportantWords.push_back(tempWord_6_);
	ImportantWords.push_back(totalCleanWords[index_2_ + 3]);
	ImportantWords.push_back(totalCleanWords[index_2_ + 4]);
	ImportantWords.push_back(totalCleanWords[index_2_ + 5]);  

	}
	else if(tempWord_3_ == "or") //or
	{ 
	ImportantWords.push_back(totalCleanWords[index_2_]);
	
	tempWord_4_ = totalCleanWords[index_2_ + 1];
	delay_to_1_to_0_ = findToOneAndToZeroDelay(tempWord_4_);
	tempWord_5_ = delay_to_1_to_0_[0];
	tempWord_6_ = delay_to_1_to_0_[1];

	ImportantWords.push_back(tempWord_5_);
	ImportantWords.push_back(tempWord_6_);
	
	ImportantWords.push_back(totalCleanWords[index_2_ + 3]);

	ImportantWords.push_back(totalCleanWords[index_2_ + 4]);
	ImportantWords.push_back(totalCleanWords[index_2_ + 5]);  
	}
	else if(tempWord_3_ == "nor") //nor
	{ 
	ImportantWords.push_back(totalCleanWords[index_2_]);
	
	tempWord_4_ = totalCleanWords[index_2_ + 1];
	delay_to_1_to_0_ = findToOneAndToZeroDelay(tempWord_4_);
	tempWord_5_ = delay_to_1_to_0_[0];
	tempWord_6_ = delay_to_1_to_0_[1];

	ImportantWords.push_back(tempWord_5_);
	ImportantWords.push_back(tempWord_6_);
	
	ImportantWords.push_back(totalCleanWords[index_2_ + 3]);
	ImportantWords.push_back(totalCleanWords[index_2_ + 4]);
	ImportantWords.push_back(totalCleanWords[index_2_ + 5]);  
	}
	else if(tempWord_3_ == "xor") //xor
	{ 
	ImportantWords.push_back(totalCleanWords[index_2_]);

	tempWord_4_ = totalCleanWords[index_2_ + 1];
	delay_to_1_to_0_ = findToOneAndToZeroDelay(tempWord_4_);
	tempWord_5_ = delay_to_1_to_0_[0];
	tempWord_6_ = delay_to_1_to_0_[1];

	ImportantWords.push_back(tempWord_5_);
	ImportantWords.push_back(tempWord_6_);

	ImportantWords.push_back(totalCleanWords[index_2_ + 3]);
	ImportantWords.push_back(totalCleanWords[index_2_ + 4]);
	ImportantWords.push_back(totalCleanWords[index_2_ + 5]);  
	}
	


}
/*--------------------------------------------------------------------------*/


	for(int index_3_=0 ; index_3_ < ImportantWords.size() ;  index_3_ ++)
	{
		
		tempWord_7_ = drop_2_(ImportantWords[index_3_]);
		final.push_back(tempWord_7_);
	}



/*--------------------------------------------------------------------------*/	
	

	ofstream readableFile("readableFile.txt");									//write file
/*--------------------------------------------------------------------------*/

	for(int index_4_=0 ; index_4_ < ImportantWords.size() ;  index_4_ ++ )
	{
	if(final[index_4_] == "module")
	{ 
	readableFile<<"moduleName= "<<final[index_4_ + 1]<<endl;
	}
	else if(final[index_4_] == "input")
	{ 
	readableFile<<"input= "<<final[index_4_ + 1]<<endl; 
	}
	else if(final[index_4_] == "output")
	{ 
	readableFile<<"output= "<<final[index_4_ + 1]<<endl; 
	}
	else if(final[index_4_] == "wire")
	{ 
	readableFile<<"wire= "<<final[index_4_ + 1]<<endl; 
	}
	else if(final[index_4_] == "and") //and
	{ 	
	readableFile<<"and: "<<" delyToOne= "<<final[index_4_ + 1]<<" delayToZero= "<<final[index_4_ + 2]<<" terminal= "<<final[index_4_ + 3]<<" "<<final[index_4_ + 4]<<" "<<final[index_4_ + 5]<<endl; 
	}

	else if(final[index_4_] == "nand") //nand
	{ 	
	readableFile<<"nand: "<<" delyToOne= "<<final[index_4_ + 1]<<" delayToZero= "<<final[index_4_ + 2]<<" terminal= "<<final[index_4_ + 3]<<" "<<final[index_4_ + 4]<<" "<<final[index_4_ + 5]<<endl; 
	}
	else if(final[index_4_] == "or") //or
	{ 	
	readableFile<<"or: "<<" delyToOne= "<<final[index_4_ + 1]<<" delayToZero= "<<final[index_4_ + 2]<<" terminal= "<<final[index_4_ + 3]<<" "<<final[index_4_ + 4]<<" "<<final[index_4_ + 5]<<endl; 
	}
		else if(final[index_4_] == "nor") //nor
	{ 	
	readableFile<<"nor: "<<" delyToOne= "<<final[index_4_ + 1]<<" delayToZero= "<<final[index_4_ + 2]<<" terminal= "<<final[index_4_ + 3]<<" "<<final[index_4_ + 4]<<" "<<final[index_4_ + 5]<<endl; 
	}
	else if(final[index_4_] == "xor") //xor
	{ 	
	readableFile<<"xor: "<<" delyToOne= "<<findIntegerInStirng(final[index_4_ + 1])<<" delayToZero= "<<findIntegerInStirng(final[index_4_ + 2])<<" terminal= "<<final[index_4_ + 3]<<" "<<final[index_4_ + 4]<<" "<<final[index_4_ + 5]<<endl; 
	}
	
	}

	readableFile.close();

}


//////functions/////

string drop_1_(string word) // The function that drop this " ; ) (  " characters
{
	string outWord = "";
	for(int index=0 ; index<word.size() ; index++)
	{
		if(word[index] != ';' && word[index] != ')' && word[index] != '(' )
		{
			outWord = outWord + word[index];
		}
	}
	return outWord;
}


string drop_2_(string word) // The function that drop this " ; ) (  ," characters
{
	string outWord = "";
	for(int index=0 ; index<word.size() ; index++)
	{
		if(word[index] != ';' && word[index] != ')' && word[index] != '(' && word[index] != ',' )
		{
			outWord = outWord + word[index];
		}
	}
	return outWord;
}

char select(string word , int sel)
{
	return word[sel];
}




string findIntegerInStirng(string str)
{
	string flag = "false";
	int temp_1_;
	string temp_2_="";
	for(int index_1_= 0 ; index_1_ < str.size() ; index_1_ ++)
	{
		temp_1_ = str.find(index_1_);
		if(0<=temp_1_<=100)
		{
			flag = "true";
		}
	}
	if(flag == "true")
	{
		string outString="";
		string TempString="";
	
		for(int index_2_=0 ; index_2_ < str.size() ; index_2_ ++)
		{
		temp_2_ = str[index_2_];
		TempString = findIntegerInCahr(temp_2_);
		if(TempString == "false")
		{
			return "false";
		}
		outString = outString + TempString;

		}
		return outString;
	}
}


string findIntegerInCahr(string str)
{
	if(str == "0"){return "0";}
	if(str == "1"){return "1";}
	if(str == "2"){return "2";}
	if(str == "3"){return "3";}
	if(str == "4"){return "4";}
	if(str == "5"){return "5";}
	if(str == "6"){return "6";}
	if(str == "7"){return "7";}
	if(str == "8"){return "8";}
	if(str == "9"){return "9";}
	else return "false";
}

vector<string> findToOneAndToZeroDelay(string str)
{
	string temp;
	vector <string> output;
	string strForCompare = *(&str);

	for(int index=0 ; index < strForCompare.size() ; index ++)
	{


		if(strForCompare[index] == '#'){continue;}
		if(strForCompare[index] != ',' && strForCompare[index] != ' ')
		{
			temp = temp + strForCompare[index];

		}
		if(strForCompare[index] == ',' || strForCompare[index] == ' ' || index==strForCompare.size() -1)
		{

			output.push_back(temp);
			temp = "";
		}
	}

	return output;
}
