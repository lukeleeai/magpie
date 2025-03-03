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

int n,a[200004],b[200004];

int main(){

	cin>>n;

	a[100000]++;

	b[100000]++;

	while (n--){

		int l,r;

		cin>>l>>r;

		a[l+100000]++;

		b[r+100000]++;

	}

	for (int i=200000;i>=0;i--)

		a[i]+=a[i+1];

	for (int i=1;i<=200000;i++)

		b[i]+=b[i-1];

	long long ans=0;

	for (int i=0;i<=200000;i++) ans+=min(b[i],a[i+1]);

	cout<<ans*2;

}