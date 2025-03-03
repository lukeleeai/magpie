/*

#include"stdc++.h"

#define rep(i,a,b) for(int i=a;i<=b;i++)

#define ll long long

#define midl (l+r)>>1 

const int maxn=1e6+7;

using namespace std;

int n,l,r,mid,arc[maxn];

bool check(int pp)

{

	if (arc[n]<=pp&&arc[n+1]<=pp) return 1;

	if (arc[n]<=pp&&arc[n-1]<=pp) return 1;

	if (arc[n]>pp&&arc[n+1]>pp) return 0;

	if (arc[n]>pp&&arc[n-1]>pp) return 0;

	rep(i,1,n) 

	 {

	 	if (arc[n+i]<=pp&&arc[n+i+1]<=pp) return 1;

	    if (arc[n-i]<=pp&&arc[n-i-1]<=pp) return 1;

     	if (arc[n+i]>pp&&arc[n+i+1]>pp) return 0;

    	if (arc[n-i]>pp&&arc[n-i-1]>pp) return 0;

	 }

}

int main(){

	scanf("%d",&n);

	rep(i,1,(n<<1)-1) 

	 scanf("%d",&arc[i]);

	for (r=(n<<1)-1,mid=l+r>>1;l<r;mid=l+r>>1)//while(l<r) 

	 if (check(mid)==1) r=mid;

	 else l=mid+1;

	cout<<l;

	return 0;

}

*/

#include<stdio.h>

#define dn(i,j) (a[i]<=k && a[j]<=k)

#define up(i,j) (k<a[i] && k<a[j])



int a[200005],n,l,r,mid;



inline bool judge(const int &k)

{

    if (dn(n-1,n) || dn(n,n+1)) return 1;

    if (up(n-1,n) || up(n,n+1)) return 0;

    for (int i=1;i<n-1;i++)

    {

        if (dn(n+i,n+i+1) || dn(n-i,n-i-1)) return 1;

        if (up(n+i,n+i+1) || up(n-i,n-i-1)) return 0;

    }

    return dn(1,1);

}



int main()

{

    scanf("%d",&n);

    for (int i=1;i<n<<1;i++) scanf("%d",a+i);

    for (r=(n<<1)-1,mid=l+r>>1;l<r;mid=l+r>>1) if (judge(mid)) r=mid;else l=mid+1;

    printf("%d",l);

}