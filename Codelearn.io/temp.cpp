#include <iostream>
using namespace std;

int main()
{
    // declare integer numbers
    int randomNumber;
    bool isPrime;
    // input from stdin
    cin >> randomNumber;

    // find the maximum prime number less than randomNumber
    do
    {
        --randomNumber;
        isPrime = true;
        for (int i = 2; i < randomNumber; i++)
        {
            if (randomNumber % i == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            printf("%d\n", randomNumber);
            break;
        }
    } while (randomNumber >= 2);
    cout << randomNumber;
}