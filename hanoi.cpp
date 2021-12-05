//Benjamin v. Rhee
//Tower Of Hanoi
#include <iostream>

void TowerOfHanoi(int height, char source, char helper, char target)
{
    if (height == 1)
    {
        std::cout << "Move disk " << height <<" from " << source << " to " << target << "." << std::endl;
        return;
    }

    else{
    TowerOfHanoi(height - 1, source, target, helper);
    std::cout << "Move disk " << height << " from " << source << " to " << target << "." << std::endl;
    TowerOfHanoi(height - 1, helper, source, target);
    }
}
 
int main()
{
    int height; 

    std::cout << "How many disks should the tower consist of?" << std::endl;   
    std::cin >> height; 
    
    if (std::cin.fail()){
        std::cout << "invalid input." << std::endl;
        return 0;
    }

    if (height < 0){
        std::cout << "invalid input." << std::endl;
        return 0;
    }


    TowerOfHanoi(height, 'A', 'B', 'C'); 
    return 0;
}
