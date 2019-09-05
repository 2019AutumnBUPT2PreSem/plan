#ifndef DBIO_C
#define DBIO_C

#include <stdio.h>
#include "dbstruct.h"
#include "dboperation.c"

/*
in 1 file ther will be 16 char and 4 int to describe the chart follows.
16 char is for name,
the ints are:
1 intNum
2 namNum
3 timNum
4 rowNum
*/

extern int indent;
extern char diagL[80];

void readHead(FILE *pfile, tblinfo *pinfo);
// read the header from the file
void writeHead(FILE *pfile, tblinfo info);
// write the header into the file
void trscptHead(FILE *pfile, tblinfo *pinfo);
// support the function both apply space and copy content
void revtrsHead(FILE *pfile, tblinfo *pinfo);
// reverse transcription

void readChart(FILE *pfile, tblinfo info, tblclmh clm);
// read the chart from the file
void writeChart(FILE *pfile, tblinfo info, tblclmh clm);
// write the chart into the file
void trscptChart(FILE *pfile, tbl *ptable);
// support the function both apply space and copy chart
void revtrsChart(FILE *pfile, tbl *ptable);
// reverse transcription

void readTable(FILE *pfile, tbl *ptable);
// read the structure from the file
void writeTable(FILE *pfile, tbl *ptable);
// write the structure into the file

void initTable(tbl *ptable);
// need "wb"
void exposeTable(tbl *ptable);
void encloseTable(tbl *ptable);
int isFirstTime(tbl table);

void readHead(FILE *pfile, tblinfo *pinfo) // read the header from the file
{
    fscanf(pfile,"%s%d%d%d%d", pinfo->name, &pinfo->intNum, &pinfo->namNum, &pinfo->timNum, &pinfo->rowNum);
    fgetc(pfile);
}
void writeHead(FILE *pfile, tblinfo info) // write the header into the file
{
    fprintf(pfile, "%s %d %d %d %d\n", info.name, info.intNum, info.namNum, info.timNum, info.rowNum);
}

void trscptHead(FILE *pfile, tblinfo *pinfo) // support the function both apply space and copy content
{
    sprintf(diagL, "[trying to transcript info of table %s]\n", pinfo->name);
    displayDiagnos();

    indent++;
    pinfo->name = (char *)malloc(sizeof(char) * STRLENLIMIT);
    if (pinfo->name != NULL)
    {
        sprintf(diagL, "[memory checked, trying to read head]\n", pinfo->name);
        displayDiagnos();

        indent++;
        readHead(pfile, pinfo); // read the chart head
        indent--;

        sprintf(diagL, "[read done, show info]\n");
        displayDiagnos();
        displayInfo(*pinfo);
    }
    else
    {
        sprintf(diagL, "[there is not enough memory for table name]\n");
        displayDiagnos();
        *pinfo = giveBlankInfo(); // give a blank info
    }
    indent--;
}

void revtrsHead(FILE *pfile, tblinfo *pinfo) // reverse transcription
{
    sprintf(diagL, "[trying to revert transcript info of table %s]\n", pinfo->name);
    displayDiagnos();

    indent++;
    if (pinfo->name != NULL)
    {
        writeHead(pfile, *pinfo); // write the header into the file

        sprintf(diagL, "[the following info will be erased]\n");
        displayDiagnos();
        displayInfo(*pinfo);

        indent++;
        destroyD1_char(pinfo->name);
        *pinfo = giveBlankInfo();
        indent--;

        sprintf(diagL, "[erase done.]\n");
        displayDiagnos();
    }
    else
    {
        sprintf(diagL, "[the head is already empty.]\n");
        displayDiagnos();
    }
    indent--;
}

void readChart(FILE *pfile, tblinfo info, tblclmh clm) // read the chart from the file
{
    sprintf(diagL, "[try to assign and copy row pointer]\n");
    displayDiagnos();

    indent++;
    tim *ptime;
    tblclmh temp = assignTblclmh(info);
    cpyTblclmh(info, clm, temp);
    indent--;

    sprintf(diagL, "[assign and copy row pointer done]\n");
    displayDiagnos();

    for (int i = 0; i < info.rowNum; i++)
    {
        for (int j = 0; j < info.intNum; j++)
        {
            fscanf(pfile, "%d", temp.phint[j]);
            temp.phint[j]++;
        }
        fgetc(pfile);
        for (int j = 0; j < info.namNum; j++)
        {
            fscanf(pfile, "%s", temp.phnam[j]);
            temp.phnam[j]++;
        }
        fgetc(pfile);
        for (int j = 0; j < info.timNum; j++)
        {
            ptime = temp.phtim[j];
            scanf(pfile, "%d%d%d%d%d%d", &ptime->yea, &ptime->mon, &ptime->day, &ptime->hou, &ptime->min, &ptime->sec);
            temp.phtim[j]++;
        }
        fgetc(pfile);
        fgetc(pfile);
    }

    sprintf(diagL, "[try to resign temp row pointer]\n");
    displayDiagnos();

    resignTblclmh(temp);

    sprintf(diagL, "[resign temp row pointer done]\n");
    displayDiagnos();
}
void writeChart(FILE *pfile, tblinfo info, tblclmh clm) // write the chart into the file
{
    sprintf(diagL, "[writting chart, assigning and copying row pointer]\n");
    displayDiagnos();

    indent++;
    tim *ptime;
    tblclmh temp = assignTblclmh(info);
    cpyTblclmh(info, clm, temp);
    indent--;

    sprintf(diagL, "[assign and copy row pointer done, will write %d row]\n", info.rowNum);
    displayDiagnos();

    indent++;
    for (int i = 0; i < info.rowNum; i++)
    {
        for (int j = 0; j < info.intNum; j++)
        {
            fprintf(pfile, "%d ", *temp.phint[j]);
            temp.phint[j]++;
        }
        for (int j = 0; j < info.namNum; j++)
        {
            fprintf(pfile, "%s ", *temp.phnam[j]);
            temp.phnam[j]++;
        }
        for (int j = 0; j < info.timNum; j++)
        {
            ptime = temp.phtim[j];
            fprintf(pfile,"%d/%d/%d %d:%d:%d", ptime->yea, ptime->mon, ptime->day, ptime->hou, ptime->min, ptime->sec);
            temp.phtim[j]++;
        }
        fprintf(pfile, "\n");
    }
    indent--;

    resignTblclmh(temp); //need to be done
}

void trscptChart(FILE *pfile, tbl *ptable) // support the function both apply space and copy chart
{
    sprintf(diagL, "[trying to transcript chart of table %s]\n", ptable->info.name);
    displayDiagnos();

    ptable->clm = assignTblChart(ptable->info);

    indent++;
    if (myxor(ptable->clm.phint == NULL, ptable->info.intNum == 0) ||
        myxor(ptable->clm.phnam == NULL, ptable->info.namNum == 0) ||
        myxor(ptable->clm.phtim == NULL, ptable->info.timNum == 0))
    {
        sprintf(diagL, "[memory not enough, fail, stire all]\n");
        displayDiagnos();

        indent++;
        resignTblChart(ptable->clm, ptable->info);
        ptable->clm = giveBlankClmh();
        ptable->lrn = 0;
        indent--;
    }
    else
    {
        sprintf(diagL, "[memory checked, start to read]\n");
        displayDiagnos();

        indent++;
        ptable->lrn = ptable->info.rowNum;
        readChart(pfile, ptable->info, ptable->clm);
        indent--;

        sprintf(diagL, "[read done]\n");
        displayDiagnos();
    }
    indent--;
}
void revtrsChart(FILE *pfile, tbl *ptable) // reverse transcription
{
    sprintf(diagL, "[trying to revert transcript chart of table %s]\n", ptable->info.name);
    displayDiagnos();

    indent++;
    if ((myxor(ptable->clm.phint == NULL, ptable->info.intNum <= 0) ||
         myxor(ptable->clm.phnam == NULL, ptable->info.namNum <= 0) ||
         myxor(ptable->clm.phtim == NULL, ptable->info.timNum <= 0)) &&
        ptable->info.rowNum != 0)
    {
        sprintf(diagL, "[the chart has lost blocks, write denied, stire all]\n");
        displayDiagnos();
    }
    else
    {
        sprintf(diagL, "[memory checked, start write]\n");
        displayDiagnos();

        indent++;
        writeChart(pfile, ptable->info, ptable->clm);
        indent--;

        sprintf(diagL, "[write done]\n");
        displayDiagnos();
    }
    indent++;
    resignTblChart(ptable->clm, ptable->info);
    ptable->clm = giveBlankClmh();
    indent--;

    indent--;
}

void readTable(FILE *pfile, tbl *ptable) //read the structure from the file
{
    sprintf(diagL, "[trying to read table %s]\n", ptable->info.name);
    displayDiagnos();

    indent++;
    trscptHead(pfile, &ptable->info);
    if (ptable->info.name == NULL)
    {
        sprintf(diagL, "[read table abort since read head failed]\n");
        displayDiagnos();
    }
    else
    {
        trscptChart(pfile, ptable);
        if (myxor(ptable->clm.phint == NULL, ptable->info.intNum == 0) ||
            myxor(ptable->clm.phnam == NULL, ptable->info.namNum == 0) ||
            myxor(ptable->clm.phtim == NULL, ptable->info.timNum == 0))
        {
            sprintf(diagL, "[read table abort since read chart failed]\n");
            displayDiagnos();
        }
        else
        {
            sprintf(diagL, "[read table done]\n");
            displayDiagnos();
        }
    }
    indent--;

    sprintf(diagL, "[read table %s procedure done]\n", ptable->info.name);
    displayDiagnos();
}
void writeTable(FILE *pfile, tbl *ptable) // write the structure into the file
{
    sprintf(diagL, "[trying to write table %s]\n", ptable->info.name);
    displayDiagnos();

    indent++;
    if (ptable->info.name != NULL &&
        ((!myxor(ptable->clm.phint == NULL, ptable->info.intNum == 0) &&
          !myxor(ptable->clm.phnam == NULL, ptable->info.namNum == 0) &&
          !myxor(ptable->clm.phtim == NULL, ptable->info.timNum == 0)) ||
         ptable->info.rowNum == 0) &&
        ptable->lrn >= ptable->info.rowNum)
    {
        sprintf(diagL, "[all checked, start to write info]\n");
        displayDiagnos();
        displayInfo(ptable->info);

        indent++;
        writeHead(pfile, ptable->info);
        indent--;

        sprintf(diagL, "[write info done]\n");
        displayDiagnos();

        revtrsChart(pfile, ptable);

        sprintf(diagL, "[erase info]\n");
        displayDiagnos();

        indent++;
        destroyD1_char(ptable->info.name);
        ptable->info = giveBlankInfo();
        indent--;

        sprintf(diagL, "[info erased]\n");
        displayDiagnos();
    }
    else
    {
        sprintf(diagL, "[table wrong, write denied, stire all]\n");
        displayDiagnos();

        indent++;
        resignTblChart(ptable->clm, ptable->info);
        destroyD1_char(ptable->info.name);
        indent--;

        sprintf(diagL, "[table stired]\n");
        displayDiagnos();
    }
    *ptable = giveBlankTbl();
    indent--;
}

void initTable(tbl *ptable)
{
    sprintf(diagL, "[tring to init table %s]\n", ptable->info.name);
    displayDiagnos();

    ptable->info.rowNum = 0;
    ptable->lrn = 0;
    if (ptable->info.name != NULL)
    {
        char *filename = fillfilenam(ptable->info.name);
        if (filename != NULL)
        {
            FILE *pfile = fopen(filename, "wb");

            indent++;
            ptable->clm = assignTblChart(ptable->info);
            writeTable(pfile, ptable);
            indent--;

            fclose(pfile);
            destroyD1_char(filename);
        }
        else
        {
            sprintf(diagL, "[file name not yet assigned]\n");
            displayDiagnos();
        }
    }
    else
    {
        sprintf(diagL, "[idiot, you've written wrong info]\n");
        displayDiagnos();
    }
}

void exposeTable(tbl *ptable)
{
    sprintf(diagL, "[tring to open file and read table %s]\n", ptable->info.name);
    displayDiagnos();

    if (ptable->info.name != NULL)
    {
        char *filename = fillfilenam(ptable->info.name);
        if (filename != NULL)
        {
            FILE *pfile = fopen(filename, "r");

            indent++;
            readTable(pfile, ptable);
            indent--;

            fclose(pfile);
            destroyD1_char(filename);

            sprintf(diagL, "[open file and read table done]\n");
            displayDiagnos();
        }
        else
        {
            sprintf(diagL, "[file name not yet assigned]\n");
            displayDiagnos();
        }
    }
    else
    {
        sprintf(diagL, "[idiot, you've written wrong info]\n");
        displayDiagnos();
    }
}

void encloseTable(tbl *ptable)
{
    sprintf(diagL, "[tring to write table %s and close file]\n", ptable->info.name);
    displayDiagnos();

    if (ptable->info.name != NULL)
    {
        char *filename = fillfilenam(ptable->info.name);
        if (filename != NULL)
        {
            FILE *pfile = fopen(filename, "w");

            indent++;
            writeTable(pfile, ptable);
            indent--;

            fclose(pfile);
            destroyD1_char(filename);

            sprintf(diagL, "[write table and close file done]\n");
            displayDiagnos();
        }
        else
        {
            sprintf(diagL, "[file name not yet assigned]\n");
            displayDiagnos();
        }
    }
    else
    {
        sprintf(diagL, "[idiot, you've written wrong info]\n");
        displayDiagnos();
    }
}

int isFirstTime(tbl table)
{
    char c;
    char *filename = fillfilenam(table.info.name);
    FILE *pfile = fopen(filename, "rb");
    free(filename);
    fread(&c, sizeof(char), 1, pfile);
    if (feof(pfile))
    {
        fclose(pfile);
        sprintf(diagL, "[The programme is running for the first time.]\n");
        displayDiagnos();
        return 1;
    }
    else
    {
        fclose(pfile);
        return 0;
    }
}
#endif
