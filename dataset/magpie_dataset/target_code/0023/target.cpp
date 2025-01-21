#include "stdc++.h"

using namespace std;

#define ll	    long long

#define vi      vector <int>

#define vii     vector <pair<int,int>>

#define ii      pair<int,int>

#define loop(n)	for(int i=0;i<n;i++)

ll mod=1e9+7;

bool is_prime(int n)

{

    if(n==2)

        return true;

    if(n%2==0||n<2)

        return false;

    for(int i=3; i<=sqrt(n); i+=2)

    {

        if(n%i==0)

            return false;

    }

    return true;

}

long long power(ll n, ll k){

    if(k==0) return 1;

    ll sq=(power(n,k/2))%mod;

    sq=(sq*sq)%mod;

    if(k%2==1)

        sq=(sq*n)%mod;

    return sq%mod;

}

void low(char &c){

c=tolower(c);

}

void primeFactors(int n)

{

    while (n % 2 == 0)

    {

        cout << 2 << " ";

        n = n/2;

    }



    for (int i = 3; i <= sqrt(n); i = i + 2)

    {

        while (n % i == 0)

        {

            cout << i << " ";

            n = n/i;

        }

    }



    if (n > 2)

        cout << n << " ";

}



#include <iostream>

using namespace std;

void fast();

int arr[100005];

map <int,int> M;

int main() {

//fast();

int n,m,ch;

string s;

cin >> n >> m;

int AC=0,WA=0;

loop(m){

    cin >> ch >> s;

    if(arr[ch]!=-1){

       if(s=="WA"){

            arr[ch]++;

        }else{

            AC++;

            WA += arr[ch];

            arr[ch]=-1;

        }

    }



}

cout << AC << " " << WA;

}











void fast(){

std::ios_base::sync_with_stdio(0);

    cin.tie(NULL);

    cout.tie(NULL);



}
