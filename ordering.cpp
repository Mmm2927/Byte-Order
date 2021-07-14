#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t my_htonl(uint32_t a){
	a = (a & 0xff000000) >> 24 | (a & 0x00ff0000) >> 8 | (a & 0x0000ff00) << 8| (a & 0x000000ff) << 24;
	return a;
}

int main(int argc, char** argv){
	uint32_t fir;
	uint32_t sec;

	FILE *a = fopen(argv[1],"rb");
	FILE *b = fopen(argv[2],"rb");

	if(a == NULL || b == NULL){
		printf("Something is wrong");
		exit(1);
	}
	fread(&fir, sizeof(fir), 1, a);
	fread(&sec, sizeof(sec), 1, b);

	fir = my_htonl(fir);
	sec = my_htonl(sec);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)",fir,fir,sec,sec,fir+sec,fir+sec);
}
