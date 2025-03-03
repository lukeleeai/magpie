#include<iostream>

using namespace std;

#define m long long

#define d(s,i,n) for(m i=s;i<n;i++)

#define z else

int main(){m n,a,b,o=1e9+7,x=90,l[x][x],r[x][x];cin>>n;d(0,i,x){l[i][0]=r[i][0]=1;d(1,j,x){if(i==j)r[i][j]=r[i][j-1]*2+l[i][j-1];z r[i][j]=r[i][j-1]+l[i][j-1];l[i][j]=r[i][j-1];}}d(0,i,n){cin>>a>>b;if(b>a)swap(a,b);m k=0;d(0,j,x)if(a>=r[0][j]&&b>=l[0][j])k=j;m g;if(k==0)k=1,g=1;z if(k==1)if(b==1)g=a;z g=4;z{g=1;if(b>=r[0][k]&&a>=l[0][k]&&l[0][k]<r[0][k])g++;d(1,j,k+1)if(r[j][k]<=a&&l[j][k]<=b)g+=1+(a-r[j][k])/l[j][k];d(1,j,k+1)if(r[j][k]<=b)g+=1+(b-r[j][k])/l[j][k];}cout<<k<<" "<<g%o<<" ";}}