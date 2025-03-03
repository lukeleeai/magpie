#include <iostream>

#include <cstdio>

#include <algorithm>

#include <vector>

#include <stack>

#include <queue>

#include <map>

#include <set>

#include <string>

#include <cstring>

#define ll long long

#define rep(x,n) for(ll (x)=0;(x)<n;(x)++)

#define rep1(x,n) for(ll (x)=1;(x)<=n;(x)++)

using namespace std;



char s[300005],book[300005];



int main()

{

    #ifdef LOCAL

        freopen("B_data","r",stdin);

    #endif

    while(cin>>s)

    {

        ll len=strlen(s),cnt=0,l=0,r=2;

        memset(book,0,sizeof(book));

        rep(i,len)

        {

            if(!i || i==(len-1) || book[i]) continue;

            while(l && book[l]) l--;

            while(r<=i || (r<len && book[r])) r++;

            if(s[l]!=s[r])

            {

                cnt++,book[i]=1;

                //cout<<s[i];

                i-=2;

            }

        }

        //cout<<endl;

        if(cnt%2) cout<<"First"<<endl;

        else cout<<"Second"<<endl;

    }

    return 0;

}
