#include "stdc++.h"



using namespace std;

int ar[1000000],cc[100050];

vector<pair<int,int> > gg[100050];

map<int,int> o;

int main()

{

int n;

cin>>n;

for(int i=0;i<n;i++){

cin>>ar[i];

cc[ar[i]]++;

}

sort(ar,ar+n);

long long h=0,l=0;

for(int i=0;i<100050;i++){

        int x;

        if(cc[i]!=0){

if(cc[i]%2==0)

h++;

else

l++;





        }

}



if(h%2==0)

cout<<l+h;

else

    cout<<l+h-1;













    return 0;

}
