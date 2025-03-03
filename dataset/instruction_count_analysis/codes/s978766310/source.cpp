#include<iostream>

using namespace std;



int gcd(int p,int q)

{

    if(q==0) return p;

    return gcd(q,p%q);

}



int main(void)

{

    int k,sum=0,g;

    cin >> k;

    for(int i=1;i<=k;i++)

    {

        for(int j=1;j<=k;j++)

        {

            g = gcd(i,j);

            for(int l=1;l<=k;l++)

            {

                sum+=gcd(g,l);

            }

        }

    }

    cout << sum;

    return 0;

}
