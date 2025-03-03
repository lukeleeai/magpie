#include<iostream>

#include<cmath>

#include<cstdio>

using namespace std;



int main(){

  long long int a;

  long long int b;

  while(cin >> a >> b){

    int ans;

    bool p[1001001];

    int num[1000001];



    for(int i=0;i<=2*b;i++){

      if(a-b+i<2)num[i] = 0;

      else num[i] = 1<<30;

    }



    int N = (int)sqrt(a+b);

    for(int i=2;i<=N;i++)p[i] = true;

    

    int c = 2;

    while(c<=N){

      for(int i=2*c;i<=N;i+=c)p[i] = false;



      int s = (c-(a-b)%c)%c;

      for(int j=s;j<=2*b;j+=c){

	long long int tmp = a-b+j;

	if(num[j]){



	  int cnt = 0;

	  while(!(tmp%c)){

	    tmp /= c;

	    cnt++;

	  }



	  if(cnt){

	    if(num[j] < cnt)num[j] = 0;

	    else num[j] = cnt;

	  }

	}

      }



      while(!p[++c]);

    }



    ans = 0;

    for(int i=0;i<=2*b;i++){

      if(num[i])ans++;

    }



    printf("%d\n",ans);

  }

}