#include "stdc++.h"



using namespace std;



#define si(x) scanf("%d",&x)

#define sl(x) scanf("%lld",&x)

//s = char []

#define ss(s) scanf("%s",&s)

//s = string to read with spaces

#define read(s) getline(cin,s)



using namespace std;



int main()

{

    int n,x;

    si(n);

    int arr[100001] = {0};

    for(int i=0;i<n;i++){

        si(x);

        arr[x]++;

    }

    int i=1,j=100000,ans = 0;

    for(;i<=j;){

        while(i<= j && (arr[i] == 1 || arr[i] == 0)){

            if(arr[i] == 1)

                ans++;

            i++;

        }

        while(j>=i && (arr[j] == 1 || arr[j] == 0)){

            if(arr[j] == 1)

                ans++;

            j--;



        }

        if(i<= j)arr[i]--;

        if(j>= i)arr[j]--;

    }

    cout << ans;

    return 0;

}
