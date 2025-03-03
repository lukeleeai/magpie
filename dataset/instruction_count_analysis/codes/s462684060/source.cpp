#include"stdc++.h"

using namespace std;

int main(){

	long long n,m,i,j,f[100010],yc[100010];

	bool g;

	cin>>n;

	char x;

	for(i=1;i<=n;i++){

		cin>>x;

		if(x=='o')f[i]=1;

		else f[i]=0;

	}

	yc[1]=1;yc[2]=1;

	g=0;

	for(i=3;i<=n;i++){

		if(yc[i-1]==1){

			if(f[i-1]==1)

				yc[i]=yc[i-2];

			else{

				if(yc[i-2]==1)yc[i]=0;

				else yc[i]=1;

			}

		}

		else{

			if(f[i-1]==1){

				if(yc[i-2]==1)yc[i]=0;

				else yc[i]=1;

			}

			else

			yc[i]=yc[i-2];

		}

	}

   	if(yc[1]==1){

		if(f[1]==1){

			if(yc[n]==1){

				if(f[n]==1){

					if(yc[2]!=yc[n]||yc[n-1]!=yc[1])g=1;

				}

				else{

					if(yc[2]!=yc[n]||yc[n-1]==yc[1])g=1;

				}

			}

			else{

				if(f[n]==1){

					if(yc[2]!=yc[n]||yc[n-1]==yc[1])g=1;

				}

				else{

					if(yc[2]!=yc[n]||yc[n-1]!=yc[1])g=1;

				}

			}

		}

		else{

			if(yc[n]==1){

				if(f[n]==1){

					if(yc[2]==yc[n]||yc[n-1]!=yc[1])g=1;

				}

				else{

					if(yc[2]==yc[n]||yc[n-1]==yc[1])g=1;

				}

			}

			else{

				if(f[n]==1){

					if(yc[2]==yc[n]||yc[n-1]==yc[1])g=1;

				}

				else{

					if(yc[2]==yc[n]||yc[n-1]!=yc[1])g=1;

				}

			}

		}

	}

	else{

		if(f[1]==1){

			if(yc[n]==1){

				if(f[n]==1){

					if(yc[2]==yc[n]||yc[n-1]!=yc[1])g=1;

				}

				else{

					if(yc[2]==yc[n]||yc[n-1]==yc[1])g=1;

				}

			}

			else{

				if(f[n]==1){

					if(yc[2]==yc[n]||yc[n-1]==yc[1])g=1;

				}

				else{

					if(yc[2]==yc[n]||yc[n-1]!=yc[1])g=1;

				}

			}

		}

		else{

			if(yc[n]==1){

				if(f[n]==1){

					if(yc[2]!=yc[n]||yc[n-1]!=yc[1])g=1;

				}

				else{

					if(yc[2]!=yc[n]||yc[n-1]==yc[1])g=1;

				}

			}

			else{

				if(f[n]==1){

					if(yc[2]!=yc[n]||yc[n-1]==yc[1])g=1;

				}

				else{

					if(yc[2]!=yc[n]||yc[n-1]!=yc[1])g=1;

				}

			}

		}

	}

	if(g==0){

		for(i=1;i<=n;i++){

			if(yc[i]==1)cout<<'S';

			else cout<<'W';

		}

		return 0;

	}

	yc[1]=1;yc[2]=0;

	g=0;

	for(i=3;i<=n;i++){

		if(yc[i-1]==1){

			if(f[i-1]==1)

				yc[i]=yc[i-2];

			else{

				if(yc[i-2]==1)yc[i]=0;

				else yc[i]=1;

			}

		}

		else{

			if(f[i-1]==1){

				if(yc[i-2]==1)yc[i]=0;

				else yc[i]=1;

			}

			else

			yc[i]=yc[i-2];

		}

	}

	if(yc[1]==1){

		if(f[1]==1){

			if(yc[n]==1){

				if(f[n]==1){

					if(yc[2]!=yc[n]||yc[n-1]!=yc[1])g=1;

				}

				else{

					if(yc[2]!=yc[n]||yc[n-1]==yc[1])g=1;

				}

			}

			else{

				if(f[n]==1){

					if(yc[2]!=yc[n]||yc[n-1]==yc[1])g=1;

				}

				else{

					if(yc[2]!=yc[n]||yc[n-1]!=yc[1])g=1;

				}

			}

		}

		else{

			if(yc[n]==1){

				if(f[n]==1){

					if(yc[2]==yc[n]||yc[n-1]!=yc[1])g=1;

				}

				else{

					if(yc[2]==yc[n]||yc[n-1]==yc[1])g=1;

				}

			}

			else{

				if(f[n]==1){

					if(yc[2]==yc[n]||yc[n-1]==yc[1])g=1;

				}

				else{

					if(yc[2]==yc[n]||yc[n-1]!=yc[1])g=1;

				}

			}

		}

	}

	else{

		if(f[1]==1){

			if(yc[n]==1){

				if(f[n]==1){

					if(yc[2]==yc[n]||yc[n-1]!=yc[1])g=1;

				}

				else{

					if(yc[2]==yc[n]||yc[n-1]==yc[1])g=1;

				}

			}

			else{

				if(f[n]==1){

					if(yc[2]==yc[n]||yc[n-1]==yc[1])g=1;

				}

				else{

					if(yc[2]==yc[n]||yc[n-1]!=yc[1])g=1;

				}

			}

		}

		else{

			if(yc[n]==1){

				if(f[n]==1){

					if(yc[2]!=yc[n]||yc[n-1]!=yc[1])g=1;

				}

				else{

					if(yc[2]!=yc[n]||yc[n-1]==yc[1])g=1;

				}

			}

			else{

				if(f[n]==1){

					if(yc[2]!=yc[n]||yc[n-1]==yc[1])g=1;

				}

				else{

					if(yc[2]!=yc[n]||yc[n-1]!=yc[1])g=1;

				}

			}

		}

	}

	if(g==0){

		for(i=1;i<=n;i++){

			if(yc[i]==1)cout<<'S';

			else cout<<'W';

		}

		return 0;

	}

	yc[1]=0;yc[2]=1;

	g=0;

	for(i=3;i<=n;i++){

		if(yc[i-1]==1){

			if(f[i-1]==1)

				yc[i]=yc[i-2];

			else{

				if(yc[i-2]==1)yc[i]=0;

				else yc[i]=1;

			}

		}

		else{

			if(f[i-1]==1){

				if(yc[i-2]==1)yc[i]=0;

				else yc[i]=1;

			}

			else

			yc[i]=yc[i-2];

		}

	}

	if(yc[1]==1){

		if(f[1]==1){

			if(yc[n]==1){

				if(f[n]==1){

					if(yc[2]!=yc[n]||yc[n-1]!=yc[1])g=1;

				}

				else{

					if(yc[2]!=yc[n]||yc[n-1]==yc[1])g=1;

				}

			}

			else{

				if(f[n]==1){

					if(yc[2]!=yc[n]||yc[n-1]==yc[1])g=1;

				}

				else{

					if(yc[2]!=yc[n]||yc[n-1]!=yc[1])g=1;

				}

			}

		}

		else{

			if(yc[n]==1){

				if(f[n]==1){

					if(yc[2]==yc[n]||yc[n-1]!=yc[1])g=1;

				}

				else{

					if(yc[2]==yc[n]||yc[n-1]==yc[1])g=1;

				}

			}

			else{

				if(f[n]==1){

					if(yc[2]==yc[n]||yc[n-1]==yc[1])g=1;

				}

				else{

					if(yc[2]==yc[n]||yc[n-1]!=yc[1])g=1;

				}

			}

		}

	}

	else{

		if(f[1]==1){

			if(yc[n]==1){

				if(f[n]==1){

					if(yc[2]==yc[n]||yc[n-1]!=yc[1])g=1;

				}

				else{

					if(yc[2]==yc[n]||yc[n-1]==yc[1])g=1;

				}

			}

			else{

				if(f[n]==1){

					if(yc[2]==yc[n]||yc[n-1]==yc[1])g=1;

				}

				else{

					if(yc[2]==yc[n]||yc[n-1]!=yc[1])g=1;

				}

			}

		}

		else{

			if(yc[n]==1){

				if(f[n]==1){

					if(yc[2]!=yc[n]||yc[n-1]!=yc[1])g=1;

				}

				else{

					if(yc[2]!=yc[n]||yc[n-1]==yc[1])g=1;

				}

			}

			else{

				if(f[n]==1){

					if(yc[2]!=yc[n]||yc[n-1]==yc[1])g=1;

				}

				else{

					if(yc[2]!=yc[n]||yc[n-1]!=yc[1])g=1;

				}

			}

		}

	}

	if(g==0){

		for(i=1;i<=n;i++){

			if(yc[i]==1)cout<<'S';

			else cout<<'W';

		}

		return 0;

	}

	yc[1]=0;yc[2]=0;

	g=0;

	for(i=3;i<=n;i++){

		if(yc[i-1]==1){

			if(f[i-1]==1)

				yc[i]=yc[i-2];

			else{

				if(yc[i-2]==1)yc[i]=0;

				else yc[i]=1;

			}

		}

		else{

			if(f[i-1]==1){

				if(yc[i-2]==1)yc[i]=0;

				else yc[i]=1;

			}

			else

			yc[i]=yc[i-2];

		}

	}

	if(yc[1]==1){

		if(f[1]==1){

			if(yc[n]==1){

				if(f[n]==1){

					if(yc[2]!=yc[n]||yc[n-1]!=yc[1])g=1;

				}

				else{

					if(yc[2]!=yc[n]||yc[n-1]==yc[1])g=1;

				}

			}

			else{

				if(f[n]==1){

					if(yc[2]!=yc[n]||yc[n-1]==yc[1])g=1;

				}

				else{

					if(yc[2]!=yc[n]||yc[n-1]!=yc[1])g=1;

				}

			}

		}

		else{

			if(yc[n]==1){

				if(f[n]==1){

					if(yc[2]==yc[n]||yc[n-1]!=yc[1])g=1;

				}

				else{

					if(yc[2]==yc[n]||yc[n-1]==yc[1])g=1;

				}

			}

			else{

				if(f[n]==1){

					if(yc[2]==yc[n]||yc[n-1]==yc[1])g=1;

				}

				else{

					if(yc[2]==yc[n]||yc[n-1]!=yc[1])g=1;

				}

			}

		}

	}

	else{

		if(f[1]==1){

			if(yc[n]==1){

				if(f[n]==1){

					if(yc[2]==yc[n]||yc[n-1]!=yc[1])g=1;

				}

				else{

					if(yc[2]==yc[n]||yc[n-1]==yc[1])g=1;

				}

			}

			else{

				if(f[n]==1){

					if(yc[2]==yc[n]||yc[n-1]==yc[1])g=1;

				}

				else{

					if(yc[2]==yc[n]||yc[n-1]!=yc[1])g=1;

				}

			}

		}

		else{

			if(yc[n]==1){

				if(f[n]==1){

					if(yc[2]!=yc[n]||yc[n-1]!=yc[1])g=1;

				}

				else{

					if(yc[2]!=yc[n]||yc[n-1]==yc[1])g=1;

				}

			}

			else{

				if(f[n]==1){

					if(yc[2]!=yc[n]||yc[n-1]==yc[1])g=1;

				}

				else{

					if(yc[2]!=yc[n]||yc[n-1]!=yc[1])g=1;

				}

			}

		}

	}

	if(g==0){

		for(i=1;i<=n;i++){

			if(yc[i]==1)cout<<'S';

			else cout<<'W';

		}

		return 0;

	}

	cout<<-1;

	return 0;

}