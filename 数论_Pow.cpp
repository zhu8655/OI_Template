LL pow(LL a, LL b, LL p){
	LL q = 1;
	for ( ; b > 0; b >>= 1){
		if (b & 1) q = (q * a) % p;
		a = (a * a) % p;
	} return q;
}