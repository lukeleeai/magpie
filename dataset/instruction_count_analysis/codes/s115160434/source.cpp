 #include "stdc++.h"

    using namespace std;

    typedef long long ll;

    #define INPUT()              freopen("input.txt", "r", stdin)

    #define OUTPUT()             freopen("output.txt", "w", stdout)

    #define F                    first

    #define S                    second

//Templatefunctions

    template<typename T>T gcd(T x, T y) { if (y == 0)return x; else return gcd(y, x%y);}

    template <class T> T euclideanDistance(T x1 , T x2 , T y1 , T y2){return sqrt(( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 ));}

    template <class T> T digitSum(T n){T sum = 0;while(n > 0)sum += n % 10,n /= 10;return sum;}

//datatypes

    typedef long long int ll;

    typedef unsigned long long int ull;

    typedef long double ld;

//constants

    const double INF = 1e+9;

    const double INFLL = 1e+18;

    const double EPS = 1e-9;

    const double PI = acos(-1);

    const int knightDir[8][2] = {{-2,-1},{-2,1},{-1,2},{1,2},{2,-1},{2,1},{-1,-2},{1,-2}};

           //const int dx[]={0,0,0,1,1,1,-1,-1,-1};

           //const int dy[]={-1,0,1,-1,0,1,-1,0,1};

    const int dx[] = {0 , 1 , 0 , -1};

    const int dy[] = {1 , 0 , -1 , 0};

//helpers

    //#define MOD         1000000007LL

    #define MAX         2000005

    const ll MOD = 1000000000 + 7;

    //int arr[10000005];

    char str[MAX+10];

//Global Variables

    int dp[MAX],n;

    std::map<int,int>::iterator it;

    int ans;

    int main()

    {

//        int t;

//        scanf("%d",&t);

//        int x = 2;

//        while(t--)

//        {

//        }

        ll n , k;

        scanf("%lld%lld",&n,&k);



        for(int i = 0 ;i < n ; i++)

        {

            scanf("%d",&dp[i]);

        }

        vector<int> m,d;

        int cnt = 0, cnt2 = 0;

        for(int i = 0 ; i < n  ; i++)

        {

            for(int j = i+1 ; j < n ; j++)

            {

                if(dp[j] < dp[i])cnt++;

            }

            for(int j = 0 ; j < i ; j++)

            {

                if(dp[j] < dp[i])cnt2++;

            }

        }

        ll ans = 0;

        ll temp = (k * (k+1))/2L;

        temp -= k;

        temp = temp%MOD;

        //printf("temp-%lld\n",temp);

        ans += ((temp+k)*cnt)%MOD;

        ans += (temp*cnt2)%MOD;

        printf("%lld\n",ans%MOD);

    }

//
