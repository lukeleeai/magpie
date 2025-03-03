#include<cstdio>  

#include<iostream>  

#include<algorithm>  

#include<cstdlib>  

#include<cstring>

#include<string>

#include<climits>

#include<vector>

#include<cmath>

#define LL long long



using namespace std;



int wt,ss[19];

inline void print(int x){

	if (x<0) x=-x,putchar('-'); 

	if (!x) putchar(48); else {for (wt=0;x;ss[++wt]=x%10,x/=10);for (;wt;putchar(ss[wt]+48),wt--);}

}

inline void print(LL x){

	if (x<0) x=-x,putchar('-');

	if (!x) putchar(48); else {for (wt=0;x;ss[++wt]=x%10,x/=10);for (;wt;putchar(ss[wt]+48),wt--);}

}



 int n,a[100010];



int main()

{

	cin>>n;

    int x=0,y=0,ans=0;

    memset(a,0,sizeof(a));

    while(n--)

    {

        cin>>y;

        if(a[y]) x++;else a[y]++,ans++;

    }

    if(x%2) ans--;

    cout<<ans<<endl;

}