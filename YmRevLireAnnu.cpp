
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[17];
};
static const struct sqlcxp sqlfpn =
{
    16,
    "YmRevLireAnnu.pc"
};


static unsigned int sqlctx = 5462435;


static struct sqlexd {
   unsigned long  sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
   unsigned char  **sqphsv;
   unsigned long  *sqphsl;
            int   *sqphss;
            short **sqpind;
            int   *sqpins;
   unsigned long  *sqparm;
   unsigned long  **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
            int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned char  *sqhstv[9];
   unsigned long  sqhstl[9];
            int   sqhsts[9];
            short *sqindv[9];
            int   sqinds[9];
   unsigned long  sqharm[9];
   unsigned long  *sqharc[9];
   unsigned short  sqadto[9];
   unsigned short  sqtdso[9];
} sqlstm = {12,9};

// Prototypes
extern "C" {
  void sqlcxt (void **, unsigned int *,
               struct sqlexd *, const struct sqlcxp *);
  void sqlcx2t(void **, unsigned int *,
               struct sqlexd *, const struct sqlcxp *);
  void sqlbuft(void **, char *);
  void sqlgs2t(void **, char *);
  void sqlorat(void **, unsigned int *, void *);
}

// Forms Interface
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern "C" { void sqliem(unsigned char *, signed int *); }

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4130,1,0,0,
5,0,0,0,0,0,58,66,0,0,1,1,0,1,0,3,109,0,0,
24,0,0,0,0,0,27,68,0,0,4,4,0,1,0,1,97,0,0,1,10,0,0,1,10,0,0,1,10,0,0,
55,0,0,2,0,0,29,83,0,0,0,0,0,1,0,
70,0,0,3,0,0,30,87,0,0,0,0,0,1,0,
85,0,0,0,0,0,59,88,0,0,1,1,0,1,0,3,109,0,0,
104,0,0,4,246,0,3,190,0,0,9,9,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,
1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
155,0,0,5,129,0,3,194,0,0,4,4,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
186,0,0,6,0,0,29,198,0,0,0,0,0,1,0,
201,0,0,7,0,0,31,207,0,0,0,0,0,1,0,
216,0,0,8,246,0,3,215,0,0,9,9,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,
1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
267,0,0,9,129,0,3,222,0,0,4,4,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
298,0,0,10,0,0,29,227,0,0,0,0,0,1,0,
};


//---------------------------------------------------------------------------------------------------------
// Lecture des donness RESAVEN placee dans le vecteur par EcrireVec
// --------------------------------------------------------------------------------------------------------

using namespace std;

#include <iostream>
#include </usr/lib/oracle/11.2/client64/precomp/public/sqlca.h>
#include <unistd.h>
#include <YmRevGlobal.h>
#include <YmRevLireAnnu.h>

//## Configuration du contexte de base JRO IC SRO DT 23805
extern sql_context ctxRevMain;
/* EXEC SQL CONTEXT USE :ctxRevMain; */ 


/* EXEC SQL BEGIN DECLARE SECTION; */ 


#define MAX_NBANNU_IN_BUF 500

int nbAnnuInBuf;

struct REV_ANNU {
        int tcn_annule;
        char date_tcn[11];
        char date_operation[11];
        int heure_annulation;
        int montant_tcn;
        int montant_rembourse;
        int montant_retenues;
        char station_origine[6];
        char station_destination[6];
      } pRevAnnuTable[MAX_NBANNU_IN_BUF];

struct REV_ANNU pRevAnnuSingle[1];

struct REV_TCN_A_ANNULER {
        int tcn_number;
        char date_paiement[11];
        char date_fichier[11];
        int heure_fichier;
     } pRevAnnuATraiterTable[MAX_NBANNU_IN_BUF];

struct REV_TCN_A_ANNULER pRevAnnuATraiterSingle[1];

char connectstringLireAnnu[55];
sql_context ctxLireAnnu;
/* EXEC SQL END DECLARE SECTION; */ 




YmRevLireAnnu::YmRevLireAnnu()
{

  nbAnnuTotal = 0;
}

YmRevLireAnnu::~YmRevLireAnnu()
{
}

void YmRevLireAnnu::Start()
{
  sprintf (connectstringLireAnnu, "%s/%s", g_UserName, g_Password);
  /* EXEC SQL WHENEVER SQLERROR DO sql_error ((char*)"Pb YmRevLireAnnu", 0); */ 

  /* EXEC SQL CONTEXT ALLOCATE :ctxLireAnnu; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 1;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&ctxLireAnnu;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(void *);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("Pb YmRevLireAnnu",0);
}


  /* EXEC SQL CONTEXT USE :ctxLireAnnu; */ 

  /* EXEC SQL CONNECT :connectstringLireAnnu; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )10;
  sqlstm.offset = (unsigned int  )24;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)connectstringLireAnnu;
  sqlstm.sqhstl[0] = (unsigned long )55;
  sqlstm.sqhsts[0] = (         int  )55;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlstm.sqlcmax = (unsigned int )100;
  sqlstm.sqlcmin = (unsigned int )2;
  sqlstm.sqlcincr = (unsigned int )1;
  sqlstm.sqlctimeout = (unsigned int )0;
  sqlstm.sqlcnowait = (unsigned int )0;
  sqlcxt(&ctxLireAnnu, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("Pb YmRevLireAnnu",0);
}


  while (g_EcrireVecEnCours || g_VAnnulation.size())
  { // On teste a la fois size et Ecriture en cours, au cas ou LireAnnu irai plus vite que EcrireVec
    purgeBufAnnu();
    LOCK_MUTEX (&g_MutexVAnnulation);
    fillBufAnnu();
    nbAnnuInBuf = bufVAnnu.size();
    if (nbAnnuInBuf)
      g_VAnnulation.erase (g_VAnnulation.begin(), g_VAnnulation.begin()+nbAnnuInBuf);
      // rappel erase supprime entre first inclu et last exclu.
    UNLOCK_MUTEX (&g_MutexVAnnulation);
    if (nbAnnuInBuf)
      InsertAnnulation();
    else
      sleep(6);	// On attend un peu qu'il y ai du taf.
    /* EXEC SQL COMMIT WORK; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )55;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt(&ctxLireAnnu, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("Pb YmRevLireAnnu",0);
}


  }
  cout<<endl;
  cout<<DonneHeure()<<" Fin LireAnnu   total="<<nbAnnuTotal<<endl;
  /* EXEC SQL COMMIT WORK RELEASE; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )70;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt(&ctxLireAnnu, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("Pb YmRevLireAnnu",0);
}


  /* EXEC SQL CONTEXT FREE :ctxLireAnnu; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )85;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&ctxLireAnnu;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(void *);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("Pb YmRevLireAnnu",0);
}


  return;
}

 // Fait delete sur tous les YmRevAnnulation* contenu dans bufVAnnu et vide ce vecteur.
void YmRevLireAnnu::purgeBufAnnu()
{
  int i;
  YmRevAnnulation* pRevAnnu;
  for (i=0; i < bufVAnnu.size(); i++)
  {
    pRevAnnu = bufVAnnu[i];
    delete pRevAnnu;
  }
  bufVAnnu.clear();
}

//place MAX_NBANNU_IN_BUF YmRevAnnulation* dans le vecteur local bufVAnnu (ou moins si g_VAnnulation en contient moins)
int YmRevLireAnnu::fillBufAnnu()
{
  int maxrec = MAX_NBANNU_IN_BUF;
  if (g_VAnnulation.size() < MAX_NBANNU_IN_BUF)
    maxrec = g_VAnnulation.size();
  bufVAnnu.assign (g_VAnnulation.begin(), g_VAnnulation.begin()+maxrec);
  return maxrec;
}


// Insertion dans la table REV_ANNULATION_ECHANGE
void YmRevLireAnnu::InsertAnnulation()
{
  memset (pRevAnnuTable, 0, sizeof(pRevAnnuTable));
  memset (pRevAnnuATraiterTable, 0, sizeof(pRevAnnuATraiterTable));
  int i, k;
  YmRevAnnulation* pRevAnnu;
  //
  //char lsdate[8];
  string lstrdatetemp;
  //
  k = 0;
  for (i=0; i < bufVAnnu.size(); i++)
  {
    pRevAnnu = bufVAnnu[i];

    pRevAnnuATraiterTable[k].tcn_number = pRevAnnu->getTcnAnnule(); 
    if (pRevAnnu->getDateTcn().empty())
      strcpy (pRevAnnuATraiterTable[k].date_paiement, "01/01/2000");
    else
    { 
      lstrdatetemp=pRevAnnu->getDateTcn().substr(6,2)+'/'+pRevAnnu->getDateTcn().substr(4,2)+'/'+pRevAnnu->getDateTcn().substr(0,4);
      
      //lstrdatetemp = string(lsdate,8);
      strcpy (pRevAnnuATraiterTable[k].date_paiement,lstrdatetemp.c_str());
      //
      //strcpy (pRevAnnuATraiterTable[k].date_paiement, ConvertAAAAMMJJ (pRevAnnu->getDateTcn()));
    }
    strcpy (pRevAnnuATraiterTable[k].date_fichier, g_szDateFichier);
    pRevAnnuATraiterTable[k].heure_fichier = g_HeureFichier;



    pRevAnnuTable[k].tcn_annule = pRevAnnu->getTcnAnnule(); 

    if (pRevAnnu->getDateTcn().empty())
      strcpy (pRevAnnuTable[k].date_tcn, "01/01/2000");
    else
    {
      //
      
      strcpy (pRevAnnuTable[k].date_tcn,lstrdatetemp.c_str());
      //
      //strcpy (pRevAnnuTable[k].date_tcn, ConvertAAAAMMJJ (pRevAnnu->getDateTcn()));
    }
    if (pRevAnnu->getDateOperation().empty())
      strcpy (pRevAnnuTable[k].date_operation, "01/01/2000");
    else
    {
      //
      
      strcpy (pRevAnnuTable[k].date_operation,lstrdatetemp.c_str());
      //
      //strcpy (pRevAnnuTable[k].date_operation, ConvertAAAAMMJJ (pRevAnnu->getDateOperation()));
    }
    pRevAnnuTable[k].heure_annulation = atoi (pRevAnnu->getHeureOperation().c_str()); 
    pRevAnnuTable[k].montant_tcn = pRevAnnu->getMontantTcn();
    pRevAnnuTable[k].montant_rembourse = pRevAnnu->getMontantRembourse(); 
    pRevAnnuTable[k].montant_retenues = pRevAnnu->getMontantRetenues(); 

    if (pRevAnnu->getStationOrigine().empty() || pRevAnnu->getStationOrigine() == "     ")  // vide ou 5 espaces
      strcpy (pRevAnnuTable[k].station_origine, "XXXXX");
    else
      strcpy (pRevAnnuTable[k].station_origine, pRevAnnu->getStationOrigine().c_str());

    if (pRevAnnu->getStationDestination().empty() || pRevAnnu->getStationDestination() == "     ") // vide ou 5 espaces
      strcpy (pRevAnnuTable[k].station_destination, "XXXXX");
    else
      strcpy (pRevAnnuTable[k].station_destination, pRevAnnu->getStationDestination().c_str());

    k++;
  }
  cout <<"-";
  /* EXEC SQL WHENEVER SQLERROR GOTO err_annu_insert; */ 

  /* EXEC SQL FOR :nbAnnuInBuf INSERT INTO REV_ANNULATION_ECHANGE 
       (TCN_ANNULE, DATE_TCN, DATE_OPERATION, HEURE_ANNULATION, MONTANT_TCN, MONTANT_REMBOURSE, MONTANT_RETENUES,
        STATION_ORIGINE, STATION_DESTINATION)
       values (:pRevAnnuTable); */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "insert INTO REV_ANNULATION_ECHANGE ( TCN_ANNULE , DATE_TCN \
, DATE_OPERATION , HEURE_ANNULATION , MONTANT_TCN , MONTANT_REMBOURSE , MONTAN\
T_RETENUES , STATION_ORIGINE , STATION_DESTINATION ) values ( :s1 ,:s2 ,:s3 ,:\
s4 ,:s5 ,:s6 ,:s7 ,:s8 ,:s9  ) ";
  sqlstm.iters = (unsigned int  )nbAnnuInBuf;
  sqlstm.offset = (unsigned int  )104;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&pRevAnnuTable->tcn_annule;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct REV_ANNU);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)pRevAnnuTable->date_tcn;
  sqlstm.sqhstl[1] = (unsigned long )11;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct REV_ANNU);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)pRevAnnuTable->date_operation;
  sqlstm.sqhstl[2] = (unsigned long )11;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct REV_ANNU);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&pRevAnnuTable->heure_annulation;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(struct REV_ANNU);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&pRevAnnuTable->montant_tcn;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(struct REV_ANNU);
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&pRevAnnuTable->montant_rembourse;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(struct REV_ANNU);
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&pRevAnnuTable->montant_retenues;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(struct REV_ANNU);
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)pRevAnnuTable->station_origine;
  sqlstm.sqhstl[7] = (unsigned long )6;
  sqlstm.sqhsts[7] = (         int  )sizeof(struct REV_ANNU);
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)pRevAnnuTable->station_destination;
  sqlstm.sqhstl[8] = (unsigned long )6;
  sqlstm.sqhsts[8] = (         int  )sizeof(struct REV_ANNU);
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt(&ctxLireAnnu, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto err_annu_insert;
}


  /* EXEC SQL FOR :nbAnnuInBuf INSERT INTO REV_TCN_A_ANNULER
       (TCN_NUMBER_AA, DATE_PAIEMENT_AA, DATE_FICHIER, HEURE_FICHIER)
       values (:pRevAnnuATraiterTable); */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "insert INTO REV_TCN_A_ANNULER ( TCN_NUMBER_AA , DATE_PAIEME\
NT_AA , DATE_FICHIER , HEURE_FICHIER ) values ( :s1 ,:s2 ,:s3 ,:s4  ) ";
  sqlstm.iters = (unsigned int  )nbAnnuInBuf;
  sqlstm.offset = (unsigned int  )155;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&pRevAnnuATraiterTable->tcn_number;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct REV_TCN_A_ANNULER);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)pRevAnnuATraiterTable->date_paiement;
  sqlstm.sqhstl[1] = (unsigned long )11;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct REV_TCN_A_ANNULER);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)pRevAnnuATraiterTable->date_fichier;
  sqlstm.sqhstl[2] = (unsigned long )11;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct REV_TCN_A_ANNULER);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&pRevAnnuATraiterTable->heure_fichier;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(struct REV_TCN_A_ANNULER);
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt(&ctxLireAnnu, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto err_annu_insert;
}


  nbAnnuTotal += nbAnnuInBuf;
  /* EXEC SQL COMMIT WORK; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )186;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt(&ctxLireAnnu, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto err_annu_insert;
}


  return;

err_annu_insert:
  cerr << "ERROR BULK INSERT ANNULATION: \n";
  char szMess[71];
  strncpy(szMess,sqlca.sqlerrm.sqlerrmc,sqlca.sqlerrm.sqlerrml);
  szMess[sqlca.sqlerrm.sqlerrml]='\0';
  cerr << szMess << "\n";
  /* EXEC SQL ROLLBACK WORK; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )201;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt(&ctxLireAnnu, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto err_annu_insert;
}



  cout<<"insertion ligne a ligne de "<<nbAnnuInBuf<<" ANNULATION"<<endl;
  int j = 0;
  for (j = 0; j < nbAnnuInBuf; j++)
  {
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    pRevAnnuSingle[0] = pRevAnnuTable[j];
    /* EXEC SQL FOR 1 INSERT INTO REV_ANNULATION_ECHANGE 
       (TCN_ANNULE, DATE_TCN, DATE_OPERATION, HEURE_ANNULATION, MONTANT_TCN, MONTANT_REMBOURSE, MONTANT_RETENUES,
        STATION_ORIGINE, STATION_DESTINATION)
       values (:pRevAnnuSingle); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 9;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert INTO REV_ANNULATION_ECHANGE ( TCN_ANNULE , DATE_TC\
N , DATE_OPERATION , HEURE_ANNULATION , MONTANT_TCN , MONTANT_REMBOURSE , MONT\
ANT_RETENUES , STATION_ORIGINE , STATION_DESTINATION ) values ( :s1 ,:s2 ,:s3 \
,:s4 ,:s5 ,:s6 ,:s7 ,:s8 ,:s9  ) ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )216;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&pRevAnnuSingle->tcn_annule;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )sizeof(struct REV_ANNU);
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)pRevAnnuSingle->date_tcn;
    sqlstm.sqhstl[1] = (unsigned long )11;
    sqlstm.sqhsts[1] = (         int  )sizeof(struct REV_ANNU);
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)pRevAnnuSingle->date_operation;
    sqlstm.sqhstl[2] = (unsigned long )11;
    sqlstm.sqhsts[2] = (         int  )sizeof(struct REV_ANNU);
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&pRevAnnuSingle->heure_annulation;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )sizeof(struct REV_ANNU);
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&pRevAnnuSingle->montant_tcn;
    sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[4] = (         int  )sizeof(struct REV_ANNU);
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqharc[4] = (unsigned long  *)0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&pRevAnnuSingle->montant_rembourse;
    sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[5] = (         int  )sizeof(struct REV_ANNU);
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqharc[5] = (unsigned long  *)0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&pRevAnnuSingle->montant_retenues;
    sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[6] = (         int  )sizeof(struct REV_ANNU);
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqharc[6] = (unsigned long  *)0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)pRevAnnuSingle->station_origine;
    sqlstm.sqhstl[7] = (unsigned long )6;
    sqlstm.sqhsts[7] = (         int  )sizeof(struct REV_ANNU);
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqharc[7] = (unsigned long  *)0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)pRevAnnuSingle->station_destination;
    sqlstm.sqhstl[8] = (unsigned long )6;
    sqlstm.sqhsts[8] = (         int  )sizeof(struct REV_ANNU);
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqharc[8] = (unsigned long  *)0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt(&ctxLireAnnu, &sqlctx, &sqlstm, &sqlfpn);
}



    /* EXEC SQL WHENEVER SQLERROR DO sql_warn ("ANNU", pRevAnnuTable[j].tcn_annule, nbAnnuTotal); */ 

    pRevAnnuATraiterSingle[0] = pRevAnnuATraiterTable[j];
    /* EXEC SQL FOR 1 INSERT INTO REV_TCN_A_ANNULER
       (TCN_NUMBER_AA, DATE_PAIEMENT_AA, DATE_FICHIER, HEURE_FICHIER)
       values (:pRevAnnuATraiterSingle); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 9;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert INTO REV_TCN_A_ANNULER ( TCN_NUMBER_AA , DATE_PAIE\
MENT_AA , DATE_FICHIER , HEURE_FICHIER ) values ( :s1 ,:s2 ,:s3 ,:s4  ) ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )267;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&pRevAnnuATraiterSingle->tcn_number;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )sizeof(struct REV_TCN_A_ANNULER);
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)pRevAnnuATraiterSingle->date_paiement;
    sqlstm.sqhstl[1] = (unsigned long )11;
    sqlstm.sqhsts[1] = (         int  )sizeof(struct REV_TCN_A_ANNULER);
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)pRevAnnuATraiterSingle->date_fichier;
    sqlstm.sqhstl[2] = (unsigned long )11;
    sqlstm.sqhsts[2] = (         int  )sizeof(struct REV_TCN_A_ANNULER);
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&pRevAnnuATraiterSingle->heure_fichier;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )sizeof(struct REV_TCN_A_ANNULER);
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt(&ctxLireAnnu, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_warn("ANNU",(pRevAnnuTable[j].tcn_annule),nbAnnuTotal);
}


    nbAnnuTotal ++;
  }
  /* EXEC SQL COMMIT WORK; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )298;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt(&ctxLireAnnu, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_warn("ANNU",(pRevAnnuTable[j].tcn_annule),nbAnnuTotal);
}


}

