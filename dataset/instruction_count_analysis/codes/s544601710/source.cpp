#include<iostream>

#include<algorithm>

using namespace std;

string s[200010];

long long x[200010]={0};

int main(){

	int n,i,j,m;

	long long ans=0,k=0;

	char t;

	cin >> n;

	for(i=1;i<=n;i++){

		x[i]=x[i]+x[i-1]+i;

	}

	for(i=0;i<n;i++){

		cin >> s[i];

	}

	for(m=0;m<n;m++){

		for(i=0;i<s[m].size()-1;i++){

			for(j=i+1;j<s[m].size();j++){

				if(s[m][i]>s[m][j]){

					t=s[m][i];

					s[m][i]=s[m][j];

					s[m][j]=t;

				}

			}

		}

	}

	sort(s,s+n);

	ans=0;

	k=0;

	for(i=1;i<n;i++){

		if(s[i]!=s[i-1]){

			ans+=x[k];

			k=0;

		}

		else

			k++;

	}

	ans+=x[k];

	cout << ans << endl;

	return 0;

}
