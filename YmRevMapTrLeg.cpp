
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
    "YmRevMapTrLeg.pc"
};


static unsigned int sqlctx = 5461539;


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
   unsigned char  *sqhstv[6];
   unsigned long  sqhstl[6];
            int   sqhsts[6];
            short *sqindv[6];
            int   sqinds[6];
   unsigned long  sqharm[6];
   unsigned long  *sqharc[6];
   unsigned short  sqadto[6];
   unsigned short  sqtdso[6];
} sqlstm = {12,6};

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
"SELECT tranche_no , to_char ( dpt_date_leg , 'dd/mm/yyyy' ) , leg_orig , leg\
_dest , to_char ( dpt_date_tr , 'dd/mm/yyyy' ) , tgv_flag FROM rev_tranches_le\
gs            ";

 static const char *sq0002 = 
"SELECT DISTINCT TRANCHE_NO FROM REV_TRANCHES_LEGS WHERE TRAIN_NO = :b0 AND D\
PT_DATE = TO_DATE ( :b1 , 'dd/mm/yyyy' )            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4130,1,0,0,
5,0,0,1,168,0,9,52,0,2049,0,0,0,1,0,
20,0,0,1,0,0,13,61,0,0,6,0,0,1,0,2,3,0,0,2,97,0,0,2,9,0,0,2,9,0,0,2,97,0,0,2,3,
0,0,
59,0,0,1,0,0,15,85,0,0,0,0,0,1,0,
74,0,0,2,128,0,9,230,0,2049,2,2,0,1,0,1,3,0,0,1,97,0,0,
97,0,0,2,0,0,13,235,0,0,1,0,0,1,0,2,3,0,0,
116,0,0,2,0,0,15,244,0,0,0,0,0,1,0,
};


#pragma ident "%Z% FileName: $RCSfile: YmRevMapTrLeg.pc,v $ Version: $Revision: 1.6 $ Date: $Date: 2009/02/20 13:10:57 $ %Z %"

//## Module: YmRevMapTrLeg
//SFD
//  Name:    YmRevMapTrLeg.cpp
//  Author:  JM. Grugeaux
//  Desc:    traitement de la liste des code tarifs
//EFD


using namespace std;

//standard includes
#include <iterator>
#include </usr/lib/oracle/11.2/client64/precomp/public/sqlca.h>

//application includes
#include <YmRevGlobal.h>
#include <YmRevMapTrLeg.h>

//## Configuration du contexte de base JRO IC SRO DT 23805
extern sql_context ctxRevMain;
/* EXEC SQL CONTEXT USE :ctxRevMain; */ 


YmRevMapTrLeg::YmRevMapTrLeg()
  {
  }

YmRevMapTrLeg::~YmRevMapTrLeg()
  {
    _MapTrLeg.clear();
  }

int YmRevMapTrLeg::init() //initialisation de la map a partir de la base
                                    // 0 = OK, -1 = pas trouve
    {
    int iRet=0;
    int iNb=0;
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

       /* varchar vcLegOrig[6]; */ 
struct { unsigned short len; unsigned char arr[6]; } vcLegOrig;

       /* varchar vcLegDest[6]; */ 
struct { unsigned short len; unsigned char arr[6]; } vcLegDest;
 //MHUE 11/09/06
       char cDateLeg[11];
       char cDateTranche[11];
       int iTrancheNo;
       short iTgvFlag;
    /* EXEC SQL END DECLARE SECTION; */ 

    
    /* EXEC SQL WHENEVER SQLERROR DO sql_error((char *)"liste des tranches legs",1); */ 

    /* EXEC SQL DECLARE cMapTrLeg CURSOR FOR
         SELECT tranche_no, to_char (dpt_date_leg, 'dd/mm/yyyy'), leg_orig, leg_dest, //MHUE 11/09/06
                            to_char (dpt_date_tr, 'dd/mm/yyyy'), tgv_flag FROM rev_tranches_legs; */ 

    /* EXEC SQL OPEN cMapTrLeg ; */ 

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
    if (sqlca.sqlcode < 0) sql_error("liste des tranches legs",1);
}



    /* EXEC SQL WHENEVER NOT FOUND DO break; */ 

    string skey1;
    string skey2;
    TrLeg  aTrLeg;
    char ctrno[10];
    while(1)
       {
       /* EXEC SQL FETCH cMapTrLeg INTO :iTrancheNo, :cDateLeg, :vcLegOrig, :vcLegDest, :cDateTranche, :iTgvFlag; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 12;
       sqlstm.arrsiz = 6;
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
       sqlstm.sqhstv[0] = (unsigned char  *)&iTrancheNo;
       sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[0] = (         int  )0;
       sqlstm.sqindv[0] = (         short *)0;
       sqlstm.sqinds[0] = (         int  )0;
       sqlstm.sqharm[0] = (unsigned long )0;
       sqlstm.sqadto[0] = (unsigned short )0;
       sqlstm.sqtdso[0] = (unsigned short )0;
       sqlstm.sqhstv[1] = (unsigned char  *)cDateLeg;
       sqlstm.sqhstl[1] = (unsigned long )11;
       sqlstm.sqhsts[1] = (         int  )0;
       sqlstm.sqindv[1] = (         short *)0;
       sqlstm.sqinds[1] = (         int  )0;
       sqlstm.sqharm[1] = (unsigned long )0;
       sqlstm.sqadto[1] = (unsigned short )0;
       sqlstm.sqtdso[1] = (unsigned short )0;
       sqlstm.sqhstv[2] = (unsigned char  *)&vcLegOrig;
       sqlstm.sqhstl[2] = (unsigned long )8;
       sqlstm.sqhsts[2] = (         int  )0;
       sqlstm.sqindv[2] = (         short *)0;
       sqlstm.sqinds[2] = (         int  )0;
       sqlstm.sqharm[2] = (unsigned long )0;
       sqlstm.sqadto[2] = (unsigned short )0;
       sqlstm.sqtdso[2] = (unsigned short )0;
       sqlstm.sqhstv[3] = (unsigned char  *)&vcLegDest;
       sqlstm.sqhstl[3] = (unsigned long )8;
       sqlstm.sqhsts[3] = (         int  )0;
       sqlstm.sqindv[3] = (         short *)0;
       sqlstm.sqinds[3] = (         int  )0;
       sqlstm.sqharm[3] = (unsigned long )0;
       sqlstm.sqadto[3] = (unsigned short )0;
       sqlstm.sqtdso[3] = (unsigned short )0;
       sqlstm.sqhstv[4] = (unsigned char  *)cDateTranche;
       sqlstm.sqhstl[4] = (unsigned long )11;
       sqlstm.sqhsts[4] = (         int  )0;
       sqlstm.sqindv[4] = (         short *)0;
       sqlstm.sqinds[4] = (         int  )0;
       sqlstm.sqharm[4] = (unsigned long )0;
       sqlstm.sqadto[4] = (unsigned short )0;
       sqlstm.sqtdso[4] = (unsigned short )0;
       sqlstm.sqhstv[5] = (unsigned char  *)&iTgvFlag;
       sqlstm.sqhstl[5] = (unsigned long )sizeof(short);
       sqlstm.sqhsts[5] = (         int  )0;
       sqlstm.sqindv[5] = (         short *)0;
       sqlstm.sqinds[5] = (         int  )0;
       sqlstm.sqharm[5] = (unsigned long )0;
       sqlstm.sqadto[5] = (unsigned short )0;
       sqlstm.sqtdso[5] = (unsigned short )0;
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
       if (sqlca.sqlcode < 0) sql_error("liste des tranches legs",1);
}

 //MHUE 11/09/06
       cDateLeg[10] = 0;
       cDateTranche[10] = 0;
       iNb++;
       vcLegOrig.arr[vcLegOrig.len] = '\0';
       vcLegDest.arr[vcLegDest.len] = '\0'; //MHUE 11/09/06
       sprintf (ctrno, "%d", iTrancheNo);
       skey1 = ctrno;
       skey1 += (char*)vcLegOrig.arr; 
//MHUE 11/09/06
       skey1 += (char*)"-----"; 
//MHUE 11/09/06
       skey1 += cDateLeg;
       strcpy (aTrLeg.dpt_date_tr, cDateTranche);
       aTrLeg.indic_tgv = iTgvFlag;
       _MapTrLeg[skey1] = aTrLeg;
//MHUE 11/09/06
       skey2 = ctrno;
       skey2 += (char*)"-----"; 
       skey2 += (char*)vcLegDest.arr; 
       skey2 += cDateLeg;
       _MapTrLeg[skey2] = aTrLeg;
//MHUE 11/09/06
       }
    /* EXEC SQL CLOSE cMapTrLeg ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 6;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )59;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("liste des tranches legs",1);
}


    if  (iNb==0) 
        iRet=-1;
    else
        iRet=0;
    return iRet;
    }

//MHUE 11/09/06
TrLeg YmRevMapTrLeg::InMap (int tranche_no, string leg_orig, string leg_dest, char* date_depart) //retourne une structure TrLeg
                        // Si non trouve renvoi un TrLeg Dummy : dpt_date_tr = "01/01/2000", indic_tgv = 2;
   {
    MapTrLegType::iterator iPos1;
    MapTrLegType::iterator iPos2;

    string skey;
    char ctrno[10];
    sprintf (ctrno, "%d", tranche_no);
    skey = ctrno;
    skey += leg_orig;
    skey += (char *)"-----";
    skey += date_depart;
    iPos1 = _MapTrLeg.find (skey);
    skey = ctrno;
    skey += (char *)"-----";
    skey += leg_dest;
    skey += date_depart;
    iPos2 = _MapTrLeg.find (skey);

    //JMG 27/06/07, pb si troncon entierement apres minuit, ano 262360
    if ((iPos1 != _MapTrLeg.end()) && (iPos2 == _MapTrLeg.end()))
    {// on essaie le troncon arrive avec le lendemain de la date de depart indique
      string sDate (date_depart);
      YmDate dtArr (sDate);
      dtArr += 1;
      char date_demain[11];
      dtArr.PrintFrench(date_demain);
      skey = ctrno;
      skey += (char *)"-----";
      skey += leg_dest;
      skey += date_demain;
      iPos2 = _MapTrLeg.find (skey);
      if (iPos2 != _MapTrLeg.end())
      {
        TrLeg trl = (TrLeg)iPos2->second;
        if (strcmp (trl.dpt_date_tr, date_depart))
          iPos2 = _MapTrLeg.end();
      }
    }
    if ((iPos1 == _MapTrLeg.end()) || (iPos2 == _MapTrLeg.end()))
    {
      TrLeg DummyTrLeg;
      strcpy (DummyTrLeg.dpt_date_tr, "01/01/2000");
      DummyTrLeg.indic_tgv = 2;
      return DummyTrLeg;
    }

    return (TrLeg)iPos1->second;
    }
//MHUE 11/09/06


//MHUE 11/09/06
//JRO ICSRO DT 23805 Surcharge de la fonction InMaP : Ajout is Train
TrLeg YmRevMapTrLeg::InMap (int tranche_no, string leg_orig, string leg_dest, char* date_depart, int isTrain) //retourne une structure TrLeg
                        // Si non trouve renvoi un TrLeg Dummy : dpt_date_tr = "01/01/2000", indic_tgv = 2;
   {
   //JRO IC SRO DT 23805 - Si le numéro de tranche est un numéro de train, on renvoie un DummyTrLeg : le segment n'a toujours pas été collecté 
   if (isTrain == 1)
    {
	
      TrLeg DummyTrLeg;
      strcpy (DummyTrLeg.dpt_date_tr, date_depart);
      DummyTrLeg.indic_tgv = 2;
      return DummyTrLeg;
    }
   
    MapTrLegType::iterator iPos1;
    MapTrLegType::iterator iPos2;

    string skey;
    char ctrno[10];
    sprintf (ctrno, "%d", tranche_no);
    skey = ctrno;
    skey += leg_orig;
    skey += (char *)"-----";
    skey += date_depart;
    iPos1 = _MapTrLeg.find (skey);
    skey = ctrno;
    skey += (char *)"-----";
    skey += leg_dest;
    skey += date_depart;
    iPos2 = _MapTrLeg.find (skey);

    //JMG 27/06/07, pb si troncon entierement apres minuit, ano 262360
    if ((iPos1 != _MapTrLeg.end()) && (iPos2 == _MapTrLeg.end()))
    {// on essaie le troncon arrive avec le lendemain de la date de depart indique
      string sDate (date_depart);
      YmDate dtArr (sDate);
      dtArr += 1;
      char date_demain[11];
      dtArr.PrintFrench(date_demain);
      skey = ctrno;
      skey += (char *)"-----";
      skey += leg_dest;
      skey += date_demain;
      iPos2 = _MapTrLeg.find (skey);
      if (iPos2 != _MapTrLeg.end())
      {
        TrLeg trl = (TrLeg)iPos2->second;
        if (strcmp (trl.dpt_date_tr, date_depart))
          iPos2 = _MapTrLeg.end();
      }
    }
    if ((iPos1 == _MapTrLeg.end()) || (iPos2 == _MapTrLeg.end()))
    {
      TrLeg DummyTrLeg;
      strcpy (DummyTrLeg.dpt_date_tr, "01/01/2000");
      DummyTrLeg.indic_tgv = 2;
      return DummyTrLeg;
    }

    return (TrLeg)iPos1->second;
    }
//MHUE 11/09/06
//JRO IC SRO - ANO 87361 - getNoTranche est mtn une méthode de YmRevMapTrLeg (anciennement YmRevMapTypeEquipement)
int YmRevMapTrLeg::getNoTranche(int NoTrain, char dpt_date[11])  
{
	

  /* EXEC SQL BEGIN DECLARE SECTION; */ 

	char cdatedpt_date[11];
	int intNoTrain;
	int notranche = 1000000000;
	int notranchefetch ;

/* EXEC SQL END DECLARE SECTION; */ 


  intNoTrain = NoTrain;
  strncpy(cdatedpt_date, dpt_date, 11);

	//EXEC SQL WHENEVER SQLERROR DO sql_error((char *)"Erreur Recuperation no_tranche",0);
	/* EXEC SQL DECLARE cMapTrancheNo CURSOR FOR
		SELECT  DISTINCT  TRANCHE_NO  FROM REV_TRANCHES_LEGS WHERE TRAIN_NO = :intNoTrain AND DPT_DATE = TO_DATE(:cdatedpt_date,'dd/mm/yyyy'); */ 

 
	/* EXEC SQL OPEN cMapTrancheNo; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )74;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&intNoTrain;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)cdatedpt_date;
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
 if (sqlca.sqlcode < 0) sql_error("liste des tranches legs",1);
}


    /* EXEC SQL WHENEVER NOT FOUND DO break; */ 

	
    while(1)
       {
		   /* EXEC SQL FETCH cMapTrancheNo INTO :notranchefetch; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 6;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )97;
     sqlstm.selerr = (unsigned short)1;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqfoff = (         int )0;
     sqlstm.sqfmod = (unsigned int )2;
     sqlstm.sqhstv[0] = (unsigned char  *)&notranchefetch;
     sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
     sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
     if (sqlca.sqlcode == 1403) break;
     if (sqlca.sqlcode < 0) sql_error("liste des tranches legs",1);
}


		   
		   if (notranchefetch < notranche)
		   {
				notranche = notranchefetch;
		   }
			
		}   
	   
    /* EXEC SQL CLOSE cMapTrancheNo ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 6;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )116;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("liste des tranches legs",1);
}


	
	//Si le train n'est pas en base, on met le no de tranche à 0.
	if (notranche == 1000000000)
	{
		
		notranche = 0;
	}

	return notranche;
}
