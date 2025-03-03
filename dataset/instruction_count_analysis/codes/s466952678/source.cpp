#include<cstdio>

#include<iostream>

#include<vector>

int main(){

  int N;

  scanf("%d",&N);

  std::vector<int> a(N);

  for(int i=0;i<N;i++){

    scanf("%d",&a[i]);

  }

  int r=0;

  for(int &x:a){

    while(x%2==0){

      r++;

      x/=2;

    }

  }

  std::cout<<r<<std::endl;

  return 0;

}