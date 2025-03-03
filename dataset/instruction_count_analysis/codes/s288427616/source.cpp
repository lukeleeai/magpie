#include"stdc++.h"

using namespace std;

const int N=1e5+7;

struct stu{

	int start,end;

}arr[N];

int ans[N];

int main(){

	memset(ans,0,sizeof(ans));

	string s;

	cin>>s;

	int n=s.length();

	bool flag=false ;

	int pos=0;

	for(int i=0;i<n ;i++){

		if(s[i]=='R'){

			if(!flag){

				arr[++pos].start=i;

				arr[pos].end=i;

				flag=true;

			}

			else arr[pos].end=i;

		}

		else	flag=false ;

	}

	arr[pos+1].start=n;

	for(int i=1;i<=pos;i++){

		int disr=arr[i].end-arr[i].start+1;//r的长度

		int disl=arr[i+1].start-arr[i].end-1;

		if(disr&1){

			ans[arr[i].end]+=disr/2 +1;

			ans[arr[i].end+1]+=disr/2;

		}

		else {

			ans[arr[i].end]+=disr/2;

			ans[arr[i].end+1]+=disr/2;			

		}

		if(disl&1){

			ans[arr[i].end]+=disl/2;

			ans[arr[i].end+1]+=disl/2+1;			

		}

		else {

			ans[arr[i].end]+=disl/2;

			ans[arr[i].end+1]+=disl/2;

		}

	}

	for(int i=0;i<n;i++) cout<<ans[i]<<" ";

	

	return 0;

} 