#include "stdc++.h"

using namespace std;

using ll = long long;

const int mod = 1e9 + 7;

const int inf = (1 << 30) - 1;

const ll infll = (1LL << 61) - 1;



#include "stdc++.h"

using namespace std;



string to_string(string s)

{

    return '"' + s + '"';

}



string to_string(const char *s)

{

    return to_string((string)s);

}



string to_string(bool b)

{

    return (b ? "true" : "false");

}



template <typename A, typename B>

string to_string(pair<A, B> p)

{

    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";

}



template <typename A>

string to_string(A v)

{

    bool first = true;

    string res = "{";

    for (const auto &x : v)

    {

        if (!first)

        {

            res += ", ";

        }

        first = false;

        res += to_string(x);

    }

    res += "}";

    return res;

}



void debug_out() { cerr << endl; }



template <typename Head, typename... Tail>

void debug_out(Head H, Tail... T)

{

    cerr << " " << to_string(H);

    debug_out(T...);

}



ll N, ans = infll, sum;



int main()

{

    cin >> N;

    vector<ll> A(N + 2), cnt;

    A[0] = 0;

    for (int i = 1; i <= N; i++)

    {

        cin >> A[i];

        sum += abs(A[i] - A[i -1]);

    }

    sum += abs(A[N + 1] - A[N]);

    A[N + 1] = 0;

    cnt.push_back(A[0]);

    for (int i = 1; i <= N; i++)

    {

        cout << sum - abs(A[i - 1] - A[i]) - abs(A[i + 1] - A[i]) + abs(A[i - 1] - A[i + 1]) << endl;

    }

}