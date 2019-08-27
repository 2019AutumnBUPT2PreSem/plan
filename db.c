typedef struct tabletitle
{
    char **intName;
    char **strName;
    char **tblName
} tblttl;

typedef struct tablerow
{
    int *pint;
    char **pstr;
    tbl *ptbl;
    int keyID;
} tblrow;

typedef struct table
{
    char *name;
    int keyIDColumn;
    int intNum;
    int strNum;
    int tblNum;
    int rowNum;
    tblttl title;
    tblrow *prow;
} tbl;

tbl* creat_table(void);
void init_table(tbl *dirty_table);
void set_table(tbl *clean_table, int keyIDColumn, int intNum, int strNum, int tblNum, int rowNum, tblttl title, tblrow *row);
void 