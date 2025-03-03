#include<iostream>

#define rep(i,n)for(int i=0;i<n;i++)

#define l int64_t

using namespace std;l q,x,y,f[99]={0,1},m=1e9+7;main(){cin>>q;rep(i,97)f[i+2]=f[i]+f[i+1];rep(i,q){cin>>x>>y;if(x>y)swap(x,y);if(y<=2){cout<<1<<" "<<(y==1?1:x==1?2:4)<<" ";continue;}rep(j,99){if(x<f[j]||y<f[j+1]){l a=x==1?2:1;rep(k,j-2){l n=f[j-1]+f[j-3-k]*f[k+2],m=f[j]+f[j-2-k]*f[k+2];if(n<=x&&m<=y)a+=(y-m)/n+1;}if(f[j]<=x){a++;rep(k,j-2)a+=(x-f[j])/(f[j-2-k]*f[k+2]);}cout<<j-2<<" "<<a%m<<" ";j=99;}}}}