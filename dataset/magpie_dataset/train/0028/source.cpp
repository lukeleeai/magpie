#include<list>

#include<iostream>

using namespace std;

int main(){

  int i;

  int n;

  long long c;

  for(;;){

    cin>>n;

    if(n==0)

      break;

    list<int> t;

    c=0;

    for(i=0;i<n;i++){

      int tmp;

      cin>>tmp;

      t.push_back(tmp);

    }

    t.sort();

    list<int>::iterator it=t.begin();

    for(i=0;i<n-1;i++){

      c+=(*it)*(n-i-1);

      it++;

    }

    cout<<c<<endl;

  }

  return 0;

}