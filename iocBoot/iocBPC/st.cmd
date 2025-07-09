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

#dbLoadRecords("../../db/Tester.db","P=BPC{1}:","user=diag")

iocInit()

## Start any sequence programs
#seq sncBPC,"user=diag"

dbpf BPC{1}:IP:Settings-SP "10.0.142.181:5000"
dbpf BPC{2}:IP:Settings-SP "10.0.142.181:5000"
dbpf BPC{3}:IP:Settings-SP "10.0.142.181:5000"
