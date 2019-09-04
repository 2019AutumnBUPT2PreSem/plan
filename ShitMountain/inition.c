#include "dbstruct.h"
#include "arraysupport.c"
#include "dboperation.c"
#include "dbio.c"
#include "displaysupport.c"

int main()
{
	char *name,**iteml;

	tbl provider = giveBlankTbl();
	name=fillnam("provider");
	setInfo(&provider.info,name,2,1,0,0);
	iteml=constructD1_charp(getClmNum(provider.info),NULL);
	iteml[0]=fillnam("IDp");
	iteml[1]=fillnam("validp");
	iteml[2]=fillnam("provName");
	provider.pitem=iteml;

	tbl user = giveBlankTbl();
	name=fillnam("user");
	setInfo(&user.info,name,5,5,0,0);
	iteml=constructD1_charp(getClmNum(user.info),NULL);
	iteml[0]=fillnam("IDu");
	iteml[1]=fillnam("validu");
	iteml[2]=fillnam("gender");
	iteml[3]=fillnam("accType");
	iteml[4]=fillnam("IDp");
	iteml[5]=fillnam("userName");
	iteml[6]=fillnam("userID");
	iteml[7]=fillnam("teleNum");
	iteml[8]=fillnam("userPWphnam");
	iteml[9]=fillnam("userEmailphnam");
	user.pitem=iteml;
	
	tbl billinfo = giveBlankTbl();
	name=fillnam("billinfo");
	setInfo(&billinfo.info,name,11,0,0,0);
	iteml=constructD1_charp(getClmNum(billinfo.info),NULL);
	iteml[0]=fillnam("IDu");
	iteml[1]=fillnam("IDs");
	iteml[2]=fillnam("validb");
	iteml[3]=fillnam("borUse");
	iteml[4]=fillnam("forUse");
	iteml[5]=fillnam("netUse");
	iteml[6]=fillnam("borRem");
	iteml[7]=fillnam("forRem");
	iteml[8]=fillnam("netRem");
	iteml[9]=fillnam("sumFee");
	iteml[10]=fillnam("moneyRem");
	billinfo.pitem = iteml;
	
	tbl telerecord = giveBlankTbl();
	name=fillnam("telerecord");
	setInfo(&telerecord.info,name,5,1,2,0);
	iteml=constructD1_charp(getClmNum(telerecord.info),NULL);
    iteml[0]=fillnam("IDt");
	iteml[1]=fillnam("validt");
	iteml[2]=fillnam("type");
	iteml[3]=fillnam("teleFee");
	iteml[4]=fillnam("IDu");
	iteml[5]=fillnam("to");
	iteml[6]=fillnam("startTime");
	iteml[7]=fillnam("endTime");
	telerecord.pitem = iteml;
	
	tbl netrecord = giveBlankTbl();
	name=fillnam("netrecord");
	setInfo(&netrecord.info,name,5,0,1,0);
    iteml=constructD1_charp(getClmNum(netrecord.info),NULL);
    iteml[0]=fillnam("IDn");
    iteml[1]=fillnam("validn");
	iteml[2]=fillnam("comAmout");
	iteml[3]=fillnam("netFee");
	iteml[4]=fillnam("IDU");
	iteml[5]=fillnam("time");
	netrecord.pitem = iteml;
	
	tbl admin = giveBlankTbl();
	name=fillnam("admin");
	setInfo(&admin.info,name,3,4,0,0);
	iteml=constructD1_charp(getClmNum(admin.info),NULL);
	iteml[0]=fillnam("IDa");
	iteml[1]=fillnam("valida");
	iteml[2]=fillnam("IDp");
	iteml[3]=fillnam("adminID");
	iteml[4]=fillnam("adminName");
	iteml[5]=fillnam("adminPW");
	iteml[6]=fillnam("adminEmail");
	admin.pitem = iteml;

    tbl set = giveBlankTbl();
	name=fillnam("set");
	setInfo(&set.info,name,6,2,0,0);
	iteml=constructD1_charp(getClmNum(set.info),NULL);
	iteml[0]=fillnam("IDs");
	iteml[1]=fillnam("valids");
	iteml[2]=fillnam("IDp");
	iteml[3]=fillnam("price");
	iteml[4]=fillnam("borTime");
	iteml[5]=fillnam("forTime");
	iteml[6]=fillnam("setname");
    iteml[7]=fillnam("description");
	set.pitem = iteml;
	
    tbl moneyrecord = giveBlankTbl();
    name=fillnam("moneyrecord");
	setInfo(&moneyrecord.info,name,5,0,1,0);
	iteml=constructD1_charp(getClmNum(moneyrecord.info),NULL);
	iteml[0]=fillnam("IDd");
	iteml[1]=fillnam("validd");
	iteml[2]=fillnam("IDu");
	iteml[3]=fillnam("IDs");
	iteml[4]=fillnam("fee");
	iteml[5]=fillnam("dealTime");
	moneyrecord.pitem = iteml;
	
	if(isFirstTime(provider) || isFirstTime(set) || isFirstTime(user) || isFirstTime(billinfo) || 
	   isFirstTime(telerecord) || isFirstTime(netrecord) || isFirstTime(moneyrecord) || isFirstTime(admin))
	{
		initTable(&provider);
		initTable(&set);
		initTable(&user);
		initTable(&billinfo);
		initTable(&telerecord);
		initTable(&netrecord);
		initTable(&moneyrecord);
		initTable(&admin);
	}
	
	return 0;
}   
