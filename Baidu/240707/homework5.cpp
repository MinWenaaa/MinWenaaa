#include<iostream>
using namespace std;

//RE

class node {
public:
	node* next;
	int key;
	int value;
	node(int key, int value, node* n = NULL) : key(key), value(value), next(n) {}
	bool insert(int k, int v) {
		node* cur1 = this;
		node* cur2 = this;
		while (cur1->next) {
			cur2 = cur1;
			cur1 = cur1->next;
			if (cur1->key == k) {
				cur1->value += v;
				return true;
			}
			if (cur1->key > k) {
				cur2->next = new node(k, v, cur1);
				return true;
			}
		}
		cur1->next = new node(k, v);
	}
	void print() {
		node* cur = this;
		while (cur) {
			if(cur->value)cout << cur->value << " " << cur->key << endl;
			cur = cur->next;
		}
	}

	void destroy() {
		node* cur = this;
		while (cur) {
			node* next = cur->next;
			delete cur;
			cur = next;
		}
		delete this;
	}
};

int main() {
	int a, b;
	cin >> a >> b;
	a += b;
	int m, n;
	node* head = new node(-1, 0);
	while (a--) {
		cin >> m >> n;
		head->insert(n, m);
	}
	head->print();
	head->destroy();
	return 0;
}