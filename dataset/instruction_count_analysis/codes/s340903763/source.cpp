#include "stdc++.h"



using namespace std;



typedef long long ll;

typedef pair<ll,int> ii;

ll L;

vector<int> arr;

vector<ii> sums;



struct sum {

    vector<ll> data;

    sum(vector<int>& arr) {

        data.resize(arr.size());

        data[0] = arr[0];

        for(int i = 1; i < (int)arr.size(); ++i)

            data[i] = data[i - 1] + ((ll)arr[i]);

    }

    ll query(int i, int j) {

        return !i ? data[j-1] : data[j-1] - data[i - 1];

    }

};



bool ok() {

    sum s(arr);

    set<int> limits;

    limits.insert(0);

    limits.insert(arr.size());

    set<int>::iterator it;

    for(int i = 0; i < (int)sums.size(); ++i) {

        s.query(4, 2);

        it = (limits.lower_bound(sums[i].second+1));

        int l = *(--it);

        int r = *(limits.upper_bound(sums[i].second+1));

        ll sum = s.query(l, r);

        if(sum < L) return false;

        limits.insert(sums[i].second+1);

    }

    return true;

}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(NULL);

    int N;

    ii mini = ii(0,-1);

    cin >> N >> L;

    arr.resize(N);

    for(auto& c: arr) cin >> c;

    for(int i = 1; i < (int)arr.size(); ++i) {

        mini = max(mini, ii(arr[i - 1] + arr[i],i-1));

    }

        sums.push_back(mini);

    ll sus = mini.first;

    for( int i = mini.second-1 ; i >= 0 ; i-- )

    {

        sus += ((ll)arr[ i ]);

        sums.push_back(ii(sus, i ));

    }

    sus = mini.first;

    for( int i = mini.second+2 ; i < (int)arr.size() ; ++i )

    {

        sus += ((ll)arr[ i ]);

        sums.push_back(ii(sus,i-1));

    }

    sort(sums.rbegin(), sums.rend());

    if(mini.first < L ) cout << "Impossible" << '\n';

    else {cout << "Possible\n";for(int i = 0; i < (int)sums.size(); ++i)

        cout << 1 + sums[i].second << '\n';

    }

    return 0;

}
