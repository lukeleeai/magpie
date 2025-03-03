#include "stdc++.h"

#define mod 1000000007



using namespace std;

long long n,k,total;

struct matrice

{

    vector < vector<long long>> t;

    matrice()

    {

        t.resize(n, vector<long long>(n));

    }



    matrice operator* (const matrice &b)

    {

        matrice ans = matrice();

        for(int i=0; i<n; i++)

            for(int j=0; j<n; j++)

                for(int k=0; k<n; k++)

                {

                    ans.t[i][k] += (t[i][j]*b.t[j][k])%mod;

                    ans.t[i][k] %= mod;

                }

        return ans;

    }

};

int main()

{

    cin>>n>>k;

    vector<vector<long long>> can(n, vector<long long>(n));

    for(int i=0; i<n; i++)

        for(int j=0; j<n; j++)

            cin>>can[i][j];



    matrice ans = matrice();

    for(int i=0; i<n; i++)

        ans.t[i][i]=1;



    matrice m = matrice();

    for(int i=0;i<n;i++)

        for(int j=0;j<n;j++)

            m.t[i][j]=can[i][j];



    while(k)

    {

        if(k%2)

        {

            ans=ans * m;

        }

        m = m*m;

        k/=2;

    }



    for(int i=0; i<n; i++)

        for(int j=0; j<n; j++)

        {

            total += ans.t[i][j];

            total %= mod;

        }



    cout<<total;

    return 0;

}
