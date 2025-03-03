#include<iostream>

#include<cmath>

#include<cstdio>

#include<vector>

using namespace std;



int main(){

  long long int a;

  long long int b;



  while(cin >> a >> b){

    int ans;

    bool p[2000000];

    vector<vector<int> > part;

    

    ans = 2*b+1;

    part.resize(b*2+1);

    int N = (int)sqrt(a+b)+1;

    for(int i=0;i<=N;i++)p[i] = true;

    p[0] = false;

    p[1] = false;

    p[2] = true;

    

    int o = 0;

    if((a-b)%2)o++;

    for(int i=o;i<=2*b;i+=2)part[i].push_back(2);

    

    int c = 3;

    while(c*c<=N){

      for(int i=3*c;i<=N;i+=2*c)p[i] = false;

      do{c+=2;}while(!p[c]);

    }

    

    

    c = 3;

    while(c<=N){

      int t = (a-b)%c;

      for(int i=(c-t)%c;i<=2*b;i+=c)part[i].push_back(c);

      do{c+=2;}while(!p[c]);

    }

    

    

    for(int i=0;i<=2*b;i++){

      long long int tmp = a-b+i;

      int prv = 1<<30;

      if(tmp<=1)ans--;

      else{

	

	if(!part[i].empty()){

	  bool f = false;

	  for(int j=0;j<(int)part[i].size();j++){

	    int cnt = 0;

	    while(!(tmp%part[i][j])){

	      tmp /= part[i][j];

	      cnt++;

	    }

	    if(prv < cnt){

	      f=true;

	      break;

	    }else{

	      prv = cnt;

	    }

	    if(tmp==1)break;

	  }

	  if(f)ans--;

	}

	

      }

    }

    

    printf("%d\n",ans);

  }

}