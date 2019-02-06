//Noah Lattari
//500760404
//Lab 1 - Comparing array sort times
#include <iostream>
#include <cstdlib> // for rand and srand
#include <ctime> // for the time function
#include <fstream> //for output file
#include <vector>
#include <chrono>
using namespace std::chrono;
using namespace std;

int SIZE = 10;
std::vector<int> ARRAY(SIZE);
std::vector<int> merge_sorted(SIZE);


std::vector<int> fillArray(std::vector<int>array);
void printUnsorted(std::vector<int>array);
std::vector<int> selectionSort(std::vector<int>arr, int n);
std::vector<int> test(std::vector<int>arr);
std::vector<int> mergeSort(std::vector<int> unsorted);
std::vector<int> merge(std::vector<int>left, std::vector<int>right);

int main(int argc, const char * argv[]) {
    /*
    cout << "Selection Sort\n" << endl;
    ARR = fillArray(ARR);
    auto start = high_resolution_clock::now();
    ARR = selectionSort(ARR, SIZE);
    auto stop = high_resolution_clock::now();
    printUnsorted(ARR);
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: of size " << SIZE << "\n" << duration.count() << " microseconds" << endl;
    /*
    SIZE = 100;
    //fillArray();
    start = high_resolution_clock::now();
    ARR = selectionSort(ARR, SIZE);
    stop = high_resolution_clock::now();
    //printUnsorted(ARR);
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: of size " << SIZE << "\n" << duration.count() << " microseconds" << endl;
    
    SIZE = 1000;
   // fillArray();
    start = high_resolution_clock::now();
    ARR = selectionSort(ARR, SIZE);
    stop = high_resolution_clock::now();
    //printUnsorted(ARR);
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: of size " << SIZE << "\n" << duration.count() << " microseconds" << endl;
    
    SIZE = 10000;
    //fillArray();
    start = high_resolution_clock::now();
    ARR = selectionSort(ARR, SIZE);
    stop = high_resolution_clock::now();
    //printUnsorted(ARR);
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: of size " << SIZE << "\n" << duration.count() << " microseconds" << endl;
    
    /*
    SIZE = 100000;
    fillArray();
    start = high_resolution_clock::now();
    ARR = selectionSort(ARR, SIZE);
    stop = high_resolution_clock::now();
    //printUnsorted(ARR);
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: of size 5 " << SIZE << "\n" << duration.count() << " microseconds" << endl;
    */
    
    /*
    SIZE = 1000000;
    fillArray();
    start = high_resolution_clock::now();
    ARR = selectionSort(ARR, SIZE);
    stop = high_resolution_clock::now();
    //printUnsorted(ARR);
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: of size 6" << SIZE << "\n" << duration.count() << " microseconds" << endl;
    */
   
 
    SIZE = 10;
    
    ARRAY = fillArray(ARRAY);
    printUnsorted(ARRAY);
    cout << "merging" << endl;
    ARRAY = mergeSort(ARRAY);
    printUnsorted(ARRAY);
    cout << "Done" << endl;
    
    
    
    return 0;
}

std::vector<int> merge(std::vector<int>left, std::vector<int>right)
{
    std::vector<int>temp;
    int l = 0, r = 0;
  
    while (l < left.size() && r < right.size()) {
        if (left[l] > right[r]) {
            temp.push_back(right[r]);
            r++;
        } else {
            temp.push_back(left[l]);
            l++;
        }
    }
   
    while(l < left.size()){
        temp.push_back(left[l]);
        l++;
    }
    
    while(r < right.size()){
        temp.push_back(right[r]);
        r++;
    }
   
    return temp;
    
}

std::vector<int> mergeSort(std::vector<int> unsorted)
{
    if(unsorted.size() == 1){
        return unsorted;
    }
    
    std::vector<int>left;
    std::vector<int>right;
    std::copy(std::begin(unsorted), std::begin(unsorted) + unsorted.size()/2, std::back_inserter(left));
    std::copy(std::begin(unsorted) + unsorted.size()/2, std::end(unsorted), std::back_inserter(right));
    
    left = mergeSort(left);
    right = mergeSort(right);
    
    return merge(left, right);
    
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



std::vector<int> fillArray(std::vector<int>array)
{
    array.resize(array.size());
    std::cout << "Size of array (n) is " << SIZE << std::endl;
    for(int i = 0; i < array.size(); i++)
    {
        array[i] = rand() % (4 * array.size()) + 1;
    }
    
    return array;
}

void printUnsorted(std::vector<int>array)
{
    for(int i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << std::endl-;
    }
}
