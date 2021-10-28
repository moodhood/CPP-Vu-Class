#include <iostream> 
#include <vector> 


int FindSmallerNumber(std::vector<int> intVector){
    int smallest = intVector.at(0);
    
    for (int x = 0; x < intVector.size(); x++){
        if(intVector.at(x) < smallest){
            smallest = intVector.at(x);
        }
    }
    return smallest;
}

int FindNextsmallestBigger(std::vector<int> intVector, int Smaller, int biggest){

  int Nextbig = Smaller;

  for (int x = 0; x < intVector.size(); x++ ){

    if(intVector.at(x) > Smaller && intVector.at(x) < biggest + 1){
     Nextbig = intVector.at(x);
     biggest = intVector.at(x);
    }
  }
  return Nextbig;

}

int FindBiggestNumber(std::vector<int> intVector){
    int Biggest = intVector.at(0);
    
    for (int x = 0; x < intVector.size(); x++){
        if(intVector.at(x) > Biggest){
            Biggest = intVector.at(x);
        }
    }
    return Biggest;
}

int FindSmallerNumberMissing(std::vector<int> intVector){
  int SmallerNumber = FindSmallerNumber(intVector);
  int BiggestNumber = FindBiggestNumber(intVector);

  while (true){

    int nextBiggest = FindNextsmallestBigger(intVector, SmallerNumber, BiggestNumber);

    if (nextBiggest != SmallerNumber + 1){
      return SmallerNumber + 1;
    }

    SmallerNumber = nextBiggest;
  }
}

int main(){
    int Numbers;

  std::cout << "How many numbers? ";
  std::cin >> Numbers;

  std::cout << "Please enter the numbers ";

  std::vector<int> NumberArray(Numbers);

  for (int x = 0; x < NumberArray.size(); x++){
    std::cin >> NumberArray.at(x);
  }

  std::cout << "The smallest missing number is " << FindSmallerNumberMissing(NumberArray); 
} 