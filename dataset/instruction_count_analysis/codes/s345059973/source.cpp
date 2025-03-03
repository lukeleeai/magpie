#include<stdio.h>

#include<string.h>

#include<algorithm>

#include<iostream>

#include<set>

#include<queue>

using namespace std;

int n;

int z;

int sum[1100000];

void dfs(int a,int b,int c,int num,int fl)

{

    if(num>1e9)

    {

        return ;

    }

    if(fl>9)

        return ;

    if(a&&b&&c)

    {

        sum[z++]=num;

        dfs(1,b,c,num*10+3,fl+1);

        dfs(a,1,c,num*10+5,fl+1);

        dfs(a,b,1,num*10+7,fl+1);

    }

    else

    {

           dfs(1,b,c,num*10+3,fl+1);

        dfs(a,1,c,num*10+5,fl+1);

        dfs(a,b,1,num*10+7,fl+1);

    }



}

int main()

{

    z=0;

    dfs(0,0,0,0,0);

    sort(sum,sum+z);

    int key;

    while(cin>>key)

    {



    int left = 0;

    int right =z-1;

    while (left <= right) {

        int mid = (left + right) / 2;

        if (sum[mid] > key) {

            right = mid - 1;

        }

        else {

            left = mid + 1;

        }

    }

    cout<<right+1<<endl;

    }



}


