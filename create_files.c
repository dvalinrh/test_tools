#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * simple program to create a file.  Arg 1 is path to the file, arg 2
 * is the size of the file in gig.
 */

#define BUFFER_SIZE 1024*1024

int
main(int argc, char **argv)
{
	FILE *fd;
	int size_g;
	int count, count1;
	char *buffer;
	char buff1[1024];

	fd = fopen(argv[1], "w");
	if (fd == NULL) {
		perror(argv[1]);
		exit (1);
	}
	size_g = atoi(argv[2]);

	buffer = (char *) malloc(BUFFER_SIZE);
	/*
 	 * To keep iozone read happy, use 0x5f.
 	 */
	memset(buffer, 0x5f, BUFFER_SIZE);
	for (count = 0; count < size_g; count++) {
		/*
 		 * Write a gig of data.
 		 */
		for (count1 = 0; count1 < 1024; count1++) {
			if (fwrite(buffer, BUFFER_SIZE, 1, fd) == 0)
				perror("fwrite");
		}
	}
	fclose(fd);
	system(buff1);
	return (0);
}
