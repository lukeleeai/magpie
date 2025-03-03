#include <iostream>

#include <utility>

#include <vector>

#include <algorithm>



using namespace std;



int main(void) {

    long long n,c,x[100000],v[100000],s[2][100001],m[2][100001],d[2][100001] = {0};

    cin >> n >> c;

    for(long long i = 0;i < n;i++)

        cin >> v[i] >> x[i];

    s[0][0] = 0;

    for(long long i = 1;i <= n;i++)

        s[0][i] = s[0][i-1] + x[i-1];

    for(long long i = 1;i <= n;i++)

        s[0][i] = s[0][i] - v[i-1];

    s[1][0] = 0;

    for(long long i = 1;i <= n;i++)

        s[1][i] = s[1][i-1] + x[n-i];

    for(long long i = 1;i <= n;i++)

        s[1][i] = s[1][i] - (c - v[n-i]);

    vector<pair<long long,long long>> p[2];

    for(long long i = 0;i <= n;i++) {

        p[0].push_back(make_pair(s[0][i], i));

        p[1].push_back(make_pair(s[1][i], i));

    }

    sort(p[0].begin(), p[0].end(),greater<pair<long long,long long>>());

    sort(p[1].begin(), p[1].end(),greater<pair<long long,long long>>());

    long long z = n;

    for(auto itr = p[0].begin();itr < p[0].end();itr++) {

        if(itr->second <= z) {

            for(long long i = itr->second;i <= z;i++) {

                m[0][i] = itr->first;

                if(i != 0 && itr->second != 0)

                    d[0][i] = v[itr->second - 1];

                else

                    d[0][i] = 0;

            }

            z = itr->second - 1;

        }

    }

    z = n;

    for(auto itr = p[1].begin();itr < p[1].end();itr++) {

        if(itr->second <= z) {

            for(long long i = itr->second;i <= z;i++) {

                m[1][i] = itr->first;

                if(i != 0 && itr->second != 0)

                    d[1][i] = c - v[n - itr->second];

                else

                    d[1][i] = 0;

            }

            z = itr->second - 1;

        }

    }

    

    long long retval = 0;

    for(long long i = 0;i <= n;i++) {

        retval = max(retval,m[0][i] + m[1][n-i] - min(d[0][i],d[1][n-i]));

        retval = max(retval,m[1][i] + m[0][n-i] - min(d[1][i],d[0][n-i]));

    }

    cout << retval << endl;

    return 0;

}
