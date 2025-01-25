#include <cstdio>

#include <cmath>

#include <cstring>

#include <utility>

#include <queue>

#include <vector>

#include <string>

#include <set>

#include <functional>

#include <algorithm>

#include <iostream>

using namespace std;

typedef long long LL;

typedef pair<int,int> P;

struct Node {

	int val;

	Node *prev;

	Node *next;

	Node(int v) {

		val=v;

		prev=next=NULL;

	}

};

Node *head=NULL,*tail=NULL;

void add(int val) {

	Node *New=new Node(val);

	if(head==NULL) {

		head=tail=New;

	}else {

		tail->next=New;

		New->prev=tail;

		tail=New;

	}

}

void del(Node *node) {

	if(node->prev!=NULL) {

		node->prev->next=node->next;

	}else {

		head=node->next;

	}

	if(node->next!=NULL) {

		node->next->prev=node->prev;

	}else {

		tail=node->prev;

	}

	delete node;

}

bool OK[200000];

int main() {

	int N,M,Q;

	scanf("%d %d %d",&N,&M,&Q);

	for(int i=0;i<N;i++) {

		add(i);

	}

	Node *cur=head;

	for(int i=0;i<M;i++) {

		int a;

		scanf("%d",&a);

		if(a&1) {

			for(int i=0;i<a;i++) {

				cur=cur->prev;

				if(cur==NULL) cur=tail;

			}

			Node *tmp=cur;

			cur=cur->next;

			if(cur==NULL) cur=head;

			del(tmp);

		}else {

			for(int i=0;i<a;i++) {

				cur=cur->next;

				if(cur==NULL) cur=head;

			}

			Node *tmp=cur;

			cur=cur->next;

			if(cur==NULL) cur=head;

			del(tmp);

		}

	}

	for(Node *cur=head;cur!=NULL;cur=cur->next) {

		OK[cur->val]=1;

	}

	for(int i=0;i<Q;i++) {

		int q;

		scanf("%d",&q);

		printf("%d\n",OK[q]);

	}

}