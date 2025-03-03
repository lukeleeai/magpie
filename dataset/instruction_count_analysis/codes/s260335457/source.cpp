#include <iostream>

#include <cstdio>

#include <cmath>

#include <vector>

#include <map>

#include <stack>

#include <queue>

#include <algorithm>

#include <set>



#define FOR(i,a,b) for(int i=(a);i<(b);i++)

#define REP(i,j) FOR(i,0,j)

#define mp std::make_pair



const int INF = 1 << 24;

const int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};



typedef unsigned long long ull;

typedef std::pair<int,int> P;



int main(){

    int n, S;

    int r[10000];

    while(std::cin >> n >> S, n){

        REP(i, n){

            std::cin >> r[i];

        }

        std::sort(r, r+n);

        int res = 0;

        for(int i=0;i+1<n;i++){

            auto it = std::upper_bound(r+i+1, r+n, S-r[i]);

            res += std::distance(it, r+n);

        }

        std::cout << res << std::endl;

    }

}