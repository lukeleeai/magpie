#include <iostream>

#include <stdio.h>

#include <string>

using namespace std;



int main()

{



    char s[100] ;

    cin >> s ;

    int i , j , x , rs = 1;

    for (i = 0 ; i <100 ; i++){

        if (s[i] == '\0')

            break;

    }



    x= i;

    for (i=0 , j=x-1  ; i<x && j>0  ; i++ , j--){

        if(s[i] != s[j])

            rs++;

    }





    cout << rs/2 << endl ;



}
