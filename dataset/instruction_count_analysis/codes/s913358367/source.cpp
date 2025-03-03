#include<algorithm>

#include<iostream>

#include<cstdio>

#include<cstring>

#include"stdc++.h"

using namespace std;

#define ll long long

#define MAXN 1000010

int  arr[1000];

int brr[101][101]={0};

int main()

{

	int n ;

	cin >>n;

	int sum=0;int pp = 0;

	if(n%2){

        pp = n-1;

	}

	else pp = n;



    for(int i=1;i<=n;i++){

        for(int j =1;j<=n;j++){

                if(j!=pp&&(brr[i][j]==0&&brr[j][i]==0)&&i!=j)

                    brr[i][j]=1,sum++;

        }

        pp--;

    }

    cout<<sum<<endl;

    for(int i=1;i<=n;i++){

        for(int j=1;j<=n;j++){

            if(brr[i][j])

                cout<<i<<" "<<j<<endl;

        }

    }

	return 0;

}
