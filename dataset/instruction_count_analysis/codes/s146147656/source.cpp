#include "stdc++.h"

using namespace std;



typedef long long int ll;

typedef pair<ll, ll> pll;



#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))

#define REP(i, n) FOR(i, n, 0)

#define OF64 std::setprecision(10)



const ll MOD = 1000000007;

const ll INF = (ll)1e15;



struct Vertex

{

    vector<int> node;

};



Vertex V[100005];

ll C[100005];

bool U[100005];

ll A[100005];



int main()

{

    ll N;

    cin >> N;

    REP(i, N - 1)

    {

        ll a, b;

        cin >> a >> b;

        a--;

        b--;

        V[a].node.push_back(b);

        V[b].node.push_back(a);

    }

    REP(i, N)

    {

        cin >> C[i];

    }

    sort(C, C + N);



    if (N == 1)

    {

        cout << 0 << endl;

        cout << C[0] << endl;

        return 0;

    }

    else if (N == 2)

    {

        cout << std::min(C[0], C[1]) << endl;

        cout << C[0] << " " << C[1] << endl;

        return 0;

    }

    queue<int> q;



    int k = 0;

    REP(i, N)

    {

        if (V[i].node.size() > 1)

        {

            k = i;

            break;

        }

    }



    q.push(k);

    int index = N - 1;

    while (!q.empty())

    {

        int t = q.front();

        q.pop();

        if (U[t])

            continue;

        A[t] = C[index--];

        U[t] = true;

        REP(i, V[t].node.size())

        {

            int n = V[t].node[i];

            if (U[n])

                continue;

            q.push(n);

        }

    }



#if false

    REP(i, N)

    {

        if (V[i].node.size() == 1)

            q.push(i);

    }



    int index = 0;

    while (!q.empty())

    {

        int t = q.front();

        q.pop();

        if (U[t])

            continue;

        A[t] = C[index++];

        U[t] = true;

        REP(i, V[t].node.size())

        {

            int n = V[t].node[i];

            if (U[n])

                continue;

            q.push(n);

        }

    }

#endif



    ll M = 0;

    memset(U, 0, sizeof(U));

    q.push(0);

    U[0] = true;

    while (!q.empty())

    {

        ll t = q.front();

        q.pop();

        REP(i, V[t].node.size())

        {

            int n = V[t].node[i];

            if (U[n])

                continue;

            M += std::min(A[n], A[t]);

            U[n] = true;

            q.push(n);

        }

    }



    cout << M << endl;

    REP(i, N)

    {

        cout << A[i] << " ";

    }

    cout << endl;

    return 0;

}