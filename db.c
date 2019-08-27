typedef struct yymmddhhmmss
{
    int year;
    int mon;
    int day;
    int h;
    int min;
    int sec;
} time;

typedef struct tablerow
{
    int *pint;
    char **pstr;
    time *ptime;
    float *pflo;
    tbl *ptbl;
    int *tblcolumn; //int this programe, key must be a number.
} tblrow;

typedef struct table
{
    char *name;
    int keyIDColumn;
    int intNum;
    int strNum;
    int timeNum;
    int floatNum;
    int tblNum;
    int rowNum;
    tblrow *prow;
} tbl;

tbl* creat_table(void);
void init_table(tbl *dirty_table);
void set_table(tbl *clean_table, char *name, int keyIDColumn, int intNum, int strNum, int tblNum, int rowNum);
int* calc_size(tbl tblInfo);
void pack_row(int *size, int *pint, char **pstr, time *ptime, float *pflo, tbl *ptbl, int *tblcolumn);
