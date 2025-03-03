#include <iostream>

#include <cmath>

using namespace std;

int a[20][20];



int main(){

	

	//printf("%f",sqrt((1-5)^2)+((2-5)^2));

	

	int n,d;

	double EPS=1e-10;

	cin>>n>>d;

	

	for(int i=0;i<n;i++){

		for(int j=0;j<d;j++){

			cin>>a[i][j];

		}

	}

	

	int sum=0;

	

	for(int k=0;k<n;k++){

		for(int i=k+1;i<n;i++){

			double ans=0;

			for(int j=0;j<d;j++){

				ans+=(a[i][j]-a[k][j])*(a[i][j]-a[k][j]);

				//printf("%f\n",ans);

			}

			double ans1=sqrt(ans);

			//printf("%f\t%f\t%f\n",ans,ans1-floor(ans1),ans1-floor(ans1));

			if(ans1-floor(ans1)<EPS){

				sum++;

				//printf("%f\t\t%f\n",ans,ans1-floor(ans1));

			}

		}

	}

	cout<<sum<<endl;

	return 0;

}






