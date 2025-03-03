#include <iostream>

#include <utility>

#include <algorithm>

using namespace std;

int c[500010],last[500010],ans[500010];

pair<pair<int,int>,int> p[500010];

int n,seg[1000010];

void update(int p,int val){

    for(seg[p += n] = val;p>1;p>>=1){

        seg[p>>1] = seg[p] + seg[p^1];

    }

}



int query(int l,int r){

    int res = 0;

    for(l += n,r += n; l<r;l>>=1,r>>=1){

        if(l&1) res += seg[l++];

        if(r&1) res += seg[--r];

    }

    return res;

}



int main(){

    int i,q; cin >> n >> q;

    for(i=0;i<n;i++){

        cin >> c[i]; c[i]--; last[i] = -1;

    }

    for(i=0;i<q;i++){

        int l,r; cin >> l >> r; l--; r--;

        p[i] = {{r,l},i};

    }

    sort(p,p + q);

    int r = 0;

    for(i=0;i<q;i++){

        pair<int,int> pp = p[i].first;

        while(r<=pp.first){

            if(last[c[r]]!=-1) update(last[c[r]],0);

            update(r,1);

            last[c[r]] = r; r++;

        }

        ans[p[i].second] = query(pp.second,pp.first + 1);

    }

    for(i=0;i<q;i++) cout << ans[i] << endl;

}