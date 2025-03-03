

#include<iostream>

#include<algorithm>

#include<vector>

using namespace std;



int main(){

  int L,H,hits,blow;

  string trys;

  vector<int> h,b,vi,ans;

  vector<string> t;

  vector<vector<int> > v;



  while(cin >> L >> H, L||H){

    t.clear();

    h.clear();

    b.clear();

    v.clear();

    ans.clear();



    for(int i=0;i<H;i++){

      cin >> trys >> hits >> blow;

      t.push_back(trys);

      h.push_back(hits);

      b.push_back(blow);

    }



    int comb = (1<<L) - 1;

    while(comb < (1<<10)){

      vi.clear();

      for(int i=0;i<10;i++){

	if( (comb>>i) & 1)vi.push_back(i);

      }

      v.push_back(vi);

      

      int x = comb & -comb, y = comb + x;

      comb = ( ( ( comb & ~y )/x )>>1 )|y;

    }



    for(int i=0;i<(int)v.size();i++){

      for(int j=0;j<H;j++){

	int sum = 0;

	for(int k=0;k<L;k++){

	  for(int l=0;l<L;l++){

	    if(v[i][k] == t[j][l] - '0'){

	      sum++;

	      break;

	    }

	  }

	}

	if(sum != h[j]+b[j]){

	  v.erase(v.begin()+i);

	  i--;

	  break;

	}

      }

    }



    bool flag = true;

    for(int i=0;i<(int)v.size();i++){

      do{

	bool f = true;

	for(int j=0;j<H;j++){

	  hits = 0;

	  for(int k=0;k<L;k++){

	    if(v[i][k] == t[j][k]-'0'){

	      hits++;

	      if(hits>h[j])break;

	    }

	  }

	  if(hits!=h[j]){

	    f = false;

	    break;

	  }

	}

	if(f){

	  if(ans.size()){

	    flag = false;

	    break;

	  }else{

	    ans = v[i];

	  } 

	}

      }while(next_permutation(v[i].begin(),v[i].end()));

      if(!flag)break;

    }

    

    if(flag && ans.size()){

      for(int i=0;i<L;i++)cout << ans[i];

      cout << endl;

    }else{

      cout << "NO" << endl;

    }

  }

}