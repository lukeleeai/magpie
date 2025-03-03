/* Ahmed Maher ( Acro_14 ) */

#include "stdc++.h"

typedef long long ll;

const ll oo = 0x3f3f3f3f;

int const N = 1e5+5;

using namespace std;

//string alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

//string BN(ll x){bool f=0;string Bn;int i=62;while(i--){if ((ll)x & (1LL << i)){Bn+='1';f=1;}else{if(f)Bn+='0';}}return Bn;}//Decimal to Binary converter

 int n = N;

int ans[664580];

int *Seive(){

    vector<bool> good(n);

    for(int i = 1; i < n; i++){

        good[i] = true;

    }

    good[1] = false;

    for(ll i = 2; i < n; i++){

        if(good[i]){

            // i = 1e7

            for(ll j = 1LL * i * i; j < n; j += i){

                good[j] = false;

            }

        }

    }

    int j=0;

    for(int i = 1; i < n; i++){

        if(good[i]){

           ans[j]=i;

           j++;

        }

    }

    return ans;

/*to print */

//    int *p;

//    p=Seive();

//      for(int i=0;i<10e7;i++){

//      cout << *(p + i) << endl;

//      system("pause");

//   }

/*end of print*/

}



int main()

{

    int *p,arr[N];

    p=Seive();

    for(int i=0;i<N;i++)arr[i] = *(p + i);

    int x;

    cin>>x;

        for (int i=0;i<N;i++){

            if (arr[i]>x && arr[i-1]<x){cout<<arr[i]<<endl;break;}

            else if (arr[i]==x){cout<<x<<endl;break;}

        }

}



//       int anss[t+1];

//            anss[j]=ans;

//     for(int j=1;j<=t;j++) printf("Case %d: %d\n",j,anss[j]);
