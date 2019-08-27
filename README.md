# Design of database
data in storage:
user(_IDu_, validu, gender, accType, userName, _userID_, _teleNum_, userPW, userEmail) [4 int, 5 char*]
billInfo(*_user(IDu)_*, validb, borUse, forUse, netUse, borRem, forRem, netRem, sumFee, moneyRem) [10 int]
teleRecord(_IDt_, validt, type, teleFee, *user(teleNum)*, to, startTime, endTime) [4 int, 2 char*, 2 time]
//type : 1, in board; 2, foreign.
netRecord(_IDn_, validn, comAmount, netFee, *user(teleNum)*, time) [4 int, 1 time, 1 char*]
admin(_IDa_, valida, *provider(IDp)*, _adminID_, adminName, adminPW, adminEmail) [3 int, 4 char*]
provider(_IDp_, validp, provName) [2 int, 1 char*]
set(_IDs_, valids, *provider(IDp)*, price, borTime, forTime, setname, description) [6 int, 2 char*]
//set(0, "recharge", NULL, 0, 0, 0, "add money")
moneyrecord(_IDd_, validd, *set(IDs)*, fee, dealTime) [4 int, 1 time]

simulate the following database:
