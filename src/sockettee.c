// file: sockettee.c
// author: smg
// description: a program to take a packet and forward it to two different places, 
// the place it was supposed to go, and a designated location for logging or analysis 
// or whatever. 
// this program is in plain jane C
// this isn't going so well. my brain isn't processing this well. 


#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdbool.h>


#include "rlutils.h"
#include "sockettee.h"

GLOBALS g;
PROGOPTS p;

/*
C function that processes both short and long options using the getopt function. This function will handle command-line arguments and parse both short options (like -a) and long options (like --option).
it will set state flags in the global area. 
*/
int process_options(int argc, char *argv[]) {
    int opt;
    // Define the long options
    struct option long_options[] = {
        {"help", no_argument, NULL, 'h'},
        {"verbose", no_argument, NULL, 'v'},
        {"listen-ip", required_argument, NULL, 'l'},
        {"listen-port",required_argument, NULL,'p' },
        {"destination1-ip", required_argument, NULL, 'l'},
        {"destination1-port",required_argument, NULL,'p' },
        {"destination2-ip", required_argument, NULL, 'l'},
        {"destination2-port",required_argument, NULL,'p' },
        {0, 0, 0, 0}  // End of options
    };

    while ((opt = getopt_long(argc, argv, "hvo:", long_options, NULL)) != -1) {
        switch (opt) {
            case 'h': {
            fprintf(stderr, "Usage: %s \n\t
            -l, --listen-ip  <listen_ip> \n\t
            -p, --listen-port <listen_port> \n\t
            -m, --destination1-ip <dest1_ip> \n\t
            -M, --destination1-port  <dest1_port> \n\t
            -n, --destination2-ip <dest2_ip>
            -N, --destination2-port  <dest2_port>\n\t
            -v, --verbose\n\t
            -h, --help\n\t

            \n", argv[0]);
                exit(0);
            }
            case 'v':
                printf("Verbose mode enabled.\n");
                p.verbose = 1;
                break;
            case 'o':
                printf("Output file: %s\n", optarg);
                p.output = 
                break;
            case 'r':
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
    return 0;
}

void redirect_packets(int listen_sock, const char *dest1_ip, int dest1_port, const char *dest2_ip, int dest2_port) {
    char buffer[BUFFER_SIZE];
    struct sockaddr_in dest1_addr, dest2_addr;

    opensocket(&dest1_addr)

    memset(&dest2_addr, 0, sizeof(dest2_addr));
    dest2_addr.sin_family = AF_INET;
    dest2_addr.sin_port = htons(dest2_port);
    if (inet_pton(AF_INET, dest2_ip, &dest2_addr.sin_addr) <= 0) {
        error_exit("invalid destination 2 address");
    }

    while (1) {
        ssize_t bytes_received = recv(listen_sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            perror("recv failed");
            continue;
        }

        if (sendto(listen_sock, buffer, bytes_received, 0, (struct sockaddr *)&dest1_addr, sizeof(dest1_addr)) < 0) {
            perror("sendto dest1 failed");
        }

        if (sendto(listen_sock, buffer, bytes_received, 0, (struct sockaddr *)&dest2_addr, sizeof(dest2_addr)) < 0) {
            perror("sendto dest2 failed");
        }
    }
}


int opensocket(sock_addr, sock_port, ) {
    int err = 0;
    memset(&sock_addr, 0, sizeof(sock_addr));
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(sock_port);
    if (inet_pton(AF_INET, sock_addr, &sock_addr.sin_addr) <= 0) {
        err = 127;
        error_exit("invalid destination 1 address");
    }
    return err;
}

int closesocket(int socketid) {
    int err = 0;
    return err;

}

// main routine
int main(int argc, char * argv[]) {
    char buffer[BUFFER_SIZE];
    struct sockaddr_in dest1_addr, dest2_addr;
    if (argc != 6) {
        fprintf(stderr, "Usage: %s \n\t
            -l, --listen-ip  <listen_ip> \n\t
            -p, --listen-port <listen_port> \n\t
            -m, --destination1-ip <dest1_ip> \n\t
            -M, --destination1-port  <dest1_port> \n\t
            -n, --destination2-ip <dest2_ip>
            -N, --destination2-port  <dest2_port>\n\t
            -v, --verbose\n\t
            -h, --help\n\t

            \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int err = 0;
    // process options runs the arguments and sets a bunch of flags. 
    process_options(argc, argv); 

    return err;
}