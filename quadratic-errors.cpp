#include <iostream>
#include <cmath>
#include <limits>

//These are all the integers.
int main() {


  double FormulaA;
  double FormulaB;
  double FormulaC;

  //Here the user gives you a input for a, b, and c.
  try{


    std::cout << "Please enter the values of a, b, and c:";
    std::cin >> FormulaA >> FormulaB >> FormulaC;


    //This is the quadratic formula ax^2 + bx + c = 0.
    double XPlus = (-FormulaB + sqrt(FormulaB * FormulaB - 4 * FormulaA * FormulaC)) / (2 *FormulaA);
    double XMin = (-FormulaB - sqrt(FormulaB * FormulaB - 4 * FormulaA * FormulaC)) / (2 * FormulaA);


    //This is to check if the input failed.
    if (std::cin.fail()) {
      throw std::runtime_error("Malformed user input");
      
    }

    //This is for if FormulaA is equal to 0.
    if(FormulaA == 0){
      throw std::runtime_error ("a must not be zero");
  
    }

    //This is for if there is no solution.
    if (std::isnan(XPlus) && std::isnan(XMin)){
        std::cout << "There is no solution." << std::endl;
   
    }

    //The quadratic formula sometimes has one or two solutions this is for the time there is only one solution. 
    else{
      if(XPlus == XMin){
        std::cout << "There is 1 solution. " << std::endl;
        std::cout << "The solution is: " << XMin << std::endl;
      }
      else{
        std::cout << "There are 2 solutions. " << std::endl;
        std::cout << "The solutions are: " << XPlus << " and " << XMin;
        return 0;
      }
    }

  }
  catch(std::runtime_error e){
    std::cerr << "An error occurred: " << e.what() << std::endl;
    return -1;
  }
    return 0;
}