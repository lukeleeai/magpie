#include "stdc++.h"

using namespace std;

long long n;



int main()

{

    ios::sync_with_stdio(false);

    cin.tie(0);

    long long n;

    cin>>n;

    string ans;

    while(n--){

        ans=(char)(n%26+'a')+ans;

        n/=26;

    }

    cout<<ans;

}