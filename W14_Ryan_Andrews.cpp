/*
asdasd

Ryan Andrews
CSCI 140 A001 Winter 2024
Professor Sammy Abaza
Week 14
Date Completed 2024 04 03
Note: My code was ran on Visual Studio Code in C++.
*/

/*
In this week you will create two more menu items:
 - saving to stack 
 - popping the stack. 

Use C++ templates to create push and pop methods
 */


#include <iostream>
#include <string>
#include <vector>
#include <fstream>




//This Allows me to not type std:: before every line
using namespace std;




/*Class Creations*/
class RAcalc {
    public:
        //First Number selection Function
        double fNum (void) {
            
            /*Variable Creation*/
            string fNumberStr = " "; 
            double fNumber = 0;
            bool numCheck = false;
            
            /*Do While Loop in case number wasnt valid*/
            do {
                
                /*variable Reset*/
                numCheck = false;

                /*Prompt User for First Number and save it as a variable*/
                cout << "First Number  : ";
                getline (cin, fNumberStr);
                
                /*Verify user input is a valid number*/
                for (int i = 0; fNumberStr[i]; i++) {
                    if (fNumberStr[i] != '0' && fNumberStr[i] != '1' && fNumberStr[i] != '2' && fNumberStr[i] != '3' && \
                        fNumberStr[i] != '4' && fNumberStr[i] != '5' && fNumberStr[i] != '6' && fNumberStr[i] != '7' && \
                        fNumberStr[i] != '8' && fNumberStr[i] != '9' && fNumberStr[i] != '.' && fNumberStr[i] != '\0') {
                        numCheck = true;
                    } 
                }

                if (numCheck == true) {
                    cout << "\nPlease only type a number 0-9 or a '.' \n";
                    numCheck = true;
                }

            } while (numCheck == true);

            /*Convert String to Float*/
            fNumber = stod(fNumberStr);

            return fNumber;
        }


        //Second Number selection Function
        double sNum (void) {

            /*Variable Creation*/
            string sNumberStr = " "; 
            double sNumber = 0;
            bool numCheck = false;
            
            /*Do While Loop in case number wasnt valid*/
            do {

                /*Variable Reset*/
                numCheck = false;

                /*Prompt User for First Number and save it as a variable*/
                cout << "Second Number  : ";
                getline (cin, sNumberStr);
                
                /*Verify user input is a valid number*/
                for (int i = 0; sNumberStr[i]; i++) {
                    if (sNumberStr[i] != '0' && sNumberStr[i] != '1' && sNumberStr[i] != '2' && sNumberStr[i] != '3' && \
                        sNumberStr[i] != '4' && sNumberStr[i] != '5' && sNumberStr[i] != '6' && sNumberStr[i] != '7' && \
                        sNumberStr[i] != '8' && sNumberStr[i] != '9' && sNumberStr[i] != '.') {
                        numCheck = true;
                    } 
                }

                if (numCheck == true) {
                    cout << "\nPlease only type a number 0-9 or a '.' \n";
                    numCheck = true;
                }

            } while (numCheck == true);

            /*Convert String to Float*/
            sNumber = stod(sNumberStr);

            return sNumber;
        }


        //Addition Function
        double addFuct(double fNum1, double sNum1) {
            
            /*Variable Creation*/
            double result = 0;  

            /*Add fNum and sNum and save it as result*/
            result = fNum1 + sNum1;

            return result;
        };


        //Subtraction Function
        double subFuct(double fNum1, double sNum1) {
            
            /*Variable Creation*/
            double result = 0;  

            /*Subtract fNum and sNum and save it as result*/
            result = fNum1 - sNum1;

            return result;
        };
        

        //Multiplication Function
        double multFunc(double fNum1, double sNum1) {
            
            /*Variable Creation*/
            double result = 0;  

            /*Multiply fNum and sNum and save it as result*/
            result = fNum1 * sNum1;

            return result;
        };
        

        //Division Function
        double divFunc(double fNum1, double sNum1) {
            
            /*Variable Creation*/
            double result = 0;  

            /*Divide fNum and sNum and save it as result*/
            result = fNum1 / sNum1;

            return result;
        };
};




/*Derived Class (inheritance)*/
class RAcalc2 : public RAcalc {
    public:
        //All in One Function
        void allinone(double fNum1, double sNum1) {
            /*Print all outputs*/
            cout << "\n" << fNum1 << " + " << sNum1 << " = " << addFuct(fNum1, sNum1);
            cout << "\n" << fNum1 << " - " << sNum1 << " = " << subFuct(fNum1, sNum1);
            cout << "\n" << fNum1 << " * " << sNum1 << " = " << multFunc(fNum1, sNum1);
            cout << "\n" << fNum1 << " / " << sNum1 << " = " << divFunc(fNum1, sNum1);
            cout << "\n";
        };
        

        //Select an Operator Function for DoCalc 
        string operatorFunc (void) {
           
            /*Variable Creation*/
            string operatorStr = " "; 
            bool numCheck = false;
            
            /*Do While Loop in case number wasnt valid*/
            do {

                /*Variable Reset*/
                numCheck = false;

                /*Prompt User for Operator and save it as a variable*/
                cout <<   "Add:  + \
                         \nSub:  - \
                         \nMult: * \
                         \nDiv:  / \
                         \nOperator  : ";
                getline (cin, operatorStr);
                
                /*Verify user input is a valid number*/
                
                if (operatorStr != "+" && operatorStr != "-" && operatorStr != "*" && operatorStr != "/") {
                    numCheck = true;
                } 
                

                if (numCheck == true) {
                    cout << "\nPlease only type an operator +, -, *, / \n";
                    numCheck = true;
                }

            } while (numCheck == true);

            return operatorStr;
        };

        
        //Do Calculations Function where you select both numbers and an operator
        void docalc(double fNum1, double sNum1, string operatorStr) {
            if (operatorStr == "+") {
                cout << "\n" << fNum1 << " + " << sNum1 << " = " << addFuct(fNum1, sNum1);
            }
            else if (operatorStr == "-") {
                cout << "\n" << fNum1 << " - " << sNum1 << " = " << subFuct(fNum1, sNum1);
            }
            else if (operatorStr == "*") {
                cout << "\n" << fNum1 << " * " << sNum1 << " = " << multFunc(fNum1, sNum1);
            }
            else if (operatorStr == "/") {
                if (sNum1 == 0) {
                    /*Variable Creation*/
                    bool trapZero = false;

                    cout << "Cannot Divide by Zero\n";

                    do { 
                        sNum1 = sNum();
                        if (sNum1 == 0) {
                            cout << "Cannot Divide by Zero\n";
                            trapZero = true;
                        }
                        else {
                            trapZero = false;
                        }
                    } while (trapZero == true);
                }
                cout << "\n" << fNum1 << " / " << sNum1 << " = " << divFunc(fNum1, sNum1);
            }
        }; 
};




class tools {
    public: 
        //Function that restarts program
        void restart (string userName) {
            cout << "\n" << userName << ", Thank you for using my application.";
            cout << "\nPress Enter to Restart Application\n";
        }


        //Function that allows user to enter their name
        string userName (void) {
            /*Variable Creation*/
            string userName = " ";
           
            /*Prompt User for Name and Save it to userName*/
            cout << "\nPlease Type your name : ";  
            getline (cin, userName); //Getline() allows me to get strings with spaces

            /*Greet User*/
            cout << "\nHello, " << userName << ".";
            return  userName;
        }


        //Function that reads MathInput Data File and manipulates MathOutput Date File
        void readDataFile (void) {
            /*Reading and Writing Files*/
            ofstream fout;
            ifstream fin;

            /*Variable Creation*/
            string myString = " ";
            string numString = "";
            float numFloat = 0;
            float numTotal = 0;
            float numElements = 0;
             

            // Read Data Sets
            /*Opens Data File to be Read*/
            fin.open("MathInput.csv");

            /*Opens Results File for Writing*/
            fout.open("MathOutput.csv");
            
            /*Read File*/
            while (getline(fin, myString)) {

                for (int i = 0; i < myString.size(); i++) {
                    if (myString[i] == '0' || myString[i] == '1' || myString[i] == '2' || myString[i] == '3' \
                        || myString[i] == '4' || myString[i] == '5' || myString[i] == '6' || myString[i] == '7' \
                        || myString[i] == '8' || myString[i] == '9' || myString[i] == '.') {
                       
                        numString = numString + myString[i];
                    }

                    else if (myString[i] == '-' && i == 1) {
                        numString = numString + myString[i];
                    }

                    else if (myString[i] == '+') {
                        //add number string to total
                        /*Convert String to Float*/
                        numFloat = stof(numString);
                        
                        /*adding number to total*/
                        numTotal = numTotal + numFloat;

                        // Write numString and Operator to Output Results File
                        fout << "\nAdd  : " << numString << "  Total : " << numTotal;

                        //Clear number string
                        numString = "";

                        /*tracking Elements*/
                        numElements ++;
                    }

                    else if (myString[i] == '-' && i != 1) {
                        //Subtract number string to total
                        /*Convert String to Float*/
                        numFloat = stof(numString);
                        
                        /*Subtracting number from total*/
                        numTotal = numTotal - numFloat;

                        // Write numString and Operator to Output Results File
                        fout << "\nSub  : " << numString << "  Total : " << numTotal;
                            
                        //Clear number string
                        numString = "";

                        /*tracking Elements*/
                        numElements ++;
                    }

                    else if (myString[i] == '*') {
                        //Multiply number string to total
                        /*Convert String to Float*/
                        numFloat = stof(numString);

                        /*Multiplying number and total*/
                        numTotal = numTotal * numFloat;
                       
                        // Write numString and Operator to Output Results File
                        fout << "\nMult : " << numString << "  Total : " << numTotal;
                            
                        //Clear number string
                        numString = "";

                        /*tracking Elements*/
                        numElements ++;
                    }

                    else if (myString[i] == '/') {
                        //Divide number string to total
                        /*Convert String to Float*/
                        numFloat = stof(numString);
                        
                        /*Dividing total by number*/   
                        numTotal = numTotal / numFloat;
                       
                        // Write numString and Operator to Output Results File
                        fout << "\nDiv  : " << numString << "  Total : " << numTotal;
                            
                        //Clear number string
                        numString = "";
                        
                        /*tracking Elements*/
                        numElements ++;
                    }

                    else if (myString[i] == '=') {
                        //print set results and reset variables
                        fout << "\nNumber of Elements: " << numElements << ", Total: " << numTotal << ", Average: " << numTotal / numElements << "\n";  
                        numElements = 0;
                        numTotal = 0;
                        numString = "";
                    }
                } 
            }
            
            /*Close Reading and Writing of both files*/
            fin.close();
            fout.close();

            /*Tell user file calculations are done*/
            cout << "\nResults saved.\n";
        }


        //Function that Reads MathOutput Data File
        void readOutputFile (void) {
            /*Reading and Writing Files*/
            ofstream fout;
            ifstream fin;

            /*Variable Creation*/
            string myString = "";
            
            // Read Output File
            /*Open Output Results file for reading*/
            fin.open("MathOutput.csv");
            
            /*Read File*/
            while(getline(fin, myString)) {
                cout << "\n" << myString << "\n";
            }

            /*Close File*/
            fin.close();
        }
};




//Creating a class "Stack" that has an array with functions to manipulate it
//The Template line allows me to interchange data types later on to fit any need I may have  
template <typename data_type> 
class Stack {
    private:
        //Creating my dynamic array using 'vector'
        vector<data_type> listOfElements;
    public: 
        //Creating my functions to manipulate the private array 
        void push (data_type value);
        void pop ();
        data_type top ();
        bool empty ();
}; 


//Define Push Function
template <class data_type>
void Stack<data_type>::push (data_type value) {
    // append copy of passed element
    listOfElements.push_back(value);
};


//Define Pop Function
template <class data_type>
void Stack<data_type>::pop () {
    // remove last element
    listOfElements.pop_back();
};


//Define Top Function
template <class data_type>
data_type Stack<data_type>::top () {
    if (listOfElements.empty()) {
        throw out_of_range("Stack<>::top(): empty stack");
    }

    // return copy of last element
    return listOfElements.back();
};


//Define Empty Function
template <class data_type>
bool Stack<data_type>::empty () {
    return listOfElements.empty();  
}




/*Start of Program*/
int main () {
    
    /*Primary While Loop, used when program restarts*/
    while (true) {

        /*Variable Creation*/
        string userName = " ";
        string clearLine = " ";
        int counter = 0;

        /*Class Declarations*/
        RAcalc calcClass; 
        RAcalc2 AllinOne;
        RAcalc2 DoCalc; 
        tools calcTools;

        /*Reading and Writing Files*/
        ofstream fout;
        ifstream fin;

        /*Creating a Stack*/
        Stack<int> intStack;
        Stack<int> intStackCopy;
        Stack<char> charStack;
        Stack<char> charStackCopy;
        Stack<string> stringStack;
        Stack<string> stringStackCopy;
        Stack<double> doubleStack;
        Stack<double> doubleStackCopy;

    
        /*Get UserName*/
        userName = calcTools.userName();

        /*Calculator Menu*/
        while(true) {
                        
            /*Variable Creation*/
            string menuSelection1 = " ";
            float fNum1 = 0;
            float sNum1 = 0;
            string op1 = "0";

            /*Provide Menu*/
            cout << "\nPlease select from the below Menu: \
                    \n(a) Addition \
                    \n(s) Subtraction \
                    \n(m) Multiplication \
                    \n(d) Division \
                    \n \
                    \n(A) All in One \
                    \n(D) Do Calc \
                    \n(W) Read Data Sets and Write Calculations into Output Results File \
                    \n(R) Read Output Results File \
                    \n \
                    \n(S) Save to Stack \
                    \n(P) Pop from Stack \
                    \n \
                    \n(e) Exit to Restart\
                    \n \
                    \nMenu Selection : ";
            
            /*Store user's Menu Selection*/
            getline (cin, menuSelection1);


            /*If & Else if Statements to sort the users selection.*/ 
            //Addition
            if (menuSelection1 == "a") {
                fNum1 = calcClass.fNum();
                sNum1 = calcClass.sNum();
                cout << fNum1 << " + " << sNum1 << " = " << calcClass.addFuct(fNum1, sNum1) << "\n";
            }
        

            //Subtraction
            else if (menuSelection1 == "s") {
                fNum1 = calcClass.fNum();
                sNum1 = calcClass.sNum();
                cout << fNum1 << " - " << sNum1 << " = " << calcClass.subFuct(fNum1, sNum1) << "\n";
            }
        

            //Multiplication
            else if (menuSelection1 == "m") {
                fNum1 = calcClass.fNum();
                sNum1 = calcClass.sNum();
                cout << fNum1 << " * " << sNum1 << " = " << calcClass.multFunc(fNum1, sNum1) << "\n";
            }
        

            //Division
            else if (menuSelection1 == "d") {
                fNum1 = calcClass.fNum();
               
                /*Variable Creation*/
                bool trapZero = false;

                /*Trap Zero*/
                do { 
                    sNum1 = calcClass.sNum();
                    if (sNum1 == 0) {
                        cout << "Cannot Divide by Zero\n";
                        trapZero = true;
                    }
                    else {
                        trapZero = false;
                    }
                } while (trapZero == true);

                cout << fNum1 << " / " << sNum1 << " = " << calcClass.divFunc(fNum1, sNum1) << "\n";
            }




            //All in One
            else if (menuSelection1 == "A") {
                fNum1 = AllinOne.fNum();
                sNum1 = AllinOne.sNum();
                AllinOne.allinone(fNum1, sNum1); 
            }


            //Do Calc
            else if (menuSelection1 == "D") {
                fNum1 = DoCalc.fNum();
                sNum1 = DoCalc.sNum();
                op1 = DoCalc.operatorFunc();               
                DoCalc.docalc(fNum1, sNum1, op1);
            }


            //Read Data Sets and Write Calculations into Output Results File
            else if (menuSelection1 == "W") {
                calcTools.readDataFile();
                counter = 1;
            }    


            //Read Output Results File
            else if (menuSelection1 == "R") {
                if (counter == 1) {
                    calcTools.readOutputFile();
                }
                else {
                    cout << "\nYou have no Output Files Calculated\n";
                }
            }




            //Save to Stack
            else if (menuSelection1 == "S") {
                //Variable Creation and reset
                string stackSelection = ""; 
                
                //Select Stack type
                cout << "\n  String (S)\
                         \n  Int    (I)\
                         \n  Double (D)\
                         \n \
                         \nWhich Stack would you like to add to : ";
                
                getline(cin, stackSelection);


                //Add String to Stack
                if (stackSelection == "S") {

                    //Add to stack of Strings 
                    do {
                        //Variable Creation
                        string userString;

                        //Prompt User for String
                        cout << "\nType a string (Press enter finish) : ";
                        getline(cin, userString);

                        //Condition to stop adding strings 
                        if (userString == "") {
                            break;
                        }

                        //add String to Stack
                        stringStack.push(userString);

                    } while (true);


                    //Print current stack of Strings    
                    stringStackCopy = stringStack;
                    cout << "\nYour Stack includes : \n";
                    while(stringStackCopy.empty() == false) {
                        cout << stringStackCopy.top() << "\n";
                        stringStackCopy.pop();
                    }
                }


                //Add Integer to Stack
                else if (stackSelection == "I") {

                    //Add to stack of Ints 
                    do {
                        //Variable Creation
                        string userString;
                        int userInt;
                        bool numCheck = false;

                        /*Do While Loop in case number wasnt valid*/
                        do {
                            //Prompt User
                            cout << "\nType an integer (Press enter finish) : ";
                            getline(cin, userString);
                            
                            //Condition to stop adding numbers
                            if (userString == "") {
                                break;
                            }
                                                   
                            /*variable Reset*/
                            numCheck = false;
                            
                            /*Verify user input is a valid number*/
                            for (int i = 0; userString[i]; i++) {
                                if (userString[i] != '0' && userString[i] != '1' && userString[i] != '2' && userString[i] != '3' && \
                                    userString[i] != '4' && userString[i] != '5' && userString[i] != '6' && userString[i] != '7' && \
                                    userString[i] != '8' && userString[i] != '9' && userString[i] != '\0') {
                                    numCheck = true;
                                } 
                            }

                            if (numCheck == true) {
                                cout << "\nPlease only type a number 0-9 \n";
                                numCheck = true;
                            }

                        } while (numCheck == true);
                        
                        //Condition to stop adding numbers
                        if (userString == "") {
                            break;
                        }

                        //Convert String to Int
                        userInt = stoi(userString);

                        //Add Int to Stack
                        intStack.push(userInt);

                    } while (true);

                    //Print current stack of Ints    
                    intStackCopy = intStack;
                    cout << "\nYour Stack includes: \n";
                    while(intStackCopy.empty() == false) {
                        cout << intStackCopy.top() << "\n";
                        intStackCopy.pop();
                    }
                }


                //Add Double to Stack
                else if (stackSelection == "D") {

                    //Add to stack of Doubles 
                    do {
                        //Variable Creation
                        string userString;
                        double userDouble;
                        bool numCheck = false;

                        /*Do While Loop in case number wasnt valid*/
                        do {
                            //Prompt User
                            cout << "\nType an double (Press enter finish) : ";
                            getline(cin, userString);
                            
                            //Condition to stop adding numbers
                            if (userString == "") {
                                break;
                            }
                                                   
                            /*variable Reset*/
                            numCheck = false;
                            int periodCounter = 0;
                            
                            /*Verify user input is a valid number*/
                            for (int i = 0; userString[i]; i++) {
                                if (userString[i] != '0' && userString[i] != '1' && userString[i] != '2' && userString[i] != '3' && \
                                    userString[i] != '4' && userString[i] != '5' && userString[i] != '6' && userString[i] != '7' && \
                                    userString[i] != '8' && userString[i] != '9' && userString[i] != '.' && userString[i] != '\0') {
                                    numCheck = true;
                                } 

                                else if (userString[i] == '.') {
                                    periodCounter++;
                                }
                            }

                            if (numCheck == true) {
                                cout << "\nPlease only type a number 0-9 or a '.' \n";
                                numCheck = true;
                            }

                            else if (periodCounter > 1) {
                                cout << "\nPlease dont use more than one '.' in your number\n";
                                numCheck = true;
                            }

                        } while (numCheck == true);
                        
                        //Condition to stop adding numbers
                        if (userString == "") {
                            break;
                        }

                        //Convert String to Double
                        userDouble = stod(userString);

                        //Add Double to Stack
                        doubleStack.push(userDouble);

                    } while (true);

                    //Print current stack of Doubles    
                    doubleStackCopy = doubleStack;
                    cout << "\nYour Stack includes: \n";
                    while(doubleStackCopy.empty() == false) {
                        cout << doubleStackCopy.top() << "\n";
                        doubleStackCopy.pop();
                    }
                }


                else {
                    cout << "\nInvalid response Please enter S, I, or D \n";
                }
            }


            //Pop from Stack
            else if (menuSelection1 == "P") {
                //Variable Creation and reset
                string stackSelection = ""; 
                
                //Select Stack type
                cout << "\n  String (S)\
                         \n  Int    (I)\
                         \n  Double (D)\
                         \n \
                         \nWhich Stack would you like to remove from : ";
                
                getline(cin, stackSelection);


                //Pop String from Stack
                if (stackSelection == "S") {
                    //variable Creation
                    string removalString = ""; 
                    int removalNumber = 0;
                    bool numCheck = false;
                    int counter = 0;

                    if (stringStack.empty()) {
                        cout << "\nYour String stack is Empty\n";
                    }

                    else {

                        //Print current stack of Strings    
                        stringStackCopy = stringStack;

                        cout << "\nYour Stack includes: \n";
                        while(stringStackCopy.empty() == false) {
                            cout << stringStackCopy.top() << "\n";
                            stringStackCopy.pop();
                            counter++;
                        }

                        
                        /*Do While Loop in case number wasnt valid*/
                        do {
                            //Prompt user to delete last entry
                            cout << "\nHow many entries would you like to remove? : ";
                            getline (cin, removalString);
                                                    
                            /*variable Reset*/
                            numCheck = false;
                            
                            /*Verify user input is a valid number*/
                            for (int i = 0; removalString[i]; i++) {
                                if (removalString[i] != '0' && removalString[i] != '1' && removalString[i] != '2' && removalString[i] != '3' && \
                                    removalString[i] != '4' && removalString[i] != '5' && removalString[i] != '6' && removalString[i] != '7' && \
                                    removalString[i] != '8' && removalString[i] != '9' && removalString[i] != '\0') {
                                    numCheck = true;
                                } 
                            }

                            if (numCheck == true) {
                                cout << "\nPlease only type a number 0-9 \n";
                                numCheck = true;
                            }

                            if (removalString == "") {
                                cout << "\nPlease Type a number\n";
                                numCheck = true;
                            }

                        } while (numCheck == true);
                        

                        //Convert String to Int
                        removalNumber = stoi(removalString);


                        //Verify Total number of removal request is less than or equal to current number of entries
                        if (removalNumber <= counter) {
                            //Removing entries
                            for (int i = 0; i < removalNumber; i++) {
                                stringStack.pop();
                            }
                        }

                        else {
                            //Too Many requested, clearing all entries
                            for (int i = 0; i < counter; i++) {
                                stringStack.pop();
                            }
                        }


                        //Printing new String Stack
                        stringStackCopy = stringStack;

                        cout << "\nYour New Stack includes : \n";
                        while(stringStackCopy.empty() == false) {
                            cout << stringStackCopy.top() << "\n";
                            stringStackCopy.pop();
                        }
                    }
                }


                //Pop Integer from Stack
                else if (stackSelection == "I") {
                    //variable Creation
                    string removalString = ""; 
                    int removalNumber = 0;
                    bool numCheck = false;
                    int counter = 0;

                    if (intStack.empty()) {
                        cout << "\nYour Integer stack is Empty\n";
                    }

                    else {

                        //Print current stack of Intergers    
                        intStackCopy = intStack;

                        cout << "\nYour Stack includes: \n";
                        while(intStackCopy.empty() == false) {
                            cout << intStackCopy.top() << "\n";
                            intStackCopy.pop();
                            counter++;
                        }

                        
                        /*Do While Loop in case number wasnt valid*/
                        do {
                            //Prompt user to delete last entry
                            cout << "\nHow many entries would you like to remove? : ";
                            getline (cin, removalString);
                                                    
                            /*variable Reset*/
                            numCheck = false;
                            
                            /*Verify user input is a valid number*/
                            for (int i = 0; removalString[i]; i++) {
                                if (removalString[i] != '0' && removalString[i] != '1' && removalString[i] != '2' && removalString[i] != '3' && \
                                    removalString[i] != '4' && removalString[i] != '5' && removalString[i] != '6' && removalString[i] != '7' && \
                                    removalString[i] != '8' && removalString[i] != '9' && removalString[i] != '\0') {
                                    numCheck = true;
                                } 
                            }

                            if (numCheck == true) {
                                cout << "\nPlease only type a number 0-9 \n";
                                numCheck = true;
                            }

                            if (removalString == "") {
                                cout << "\nPlease Type a number\n";
                                numCheck = true;
                            }

                        } while (numCheck == true);
                        

                        //Convert String to Int
                        removalNumber = stoi(removalString);


                        //Verify Total number of removal request is less than or equal to current number of entries
                        if (removalNumber <= counter) {
                            //Removing entries
                            for (int i = 0; i < removalNumber; i++) {
                                intStack.pop();
                            }
                        }

                        else {
                            //Too Many requested, clearing all entries
                            for (int i = 0; i < counter; i++) {
                                intStack.pop();
                            }
                        }


                        //Printing new Integer Stack
                        intStackCopy = intStack;

                        cout << "\nYour New Stack includes : \n";
                        while(intStackCopy.empty() == false) {
                            cout << intStackCopy.top() << "\n";
                            intStackCopy.pop();
                        }
                    }
                }


                //Pop Double from Stack
                else if (stackSelection == "D") {
                    //variable Creation
                    string removalString = ""; 
                    int removalNumber = 0;
                    bool numCheck = false;
                    int counter = 0;

                    if (doubleStack.empty()) {
                        cout << "\nYour Double stack is Empty\n";
                    }

                    else {

                        //Print current stack of Doubles    
                        doubleStackCopy = doubleStack;

                        cout << "\nYour Stack includes: \n";
                        while(doubleStackCopy.empty() == false) {
                            cout << doubleStackCopy.top() << "\n";
                            doubleStackCopy.pop();
                            counter++;
                        }

                        
                        /*Do While Loop in case number wasnt valid*/
                        do {
                            //Prompt user to delete last entry
                            cout << "\nHow many entries would you like to remove? : ";
                            getline (cin, removalString);
                                                    
                            /*variable Reset*/
                            numCheck = false;
                            
                            /*Verify user input is a valid number*/
                            for (int i = 0; removalString[i]; i++) {
                                if (removalString[i] != '0' && removalString[i] != '1' && removalString[i] != '2' && removalString[i] != '3' && \
                                    removalString[i] != '4' && removalString[i] != '5' && removalString[i] != '6' && removalString[i] != '7' && \
                                    removalString[i] != '8' && removalString[i] != '9' && removalString[i] != '\0') {
                                    numCheck = true;
                                } 
                            }

                            if (numCheck == true) {
                                cout << "\nPlease only type a number 0-9 \n";
                                numCheck = true;
                            }

                            if (removalString == "") {
                                cout << "\nPlease Type a number\n";
                                numCheck = true;
                            }

                        } while (numCheck == true);
                        

                        //Convert String to Int
                        removalNumber = stoi(removalString);


                        //Verify Total number of removal request is less than or equal to current number of entries
                        if (removalNumber <= counter) {
                            //Removing entries
                            for (int i = 0; i < removalNumber; i++) {
                                doubleStack.pop();
                            }
                        }

                        else {
                            //Too Many requested, clearing all entries
                            for (int i = 0; i < counter; i++) {
                                doubleStack.pop();
                            }
                        }


                        //Printing new double Stack
                        doubleStackCopy = doubleStack;

                        cout << "\nYour New Stack includes : \n";
                        while(doubleStackCopy.empty() == false) {
                            cout << doubleStackCopy.top() << "\n";
                            doubleStackCopy.pop();
                        }
                    }
                }


                else {
                    cout << "\nInvalid response Please enter S, I, or D \n";
                }
            }





            //Exit to restart
            else if (menuSelection1 == "e") {
                calcTools.restart(userName);

                /*Clear out overflow to prevrent it from filling in User Name*/
                getline(cin, clearLine);
                break;
            }   


            /*The Else Statement provides user input error protection.*/
            else {
                cout << "Please only type an appropriate character: a, s, m, d, A, D, W, R, S, P, or e.\n"; 
            }
        }
    }
}
"# CMD Line ECHO" 
