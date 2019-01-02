
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
    "YmRevMapDeviceType.pc"
};


static unsigned int sqlctx = 174694499;


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
"SELECT device_type , groupe_device FROM rev_device_types ORDER BY device_typ\
e            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4130,1,0,0,
5,0,0,1,89,0,9,55,0,2049,0,0,0,1,0,
20,0,0,1,0,0,13,62,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
43,0,0,1,0,0,15,72,0,0,0,0,0,1,0,
};


#pragma ident "%Z% FileName: $RCSfile: YmRevMapDeviceType.pc,v $ Version: $Revision: 1.5 $ Date: $Date: 2006/11/24 13:50:52 $ %Z %"

//## Module: YmRevMapDeviceType
//SFD
//  Name:    YmRevMapDeviceType.cpp
//  Author:  JM. Grugeaux
//  Desc:    traitement de la liste des device type
//EFD


using namespace std;

//standard includes
#include <iterator>
#include <string.h>
//application includes
#include <YmRevGlobal.h>
#include <YmRevMapDeviceType.h>
#include </usr/lib/oracle/11.2/client64/precomp/public/sqlca.h>
//## Configuration du contexte de base JRO IC SRO DT 23805
extern sql_context ctxRevMain;
/* EXEC SQL CONTEXT USE :ctxRevMain; */ 


YmRevMapDeviceType::YmRevMapDeviceType()
  {
  }
YmRevMapDeviceType::~YmRevMapDeviceType()
  {
    MapDeviceTypeType::iterator iPos = _MapDeviceType.begin();
    MapDeviceTypeType::iterator iFin = _MapDeviceType.end();

    YmRevDeviceType* pRevDeviceType;
    while (iPos!=iFin)
       {
       pRevDeviceType =iPos->second;
       delete pRevDeviceType;
       iPos++;
       }
    _MapDeviceType.clear();
  }

int YmRevMapDeviceType::init() //initialisation de la map a partir de la base
                                    // 0 = OK, -1 = pas trouve
    {
    int iRet=0;
    int iNb=0;
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

       /* varchar vcDeviceType[4]; */ 
struct { unsigned short len; unsigned char arr[4]; } vcDeviceType;

       /* varchar vcGroupeDevice[11]; */ 
struct { unsigned short len; unsigned char arr[11]; } vcGroupeDevice;

    /* EXEC SQL END DECLARE SECTION; */ 

    
    /* EXEC SQL WHENEVER SQLERROR DO sql_error((char *)"liste des device Type illisible",1); */ 

    /* EXEC SQL DECLARE cMapDeviceType CURSOR FOR
         SELECT device_type, groupe_device FROM rev_device_types ORDER BY device_type; */ 

    /* EXEC SQL OPEN cMapDeviceType ; */ 

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
    if (sqlca.sqlcode < 0) sql_error("liste des device Type illisible",1);
}



    /* EXEC SQL WHENEVER NOT FOUND DO break; */ 

    string skey;
    string sdevice;
    while(1)
       {
       /* EXEC SQL FETCH cMapDeviceType INTO :vcDeviceType, :vcGroupeDevice; */ 

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
       sqlstm.sqhstv[0] = (unsigned char  *)&vcDeviceType;
       sqlstm.sqhstl[0] = (unsigned long )6;
       sqlstm.sqhsts[0] = (         int  )0;
       sqlstm.sqindv[0] = (         short *)0;
       sqlstm.sqinds[0] = (         int  )0;
       sqlstm.sqharm[0] = (unsigned long )0;
       sqlstm.sqadto[0] = (unsigned short )0;
       sqlstm.sqtdso[0] = (unsigned short )0;
       sqlstm.sqhstv[1] = (unsigned char  *)&vcGroupeDevice;
       sqlstm.sqhstl[1] = (unsigned long )13;
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
       if (sqlca.sqlcode < 0) sql_error("liste des device Type illisible",1);
}


       iNb++;
       vcDeviceType.arr[vcDeviceType.len] = '\0';
       vcGroupeDevice.arr[vcGroupeDevice.len] = '\0';
       skey = (char*)vcDeviceType.arr; 
       sdevice = (char*)vcGroupeDevice.arr; 
       YmRevDeviceType *pRevDeviceType = new YmRevDeviceType(skey, sdevice);
       //_MapDeviceType.insert(MapDeviceTypeType::value_type(skey, pRevTarif));
       _MapDeviceType[skey] = pRevDeviceType;
       }
    /* EXEC SQL CLOSE cMapDeviceType ; */ 

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
    if (sqlca.sqlcode < 0) sql_error("liste des device Type illisible",1);
}


    if  (iNb==0) 
        iRet=-1;
    else
        iRet=0;
    return iRet;
    }

bool YmRevMapDeviceType::isInMap(string sDeviceType) //retourne TRUE si trouve, FALSE sinon
{
  if (g_TestCanaux)
    return (findInMap (sDeviceType) != NULL);

  return true;
}

YmRevDeviceType* YmRevMapDeviceType::findInMap(string sDeviceType) //retourne pointeur si OK, NULL sinon
    {
    MapDeviceTypeType::iterator iPos;
    YmRevDeviceType* pYmRevDeviceType;
    // suppression des blancs inutiles de la variable d'entree
    string sDevTyp;
    int j=0;
    for (int i=0;i <sDeviceType.size();i++) {
        if (sDeviceType.substr(i,1) != string(" ")) {
           sDevTyp=sDevTyp.substr(0,j)+sDeviceType.substr(i,1);
           j++;
        }       
    } 
    iPos = _MapDeviceType.find (sDevTyp);
    if (iPos == _MapDeviceType.end())
      return NULL;

    pYmRevDeviceType = iPos->second;
    return pYmRevDeviceType;
    }

