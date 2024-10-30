#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int GetSum(long cardNumber);
long GetMaxLoops(long cardNumber);
int DigitCheck(int index, int digit);
int GetLength(long cardNumber);
int GetFirstDigit(long cardNumber);
int GetSecondDigit(long cardNumber);
string CardValidator(long cardNumber);
int CheckSum (long cardNmber);

int main(void)
{
    long cardNumber = get_long("Card Number: ");
    string result = CardValidator(cardNumber);
    //long result = CheckSum(cardNumber);
    printf("result: %s\n", result);

}

string CardValidator(long cardNumber)
{

    int length = GetLength(cardNumber);
    int firstDigit = GetFirstDigit(cardNumber);
    int secondDigit = GetSecondDigit(cardNumber);
    int sumLastDigit = CheckSum(cardNumber);
    string result = "invalid";

    if (sumLastDigit == 0)
    {
        if (length == 15 && firstDigit == 3 && (secondDigit == 4 || secondDigit == 7))
        {
            result = "American Express";
        }
        else if ((length == 16 || length == 13) && firstDigit == 4)
        {
            result = "Visa";
        }
        else if (length == 16 && firstDigit == 5 && (secondDigit < 6 && secondDigit > 0 ))
        {
            result = "Master Card";
        }
    }
    return result;
}

int CheckSum(long cardNumber) // returns last digit of the sum
{
    int sum = GetSum(cardNumber);
    int sumLastDigit = sum % 10;
    return sumLastDigit;
}

int GetFirstDigit(long cardNumber) // returns first digit of the card number
{
    long maxLoops = GetMaxLoops(cardNumber);
    int firstDigit = (cardNumber % maxLoops) / (maxLoops/10);
    return firstDigit;
}

int GetSecondDigit(long cardNumber) // returns second digit of the card number
{
    long maxLoops = GetMaxLoops(cardNumber);
    int secondDigit = (cardNumber % (maxLoops/10)) / (maxLoops/100);
    return secondDigit;
}

int GetSum(long cardNumber) // returns the total sum of the each digit according to Luhn's Algorithm
{
    long maxLoops = GetMaxLoops(cardNumber);
    int index = 1;
    int sumLastDigit = 0;
    int sum = 0;
    int digit;
    for (long i = 10; i <= maxLoops; i = i * 10)
    {
        digit = (cardNumber % i) / (i/10); // can i remove this?
        sum = sum + DigitCheck(index, digit);
        index++;
    }
    return sum;
}

long GetMaxLoops(long cardNumber) // returns max loops to fill in second argument of the for loop
{
    int length = GetLength(cardNumber);
    long maxLoops = pow(10, length);
    return maxLoops;
}

int DigitCheck(int index, int digit) // returns the right value of each digit for the sum
{
        int sum = 0;
        int subSum = 0;
        if (index % 2 == 0)
        {
            subSum = digit * 2;
            if (subSum < 10)
            {
                sum = subSum;
            }
            else
            {
                sum = (subSum % 10) + (subSum % 100 / 10);
            }
        }
        else
        {
            sum = digit;
        }
        return sum;
}

int GetLength(long cardNumber) // returns card number length
{
    int length = 0;

    for (long i = cardNumber; i > 0; i = i/10)
    {
        length++;
    }
    return length;
}
