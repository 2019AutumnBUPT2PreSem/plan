   # Design of database
data in storage:
(tblList[0])provider(<u>IDp(phint[0])</u>, validp(phint[1]), provName(phnam[0])) [2 int, 1 char*]

(tblList[1])user(<u>IDu(phint[0])</u>, validu(phint[1]), gender(phint[2]), accType(phint[3]), *provider(IDp)*(phint[4]), userName(phnam[0]), userID((phnam[1]), teleNum(phnam[2]), userPWphnam[3]), userEmailphnam[4])) [5 int, 5 char*]

(tblList[2])billInfo(*<u>user(IDu)(phint[0])</u>*, *set(IDs)*(phint[1]), validb(phint[2]), borUse(phint[3])//国内月的时长, forUse(phint[4])//国外月时长, netUse(phint[5])//网费月流量, borRem(phint[6)//国内剩余时长, forRem(phint[7])//国外剩余时长, netRem(phint[8])//网费剩余时长, sumFee(phint[9])//本月全部支出, moneyRem(phint[10])//剩余钱) [11 int]

(tblList[3])teleRecord(<u>IDt(phint[0])</u>, validt(phint[1]), type(phint[2]), teleFee(phint[3]), *user(IDu)*(phint[4]), to(phnam[0]), startTime(phtim[0]), endTime(phtim[1])) [5int, 1char*, 2 time]
//type : 1, in board; 2, foreign.

(tblList[4])netRecord(<u>IDn(phint[0])</u>, validn(phint[1]), comAmount(phint[2]), netFee(phint[3]), *user(IDU)*(phint[4]), time(phtim[0])) [5int, 0char*, 1 time]

(tblList[5])admin(<u>IDa(phint[0])</u>, valida(phint[1]), *provider(IDp)*(phint[2]), adminID(phint[3]), adminName(phnam[0]), adminPW(phnam[1]), adminEmail(phnam[2])) [3 int, 4 char*]

(tblList[6])set(<u>IDs(phint[0])</u>, valids(phint[1]), *provider(IDp)*(phint[2]), price(phint[3]), borTime(phtim[0]), forTime(phtim[1]), setname(phnam[0]), description(phnam[1])) [6 int, 2 char*]

(tblList[7])moneyrecord(<u>IDd(phint[0])</u>, validd(phint[1]), *user(IDu)*(phint[2]), *set(IDs)*(phint[3]), fee(phint[4]), dealTime(phtim[0])) [5 int, 1 time]

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

