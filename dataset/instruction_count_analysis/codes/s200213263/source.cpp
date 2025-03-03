// lcmとかはg++ -std=c++17 default.cppみたいなかんじで



#include "stdc++.h"

#define mod 1000000007

#define INF 1001001001

#define ll long long

#define ln cout<<endl

#define Yes cout<<"Yes"<<endl

#define No cout<<"No"<<endl

#define double long double

#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)

#define rep(i,n) REP(i,0,n)

#define rep1(i,n) REP(i,1,n+1)

using namespace std;

bool my_compare(pair<ll, ll> a, pair<ll , ll> b) {

    // 基本はfirstで比較

    if(a.first != b.first){

         return a.first < b.first; // 昇順

        //return a.first > b.first; // 降順

    }



    // それ以外はsecondで比較

    if(a.second != b.second){

        return a.second > b.second;

    }else{

        // どちらも同じ

        return true;

    }

}



int main() {

    cin.tie(0);

   	ios::sync_with_stdio(false);



    ll a,b,m,n,maxi=0,f=0,mini=INF,sum=0;

    string str,sub;

    ll h,w;

    string str1;

    cin>>h>>w;

    

    if(w<h) {

        mini=0;

    }

    if(h==0||w==0) mini=0;

    for(ll i=h;i<w;i++){

        for(ll j=i+1;j<=w;j++){

            

        mini=min(mini,(i*j)%2019);

            if(mini==0) {

              cout<<0<<endl;

            return 0;

            }

        }

    }



    cout<<mini<<endl;



    return 0;

}
