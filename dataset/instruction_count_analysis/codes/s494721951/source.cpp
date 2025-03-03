#include<iostream>

#include<stdio.h>

#include<cstring>

#include<algorithm>

using namespace std;

int main()

{

    int h,w;

    int n;

    int c[10090];

    cin>>h>>w>>n;

    int last=1;

    int map[103][103];

    for(int i=1;i<=n;i++)

    {

        cin>>c[i];

    }

    for(int i=0;i<h;i++)

    {

        if(i%2==0)

        {



            for(int j=0;j<w-1;j++)

            {

                if(c[last]--){map[i][j]=last;if(c[last]==0)last++;}

            }

            if(c[last]--){map[i][w-1]=last;if(c[last]==0)last++;}

        }

        else

        {

            for(int j=w-1;j>0;j--)if(c[last]--){map[i][j]=last;if(c[last]==0)last++;}

            if(c[last]--){map[i][0]=last;if(c[last]==0)last++;}

        }

    }

    for(int i=0;i<h;i++)

    {



            for(int j=0;j<w-1;j++)cout<<map[i][j]<<" ";

            cout<<map[i][w-1]<<endl;





    }

    return 0;

}




