//Noah Lattari
//500760404
//Lab 1 - Comparing array sort times
#include <iostream>
#include <cstdlib> // for rand and srand
#include <ctime> // for the time function
#include <fstream> //for output file

const int smallArraySize = 10;
const int mediumArraySize = 100;
int main(int argc, const char * argv[]) {
    // insert code here...
    int smallArray[10];
    int mediumArray[100];
    int largeArray[1000];
    
    //array of size 10
    for(int i = 0; i < smallArraySize; i++)
    {
        smallArray[i] = rand() % 40 + 1;
         printf("%d ", smallArray[i]);
    }
    
    //call sorts
    
    for(int i = 0; i < mediumArraySize; i++)
    {
        mediumArray[i] = rand() % 400 + 1;
        printf("%d ", mediumArray[i]);
    }
    
    
    
    
  
    return 0;
    
    
}
