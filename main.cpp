#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t get_4byte_from_file(const char* fname){
	FILE*fp=fopen(fname,"rb");
	if(fp==NULL){
		printf("can\'t open file \"%s\"\n",fname);
		exit(1);
	}
	uint32_t res;
	if(fread(&res,4,1,fp)!=1){
		printf("can\'t read file \"%s\"\n",fname);
		exit(1);
	}
	fclose(fp);
	return res;
}

int main(int c,char** v){
	if(c!=3){
		printf("usage : add-nbo <file1> <file2>\n");
		return 1;
	}
	uint32_t a=ntohl(get_4byte_from_file(v[1]));
	uint32_t b=ntohl(get_4byte_from_file(v[2]));
	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n",a,a,b,b,a+b,a+b);
	return 0;
}
