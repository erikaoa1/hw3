## HW 3

 - Name: Erika Abumere
 - Email: abumere@usc.edu

Make sure you are in the hw3 directory (cd hw3) before attempting to compile/run these programs.

 How to compile llrec-test:   make llrec-test

How to run: ./llrec-test (input files for linked list) 
- for example: ./llrec-test llrec-test1.in

Note regarding llpivot(): 
For the llpivot function, the instructions say to handle the case where the input linked list is empty. 
Initially, I was going to cout an error message if the input linked list was empty, 
however I wasn't sure if printing an error message would disturb the automatic tests that the graders use,
so i removed iostream and commented out the error message. It now simply returns nothing if the input linked list is empty. 



How to compile and run logicsim:

Make sure you are in the logicsim directory (cd logicsim)

Compile: make
Run: ./logicsim (input text file)
- for example: ./logicsim single_and.text

How to turn it into a timing diagram:
./logicsim > (name of uml).uml
java -jar plantuml.jar (name of uml).uml

For example: 
./logicsim > my_and.uml
java -jar plantuml.jar my_and.uml