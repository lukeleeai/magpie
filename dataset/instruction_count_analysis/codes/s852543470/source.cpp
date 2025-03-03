#include "stdc++.h"

using namespace std;

#define rint register int

inline int read(){int r;int s=0,c;for(;!isdigit(c=getchar());s=c);for(r=c^48;isdigit(c=getchar());(r*=10)+=c^48);return s^45?r:-r;}

int n, K; int main(){n = read(); K = read(); return !printf("%d\n",(n-2)/(K-1)+1);}