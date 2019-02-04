//Noah Lattari
//500760404
//Lab 1 - Comparing array sort times
#include <iostream>
#include <cstdlib> // for rand and srand
#include <ctime> // for the time function
#include <fstream> //for output file
#include <vector>

int SIZE = 10;
std::vector<int> arr(SIZE);


void fillArray();
void printUnsorted();
int main(int argc, const char * argv[]) {

    fillArray();
    printUnsorted();
    return 0;
    
    
    

}

void fillArray()
{
    arr.resize(SIZE);
    std::cout << "Size of array (n) is " << SIZE << std::endl;
    for(int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % (4 * SIZE) + 1;
    }
}

void printUnsorted()
{
    for(int i = 0; i < SIZE; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}
