#include<iostream>

#include<map>

#include<set>

#include<list>

#include<queue>

#include<cmath>

#include<string>

#include<iomanip>

#include<algorithm>

using namespace std;



int main()

{

	long long num;

	int cnt1,cnt2,temp,k,MAX,MIN = 99;//最大位数99 

	cin >> num;

	int t = sqrt(num);

	for(int i = t;i >= 1;i--)

	{

		if(num%i == 0)

		{

			k = i;

			cnt1 = 0;//记录位数 

			cnt2 = 0;

			MAX = 0;//记录本次位数最大 

			temp = num/i;

			while(k)

			{

				k /= 10;

				cnt1++;

			}

			while(temp)

			{

				temp /= 10;

				cnt2++;

			}

			MAX = max(cnt1,cnt2);//每次中的最大 

			MIN = min(MAX,MIN);	//每次保留最大中的最小	

		}	

	}

	cout << MIN << endl;

	return 0; 

}