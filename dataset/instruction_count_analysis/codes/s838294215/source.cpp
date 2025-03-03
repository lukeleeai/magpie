    #include<iostream>

    using namespace std;

    int main(){

    	int n;

    	cin>>n;

    	long long int sum=0;

    	int a[200000];

    	for(int i=0;i<n;i++){

    		cin>>a[i];

    		sum+=a[i];

    	}

    	sum-=a[n-1];

    	long long int k=a[n-1];

    	long long int min=abs(sum-k);

    	for(int i=n-2;i>0;i--){

    		sum-=a[i];

    		k+=a[i];

    		if(abs(sum-k)<min){

    			min=abs(sum-k);

    		}

    		

    	}

    	cout<<min;

    

    }