#include<iostream>

#include<cstdio>

#include<algorithm>

using namespace std;



int a[26][2],ans,temp;



char b[110];





int main()

{

    int n;

    scanf("%d%s",&n,b);

    for (int i=0;i<n;i++)

    a[b[i]-97][0]++;

    for (int i=0;i<n;i++)

    {

        if (a[b[i]-97][1]==0 && a[b[i]-97][0]>=2) temp++;

        if (a[b[i]-97][1]>0 && a[b[i]-97][0]==1) temp--;

        a[b[i]-97][1]++;a[b[i]-97][0]--;

        ans=max(ans,temp);

    }

    cout<<ans<<endl;

    return 0;

}