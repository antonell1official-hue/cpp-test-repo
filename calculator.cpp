#include "calculator.h"
#include <cmath>
#include <limits>
#include <string>
#include <sstream> 
#include <iostream>
using namespace std;

bool ReadNumber(Number& result) {
    cin >> result;
    if (cin.fail()) {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

bool RunCalculatorCycle() {
    Number current = 0;
     Number memory = 0;
     bool memory_initialized = false;
     
    if (!ReadNumber(current)) {
        cerr << "Error: Numeric operand expected" << endl;
        return false;
    }
    
    while (true) {
        string command;
        cin >> command;
        
          if (command == "+" || command == "-" || command == "*" || 
            command == "/" || command == "**" || command == ":") {
            
               Number operand;
             if (!ReadNumber(operand)) {
                cerr << "Error: Numeric operand expected" << endl;
                return false;
            }
            
            if (command == "+") {
                 current += operand;
              } else if (command == "-") {
                current -= operand;
            } else if (command == "*") {
                  current *= operand;
            } else if (command == "/") {
                  
                if (operand == 0) {
                    cerr << "Error: Division by zero" << endl;
                    return false;
                }
                  current /= operand;
            } else if (command == "**") {
                     current = std::pow(current, operand); 
              } else if (command == ":") {
                current = operand;
            }
             
          } else if (command == "=") {
              cout << current << endl;
        }  else if (command == "c") {
            current = 0;
        } else if (command == "q") {
            return true;
         } else if (command == "s") {
            memory = current;
            memory_initialized = true;
        } else if (command == "l") {
            if (!memory_initialized) {
                cerr << "Error: Memory is empty" << endl;
                return false;
            }
            current = memory;
        } else {
              cerr << "Error: Unknown token " << command << endl;
               return false;
        }
    }
}