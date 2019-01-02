
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
           char  filnam[18];
};
static const struct sqlcxp sqlfpn =
{
    17,
    "YmRevInfoBatch.pc"
};


static unsigned int sqlctx = 10919627;


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

 static const char *sq0003 = 
"SELECT key_info , assoc_data FROM rev_info_batch ORDER BY key_info          \
  ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4130,1,0,0,
5,0,0,1,105,0,5,59,0,0,2,2,0,1,0,1,9,0,0,1,9,0,0,
28,0,0,2,0,0,29,61,0,0,0,0,0,1,0,
43,0,0,3,78,0,9,80,0,2049,0,0,0,1,0,
58,0,0,3,0,0,13,87,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
81,0,0,3,0,0,15,97,0,0,0,0,0,1,0,
};


#pragma ident "%Z% FileName: $RCSfile: YmRevInfoBatch.pc,v $ Version: $Revision: 1.2 $ Date: $Date: 2006/04/03 16:04:29 $ %Z %"

//## Module: YmRevInfoBatch
//SFD
//  Name:    YmRevInfoBatch.cpp
//  Author:  JM. Grugeaux
//  Desc:    Lecture et mise a jour de la table rev_info_batch
//EFD


using namespace std;

//standard includes
#include <iterator>
#include </usr/lib/oracle/11.2/client64/precomp/public/sqlca.h>

//application includes
#include <YmRevGlobal.h>
#include <YmRevInfoBatch.h>


//## Global
extern sql_context ctxRevMain;

/* EXEC SQL CONTEXT USE :ctxRevMain; */ 


YmRevInfoBatch::YmRevInfoBatch()
  {
  }
YmRevInfoBatch::~YmRevInfoBatch()
  {
  }


string YmRevInfoBatch::getAssocData(string key_info) // renvoi la valeur associe a la clef key_info. Vide si non trouve
{
    InfoBatchType::iterator iPos;
    string sRtn = "" ;

    iPos = _InfoBatch.find (key_info);
    if (iPos != _InfoBatch.end())
      sRtn = iPos->second;
    return sRtn;
}


// met a jour la Map en memoire, et aussi la table rev_info_batch
void YmRevInfoBatch::setAssocData(string key_info, string assoc_data)
{
    _InfoBatch[key_info] = assoc_data;
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

       /* varchar vcKeyInfo[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } vcKeyInfo;

       /* varchar vcAssocData[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } vcAssocData;

    /* EXEC SQL END DECLARE SECTION; */ 

    strcpy ((char*) vcKeyInfo.arr, key_info.c_str());
    vcKeyInfo.len = key_info.size();
    strcpy ((char*) vcAssocData.arr, assoc_data.c_str());
    vcAssocData.len = assoc_data.size();
    /* EXEC SQL UPDATE REV_INFO_BATCH set ASSOC_DATA = :vcAssocData, posted_time = sysdate, user_id = user
             WHERE KEY_INFO = :vcKeyInfo; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 2;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "update REV_INFO_BATCH set ASSOC_DATA = :b0 , posted_time \
= sysdate , user_id = user WHERE KEY_INFO = :b1 ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&vcAssocData;
    sqlstm.sqhstl[0] = (unsigned long )33;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&vcKeyInfo;
    sqlstm.sqhstl[1] = (unsigned long )33;
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
}


    /* EXEC SQL COMMIT; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 2;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )28;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
}


}


int YmRevInfoBatch::init() //initialisation de la map a partir de la base
                                    // 0 = OK, -1 = pas trouve
{
    int iRet=0;
    int iNb=0;
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

       /* varchar vcKeyInfo[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } vcKeyInfo;

       /* varchar vcAssocData[31]; */ 
struct { unsigned short len; unsigned char arr[31]; } vcAssocData;

       short inull_AssocData = -1;
    /* EXEC SQL END DECLARE SECTION; */ 

    
    /* EXEC SQL WHENEVER SQLERROR DO sql_error((char *)"rev_info_batch illisible",1); */ 

	
    /* EXEC SQL DECLARE cInfoBatch CURSOR FOR
         SELECT key_info, assoc_data FROM rev_info_batch ORDER BY key_info; */ 

    /* EXEC SQL OPEN cInfoBatch ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 2;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0003;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )43;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("rev_info_batch illisible",1);
}



    /* EXEC SQL WHENEVER NOT FOUND DO break; */ 

    string skeyInfo;
    string sAssocData;
    while(1)
       {
       /* EXEC SQL FETCH cInfoBatch INTO :vcKeyInfo, :vcAssocData:inull_AssocData; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 12;
       sqlstm.arrsiz = 2;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )58;
       sqlstm.selerr = (unsigned short)1;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlstm.sqfoff = (         int )0;
       sqlstm.sqfmod = (unsigned int )2;
       sqlstm.sqhstv[0] = (unsigned char  *)&vcKeyInfo;
       sqlstm.sqhstl[0] = (unsigned long )33;
       sqlstm.sqhsts[0] = (         int  )0;
       sqlstm.sqindv[0] = (         short *)0;
       sqlstm.sqinds[0] = (         int  )0;
       sqlstm.sqharm[0] = (unsigned long )0;
       sqlstm.sqadto[0] = (unsigned short )0;
       sqlstm.sqtdso[0] = (unsigned short )0;
       sqlstm.sqhstv[1] = (unsigned char  *)&vcAssocData;
       sqlstm.sqhstl[1] = (unsigned long )33;
       sqlstm.sqhsts[1] = (         int  )0;
       sqlstm.sqindv[1] = (         short *)&inull_AssocData;
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
       if (sqlca.sqlcode < 0) sql_error("rev_info_batch illisible",1);
}


       if (inull_AssocData == -1)
         sAssocData = "";
       iNb++;
       vcKeyInfo.arr[vcKeyInfo.len] = '\0';
       vcAssocData.arr[vcAssocData.len] = '\0';
       skeyInfo = (char*)vcKeyInfo.arr; 
       sAssocData = (char*)vcAssocData.arr;
       _InfoBatch[skeyInfo] = sAssocData;
       }
    /* EXEC SQL CLOSE cInfoBatch ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 2;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )81;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("rev_info_batch illisible",1);
}


    if  (iNb==0) 
        iRet=-1;
    else
        iRet=0;
    return iRet;
}

