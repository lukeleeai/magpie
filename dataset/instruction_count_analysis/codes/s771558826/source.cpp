#include"stdc++.h"

using namespace std;

#define ll unsigned long long int

ll ar[500009],br[500009],fr[500009];

string s1,s2,s3[200005];

map<string,int>mp;

int main()

{

    ll i,j,k,e,r,n,s,d,f,g,h,u,ck=0,ck1=0,t;

    cin >> n;

    g=0;

    for(i=1; i<=n; i++)

    {

        cin >> s3[i];

    sort(s3[i].begin(),s3[i].end());

    mp[s3[i]]++;

    if(mp[s3[i]]>1)

    {



        g+=mp[s3[i]]-1;

    }

    }

//    for(i=1;i<n;i++)

//    {

//        for(j=i+1;j<=n;j++)

//        {

//            if(s3[i]==s3[j])

//            {

//                g++;

//            }

//        }

//    }

    cout << g << endl;

    return 0;

}

/*

2

greenbin

beginner

*/
