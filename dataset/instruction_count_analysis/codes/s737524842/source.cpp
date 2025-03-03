#include"stdc++.h"

using namespace std;

string s[200005];

int main()

{

    ios::sync_with_stdio(false);

    int a,b,c,d,count1=0;

    cin>>a>>b>>c>>d;

    while(a>0&&c>0)

    {

        if(count1%2)

        {

            a-=d;

            if(a<=0)

                {

                    cout<<"No"<<endl;

                    return 0;

                }

        }

        else

        {

            c-=b;

            if(c<=0)

               {

                    cout<<"Yes"<<endl;

                    return 0;

                }

        }

        count1++;

    }

}
