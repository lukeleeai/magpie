#include<iostream>

#include<algorithm>

#include<vector>

using namespace std;



int main(){

  int L,H,hits,blow;

  string trys;

  vector<int> h,b,v,ans;

  vector<string> t;



  while(cin >> L >> H, L||H){

    t.clear();

    h.clear();

    b.clear();

    ans.clear();



    for(int i=0;i<H;i++){

      cin >> trys >> hits >> blow;

      t.push_back(trys);

      h.push_back(hits);

      b.push_back(blow);

    }



    bool f1 = true;

    int comb = (1<<L) - 1;

    while(comb < (1<<10)){

      v.clear();

      for(int i=0;i<10;i++){

	if( (comb>>i) & 1)v.push_back(i);

      }



      bool f2 = true;

      for(int i=0;i<H;i++){

	int sum = 0;

	for(int j=0;j<L;j++){

	  for(int k=0;k<L;k++){

	    if(v[j] == t[i][k] - '0'){

	      sum++;

	      break;

	    }

	  }

	}

	if(sum != h[i]+b[i]){

	  f2 = false;

	  break;

	}

      }

      

      if(f2){

	do{

	  bool f3 = true;

	  for(int i=0;i<H;i++){

	    hits = 0;

	    for(int j=0;j<L;j++){

	      if(v[j] == t[i][j]-'0'){

		hits++;

		if(hits>h[i])break;

	      }

	    }

	    if(hits!=h[i]){

	      f3 = false;

	      break;

	    }

	  }

	  if(f3){

	    if(ans.size()){

	      f1 = false;

	      break;

	    }else{

	      ans = v;

	    } 

	  }

	}while(next_permutation(v.begin(),v.end()));

      }

    

      if(!f1)break;

      int x = comb & -comb, y = comb + x;

      comb = ( ( ( comb & ~y )/x )>>1 )|y;

    }

    if(f1 && ans.size()){

      for(int i=0;i<L;i++)cout << ans[i];

      cout << endl;

    }else{

      cout << "NO" << endl;

    }

  }

}