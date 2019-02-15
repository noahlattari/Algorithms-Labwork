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
float lgpower(float x, int y);


int main(int argc, const char * argv[]) {
    
    int test = 4;
    int raised = 2;
    cout << "Linear time: power(4,2) = "<< power(&test,&raised) << endl;
    float x = 12;
    float y = -5;
    cout << "Linear time: power(12,-5) = "<< lgpower(x,y) << endl;
    

    
    return 0;

}

//power running in O(n) where n is the size of the power
int power(int *x, int *y){
    if(*y == 0){
        return 1;
        //corner case since power of 0 is always 1
    }
    int result = 0;
    
    for(int i = 1; i <= *y; i++){
        result= *x * *x;
    }
    return result;
}

float lgpower(float x, int y)
{
    float temp;
    if( y == 0){
        return 1;
    }
    
    temp = lgpower(x, y/2);
    
    if (y%2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
}
