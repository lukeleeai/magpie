#include"stdc++.h"

using namespace std;

string s="";

int main(){



    ios::sync_with_stdio(false);

    cin.tie(0);



    long long n;

    cin>>n;

    while(n--){

        s=char(n%26+'a')+s;

        n/=26;

    }



    cout<<s;

}
