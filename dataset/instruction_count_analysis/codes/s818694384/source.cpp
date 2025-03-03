#include<iostream>

using namespace std;

int p[200010];

int main(void)

{

    int n,sum=0,mi=1e9;

    cin >> n;

    for(int i=1;i<=n;i++)

        cin >> p[i];

    for(int i=1;i<=n;i++)

    {

        if(p[i]<mi)

        {

            mi=p[i];

            sum++;

        }

    }

    cout << sum;

    return 0;

}