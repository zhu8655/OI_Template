/*=====Template_SBT=====*/
struct SBT{
	#define sMAXN 10010
	int treeCnt, root;
	struct tnode{int data, lc, rc, size;} tree[sMAXN];
	inline void clear(){treeCnt = 0; root = 0;}
	inline void leftRot(int &x){
		int k = tree[x].rc;
		tree[x].rc = tree[k].lc;
		tree[k].lc = x;
		tree[k].size = tree[x].size;
		tree[x].size = tree[tree[x].lc].size + tree[tree[x].rc].size + 1;
		x = k;
	}
	inline void rightRot(int &x){
		int k = tree[x].lc;
		tree[x].lc = tree[k].rc;
		tree[k].rc = x;
		tree[k].size = tree[x].size;
		tree[x].size = tree[tree[x].lc].size + tree[tree[x].rc].size + 1;
		x = k;
	}
	void maintain(int &x, bool fg){
		if (!fg){
			if (tree[tree[tree[x].lc].lc].size > tree[tree[x].rc].size)
				rightRot(x);
			else if (tree[tree[tree[x].lc].rc].size > tree[tree[x].rc].size){
				leftRot(tree[x].lc);
				rightRot(x);
			}
			else return;
		}
		else{
			if (tree[tree[tree[x].rc].rc].size > tree[tree[x].lc].size)
				leftRot(x);
			else if (tree[tree[tree[x].rc].lc].size > tree[tree[x].lc].size){
				rightRot(tree[x].rc);
				leftRot(x);
			}
			else return;
		}
		maintain(tree[x].lc, 0);
		maintain(tree[x].rc, 1);
		maintain(x, 1);
		maintain(x, 0);
	}
	void ins(int &x, int data){
		if (x == 0){
			x = ++treeCnt;
			tree[x].lc = tree[x].rc = 0;
			tree[x].size = 1; tree[x].data = data;
		}
		else{
			tree[x].size++;
			ins((data < tree[x].data) ? (tree[x].lc) : (tree[x].rc), data);
			maintain(x, data >= tree[x].data);
		}
	}
	int del(int &x, int data){
		int tmp;
		tree[x].size--;
		if (data == tree[x].data || data < tree[x].data && tree[x].lc == 0 || data > tree[x].data && tree[x].rc == 0){
			tmp = tree[x].data;
			if (tree[x].lc && tree[x].rc)
				tree[x].data = del(tree[x].lc, tree[x].data + 1);
			else
				x = tree[x].lc + tree[x].rc;
		}
		else if (data < tree[x].data) tmp = del(tree[x].lc, data);
		else if (data > tree[x].data) tmp = del(tree[x].rc, data);
		return tmp;
	}
	bool find(int x, int data){
		if (x == 0) return 0;
		if (data < tree[x].data) return find(tree[x].lc, data);
		else return (tree[x].data == data || find(tree[x].rc, data));
	}
	int rank(int x, int data){
		if (x == 0) return 1;
		if (data <= tree[x].data) return rank(tree[x].lc, data);
		return rank(tree[x].rc, data) + tree[tree[x].lc].size + 1;
	}
	int select(int x, int k){
		int r = tree[tree[x].lc].size + 1;
		if (k == r) return tree[x].data;
		if (k < r) return select(tree[x].lc, k);
		return select(tree[x].rc, k - r);
	}
	inline int getmin(){
		int x;
		for (x = root; tree[x].lc; x = tree[x].lc);
		return tree[x].data;
	}
	inline int getmax(){
		int x;
		for (x = root; tree[x].rc; x = tree[x].rc);
		return tree[x].data;
	}
	int pred(int x, int data){
		if (x == 0) return data;
		if (data <= tree[x].data)
			return pred(tree[x].lc, data);
		else{
			int tmp = pred(tree[x].rc, data);
			if (tmp == data) tmp = tree[x].data;
			return tmp;
		}
	}
	int succ(int x, int data){
		if (x == 0) return data;
		if (tree[x].data <= data)
			return succ(tree[x].rc, data);
		else{
			int tmp = succ(tree[x].lc, data);
			if (tmp == data) tmp = tree[x].data;
			return tmp;
		}
	}
} bst;