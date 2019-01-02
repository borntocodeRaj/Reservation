
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
           char  filnam[21];
};
static const struct sqlcxp sqlfpn =
{
    20,
    "YmRevLireRetraits.pc"
};


static unsigned int sqlctx = 87415251;


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
   unsigned char  *sqhstv[3];
   unsigned long  sqhstl[3];
            int   sqhsts[3];
            short *sqindv[3];
            int   sqinds[3];
   unsigned long  sqharm[3];
   unsigned long  *sqharc[3];
   unsigned short  sqadto[3];
   unsigned short  sqtdso[3];
} sqlstm = {12,3};

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
5,0,0,1,128,0,5,97,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,68,0,0,
32,0,0,2,0,0,29,100,0,0,0,0,0,1,0,
};


//---------------------------------------------------------------------------------------------------------
// lecture des donness RESAVEN retraits placee dans le vecteur par le Thread EcrireVec
// --------------------------------------------------------------------------------------------------------

using namespace std;

#include <iostream>
#include </usr/lib/oracle/11.2/client64/precomp/public/sqlca.h>
#include <unistd.h>
#include <YmRevDate.h>
#include <YmRevGlobal.h>
#include <YmRevLireRetraits.h>

//## Configuration du contexte de base JRO IC SRO DT 23805
extern sql_context ctxRevMain;
/* EXEC SQL CONTEXT USE :ctxRevMain; */ 


/* EXEC SQL BEGIN DECLARE SECTION; */ 


#define MAX_NBRETRAITS_IN_BUF 500

int nbRetraitsInBuf;

char pCanalEmissionTable[MAX_NBRETRAITS_IN_BUF][6];
char pDateTable[MAX_NBRETRAITS_IN_BUF][17];
unsigned int pTcnNumberTable[MAX_NBRETRAITS_IN_BUF];

/* EXEC SQL END DECLARE SECTION; */ 




YmRevLireRetraits::YmRevLireRetraits()
{
  nbRetraits = 0;
}

YmRevLireRetraits::~YmRevLireRetraits()
{
}

void YmRevLireRetraits::Start()
{
  /* EXEC SQL WHENEVER SQLERROR DO sql_error ((char*)"Pb YmRevLireRetraits", 0); */ 


  // On attend que la lecture du ResaVen et l'ecriture en base soit finies
  while (g_EcrireVecEnCours || g_NbThreadLecteur)
    sleep(6);

  while (g_VRetraits.size())
  { // Normalement LOCK et UNLOCK sont inutile, mais on garde pour faire joli.
    LOCK_MUTEX (&g_MutexVRetraits);
    nbRetraitsInBuf = fillBufRetrait();
    g_VRetraits.erase (g_VRetraits.begin(), g_VRetraits.begin()+nbRetraitsInBuf);
    // rappel erase supprime entre first inclu et last exclu.
    UNLOCK_MUTEX (&g_MutexVRetraits);
    if (nbRetraitsInBuf)
      UpdateRetraits();
  }
  cout<<endl;
  cout<<DonneHeure()<<" Fin LireRetraits  nombre:"<<nbRetraits<<endl;
}


//place MAX_NBRETRAITS_IN_BUF YmRevRetraits dans les tableaux (ou moins si g_VRetraits en contient moins)
int YmRevLireRetraits::fillBufRetrait()
{
  int maxrec = MAX_NBRETRAITS_IN_BUF;
  if (g_VRetraits.size() < MAX_NBRETRAITS_IN_BUF)
    maxrec = g_VRetraits.size();
  int i;
  string lstrdatetemp;
  YmRevRetraits* pRetrait;
  for (i = 0; i < maxrec; i++)
  {
    pRetrait = g_VRetraits[i];
    strcpy (pCanalEmissionTable[i], pRetrait->getCanalEmission().c_str());
    //
    lstrdatetemp=pRetrait->getDateTransaction().substr(6,2)+'/'+pRetrait->getDateTransaction().substr(4,2)+'/'+pRetrait->getDateTransaction().substr(0,4);
    strcpy (pDateTable[i],lstrdatetemp.c_str() );
    //

    //strcpy (pDateTable[i], ConvertAAAAMMJJ (pRetrait->getDateTransaction()));
    strcat (pDateTable[i], " ");
    strcat (pDateTable[i], pRetrait->getHeureTransaction().c_str());
    pTcnNumberTable[i] = pRetrait->getTcnNumber();
    delete pRetrait;
  }
  return maxrec;
}


// Mise a jour des champs DATE_EMISSION_PHYSIQUE et IATA_VENTE de REV_TCN
void YmRevLireRetraits::UpdateRetraits()
{
  cout <<"r";
  nbRetraits += nbRetraitsInBuf;
  /* EXEC SQL FOR :nbRetraitsInBuf UPDATE REV_TCN SET DATE_EMISSION_PHYSIQUE = TO_DATE (:pDateTable, 'dd/mm/yyyy hh24mi'),
                                                   CANAL_EMISSION = :pCanalEmissionTable
			  WHERE TCN_NUMBER = :pTcnNumberTable; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 3;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "update REV_TCN SET DATE_EMISSION_PHYSIQUE = TO_DATE ( :b1 ,\
 'dd/mm/yyyy hh24mi' ) , CANAL_EMISSION = :b2 WHERE TCN_NUMBER = :b3 ";
  sqlstm.iters = (unsigned int  )nbRetraitsInBuf;
  sqlstm.offset = (unsigned int  )5;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)pDateTable;
  sqlstm.sqhstl[0] = (unsigned long )17;
  sqlstm.sqhsts[0] = (         int  )17;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)pCanalEmissionTable;
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )6;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)pTcnNumberTable;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(int);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("Pb YmRevLireRetraits",0);
}

 
  /* EXEC SQL COMMIT WORK; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 3;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )32;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("Pb YmRevLireRetraits",0);
}


}

