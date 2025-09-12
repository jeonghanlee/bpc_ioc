#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>
#include <aSubRecord.h>
#include <registryFunction.h>
#include <epicsExport.h>

static int DecodeSub2(aSubRecord *precord) {
    float *status;

    status = (float *)precord->a;
    *(float *)precord->vala = status[26];
    *(float *)precord->vals = status[27];
    *(float *)precord->valc = status[28];
    *(float *)precord->vald = status[29];
    *(float *)precord->vale = status[30];
    *(float *)precord->valf = status[31];
    *(float *)precord->valg = status[32];
    *(float *)precord->valh = status[33];
    *(float *)precord->vali = status[35];
    *(float *)precord->valj = status[36];
    *(float *)precord->valk = status[37];
    *(int *)precord->vall = (int)status[38];
    *(int *)precord->valm = (int)status[39];
    *(int *)precord->valn = (int)status[40];
    *(int *)precord->valo = (int)status[41];
    *(int *)precord->valp = (int)status[42];
    *(int *)precord->valq = (int)status[43];
    *(float *)precord->valr = status[44];
    *(float *)precord->vals = status[45];
    *(float *)precord->valt = status[46];
    return(0);
}
// Note the function must be registered at the end!
epicsRegisterFunction(DecodeSub2);
