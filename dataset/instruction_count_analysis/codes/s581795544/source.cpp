#include "stdc++.h"



using namespace std;

#define ll long long

const int N=2e5+5;

int a[N];

bool ball[N];

int main()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);cout.tie(0);

    int l,r;

    set<int>st;

    cin>>l>>r;

    st.insert(l%2019);

    int ans=1e9;

    for(int i=l+1;i<=r;i++){

        for(auto x:st)

            ans=min(ans,x*(i%2019)%2019);

        if(ans==0)

            return cout<<ans<<endl,0;

        st.insert(i%2019);

    }

    cout<<ans<<endl;

    return 0;

}
