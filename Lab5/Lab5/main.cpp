#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <array>
int canBook(int arrive[], int leave[], int rooms);
int main(int argc, const char * argv[]) {
    
    // Booking 1 arrives on the 1st and leaves on the 2nd // Booking 2 arrives on the 3rd and leaves on the 6th // etc.
    // You may wish to try some of your own examples
    int arrive_dates [] = { 1, 3, 5, 6, 6 };
    int leave_dates[] = { 2, 6, 8, 7, 8 };
    int n = 3;
    int res;
    int a;
    int b;
    
    for(int i = 0; i < 5; i++)
    {
        for(int j = i + 1; j < 5; j++)
        {
            if(leave_dates[i] > leave_dates[j])
            {
                a = leave_dates[i];
                leave_dates[i] = leave_dates[j];
                leave_dates[j] = a;
                
                b = arrive_dates[i];
                arrive_dates[i] = arrive_dates[j];
                arrive_dates[j] = b;
            }
        }
    }
    
    res = canBook(arrive_dates , leave_dates , n);
    std::cout << res << "\n";
    
    return 0;
    
}

int canBook(int arrive[], int leave[], int rooms)
{
    int n = 1;
    
    for(int i = 0; i < 4; i++)
    {
        if(leave[i] < arrive[i + 1])
        {
            n--;
        }
        else{
            n++;
        }
    }
    
    
    if(n > rooms){
        return 0;
    }
    
    else{
        return 1;
    }
    
}
