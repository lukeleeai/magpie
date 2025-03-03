#include<iostream>

using namespace std;



int main()

{

	int n;

	while(cin>>n)

	{

		int ans=n%10;

		if(ans==2||ans==4||ans==5||ans==7||ans==9)

		cout<<"hon"<<endl;

		else if(ans==0||ans==1||ans==6||ans==8)

		cout<<"pon"<<endl;

		else

		cout<<"bon"<<endl;

	}

	

return 0;

}