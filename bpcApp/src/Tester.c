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
#include <math.h>
#include <time.h>
#include "cadef.h"
#include <aSubRecord.h>
#include <registryFunction.h>
#include <epicsExport.h>

#define IPADDR "10.0.142.XXX"
#define PORT 5555
#define BUFFER_SIZE 1024

void UDPcommand(char* command){

    printf("%s",command);
/*    int sockfd;
    unsigned char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    socklen_t len = sizeof(server_addr);

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, IPADDR, &server_addr.sin_addr) <= 0) {
        perror("invalid address/ address not supported");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    ssize_t bytes_sent = sendto(sockfd, command, 4, 0, (const struct sockaddr *) &server_addr, sizeof(server_addr));
    if(bytes_sent < 0) {
        perror("sendto failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    close(sockfd);*/

}

static int Tester(aSubRecord *precord) {

    static int oldCH1=0,oldCH2=0,oldCH3=0,oldCH4=0,oldCAL=0;
    static int oldMode1=0,oldMode2=0,oldMode3=0,oldMode4=0;
    static int oldDCCTfault=0,oldIgndChan=0;
    static float oldIgnd=0,oldVgain1=0,oldVgain2=0,oldVgain3=0;
    static float oldVgain4=0,oldCALdac=0;
    static float oldIgain4=0,oldIgain1=0,oldIgain2=0,oldIgain3=0;
    static char oldTester[30];

    int CH1state = *(int *)precord->a;
    int CH2state = *(int *)precord->b;
    int CH3state = *(int *)precord->c;
    int CH4state = *(int *)precord->d;
    int CALstate = *(int *)precord->e;
    int CH1mode = *(int *)precord->f;
    int CH2mode = *(int *)precord->g;
    int CH3mode = *(int *)precord->h;
    int CH4mode = *(int *)precord->i;
    int DCCTfault = *(int *)precord->j;
    int IgndChan = *(int *)precord->k;
    float Ignd = *(float *)precord->l;
    float Vgain1 = *(float *)precord->m;
    float Vgain2 = *(float *)precord->n;
    float Vgain3 = *(float *)precord->o;
    float Vgain4 = *(float *)precord->p;
    float Igain1 = *(float *)precord->q;
    float Igain2 = *(float *)precord->r;
    float Igain3 = *(float *)precord->s;
    float Igain4 = *(float *)precord->t;
    char *TesterCMD = (char *)precord->u;

//    char *dest = malloc(strlen(TesterCMD)+1);
//    strcpy(dest,TesterCMD);
//    printf("Tester2 CMD: %s   %s\n",TesterCMD,dest);
//    strcpy(TesterCMD,oldTester);
    char cmd[20], val[10];

    if(oldCH1!=CH1state){
        oldCH1 = CH1state;
        strcpy(cmd,"C1");
        sprintf(val,"%d",CH1state);
        strcat(cmd,val);
        strcat(cmd,"\n");
        UDPcommand(cmd);
    }
    if(oldCH2!=CH2state){
        oldCH2 = CH2state;
        strcpy(cmd,"C2");
        sprintf(val,"%d",CH2state);
        strcat(cmd,val);
        strcat(cmd,"\n");
        UDPcommand(cmd);
    }
    if(oldCH3!=CH3state){
        oldCH3 = CH3state;
        strcpy(cmd,"C3");
        sprintf(val,"%d",CH3state);
        strcat(cmd,val);
        strcat(cmd,"\n");
        UDPcommand(cmd);
    }
    if(oldCH4!=CH4state){
        oldCH4 = CH4state;
        strcpy(cmd,"C4");
        sprintf(val,"%d",CH4state);
        strcat(cmd,val);
        strcat(cmd,"\n");
        UDPcommand(cmd);
    }
    if(oldCAL!=CALstate){
        oldCAL = CALstate;
        strcpy(cmd,"CAL");
        sprintf(val,"%d",CALstate);
        strcat(cmd,val);
        strcat(cmd,"\n");
        UDPcommand(cmd);
    }
    if(oldMode1!=CH1mode){
        oldMode1 = CH1mode;
        strcpy(cmd,"T1");
        sprintf(val,"%d",CH1mode);
        strcat(cmd,val);
        strcat(cmd,"\n");
        UDPcommand(cmd);
    }
    if(oldMode2!=CH2mode){
        oldMode2 = CH2mode;
        strcpy(cmd,"T2");
        sprintf(val,"%d",CH2mode);
        strcat(cmd,val);
        strcat(cmd,"\n");
        UDPcommand(cmd);
    }
    if(oldMode3!=CH3mode){
        oldMode3 = CH3mode;
        strcpy(cmd,"T3");
        sprintf(val,"%d",CH3mode);
        strcat(cmd,val);
        strcat(cmd,"\n");
        UDPcommand(cmd);
    }
    if(oldMode4!=CH4mode){
        oldMode4 = CH4mode;
        strcpy(cmd,"T4");
        sprintf(val,"%d",CH4mode);
        strcat(cmd,val);
        strcat(cmd,"\n");
        UDPcommand(cmd);
    }
    if(oldDCCTfault!=DCCTfault){
        oldDCCTfault = DCCTfault;
        strcpy(cmd,"D");
        sprintf(val,"%d",DCCTfault);
        strcat(cmd,val);
        strcat(cmd,"\n");
        UDPcommand(cmd);
    }
    if(oldIgndChan!=IgndChan || oldIgnd!=Ignd){
        oldIgndChan = IgndChan;
        oldIgnd = Ignd;
        strcpy(cmd,"Ignd");
        sprintf(val,"%d",IgndChan);
        strcat(cmd,val);
        sprintf(val,"%4.3f",Ignd);
        strcat(cmd,val);
        strcat(cmd,"\n");
        UDPcommand(cmd);
    }
    if(oldVgain1!=Vgain1){
        oldVgain1 = Vgain1;
        strcpy(cmd,"V1");
        sprintf(val,"%4.3f",Vgain1);
        strcat(cmd,val);
        strcat(cmd,"\n");
        UDPcommand(cmd);
    }
    if(oldVgain2!=Vgain2){
        oldVgain2 = Vgain2;
        strcpy(cmd,"V2");
        sprintf(val,"%4.3f",Vgain2);
        strcat(cmd,val);
        strcat(cmd,"\n");
        UDPcommand(cmd);
    }
    if(oldVgain3!=Vgain3){
        oldVgain3 = Vgain3;
        strcpy(cmd,"V3");
        sprintf(val,"%4.3f",Vgain3);
        strcat(cmd,val);
        strcat(cmd,"\n");
        UDPcommand(cmd);
    }
    if(oldVgain4!=Vgain4){
        oldVgain4 = Vgain4;
        strcpy(cmd,"V4");
        sprintf(val,"%4.3f",Vgain4);
        strcat(cmd,val);
        strcat(cmd,"\n");
        UDPcommand(cmd);
    }
    if(oldIgain1!=Igain1){
        oldIgain1 = Igain1;
        strcpy(cmd,"I1");
        sprintf(val,"%4.3f",Igain1);
        strcat(cmd,val);
        strcat(cmd,"\n");
        UDPcommand(cmd);
    }
    if(oldIgain2!=Igain2){
        oldIgain2 = Igain2;
        strcpy(cmd,"I2");
        sprintf(val,"%4.3f",Igain2);
        strcat(cmd,val);
        strcat(cmd,"\n");
        UDPcommand(cmd);
    }
    if(oldIgain3!=Igain3){
        oldIgain3 = Igain3;
        strcpy(cmd,"I3");
        sprintf(val,"%4.3f",Igain3);
        strcat(cmd,val);
        strcat(cmd,"\n");
        UDPcommand(cmd);
    }
    if(oldIgain4!=Igain4){
        oldIgain4 = Igain4;
        strcpy(cmd,"I4");
        sprintf(val,"%4.3f",Igain4);
        strcat(cmd,val);
        strcat(cmd,"\n");
        UDPcommand(cmd);
    }
    if(strcmp(oldTester,TesterCMD)!=0){
//        printf("New Tester2 CMD: %s   %s\n",TesterCMD,oldTester);
        strcpy(oldTester,TesterCMD);
        UDPcommand(TesterCMD);
    }

    return(0);
}
// Note the function must be registered at the end!
epicsRegisterFunction(Tester);
