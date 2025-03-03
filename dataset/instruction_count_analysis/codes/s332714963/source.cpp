#include"stdc++.h"

using namespace std;

typedef long long ll;



#define         pb         push_back

#define         sf(x)      scanf("%d",&x)

#define         sfl(x)     scanf("%lld",&x)

#define         pf(x)      printf("%d\n",x)

#define         pfl(x)     printf("%lld\n",x)

#define         endl       '\n'

#define         pii        pair<int,int>

#define         mapii      map<int,int>

#define         mapll      map<ll,ll>

#define         mapci      map<char,int>

#define         mapcl      map<char,ll>

#define         mapsi      map<string,int>

#define         mapsl      map<string,ll>

#define         pll        pair<ll,ll>

#define         vi         vector<int>

#define         vl         vector<ll>

#define         vd         vector<double,double>

#define         all(c)     c.begin(),c.end()

#define         F          first

#define         S          second

#define         mp         make_pair

#define        ftc(x)      cerr << #x << ": " << x << " " << endl;

#define         PI         acos(-1)

#define         lcm(a,b)   ((a*b)/__gcd(a,b))

#define        optimize    ios_base::sync_with_stdio(false);cin.tie(NULL);

#define        sqr(a)       ((a)*(a))

#define MAX 2009

int dx[]= {0,0,1,-1};

int dy[]= {1,-1,0,0};



int n,m,k;



int  valid(int x,int y)

{

    if((x>=0 && x<n) && (y>=0 && y<m) )

    {

        return 1;

    }

    return 0;

}



int main()

{

    int i,j,l,r;



    cin >> n >> m >> k;



    int dis[n+10][m+10];

    char s[n+10][m+10];

    int vis[n+10][m+10];





    int x1,x2,y1,y2;



    cin >> x1 >> y1 >> x2 >> y2;

    x1--,x2--,y1--,y2--;





    for(i=0; i<n; i++)

    {

        for(j=0; j<m; j++)

        {

            cin >> s[i][j];

            vis[i][j] = 0;

            dis[i][j]= 200000000;

        }

    }



    queue<pii>q;



    dis[x1][y1] = 0;



    q.push({x1,y1});

    int paise = 0;

    while(!q.empty())

    {

        pii pp = q.front();



        q.pop();



        if(vis[pp.F][pp.S])continue;



        vis[pp.F][pp.S] = 1;



        for(i=0; i<4; i++)

        {



            for(j=1; j<=k; j++)

            {

                int x,y;





                x = pp.F + dx[i]*j;

                y = pp.S + dy[i]*j;



                if(!valid(x,y) || s[x][y] == '@' || dis[x][y]<=dis[pp.F][pp.S])break;





                if(dis[x][y] > (1 + dis[pp.F][pp.S]))dis[x][y] = 1 + dis[pp.F][pp.S],q.push({x,y});

            }



        }





    }





    if(dis[x2][y2] != 200000000)cout << dis[x2][y2] << endl;

    else cout << -1 << endl;





}
