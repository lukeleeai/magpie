/*|In The Name Of Allah|*/

//This Month Will Be Expert ISA

#include "stdc++.h"



using namespace std;



const int N = 1e6+7;



const int mod = 1e9+7;



int n;

int ar[N];



vector < int > primeFactors(long long num){

    vector < int > prm;

    while (num % 2 == 0){

        prm.push_back(2);

        num = num/2;

    }

    for (long long i = 3; i*i <= num; i = i + 2){

        while (num % i == 0){

            prm.push_back(i);

            num = num/i;

        }

    }

    if (num > 2)

        prm.push_back(num);

    return prm;

}



int mxF[N];



int fastP(int b, int e){

    if(!e)

        return 1;

    if(e & 1)

        return b * 1ll * fastP(b * 1ll * b % mod, e >> 1) % mod;

    return fastP(b * 1ll * b % mod, e >> 1) % mod;

}



int main(){

    scanf("%d" , &n);

    for(int i = 1; i <= n; i++){

        scanf("%d" , &ar[i]);

        map < int , int > cntF;

        vector < int > prmF = primeFactors(ar[i]);

        for(auto v : prmF){

            cntF[v]++;

        }

        for(auto v : cntF){

            mxF[v.first] = max(mxF[v.first] , v.second);

        }

    }

    int sum = 0;

    long long LCM = 1;

    for(int i = 1; i <= 1e6; i++){

        while(mxF[i]--){

            LCM = LCM * i % mod;

        }

    }

    for(int i = 1; i <= n; i++){

        sum = (sum + LCM * fastP(ar[i] , mod - 2)) % mod;

    }

    printf("%d\n" , sum);

}
