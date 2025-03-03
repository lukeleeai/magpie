#include <algorithm>

#include <cstdio>

#include <iostream>

#include <cfloat>

#include <climits>

#include <cstdlib>

#include <cstring>

#include <cmath>

#include <queue>

#include <sstream>

#include <stack>

#include <time.h>

#include <vector>

#include <complex>

#include <map>

#include <set>

#include <iomanip>

#include <math.h>

#include <stdlib.h>

#include <list>

#include <utility>

#include <memory>

#include <cstring>

#include <fstream>

#include <numeric>

#include <assert.h>

#include <bitset>

#include <ios> 

#include "stdc++.h"

using namespace std;

int main(){

	int n;

	cin>>n;

	vector <int> x(n+1),y(n+1);

	for (int i=0;i<n;i++) cin>>x[i]>>y[i];

	sort (x.rbegin(),x.rend());

	sort (y.begin(),y.end());

	long long ans=0;

	for (int i=0;i<n+1;i++){

		if (x[i]>y[i]){

			ans+=2*(x[i]-y[i]);

		}

	}

	cout<<ans;

}