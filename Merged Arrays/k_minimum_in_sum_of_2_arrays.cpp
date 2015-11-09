#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct node {
	int val, id;
	node(int val_t, int id_t) {
		val = val_t;
		id = id_t;
	}
	bool operator > (const struct node& u) const {
		return val < u.val;
	}	
	bool operator < (const struct node& u) const {
		return val > u.val;
	}
	bool operator == (const struct node& u) const {
		return val == u.val;
	}
};

class Solution{
public:
	vector<int> get_k_minimum(vector<int> &a, vector<int> &b) {
		vector<int> ret;
	 	int n = a.size();
		priority_queue<node> q;
		vector<int> p;
		p.assign(n, 0); // pointers to current b[] positions in each line
		for(int i = 0; i < n; i++) {
			node tmp(a[i] + b[0], i);
			q.push(tmp);
		}
		int count = 0;
		while(count < n) {
			node top = q.top();
			q.pop();
			ret.push_back(top.val);
			node tmp(a[top.id] + b[++p[top.id]], top.id);// position pointer increment by 1
			q.push(tmp);
			++count;
		}
		return ret;				
	}
};

int main() {
	int n, x;
	freopen("in", "r", stdin);
	Solution obj;
	while(~scanf("%d", &n)){
		vector<int> a,b;
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			a.push_back(x);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			b.push_back(x);
		}
		vector<int> ans;
		ans = obj.get_k_minimum(a,b);
		for (int i = 0; i < n; i++) {
			printf("%d ", ans[i]);
		}
		puts("");
	}	
	return 0;
}
