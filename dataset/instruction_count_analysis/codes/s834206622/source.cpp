#include<iostream>

using namespace std;

#define N 1000001



int arrr1[N+5],arrr2[N+5];

int main()

{

    int n,m,a,b;



    cin>>n>>m;

    for(int i=0; i<m; i++)

    {

        cin>>a>>b;

        if(a==1)

            arrr1[b]=1;//第一次的终点

        if(b==n)

            arrr2[a]=1;//第二次的起点

    }



    int p=0;

    for(int i=1; i<=m; i++)

    {

        if(arrr1[i]&&arrr2[i])

        {

            cout<<"POSSIBLE"<<endl;

            p=1;

        }

    }



    if(p==0)

        cout<<"IMPOSSIBLE"<<endl;



    return 0;

}