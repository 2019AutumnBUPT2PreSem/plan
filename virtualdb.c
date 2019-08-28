#ifndef VIRTUALDB_C
#define VIRTUALDB_C

#include "dboperation.c"


tbl* vdb_init_resource(void)
{
    tbl* newtbl;
    newtbl = (tbl*)malloc(sizeof(tbl));
    newtbl->prow = (tblrow*)malloc(ROWLIMIT * sizeof(tblrow));
    init_table()
}
read_resource
write_resource
int vdb_free_resource(tbl* resource)
{

}

tbl* vdb_creat_table(tbl *resource)
{
    if(resource->info.rowNum < resource->locatedRowNum)
    {
        resource->info.rowNum++;
        resource->prow[resource->rowNum] = ()
    }
    else
    {
        printf("Error, not enough space.");
        return NULL;
    }
}

#endif