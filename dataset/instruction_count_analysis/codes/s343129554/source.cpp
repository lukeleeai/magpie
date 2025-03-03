#include "stdc++.h"

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long int ll;

typedef pair<int, int> P;



int n;

P sec[101010];



int main()

{

    cin >> n;

    rep(i, n)

    {

        int x, l;

        cin >> x >> l;

        sec[i].first = x + l;

        sec[i].second = x - l;

    }

    sort(sec, sec + n);



    int res = 0, pos = -1000000001;

    rep(i, n)

    {

        if(pos <= sec[i].second)

        {

            pos = sec[i].first;

            res++;

        }

    }

    cout << res << endl;



    return 0;

}