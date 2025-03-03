#include "stdc++.h"



using namespace std;



int main() {

    std::ios::sync_with_stdio(false);

    string s;

    cin>>s;

    long n=s.length();

    long ans=0;

    int a;

    if(s[0]=='W' )

        a=0;

    else

        a=1;

    for(long i=0;i<n;i++){

        if(s[i]=='W' && a==1){

            a=0;

            ans+=1;

        }

        else if(s[i]=='B' && a==0){

            a=1;

            ans+=1;

        }

    }

    cout<<ans;

    return 0;

}
