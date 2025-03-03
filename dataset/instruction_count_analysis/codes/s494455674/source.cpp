#include<iostream>

#include<cmath>

#include<algorithm>



using namespace std;



struct A{

	int x,y,h;

}a[100];



int main()

{

	int N,X,Y,H,h;

	int j,s;

	cin>>N;

	for(int i=0;i<N;i++)

	{

		cin>>a[i].x>>a[i].y>>a[i].h;

		if(a[i].h) s=i;

	} 

	for(X=0;X<=100;X++)

	{

		for(Y=0;Y<=100;Y++)

		{

			H=abs(a[s].x-X)+abs(a[s].y-Y)+a[s].h;

			for(j=0;j<N;j++)

			{

				h=max(H-abs(a[j].x-X)-abs(a[j].y-Y),0);

				if(h!=a[j].h)	break;

			}

			if(j==N) cout<<X<<' '<<Y<<' '<<H;

		}

	}

	return 0;

 } 