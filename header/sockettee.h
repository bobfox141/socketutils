// file: sockettee.h
// author: smg

#ifndef SOCKETTEE_H
#define SOCKETTEE_H

#define BUFFER_SIZE 4096


typedef struct progoptflags_tag {
    int verbose; 
    int help; 
    int outputfile; 
    char ofname[100];
    
} PROGOPTS;

struct globals{
    int listensockfd;
    int outputsockfd;
    int destsockfd;
    char *listen_ip;
    int listen_port;
    char *dest1_ip;
    int dest1_port;
    char *dest2_ip;
    int dest2_port;

    struct sockaddr_in listen_addr;
    struct sockaddr_in dest_addr;
    struct sockaddr_in analyze_addr;

} GLOBALS;




#endif 
