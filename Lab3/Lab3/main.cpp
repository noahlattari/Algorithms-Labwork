#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


long multiply4(string num1, string num2)
{
    int n1 = num1.size();
    int n2 = num2.size();
    if (n1 == 0 || n2 == 0)
        return 0;

    vector<int> result(n1 + n2, 0);
    
    // Below two indexes are used to find positions
    // in result.
    int i_n1 = 0;
    int i_n2 = 0;
    
    // Go from right to left in num1
    for (int i=n1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';
        
        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0;
        
        // Go from right to left in num2
        for (int j=n2-1; j>=0; j--)
        {
            // Take current digit of second number
            int n2 = num2[j] - '0';
            
            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position.
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
            
            // Carry for next iteration
            carry = sum/10;
            
            // Store result
            result[i_n1 + i_n2] = sum % 10;
            
            i_n2++;
        }
        
        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
        
        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }
    
    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
        i--;
    
    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
        return 0;
    
    // generate the result string
    string s = "";
    
    while (i >= 0)
        s += std::to_string(result[i--]);
    
    long finished =  stol(s, nullptr, 10);
    return finished;
}

int getLength(long value) {
    int counter = 0;
    while (value != 0) {
        counter++;
        value /= 10;
    }
    return counter;
}

long multiply3(string n1, string n2)
{
    long number1 = std::stol (n1,nullptr,10);
    long number2 = std::stol (n2,nullptr,10);
    int n1Length = getLength(number1);
    int n2Length = getLength(number2);
    
    int N = (int)(fmax(n1Length, n2Length));
    
    if (N < 10)
        return number1 * number2;
    
    N = (N/2) + (N%2);
    
    long multiplier = pow(10, N);
    
    long b = number1/multiplier;
    long a = number1 - (b * multiplier);
    long d = number2 / multiplier;
    long c = number2 - (d * N);
    
    long z0 = multiply3(std::to_string(a), std::to_string(c));
    long z1 = multiply3(std::to_string(a) + std::to_string(b), std::to_string(c) + std::to_string(d));
    long z2 = multiply3(std::to_string(b), std::to_string(d));
    
    return z0 + ((z1 - z0 - z2) * multiplier) + (z2 * (long long)(pow(10, 2 * N)));
}


int main()
{
  
    cout << "Traditional Multiplication: " << multiply4("1234", "4321") << endl;
    cout << "Karatsuba Multiplication: " << multiply3("1234", "4321") << endl;
    
    cout << "Traditional Multiplication: " << multiply4("110", "220") << endl;
    cout << "Karatsuba Multiplication: " << multiply3("110", "220") << endl;
    
    cout << "Traditional Multiplication: " << multiply4("14589", "912") << endl;
    cout << "Karatsuba Multiplication: " << multiply3("14589", "912") << endl;
    
    cout << "Traditional Multiplication: " << multiply4("7777777", "88888888") << endl;
    cout << "Karatsuba Multiplication: " << multiply3("7777777", "88888888") << endl;
    
    return 0;
   
}
