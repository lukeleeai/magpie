#include<iostream>

#include<cstring>

#include<algorithm>

using namespace std;



int main(){

	int n,k;

	int x[101][101];

	int a,b,c,d,e;

	int y[101][101];

	int p;

	int sum=1000000000;

	bool s[101];

	int h[101];

	int h2[101][201];



	while(true){

		memset(x,127,sizeof(x));

		memset(s,false,sizeof(s));

		memset(h,0,sizeof(h));

		cin>>n>>k;

		if(n==0 && k==0){

			break;

		}

		e=n;

		sum=1000000000;

		for(int i=0;i<k;i++){

			memset(y,127,sizeof(y));

			sum=1000000000;

			p=10000000;

			cin>>a;

			if(a==0){

				cin>>b>>c;

				y[0][b]=0;

				if(s[c]==true && s[b]==true){

					for(int j=1;j<=e;j++){

						for(int l=1;l<=n;l++){

							if(y[j-1][l]<100000000){

								for(int m=1;m<=h[l];m++){

									if(x[l][h2[l][m]]<100000000){

										y[j][h2[l][m]]=min(y[j][h2[l][m]],y[j-1][l]+x[l][h2[l][m]]);

									}

								}

							}

						}

					}

				}

				for(int j=1;j<=n;j++){

					sum=min(sum,y[j][c]);

				}

				if(sum>=1000000000){

					sum=-1;

				}

				cout<<sum<<endl;

			}



			if(a==1){

				cin>>b>>c>>d;

				x[b][c]=min(x[b][c],d);

				x[c][b]=min(x[c][b],d);

				s[c]=true;

				s[b]=true;

				h[b]++;

				h[c]++;

				h2[b][h[b]]=c;

				h2[c][h[c]]=b;

			}

		}

	}

	return 0;

}