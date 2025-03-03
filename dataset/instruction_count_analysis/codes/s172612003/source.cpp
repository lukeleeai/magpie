  //Keep Working Hard

  // I__Like__Food  

  #include"stdc++.h"

  #include <ext/pb_ds/assoc_container.hpp> 

  #include <ext/pb_ds/tree_policy.hpp>

  #define rep(i,a,b) for(int i = a; i <=b; i++)

  #define rep2(i,a,b) for(int i = a; i>=b; i--)

  #pragma GCC optimize("O3")

  #pragma GCC optimize("Ofast") 

  #pragma GCC optimize("unroll-loops")

  using namespace std;

  using namespace __gnu_pbds;

  #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  #define endl "\n"

  #define int long long

  #define all(v) v.begin(),v.end()

  #define PB push_back

  #define MP make_pair

  #define double long double

  #define trace1(x)                cerr<<#x<<": "<<x<<endl

  #define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl

  #define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl

  #define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl

  #define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl

  #define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

  #define cases int testcases;cin>>testcases; while(testcases--)

  const int mod = 1e9 + 7;

  const int N = 200005;

  const int INF = 1e16;

  const double PI = acos(-1);







vector<int> adj[N];

    int bvis[N];



int dist[N];



void bfs(int u)

{



    queue<int> q;

    q.push(u);

    dist[u] = 0;

    while(q.size())

    {

        u = q.front(), q.pop();

        for(int &v : adj[u])

        {

            if(!bvis[v])

            {

                dist[v] = dist[u] + 1;

                bvis[v] = 1;

                q.push(v);

            }

        }

    }

}



int ans[N];



int32_t main()

{

       



    IOS





    int n,x,y;

    cin >> n >> x >> y;





    for(int i = 1; i <= n-1; i++)

    {

      adj[i].PB(i+1);

      adj[i+1].PB(i);

    }



    adj[x].PB(y);

    adj[y].PB(x);





    set<pair<int,int>> s;

    map<int,int> mp;



    for(int i = 1; i <= n; i++)

    {

      bfs(i);

      dist[i] = 0;

      for(int j = 1; j <= n; j++)

      {

        int xx = i;

        int yy = j;

        if(xx > yy)swap(xx,yy);

        if(!s.count({xx,yy}))

        {

            mp[dist[yy]]++; 

            s.insert({xx,yy});         

        }

        bvis[j] = false;

        dist[j] = 0;

      }





    }



    for(auto i : mp)

    {



      //trace2(i.first,i.second);

      if(i.first >=1 and i.first <= n - 1)

        {

          ans[i.first] = i.second;

        }

    }

  

    for(int i = 1; i <= n-1; i++)cout << ans[i] << endl;





    // bfs(4);



    // for(int i = 1; i <= n; i++)

    // {

    //   cout << dist[i] << endl;

    // }





  return 0;

} 