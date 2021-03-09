using namespace std;
#include <fstream>
#include <iostream>

#include "functions.h"

	const lv4 lv4Value [4] = {lX , l1 , l1 , lZ};			//logic varible
	const string lv4Image [4] = {"lX" , "l0" , "l1" , "lZ"};
main()
{
	
	/*		varibles		*/
vector <string> allInfo(0);
vector <string> moduleInfo(0);
vector <string> moduleInput(0);
vector <string> moduleOutput(0);
vector <string> moduleWire(0);
vector <string> moduleGate(0);
vector <string> totalData(0);
vector <string> data_lv4_(0);
vector <string> delay(0);
string tempWord_1_;
string tempWord_2_;
int index_input = 0;
int index_output = 0;
int index_wire = 0;
int index_gate = 0;

lv4 output;
int output_index;
string output_vector_name;
lv4 input_1_;
lv4 input_2_;
int dely_to_1;
int delay_to_0;

	
/*read the data file*/

ifstream dataFile("data.txt");
if(!dataFile)
{
	cout<<"failure data.txt!"<<endl;
}
/*push the data of file(inputs and delys) in vector */
while (dataFile>>tempWord_1_)
{
	tempWord_1_ = drop_3_(tempWord_1_);
	totalData.push_back(tempWord_1_);
}
//delay
for(int index=0 ; index < totalData.size() ; index ++)
{
	if(index%2==0)
	{
		delay.push_back(totalData[index]);
	}
	else
	{
		data_lv4_.push_back(totalData[index]);
	}
}

/*push the data of file	(the algirthem that programme must perform ) in vector */
ifstream svFile("readableFile.txt");
if(!svFile)
{
	cout<<"failure readableFile.txt!"<<endl;
}

while (svFile>>tempWord_2_)
{ 
	allInfo.push_back(tempWord_2_);
}

/* seprate the data in to input,output,wire,gate,delay_to_1,delay_to_zero */
for(int index_1_=0 ; index_1_ < allInfo.size() ; index_1_ ++)
{
	if(allInfo[index_1_] == "moduleName=")
	{
		moduleInfo.push_back(allInfo[index_1_ + 1]);
	}
	else if(allInfo[index_1_]  == "input=")
	{
		moduleInput.push_back(allInfo[index_1_ + 1]);
		index_input = index_input + 1;
	}
	else if(allInfo[index_1_]  == "output=")
	{
		moduleOutput.push_back(allInfo[index_1_ + 1]);
		index_output = index_output + 1;
	}
	else if(allInfo[index_1_]  == "wire=")
	{
		moduleWire.push_back(allInfo[index_1_ + 1]);
		index_wire = index_wire + 1;
	}
	else if(allInfo[index_1_]  == "and:") //and
	{
		moduleGate.push_back(allInfo[index_1_]);
		moduleGate.push_back(allInfo[index_1_ + 2]);
		moduleGate.push_back(allInfo[index_1_ + 4]);
		moduleGate.push_back(allInfo[index_1_ + 6]);
		moduleGate.push_back(allInfo[index_1_ + 7]);
		moduleGate.push_back(allInfo[index_1_ + 8]);
		index_gate = index_gate + 1;
	}
	else if(allInfo[index_1_]  == "nand:") //nand
	{
		moduleGate.push_back(allInfo[index_1_]);
		moduleGate.push_back(allInfo[index_1_ + 2]);
		moduleGate.push_back(allInfo[index_1_ + 4]);
		moduleGate.push_back(allInfo[index_1_ + 6]);
		moduleGate.push_back(allInfo[index_1_ + 7]);
		moduleGate.push_back(allInfo[index_1_ + 8]);
		index_gate = index_gate + 1;
	}
	else if(allInfo[index_1_]  == "or:") //or
	{
		moduleGate.push_back(allInfo[index_1_]);
		moduleGate.push_back(allInfo[index_1_ + 2]);
		moduleGate.push_back(allInfo[index_1_ + 4]);
		moduleGate.push_back(allInfo[index_1_ + 6]);
		moduleGate.push_back(allInfo[index_1_ + 7]);
		moduleGate.push_back(allInfo[index_1_ + 8]);
		index_gate = index_gate + 1;
	}
	else if(allInfo[index_1_]  == "nor:") //nor
	{
		moduleGate.push_back(allInfo[index_1_]);
		moduleGate.push_back(allInfo[index_1_ + 2]);
		moduleGate.push_back(allInfo[index_1_ + 4]);
		moduleGate.push_back(allInfo[index_1_ + 6]);
		moduleGate.push_back(allInfo[index_1_ + 7]);
		moduleGate.push_back(allInfo[index_1_ + 8]);
		index_gate = index_gate + 1;
	}
	else if(allInfo[index_1_]  == "xor:") //xor
	{
		moduleGate.push_back(allInfo[index_1_]);
		moduleGate.push_back(allInfo[index_1_ + 2]);
		moduleGate.push_back(allInfo[index_1_ + 4]);
		moduleGate.push_back(allInfo[index_1_ + 6]);
		moduleGate.push_back(allInfo[index_1_ + 7]);
		moduleGate.push_back(allInfo[index_1_ + 8]);
		index_gate = index_gate + 1;
	}
}


lv4 module_Input[index_input][data_lv4_.size()]; //store value of moduleInput vector //
lv4 module_Output[index_output][data_lv4_.size()]; //store value of moduleOutput vector //
lv4 module_Wire[index_wire]; //store value of moduleWire vector //
lv4 lastStateGate[moduleGate.size()];


//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ initializing ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//

for(int index_1_ = 0 ; index_1_ < index_input ; index_1_ ++)
{
	for(int index_2_ = 0 ; index_2_ < data_lv4_.size() ; index_2_ ++)
	{
		module_Input[index_1_][index_2_] = initial();
	}
}

for(int index_3_ = 0 ; index_3_ < index_input ; index_3_ ++)
{
	for(int index_4_ = 0 ; index_4_ < data_lv4_.size() ; index_4_ ++)
	{
		module_Output[index_3_][index_4_] = initial();
	}
}


for(int index_6_ = 0 ; index_6_ < data_lv4_.size() ; index_6_ ++)
{
	module_Wire[index_6_] = initial();
}



for(int index_7_ = 0 ; index_7_ < data_lv4_.size() ; index_7_ ++)
{
	lastStateGate[index_7_] = initial();
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^END of initializing ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//


int dalyArray[delay.size()];
string Temp_1_ = " ";
int intTemp_1_ = 0;
int intTemp_2_ = 0;

/*	save the dealy of the opration in array(dalyArray)	*/
for(int index__1__=0 ; index__1__ < delay.size() ; index__1__ ++)
{ int power = delay[index__1__].size();
	for(int index__2___= 0 ; index__2___ < delay[index__1__].size() ; index__2___ ++)
	{
		Temp_1_ = select_2_(delay[index__1__] , index__2___);
		
		intTemp_1_ = string_to_integer(Temp_1_);

		intTemp_2_ = (intTemp_1_ * (pow(10 , power - 1))) + intTemp_2_;
		power = power -1 ;
	}
	dalyArray[index__1__] = intTemp_2_;
	intTemp_2_ = 0;	
}

/*		fill data_lv4_ to array(module_Input)		 */
string Temp_2_;
for(int index__ =0; index__ < data_lv4_.size() ; index__ ++)
{
	for(int index___=0 ; index___ < data_lv4_[index__].size() ; index___ ++)
	{
		Temp_2_ = select_2_(data_lv4_[index__] , index___);

		module_Input[index__][index___] = string_to_lv4_(Temp_2_);
		
	}
}


/*make a file for show output */
ofstream outputFile("outputFile.txt");


/****************************************************MAIN PROCESS************************************************************************/

	outputFile<<"current_time: "<<"0"<<endl<<"***********************************************************************"<<endl<<"***********************************************************************"<<endl;


for(int index___=0 ; index___ < data_lv4_.size() ; index___ ++)// this loop is for handel sevral inputs
{
	
	
	current_time = current_time + dalyArray[index___];
	
	
	
 for(int index_2_=0 ; index_2_ < (index_gate * 6 ) ; index_2_ = index_2_ + 6)
 {



/*############################  AND ############################*/
	if(moduleGate[index_2_] == "and:")
	{
		/*-----------------store location that output must be save-----------------*/
		if(find(moduleInput , moduleGate[index_2_ + 3]) != -1)
		{
			output_index = find(moduleInput , moduleGate[index_2_ + 3]);
			output_vector_name = "moduleInput";
		}
		else if(find(moduleOutput , moduleGate[index_2_ + 3]) != -1)
		{
			output_index = find(moduleOutput , moduleGate[index_2_ + 3]);
			output_vector_name = "moduleOutput";
		}
		else if(find(moduleWire , moduleGate[index_2_ + 3]) != -1)
		{
			output_index = find(moduleWire , moduleGate[index_2_ + 3]);
			output_vector_name = "moduleWire";
		}
/*-----------------end-----------------*/

/*-----------------set input one-----------------*/

		if(find(moduleInput , moduleGate[index_2_ + 4]) != -1)
		{
			input_1_ = module_Input[index___][find(moduleInput , moduleGate[index_2_ + 4])];
		}
		else if(find(moduleOutput , moduleGate[index_2_ + 4]) != -1)
		{
			input_1_ = module_Output[index___][find(moduleOutput , moduleGate[index_2_ + 4])];
		}
		else if(find(moduleWire , moduleGate[index_2_ + 4]) != -1)
		{
			input_1_ = module_Wire[find(moduleWire , moduleGate[index_2_ + 4])];
		}
/*-----------------end-----------------*/

/*-----------------set input two-----------------*/

		if(find(moduleInput , moduleGate[index_2_ + 5]) != -1)
		{
			input_2_ = module_Input[index___][find(moduleInput , moduleGate[index_2_ + 5])];
		}
		else if(find(moduleOutput , moduleGate[index_2_ + 5]) != -1)
		{
			input_2_ = module_Output[index___][find(moduleOutput , moduleGate[index_2_ + 5])];
		}
		else if(find(moduleWire , moduleGate[index_2_ + 5]) != -1)
		{
			input_2_ = module_Wire[find(moduleWire , moduleGate[index_2_ + 5])];
		}
/*-----------------end-----------------*/
	
		dely_to_1 = ConvertStringOfNumbersToInteger(moduleGate[index_2_ + 1]);
		delay_to_0 = ConvertStringOfNumbersToInteger(moduleGate[index_2_ + 2]);
		
		/* main opration */
		output = ANDlv4(input_1_ , input_2_ , lastStateGate[index_2_] , current_time , dely_to_1 , delay_to_0);
		lastStateGate[index_2_] = output;
		/*---------------*/

	if(output_vector_name == "moduleInput"){module_Input[index___][output_index] = output;}
	else if(output_vector_name == "moduleOutput"){module_Output[index___][output_index] = output;}
	else if(output_vector_name == "moduleWire"){module_Wire[output_index] = output;}
	
	//write output on file
	outputFile<<"current_time: "<<current_time<<"    "<<moduleGate[index_2_]<<"    input1: "<<lv4Image[input_1_]<<"    input2: "<<lv4Image[input_2_]<<"    output: "<<lv4Image[output]<<endl;
	}
/*############################ END OF AND ############################*/

/*############################  NAND ############################*/

	if(moduleGate[index_2_] == "nand:")
	{
		/*-----------------store location that output must be save-----------------*/
		if(find(moduleInput , moduleGate[index_2_ + 3]) != -1)
		{
			output_index = find(moduleInput , moduleGate[index_2_ + 3]);
			output_vector_name = "moduleInput";
			
		}
		if(find(moduleOutput , moduleGate[index_2_ + 3]) != -1)
		{
			output_index = find(moduleOutput , moduleGate[index_2_ + 3]);
			output_vector_name = "moduleOutput";
			
		}
		if(find(moduleWire , moduleGate[index_2_ + 3]) != -1)
		{
			output_index = find(moduleWire , moduleGate[index_2_ + 3]);
			output_vector_name = "moduleWire";
			
		}
		
/*-----------------end-----------------*/

/*-----------------set input one-----------------*/

		if(find(moduleInput , moduleGate[(index_2_ + 4)]) != -1)
		{

			input_1_ = module_Input[index___][find(moduleInput , moduleGate[index_2_ + 4])];
		
		}
		if(find(moduleOutput , moduleGate[index_2_ + 4]) != -1)
		{
			input_1_ = module_Output[index___][find(moduleOutput , moduleGate[index_2_ + 4])];
			
		}
		if(find(moduleWire , moduleGate[index_2_ + 4]) != -1)
		{
			input_1_ = module_Wire[find(moduleWire , moduleGate[index_2_ + 4])];	
			
		}
/*-----------------end-----------------*/

/*-----------------set input two-----------------*/

		if(find(moduleInput , moduleGate[index_2_ + 5]) != -1)
		{
			input_2_ = module_Input[index___][find(moduleInput , moduleGate[index_2_ + 5])];
			
		}

		if(find(moduleOutput , moduleGate[index_2_ + 5]) != -1)
		{
			input_2_ = module_Output[index___][find(moduleOutput , moduleGate[index_2_ + 5])];
			
		}
		if(find(moduleWire , moduleGate[index_2_ + 5]) != -1)
		{
			input_2_ = module_Wire[find(moduleWire , moduleGate[index_2_ + 5])];
			
		}
/*-----------------end-----------------*/
	
		dely_to_1 = ConvertStringOfNumbersToInteger(moduleGate[index_2_ + 1]);
		delay_to_0 = ConvertStringOfNumbersToInteger(moduleGate[index_2_ + 2]);
		
		/* main opration */
		output = NANDlv4(input_1_ , input_2_ , lastStateGate[index_2_] , current_time , dely_to_1 , delay_to_0);
		lastStateGate[index_2_] = output;
		/*---------------*/

	if(output_vector_name == "moduleInput"){module_Input[index___][output_index] = output;}
	if(output_vector_name == "moduleOutput"){module_Output[index___][output_index] = output;}
	if(output_vector_name == "moduleWire"){module_Wire[output_index] = output;}
	

	
//write output on file
	outputFile<<"current_time: "<<current_time<<"    "<<moduleGate[index_2_]<<"    input1: "<<lv4Image[input_1_]<<"    input2: "<<lv4Image[input_2_]<<"    output: "<<lv4Image[output]<<endl;
	}
/*############################ END OF NAND ############################*/

/*############################  OR ############################*/
	if(moduleGate[index_2_] == "or:")
	{
		/*-----------------store location that output must be save-----------------*/
		if(find(moduleInput , moduleGate[index_2_ + 3]) != -1)
		{
			output_index = find(moduleInput , moduleGate[index_2_ + 3]);
			output_vector_name = "moduleInput";
		}
		else if(find(moduleOutput , moduleGate[index_2_ + 3]) != -1)
		{
			output_index = find(moduleOutput , moduleGate[index_2_ + 3]);
			output_vector_name = "moduleOutput";
		}
		else if(find(moduleWire , moduleGate[index_2_ + 3]) != -1)
		{
			output_index = find(moduleWire , moduleGate[index_2_ + 3]);
			output_vector_name = "moduleWire";
		}
/*-----------------end-----------------*/

/*-----------------set input one-----------------*/

		if(find(moduleInput , moduleGate[index_2_ + 4]) != -1)
		{
			input_1_ = module_Input[index___][find(moduleInput , moduleGate[index_2_ + 4])];
		}
		else if(find(moduleOutput , moduleGate[index_2_ + 4]) != -1)
		{
			input_1_ = module_Output[index___][find(moduleOutput , moduleGate[index_2_ + 4])];
		}
		else if(find(moduleWire , moduleGate[index_2_ + 4]) != -1)
		{
			input_1_ = module_Wire[find(moduleWire , moduleGate[index_2_ + 4])];
		}
/*-----------------end-----------------*/

/*-----------------set input two-----------------*/

		if(find(moduleInput , moduleGate[index_2_ + 5]) != -1)
		{
			input_2_ = module_Input[index___][find(moduleInput , moduleGate[index_2_ + 5])];
		}
		else if(find(moduleOutput , moduleGate[index_2_ + 5]) != -1)
		{
			input_2_ = module_Output[index___][find(moduleOutput , moduleGate[index_2_ + 5])];
		}
		else if(find(moduleWire , moduleGate[index_2_ + 5]) != -1)
		{
			input_2_ = module_Wire[find(moduleWire , moduleGate[index_2_ + 5])];
		}
/*-----------------end-----------------*/
	
		dely_to_1 = string_to_integer(moduleGate[index_2_ + 1]);
		delay_to_0 = string_to_integer(moduleGate[index_2_ + 2]);
		
		/* main opration */
		output = ORlv4(input_1_ , input_2_ , flag_state , current_time , dely_to_1 , delay_to_0);
		/*---------------*/

	if(output_vector_name == "moduleInput"){module_Input[index___][output_index] = output;}
	else if(output_vector_name == "moduleOutput"){module_Output[index___][output_index] = output;}
	else if(output_vector_name == "moduleWire"){module_Wire[output_index] = output;}

//write output on file
	outputFile<<"current_time: "<<current_time<<"    "<<moduleGate[index_2_]<<"    input1: "<<lv4Image[input_1_]<<"    input2: "<<lv4Image[input_2_]<<"    output: "<<lv4Image[output]<<endl;
	}

/*############################ END OF OR ############################*/

/*############################  NOR ############################*/
	if(moduleGate[index_2_] == "nor:")
	{
		/*-----------------store location that output must be save-----------------*/
		if(find(moduleInput , moduleGate[index_2_ + 3]) != -1)
		{
			output_index = find(moduleInput , moduleGate[index_2_ + 3]);
			output_vector_name = "moduleInput";
		}
		else if(find(moduleOutput , moduleGate[index_2_ + 3]) != -1)
		{
			output_index = find(moduleOutput , moduleGate[index_2_ + 3]);
			output_vector_name = "moduleOutput";
		}
		else if(find(moduleWire , moduleGate[index_2_ + 3]) != -1)
		{
			output_index = find(moduleWire , moduleGate[index_2_ + 3]);
			output_vector_name = "moduleWire";
		}
/*-----------------end-----------------*/

/*-----------------set input one-----------------*/

		if(find(moduleInput , moduleGate[index_2_ + 4]) != -1)
		{
			input_1_ = module_Input[index___][find(moduleInput , moduleGate[index_2_ + 4])];
		}
		else if(find(moduleOutput , moduleGate[index_2_ + 4]) != -1)
		{
			input_1_ = module_Output[index___][find(moduleOutput , moduleGate[index_2_ + 4])];
		}
		else if(find(moduleWire , moduleGate[index_2_ + 4]) != -1)
		{
			input_1_ = module_Wire[find(moduleWire , moduleGate[index_2_ + 4])];
		}
/*-----------------end-----------------*/

/*-----------------set input two-----------------*/

		if(find(moduleInput , moduleGate[index_2_ + 5]) != -1)
		{
			input_2_ = module_Input[index___][find(moduleInput , moduleGate[index_2_ + 5])];
		}
		else if(find(moduleOutput , moduleGate[index_2_ + 5]) != -1)
		{
			input_2_ = module_Output[index___][find(moduleOutput , moduleGate[index_2_ + 5])];
		}
		else if(find(moduleWire , moduleGate[index_2_ + 5]) != -1)
		{
			input_2_ = module_Wire[find(moduleWire , moduleGate[index_2_ + 5])];
		}
/*-----------------end-----------------*/
	
		dely_to_1 = ConvertStringOfNumbersToInteger(moduleGate[index_2_ + 1]);
		delay_to_0 = ConvertStringOfNumbersToInteger(moduleGate[index_2_ + 2]);
		
		/* main opration */
		output = NORlv4(input_1_ , input_2_ , lastStateGate[index_2_] , current_time , dely_to_1 , delay_to_0);
		lastStateGate[index_2_] = output;
		/*---------------*/

	if(output_vector_name == "moduleInput"){module_Input[index___][output_index] = output;}
	else if(output_vector_name == "moduleOutput"){module_Output[index___][output_index] = output;}
	else if(output_vector_name == "moduleWire"){module_Wire[output_index] = output;}

//write output on file
	outputFile<<"current_time: "<<current_time<<"    "<<moduleGate[index_2_]<<"    input1: "<<lv4Image[input_1_]<<"    input2: "<<lv4Image[input_2_]<<"    output: "<<lv4Image[output]<<endl;
	}

/*############################ END OF NOR ############################*/


/*############################  XOR ############################*/
	if(moduleGate[index_2_] == "xor:")
	{
		/*-----------------store location that output must be save-----------------*/
		if(find(moduleInput , moduleGate[index_2_ + 3]) != -1)
		{
			output_index = find(moduleInput , moduleGate[index_2_ + 3]);
			output_vector_name = "moduleInput";
		}
		else if(find(moduleOutput , moduleGate[index_2_ + 3]) != -1)
		{
			output_index = find(moduleOutput , moduleGate[index_2_ + 3]);
			output_vector_name = "moduleOutput";
		}
		else if(find(moduleWire , moduleGate[index_2_ + 3]) != -1)
		{
			output_index = find(moduleWire , moduleGate[index_2_ + 3]);
			output_vector_name = "moduleWire";
		}
/*-----------------end-----------------*/

/*-----------------set input one-----------------*/

		if(find(moduleInput , moduleGate[index_2_ + 4]) != -1)
		{
			input_1_ = module_Input[index___][find(moduleInput , moduleGate[index_2_ + 4])];
		}
		else if(find(moduleOutput , moduleGate[index_2_ + 4]) != -1)
		{
			input_1_ = module_Output[index___][find(moduleOutput , moduleGate[index_2_ + 4])];
		}
		else if(find(moduleWire , moduleGate[index_2_ + 4]) != -1)
		{
			input_1_ = module_Wire[find(moduleWire , moduleGate[index_2_ + 4])];
		}
/*-----------------end-----------------*/

/*-----------------set input two-----------------*/

		if(find(moduleInput , moduleGate[index_2_ + 5]) != -1)
		{
			input_2_ = module_Input[index___][find(moduleInput , moduleGate[index_2_ + 5])];
		}
		else if(find(moduleOutput , moduleGate[index_2_ + 5]) != -1)
		{
			input_2_ = module_Output[index___][find(moduleOutput , moduleGate[index_2_ + 5])];
		}
		else if(find(moduleWire , moduleGate[index_2_ + 5]) != -1)
		{
			input_2_ = module_Wire[find(moduleWire , moduleGate[index_2_ + 5])];
		}
/*-----------------end-----------------*/
	
		dely_to_1 = ConvertStringOfNumbersToInteger(moduleGate[index_2_ + 1]);
		delay_to_0 = ConvertStringOfNumbersToInteger(moduleGate[index_2_ + 2]);
		
		/* main opration */
		output = XORlv4(input_1_ , input_2_ , lastStateGate[index_2_] , current_time , dely_to_1 , delay_to_0);
		lastStateGate[index_2_] = output;	
		/*---------------*/

	if(output_vector_name == "moduleInput"){module_Input[index___][output_index] = output;}
	else if(output_vector_name == "moduleOutput"){module_Output[index___][output_index] = output;}
	else if(output_vector_name == "moduleWire"){module_Wire[output_index] = output;}
//write output on file
	outputFile<<"current_time: "<<current_time<<"    "<<moduleGate[index_2_]<<"    input1: "<<lv4Image[input_1_]<<"    input2: "<<lv4Image[input_2_]<<"    output: "<<lv4Image[output]<<endl;
	}

/*############################ END OF XOR ############################*/

		outputFile<<"outputs resault: "<<lv4Image[module_Output[index___][output_index]]<<endl;
//		outputFile<<moduleOutput[index_2_]<<"    "<<module_Output[index___][output_index]<<endl;

}

outputFile<<"***********************************************************************"<<endl;
}


/****************************************************************************************************************************************/


outputFile.close();
svFile.close();
dataFile.close();
	}

