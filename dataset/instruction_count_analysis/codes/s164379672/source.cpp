#include<cstdio>

#include<string>

#include<iostream>

#include<algorithm>

using namespace std;

struct node

{

    string a;

    int b;

    int y;

} m[10005];

int main()

{

    int n;

    cin>>n;

    for(int i=0; i<n; i++)

    {

        cin>>m[i].a>>m[i].b;

        m[i].y=i;

    }

    for(int i=0; i<n; i++)

    {

        for(int j=i+1; j<n; j++)

        {

            if(m[j].a<m[i].a)

            {

                node h;

                h=m[j];

                m[j]=m[i];

                m[i]=h;

            }

            if(m[j].a==m[i].a)

            {

                if(m[j].b>m[i].b)

                {

                    node h;

                    h=m[j];

                    m[j]=m[i];

                    m[i]=h;

                }

            }

        }

    }

    for(int i=0;i<n;i++)

    {

        cout<<m[i].y+1<<endl;

    }

}
