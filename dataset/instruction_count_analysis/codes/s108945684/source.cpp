#include <iostream>

#include <iomanip>

typedef long long ll;

using namespace std;

const  ll INF = 1e9;

const  ll MOD = 1e9 + 7;

#define repi(i,n,init) for(ll i=init;i<(n);i++)



int main()

{

    int x;

    cin >> x;

    repi(i,x+1,1){

        if(int(i * 1.08) == x){

            cout << i << endl;

            return 0;

        }

    }

    cout << ":(" << endl;

    return 0;

}