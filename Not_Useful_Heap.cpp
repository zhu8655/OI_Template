/*=====Template_Heap=====*/
struct heap{
	#define hMAXN 10010
	int hCnt, a[hMAXN], idx[hMAXN][2];
	inline void clear(){hCnt = 0;}
	inline void swp(int p, int q){a[q] = a[p]; idx[q][0] = idx[p][0];}
	inline void maintain(int p){idx[idx[p][0]][1] = p;}
	void swim(int p){
		int tmp[] = {a[p], idx[p][0]};
		for (int q = p >> 1; q > 0; p = q, q >>= 1){
			if (a[q] > tmp[0]){
				swp(q, p); maintain(p);
			} else break;
		} a[p] = tmp[0]; idx[p][0] = tmp[1]; maintain(p);
	}
	void sink(int p){
		int tmp[] = {a[p], idx[p][0]};
		for (int q = p << 1; q <= hCnt; p = q, q <<= 1){
			if (q < hCnt && a[q] > a[q+1]) q++;
			if (a[q] < tmp[0]){
				swp(q, p); maintain(p);
			} else break;
		} a[p] = tmp[0]; idx[p][0] = tmp[1]; maintain(p);
	}
	void push(int x){a[++hCnt] = x; swim(hCnt);}
	void push(int x, int p){a[++hCnt] = x; idx[hCnt][0] = p; swim(hCnt);}
	int pop(int p){int ret = a[p]; swp(hCnt, p); a[hCnt] = idx[hCnt][0] = 0; hCnt--; swim(p); sink(p); return ret;}
} h;