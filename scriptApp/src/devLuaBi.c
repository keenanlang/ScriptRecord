#include "devUtil.h"

#include <biRecord.h>
#include <epicsExport.h>
#include <dbCommon.h>
#include <devSup.h>

static long readData(struct biRecord* record)
{
	return runScript(record->dpvt);
}


static long initRecord (dbCommon* record)
{
	biRecord* bi = (biRecord*) record;
	
	bi->dpvt = parseINPOUT(&bi->inp);
	
	return 0;
}

struct {
    long number;
    DEVSUPFUN report;
    DEVSUPFUN init;
    DEVSUPFUN init_record;
    DEVSUPFUN get_ioint_info;
    DEVSUPFUN read;
    DEVSUPFUN special_linconv;
} devLuaBi = {
    6,
    NULL,
    NULL,
    initRecord,
    NULL,
    readData,
    NULL
};

epicsExportAddress(dset, devLuaBi);