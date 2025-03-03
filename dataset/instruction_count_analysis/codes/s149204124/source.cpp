#define _USE_MATH_DEFINES

#include "stdc++.h"

using namespace std;



//template

#define rep(i,a,b) for(int i=(a);i<(b);i++)

#define rrep(i,a,b) for(int i=(a);i>(b);i--)

#define ALL(v) (v).begin(),(v).end()

typedef long long int ll; typedef pair<ll, ll> P;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<typename A,size_t N,typename T>void Fill(A(&array)[N],const T &val){fill((T*)array, (T*)(array+N), val);}

const int inf = INT_MAX / 2; const ll INF = LLONG_MAX / 2;

//template end







int main(){

    int n,k; scanf("%d%d",&n,&k);

    vector<int> a(n);

    rep(i,0,n)scanf("%d",&a[i]);

    set<int> st;

    rep(i,0,k)st.insert(a[i]);

    int ans=1,cnt=0,nosort=0;

    rep(i,1,n){

        if(a[i-1]<a[i])cnt++; else cnt=0;

        if(cnt==k-1)nosort++;

    }

    rep(i,k,n){

        st.erase(a[i-k]);

        if(*st.begin()<a[i-k]||*st.rbegin()>a[i])ans++;

        st.insert(a[i]);

    }

    printf("%d\n",ans-max(nosort-1,0));

    return 0;

}