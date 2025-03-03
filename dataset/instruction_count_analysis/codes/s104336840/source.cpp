#include<iostream>

#include<algorithm>

#include<vector>

using namespace std;

const int N=1e5+10;

typedef long long LL;



vector<int> v[N];

int a[N];

int b[N];



int dp[1<<15];



int main()

{

    int n,m;

    cin>>n>>m;

    for(int i=1;i<=m;i++)

    {

        cin>>a[i];

        int c;

        cin>>c;

        for(int j=1;j<=c;j++)   

        {

            int u;

            cin>>u;

            u--;

            b[i]|=(1<<u);

        }

        //cout<<b[i]<<endl;

    }





    for(int i=1;i<=m;i++)

    {

        int u=b[i];



        for(int j=0;j<(1<<n);j++)

        {

            if(j==0||dp[j])

            {

                if(dp[u|j])

                {

                    dp[u|j]=min(dp[u|j],dp[j]+a[i]);

                }

                else

                {

                    dp[u|j]=dp[j]+a[i];

                }

            }

        }

    }



    if(dp[(1<<n)-1])

        cout<<dp[(1<<n)-1]<<endl;

    else

        cout<<-1<<endl;

    



    

    //system("pause");

}