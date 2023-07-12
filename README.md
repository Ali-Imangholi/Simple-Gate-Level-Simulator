# Simple Gate-Level Simulator
gate level simulation in c++ ,  give system verilog code (.SV) and simulate it in c++

For run programe corectly:
1)In first you must provide system verilog code and save it in *.txt foramt.
2)Second you must provide the timing(delays) an inputs values and save it in *.txt foramt(name it data.txt)
3)After that you must run readfile.exe programe , this make a readableFile.txt file thats have important parts of your system verilog programe.
4)In this level you must run stimuli.exe , after that you can sea output of your gate-level logic in output.txt.

Notice:
1) In this simulation we have 4 logic value: 1 , 0 , Z , X (in the code and resault file this 4 logic value show by l0 , l1 , lX , LZ).
2) You must observe the syntax below for delay in system verilog file.
          #(delay_to_1,delay_to_0).
          
**************************************************************************************************************************************************	

![1](https://user-images.githubusercontent.com/80327162/110479173-5fa8a800-80fa-11eb-9e7e-c7699eede5e8.PNG)


![2](https://user-images.githubusercontent.com/80327162/110479191-633c2f00-80fa-11eb-84ea-74220054f87e.PNG)


![3](https://user-images.githubusercontent.com/80327162/110479230-69caa680-80fa-11eb-8fa9-93cf039b411f.PNG)
