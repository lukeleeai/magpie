#include <iostream>

#include <vector>

#include <set>

#include <algorithm>



using namespace std;



bool DEBUG = false;



long long int gcd(long long int a, long long int b){ 

    if (a == 0) 

        return b;  

    return gcd(b % a, a);  

 } 

 

 long long int lcm(long long int a, long long int b)  

 {  

    return (a*b)/gcd(a, b);  

 }



int main(){

    long long int a, b, c, d;

    cin >>a >>b >>c >>d;

    //for(long long int i=a; i<=b; i++){

    //    if(i%c > 0 && i%d > 0){

    //        cnt++;

    //    }

    //}

    long long int n = b-a+1;

    long long int lcmOfCD = lcm(c,d);

    long long int multiplesInRange = b/c - (a-1)/c + b/d - (a-1)/d;

    long long int repeatedMultiplesInRange = b/lcmOfCD - (a-1)/lcmOfCD;

    if(DEBUG){

        cout <<"lcm of c and d is " <<lcmOfCD <<endl;

        cout <<n <<" numbers in range" <<endl;

        cout <<b/c <<" multiples of " <<c <<" up to " <<b <<endl;

        cout <<(a-1)/c <<" multiples of " <<c <<" up to exc " <<a <<endl;

        cout <<b/c - (a-1)/c <<" multiples of " <<c <<" in range " <<endl <<endl;

        

        cout <<b/d <<" multiples of " <<d <<" up to " <<b <<endl;

        cout <<(a-1)/d <<" multiples of " <<d <<" up to exc " <<a <<endl;

        cout <<b/d - (a-1)/d <<" multiples of " <<d <<" in range " <<endl <<endl;

        

        cout <<multiplesInRange <<" multiples in range" <<endl <<endl;

        

        cout <<b/lcmOfCD <<" common multiples up to " <<b <<endl;

        cout <<(a-1)/lcmOfCD <<" common multiples up to exc " <<a <<endl;

        cout <<repeatedMultiplesInRange <<" repeated multiples in range" <<endl <<endl;

        

        cout <<"guess inc commons = " <<n - multiplesInRange  <<endl;

        cout <<"guess exc commons = " <<n - multiplesInRange + repeatedMultiplesInRange <<endl;

    }

    cout <<n - multiplesInRange + repeatedMultiplesInRange <<endl;

}