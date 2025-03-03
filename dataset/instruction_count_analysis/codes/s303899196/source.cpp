#include "stdc++.h"

#define pan(i,n) for(int i=0;i<n;i++)

#define ll long long int

#define vi vector<int>

#define pb push_back

#define INF 1e9+7

#define inf 100001

#define PI 3.141592653

using namespace std; 



int main(){

    int n;

    cin>>n;

    vi v,p;

    pan(i,n){int x;

        cin>>x;

        if(i%2==0) v.pb(x);

        else p.pb(x);

    }

    int o=0,o1=-1,e=0,e1=-1,x[inf],y[inf];

    memset(x,0,sizeof(x));

    memset(y,0,sizeof(y));

    for(int i=0;i<v.size();i++) x[v[i]]++;

    int ce=*max_element(x,x+inf);

    e=distance(x,max_element(x,x+inf));

    x[e]=0;

    int ce1=*max_element(x,x+inf);

    e1=distance(x,max_element(x,x+inf));

    pan(i,p.size()) y[p[i]]++;

    int co=*max_element(y,y+inf);

    o=distance(y,max_element(y,y+inf));

    y[o]=0;

    int co1=*max_element(y,y+inf);

    o1=distance(y,max_element(y,y+inf));

    int ans=0;

    if(o!=e) ans=n-co-ce;

    else{

        ans=min(n-co-ce1,n-co1-ce);

    }

    cout<<ans;

} 