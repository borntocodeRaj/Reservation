
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
    "YmRevMapTpFBC.pc"
};


static unsigned int sqlctx = 5461139;


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
5,0,0,1,185,0,3,164,0,0,9,9,0,1,0,1,3,0,0,1,97,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
56,0,0,2,0,0,29,167,0,0,0,0,0,1,0,
71,0,0,3,185,0,3,175,0,0,9,9,0,1,0,1,3,0,0,1,97,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
122,0,0,4,0,0,29,179,0,0,0,0,0,1,0,
137,0,0,5,196,0,3,228,0,0,9,9,0,1,0,1,3,0,0,1,97,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,
188,0,0,6,0,0,29,231,0,0,0,0,0,1,0,
203,0,0,7,196,0,3,239,0,0,9,9,0,1,0,1,3,0,0,1,97,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,
254,0,0,8,0,0,29,242,0,0,0,0,0,1,0,
};


#pragma ident "%Z% FileName: $RCSfile: YmRevMapTpFBC.pc,v $ Version: $Revision: 1.2 $ Date: $Date: 2009/02/20 13:10:57 $ %Z %"

//## Module: YmRevMapTpFBC
//SFD
//  Name:    YmRevMapTpFBC.cpp
//  Author:  JM. Grugeaux
//  Desc:    traitement de la liste des code tarifs
//EFD


using namespace std;

//standard includes
#include <iterator>
#include </usr/lib/oracle/11.2/client64/precomp/public/sqlca.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
//application includes
#include <YmRevGlobal.h>
#include <YmRevMapTpFBC.h>

//## Configuration du contexte de base JRO IC SRO DT 23805
extern sql_context ctxRevMain;
/* EXEC SQL CONTEXT USE :ctxRevMain; */ 


/* EXEC SQL BEGIN DECLARE SECTION; */ 


#define MAX_NB_TPREVFBC 1000

int nbInBulk;

struct TPREV_FBC {
        int tranche_no;
        char dpt_date[11];
        /* varchar orig[6]; */ 
struct { unsigned short len; unsigned char arr[6]; } orig;

        /* varchar dest[6]; */ 
struct { unsigned short len; unsigned char arr[6]; } dest;

        /* varchar fare_basis_code[9]; */ 
struct { unsigned short len; unsigned char arr[9]; } fare_basis_code;

        char date_od[11];
        int nb_voyageurs;
        int market_id;
        int revenu;
      } pTpRevFBCTable[MAX_NB_TPREVFBC];

struct TPREV_FBC_NON_TRAITE {
        int tranche_no;
        char dpt_date[11];
        /* varchar orig[6]; */ 
struct { unsigned short len; unsigned char arr[6]; } orig;

        /* varchar dest[6]; */ 
struct { unsigned short len; unsigned char arr[6]; } dest;

        /* varchar fare_basis_code[9]; */ 
struct { unsigned short len; unsigned char arr[9]; } fare_basis_code;

        char date_od[11];
        int nb_voyageurs;
        int revenu;
        char date_fichier[11];
      } pTpRevFBCNTTable[MAX_NB_TPREVFBC];

/* EXEC SQL END DECLARE SECTION; */ 




YmRevMapTpFBC::YmRevMapTpFBC()
{
}

YmRevMapTpFBC::~YmRevMapTpFBC()
{
   Clear();
}

void YmRevMapTpFBC::Clear()
{
    MapTpFBCType::iterator iPos = _MapTpFBC.begin();
    MapTpFBCType::iterator iFin = _MapTpFBC.end();

    YmRevTpFBC* pTpFBC;
    while (iPos!=iFin)
       {
       pTpFBC =iPos->second;
       delete pTpFBC;
       iPos++;
       }
    _MapTpFBC.clear();
}

void YmRevMapTpFBC::Add (YmRevTpFBC* pTpFBC)
{
  string skey;
  char cTrNo[10];
  sprintf (cTrNo, "%d", pTpFBC->getTrancheNo());
  skey = cTrNo;
  skey += pTpFBC->getDateOd();
  skey += pTpFBC->getOrig();
  skey += pTpFBC->getDest();
  skey += pTpFBC->getFareBasisCode();
  _MapTpFBC[skey] = pTpFBC;
}

YmRevTpFBC* YmRevMapTpFBC::isInMap(int tranche_no, char* date_od, string orig, string dest, string fare_basis_code)
                                 //retourne un pointeur sur YmRevTpFBC si deja present
    {
    MapTpFBCType::iterator iPos;
    YmRevTpFBC* pTpFBC;

    char cTrNo[10];
    sprintf (cTrNo, "%d", tranche_no);
    string skey = cTrNo;
    skey += date_od;
    skey += orig;
    skey += dest;
    skey += fare_basis_code;
    iPos = _MapTpFBC.find (skey);
    if (iPos == _MapTpFBC.end())
      return NULL;

    pTpFBC = iPos->second;
    return pTpFBC;
    }


void YmRevMapTpFBC::InsertTPREVFBC()
{
  if (!strcmp (g_Client, "SN") && !g_forceFBC)
    return; // Si SNCF et pas de FBC force, on ne fait rien
  int totalRevenu = 0;
  int totalPassagers = 0;
  cout<<DonneHeure()<<" Ecriture dans dans TPREV_FBC_OD"<<endl;
  
  /* EXEC SQL WHENEVER SQLERROR DO sql_error  ("INSERT IN TPREV_FBC_OD en erreur", 0); */ 

  MapTpFBCType::iterator iPos = _MapTpFBC.begin();
  MapTpFBCType::iterator iFin = _MapTpFBC.end();

  YmRevTpFBC* pTpFBC;
  nbInBulk = MAX_NB_TPREVFBC;
  int i = 0;
  int nbl = 0;
  while (iPos!=iFin)
  {
     pTpFBC =iPos->second;
     if (pTpFBC->getTypeFlag() != 2)
     {
       pTpRevFBCTable[i].tranche_no = pTpFBC->getTrancheNo();
       strcpy (pTpRevFBCTable[i].dpt_date, pTpFBC->getDptDate());
       strcpy ((char*)pTpRevFBCTable[i].orig.arr, pTpFBC->getOrig().c_str());
       pTpRevFBCTable[i].orig.len = pTpFBC->getOrig().size();
       strcpy ((char*)pTpRevFBCTable[i].dest.arr, pTpFBC->getDest().c_str());
       pTpRevFBCTable[i].dest.len = pTpFBC->getDest().size();
       strcpy ((char*)pTpRevFBCTable[i].fare_basis_code.arr, pTpFBC->getFareBasisCode().c_str());
       pTpRevFBCTable[i].fare_basis_code.len = pTpFBC->getFareBasisCode().size();
       strcpy (pTpRevFBCTable[i].date_od, pTpFBC->getDateOd());
       pTpRevFBCTable[i].nb_voyageurs = pTpFBC->getNbVoyageurs();
       pTpRevFBCTable[i].market_id = 0;
       pTpRevFBCTable[i].revenu = pTpFBC->getRevenu();

       totalPassagers += pTpFBC->getNbVoyageurs();
       totalRevenu += pTpFBC->getRevenu();
       i++;
       nbl ++;
     }
     iPos++;

     if (i == nbInBulk)
     {
       /* EXEC SQL FOR :nbInBulk INSERT INTO TPREV_FBC_OD
         (TRANCHE_NO, DPT_DATE, ORIG, DEST, FARE_BASIS_CODE, DATE_OD, NB_VOYAGEURS, MARKET_ID, REVENU)
         values (:pTpRevFBCTable); */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 12;
       sqlstm.arrsiz = 9;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.stmt = "insert INTO TPREV_FBC_OD ( TRANCHE_NO , DPT_DATE , ORI\
G , DEST , FARE_BASIS_CODE , DATE_OD , NB_VOYAGEURS , MARKET_ID , REVENU ) val\
ues ( :s1 ,:s2 ,:s3 ,:s4 ,:s5 ,:s6 ,:s7 ,:s8 ,:s9  ) ";
       sqlstm.iters = (unsigned int  )nbInBulk;
       sqlstm.offset = (unsigned int  )5;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlstm.sqhstv[0] = (unsigned char  *)&pTpRevFBCTable->tranche_no;
       sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[0] = (         int  )sizeof(struct TPREV_FBC);
       sqlstm.sqindv[0] = (         short *)0;
       sqlstm.sqinds[0] = (         int  )0;
       sqlstm.sqharm[0] = (unsigned long )0;
       sqlstm.sqharc[0] = (unsigned long  *)0;
       sqlstm.sqadto[0] = (unsigned short )0;
       sqlstm.sqtdso[0] = (unsigned short )0;
       sqlstm.sqhstv[1] = (unsigned char  *)pTpRevFBCTable->dpt_date;
       sqlstm.sqhstl[1] = (unsigned long )11;
       sqlstm.sqhsts[1] = (         int  )sizeof(struct TPREV_FBC);
       sqlstm.sqindv[1] = (         short *)0;
       sqlstm.sqinds[1] = (         int  )0;
       sqlstm.sqharm[1] = (unsigned long )0;
       sqlstm.sqharc[1] = (unsigned long  *)0;
       sqlstm.sqadto[1] = (unsigned short )0;
       sqlstm.sqtdso[1] = (unsigned short )0;
       sqlstm.sqhstv[2] = (unsigned char  *)&pTpRevFBCTable->orig;
       sqlstm.sqhstl[2] = (unsigned long )8;
       sqlstm.sqhsts[2] = (         int  )sizeof(struct TPREV_FBC);
       sqlstm.sqindv[2] = (         short *)0;
       sqlstm.sqinds[2] = (         int  )0;
       sqlstm.sqharm[2] = (unsigned long )0;
       sqlstm.sqharc[2] = (unsigned long  *)0;
       sqlstm.sqadto[2] = (unsigned short )0;
       sqlstm.sqtdso[2] = (unsigned short )0;
       sqlstm.sqhstv[3] = (unsigned char  *)&pTpRevFBCTable->dest;
       sqlstm.sqhstl[3] = (unsigned long )8;
       sqlstm.sqhsts[3] = (         int  )sizeof(struct TPREV_FBC);
       sqlstm.sqindv[3] = (         short *)0;
       sqlstm.sqinds[3] = (         int  )0;
       sqlstm.sqharm[3] = (unsigned long )0;
       sqlstm.sqharc[3] = (unsigned long  *)0;
       sqlstm.sqadto[3] = (unsigned short )0;
       sqlstm.sqtdso[3] = (unsigned short )0;
       sqlstm.sqhstv[4] = (unsigned char  *)&pTpRevFBCTable->fare_basis_code;
       sqlstm.sqhstl[4] = (unsigned long )11;
       sqlstm.sqhsts[4] = (         int  )sizeof(struct TPREV_FBC);
       sqlstm.sqindv[4] = (         short *)0;
       sqlstm.sqinds[4] = (         int  )0;
       sqlstm.sqharm[4] = (unsigned long )0;
       sqlstm.sqharc[4] = (unsigned long  *)0;
       sqlstm.sqadto[4] = (unsigned short )0;
       sqlstm.sqtdso[4] = (unsigned short )0;
       sqlstm.sqhstv[5] = (unsigned char  *)pTpRevFBCTable->date_od;
       sqlstm.sqhstl[5] = (unsigned long )11;
       sqlstm.sqhsts[5] = (         int  )sizeof(struct TPREV_FBC);
       sqlstm.sqindv[5] = (         short *)0;
       sqlstm.sqinds[5] = (         int  )0;
       sqlstm.sqharm[5] = (unsigned long )0;
       sqlstm.sqharc[5] = (unsigned long  *)0;
       sqlstm.sqadto[5] = (unsigned short )0;
       sqlstm.sqtdso[5] = (unsigned short )0;
       sqlstm.sqhstv[6] = (unsigned char  *)&pTpRevFBCTable->nb_voyageurs;
       sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[6] = (         int  )sizeof(struct TPREV_FBC);
       sqlstm.sqindv[6] = (         short *)0;
       sqlstm.sqinds[6] = (         int  )0;
       sqlstm.sqharm[6] = (unsigned long )0;
       sqlstm.sqharc[6] = (unsigned long  *)0;
       sqlstm.sqadto[6] = (unsigned short )0;
       sqlstm.sqtdso[6] = (unsigned short )0;
       sqlstm.sqhstv[7] = (unsigned char  *)&pTpRevFBCTable->market_id;
       sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[7] = (         int  )sizeof(struct TPREV_FBC);
       sqlstm.sqindv[7] = (         short *)0;
       sqlstm.sqinds[7] = (         int  )0;
       sqlstm.sqharm[7] = (unsigned long )0;
       sqlstm.sqharc[7] = (unsigned long  *)0;
       sqlstm.sqadto[7] = (unsigned short )0;
       sqlstm.sqtdso[7] = (unsigned short )0;
       sqlstm.sqhstv[8] = (unsigned char  *)&pTpRevFBCTable->revenu;
       sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[8] = (         int  )sizeof(struct TPREV_FBC);
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
       sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
       if (sqlca.sqlcode < 0) sql_error("INSERT IN TPREV_FBC_OD en erreur",0);
}


       /* EXEC SQL COMMIT WORK; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 12;
       sqlstm.arrsiz = 9;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )56;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
       if (sqlca.sqlcode < 0) sql_error("INSERT IN TPREV_FBC_OD en erreur",0);
}


       cout<<"t";
       i = 0;
     }
  }
  if (i)
  { // On insere le reliquat
    nbInBulk = i;
    /* EXEC SQL FOR :nbInBulk INSERT INTO TPREV_FBC_OD
         (TRANCHE_NO, DPT_DATE, ORIG, DEST, FARE_BASIS_CODE, DATE_OD, NB_VOYAGEURS,
          MARKET_ID, REVENU)
         values (:pTpRevFBCTable); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 9;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert INTO TPREV_FBC_OD ( TRANCHE_NO , DPT_DATE , ORIG ,\
 DEST , FARE_BASIS_CODE , DATE_OD , NB_VOYAGEURS , MARKET_ID , REVENU ) values\
 ( :s1 ,:s2 ,:s3 ,:s4 ,:s5 ,:s6 ,:s7 ,:s8 ,:s9  ) ";
    sqlstm.iters = (unsigned int  )nbInBulk;
    sqlstm.offset = (unsigned int  )71;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&pTpRevFBCTable->tranche_no;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )sizeof(struct TPREV_FBC);
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)pTpRevFBCTable->dpt_date;
    sqlstm.sqhstl[1] = (unsigned long )11;
    sqlstm.sqhsts[1] = (         int  )sizeof(struct TPREV_FBC);
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&pTpRevFBCTable->orig;
    sqlstm.sqhstl[2] = (unsigned long )8;
    sqlstm.sqhsts[2] = (         int  )sizeof(struct TPREV_FBC);
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&pTpRevFBCTable->dest;
    sqlstm.sqhstl[3] = (unsigned long )8;
    sqlstm.sqhsts[3] = (         int  )sizeof(struct TPREV_FBC);
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&pTpRevFBCTable->fare_basis_code;
    sqlstm.sqhstl[4] = (unsigned long )11;
    sqlstm.sqhsts[4] = (         int  )sizeof(struct TPREV_FBC);
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqharc[4] = (unsigned long  *)0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)pTpRevFBCTable->date_od;
    sqlstm.sqhstl[5] = (unsigned long )11;
    sqlstm.sqhsts[5] = (         int  )sizeof(struct TPREV_FBC);
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqharc[5] = (unsigned long  *)0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&pTpRevFBCTable->nb_voyageurs;
    sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[6] = (         int  )sizeof(struct TPREV_FBC);
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqharc[6] = (unsigned long  *)0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)&pTpRevFBCTable->market_id;
    sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[7] = (         int  )sizeof(struct TPREV_FBC);
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqharc[7] = (unsigned long  *)0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)&pTpRevFBCTable->revenu;
    sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[8] = (         int  )sizeof(struct TPREV_FBC);
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
    sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("INSERT IN TPREV_FBC_OD en erreur",0);
}


    /* EXEC SQL COMMIT WORK; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 9;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )122;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("INSERT IN TPREV_FBC_OD en erreur",0);
}


    cout<<"t";
  }
  cout<<endl;
  cout<<DonneHeure()<<" Fin insert "<<nbl<<" lignes dans TPREV_FBC_OD, totRevenu="<<totalRevenu<<" totPas="<<totalPassagers<<endl;
}

void YmRevMapTpFBC::InsertTPREVFBCNONTRAITE()
{
  if (!strcmp (g_Client, "SN") && !g_forceFBC)
    return; // Si SNCF et pas de FBC force, on ne fait rien
  int totalRevenu = 0;
  int totalPassagers = 0;
  cout<<DonneHeure()<<" Ecriture dans dans TPREV_FBC_NON_TRAITE"<<endl;

  /* EXEC SQL WHENEVER SQLERROR DO sql_error  ("INSERT IN TPREV_FBC_NON_TRAITE en erreur", 0); */ 

  MapTpFBCType::iterator iPos = _MapTpFBC.begin();
  MapTpFBCType::iterator iFin = _MapTpFBC.end();

  YmRevTpFBC* pTpFBC;
  nbInBulk = MAX_NB_TPREVFBC;
  int i = 0;
  int nbl = 0;
  while (iPos!=iFin)
  {
     pTpFBC =iPos->second;
     if (pTpFBC->getTypeFlag() == 2)
     {
       pTpRevFBCNTTable[i].tranche_no = pTpFBC->getTrancheNo();
       strcpy (pTpRevFBCNTTable[i].dpt_date, pTpFBC->getDptDate());
       strcpy ((char*)pTpRevFBCNTTable[i].orig.arr, pTpFBC->getOrig().c_str());
       pTpRevFBCNTTable[i].orig.len = pTpFBC->getOrig().size();
       strcpy ((char*)pTpRevFBCNTTable[i].dest.arr, pTpFBC->getDest().c_str());
       pTpRevFBCNTTable[i].dest.len = pTpFBC->getDest().size();
       strcpy ((char*)pTpRevFBCNTTable[i].fare_basis_code.arr, pTpFBC->getFareBasisCode().c_str());
       pTpRevFBCNTTable[i].fare_basis_code.len = pTpFBC->getFareBasisCode().size();
       strcpy (pTpRevFBCNTTable[i].date_od, pTpFBC->getDateOd());
       pTpRevFBCNTTable[i].nb_voyageurs = pTpFBC->getNbVoyageurs();
       pTpRevFBCNTTable[i].revenu = pTpFBC->getRevenu();
       strcpy (pTpRevFBCNTTable[i].date_fichier, pTpFBC->getDateFichier());

       totalPassagers += pTpFBC->getNbVoyageurs();
       totalRevenu += pTpFBC->getRevenu();
       i++;
       nbl ++;
     }
     iPos++;
     if (i == nbInBulk)
     {
       /* EXEC SQL FOR :nbInBulk INSERT INTO TPREV_FBC_NON_TRAITE
         (TRANCHE_NO, DPT_DATE, ORIG, DEST, FARE_BASIS_CODE, DATE_OD, NB_VOYAGEURS, REVENU, DATE_FICHIER)
         values (:pTpRevFBCNTTable); */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 12;
       sqlstm.arrsiz = 9;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.stmt = "insert INTO TPREV_FBC_NON_TRAITE ( TRANCHE_NO , DPT_DA\
TE , ORIG , DEST , FARE_BASIS_CODE , DATE_OD , NB_VOYAGEURS , REVENU , DATE_FI\
CHIER ) values ( :s1 ,:s2 ,:s3 ,:s4 ,:s5 ,:s6 ,:s7 ,:s8 ,:s9  ) ";
       sqlstm.iters = (unsigned int  )nbInBulk;
       sqlstm.offset = (unsigned int  )137;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlstm.sqhstv[0] = (unsigned char  *)&pTpRevFBCNTTable->tranche_no;
       sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[0] = (         int  )sizeof(struct TPREV_FBC_NON_TRAITE);
       sqlstm.sqindv[0] = (         short *)0;
       sqlstm.sqinds[0] = (         int  )0;
       sqlstm.sqharm[0] = (unsigned long )0;
       sqlstm.sqharc[0] = (unsigned long  *)0;
       sqlstm.sqadto[0] = (unsigned short )0;
       sqlstm.sqtdso[0] = (unsigned short )0;
       sqlstm.sqhstv[1] = (unsigned char  *)pTpRevFBCNTTable->dpt_date;
       sqlstm.sqhstl[1] = (unsigned long )11;
       sqlstm.sqhsts[1] = (         int  )sizeof(struct TPREV_FBC_NON_TRAITE);
       sqlstm.sqindv[1] = (         short *)0;
       sqlstm.sqinds[1] = (         int  )0;
       sqlstm.sqharm[1] = (unsigned long )0;
       sqlstm.sqharc[1] = (unsigned long  *)0;
       sqlstm.sqadto[1] = (unsigned short )0;
       sqlstm.sqtdso[1] = (unsigned short )0;
       sqlstm.sqhstv[2] = (unsigned char  *)&pTpRevFBCNTTable->orig;
       sqlstm.sqhstl[2] = (unsigned long )8;
       sqlstm.sqhsts[2] = (         int  )sizeof(struct TPREV_FBC_NON_TRAITE);
       sqlstm.sqindv[2] = (         short *)0;
       sqlstm.sqinds[2] = (         int  )0;
       sqlstm.sqharm[2] = (unsigned long )0;
       sqlstm.sqharc[2] = (unsigned long  *)0;
       sqlstm.sqadto[2] = (unsigned short )0;
       sqlstm.sqtdso[2] = (unsigned short )0;
       sqlstm.sqhstv[3] = (unsigned char  *)&pTpRevFBCNTTable->dest;
       sqlstm.sqhstl[3] = (unsigned long )8;
       sqlstm.sqhsts[3] = (         int  )sizeof(struct TPREV_FBC_NON_TRAITE);
       sqlstm.sqindv[3] = (         short *)0;
       sqlstm.sqinds[3] = (         int  )0;
       sqlstm.sqharm[3] = (unsigned long )0;
       sqlstm.sqharc[3] = (unsigned long  *)0;
       sqlstm.sqadto[3] = (unsigned short )0;
       sqlstm.sqtdso[3] = (unsigned short )0;
       sqlstm.sqhstv[4] = (unsigned char  *)&pTpRevFBCNTTable->fare_basis_code;
       sqlstm.sqhstl[4] = (unsigned long )11;
       sqlstm.sqhsts[4] = (         int  )sizeof(struct TPREV_FBC_NON_TRAITE);
       sqlstm.sqindv[4] = (         short *)0;
       sqlstm.sqinds[4] = (         int  )0;
       sqlstm.sqharm[4] = (unsigned long )0;
       sqlstm.sqharc[4] = (unsigned long  *)0;
       sqlstm.sqadto[4] = (unsigned short )0;
       sqlstm.sqtdso[4] = (unsigned short )0;
       sqlstm.sqhstv[5] = (unsigned char  *)pTpRevFBCNTTable->date_od;
       sqlstm.sqhstl[5] = (unsigned long )11;
       sqlstm.sqhsts[5] = (         int  )sizeof(struct TPREV_FBC_NON_TRAITE);
       sqlstm.sqindv[5] = (         short *)0;
       sqlstm.sqinds[5] = (         int  )0;
       sqlstm.sqharm[5] = (unsigned long )0;
       sqlstm.sqharc[5] = (unsigned long  *)0;
       sqlstm.sqadto[5] = (unsigned short )0;
       sqlstm.sqtdso[5] = (unsigned short )0;
       sqlstm.sqhstv[6] = (unsigned char  *)&pTpRevFBCNTTable->nb_voyageurs;
       sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[6] = (         int  )sizeof(struct TPREV_FBC_NON_TRAITE);
       sqlstm.sqindv[6] = (         short *)0;
       sqlstm.sqinds[6] = (         int  )0;
       sqlstm.sqharm[6] = (unsigned long )0;
       sqlstm.sqharc[6] = (unsigned long  *)0;
       sqlstm.sqadto[6] = (unsigned short )0;
       sqlstm.sqtdso[6] = (unsigned short )0;
       sqlstm.sqhstv[7] = (unsigned char  *)&pTpRevFBCNTTable->revenu;
       sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[7] = (         int  )sizeof(struct TPREV_FBC_NON_TRAITE);
       sqlstm.sqindv[7] = (         short *)0;
       sqlstm.sqinds[7] = (         int  )0;
       sqlstm.sqharm[7] = (unsigned long )0;
       sqlstm.sqharc[7] = (unsigned long  *)0;
       sqlstm.sqadto[7] = (unsigned short )0;
       sqlstm.sqtdso[7] = (unsigned short )0;
       sqlstm.sqhstv[8] = (unsigned char  *)pTpRevFBCNTTable->date_fichier;
       sqlstm.sqhstl[8] = (unsigned long )11;
       sqlstm.sqhsts[8] = (         int  )sizeof(struct TPREV_FBC_NON_TRAITE);
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
       sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
       if (sqlca.sqlcode < 0) sql_error("INSERT IN TPREV_FBC_NON_TRAITE en erreur",0);
}


       /* EXEC SQL COMMIT WORK; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 12;
       sqlstm.arrsiz = 9;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )188;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
       if (sqlca.sqlcode < 0) sql_error("INSERT IN TPREV_FBC_NON_TRAITE en erreur",0);
}


       cout<<"t";
       i = 0;
     }
  }
  if (i)
  { // On insere le reliquat
    nbInBulk = i;
    /* EXEC SQL FOR :nbInBulk INSERT INTO TPREV_FBC_NON_TRAITE
         (TRANCHE_NO, DPT_DATE, ORIG, DEST, FARE_BASIS_CODE, DATE_OD, NB_VOYAGEURS, REVENU, DATE_FICHIER)
         values (:pTpRevFBCNTTable); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 9;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert INTO TPREV_FBC_NON_TRAITE ( TRANCHE_NO , DPT_DATE \
, ORIG , DEST , FARE_BASIS_CODE , DATE_OD , NB_VOYAGEURS , REVENU , DATE_FICHI\
ER ) values ( :s1 ,:s2 ,:s3 ,:s4 ,:s5 ,:s6 ,:s7 ,:s8 ,:s9  ) ";
    sqlstm.iters = (unsigned int  )nbInBulk;
    sqlstm.offset = (unsigned int  )203;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&pTpRevFBCNTTable->tranche_no;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )sizeof(struct TPREV_FBC_NON_TRAITE);
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)pTpRevFBCNTTable->dpt_date;
    sqlstm.sqhstl[1] = (unsigned long )11;
    sqlstm.sqhsts[1] = (         int  )sizeof(struct TPREV_FBC_NON_TRAITE);
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&pTpRevFBCNTTable->orig;
    sqlstm.sqhstl[2] = (unsigned long )8;
    sqlstm.sqhsts[2] = (         int  )sizeof(struct TPREV_FBC_NON_TRAITE);
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&pTpRevFBCNTTable->dest;
    sqlstm.sqhstl[3] = (unsigned long )8;
    sqlstm.sqhsts[3] = (         int  )sizeof(struct TPREV_FBC_NON_TRAITE);
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&pTpRevFBCNTTable->fare_basis_code;
    sqlstm.sqhstl[4] = (unsigned long )11;
    sqlstm.sqhsts[4] = (         int  )sizeof(struct TPREV_FBC_NON_TRAITE);
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqharc[4] = (unsigned long  *)0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)pTpRevFBCNTTable->date_od;
    sqlstm.sqhstl[5] = (unsigned long )11;
    sqlstm.sqhsts[5] = (         int  )sizeof(struct TPREV_FBC_NON_TRAITE);
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqharc[5] = (unsigned long  *)0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&pTpRevFBCNTTable->nb_voyageurs;
    sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[6] = (         int  )sizeof(struct TPREV_FBC_NON_TRAITE);
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqharc[6] = (unsigned long  *)0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)&pTpRevFBCNTTable->revenu;
    sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[7] = (         int  )sizeof(struct TPREV_FBC_NON_TRAITE);
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqharc[7] = (unsigned long  *)0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)pTpRevFBCNTTable->date_fichier;
    sqlstm.sqhstl[8] = (unsigned long )11;
    sqlstm.sqhsts[8] = (         int  )sizeof(struct TPREV_FBC_NON_TRAITE);
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
    sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("INSERT IN TPREV_FBC_NON_TRAITE en erreur",0);
}


    /* EXEC SQL COMMIT WORK; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 9;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )254;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("INSERT IN TPREV_FBC_NON_TRAITE en erreur",0);
}


    cout<<"t";
  }
  cout<<endl;
  cout<<DonneHeure()<<" Fin insert "<<nbl<<" lignes dans TPREV_FBC_NON_TRAITE, totRevenu="<<totalRevenu<<" totPas="<<totalPassagers<<endl;
}
