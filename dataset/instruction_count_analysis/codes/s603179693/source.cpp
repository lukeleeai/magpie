#include"stdc++.h"

using namespace std;

char a[100005];

int x=0,y=0,ans=0;

int main()

{

    cin>>a;

    for (int i=0;i<sizeof(a);i++)

        if (x==y) {

            x++; 

            if(a[i]=='p') ans--;

        }

    else {

        y++; 

        if(a[i]=='g') ans++;

    }

    printf("%d\n",ans);

    return 0;

}