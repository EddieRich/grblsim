#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <linux/limits.h>
#include <stdbool.h>
#include "errors.h"
#include "grbl.h"

struct s_options
{
	int homing;
	int verbose;
} options = { 0 };

void show_options()
{
	printf("options:\n");
	printf("  verbose=%d\n", options.verbose);
}

void show_usage(char* appname)
{
	if (appname[0] == '.' && appname[1] == '/')
		appname += 2;

	printf("\nusage: %s [options]\noptions:\n", appname);
	printf("  -h       enable homing\n");
	printf("  -v       verbose, show lots of information\n");
	printf("\n\n");
}

int main(int argc, char* argv[])
{
	int opt;

	while ((opt = getopt(argc, argv, "hv")) != -1)
	{
		// ascii value of option letter
		switch (opt)
		{
		case 'h':
			options.homing = true;
			break;

		case 'v':
			options.verbose = true;
			break;

		default:
		// unknown option
			show_usage(argv[0]);
			exit(E_FAILURE);
		}
	}


	// argc and argv have been modified
	// if a filename (for example) should have been specified but wasn't,
	// optind will = argc, show the error
	//if (optind >= argc)
	//{
	//	show_usage(argv[0]);
	//	show_error(E_EXTRA_ARGS);
	//}
	// filename is *argv[optind]


	if (grbl_init(options.verbose) == E_SUCCESS)
	{
		grbl_homing(options.verbose, options.homing);
		grbl_run(options.verbose);
	}

	exit(E_SUCCESS);
}

