#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdint.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include "cadef.h"
#include <aSubRecord.h>
#include <registryFunction.h>
#include <epicsExport.h>

//#define IPADDR "10.0.142.181"
//#define PORT 5000
#define BUFFER_SIZE 1024

void byteArrayToFloatArray(const uint8_t *byteArray, float *floatArray, size_t floatCount) {
    for (size_t i = 0; i < floatCount; i++) {
        // Assuming the byte array is in little-endian format
        uint32_t temp = (byteArray[i * 4]) |
                        (byteArray[i * 4 + 1] << 8) |
                        (byteArray[i * 4 + 2] << 16) |
                        (byteArray[i * 4 + 3] << 24);
        floatArray[i] = *((float *)&temp);
    }
}

int getUDPloop(float *data, char *IPset){

    char *IPADDR = strtok(IPset,":");
    int PORT = atoi(strtok(NULL,":"));

    int sockfd;
    unsigned char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    socklen_t len = sizeof(server_addr);

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
//        exit(EXIT_FAILURE);
        return(1);
    }
    struct timeval timeout;
    timeout.tv_sec = 2;
    timeout.tv_usec = 0;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("setsockopt failed");
        close(sockfd);
    }
    if (setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("setsockopt send timeout failed");
        close(sockfd);
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, IPADDR, &server_addr.sin_addr) <= 0) {
        perror("invalid address/ address not supported");
        close(sockfd);
        return(2);
    }
    ssize_t bytes_sent = sendto(sockfd, "Loop", 4, 0, (const struct sockaddr *) &server_addr, sizeof(server_addr));
    if(bytes_sent < 0) {
        perror("sendto failed");
        close(sockfd);
        return(3);
    }
    int n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *) &server_addr, &len);
    buffer[n] = '\0';
    if(n<0){
        if (errno == EAGAIN || errno == EWOULDBLOCK) {
            printf("UDP receive timed out!\n");
        } else {
            perror("sendto failed");
        }
        return(4);
    }
    byteArrayToFloatArray(buffer, data, 60);
    close(sockfd);
    return(0);
}

static int StatSub(aSubRecord *precord) {

    char *IPset = (char *)precord->a;
    float data[60];
    int status;

    status = getUDPloop(data,IPset);

//    for(int i=0;i<60;i++){
//        printf("data[%d]=%.4f\n",i,data[i]);
//    }
//    printf("\n\n");
    memcpy((float *)precord->vala,data,60*sizeof(*data));

    *(int *)precord->valb = (int)data[48];
    *(int *)precord->valc = (int)data[49];
    *(int *)precord->vald = (int)data[50];
    *(int *)precord->vale = (int)data[52];
    *(int *)precord->valf = (int)data[53];
    *(int *)precord->valg = (int)data[54];
    *(float *)precord->valh = data[55];
    *(float *)precord->vali = data[56];
    *(int *)precord->valj = (int)data[57];
    *(int *)precord->valk = (int)data[58];
    *(int *)precord->vall = (int)data[59];
    *(int *)precord->valm = status;
    return(0);
}
// Note the function must be registered at the end!
epicsRegisterFunction(StatSub);
