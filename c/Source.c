#include<stdio.h>
#include<stdbool.h>

int main() {
	FILE* f;
	fopen_s(&f, "sentences.txt", "r");
	char character;
	int linenum = 0;
	int counter = 0;
	char sentence[80];
	bool has = false;
	int count = 0;
	char upppercasealphabet[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	int alphabetindex[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int pangrams = 0;
	for (int x = 0; x < 80; x++) {
		sentence[x] = ' ';
	}
	while (1) {
		 
		character = fgetc(f);
		 if (feof(f)) {
			 break;
		 }
		 if (character == '\n') {
			 linenum++;
			 counter = 0;
			 for (int i = 0; i < 80; i++) {
					 for (int j = 0; j < 26; j++) {
						 if (sentence[i] == alphabet[j]) {
							 if (alphabetindex[j] == 0) {
								 count++;
								 alphabetindex[j] = 1;
						 }
						 }
								
					 }
				 if (has) {
					 count++;
					 has = false;
				 }
			 }
			 for (int i = 0; i < 80; i++) {
				 for (int j = 0; j < 26; j++) {
					 if (sentence[i] == upppercasealphabet[j]) {
						 if (alphabetindex[j] == 0) {
							 count++;
							 alphabetindex[j] = 1;
						 }
					 }

				 }
				 if (has) {
					 count++;
					 has = false;
				 }
			 }
			 if (count == 26) {
				 printf("%d: ", linenum);
				 for (int x = 0; x < 80; x++) {
					 printf("%c", sentence[x]);
				 }
				 printf("\n");
				 pangrams++;
			 }
			 count = 0;
			 for (int j = 0; j < 26; j++) {
				 alphabetindex[j] = 0;
			 }
			 for (int x = 0; x < 80; x++) {
				 sentence[x] = ' ';
			 }
		 }
		 else {
			 sentence[counter] = character;
			 counter++;
		 }
	 }
	printf("%d pangrams found.\n", pangrams);
}