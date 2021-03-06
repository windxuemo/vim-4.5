/*
 * This program, when compiled with Turbo-C, will make <LF> into <CR><LF>
 */

#include <stdio.h>

char buffer[1024];

main(argc, argv)
	int argc;
	char **argv;
{
	int	len;

	while ((len = fread(buffer, 1, 1024, stdin)) > 0)
		fwrite(buffer, 1, len, stdout);
	if (ferror(stdin))
		fprintf(stderr, "Error while reading\n");
	if (ferror(stdout))
		fprintf(stderr, "Error while writing\n");
}
