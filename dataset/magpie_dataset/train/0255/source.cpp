#include<iostream>

#include<string>

#include<vector>

#include<set>

#include<algorithm>

#include<cstring>

#include<cstdlib>

#include<cmath>



#define INF 1001



using namespace std;



struct point{

	int x,y,z;

	point():x(0),y(0),z(0){}

	point(int x, int y, int z):x(x),y(y),z(z){}

	bool operator ==(const point &t)const{

		if( x == t.x && y == t.y && z == t.z )

			return true;

		return false;

	}

	bool operator <(const point &t)const{

		if( x < t.x ){

			return true;

		}else if( x == t.x ){

			if( y < t.y ){

				return true;

			}else if( y == t.y ){

				if( z < t.z ){

					return true;

				}

			}

		}

		return false;

	}

	void rot90arndX(){

		int tz = z; z = -y; y = tz;

	}

	void rot90arndY(){

		int tz = z; z = x; x = -tz;

	}

	void rot90arndZ(){

		int tx = x; x = y; y = -tx;

	}

	void set(int x, int y, int z){

		this->x = x; this->y = y; this->z = z;

	}

};



ostream &operator << (ostream &os, const point &t){

	os << '(' << t.x << ',' << t.y << ',' << t.z << ')';

	return os;

}



struct strange_key{

	vector<point> vp;

	vector<point> vcube;



	void rot90arndX(){

		for(unsigned int i = 0; i < vp.size(); ++i){

			vp[i].rot90arndX();

		}

		for(unsigned int i = 0; i < vcube.size(); ++i){

			vcube[i].rot90arndX();

		}

	}

	void rot90arndY(){

		for(unsigned int i = 0; i < vp.size(); ++i){

			vp[i].rot90arndY();

		}

		for(unsigned int i = 0; i < vcube.size(); ++i){

			vcube[i].rot90arndY();

		}

	}

	void rot90arndZ(){

		for(unsigned int i = 0; i < vp.size(); ++i){

			vp[i].rot90arndZ();

		}

		for(unsigned int i = 0; i < vcube.size(); ++i){

			vcube[i].rot90arndZ();

		}

	}

	void MoveToOrigin(int base){

		int dx = vcube[ base ].x;

		int dy = vcube[ base ].y;

		int dz = vcube[ base ].z;

		

		for(unsigned int i = 0; i < vcube.size(); ++i){

			vcube[i].x -= dx;

			vcube[i].y -= dy;

			vcube[i].z -= dz;

		}

		for(unsigned int i = 0; i < vp.size(); ++i){

			vp[i].x -= dx;

			vp[i].y -= dy;

			vp[i].z -= dz;

		}

	}

	bool Same(strange_key &t){

		if( vp.size() != t.vp.size() )

			return false;



		for(int a = 0; a < 4; ++a){

			for(int b = 0; b < 4; ++b){

				for(int c = 0; c < 4; ++c){

					for(unsigned int l = 0; l < vcube.size(); ++l){

						this->MoveToOrigin( l );

						for(unsigned int m = 0; m < vcube.size(); ++m){

							bool bSame = true;

							t.MoveToOrigin( m );

							

							sort( vp.begin(), vp.end() );

							sort( t.vp.begin(), t.vp.end() );



							for(unsigned int n = 0; n < vp.size(); ++n){

								if( !(vp[n] == t.vp[n]) ){

									bSame = false;

									break;

								}

							}

							

							/*

							cout << "Key Expression:";

							for(set<point>::iterator it = sp.begin(); it != sp.end(); ++it){

								cout << *it << ' ';

							}

							cout << "\nKey Expression:";

							for(set<point>::iterator it = t.sp.begin(); it != t.sp.end(); ++it){

								cout << *it << ' ';

							}

							cout << "\n--------------------\n";

							*/



							if( bSame )

								return true;

						}

					}

					rot90arndX();

				}

				rot90arndY();

			}

			rot90arndZ();

		}

		return false;

	}

};



void input_strange_key( istream &is, int n, strange_key &in ){

	if( is ){

		point now;

		bool val[51]={false,};

		vector<point> pos_mem(51);

		int minx=INF, maxx=-INF, miny=INF, maxy=-INF, minz=INF, maxz=-INF;

		

		val[0]=true;

		for(int i = 0; i < n; ++i){

			string s;

			

			cin >> s;

			if( s[0] != '+' && s[0] != '-' ){

				int mem = atoi( s.c_str() );

				if( val[ mem ] ){

					now = pos_mem[ mem ];

				}else{

					pos_mem[ mem ] = now;

					val[ mem ] = true;

				}

			}else{

				int progress = ( s[0] == '+' ? 2 : -2 );

				point next = now;

				switch( s[1] ){

					case 'x':

						now.x += progress / 2;

						in.vp.push_back( now );

						now.x += progress / 2;

						break;

					case 'y':

						now.y += progress / 2;

						in.vp.push_back( now );

						now.y += progress / 2;

						break;

					case 'z':

						now.z += progress / 2;

						in.vp.push_back( now );

						now.z += progress / 2;

						break;

				}

			}

			minx = std::min( minx, now.x ); maxx = std::max( maxx, now.x );

			miny = std::min( miny, now.y ); maxy = std::max( maxy, now.y );

			minz = std::min( minz, now.z ); maxz = std::max( maxz, now.z );

		}

		in.vcube.push_back( point( minx, miny, minz ) );

		in.vcube.push_back( point( minx, miny, maxz ) );

		in.vcube.push_back( point( minx, maxy, minz ) );

		in.vcube.push_back( point( minx, maxy, maxz ) );

		in.vcube.push_back( point( maxx, miny, minz ) );

		in.vcube.push_back( point( maxx, miny, maxz ) );

		in.vcube.push_back( point( maxx, maxy, minz ) );

		in.vcube.push_back( point( maxx, maxy, maxz ) );

	}

}





ostream &operator << (ostream &os, const strange_key &t){

	os << "Key Expression:\n";

	for(unsigned int i = 0; i < t.vp.size(); ++i){

		if( i != 0 )

			os << ' ';

		os << t.vp[i];

	}

	return os;

}



int main(){

	while( true ){

		int n1,n2;

		strange_key a, b;



		cin>>n1;

		if( n1 == 0 )

			break;

		input_strange_key( cin, n1, a );

		cin>>n2;

		input_strange_key( cin, n2, b );



		if( a.Same( b ) )

			cout << "SAME\n";

		else

			cout << "DIFFERENT\n";



	}

	return 0;

}