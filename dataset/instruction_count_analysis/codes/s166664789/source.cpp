#include <stdio.h>

#include <string.h>

#include <algorithm>

#include <iostream>

#include <vector>

#include <map>

#define ll long long

#define inf 0x3f3f3f3f

using namespace std;

const int maxn = 2e5 + 5;



int n;

vector<int> a;

int b[maxn];

bool cmp(int x, int y)

{

    return x > y;

}



int main()

{

    cin >> n;

    for(int i=1; i<=n; i++)

    {

        scanf("%d", &b[i]);

        a.push_back(b[i]);

    }

    sort(a.begin(), a.end(), cmp);

    for(int i=1; i<=n; i++)

    {

        int mid = n/2;

        if(b[i] < a[mid-1])

            printf("%d\n", a[mid-1]);

        else

            printf("%d\n", a[mid]);

    }

    return 0;

}

/****



****/
