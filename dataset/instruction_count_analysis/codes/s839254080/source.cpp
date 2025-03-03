#include"stdc++.h"

using namespace std;

int a,b,c,d;

int main(){

cin>>a>>b>>c>>d;

if (a+b<c+d) puts("Right");

else if (a+b>c+d) puts("Left");

else puts("Balanced");

}