# gate-level-simulate-in-cpp
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
          
                                                               ******************
                                        
Example for more detailes:

first I provide a system verilog code that show below adn save it in *.txt:
-----------------------------------
| module mux (a, b, s, y);        |
| input a;                        |
| input b;                        |
| input s;                        |
| output y;                       |
| wire sbar;                      |
| wire aa;                        |
| wire bb;                        |
| nand #(3,5) U1 (sbar, s, s);    |
| nand #(3,5) U2 (aa, a, sbar);   |
| nand #(3,5) U3 (bb, b, s);      |
| nand #(3,5) U4 (y, aa, bb);     |
| endmodule                       | 
----------------------------------- .txt

second I provide a delays and inputs values:
-----------
| 0 100   |
| 21 001  |
| 31 101  |
| 19 010  |
----------- data.txt


then I run readFile.exe (the resault showen below):
--------------------------------------------------------------
| moduleName= mux                                             |
| input= a                                                    |
| input= b                                                    |
| input= s                                                    |
| output= y                                                   |
| wire= sbar                                                  |
| wire= aa                                                    |
| wire= bb                                                    |
| nand:  delyToOne= 3 delayToZero= 5 terminal= sbar s s       |
| nand:  delyToOne= 3 delayToZero= 5 terminal= aa a sbar      |
| nand:  delyToOne= 3 delayToZero= 5 terminal= bb b s         |
| nand:  delyToOne= 3 delayToZero= 5 terminal= y aa bb        |                           
---------------------------------------------------------------readableFile.txt

After that I run stimuli.exe , I can see the output.


current_time: 0
***********************************************************************
***********************************************************************
current_time: 3    nand:    input1: l0    input2: l0    output: l1
outputs resault: lX
current_time: 8    nand:    input1: l1    input2: l1    output: l0
outputs resault: lX
current_time: 11    nand:    input1: l0    input2: l0    output: l1
outputs resault: lX
current_time: 14    nand:    input1: l0    input2: l1    output: l1
outputs resault: l1
***********************************************************************
current_time: 40    nand:    input1: l1    input2: l1    output: l0
outputs resault: lX
current_time: 43    nand:    input1: l0    input2: l0    output: l1
outputs resault: lX
current_time: 43    nand:    input1: l0    input2: l1    output: l1
outputs resault: lX
current_time: 48    nand:    input1: l1    input2: l1    output: l0
outputs resault: l0
***********************************************************************
current_time: 79    nand:    input1: l1    input2: l1    output: l0
outputs resault: l1
current_time: 79    nand:    input1: l1    input2: l0    output: l1
outputs resault: l0
current_time: 79    nand:    input1: l0    input2: l1    output: l1
outputs resault: l0
current_time: 79    nand:    input1: l1    input2: l1    output: l0
outputs resault: l0
***********************************************************************
current_time: 101    nand:    input1: l0    input2: l0    output: l1
outputs resault: l0
current_time: 101    nand:    input1: l0    input2: l1    output: l1
outputs resault: l0
current_time: 101    nand:    input1: l1    input2: l0    output: l1
outputs resault: l1
current_time: 101    nand:    input1: l1    input2: l1    output: l0
outputs resault: l0
***********************************************************************
 
