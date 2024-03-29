#ifndef DBOPERATION_C
#define DBOPERATION_C

#include"arraysupport.c"
#include"dbstruct.h"
#include"displaysupport.c"
#include<string.h>

extern int indent;
extern char diagL[80];

tblclmh giveBlankClmh(void);
tblinfo giveBlankInfo(void);
tbl giveBlankTbl(void);
tim giveBlankTim(void);

char* fillnam(const char *p);  // support the function fill name
char* fillfilenam(const char *p); // don'tuse
void setInfo(tblinfo *pinfo, char* name, int intNum, int strNum, int timNum, int rowNum); //set info
int getClmNum(tblinfo info); // get the number of each column
tim setTim(int y, int mo, int d, int h, int mi, int s);

int myxor(int a, int b);

tblclmh assignTblclmh(tblinfo info); // create space for column head
void resignTblclmh(tblclmh tablecolumn); // free space for column head

tblclmh assignTblChart(tblinfo info); //create space for chart
void resignTblChart(tblclmh tablecolumn, tblinfo info); //free space for chart

void cpyTblclmh(tblinfo info, tblclmh clmh1, tblclmh clmh2); //clmh1->clmh2
void extendTblclm(tblinfo info, tblclmh *tablecolumn, int *locRowNum); //this chart will change ptablecolumn to NULL if failed

void addrow(tbl *table, int *introw, char **namrow, tim *timrow); // add a new row to chart
void display_tbl(tbl table);

tblclmh giveBlankClmh(void)
{
    tblclmh newclmh;
    newclmh.phint = NULL;
    newclmh.phnam = NULL;
    newclmh.phtim = NULL;
}
//give the form a new blank column head

tblinfo giveBlankInfo(void)
{
    tblinfo info;
    info.name = NULL;
    info.intNum = 0;
    info.namNum = 0;
    info.timNum = 0;
    info.rowNum = 0;
    return info;
}
//give the form new blank info

tbl giveBlankTbl(void)
{
    tbl table;
    table.info = giveBlankInfo();
    table.lrn = 0;
    table.clm = giveBlankClmh(); 
    return table;
}
//give a new blank form

tim giveBlankTim(void)
{
    tim blankTim;
    blankTim.yea = 0;
    blankTim.mon = 0;
    blankTim.day = 0;
    blankTim.hou = 0;
    blankTim.min = 0;
    blankTim.sec = 0;
    return blankTim;
}
// give a new time to the form

char* fillnam(const char *p) //you need to free the pointer // support the function fill name
{
    char* newnam = (char*)malloc(sizeof(char) * STRLENLIMIT);
    if(newnam != NULL)
    {
        strncpy(newnam, p, STRLENLIMIT);
    }
    return newnam;
}
char* fillfilenam(const char *p) // must char * p = fillnam("dfakwfjdshfalkjdf"); char * q = fillfilenam(p); free(p); ... free(q);
{
    char* newnam = (char*)malloc(sizeof(char) * (STRLENLIMIT + 5));
    strncpy(newnam, p, STRLENLIMIT);
    newnam[STRLENLIMIT] = '\0';
    strcat(newnam, ".tbl");
    return newnam;
}
void setInfo(tblinfo *pinfo, char *name, 
              int intNum, int namNum, int timNum, int rowNum) // set infoo
{
    pinfo->name = name;
    pinfo->intNum = intNum;
    pinfo->namNum = namNum;
    pinfo->timNum = timNum;
    pinfo->rowNum = rowNum;
}

int getClmNum(tblinfo info) // get the number of each column
{
    return info.intNum + info.namNum + info.timNum;
}

tim setTim(int y, int mo, int d, int h, int mi, int s)
{
    tim temp;
    temp.yea = y;
    temp.mon = mo;
    temp.day = d;
    temp.hou = h;
    temp.min = mi;
    temp.sec = s;
    return temp;
}

int myxor(int a, int b)
{
	return (!a && b) || (a && !b);
}

tblclmh assignTblclmh(tblinfo info) // create space for column head
{
    tblclmh newclmh;

    sprintf(diagL, "[trying to assign row pointer]\n");
    displayDiagnos();

    indent++;
    newclmh.phint = constructD1_intp(info.intNum, NULL);
    if(myxor(newclmh.phint == NULL, info.intNum <= 0))
    {
        sprintf(diagL, "[assign block pointer for int failed, row pointer set NULL]\n");
        displayDiagnos();
        newclmh = giveBlankClmh();
    }
    else
    {
        sprintf(diagL, "[assign block pointer for int done, assign that for nam]\n");
        displayDiagnos();

        newclmh.phnam = constructD1_charpp(info.namNum, NULL);
        if(myxor(newclmh.phnam == NULL, info.namNum <= 0))
        {
            sprintf(diagL, "[assign block pointer for nam failed, row pointer set NULL]\n");
            displayDiagnos();

            destroyD1_intp(newclmh.phint);
            newclmh = giveBlankClmh();
        }
        else
        {
            sprintf(diagL, "[assign block pointer for nam done, set that for tim]\n");
            displayDiagnos();

            newclmh.phtim = constructD1_timp(info.timNum, NULL);
            if(myxor(newclmh.phtim == NULL, info.timNum <= 0))
            {
                sprintf(diagL, "[assign block pointer for tim failed, row pointer set NULL]\n");
                displayDiagnos();

                destroyD1_intp(newclmh.phint);
                destroyD1_charpp(newclmh.phnam);
                newclmh = giveBlankClmh();
            }
            else
            {
                sprintf(diagL, "[assign block pointer for tim done]\n");
                displayDiagnos();
            }
        }
    }
    indent--;

    sprintf(diagL, "[assign row pointer procedure done]\n");
    displayDiagnos();

    return newclmh;
}
void resignTblclmh(tblclmh tablecolumn) // free space for column head
{
    sprintf(diagL, "[resigning row pointer]\n");
    displayDiagnos();

	destroyD1_intp(tablecolumn.phint);
    destroyD1_charpp(tablecolumn.phnam);
    destroyD1_timp(tablecolumn.phtim);

    sprintf(diagL, "[resign row pointer done]\n");
    displayDiagnos();
}

void cpyTblclmh(tblinfo info, tblclmh clmh1, tblclmh clmh2) // clmh1 -> clmh2
{
    sprintf(diagL, "[copying row pointer  of %s to new row pointer]\n", info.name);
    displayDiagnos();

    for(int i = 0; i < info.intNum; i++)
    {
        clmh2.phint[i] = clmh1.phint[i];
    }
    for(int i = 0; i < info.namNum; i++)
    {
        clmh2.phnam[i] = clmh1.phnam[i];
    }
    for(int i = 0; i < info.timNum; i++)
    {
        clmh2.phtim[i] = clmh1.phtim[i];
    }

    sprintf(diagL, "[copy row pointer done]\n");
    displayDiagnos();
}

tblclmh assignTblChart(tblinfo info) //create space for chart
{
    sprintf(diagL, "[assigning space for chart]\n");
    displayDiagnos();

    tblclmh newclmh = giveBlankClmh();

    indent++;
    if(info.rowNum <= 0)
    {
        newclmh = assignTblclmh(info);
    }
    else
    {
        sprintf(diagL, "[assigning 2D int chart %dc, %dr]\n", info.intNum, info.rowNum);
        displayDiagnos();

        newclmh.phint = constructD2_int(info.intNum, info.rowNum, 0);//
        if(myxor(newclmh.phint == NULL, info.intNum <= 0))
        {
            sprintf(diagL, "[fail to assign 2D int chart, stire all]\n");
            displayDiagnos();

            newclmh = giveBlankClmh();
        }
        else
        {
            sprintf(diagL, "[assign 2D int chart done, assigning 2D nam chart %dc, %dr]\n", info.namNum, info.rowNum);
            displayDiagnos();

            newclmh.phnam = constructD3_char(info.namNum, info.rowNum, STRLENLIMIT, '\0');
            if(myxor(newclmh.phnam == NULL, info.namNum <= 0))
            {
                sprintf(diagL, "[fail to assign 2D nam chart, stire all]\n");
                displayDiagnos();

                destroyD2_int(newclmh.phint, info.intNum);
                newclmh = giveBlankClmh();
            }
            else
            {
                sprintf(diagL, "[assign 2D nam chart done, assigning 2D tim chart %dc, %dr]\n", info.timNum, info.rowNum);
                displayDiagnos();

                newclmh.phtim = constructD2_tim(info.timNum, info.rowNum, giveBlankTim());
                if(myxor(newclmh.phtim == NULL, info.timNum <= 0))
                {
                    sprintf(diagL, "[fail to assign 2D tim chart, stire all]\n");
                    displayDiagnos();

                    destroyD2_int(newclmh.phint, info.intNum);
                    destroyD3_char(newclmh.phnam, info.namNum, info.rowNum);
                    newclmh = giveBlankClmh();
                }
                else
                {
                    sprintf(diagL, "[assign 2D nam chart done]\n");
                    displayDiagnos();
                }
            }
        }
    }
    indent--;

    sprintf(diagL, "[assign space for chart done]\n");
    displayDiagnos();

    return newclmh;
}

void resignTblChart(tblclmh tablecolumn, tblinfo info) //free space for chart
{
	destroyD2_int(tablecolumn.phint, info.intNum);
    destroyD3_char(tablecolumn.phnam, info.namNum, info.rowNum);
    destroyD2_tim(tablecolumn.phtim, info.timNum);
}

void extendTblclm(tblinfo info, tblclmh *ptablecolumn, int *plocRowNum) // this chart will change ptablecolumn to NULL if failed
{
    ptablecolumn->phint = extendD2N_int(ptablecolumn->phint, info.intNum, *plocRowNum, EXPPT, 0);
    ptablecolumn->phnam = extendD3M_char(ptablecolumn->phnam, info.namNum, *plocRowNum, STRLENLIMIT, EXPPT, '\0');
    ptablecolumn->phtim = extendD2N_tim(ptablecolumn->phtim, info.timNum, *plocRowNum, EXPPT, giveBlankTim());
    
    sprintf(diagL, "[done extend D2M, int %d, nam %d, tim %d]\n", ptablecolumn->phint != NULL, ptablecolumn->phnam != NULL, ptablecolumn->phtim != NULL);
    displayDiagnos();

    if((myxor(ptablecolumn->phint == NULL, info.intNum <= 0) ||
        myxor(ptablecolumn->phnam == NULL, info.namNum <= 0) ||
        myxor(ptablecolumn->phtim == NULL, info.timNum <= 0)))
    {
        destroyD2_int(ptablecolumn->phint, info.intNum);
        destroyD3_char(ptablecolumn->phnam, info.namNum, info.rowNum);
        destroyD2_tim(ptablecolumn->phtim, info.timNum);
        *ptablecolumn = giveBlankClmh();
        *plocRowNum = 0;

        sprintf(diagL, "[fail to extendTblclm ]\n");
        displayDiagnos();
    }
    else
	{
		*plocRowNum += EXPPT;
        sprintf(diagL, "[extendTblclm is done]\n");
        displayDiagnos();
	}
}

void addrow(tbl *ptable, int *introw, char **namrow, tim *timrow) // add a new blank row to chart
{
    sprintf(diagL, "[trying to add row to table %s]\n", ptable->info.name);
    displayDiagnos();

    indent++;
    if(ptable->lrn <= (ptable->info.rowNum + 1))
    {
        sprintf(diagL, "[located row not enough, extend]\n");
        displayDiagnos();

        indent++;
        extendTblclm(ptable->info, &ptable->clm, &ptable->lrn);
        indent--;

        if(ptable->lrn <= 0)
        {
            sprintf(diagL, "[add row failed, stire all]\n");
            displayDiagnos();
        }
        else
        {
            addrow(ptable, introw, namrow, timrow);
            sprintf(diagL, "[addrow is done]\n");
            displayDiagnos();
            
        }
    }
    else
    {
        displayInfo(ptable->info);
        for(int i = 0; i < ptable->info.intNum; i++)
        {
            ptable->clm.phint[i][ptable->info.rowNum] = introw[i];
        }
           
        sprintf(diagL, "[add intArray is done]\n");
        displayDiagnos();

        for(int i = 0; i < ptable->info.namNum; i++)
        {
            strncpy(ptable->clm.phnam[i][ptable->info.rowNum], namrow[i], STRLENLIMIT);
        }

        sprintf(diagL, "[add nameArray is done]\n");
        displayDiagnos();

        for(int i = 0; i < ptable->info.timNum; i++)
        {
            ptable->clm.phtim[i][ptable->info.rowNum] = timrow[i];
        }

        sprintf(diagL, "[add timArray is done]\n");
        displayDiagnos();

        ptable->info.rowNum = ptable->info.rowNum + 1;
    }
    indent--;
}

void display_tbl(tbl table)
{
    displayInfo(table.info);
    tblclmh temp = assignTblclmh(table.info);
    cpyTblclmh(table.info, table.clm, temp);

    for(int i = 0; i < table.info.rowNum; i++)
    {
        for (int j = 0; j < table.info.intNum; j++)
        {
            display_int(*temp.phint[j]);
            printf("|");
            temp.phint[j]++;
        }
        for (int j = 0; j < table.info.namNum; j++)
        { 
            display_nam(*temp.phnam[j]);
            printf("|");
            temp.phnam[j]++;
        }
        for (int j = 0; j < table.info.timNum; j++)
        {
            display_tim(*temp.phtim[j]);
            printf("|");
            temp.phtim[j]++;
        }
        printf("\n");    
    }
}
#endif
