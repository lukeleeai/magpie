#include "stdc++.h"

using namespace std;



#define pb push_back

#define mp make_pair

#define f first

#define s second

#define int long long

#define double long double

typedef long long ll;

typedef pair<int,int> pii;

#define MAXN 1123456

#define INF LLONG_MAX

#define MOD 32416187567

#define cte 10002

#define MAX ULLONG_MAX



pair<int,pii> v[112345];





int32_t main(){

    ios::sync_with_stdio(false);

    cin.tie(0);

    cout.precision(11);

    cout.setf(ios::fixed);



    int n;

    cin>>n;



    for(int i=0;i<n;i++){

        cin>>v[i].f>>v[i].s.f>>v[i].s.s;

    }



    sort(v,v+n);



    int dis=abs(v[0].s.s)+abs(v[0].s.f);

    //cout<<dis<<endl;

    if(dis>v[0].f || (v[0].f-dis)%2==1){

        cout<<"No"<<endl;

        return 0;

    }





    for(int i=1;i<n;i++){

        int dis=abs(v[i].s.s-v[i-1].s.s)+abs(v[i].s.f-v[i-1].s.f);

        //cout<<dis<<endl;

        if(dis>v[i].f-v[i-1].f || ((v[i].f-v[i-1].f)-dis)%2==1){

            cout<<"No"<<endl;

            return 0;

        }

    }



    cout<<"Yes"<<endl;

    return 0;



}








