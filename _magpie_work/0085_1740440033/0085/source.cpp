#include<iostream>

#include<algorithm>

#include<vector>

#include<map>

using namespace std;



const int N_MAX = 100000;

const int R_MAX = 50;

const int BigNumber = 1000000007;	

long long *Factrial;

const int smallNMax = N_MAX ;



 struct squaence{

	int start,length, counter;

	

	squaence(){}

	squaence(int _start, int _end){

		start = _start;

		length = _end - _start + 1;

		counter = 0;

	}

};



 	

 void SolveForLargeN(int N, int R){

	 int s[R_MAX], t[R_MAX];

			vector<int> st_vector(2*R);

		for(int r=0; r<R; r++){

			int tmp_s, tmp_t;

			cin >> tmp_s >> tmp_t;

			s[r] = tmp_s-1;

			t[r] = tmp_t-1;

			st_vector[2*r  ] = s[r];

			st_vector[2*r+1] = t[r];

		}

		sort(st_vector.begin(), st_vector.end());

		st_vector.erase(unique(st_vector.begin(), st_vector.end()), st_vector.end());

		const int st_vector_size = st_vector.size();

		

		vector<squaence> number(st_vector.size()*2+1);

		int n=0;

		for(int j=0; j<st_vector_size; j++){

			if(n <st_vector[j])number.push_back(squaence(n, st_vector[j]-1));

			n = st_vector[j];

			number.push_back(squaence(n, n));

			n++;

		}

		if(n<N)number.push_back(squaence(n, N-1));

			

		map<int,int> index_map;

		for(int i=0; i<st_vector_size; i++){

			int v = st_vector[i];

			auto it = find_if(number.begin(), number.end(), [v](squaence s){return s.start==v;});

			index_map[v] = distance(number.begin(), it) ;

		}



		for(int r=0; r<R; r++){

			int rs = index_map[s[r]];

			int rt = index_map[t[r]];



			int ns = number[rs].start;

			int nt = number[rt].start;

			int cs = number[rs].counter;

			int ct = number[rt].counter;

				

			if(ns<nt)	ct++;

			else		cs--;

			for(int i=rs+1; i<rt; i++){

				int ni = number[i].start;

				if(ni < nt){

					ct+=number[i].length;

					if(ns<ni) number[i].counter++;

				}

				if(ni < ns){

					cs-=number[i].length;

					if(nt<ni) number[i].counter--;

				}

			}



			number[rs].counter = cs;

			number[rt].counter = ct;

			swap(number[rs], number[rt]);

		}

	

		n=0;

		long long  index = 0;

		const int number_size = number.size();

		for(int i=0; i<number_size; i++){

			const squaence* s = &number[number_size-1-i];

			if(s->counter != 0){

				long long f = 0;

				for(int j=0; j< s->length; j++,n++){

					f += Factrial[n] % BigNumber;

				}

				index += s->counter * f % BigNumber;

			}

			else{

				n += s->length;

			}

		}

		cout << index%BigNumber << endl;

 }

 void SolveForSmallN(int N, int R){



	long long RevFactrial[smallNMax];

	int number[smallNMax], counter[smallNMax];

	

	RevFactrial[smallNMax-1] = 1;

	for(int i=smallNMax-2; i>=0; i--){

		RevFactrial[i] =  (RevFactrial[i+1] * (smallNMax -i-1)) % BigNumber;

	}





	 for(int n=0; n<N; n++){

			number[n] = n;

			counter[n] = 0;

		}

		

		for(int r=0; r<R; r++){

			int s, t;

			cin >> s >> t;

			s--; t--;

			int ns = number[s];

			int nt = number[t];

			int cs = counter[t];

			int ct = counter[s];

				

			if(ns<nt)	cs++;

			else		ct--;

			for(int i=s+1; i<t; i++){

				int ni = number[i];

				if(ni < nt){

					cs++;

					if(ns<ni) counter[i]++;

				}

				if(ni < ns){

					ct--;

					if(nt<ni) counter[i]--;

				}

			}



			counter[s] = cs;

			counter[t] = ct;

			number[s] = nt;

			number[t] = ns;

		}



		long long  index = 0;

		for(int i=0; i<N-1; i++){

			index  +=  counter[i]*RevFactrial[smallNMax-N+i]%BigNumber;

		}

		cout << index%BigNumber << endl;

 }



int main(){

	Factrial = new long long[N_MAX];



	Factrial[0] = 1;

	for(int i=1; i<N_MAX; i++){

		Factrial[i] =  (Factrial[i-1] * i) % BigNumber;

	}



	int N,R;

	while(true){

		cin >> N;

		if(N==0) break;

		cin >> R;



		if(N>smallNMax) SolveForLargeN(N,R);

		else SolveForSmallN(N,R);

	

	}

	delete[] Factrial;

	return 0;

}