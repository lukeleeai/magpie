#include "stdc++.h"

using namespace std;

vector<int>a[1005];

int main()

{

    int h,w;

    cin>>h>>w;

    int n;

    cin>>n;

    int f=0;

    for(int i=0; i<n; i++)

    {

        int x;

        scanf("%d",&x);

        for(int j=0;j<x;j++)

            a[f/w].push_back(i+1),f++;

    }

 

    for(int i=0; i<h; i++)

    {

        if(i&1)reverse(a[i].begin(),a[i].end());

        printf("%d",a[i][0]);

        for(int j=1; j<w; j++)

            printf(" %d",a[i][j]);

        printf("\n");

    }

    return 0;

}