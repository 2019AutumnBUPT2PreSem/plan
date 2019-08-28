# 题目
## 题目集1
1.1 现有如下结构：
```c
// prepare 16 char for 1 string.
// 以下结构并非本次需处理的结构， 仅仅是其部分
typedef struct tableinfo  
{  
    int intNum;  
    int strNum;  
    int timNum;  
    int floNum;  
    int tblNum;  
    int rowNum;   
} tblinfo;  
```
```c
typedef struct table  
{  
    char *name; // max 16 char
    int recordMode; // -1 : abandon; 0 : empty; 1 : column; 2 : row  
    tblinfo info;  
} tbl;
```
在文件"test.txt"中有如下文字
```
test
2
4,2,2,1,0,20
```
其中第一行为表名(`name`)，第二行为文件存储方式(`recordMode`)，第三行为文件大小信息(`intNum; strNum; timNum; floNum; tblNum; rowNum`)。

请设计以下函数把这些信息写入结构体中。  
`void read_head(FILE *pfile, tbl table)`.
***
1.2 现在你拿到了上面函数产生的结构体，设计上一个函数的反函数，`void write_head(FILE *pfile, tbl inMem)`将内容注入到文件中。
***
1.3 观察该时间表达法`19/08/29 00:14:23`，若有结构体`time`:
```c
typedef struct ymdhms
{
    int yea;
    int mon;
    int day;
    int hou;
    int min;
    int sec;
} time;
```
请写出`time read_time(FILE *pfile)`来读取时间，及其反函数`time write_time(FILE *pfile)`来写入时间。
***
1.4 我们现在考虑更复杂的情况，定义以下结构体`tblclm`并更改`table`。
```c
typedef struct tablecolumn
{
    int **phint; // pointer to the headpointer of a list of int, all the same.
    char ***phstr;
    time **phtim;
    float **phflo;
    tbl **phtbl;
} tblclm;

typedef struct table  
{  
    char *name; // max 16 char
    int recordMode; // -1 : abandon; 0 : empty; 1 : column; 2 : row  
    tblinfo info;
    tblclm clm;
} tbl;
```
现在想办法将含有以下内容的"test.txt"读入新的`table`中。(注意，现在所有用例中tblNum值全部为0，目前不考虑表作为数据库项)
```
test
2
4,2,2,1,0,2
12,878,123,1414,aldsiope        ,yutfdery        ,19/08/29 00:14:23,19/08/29 00:15:18,12.108
2342,432,134,765,aldskfas        ,qewqwenl        ,19/08/29 00:22:54,19/08/29 00:31:08,310.123
```
存储方式为同一列的内容按顺序存在一个一维动态数组中。(提示，建立一个tblclm,存储这样的指针：申请来存储随时变动的内存写入指针的动态指针数组，而我们的指针指向该数组头)

1.4.1 设计纯粹表格读取函数，此函数定义为`void read_chart(FILE *pfile, tblinfo info, tblclm *targetclm)`。  
1.4.2 设计上一个函数的反函数`void write_chart(FILE *pfile, tblinfo info, tblclm sourceclm)`。  
1.4.3 设计文件整体读取并建立`table`的函数`void read_table(FILE *pfile, tbl *targettbl)`。  
1.4.4 设计上一个函数的反函数`void write_table(FILE *pfile, tbl sourcetbl)`。  
***
1.5 解决收尾问题，释放动态数组的内存，在一个table中我们至少有：各类2维数组，



3 void read_row(FILE *pfile, tblinfo info, int rowNum, tblrow *inMem)
4 void write_row(FILE *pfile, tblinfo info, int rowNum, tblrow row)