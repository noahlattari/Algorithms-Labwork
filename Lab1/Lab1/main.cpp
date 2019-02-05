//Noah Lattari
//500760404
//Lab 1 - Comparing array sort times
#include <iostream>
#include <cstdlib> // for rand and srand
#include <ctime> // for the time function
#include <fstream> //for output file
#include <vector>

int SIZE = 10;
std::vector<int> ARR(SIZE);


void fillArray();
void printUnsorted(std::vector<int>array);
std::vector<int> selectionSort(std::vector<int>arr, int n);


int main(int argc, const char * argv[]) {
    
    fillArray();
    ARR = selectionSort(ARR, SIZE);
    printUnsorted(ARR);
    
    SIZE = 100;
    fillArray();
    ARR = selectionSort(ARR, SIZE);
    printUnsorted(ARR);
    //mergesort()
    
    return 0;
}

std::vector<int> selectionSort(std::vector<int>arr, int n)
{
    int i, j, minIndex, tmp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        if (minIndex != i) {
            tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }
    return arr;
}

void fillArray()
{
    ARR.resize(SIZE);
    std::cout << "Size of array (n) is " << SIZE << std::endl;
    for(int i = 0; i < SIZE; i++)
    {
        ARR[i] = rand() % (4 * SIZE) + 1;
    }
}

void printUnsorted(std::vector<int>array)
{
    for(int i = 0; i < SIZE; i++)
    {
        std::cout << array[i] << std::endl;
    }
}
