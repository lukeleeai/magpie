#include "stdc++.h"



using namespace std;



bool cmp(pair<int,int>A, pair<int,int>B){

    if(A.second == B.second)

       return  A.first < B.first;

    return A.second < B.second;

}

int main(){

    int n, m;

    vector < pair<int,int> > v(m);

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++){

        int a, b;

        scanf("%d %d", &a, &b);

        v.push_back(make_pair(a, b));

    }

    sort(v.begin(),v.end(), cmp);

    int ans = 1;

    int cur = v[0].second;

    for (int i = 1; i < m; i++){

        if (v[i].first >= cur){

            ans++;

            cur = v[i].second;

        }

    }

    printf("%d\n", ans);

    return 0;

}
