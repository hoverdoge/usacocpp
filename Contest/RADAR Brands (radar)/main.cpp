#include <iostream>

using namespace std;

long f_reverse(long number);

int main() {
    long brand; int counter = 1;
    cin >> brand;

    while(true)
    {
        // reverses brand
        long reverse = f_reverse(brand);
        // adds
        brand += reverse;
        // checks for palindrome
        if (brand == f_reverse(brand))
        {
            cout << counter << " " << brand << endl;
            break;
        }
        counter++;
    }
}


long f_reverse(long number)
{
    long final = 0;

    while (number > 0)
    {
        final = final * 10 + number % 10;
        number /= 10;
    }

    return final;
}