#include"stdc++.h"

using namespace std;

const double pi=M_PI;

int main(void)

{

  short A,B,H,M;

  cin>>A>>B>>H>>M;

  return printf("%.20lf",pow(A*A+B*B-2*A*B*cos(((H*60+M)/2.0-6*M)*pi/180.0),0.5)),0;

}