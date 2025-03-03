#include <cstdio>

#include <iostream>



int c[301000];

int a[301000], st[301000], top, n;



void add(int x) {for(int i = x; i <= n; i += i & -i) c[i]++;}

int query(int x) {int ans = 0;for(int i = x; i; i -= i & -i) ans += c[i]; return ans;}



bool check1()

{

	for(int i = 1; i <= n; i++)

	{

		if((a[i] - i) & 1) return false;

	}

	return true;

}



bool check2()

{

	for(int i = 1; i <= n - 2; i++)

	{

		if(a[i] != i && a[i + 1] != i + 1 && a[i + 2] != i + 2) return false;

	}

	return true;

}



bool check3()

{

	long long sum = 0;

	for(int i = n; i >= 1; i--)

	{

		sum += query(a[i]);

		add(a[i]);

	}

	if(sum % 3 != 0) return false;

	return true;

}



bool check4()

{

	top = 0;

	st[++top] = a[1];

	for(int i = 3; i <= n; i += 2)

	{

		if(st[top] > a[i]) st[++top] = a[i];

		else

		{

			int l = 1, r = top + 1;

			while(l < r)

			{

				int mid = l + r >> 1;

				if(st[mid] < a[i]) r = mid;

				else l = mid + 1;

			}

			st[r] = a[i];

		}

	}

	if(top > 2) return false;

	top = 0;

	st[++top] = a[2];

	for(int i = 2; i <= n; i += 2)

	{

		if(st[top] > a[i]) st[++top] = a[i];

		else

		{

			int l = 1, r = top + 1;

			while(l < r)

			{

				int mid = l + r >> 1;

				if(st[mid] < a[i]) r = mid;

				else l = mid + 1;

			}

			st[r] = a[i];

		}

	}

	if(top > 2) return false;

	return true;

}



int main()

{

	scanf("%d", &n);

	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

	if(check1() && check2() && check3() && check4()) puts("Yes");

	else puts("No");

	return 0;

}