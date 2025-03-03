#include "stdc++.h"

using namespace std;

using lint = long long int;

#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)

#define REP(i, n) FOR(i,0,n)



vector<int> makePrimeLst(int N)

{

    if (N < 2) return vector<int>();

    if (N == 2) return vector<int>{2};

    vector<int> ans;

    vector<int> alive(N+1, 1);

    for (int i=2; (long long)i*i<=(long long)N; i++)

    {

        if (alive[i]) ans.push_back(i);

        for (int t = i; t<=N; t += i) alive[t] = 0;

    }

    for (int i=ans.back()+1; i<=N; i++) if (alive[i]) ans.push_back(i);

    return ans;

}



constexpr int Nmax = 501;

lint ans[Nmax][Nmax];



int main()

{

    vector<int> info = makePrimeLst(10000);



    vector<lint> p, q;

    int now = 2;

    while (p.size() < Nmax + 1)

    {

        p.insert(p.begin(), info[now++]);

        q.insert(q.begin(), info[now++]);

        p.push_back(info[now++]);

        q.push_back(info[now++]);

    }



    int N;

    cin >> N;

    REP(i, N) REP(j, N)

    {

        int u = (i + j) / 2, v = (i + (Nmax - 1 - j)) / 2;

        cout << (((i + j) & 1) ? p[u + 1] * q[v + 1] : p[u] * p[u + 1] * q[v] * q[v + 1] + 3) << (j == N - 1 ? "\n" : " ");

    }

}
