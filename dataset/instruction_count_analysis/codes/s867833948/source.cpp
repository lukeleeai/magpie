#include "stdc++.h"

using namespace std;

int main()

{

   int x;

   cin>>x;

    int a[x];

    for(int i=0;i<x;i++)

        cin>>a[i];

    sort(a,a+x);

    cout<<a[x-1]-a[0];

   return 0;

   }
