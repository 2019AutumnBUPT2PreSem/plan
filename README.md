# Design of database
data in storage:
provider(<u>IDp</u>, validp, provName) [2 int, 1 char*]
user(<u>IDu</u>, validu, gender, accType, *provider(IDp)*, userName, userID, teleNum, userPW, userEmail) [5 int, 5 char*]
billInfo(*<u>user(IDu)</u>*, *set(IDs)*, validb, borUse, forUse, netUse, borRem, forRem, netRem, sumFee, moneyRem) [11 int]

teleRecord(<u>IDt</u>, validt, type, teleFee, *user(IDu)*, to, startTime, endTime) [4 int, 2 char*, 2 time]
//type : 1, in board; 2, foreign.

netRecord(<u>IDn</u>, validn, comAmount, netFee, *user(teleNum)*, time) [4 int, 1 char*, 1 time]

admin(<u>IDa</u>, valida, *provider(IDp)*, adminID, adminName, adminPW, adminEmail) [3 int, 4 char*]

set(<u>IDs</u>, valids, *provider(IDp)*, price, borTime, forTime, setname, description) [6 int, 2 char*]
//set(0, 1, n, 0, 0, 0, "recharge", "add money")

moneyrecord(<u>IDd</u>, validd, *user(IDu)*, *set(IDs)*, fee, dealTime) [4 int, 1 time]

# Or try the structures:
{int a[16]; char *b[5]           } user,billInfo;
{int a[4];  char *b[2]; time c[2]} teleRecord;
{int a[4];  char *b[1]; time c   } netRecord;
{int a[2];  char *b[1]           } provider;
{int a[3];  char *b[4]           } admin;
{int a[6];  char *b[2]           } set;
{int a[4];              time c   } moneyrecord;

# The procedure that links the tables
int *map(int *seq, int *);
this procedure will return a list of number, which is like a virtually new table.
(1,3) (2,4) (3,1) (4,5) (5,2) (34152)-- access(map(1, 3, 4, 2, 5), table) --> (1,3) (3,1) (4,5) (2,4) (5,2) (31542)

int *filter(int rule(tblrow row));
this procedure will return a cut list, as filtered.
(1,3) (2,4) (3,1) (4,5) (5,2) (34125)-- filter( >3?(), tbl a) -->(2,4) (4,5) (45)

user(<u>IDu</u>, validu, gender, accType, *provider(IDp)*, userName, userID, teleNum, userPW, userEmail)

      1            1        -1       -1     -1              -1          a         -1    -1      -1
      2            1                                                    c
      3            1                                                    b

      (IDu, userID)

1 void write_head(FILE *pfile, tbl inMem)
2 void read_head(FILE *pfile, tblinfo info)

3 void read_row(FILE *pfile, tblinfo info, int rowNum, tblrow *inMem)
4 void write_row(FILE *pfile, tblinfo info, int rowNum, tblrow row)