#include <iostream>

#include <string>

#include <algorithm>

#include <map>



#define lli long long int



using namespace std;

string ordena(string s){

  sort(s.begin(), s.end());

  return s;

}



int main() {



  lli n;

  cin >> n;

  map<string,lli> M;

  string s;

  for(lli i=0; i<n; i++){

    cin >> s;

    sort(s.begin(), s.end());

    M[s]++;



  }

  lli cont=0, aux, aux1;

  map<string,lli>::iterator it;

  for(it=M.begin(); it!=M.end(); it++){

    if(it->second>1)  {

      aux=it->second;

      aux1=aux*(aux-1);

      cont+=aux1/2;

    }

  }

  cout << cont;

}
