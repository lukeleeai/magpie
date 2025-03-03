#include"stdc++.h"

using namespace std;

long long a,b;

long long fans;

int main()

{

    cin>>a>>b;

    if((a<0&&b>0)||a==0||b==0)

    {

        cout<<"Zero"<<endl;

        return 0;

    }

    for(int i=a;i<=b;i++)

    {

        if(i<0)

         fans++;

    }

    if(fans%2==1)

      cout<<"Negative"<<endl;

    else

      cout<<"Positive"<<endl;

    return 0;

}