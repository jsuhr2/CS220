#include "bits.h"
#include <stdio.h>

void print_in_binary(unsigned int x){
	unsigned int b;
	int i;
	for (i = 31; i >= 0; i--){
		b = BIT(i);
		if(IS_SET_ANY(x, b))
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}

unsigned int get_page_offset(unsigned int address){
	unsigned int b;
	b = BF_GET(address + 11, address, 12);
	return b;
}

unsigned int get_tlb_id(unsigned int address){
	unsigned int b;
	b = BF_GET(address + 14, address + 12, 3);
	return b;
}

unsigned int get_tlb_tag(unsigned int address){
	unsigned int b;
	b = BF_GET(address + 31, address + 24, 8);
	return b;
}

unsigned int set_page_offset(unsigned int address, unsigned int new_offset){
	unsigned int b;
	b = BF_SET(address, new_offset + 11, new_offset, 12);
	return b;
}

unsigned int set_tlb_id(unsigned int address, unsigned int new_tlb_id){
	unsigned int b;
	b = BF_SET(address + 12, new_tlb_id + 2, new_tlb_id, 3);
	return b;
}

unsigned int set_tlb_tag(unsigned int address, unsigned int new_tag){
	unsigned int b;
	b = BF_SET(address + 24, new_tag + 7, new_tag, 8);
	return b;
}
