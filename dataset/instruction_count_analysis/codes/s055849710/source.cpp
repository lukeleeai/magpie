#include "stdc++.h"

using namespace std;



long long f(long long b,long long n)

{

    if(n==0) return 0;

    else if(n<b) return n;

    return f(b,n/b) + (n%b);

}

int main()

{

    long long m,s;

    cin >> m >> s;

    long long k=m-s;

    long long ans=1e12+7;

    if(k<0)

    {

        cout << "-1" << "\n";

        return 0;

    }

    else if(k==0)

    {

        cout << m+1 << "\n";

        return 0;

    }

    else

    {

        long long t=sqrt(k);

        for(long long i=1;i<=t;i++)

        {

            if(k%i==0)

            {

                if(f(i+1,m) == s) ans=min(ans,i+1);

                if(f((k/i)+1,m) == s) ans=min(ans,(k/i)+1);

            }

        }

    }

    if(ans==1e12+7)

        cout << "-1" << "\n";

    else

        cout << ans << "\n";

}
