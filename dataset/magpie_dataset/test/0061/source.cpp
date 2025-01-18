#include"stdc++.h"

using namespace std;

string a;

int b[15],q;

int main()

{

    cin>>a;

    for(int i=0;i<a.size();i++)

    {

        if(a[i]=='0'){q++;b[q]=0;} 

        if(a[i]=='1'){q++;b[q]=1;}

        if(a[i]=='B'&&q>=1)q--;

    }    

    for(int i=1;i<=q;i++)cout<<b[i];

    cout<<endl;

    return 0;

}