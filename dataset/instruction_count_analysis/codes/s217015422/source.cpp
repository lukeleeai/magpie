#include "stdc++.h"



using namespace std;

typedef long long ll ;

const int N =  1e5 ;

int main()

{

    vector<int>primes;

    int vis[100001];

    memset(vis , 0 , sizeof vis);

    for(int i =2 ; i <= N ; i++)

    {

        if(!vis[i])

        {

            primes.push_back(i);

            for(int j = i+i ; j <= N ;j+=i)

            {

                vis[j]=1;

            }

        }

    }

    primes.push_back(100003);

    ll n;

    cin >> n;

    cout << *lower_bound(primes.begin(),primes.end(),n) ;

    return 0;

}
