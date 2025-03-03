#include<iostream>

using namespace std;



main(){

  int n,s;

  while(cin>>n>>s && n){

    int r[101]={0};

    for(int i=0;i<n;i++){

      int tmp;cin>>tmp;r[tmp]++;

    }

    int ans = 0;

    for(int i=0;i<101;i++){

      if (i+i > s && r[i])ans += (r[i]*(r[i]-1))/2;

      for(int j=i+1;j<101;j++){

	if (i+j > s && r[i] && r[j])ans += r[i]*r[j];

      }

    }

    cout << ans << endl;

  }

}