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
std::vector<int> mergeSelect(std::vector<int>left, std::vector<int>right);
std::vector<int> mergeAndSelect(std::vector<int>unsorted);

int main(int argc, const char * argv[]) {
    
    
    
    cout << "Selection Sort\n" << endl;
    
    ARRAY = fillArray(ARRAY);
    auto start = high_resolution_clock::now();
    ARRAY = selectionSort(ARRAY, SIZE);
    auto stop = high_resolution_clock::now();
    printUnsorted(ARRAY);
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: of size " << SIZE << "\n" << duration.count() << " microseconds" << endl;
    
    SIZE = 100;
    ARRAY = fillArray(ARRAY);
    start = high_resolution_clock::now();
    ARRAY = selectionSort(ARRAY, SIZE);
    stop = high_resolution_clock::now();
    //printUnsorted(ARRAY);
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: of size " << SIZE << "\n" << duration.count() << " microseconds" << endl;
    
    SIZE = 1000;
    ARRAY = fillArray(ARRAY);
    start = high_resolution_clock::now();
    ARRAY = selectionSort(ARRAY, SIZE);
    stop = high_resolution_clock::now();
    //printUnsorted(ARRAY);
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: of size " << SIZE << "\n" << duration.count() << " microseconds" << endl;
    
    SIZE = 10000;
    ARRAY = fillArray(ARRAY);
    start = high_resolution_clock::now();
    ARRAY = selectionSort(ARRAY, SIZE);
    stop = high_resolution_clock::now();
    //printUnsorted(ARRAY);
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: of size " << SIZE << "\n" << duration.count() << " microseconds" << endl;
    
    SIZE = 20000;
    ARRAY = fillArray(ARRAY);
    start = high_resolution_clock::now();
    ARRAY = selectionSort(ARRAY, SIZE);
    stop = high_resolution_clock::now();
    //printUnsorted(ARRAY);
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: of size " << SIZE << "\n" << duration.count() << " microseconds" << endl;
    
    SIZE = 30000;
    ARRAY = fillArray(ARRAY);
    start = high_resolution_clock::now();
    ARRAY = selectionSort(ARRAY, SIZE);
    stop = high_resolution_clock::now();
    //printUnsorted(ARRAY);
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: of size " << SIZE << "\n" << duration.count() << " microseconds" << endl;
    
    cout << "Merge Sort" << endl;
    
    SIZE = 10;
    ARRAY = fillArray(ARRAY);
    start = high_resolution_clock::now();
    ARRAY = mergeSort(ARRAY);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    printUnsorted(ARRAY);
    cout << "Time taken by function: of size " << SIZE << "\n" << duration.count() << " microseconds" << endl;
    
    SIZE = 100;
    ARRAY = fillArray(ARRAY);
    start = high_resolution_clock::now();
    ARRAY = mergeSort(ARRAY);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    //printUnsorted(ARRAY);
    cout << "Time taken by function: of size " << SIZE << "\n" << duration.count() << " microseconds" << endl;
    
    SIZE = 1000;
    ARRAY = fillArray(ARRAY);
    start = high_resolution_clock::now();
    ARRAY = mergeSort(ARRAY);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
   // printUnsorted(ARRAY);
    cout << "Time taken by function: of size " << SIZE << "\n" << duration.count() << " microseconds" << endl;
    
    SIZE = 10000;
    ARRAY = fillArray(ARRAY);
    start = high_resolution_clock::now();
    ARRAY = mergeSort(ARRAY);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
   // printUnsorted(ARRAY);
    cout << "Time taken by function: of size " << SIZE << "\n" << duration.count() << " microseconds" << endl;
    
    SIZE = 20000;
    ARRAY = fillArray(ARRAY);
    start = high_resolution_clock::now();
    ARRAY = mergeSort(ARRAY);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
   // printUnsorted(ARRAY);
    cout << "Time taken by function: of size " << SIZE << "\n" << duration.count() << " microseconds" << endl;
    
    SIZE = 100000;
    ARRAY = fillArray(ARRAY);
    start = high_resolution_clock::now();
    ARRAY = mergeSort(ARRAY);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    //printUnsorted(ARRAY);
    cout << "Time taken by function: of size " << SIZE << "\n" << duration.count() << " microseconds" << endl;
    
    cout << "Merge with Selection Sort" << endl;
    
    SIZE = 10;
    ARRAY=fillArray(ARRAY);
    start = high_resolution_clock::now();
    ARRAY = mergeAndSelect(ARRAY);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    //printUnsorted(ARRAY);
    cout << "Time taken by function: of size " << SIZE << "\n" << duration.count() << " microseconds" << endl;
    
    SIZE = 100;
    ARRAY=fillArray(ARRAY);
    start = high_resolution_clock::now();
    ARRAY = mergeAndSelect(ARRAY);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    //printUnsorted(ARRAY);
    cout << "Time taken by function: of size " << SIZE << "\n" << duration.count() << " microseconds" << endl;
    
    SIZE = 1000;
    ARRAY=fillArray(ARRAY);
    start = high_resolution_clock::now();
    ARRAY = mergeAndSelect(ARRAY);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    //printUnsorted(ARRAY);
    cout << "Time taken by function: of size " << SIZE << "\n" << duration.count() << " microseconds" << endl;
    
    SIZE = 10000;
    ARRAY=fillArray(ARRAY);
    start = high_resolution_clock::now();
    ARRAY = mergeAndSelect(ARRAY);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    //printUnsorted(ARRAY);
    cout << "Time taken by function: of size " << SIZE << "\n" << duration.count() << " microseconds" << endl;
    
    SIZE = 20000;
    ARRAY=fillArray(ARRAY);
    start = high_resolution_clock::now();
    ARRAY = mergeAndSelect(ARRAY);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    //printUnsorted(ARRAY);
    cout << "Time taken by function: of size " << SIZE << "\n" << duration.count() << " microseconds" << endl;
    
    SIZE = 100000;
    ARRAY=fillArray(ARRAY);
    start = high_resolution_clock::now();
    ARRAY = mergeAndSelect(ARRAY);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    //printUnsorted(ARRAY);
    cout << "Time taken by function: of size " << SIZE << "\n" << duration.count() << " microseconds" << endl;
    return 0;
}

std::vector<int> mergeAndSelect(std::vector<int>unsorted){
    if(unsorted.size() == 1){
        return unsorted;
    }
    
    std::vector<int>left;
    std::vector<int>right;
    std::copy(std::begin(unsorted), std::begin(unsorted) + unsorted.size()/2, std::back_inserter(left));
    std::copy(std::begin(unsorted) + unsorted.size()/2, std::end(unsorted), std::back_inserter(right));
    
    
    int m = SIZE+1/2;
    
    if(m == 7){
       return unsorted = selectionSort(unsorted, SIZE);
    } else{
        left = mergeAndSelect(left);
        right = mergeAndSelect(right);
    }
    return mergeSelect(left, right);
}

std::vector<int> mergeSelect(std::vector<int>left, std::vector<int>right){
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
    array.resize(SIZE);
    std::cout << "Size of array (n) is " << SIZE << std::endl;
    for(int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % (4 * SIZE) + 1;
    }
    
    return array;
}

void printUnsorted(std::vector<int>array)
{
    for(int i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << std::endl;
    }
}
