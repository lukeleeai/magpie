#include <iostream>

#include "stdc++.h"



using namespace std;

int a[500000],b[500000],n;

long long sums,ans;



int main()

{

    scanf("%d",&n);

    long long sums = 0;int tmp;

    for(int i=0;i<n;++i){

        scanf("%d",&tmp);++a[tmp-1];

    }



    vector<int> vn;

    sort(a,a+n);reverse(a,a+n);

    int j = n-1;

    int rs = 0;

    for(int i=1;i<=n;++i){

        while(j>=0&&a[j]<i){

            rs += a[j--];

        }

        b[i] = rs/i + (j+1);

    }



    j = n;

    for(int i=1;i<=n;++i){

        while(j>=1&&b[j]<i) --j;

        printf("%d\n",j);

    }

    return 0;

}
