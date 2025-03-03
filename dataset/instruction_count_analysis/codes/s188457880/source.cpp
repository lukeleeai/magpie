#include"stdc++.h"

using namespace std;

int main()

{

    char c[100][100];

    int a[100][100]={0},n,m;

    cin>>n>>m;

    for(int i=0;i<n;i++)

        for(int j=0;j<m;j++)

        {

            cin>>c[i][j];

            if(c[i][j]=='#')

            {

                a[i][j]=-10;

                if(i-1>=0&&j-1>=0) a[i-1][j-1]++;

                if(i-1>=0) a[i-1][j]++;

                if(j-1>=0) a[i][j-1]++;

                if(i+1<n&&j-1>=0) a[i+1][j-1]++;

                if(i-1>=0&&j+1<m) a[i-1][j+1]++;

                if(i+1<n&&j+1<m) a[i+1][j+1]++;

                if(i+1<n) a[i+1][j]++;

                if(j+1<m) a[i][j+1]++;

            }

        }

    for(int i=0;i<n;i++)

    {

        for(int j=0;j<m;j++)

        {

        	if(c[i][j]!='#') cout<<a[i][j];

            else cout<<"#";

        }

        cout<<endl;

    }

    return 0;

}