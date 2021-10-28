#include <iostream>
#include <cmath>

//These are all the integers.
int main() {
    double FormulaA;
    double FormulaB;
    double FormulaC;

    //Here the user gives you a input for a, b, and c.
    std::cout << "Please enter the values of a, b, and c:";
    std::cin >> FormulaA >> FormulaB >> FormulaC;

    //This is the quadratic formula ax^2 + bx + c = 0.
    double XPlus = (-FormulaB + sqrt(FormulaB * FormulaB - 4 * FormulaA * FormulaC)) / (2 *FormulaA);
    double XMin = (-FormulaB - sqrt(FormulaB * FormulaB - 4 * FormulaA * FormulaC)) / (2 * FormulaA);

    //This is for if there is no solution.
    if (std::isnan(XPlus) && std::isnan(XMin)){
        std::cout << "There is no solution." << std::endl;
    }

    //The quadratic formula sometimes has one or two solutions this is for the time there is only one solution. 
    else{
        if(XPlus == XMin){
            std::cout << "There is 1 solution. " << std::endl;
            std::cout << "The solution is: " << XMin << std::endl;
    
    //This is when the quadratic formuila has two solutions. 
        }
        else{
            std::cout << "There are 2 solutions. " << std::endl;
            std::cout << "The solutions are: " << XPlus << " and " << XMin;
        }
    }
}