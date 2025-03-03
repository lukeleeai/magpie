#include <cstdio>

#include <cstring>

#include <iostream>

using namespace std;



const int maxn=100;

char a[maxn][maxn],b[maxn][maxn];



int main()

{

	int n,m;

	while(scanf("%d%d",&n,&m)!=EOF)

	{

		for(int i=0;i<n;i++)

		    scanf("%s",&a[i]);

		for(int i=0;i<m;i++)

		    scanf("%s",&b[i]);

		int flag=1;

        for(int i=0;i<n;i++)

        {

            for(int j=0;j<n;j++)

            {

 

                if(a[i][j]==b[0][0])

                {

                    flag=0;

                    for(int x=0;x<m;x++)

                    {

                        for(int y=0;y<m;y++)

                        {

                            if(a[i+x][j+y]!=b[x][y])

                            {

                                flag=1;

                                break;

                            }

                        }

                    }

                } 

                if(flag==0)

                    break;  

            }

            if(flag==0)

                break;

        }

        if(flag==0)

            cout << "Yes" << endl;

        else

            cout << "No" << endl;

	}

	return 0;

}