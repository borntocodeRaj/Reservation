
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
    "YmRevMapTarifs.pc"
};


static unsigned int sqlctx = 10921651;


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
   unsigned char  *sqhstv[8];
   unsigned long  sqhstl[8];
            int   sqhsts[8];
            short *sqindv[8];
            int   sqinds[8];
   unsigned long  sqharm[8];
   unsigned long  *sqharc[8];
   unsigned short  sqadto[8];
   unsigned short  sqtdso[8];
} sqlstm = {12,8};

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
"SELECT code_tarif , class_of_service , to_char ( start_date , 'YYYYMMDD' ) ,\
 to_char ( end_date , 'YYYYMMDD' ) , coefficient , fixe , fixe_km , num_Palier\
 FROM rev_tarifs_view ORDER BY code_tarif asc , class_of_service desc , num_pa\
lier desc            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4130,1,0,0,
5,0,0,1,253,0,9,75,0,2049,0,0,0,1,0,
20,0,0,1,0,0,13,84,0,0,8,0,0,1,0,2,9,0,0,2,9,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,
0,0,2,3,0,0,2,3,0,0,
67,0,0,1,0,0,15,108,0,0,0,0,0,1,0,
};


#pragma ident "%Z% FileName: $RCSfile: YmRevMapTarifs.pc,v $ Version: $Revision: 1.6 $ Date: $Date: 2006/04/27 09:08:46 $ %Z %"

//## Module: YmRevMapTarifs
//SFD
//  Name:    YmRevMapTarifs.cpp
//  Author:  JM. Grugeaux
//  Desc:    traitement de la liste des code tarifs
//EFD


using namespace std;

//standard includes
#include <iterator>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include </usr/lib/oracle/11.2/client64/precomp/public/sqlca.h>

//application includes
#include <YmRevGlobal.h>
#include <YmRevMapTarifs.h>

//## Configuration du contexte de base JRO IC SRO DT 23805
extern sql_context ctxRevMain;
/* EXEC SQL CONTEXT USE :ctxRevMain; */ 



YmRevMapTarifs::YmRevMapTarifs()
  {
    nbFindMapTarif = 0;
  }
YmRevMapTarifs::~YmRevMapTarifs()
  {
    MapTarifsType::iterator iPos = _MapTarifs.begin();
    MapTarifsType::iterator iFin = _MapTarifs.end();

    YmRevTarifs* pRevTarif;
    while (iPos!=iFin)
       {
       pRevTarif =iPos->second;
       delete pRevTarif;
       iPos++;
       }
    _MapTarifs.clear();
  }

//DM7978 - HRI - 06/03/2015 - Ajout du numero de palier
int YmRevMapTarifs::init() //initialisation de la map a partir de la base
                                    // 0 = OK, -1 = pas trouve
    {
    nbFindMapTarif = 0;
    int iRet=0;
    int iNb=0;
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

       /* varchar vcCodeTarif[5]; */ 
struct { unsigned short len; unsigned char arr[5]; } vcCodeTarif;

       /* varchar vcClassOfService[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } vcClassOfService;

       char start_date[9];
       char end_date[9];
       int iCoefficient;
       int iFixe;
       int iFixeKm;
       short inull_coeff = -1;
       short inull_fixe = -1;
       short inull_fixekm = -1;
	   int numPalier;
    /* EXEC SQL END DECLARE SECTION; */ 

   
    /* EXEC SQL WHENEVER SQLERROR DO sql_error((char *)"liste des tarifs illisible",1); */ 

    /* EXEC SQL DECLARE cMapTarif CURSOR FOR
         SELECT code_tarif, class_of_service, to_char (start_date, 'YYYYMMDD'), to_char (end_date, 'YYYYMMDD'),
                coefficient, fixe, fixe_km, num_Palier
         FROM rev_tarifs_view ORDER BY code_tarif asc, class_of_service desc, num_palier desc; */ 

    /* EXEC SQL OPEN cMapTarif ; */ 

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
    if (sqlca.sqlcode < 0) sql_error("liste des tarifs illisible",1);
}



    /* EXEC SQL WHENEVER NOT FOUND DO break; */ 

    string skey1;
    string skey2;
    string sStartDate;
    string sEndDate;
    while(1)
       {
       /* EXEC SQL FETCH cMapTarif INTO :vcCodeTarif, :vcClassOfService, :start_date, :end_date,
                                     :iCoefficient:inull_coeff, :iFixe:inull_fixe, :iFixeKm:inull_fixekm,:numPalier; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 12;
       sqlstm.arrsiz = 8;
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
       sqlstm.sqhstv[0] = (unsigned char  *)&vcCodeTarif;
       sqlstm.sqhstl[0] = (unsigned long )7;
       sqlstm.sqhsts[0] = (         int  )0;
       sqlstm.sqindv[0] = (         short *)0;
       sqlstm.sqinds[0] = (         int  )0;
       sqlstm.sqharm[0] = (unsigned long )0;
       sqlstm.sqadto[0] = (unsigned short )0;
       sqlstm.sqtdso[0] = (unsigned short )0;
       sqlstm.sqhstv[1] = (unsigned char  *)&vcClassOfService;
       sqlstm.sqhstl[1] = (unsigned long )5;
       sqlstm.sqhsts[1] = (         int  )0;
       sqlstm.sqindv[1] = (         short *)0;
       sqlstm.sqinds[1] = (         int  )0;
       sqlstm.sqharm[1] = (unsigned long )0;
       sqlstm.sqadto[1] = (unsigned short )0;
       sqlstm.sqtdso[1] = (unsigned short )0;
       sqlstm.sqhstv[2] = (unsigned char  *)start_date;
       sqlstm.sqhstl[2] = (unsigned long )9;
       sqlstm.sqhsts[2] = (         int  )0;
       sqlstm.sqindv[2] = (         short *)0;
       sqlstm.sqinds[2] = (         int  )0;
       sqlstm.sqharm[2] = (unsigned long )0;
       sqlstm.sqadto[2] = (unsigned short )0;
       sqlstm.sqtdso[2] = (unsigned short )0;
       sqlstm.sqhstv[3] = (unsigned char  *)end_date;
       sqlstm.sqhstl[3] = (unsigned long )9;
       sqlstm.sqhsts[3] = (         int  )0;
       sqlstm.sqindv[3] = (         short *)0;
       sqlstm.sqinds[3] = (         int  )0;
       sqlstm.sqharm[3] = (unsigned long )0;
       sqlstm.sqadto[3] = (unsigned short )0;
       sqlstm.sqtdso[3] = (unsigned short )0;
       sqlstm.sqhstv[4] = (unsigned char  *)&iCoefficient;
       sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[4] = (         int  )0;
       sqlstm.sqindv[4] = (         short *)&inull_coeff;
       sqlstm.sqinds[4] = (         int  )0;
       sqlstm.sqharm[4] = (unsigned long )0;
       sqlstm.sqadto[4] = (unsigned short )0;
       sqlstm.sqtdso[4] = (unsigned short )0;
       sqlstm.sqhstv[5] = (unsigned char  *)&iFixe;
       sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[5] = (         int  )0;
       sqlstm.sqindv[5] = (         short *)&inull_fixe;
       sqlstm.sqinds[5] = (         int  )0;
       sqlstm.sqharm[5] = (unsigned long )0;
       sqlstm.sqadto[5] = (unsigned short )0;
       sqlstm.sqtdso[5] = (unsigned short )0;
       sqlstm.sqhstv[6] = (unsigned char  *)&iFixeKm;
       sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[6] = (         int  )0;
       sqlstm.sqindv[6] = (         short *)&inull_fixekm;
       sqlstm.sqinds[6] = (         int  )0;
       sqlstm.sqharm[6] = (unsigned long )0;
       sqlstm.sqadto[6] = (unsigned short )0;
       sqlstm.sqtdso[6] = (unsigned short )0;
       sqlstm.sqhstv[7] = (unsigned char  *)&numPalier;
       sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[7] = (         int  )0;
       sqlstm.sqindv[7] = (         short *)0;
       sqlstm.sqinds[7] = (         int  )0;
       sqlstm.sqharm[7] = (unsigned long )0;
       sqlstm.sqadto[7] = (unsigned short )0;
       sqlstm.sqtdso[7] = (unsigned short )0;
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
       if (sqlca.sqlcode < 0) sql_error("liste des tarifs illisible",1);
}


       if (inull_coeff == -1)
         iCoefficient = 0;
       if (inull_fixe == -1)
         iFixe = 0;
       if (inull_fixekm == -1)
         iFixeKm = 0;
       iNb++;
       vcCodeTarif.arr[vcCodeTarif.len] = '\0';
       vcClassOfService.arr[vcClassOfService.len] = '\0';
       skey1 = (char*)vcCodeTarif.arr; 
       skey2 = (char*)vcClassOfService.arr;
       sStartDate = start_date;
       sEndDate = end_date;
       YmRevTarifs *pRevTarif = new YmRevTarifs(skey1, skey2, numPalier, YmDate(sStartDate), YmDate(sEndDate),
                                                iCoefficient, iFixe, iFixeKm);
       _MapTarifs.insert(MapTarifsType::value_type(skey1, pRevTarif));
	   	char dateW[25];
	cout << "YmRevMapTarifs::init()   Type = " << skey1 << " CS = " << skey2 << " sNumPalier = " << numPalier << " StartDate = " << sStartDate << " EndDate = " << sEndDate << endl;

     }
	cout << "YmRevMapTarifs::init()   size map = " <<_MapTarifs.size() << endl;

    /* EXEC SQL CLOSE cMapTarif ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 8;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )67;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("liste des tarifs illisible",1);
}


    if  (iNb==0) 
        iRet=-1;
    else
        iRet=0;
    return iRet;
    }

	//DM7978 - HRI - 06/03/2015 - Ajout du numero de palier
YmRevTarifs* YmRevMapTarifs::isInMap(string sCodeTarif, string sClassOfService, int sNumPalier, YmDate DateDepart)
 //retourne pointeur si OK, NULL sinon
 {
    MapTarifsType::iterator iPos;
    MapTarifsType::iterator iPos0;
    YmRevTarifs* pYmRevTarif = NULL;
    YmRevTarifs* pYmRevTarifSubcOk = NULL;
    YmRevTarifs* pYmRevTarifCmptOk = NULL;
    YmRevTarifs* pYmRevTarifAllOk = NULL;
    string sCmptOk = sClassOfService;
    string sSubcOk = sClassOfService;
    sCmptOk[1] = '0';
    sSubcOk[0] = '0';

	char dateW[25];
	//cout << "YmRevMapTarifs::isInMap   Recherche CS = " << sClassOfService << " sCodeTarif = " << sCodeTarif << " sNumPalier = " << sNumPalier << " DptDate = " << DateDepart.PrintResaven(dateW) << " sSubcOk = " << sSubcOk <<  " sCmptOk = " << sCmptOk <<endl;
	
    string skey = sCodeTarif;
    iPos0 = iPos = _MapTarifs.find (skey);
    while ((iPos != _MapTarifs.end()) && (iPos->first == iPos0->first))
    {
      pYmRevTarif = iPos->second;
      if ((pYmRevTarif->get_startDate() <= DateDepart) && (pYmRevTarif->get_endDate() >= DateDepart))
      {
        if (pYmRevTarif->get_ClassOfService() == sClassOfService && pYmRevTarif->get_numPalier() == sNumPalier)
        {
           nbFindMapTarif++;
		   //cout << "YmRevMapTarifs::isInMap ====> OK TROUVE 0" << endl;
           return pYmRevTarif;
        }
        else if (pYmRevTarif->get_ClassOfService() == sClassOfService && pYmRevTarif->get_numPalier() < 0)
        {
           nbFindMapTarif++;
		   //cout << "YmRevMapTarifs::isInMap ====> OK TROUVE 0 BIS" << endl;
           return pYmRevTarif;
        }		
        else if (pYmRevTarif->get_ClassOfService() == sSubcOk && pYmRevTarif->get_numPalier() < 0)
           pYmRevTarifSubcOk = pYmRevTarif;
        else if (pYmRevTarif->get_ClassOfService() == sCmptOk && pYmRevTarif->get_numPalier() < 0)
           pYmRevTarifCmptOk = pYmRevTarif;
        else if (pYmRevTarif->get_ClassOfService() == "00" && pYmRevTarif->get_numPalier() < 0)
           pYmRevTarifAllOk = pYmRevTarif;
     
      }
      iPos++;
    }
    if (pYmRevTarifSubcOk)
    {
      nbFindMapTarif++;
	  //cout << "YmRevMapTarifs::isInMap ====> OK TROUVE 1" << endl;
      return pYmRevTarifSubcOk;
    }
    if (pYmRevTarifCmptOk)
    {
      nbFindMapTarif++;
	  //cout << "YmRevMapTarifs::isInMap ====> OK TROUVE 2" << endl;
      return pYmRevTarifCmptOk;
    }
    if (pYmRevTarifAllOk)
    {
      nbFindMapTarif++;
 	  //cout << "YmRevMapTarifs::isInMap ====> OK TROUVE 3" << endl;

      return pYmRevTarifAllOk;
    }
    return NULL;
}

