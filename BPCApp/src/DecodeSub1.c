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

static int DecodeSub1(aSubRecord *precord) {
    float *status;

    status = (float *)precord->a;
    *(int *)precord->vala = (int)(status[0]);
    *(float *)precord->valb = status[1];
    *(float *)precord->valc = status[2];
    *(float *)precord->vald = status[3];
    *(float *)precord->vale = status[4];
    *(float *)precord->valf = status[5];
    *(float *)precord->valg = status[6];
    *(float *)precord->valh = status[7];
    *(float *)precord->vali = status[8];
    *(float *)precord->valj = status[9];
    *(float *)precord->valk = status[10];
    *(float *)precord->vall = status[11];
    *(float *)precord->valm = status[12];
    *(float *)precord->valn = status[18]; //Check this index
    *(float *)precord->valo = status[19];
    *(float *)precord->valp = status[20];
    *(float *)precord->valq = status[21];
    *(float *)precord->valr = status[22];
    *(float *)precord->vals = status[23];
    *(float *)precord->valt = status[24];
    *(float *)precord->valu = status[25];
    return(0);
}
// Note the function must be registered at the end!
epicsRegisterFunction(DecodeSub1);
