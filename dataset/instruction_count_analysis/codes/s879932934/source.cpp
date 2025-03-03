#include <iostream>

#include <iomanip>

#include <algorithm>

#include <array>

#include <cassert>

#include <utility>

#include <vector>



struct Bit{

    const int n;

    std::vector<int> data;

    Bit(const int n):n(n){ data.assign(n + 1, 0); }

    void add(int idx, int val = 1){

        for(; idx <= n; idx += idx & -idx) data[idx] += val;

    }

    int sum(int idx) const {

        int res = 0;

        for(; idx > 0; idx -= idx & -idx) res += data[idx];

        return res;

    }

};





int main(void){

    std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); 

    std::cout << std::fixed << std::setprecision(16);



    int n, q; std::cin >> n >> q;

    std::vector<int> A(n); for(int i = 0; i < n; ++i){ std::cin >> A[i]; --A[i]; }



    Bit BIT(n);

    std::vector<int> lastAppend(n, 0);

    std::vector<int> res(q);



    std::vector<std::array<int, 3>> Query(q);

    for(int i = 0; i < q; ++i){

        int l, r; std::cin >> l >> r;

        Query[i][0] = r;

        Query[i][1] = l;

        Query[i][2] = i;

    }

    std::sort(Query.begin(), Query.end());



    for(int r = 1, idx = 0; r <= n; ++r){

        const int color = A[r - 1];

        if(lastAppend[color] != 0) BIT.add(lastAppend[color], -1);

        lastAppend[color] = r; BIT.add(r, 1);

        while(idx < q and Query[idx][0] == r){

            // [l, r] 1-indexedで

            res[Query[idx][2]] = BIT.sum(r) - BIT.sum(Query[idx][1] - 1);

            ++idx;

        }

    }

    for(int i = 0; i < q; ++i){

        std::cout << res[i] << '\n';

    }







    

    return 0;

}