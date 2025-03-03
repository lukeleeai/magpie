///dit me set

///tao xai Fenwick Tree



#include "stdc++.h"

using namespace std;

const int maxN = 1e5 + 5;



int n;

int a[maxN * 3];

int64_t f[maxN * 3], g[maxN * 3];

map<pair<int, int>, int> pos;



int cnt[maxN * 3];

int64_t fwt[maxN * 3];



void upd(int idx, int64_t val) {

    for(; idx < 3 * maxN; idx += idx & -idx) {

        fwt[idx] += val;

        cnt[idx] += 1;

    }

}



pair<int64_t, int> sum(int idx) {

    int64_t total = 0;

    int bar = 0;

    for(; idx > 0; idx -= idx & -idx) {

        total += fwt[idx];

        bar += cnt[idx];

    }

    return {total, bar};

}



pair<int64_t, int> sum(int l, int r) {

    auto rr = sum(r);

    auto ll = sum(l - 1);



    return {rr.first - ll.first, rr.second - ll.second};

}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);



    cin >> n;



    int counter = 0;



    vector<pair<int, int> > vv;



    for(int i = 1; i <= 3 * n; i++) {

        cin >> a[i];

        vv.emplace_back(a[i], i);

    }



    sort(vv.begin(), vv.end());



    for(auto p : vv)

        pos[p] = ++counter;



    int64_t pre = 0;



    for(int i = 1; i <= 2 * n; i++) {

        upd(pos[{a[i], i}], a[i]);

        pre += a[i];

        int64_t curSum = pre;



        if(i >= n) {

            int k = i - n;



            if(k) {

                int lo = 1, hi = 3 * maxN - 1;

                while(lo <= hi) {

                    int mid = (lo + hi) / 2;

                    auto curPair = sum(1, mid);

                    if(curPair.second > k) {

                        hi = mid - 1;

                    } else if(curPair.second < k) {

                        lo = mid + 1;

                    } else {

                        curSum -= curPair.first;

                        break;

                    }

                }

            }



            f[i] = curSum;

        }

    }



    for(int i = 0; i < 3 * maxN; i++)

        fwt[i] = cnt[i] = 0;



    int64_t suf = 0;

    for(int i = 3 * n; i > n; i--) {

        upd(pos[{a[i], i}], a[i]);

        suf += a[i];

        int64_t curSum = suf;



        if(i <= 3 * n - n + 1) {

            int k = 3 * n - n + 1 - i;

            if(k) {

                int lo = 1, hi = 3 * maxN - 1;

                while(lo <= hi) {

                    int mid = (lo + hi) / 2;

                    auto curPair = sum(mid, 3 * maxN - 1);

                    if(curPair.second > k) {

                        lo = mid + 1;

                    } else if(curPair.second < k) {

                        hi = mid - 1;

                    } else {

                        curSum -= curPair.first;

                        break;

                    }

                }

            }



            g[i] = curSum;

        }

    }



    int64_t ans = -1e18;

    for(int i = n; i <= n + n; i++) {

        ans = max(ans, f[i] - g[i + 1]);

    }



    cout << ans << '\n';



    return 0;

}
