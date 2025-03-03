#include<iostream>

#include<map>

#include<vector>

#include<string>



using namespace std;

#define mp make_pair

int main(){

  int n;

  string a;

  long long b,c;

  map<string,long long> data;

  vector<string> id;

  while(true){

    id.clear();

    data.clear();

    cin>>n;

    if(!n)

      break;

    for(int i=0;i<n;i++){

      cin>>a>>b>>c;

      c*=b;

      if(data.find(a)==data.end()){

	data.insert(mp(a,c));

	id.push_back(a);

      }

      else{

	data[a]+=c;

      }

    }

    bool empty = true;

    for(int i=0;i<id.size();i++){

      if(data[id[i]]>=1000000){

	cout<<id[i]<<endl;

	empty = false;

      }

    }

    if (empty)

      cout<<"NA"<<endl;



  }

  return 0;

}