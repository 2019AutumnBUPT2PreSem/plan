#include"dbstruct.h"
#include"arraysupport.c"
#include"dboperation.c"
#include"dbio.c"


int main()
{
    char *name, **iteml;
    
    tbl provider;
    name = fillnam("provider");
    setInfo(&provider, name, 2, 1, 0, 0);
    iteml = constructD1_charp(getClmNum(provider.info), NULL);
    iteml[0] = fillnam("IDp");
    iteml[1] = fillnam("validp");
    iteml[2] = fillnam("provName");
    provider.pitem = iteml;
    if(isFirstTime(provider))
    {
        initTable(provider.info, &provider);
    }

    tbl user;
    tbl billinfo;
    tbl telerecord;



}