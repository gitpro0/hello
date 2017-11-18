#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>

struct option longopts[] =
{
	{"greeting",	required_argument,	NULL,	'g'},
	{"help",	no_argument,		NULL,	'h'},
	{"traditional",	no_argument,		NULL,	't'},
	{"version",	no_argument,		NULL,	'v'},
	{NULL, 		0, 			NULL, 	 0 }
};

static const char version[] = "1.0";

void print_help();
void print_version();

int main(int argc, char *argv[])
{
	int optc;
	int lose = 0;
	const char *greeting_msg;

	greeting_msg = "Hello World!";

	while(( optc = getopt_long(argc, argv, "g:htv", longopts, NULL)) != -1)
	{
		switch(optc)
		{
			case 'v':
				print_version();
				exit(EXIT_SUCCESS);
				break;
      			case 'g':
				greeting_msg = optarg;
				break;
      			case 'h':
				print_help ();
				exit(EXIT_SUCCESS);
				break;
      			case 't':
				greeting_msg = "hello, world";
				break;
      			default:
				lose = 1;
				break;
		}
	}

	if(lose || optind < argc)
	{
		printf("error\n");
		print_help();
		exit(EXIT_SUCCESS);
	}

	printf("%s\n", greeting_msg);
}

void print_help()
{
	printf("Usage: hello [OPTION]...\n");
	printf("Print a friendly, customizable greeting.\n");
}

void print_version()
{
	printf("hello version %s\n", version);
}
