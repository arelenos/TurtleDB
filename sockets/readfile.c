#include <stdio.h>
#include <stdlib.h>


int main() {


	char buffer[256];
	FILE *fp;
	fp = fopen("rnd_file_xfer.txt", "r");
	if (! fp) {
		printf("File not found.\n");
		exit(1);
	}
	while (fgets(buffer, 500, fp)) {
		printf("%s", buffer);
	}
	printf("\n");

    return 0;
}