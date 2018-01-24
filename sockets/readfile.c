#include <stdio.h>



int main() {


	char buffer[256];
	bzero(buffer, MAX_BUFFER_SIZE);
	FILE *fp;
	int numwords = 0;
	char c;

	fp = fopen(filename, "r");
	while ((c = fgetc(fp)) != EOF) {
		fscanf(fp, "%s", buffer);
		if (isspace(c) || c == '\t') {
			++numwords;
		}
	}

    return 0;
}