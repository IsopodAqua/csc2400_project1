/*
File: cdgarrett42_project1.cpp
Author: Cole Garrett
Date: October 4th 2023 (date of correction, that is)
Description: To find the greatest common denominator of two integers by using either the extended euclidean algorithm or consecutive consecutive integer checking algorithm
*/
#include <iostream>
using namespace std;

int extendedEuclidean(int a, int b, int &x, int &y) //performs the extended euclidean algorithm
{
    if (b == 0) //base case
    {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedEuclidean(b, a % b, x1, y1); //recursion

    x = y1; //coefficients
    y = x1 - (a / b) * y1;

    return gcd;
}

int consecutiveInteger(int a, int b) //performs the consecutive integer checking algorithm
{
    int smaller = (a < b) ? a : b;
    int gcd = 1;

    for (int i = 1; i <= smaller; i++) 
    {
        if (a % i == 0 && b % i == 0) 
        {
            gcd = i;
        }
    }

    return gcd;
}

int* primeFactorization(int n, int& size) //finds prime factors of numbers, necessary for middle school procedure
{
    int* factors = new int[INT_MAX]; // let's hope it doesn't go above the int max
    int index = 0;
    
    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            factors[index++] = i;
            n /= i;
        }
    }

    size = index;
    return factors;
}

int middleSchool(int a, int b) //performs middle school procedure
{
    int sizeA, sizeB;
    int* factorsA = primeFactorization(a, sizeA); //prime factors need to be found first
    int* factorsB = primeFactorization(b, sizeB);

    int gcd = 1;
    int i = 0, j = 0;

    while (i < sizeA && j < sizeB)//iterates through the array analyzing common factors
    {
        if (factorsA[i] == factorsB[j]) //if a common factor is found, keeps proceeding to see if any are larger
        {
            gcd *= factorsA[i];
            i++;
            j++;
        } 
        else if (factorsA[i] < factorsB[j]) 
        {
            i++;
        } 
        else 
        {
            j++;
        }
    }

    delete[] factorsA;
    delete[] factorsB;

    return gcd;
}

int main()
{
    int a = 0; //i could have made this one line but i like having multiple lines, it looks clearer to me
    int b = 0;
    int g = 0;
    int x = 0; //x and y aren't really used since we're just finding the gcd, but they're a part of extended euclid's algorithm
    int y = 0;
    int choice = 0;

    cout << "Please insert the first number" << endl; //input section
    cin >> a;
    cout << "Please insert the second number" << endl;
    cin >> b;
    cout << "How would you like to find the GCD?" << endl;
    cout << "1) Extended Euclids Algorithm" << endl;
    cout << "2) Consecutive Integer Checking Algorithm" << endl;
    cout << "3) Middle School Procedure" << endl;

    while(choice != 1 && choice != 2 && choice != 3) //input validation
    {
        cin >> choice;
        if(choice != 1 && choice != 2 && choice != 3)
        {
            cout << "Invalid input, try again." << endl;
        }
    }
    
    if(choice == 1) //do what they say on the tin
    {
        if(a == 0 && b == 0)
        {
            cout << "gcd("<<a<<","<<b<<") = undefined"; //in case of both being zero
        }
        else
        {
            g = extendedEuclidean(abs(a), abs(b), x, y); //abs is used here to make negative numbers positive
            cout << "gcd("<<a<<","<<b<<") = "<< g; 
        }
    }

    if(choice == 2)
    {
        if(a == 0 && b == 0)
        {
            cout << "gcd("<<a<<","<<b<<") = undefined"; //in case of both being zero and abs is used here to make negative numbers positive
        }
        else if (a == 0 && b != 0)
        {
            cout << "gcd("<<a<<","<<b<<") = "<< abs(b); //in case of one being zero and abs is used here to make negative numbers positive
        }
        else if (b ==0)
        {
            cout << "gcd("<<a<<","<<b<<") = "<< abs(a); //in case of one being zero and abs is used here to make negative numbers positive
        }    
        else
        {
            g = consecutiveInteger(abs(a),abs(b)); //abs is used here to make negative numbers positive
            cout << "gcd("<<a<<","<<b<<") = "<< g;
        }
    }

    if(choice == 3)
    {
        if(a == 0 && b == 0)
        {
            cout << "gcd("<<a<<","<<b<<") = undefined"; //in case of both being zero and abs is used here to make negative numbers positive
        }
        else if (a == 0 && b != 0)
        {
            cout << "gcd("<<a<<","<<b<<") = "<< abs(b); //in case of one being zero and abs is used here to make negative numbers positive
        }
        else if (b ==0)
        {
            cout << "gcd("<<a<<","<<b<<") = "<< abs(a); //in case of one being zero and abs is used here to make negative numbers positive
        }    
        else
        {
            g = middleSchool(abs(a),abs(b)); //abs is used here to make negative numbers positive
            cout << "gcd("<<a<<","<<b<<") = "<< g;
        }
    }

    return 0;
}