//BenjaminvanRHee5v4.
//Hello this is my Collatz C++ program.
#include <iostream>


int main()
{
    std::cout << "Enter the first number of the sequence: ";
    long long x;
    std::cin >> x;
    while (x != 1)//(!= means is not) 
    {
        std::cout << x << " ";
        //even
        if ((x & 1) == 0) 
            x >>= 1;
        //uneven    
        else x = x * 3 + 1;
    }
    std::cout << x << std::endl;
    if (x == 1)
    
}

