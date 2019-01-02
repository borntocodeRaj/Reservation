using namespace std;

#include <YmRevGlobal.h>
#include <YmRevAnnulation.h>

YmRevAnnulation::YmRevAnnulation()
{
_tcnAnnule=0;
_dateTcn.clear();
_dateOperation.clear();
_heureOperation.clear();
_montantTcn=0;
_montantRembourse=0;
_montantRetenues=0;
_stationOrigine.clear();
_stationDestination.clear();
}

YmRevAnnulation::~YmRevAnnulation()
{;
}

void YmRevAnnulation::initAnnulation07(char *buff)
{
 string lsbuff (buff);
 string lsnumber;

 // _tcnAnnule
 lsnumber.assign (lsbuff,90,9);
 _tcnAnnule=atol(lsnumber.data());

 // _dateTcn
 lsnumber.assign(lsbuff,82,8);
 if (atol(lsnumber.data()) !=0)
    _dateTcn=lsbuff.substr(86,4)+lsbuff.substr(84,2)+lsbuff.substr(82,2);

 // _dateOperation
 lsnumber.assign(lsbuff,20,8);
 if (atol(lsnumber.data()) !=0)
    _dateOperation=lsbuff.substr(24,4)+lsbuff.substr(22,2)+lsbuff.substr(20,2);

 // _heureOperation
 lsnumber.assign(lsbuff,28,4);
 if ((atoi(lsnumber.data()) !=0) || (lsnumber.data() == "0000"))
    _heureOperation.assign(lsbuff,28,4);

 // _montantTcn
 lsnumber.assign (lsbuff,99,10);
 _montantTcn = atol (lsnumber.data());

 // _montantRembourse
 lsnumber.assign (lsbuff,109,10);
 _montantRembourse = atol (lsnumber.data());

 // _montantRetenues
 lsnumber.assign (lsbuff,121,10);
 _montantRetenues = atol (lsnumber.data());

 // _stationOrigine
 _stationOrigine.assign(lsbuff,137,5);

 // _stationDestination
 _stationDestination.assign(lsbuff,142,5);

};

void YmRevAnnulation::initAnnulation0700(char *buff)
{
 string lsbuff (buff);
 string lsnumber;

 // _tcnAnnule
 lsnumber.assign (lsbuff,90,9);
 _tcnAnnule=atol(lsnumber.data());

 // _dateTcn
 lsnumber.assign(lsbuff,82,8);
 if (atol(lsnumber.data()) !=0)
    _dateTcn=lsbuff.substr(86,4)+lsbuff.substr(84,2)+lsbuff.substr(82,2);

 // _dateOperation
 lsnumber.assign(lsbuff,20,8);
 if (atol(lsnumber.data()) !=0)
    _dateOperation=lsbuff.substr(24,4)+lsbuff.substr(22,2)+lsbuff.substr(20,2);

 // _heureOperation
 lsnumber.assign(lsbuff,28,4);
 if ((atoi(lsnumber.data()) !=0) || (lsnumber.data() == "0000"))
    _heureOperation.assign(lsbuff,28,4);

 // _montantTcn
 lsnumber.assign (lsbuff,101,10);
 _montantTcn = atol (lsnumber.data());
 
 // _montantRembourse
 lsnumber.assign (lsbuff,111,10);
 _montantRembourse = atol (lsnumber.data());

 // _montantRetenues
 lsnumber.assign (lsbuff,127,10);
 _montantRetenues = atol (lsnumber.data());

};

void YmRevAnnulation::initAnnulation0704(char *buff)
{
 string lsbuff (buff);
 string lsnumber;

 // _tcnAnnule
 lsnumber.assign (lsbuff,90,9);
 unsigned int tcnAnnule=atol(lsnumber.data());
 if (tcnAnnule != getTcnAnnule())
   return; // ce n'est pas le bon

 // _stationOrigine
 _stationOrigine.assign(lsbuff,101,5);

 // _stationDestination
 _stationDestination.assign(lsbuff,106,5);

};

void YmRevAnnulation::initAnnulation09(char *buff)
{
 string lsbuff (buff);
 string lsnumber;

//Date de la transaction 
 lsnumber.assign(lsbuff,15,8);
 if (atol(lsnumber.data()) !=0)
    _dateOperation=lsbuff.substr(19,4)+lsbuff.substr(17,2)+lsbuff.substr(15,2);


 // _tcnAnnule
 lsnumber.assign (lsbuff,40,9);
 _tcnAnnule=atol(lsnumber.data());

 // Autres
 _dateTcn.clear();
 _heureOperation.clear();
 _stationOrigine.clear();
 _stationDestination.clear();
};

void YmRevAnnulation::alimenterVecteurAnnulation()
{
LOCK_MUTEX(&g_MutexVAnnulation);
g_VAnnulation.push_back(this);
UNLOCK_MUTEX(&g_MutexVAnnulation);
}


