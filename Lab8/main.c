#include <stdio.h>
int main(){
	print_in_binary(10);
	unsigned int g1, g2, g3, s1, s2, s3;
	g1 = get_page_offset(0xf712c0d0);
	g2 = get_tlb_id(0xf712c0d0);
	g3 = get_tlb_tag(0xf712c0d0);

	s1 = set_page_offset(0xf712c0d0, 0x1a3);
	s2 = set_tlb_id(0xf712c0d0, 0);
	s3 = set_tlb_tag(0xf712c0d0, 0x8400);

	printf("Get:\n%li\n%li\n%li\nSet:\n%li\n%li\n%li\n", g1, g2, g3, s1, s2, s3);

	return 0;
}
