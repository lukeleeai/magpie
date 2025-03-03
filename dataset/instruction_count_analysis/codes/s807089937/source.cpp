#include"stdc++.h"

using namespace std;



#define LL long long

#define LD long double

#define Mod 1000000007

#define L_Mod 17100000013



const double eps = 1e-9;

const int INF = 0x3f3f3f3f;

const double PI = 3.1415926535;



#define NO_TLE std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);



#define ree(a,n) memset(a,n,si 2)



#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))

#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))

#define red(i,l,u) for(int (i)=(int)(l);(i)>=(int)(u);--(i))





int main()

{

    LL n,m,M4=0,M2=0;

    cin>>n;

    LL  a[100002]= {0};

    for(int i=0; i<n; i++)

        cin>>a[i];

    for(int i=0; i<n; i++)

    {

        if(a[i]%4==0)

            M4++;

        else if(a[i]%2==0)

            M2++;

    }

    M2=M2/2*2;

    if(M4*2+1+M2>=n)

        cout<<"Yes";

    else

        cout<<"No";

}
