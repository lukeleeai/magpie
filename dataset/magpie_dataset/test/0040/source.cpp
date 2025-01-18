#include"stdc++.h"

using namespace std;

#define ALL(x) begin(x),end(x)

typedef long long ll;

int OO = 0x3f3f3f3f;



int n, k;

int arr[100005];

int mem[100005];



int solve(int x)

{

    if(x == n-1)

        return 0;



    if(mem[x] != OO)

        return mem[x];



    for(int i = 1; i <= k  && (x+i) <= n-1; i++)

    {

        mem[x] = min(mem[x], solve(x+i)+abs(arr[x] - arr[x+i]));

    }



    return mem[x];

}



int main()

{

    cin >> n >> k;

    memset(mem, OO, sizeof mem);

    for(int i = 0; i< n; i++)

    {

        cin >> arr[i];

    }

    cout << solve(0) << endl;

    return 0;

}
