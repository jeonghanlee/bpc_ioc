#!../../bin/linux-x86_64/BPC

#- You may have to change BPC to something else
#- everywhere it appears in this file

#< envPaths

epicsEnvSet("SCAN2",".2 second")
epicsEnvSet("SCAN3",".3 second")
## Register all support components
dbLoadDatabase "../../dbd/BPC.dbd"
BPC_registerRecordDeviceDriver(pdbbase) 

## Load record instances
#dbLoadRecords("../../db/BPC.db","user=diag")
dbLoadRecords("../../db/System.db","SYS=BPC:","user=diag")
dbLoadRecords("../../db/Status21.db","P=BPC{1}:","user=diag")
dbLoadRecords("../../db/Status22.db","P=BPC{2}:","user=diag")
dbLoadRecords("../../db/Status23.db","P=BPC{3}:","user=diag")
dbLoadRecords("../../db/Status24.db","P=BPC{4}:","user=diag")
dbLoadRecords("../../db/Status25.db","P=BPC{5}:","user=diag")
dbLoadRecords("../../db/Status26.db","P=BPC{6}:","user=diag")
dbLoadRecords("../../db/Status27.db","P=BPC{7}:","user=diag")
dbLoadRecords("../../db/Status20.db","P=BPC{8}:","user=diag")

#dbLoadRecords("../../db/Tester.db","P=BPC{1}:","user=diag")

iocInit()

## Start any sequence programs
#seq sncBPC,"user=diag"

dbpf BPC{1}:IP:Settings-SP "10.68.26.51:5000"
dbpf BPC{2}:IP:Settings-SP "10.68.26.52:5000"
dbpf BPC{3}:IP:Settings-SP "10.68.26.53:5000"
dbpf BPC{4}:IP:Settings-SP "10.68.26.54:5000"
dbpf BPC{5}:IP:Settings-SP "10.68.26.55:5000"
dbpf BPC{6}:IP:Settings-SP "10.68.26.56:5000"
dbpf BPC{7}:IP:Settings-SP "10.68.26.57:5000"
dbpf BPC{8}:IP:Settings-SP "10.68.26.58:5000"

