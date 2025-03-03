#include "bits/stdc++.h"

using namespace std;

int main()

{

ios_base::sync_with_stdio(false);

int n;

cin >> n;

long long a[2*n+1];

for(int i = 0; i < 2*n; i++)cin >> a[i];

sort(a,a+2*n);

long long sum = 0;

for(int i = 0; i < 2*n; i+=2)

{

sum+=a[i];

}

cout << sum;

return 0;

}