#include<cstdio>

#include<cstring>

#include<algorithm>

#include<iostream>

#include<string>

#include<vector>

#include<stack>

#include<bitset>

#include<cstdlib>

#include<cmath>

#include<set>

#include<list>

#include<deque>

#include<map>

#include<queue>

#define LL long long

using namespace std;

bool binarysearch(int a[],int n,int q){

int left=0,right=n,mid;

while(left<right){

mid=(left+right)/2;

if (q==a[mid]){return true;}

else if (q>a[mid]){left=mid+1;}

else if (q<a[mid]){right=mid;}

}

return false;

}

int main(){

int i,n1,n2,q,a[100009],sum=0;

cin>>n1;

for (i=0;i<n1;i++){cin>>a[i];}

cin>>n2;

for (i=0;i<n2;i++){cin>>q;

if (binarysearch(a,n1,q)){sum++;}

}

cout<<sum<<endl;

return 0;

}
