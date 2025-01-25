#include<iostream>

#include<algorithm>

using namespace std;int*t,n,m,d,i,s[99999];main(){for(;cin>>d>>n>>m,s[i=n]=d;cout<<i<<'\n'){for(;--i;)cin>>s[i];for(sort(s,s+n);m--;t=upper_bound(s,s+n,d),i+=min(d-*--t,*t-d))cin>>d;}}