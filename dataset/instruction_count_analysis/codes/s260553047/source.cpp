#include"stdc++.h"

using namespace std;

const int maxn=1e5+7;

int num[maxn];

int main()

{

    string stra;

    string strb;

    cin>>stra>>strb;

    int len=stra.size();

    memset(num,-1,sizeof(num));

    for(int i=0;i<len;i++)

    {

        if(num[stra[i]]==-1)

        {

            num[stra[i]]=strb[i];

        }

        else

        {

            if(num[stra[i]]!=strb[i])

            {

                cout<<"No"<<endl;

                return 0;

            }

        }

    }

    memset(num,-1,sizeof(num));

    for(int i=0;i<len;i++)

    {

        if(num[strb[i]]==-1)

        {

            num[strb[i]]=stra[i];

        }

        else

        {

            if(num[strb[i]]!=stra[i])

            {

                cout<<"No"<<endl;

                return 0;

            }

        }

    }

    cout<<"Yes"<<endl;

    return 0;

}