#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;  // 0 and 1 are not prime
    }

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;  // num is divisible by i, so it's not prime
        }
    }

    return true;  // num is prime
}

// Function to check if a number is a circular prime
bool isCircularPrime(int num) {
    int temp = num;
    int numDigits = 0;

    while (temp > 0) {
        temp /= 10;
        ++numDigits;
    }

    temp = num;

    for (int i = 0; i < numDigits; ++i) {
        if (!isPrime(temp)) {
            return false;
        }

        int lastDigit = temp % 10;
        temp = lastDigit * (int)pow(10, numDigits - 1) + temp / 10;
    }

    return true;
}

// Function to check if a number is a safe prime
bool isSafePrime(int num) {
    int safeNum = (num - 1) / 2;
    return isPrime(num) && isPrime(safeNum);
}

int main() {
    int lowerLimit, upperLimit;

    // Get the range from the user
    printf("Enter the lower limit: ");
    scanf("%d", &lowerLimit);

    printf("Enter the upper limit: ");
    scanf("%d", &upperLimit);

    printf("Prime numbers in the range %d to %d:\n", lowerLimit, upperLimit);

    for (int i = lowerLimit; i <= upperLimit; ++i) {
        if (isPrime(i)) {
            printf("%d is a regular prime.\n", i);

            if (isCircularPrime(i)) {
                printf("   and a circular prime.\n");
            }

            if (isSafePrime(i)) {
                printf("   and a safe prime.\n");
            }
        }
    }

    return 0;
}
