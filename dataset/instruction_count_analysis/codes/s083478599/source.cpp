/*g++ main.cpp -o main.out*/

/*./main.out*/



#include <map>

#include <set>

#include <list>

#include <cmath>

#include <ctime>

#include <deque>

#include <queue>

#include <stack>

#include <bitset>

#include <cctype>

#include <cstdio>

#include <string>

#include <vector>

#include <climits>

#include <cstdlib>

#include <cstring>

#include <fstream>

#include <iomanip>

#include <sstream>

#include <iostream>

#include <iterator>

#include <algorithm>

using namespace std;



#define LL long long

#define LD long double

#define Mod 1000000007

#define L_Mod 17100000013



const double eps = 1e-9;

const int INF = 0x3f3f3f3f;

const double PI = 3.1415926535;



#define NO_TLE std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);



#define ree(a,n) memset(a,n,sizeof(a));



#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))

#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))

#define red(i,l,u) for(int (i)=(int)(l);(i)>=(int)(u);--(i))



LL lcm(LL a,LL b)

{

    return a*b/__gcd(a,b);

}



LL a[100005];



int main()

{

    NO_TLE

    int n;

    cin>>n;

//    rep(i,n)cin>>a[i];

//    LL l=a[0];

//    rer(i,1,n-1)

//    {

//        LL t=__gcd(l,a[i]);

//        l=l/t*a[i];

//    }

//    LL sum=0;

//    l--;

//    rep(i,n)sum+=l%a[i];

//    cout<<sum<<endl;

    LL sum=0,x;

    while(n--)

    {

        cin>>x;

        sum+=x-1;

    }

    cout<<sum<<endl;

    return 0;

}