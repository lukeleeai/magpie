#pragma GCC optimize(3)

#include"stdc++.h"

char a[100005];

int x,y,ans;

main(){

std::cin>>a;

for(int i=0;i<sizeof(a);i++)

if(x==y){x++;if(a[i]=='p')ans--;}

else{y++;if(a[i]=='g')ans++;}

printf("%d\n",ans);}