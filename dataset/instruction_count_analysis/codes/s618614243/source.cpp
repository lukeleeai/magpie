#include <iostream>

#include <cmath>

using namespace std;

int x[102],y[102],h[102];

int c_x,c_y,c_h;

int max_h;

int main()

{

	int n;

	scanf("%d",&n);

	max_h = -1;

	for(int i = 1;i <= n;i ++)

	{

		scanf("%d%d%d",x + i,y + i,h + i);

		max_h = max(max_h,h[i]);

	}

	int sign = 1;

	for(c_h = max_h;sign;c_h ++)

		for(c_x = 0;sign && c_x <= 100;c_x ++)

			for(c_y = 0;sign && c_y <= 100;c_y ++)

			{

				int i = 1;

				for(;i <= n;i ++)

					if(h[i] != max(0,(c_h - abs(c_x - x[i]) - abs(c_y - y[i]))))

						break;

				if(i > n)

					sign = 0;

			}

	printf("%d %d %d\n",c_x - 1,c_y - 1,c_h - 1);

	return 0;

}