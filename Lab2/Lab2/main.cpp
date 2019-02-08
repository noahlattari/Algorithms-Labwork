//
//  main.cpp
//  Lab2
//
//  Created by Noah Lattari on 2019-02-08.
//  Copyright © 2019 Noah Lattari. All rights reserved.
//

#include <iostream>
#include <cstdlib> // for rand and srand
#include <ctime> // for the time function
#include <fstream> //for output file
#include <vector>
#include <chrono>

using namespace std::chrono;
using namespace std;
int power(int *x, int *y);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
  
    int test = 4;
    int raised = 2;
    test = power(&test,&raised);
    cout << "Linear time: power(2,5) = "<< test << endl;
    

    
    return 0;

}

//power running in O(n) where n is the size of the power
int power(int *x, int *y){
    
    int result = 0;
    
    for(int i = 1; i <= *y; i++){
        result= *x * *x;
    }
    return result;
}
