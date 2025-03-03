#include"stdc++.h"

using namespace std;int64_t k,t=1,n;int S(int64_t x){int s=0;while(x)s+=x%10,x/=10;return s;}int main(){cin>>k;while(n+=t,cout<<n<<endl,--k)while((n+t)*S(n+t+t)>S(n+t)*(n+t+t))t*=10;}
