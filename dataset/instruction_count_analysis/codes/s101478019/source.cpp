#include"stdc++.h"

using namespace std;

int p[100009],f[100009];

main()

{

    p[1]=1;



    for (int i=2; i<=100000; i++)

    {

        for (int j=2*i; j<=100000; j+=i)

            p[j]=1;

    }

    p[2]=0;

    for (int i=1; i<=100000; i++)//构造前缀和

    {

        if(p[i]==0 && p[(i+1)/2]==0 && i!=2)//如果该数满足要求，前缀和加1；否则不变

            {

                f[i]=f[i-1]+1;

            }

        else f[i]=f[i-1];

    }

    int q;

    cin>>q;

    while(q--)

    {

        int l,r;

        cin>>l>>r;

        cout<<f[r]-f[l-1]<<endl;//对于每组询问，直接输出f[r]-f[l-1]

    }

}