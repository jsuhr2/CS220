#include <stdio.h>
struct bad_struct{
	short s1;
	long l1;
	short s2;
};

struct good_struct{
	short s1;
	short s2;
	long l1;
};

union unit{
	char c;
	int i;
	long l;
};

unsigned int foo(int x[]){
	return sizeof(x);
}

int main(){
	struct good_struct gs;
	struct bad_struct bs;
	printf("sizeof(gs) = %d,	sizeof(bs) = %d\n", sizeof(gs), sizeof(bs));
	printf("bad_struct locations:  s1: %p, l1: %p, s2: %p\n", &bs.s1, &bs.l1, &bs.s2);
	printf("good_struct locations: s1: %p, s2: %p, l1: %p\n", &gs.s1, &gs.s2, &gs.l1);

	union unit u;
	printf("sizeof(u) = %d\n", sizeof(u));
	printf("unit locations: c: %p, i: %p, l: %p\n", &u.c, &u.i, &u.l);
	scanf("%lu", &u.l);
	printf("%d\n", (int) sizeof(u));
	printf("%c, %lu, %d, %s\n", u.c, u.l, u.i, &u.l);

	int x[10];
	printf("sizeof(x) = %d\n", sizeof(x));
	printf("foo(x) = %d\n", foo(x));
	
	int y[20];
	printf("sizeof(y) = %d\n", sizeof(y));
	printf("foo(y) = %d\n", foo(y));
	
	int z[30];
	printf("sizeof(z) = %d\n", sizeof(z));
	printf("foo(z) = %d\n", foo(z));

	return 0;
}
