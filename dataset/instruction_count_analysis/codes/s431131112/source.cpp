#include"stdc++.h"

#define   ll  long long int

#define   sz  100100



using namespace std;



string ss[sz];





string tani(ll n,char ch)

{

    ll i;

    string s="";



    for(i=1;i<=n;i++)s+=ch;



    return s;



}

int main()

{



    string s="abcdefghijklmnopqrstuvwxyz";



    ll i,j,k,p,x,d,c,a,b,n;



    string an="";



    cin>>n;



    ll mn=10000000;





    for(i=1;i<=n;i++)

    {

        cin>>ss[i];

    }



    for(i=0;i<26;i++)

    {

        mn=10000000;



        for(j=1;j<=n;j++)

        {

            c=0;



            for(k=0;k<ss[j].size();k++)

            {

                if(ss[j][k]==s[i])c++;

            }

            mn=min(mn,c);

        }



        string xx=tani(mn,s[i]);



        an+=xx;

    }



    cout<<an<<endl;



    return 0;

}


