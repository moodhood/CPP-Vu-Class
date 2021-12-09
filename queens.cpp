//Benjamin v. Rhee & Ijssel Koster


#include <iostream>
#include <vector>
#include <string>


//This is for the chessboard, we used ASCII code for this. 
void printBoard(std::vector < std::vector <bool> >& inVector){

  char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  std::cout << "   ";

  for (int x = 0; x < inVector[0].size(); x++)
    std::cout << alphabet[x % 26] << " ";

  std::cout << "\n";

  for (int y = 0; y < inVector.size(); y++) {

    if (y+1 < 10)
      std::cout << " ";

    std::cout << y + 1 << " ";

    for (int x = 0; x < inVector[y].size(); x++){

      if ((x + (y % 2)) % 2){
        std::cout << "\u001b[30m";
      }
      else{
        std::cout << "\u001b[37m";
      }

      if(inVector[y][x]){
        std::cout << "\e[1m\u001b[31m" << "Q " << "\u001b[0m\e[0m";
      }
      else{
        std::cout << char(254) << " ";
      }
    }
    std::cout << "\u001b[0m\e[0m\n";
  }
}

//This checks the lanes from vertically , horizontally and diagonally
bool checkTake(std::vector < std::vector <bool> >& inVector, int xPos, int yPos){

  //? Left to right

  for (int x = 0; x < inVector[0].size(); x++){

    if(inVector[yPos][x])
      return true;
  }


  //? Top to bottom

  for (int y = 0; y < inVector[0].size(); y++){

    if(inVector[y][xPos])
      return true;
  }


  //? Top left to bottom right

  for (int x = xPos, y = yPos; y >= 0 && x >= 0; x--, y--){

    if(inVector[y][x])
      return true;
  }

  for (int x = xPos, y = yPos; y < inVector.size() && x < inVector[0].size(); x++, y++){

    if(inVector[y][x])
      return true;
  }


  //? Bottom left to top right

  for (int x = xPos, y = yPos; y < inVector[0].size() && x >= 0; x--, y++){

    if(inVector[y][x])
      return true;
  }

  for (int x = xPos, y = yPos; y >= 0 && x < inVector[0].size(); x++, y--){

    if(inVector[y][x]){
      return true;
    }
  }

  return false;
}

//This checks where the queens can be placed.
bool placeQueens(std::vector < std::vector <bool> >& inVector, int xPos){

  if (xPos >= inVector.size())
    return true;


  for (int yPos = 0; yPos < inVector.size(); yPos++) {

    if (!checkTake(inVector, xPos, yPos)) {

      inVector[yPos][xPos] = 1;

      if (placeQueens(inVector, xPos + 1))
        return true;

      
      inVector[yPos][xPos] = 0; 
    }
  }

  return false;
}


int main(){

  try{

    int boardSize;

    std::cout << "How many queens to place on the board?\n";

    std::cin >> boardSize;

    if (std::cin.fail()){
      throw std::runtime_error("error: invalid input");
    }

    if (boardSize <= 0){
      throw std::runtime_error("error: invalid input");
    }

    std::vector<std::vector<bool>> chessBoard(boardSize, std::vector<bool>(boardSize, 0));


    if (placeQueens(chessBoard, 0) == false)
      throw std::runtime_error("No solution found to place " + std::to_string(boardSize) + " queens on a " + std::to_string(boardSize) + " by " + std::to_string(boardSize) + " chess board");

    printBoard(chessBoard);

    return 0;

  }
  catch(std::runtime_error e){

    std::cerr << e.what() << std::endl;

    return -1;
  }
}