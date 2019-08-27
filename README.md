# Design of database
data in storage:
user(<u>IDu</u>, validu, gender, accType, userName, userID, teleNum, userPW, userEmail) [4 int, 5 char*]
billInfo(*<u>user(IDu)</u>*, validb, borUse, forUse, netUse, borRem, forRem, netRem, sumFee, moneyRem) [10 int]

teleRecord(<u>IDt</u>, validt, type, teleFee, *user(teleNum)*, to, startTime, endTime) [4 int, 2 char*, 2 time]
//type : 1, in board; 2, foreign.

netRecord(<u>IDn</u>, validn, comAmount, netFee, *user(teleNum)*, time) [4 int, 1 char*, 1 time]

provider(<u>IDp</u>, validp, provName) [2 int, 1 char*]
//provider(0, 1, "recharge")

admin(<u>IDa</u>, valida, *provider(IDp)*, <u>adminID</u>, adminName, adminPW, adminEmail) [3 int, 4 char*]

set(<u>IDs</u>, valids, *provider(IDp)*, price, borTime, forTime, setname, description) [6 int, 2 char*]
//set(0, 1, 0, 0, 0, 0, "recharge", "add money")

moneyrecord(<u>IDd</u>, validd, *set(IDs)*, fee, dealTime) [4 int, 1 time]

# The structures:
{int a[14]; char *b[5]           } user,billInfo;
{int a[4];  char *b[2]; time c[2]} teleRecord;
{int a[4];  char *b[1]; time c   } netRecord;
{int a[2];  char *b[1]           } provider;
{int a[3];  char *b[4]           } admin;
{int a[6];  char *b[2]           } set;
{int a[4];              time c   } moneyrecord;

# The procedure that links the tables
int *filter(int filter?(), tbl a);
this procedure will return a cut list, as filtered.
(1,3) (2,4) (3,1) (4,5) (5,2) (34125)-- filter( >3?(), tbl a) -->(2,4) (4,5) (45)

int *map(int *seq);
this procedure will return a list of number, which is like a virtually new table.
(1,3) (2,4) (3,1) (4,5) (5,2) (34152)-- map(1, 3, 4, 2, 5) --> (1,3) (3,1) (4,5) (2,4) (5,2) (31542)