#include <iostream>

#include<algorithm>

#include<cmath>

using namespace std;



int main()

{

   unsigned long long n,k;

  unsigned long long arr[200005];

  unsigned long long maxm=1;

   unsigned long long cnt =0;



  cin>>n>>k;



  for(int i=0;i<n;i++){

        cin>>arr[i];

        cnt+=arr[i];

  }

  sort(arr,arr+n);



  if (k>=n){

    cout<<0;

  } else if (k==0){

   cout<< cnt;





  }

  else {

  for (int i=n-1;i>=0;i--){

        if (maxm<=k){

        cnt-=arr[i];}

        maxm++;

  }

   cout<<cnt;}



    return 0;

}
