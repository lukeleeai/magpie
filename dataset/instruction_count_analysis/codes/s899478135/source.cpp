#include <iostream>

#include <vector>

#include <string>

#include <algorithm>

#include <stdio.h>

#include <cmath>

using namespace std;



int to_int(string s){

    int number = 0;

    for(int i=0;i<s.size();i++){

        number *= 10;

        number += s[i] - '0';

    }

    return number;

}



string to_str(int n){

    string s;

    while(n!=0){

        s += n % 10 + 48;

        n /= 10;

    }

    reverse(s.begin(),s.end());

    return s;

}



bool isLeapYear(int year)

{

    if(((year % 4 == 0 ) && (year % 100 != 0)) || (year % 400 == 0))

        return true;

    else

        return false;

}



bool isPrime(int n)

{

    if (n == 2)

        return true;

    if ((n & 1)==0)

        return false;

    for (int i = 3; i*i <= n;i+=2) {

        if (n%i == 0)

            return false;

    }



    return true;

}



/*#define row 5001

#define col 10000



int arr[row][col];



void fib()

{

    arr[0][0] = 0;

    arr[1][0] = 1;

    for(int i=2;i<row;i++){

        for(int j=0;j<col;j++){

            if(arr[i-1][j] + arr[i-2][j] == 0)

                continue;

            arr[i][j] += arr[i-1][j] + arr[i-2][j];

            if(arr[i][j] > 9){

                arr[i][j+1] = arr[i][j]/10;

                arr[i][j] %= 10;

            }

        }

    }

}*/



int main()

{

    int a, b, c;

    cin >> a >> b >> c;

    if((b-a) == (c-b))

        cout << "YES" << endl;

    else

        cout << "NO" << endl;



    return 0;

}
