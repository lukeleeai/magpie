#include "stdc++.h"



#define M_PI 3.14159265358979323846



using namespace std;



//typedef

//-------------------------#include "stdc++.h"



#define M_PI 3.14159265358979323846



using namespace std;



//conversion

//------------------------------------------

inline int toInt(string s)

{

    int v;

    istringstream sin(s);

    sin >> v;

    return v;

}

template <class T>

inline string toString(T x)

{

    ostringstream sout;

    sout << x;

    return sout.str();

}

inline int readInt()

{

    int x;

    scanf("%d", &x);

    return x;

}



//typedef

//------------------------------------------

typedef vector<int> VI;

typedef vector<VI> VVI;

typedef vector<string> VS;

typedef pair<int, int> PII;

typedef pair<int, PII> TIII;

typedef long long LL;

typedef unsigned long long ULL;

typedef vector<LL> VLL;

typedef vector<VLL> VVLL;



//container util



//------------------------------------------

#define ALL(a) (a).begin(), (a).end()

#define RALL(a) (a).rbegin(), (a).rend()

#define PB push_back

#define MP make_pair

#define SZ(a) int((a).size())

#define SQ(a) ((a) * (a))

#define EACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)

#define EXIST(s, e) ((s).find(e) != (s).end())

#define SORT(c) sort((c).begin(), (c).end())



//repetition

//------------------------------------------

#define FOR(i, s, n) for (int i = s; i < (int)n; ++i)

#define REP(i, n) FOR(i, 0, n)

#define MOD 1000000007



#define rep(i, a, b) for (int i = a; i < (b); ++i)

#define trav(a, x) for (auto &a : x)

#define all(x) x.begin(), x.end()

#define sz(x) (int)(x).size()



typedef long long ll;

typedef pair<int, int> pii;

typedef vector<int> vi;

const double EPS = 1E-8;



#define chmin(x, y) x = min(x, y)

#define chmax(x, y) x = max(x, y)

const int INF = 2147483647;



const int dxy[5] = {-1, 0, 1, 0, -1};

int main()

{

    cin.tie(0);

    ios::sync_with_stdio(false);

    //cout << fixed << setprecision(10);



    int H, W;

    cin >> H >> W;



    vector<string> f;

    queue<pair<int, int>> q;



    vector<vector<int>> d(H, vector<int>(W, -1));

    for (int i = 0; i < H; i++)

    {

        string s;

        cin >> s;

        f.push_back(s);

        for (int j = 0; j < W; j++)

        {

            if (s[j] == '#')

            {

                q.push({i, j});

                d[i][j] = 0;

            }

        }

    }



    int ans = 0;

    while (q.size())

    {

        pair<int, int> p = q.front();

        q.pop();



        int y = p.first, x = p.second;

        for (int i = 0; i < 4; i++)

        {

            int ny = y + dxy[i], nx = x + dxy[i + 1];

            if (ny >= 0 && ny < H && nx >= 0 && nx < W && d[ny][nx] == -1)

            {

                d[ny][nx] = d[y][x] + 1;

                ans = max(ans, d[ny][nx]);

                q.push({ny, nx});

            }

        }

    }

    cout << ans << endl;



    return 0;

}
