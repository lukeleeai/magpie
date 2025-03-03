#include<iostream>

using namespace std;

const int MAX = 100000, mod = 1e9+7;

int A[MAX];

int main(){

    int n, maxi = 0;

    long long sum = 1;

    cin >> n;

    A[0] = 3;

    

    for (int i = 0; i < n; i++)

    {

        int a;

        cin >> a;

        sum = (sum * A[a]) % mod;

        A[a]--;

        A[a+1]++;

    }

    cout << sum << endl;

}