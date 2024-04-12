#include <stdio.h>
#include "file.h"

// Function to copy file

int fcopy(const char* sourceName, const char* DestinationName) {
	FILE* fptr_s{}; // file pointer to source
	FILE* fptr_d{}; // file pointer to destination
	errno_t f_open_s{}; // errno_t to check errors while opening files
	errno_t f_open_d{};

	// successfull only if f_open_s is 0
	f_open_s = fopen_s(&fptr_s, sourceName, "r"); 
	if (f_open_s) return 1; // returns 1 if source file couldn't open
	f_open_d = fopen_s(&fptr_d, DestinationName, "w");
	if (f_open_d) return -1; // returns -1 if destination file couldn't open

	char c{};
	while ((c, c = getc(fptr_s)) != EOF) { // extracting data as a char until End Of File 
		putc(c, fptr_d); // writing data as a char to the File
	}

	// successfull closed only if EOF not returned
	if (fclose(fptr_d) == EOF) return 2; // returns 2 if destination file couldn't be closed
	if (fclose(fptr_s) == EOF) return -2;// returns -2 if source file couldn't be closed

	return 0;
	

}
