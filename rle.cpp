//Benjamin v. Rhee 
//Run-Length Encoding
#include <iostream>
#include <string>

int main(){

    std::string txt;
    std::cout << "Enter the data to be compressed:" << std::endl;
    std::cin >> txt;

//looks if there are anny numbers in the string (txt).
if (std::string::npos != txt.find_first_of("0123456789"))
{
  std::cout << "error: invalid input" << std::endl;;

return 0; 
}

//Looks if there are anny capital characters in the string (txt).
if (std::string::npos != txt.find_first_of("QWERTYUIOPASDFGHJKLZXCVBNM"))
{
  std::cout << "error: invalid input" << std::endl;;

return 0; 
}

std::cout <<  "The compressed data is: ";

//Loop runs until x = txt.size
  for (int x = 0; x < txt.size(); x++){
    int Rln = 1;

//While loop runs when txt[x] is true and x <txt.size() is true (both need to be true).  
        while (txt[x] == txt[x + 1] && x < txt.size()){
            Rln++;
            x++;
        }
        std::cout << Rln << txt[x];
  }  
  return 0; 
}  



