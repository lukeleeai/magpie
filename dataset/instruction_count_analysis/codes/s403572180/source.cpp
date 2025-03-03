#include <iostream>

#include <algorithm>

using namespace std;



long long d[10],v[10];



void compute(int n){

    for(int i = 2 ; i <= min(d[n],v[n]) ; i++){

        if(d[n]%i==0||v[n]%i==0){

            while(d[n]%i==0&&v[n]%i==0){

                d[n] /= i;

                v[n] /= i;

            }

        }

    }

}



int main(){

    int n;

    

    while(cin >>n,n){

        long long a,b;

        for(int i = 0 ; i < n ; i++){

            cin >> d[i] >> v[i];

            compute(i);

        }

        

        a = (d[0]*d[1])/__gcd(d[0],d[1]);

        b = __gcd(v[0],v[1]);

        

        for(int i = 2 ; i < n ; i++){

            a = (a*d[i])/__gcd(a,d[i]);

            b = __gcd(b,v[i]);

        }



        for(int i = 0 ; i < n ; i++){

            cout << a*v[i]/(b*d[i]) << endl;

        }

    }

    

    return 0;

}