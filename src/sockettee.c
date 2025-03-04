// file: sockettee.c
// author: smg
// description: a program to take a packet and forward it to two different places, 
// the place it was supposed to go, and a designated location for logging or analysis 
// or whatever. 
// this program is in plain jane C

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <inet.h>

#include "rlutils.h"
#include "sockettee.h"


/*
Here's an example C function that processes both short and long options using the getopt function. This function will handle command-line arguments and parse both short options (like -a) and long options (like --option).
*/
void process_options(int argc, char *argv[]) {
    int opt;
    // Define the long options
    struct option long_options[] = {
        {"help", no_argument, NULL, 'h'},
        {"verbose", no_argument, NULL, 'v'},
        {"output", required_argument, NULL, 'o'},
        {0, 0, 0, 0}  // End of options
    };

    while ((opt = getopt_long(argc, argv, "hvo:", long_options, NULL)) != -1) {
        switch (opt) {
            case 'h':
                printf("Usage: %s [options]\n", argv[0]);
                printf("  -h, --help        Display this help message\n");
                printf("  -v, --verbose     Enable verbose output\n");
                printf("  -o, --output      Specify output file\n");
                exit(0);
            case 'v':
                printf("Verbose mode enabled.\n");

                break;
            case 'o':
                printf("Output file: %s\n", optarg);
                break;
            case '?':
                // getopt handles invalid options
                break;
            default:
                printf("Unknown option: %c\n", opt);
                exit(1);
        }
    }

    // If there are extra arguments, they are left in argv[optind:]
    if (optind < argc) {
        printf("Extra arguments: ");
        for (int i = optind; i < argc; i++) {
            printf("%s ", argv[i]);
        }
        printf("\n");
    }
}



int opensocket(int socketid) {
    int err = 0;
    return err;
}

int closesocket(int socketid) {
    int err = 0;
    return err;

}

// main routine
int main(int argc, char * argv[]) {
    int err = 0;
    process_options(argc, argv);

    return err;
}