

#include<iostream>

int main(){

  int f[2],i,j;

  std::string r,a;

  while(std::cin>>r>>a,r!="0"&&a!="0"){

    for(f[0]=f[1]=i=0;i<4;i++)for(j=4;j-->0;)if(a[i]==r[j])f[i!=j]++;

    std::cout<<f[0]<<" "<<f[1]<<"\n";

  }

}