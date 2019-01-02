
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
           char  filnam[22];
};
static const struct sqlcxp sqlfpn =
{
    21,
    "YmRevMapTrNonYield.pc"
};


static unsigned int sqlctx = 174785499;


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
   unsigned char  *sqhstv[2];
   unsigned long  sqhstl[2];
            int   sqhsts[2];
            short *sqindv[2];
            int   sqinds[2];
   unsigned long  sqharm[2];
   unsigned long  *sqharc[2];
   unsigned short  sqadto[2];
   unsigned short  sqtdso[2];
} sqlstm = {12,2};

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

 static const char *sq0001 = 
"SELECT tranche_no , TO_CHAR ( dpt_date , 'YYYYMMDD' ) FROM rev_tranches_non_\
yield ORDER BY tranche_no , dpt_date            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4130,1,0,0,
5,0,0,1,124,0,9,63,0,2049,0,0,0,1,0,
20,0,0,1,0,0,13,71,0,0,2,0,0,1,0,2,3,0,0,2,97,0,0,
43,0,0,1,0,0,15,87,0,0,0,0,0,1,0,
};


#pragma ident "%Z% FileName: $RCSfile: YmRevMapTrNonYield.pc,v $ Version: $Revision: 1.4 $ Date: $Date: 2009/02/20 13:10:57 $ %Z %"

//## Module: YmRevMapTrNonYield
//SFD
//  Name:    YmRevMapTrNonYield.pc
//  Author:  M. Hue
//  Desc:    code de la map de la relation classe de service/classe de controle (nest level)
//EFD


using namespace std;

//standard includes
#include <map>
#include <string>
#include <iterator>
#include </usr/lib/oracle/11.2/client64/precomp/public/sqlca.h>

//application includes
#include <YmRevTrNonYield.h>
#include <YmRevMapTrNonYield.h>
#include <YmRevDate.h>
#include <YmRevGlobal.h>


//## Configuration du contexte de base JRO IC SRO DT 23805
extern sql_context ctxRevMain;
/* EXEC SQL CONTEXT USE :ctxRevMain; */ 


YmRevMapTrNonYield::~YmRevMapTrNonYield()
{
    mapTrNonYieldType::iterator iPos = _MapTrNonYield.begin();
    mapTrNonYieldType::iterator iFin = _MapTrNonYield.end();

    YmRevTrNonYield* pRevTrNonYield;
    while (iPos!=iFin)
       {
       pRevTrNonYield =iPos->second;
       delete pRevTrNonYield;
       iPos++;
       }
    _MapTrNonYield.clear();
}

int YmRevMapTrNonYield::init() //lecture des donnees dans les tables THALES
{
    int iRet=0;
    int iNb=0;
    string szDptDate ;
    string Dpt_date;
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

       int trancheNo;
       char DptDate[11];
       /* varchar dptdate[11]; */ 
struct { unsigned short len; unsigned char arr[11]; } dptdate;

    /* EXEC SQL END DECLARE SECTION; */ 


    /* EXEC SQL WHENEVER SQLERROR DO sql_error((char *)"virtual nesting illisible",1); */ 

    /* EXEC SQL DECLARE cMapTrNonYield CURSOR FOR
      SELECT tranche_no, TO_CHAR(dpt_date,'YYYYMMDD')
      FROM rev_tranches_non_yield
      ORDER BY tranche_no, dpt_date; */ 


    /* EXEC SQL OPEN cMapTrNonYield ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 0;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0001;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("virtual nesting illisible",1);
}



    /* EXEC SQL WHENEVER NOT FOUND DO break; */ 

    
    char szKey[20];

    while(1)
       {
       /* EXEC SQL FETCH cMapTrNonYield INTO :trancheNo, :DptDate; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 12;
       sqlstm.arrsiz = 2;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )20;
       sqlstm.selerr = (unsigned short)1;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlstm.sqfoff = (         int )0;
       sqlstm.sqfmod = (unsigned int )2;
       sqlstm.sqhstv[0] = (unsigned char  *)&trancheNo;
       sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[0] = (         int  )0;
       sqlstm.sqindv[0] = (         short *)0;
       sqlstm.sqinds[0] = (         int  )0;
       sqlstm.sqharm[0] = (unsigned long )0;
       sqlstm.sqadto[0] = (unsigned short )0;
       sqlstm.sqtdso[0] = (unsigned short )0;
       sqlstm.sqhstv[1] = (unsigned char  *)DptDate;
       sqlstm.sqhstl[1] = (unsigned long )11;
       sqlstm.sqhsts[1] = (         int  )0;
       sqlstm.sqindv[1] = (         short *)0;
       sqlstm.sqinds[1] = (         int  )0;
       sqlstm.sqharm[1] = (unsigned long )0;
       sqlstm.sqadto[1] = (unsigned short )0;
       sqlstm.sqtdso[1] = (unsigned short )0;
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
       if (sqlca.sqlcode == 1403) break;
       if (sqlca.sqlcode < 0) sql_error("virtual nesting illisible",1);
}

 
       iNb++;
      dptdate.arr[dptdate.len]= '\0';
       
      Dpt_date = string(DptDate,10);
       
      
      
       szDptDate = Dpt_date.c_str();
        YmDate szDptDate ;
       
       YmRevTrNonYield *pRevTrNonYield = new YmRevTrNonYield(trancheNo, szDptDate);
       sprintf(szKey,"%06d%s",trancheNo, dptdate.arr);
       //_MapTrNonYield.insert(mapTrNonYieldType::value_type(szKey, pRevTrNonYield));
       _MapTrNonYield[(string)szKey]= pRevTrNonYield;
       }
    /* EXEC SQL CLOSE cMapTrNonYield ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 2;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )43;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("virtual nesting illisible",1);
}


    if  (iNb==0)
        iRet=-1;
    else
        iRet=0;
    return iRet;

}

short YmRevMapTrNonYield::isInMap(int trancheNo_, YmDate& DptDate_)
   // si la tranche existe pour D, D-1 ou D+1 elle est non yieldie
// retour=0 si pas trouve
{
   mapTrNonYieldType::iterator iPos;
   YmRevTrNonYield* pYmRevTrNonYield;
   

    char szKey[20];
    sprintf(szKey,"%06d%4d%02d%02d",trancheNo_,DptDate_.year(), DptDate_.month(), DptDate_.day());
    iPos = _MapTrNonYield.find ((string)szKey);
    if (iPos != _MapTrNonYield.end()) 
       return 1;
    else
      {
      DptDate_-=1;
      sprintf(szKey,"%06d%4d%02d%02d",trancheNo_,DptDate_.year(), DptDate_.month(), DptDate_.day());
      iPos = _MapTrNonYield.find ((string)szKey);
      if (iPos != _MapTrNonYield.end()) 
         return 1;
      else
        {
        DptDate_+=2;
        sprintf(szKey,"%06d%4d%02d%02d",trancheNo_,DptDate_.year(), DptDate_.month(), DptDate_.day());
        iPos = _MapTrNonYield.find ((string)szKey);
        if (iPos != _MapTrNonYield.end()) 
           return 1;
        }
      }

return 0;
}

