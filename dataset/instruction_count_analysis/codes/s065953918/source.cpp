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

    multiset<int>st;

    int n;

    cin>>n;

    for(int i=0;i<n;i++)

        cin>>a[i],st.insert(a[i]);

    for(int i=0;i<n;i++)

    {

       st.erase(st.find(a[i]));

       cout<<*st.rbegin()<<'\n';

       st.insert(a[i]);

    }

    return 0;

}
