#include "stdc++.h"

using namespace std;

const int N=2e5+5;

string A[N];

int n;

long long sum,mem[N];

long long fact(int i){

    if(!i) return 1;

    if(mem[i]!=-1) return mem[i];

    return mem[i]=fact(i-1)*i*1ll;

}

long long ans(int i){

if(i<=1) return 0;

if(i==2) return 1;

return fact(i)/(fact(i-2)*2);

}

long long spdAns(int i){

    if(i<=1) return 0;

    if(i==2) return 1;

    long long ret=1;

    ret=1ll*i*(i-1) / 2;

    return ret;

}

map<string,int> mp;

int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    memset(mem,-1,sizeof mem);

    cin>>n;

    for(int i=0;i<n;++i){

        cin>>A[i];

        sort(A[i].begin(),A[i].end());

        mp[A[i]]++;

    }

    long long ze=0;

    map<string,int>::iterator it = mp.begin();

    while(it!=mp.end()){

        

        ze+=spdAns(it->second);

        it++;

    }

    /*sort(A,A+n);

    int re=1;

    string cur=A[0];

    for(int i=1;i<=n;++i){

       if(cur!=A[i]){

        sum+=ans(re);

      //  cout<<re<<endl;

        re=0;

        cur=A[i];

       }

       re++;

    }*/



    cout<<ze<<endl;

    return 0;

}
