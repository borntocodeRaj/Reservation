
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
           char  filnam[16];
};
static const struct sqlcxp sqlfpn =
{
    15,
    "YmRevMapTpOD.pc"
};


static unsigned int sqlctx = 2730667;


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
   unsigned char  *sqhstv[15];
   unsigned long  sqhstl[15];
            int   sqhsts[15];
            short *sqindv[15];
            int   sqinds[15];
   unsigned long  sqharm[15];
   unsigned long  *sqharc[15];
   unsigned short  sqadto[15];
   unsigned short  sqtdso[15];
} sqlstm = {12,15};

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

 static const char *sq0007 = 
"SELECT MIN ( b . TRANCHE_NO ) , b . TRAIN_NO , b . DPT_DATE FROM TPREV_NON_T\
RAITE a , REV_TRANCHES_LEGS b WHERE a . IS_TRAIN = 1 AND b . TRAIN_NO = a . TR\
ANCHE_NO AND a . DPT_DATE = b . DPT_DATE GROUP BY b . TRANCHE_NO , b . TRAIN_N\
O , b . DPT_DATE            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4130,1,0,0,
5,0,0,1,293,0,3,238,0,0,15,15,0,1,0,1,3,0,0,1,97,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,
0,
80,0,0,2,0,0,29,242,0,0,0,0,0,1,0,
95,0,0,3,293,0,3,307,0,0,15,15,0,1,0,1,3,0,0,1,97,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,
0,0,
170,0,0,4,0,0,29,311,0,0,0,0,0,1,0,
185,0,0,5,293,0,3,321,0,0,15,15,0,1,0,1,3,0,0,1,97,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,
0,0,
260,0,0,6,0,0,29,325,0,0,0,0,0,1,0,
275,0,0,7,260,0,9,348,0,2049,0,0,0,1,0,
290,0,0,7,0,0,13,354,0,0,3,0,0,1,0,2,3,0,0,2,3,0,0,2,9,0,0,
317,0,0,8,84,0,5,369,0,0,3,3,0,1,0,1,3,0,0,1,3,0,0,1,9,0,0,
344,0,0,7,0,0,15,373,0,0,0,0,0,1,0,
359,0,0,9,282,0,3,429,0,0,14,14,0,1,0,1,3,0,0,1,97,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
430,0,0,10,0,0,29,433,0,0,0,0,0,1,0,
445,0,0,11,282,0,3,444,0,0,14,14,0,1,0,1,3,0,0,1,97,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
516,0,0,12,0,0,29,448,0,0,0,0,0,1,0,
};


#pragma ident "%Z% FileName: $RCSfile: YmRevMapTpOD.pc,v $ Version: $Revision: 1.8 $ Date: $Date: 2009/02/20 13:10:57 $ %Z %"

//## Module: YmRevMapTpOD
//SFD
//  Name:    YmRevMapTpOD.cpp
//  Author:  JM. Grugeaux
//  Desc:    traitement de la liste des code tarifs
//EFD


using namespace std;

//standard includes
#include <iterator>
#include </usr/lib/oracle/11.2/client64/precomp/public/sqlca.h>

//application includes
#include <YmRevGlobal.h>
#include <YmRevMapTpOD.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>

//## Configuration du contexte de base JRO IC SRO DT 23805
extern sql_context ctxRevMain;
/* EXEC SQL CONTEXT USE :ctxRevMain; */ 


/* EXEC SQL BEGIN DECLARE SECTION; */ 


#define MAX_NB_TPREVOD 1000

int nbInBulk;

struct TPREV_OD {
		
        int tranche_no;
        char dpt_date[11];
        /* varchar orig[6]; */ 
struct { unsigned short len; unsigned char arr[6]; } orig;

        /* varchar dest[6]; */ 
struct { unsigned short len; unsigned char arr[6]; } dest;

        /* varchar class_of_service[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } class_of_service;

		//DM7978 - JLA - Ajout du num_palier
		int num_palier;
        int nest_level;
        char date_od[11];
        int nb_voyageurs;
        int market_id;
        int revenu;
        int type_flag;
        char date_fichier[11];
        int heure_fichier;
//DM5882.1 :sous-contingentement ( scx ) pour nestlevel =0
        int scx;
//
      } pTpRevODTable[MAX_NB_TPREVOD];

struct TPREV_NON_TRAITE {
		
        int tranche_no;
        char dpt_date[11];
        /* varchar orig[6]; */ 
struct { unsigned short len; unsigned char arr[6]; } orig;

        /* varchar dest[6]; */ 
struct { unsigned short len; unsigned char arr[6]; } dest;

        /* varchar class_of_service[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } class_of_service;

		//DM7978 - JLA - Ajout du num_palier
		int num_palier;
        int nest_level;
        char date_od[11];
        int nb_voyageurs;
        int revenu;
        char date_fichier[11];
        int heure_fichier;
//DM5882.1 :sous-contingentement ( scx ) pour nestlevel =0
        int scx;
		// JRO -IC SRO - DT 23805 - Ajout flag is train
       int isTrain; 
      } pTpRevNTTable[MAX_NB_TPREVOD];

/* EXEC SQL END DECLARE SECTION; */ 




YmRevMapTpOD::YmRevMapTpOD()
{
}

YmRevMapTpOD::~YmRevMapTpOD()
{
   Clear();
}

void YmRevMapTpOD::Clear()
{
    MapTpODType::iterator iPos = _MapTpOD.begin();
    MapTpODType::iterator iFin = _MapTpOD.end();

    YmRevTpOD* pTpOD;
    while (iPos!=iFin)
       {
       pTpOD =iPos->second;
       delete pTpOD;
       iPos++;
       }
    _MapTpOD.clear();
}
// DM 7978 - JLA - Ajout du Pipe pour différencier chaque chiffre qui peuvent de 3 à 1 caractères 
void YmRevMapTpOD::Add (YmRevTpOD* pTpOD)
{
  string skey;
  char cTrNo[10];

  sprintf (cTrNo, "%d", pTpOD->getTrancheNo());
   skey = cTrNo;



  skey += pTpOD->getDateOd();
  skey += pTpOD->getOrig();
  skey += pTpOD->getDest();
  skey += pTpOD->getClassOfService();
  //DM7978 - JLA - Ajout du num_palier
  sprintf (cTrNo, "%d",  pTpOD->getNumPalier());
  skey += cTrNo;
  skey+="|";
  sprintf (cTrNo, "%d", pTpOD->getNestLevel());
  skey += cTrNo;
  skey+="|";
  //DM7978 - JLA - FIN
//DM5882.1 :sous-contingentement ( scx ) pour nestlevel =0
  sprintf (cTrNo, "%d", pTpOD->getScx());
  skey += cTrNo;
// JRO -IC SRO - DT 23805 - Ajout flag is train
	sprintf (cTrNo, "%d", pTpOD->getIsTrain());
    skey += cTrNo;

  _MapTpOD[skey] = pTpOD;
}
//DM7978 - JLA - Ajout du num_palier - Ajout du Pipe pour différencier chaque chiffre qui peuvent de 3 à 1 caractères 

YmRevTpOD* YmRevMapTpOD::isInMap(int tranche_no, char* date_od, string orig, string dest, string class_of_service,int num_palier,
                                 int nest_level,int scx , int isTrain) //retourne un pointeur sur YmRevTpOD si deja present
    {
    MapTpODType::iterator iPos;
    YmRevTpOD* pTpOD;

	
    char cTrNo[10];

	  sprintf (cTrNo, "%d", tranche_no);
	string skey = cTrNo;
  
 

    skey += date_od;
    skey += orig;
    skey += dest;
    skey += class_of_service;
	//DM7978 - JLA - Ajout du num_palier
	sprintf (cTrNo, "%d", num_palier);
	skey += cTrNo;
	skey+="|";
    sprintf (cTrNo, "%d", nest_level);
    skey += cTrNo;
	skey+="|";
	//DM7978 - JLA - FIN
//DM5882.1 :sous-contingentement ( scx ) pour nestlevel =0
    sprintf (cTrNo, "%d", scx);
    skey += cTrNo;
	//DM7978 - JLA - Ajout du num_palier
// JRO -IC SRO - DT 23805 - Ajout flag is train
	sprintf (cTrNo, "%d", isTrain);
    skey += cTrNo;
    iPos = _MapTpOD.find (skey);
    if (iPos == _MapTpOD.end())
      return NULL;

    pTpOD = iPos->second;
    return pTpOD;
    }


// code Obsolete, cette fonction n'est jamais utilisée JRO
void YmRevMapTpOD::InsertAndPurge()
{
  int totalRevenu = 0;
  int totalPassagers = 0;
  cout<<DonneHeure()<<" Ecriture de "<<_MapTpOD.size()<<" lignes dans TPREV_OD"<<endl;
  /* EXEC SQL WHENEVER SQLERROR DO sql_error  ("INSERT IN TPREV_OD en erreur", 0); */ 

  while (_MapTpOD.size())
  {
    memset (pTpRevODTable, 0, sizeof (pTpRevODTable));
    YmRevTpOD* pTpOD;
    nbInBulk = MAX_NB_TPREVOD;
    if (_MapTpOD.size() < nbInBulk)
      nbInBulk = _MapTpOD.size();
  
    MapTpODType::iterator iPos = _MapTpOD.begin();
    int i = 0;
    while (i < nbInBulk)
    {
      pTpOD = iPos->second;

	
      pTpRevODTable[i].tranche_no = pTpOD->getTrancheNo();
      strcpy (pTpRevODTable[i].dpt_date, pTpOD->getDptDate());
      strcpy ((char*)pTpRevODTable[i].orig.arr, pTpOD->getOrig().c_str());
      pTpRevODTable[i].orig.len = pTpOD->getOrig().size();
      strcpy ((char*)pTpRevODTable[i].dest.arr, pTpOD->getDest().c_str());
      pTpRevODTable[i].dest.len = pTpOD->getDest().size();
      strcpy ((char*)pTpRevODTable[i].class_of_service.arr, pTpOD->getClassOfService().c_str());
      pTpRevODTable[i].class_of_service.len = pTpOD->getClassOfService().size();
	  //DM7978 - JLA - Ajout du num_palier
	  pTpRevODTable[i].num_palier = pTpOD->getNumPalier();
      pTpRevODTable[i].nest_level = pTpOD->getNestLevel();
//DM5882.1 :sous-contingentement ( scx ) pour nestlevel =0
      pTpRevODTable[i].scx = pTpOD->getScx();
//

      strcpy (pTpRevODTable[i].date_od, pTpOD->getDateOd());
      pTpRevODTable[i].nb_voyageurs = pTpOD->getNbVoyageurs();
      pTpRevODTable[i].market_id = 0;
      pTpRevODTable[i].revenu = pTpOD->getRevenu();
      pTpRevODTable[i].type_flag = pTpOD->getTypeFlag();
      strcpy (pTpRevODTable[i].date_fichier, pTpOD->getDateFichier());
      pTpRevODTable[i].heure_fichier = pTpOD->getHeureFichier();

      totalPassagers += pTpOD->getNbVoyageurs();
      totalRevenu += pTpOD->getRevenu();
      //cout<<"TPREV_OD: "<<pTpRevODTable[i].tranche_no<<" "<<pTpRevODTable[i].date_od<<" "<<pTpOD->getOrig()<<" "<<pTpOD->getDest()<<" "<<pTpOD->getClassOfService()<<" "<<pTpRevODTable[i].nest_level<<" "<<pTpRevODTable[i].dpt_date<<endl;
      delete pTpOD;
      i++;
      iPos++;
    } 
    _MapTpOD.erase (_MapTpOD.begin(), iPos);

    //DM7978 - JLA - Ajout du num_palier
	
	
    /* EXEC SQL FOR :nbInBulk INSERT INTO TPREV_OD
         (TRANCHE_NO, DPT_DATE, ORIG, DEST, CLASS_OF_SERVICE, NUM_PALIER, NEST_LEVEL, DATE_OD, NB_VOYAGEURS,
          MARKET_ID, REVENU, TYPE_FLAG, DATE_FICHIER, HEURE_FICHIER, SCX)
         values (:pTpRevODTable); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 15;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert INTO TPREV_OD ( TRANCHE_NO , DPT_DATE , ORIG , DES\
T , CLASS_OF_SERVICE , NUM_PALIER , NEST_LEVEL , DATE_OD , NB_VOYAGEURS , MARK\
ET_ID , REVENU , TYPE_FLAG , DATE_FICHIER , HEURE_FICHIER , SCX ) values ( :s1\
 ,:s2 ,:s3 ,:s4 ,:s5 ,:s6 ,:s7 ,:s8 ,:s9 ,:s10 ,:s11 ,:s12 ,:s13 ,:s14 ,:s15  \
) ";
    sqlstm.iters = (unsigned int  )nbInBulk;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&pTpRevODTable->tranche_no;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)pTpRevODTable->dpt_date;
    sqlstm.sqhstl[1] = (unsigned long )11;
    sqlstm.sqhsts[1] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&pTpRevODTable->orig;
    sqlstm.sqhstl[2] = (unsigned long )8;
    sqlstm.sqhsts[2] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&pTpRevODTable->dest;
    sqlstm.sqhstl[3] = (unsigned long )8;
    sqlstm.sqhsts[3] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&pTpRevODTable->class_of_service;
    sqlstm.sqhstl[4] = (unsigned long )5;
    sqlstm.sqhsts[4] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqharc[4] = (unsigned long  *)0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&pTpRevODTable->num_palier;
    sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[5] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqharc[5] = (unsigned long  *)0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&pTpRevODTable->nest_level;
    sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[6] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqharc[6] = (unsigned long  *)0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)pTpRevODTable->date_od;
    sqlstm.sqhstl[7] = (unsigned long )11;
    sqlstm.sqhsts[7] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqharc[7] = (unsigned long  *)0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)&pTpRevODTable->nb_voyageurs;
    sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[8] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqharc[8] = (unsigned long  *)0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)&pTpRevODTable->market_id;
    sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[9] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[9] = (         short *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqharc[9] = (unsigned long  *)0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)&pTpRevODTable->revenu;
    sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[10] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[10] = (         short *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqharc[10] = (unsigned long  *)0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (unsigned char  *)&pTpRevODTable->type_flag;
    sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[11] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[11] = (         short *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned long )0;
    sqlstm.sqharc[11] = (unsigned long  *)0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (unsigned char  *)pTpRevODTable->date_fichier;
    sqlstm.sqhstl[12] = (unsigned long )11;
    sqlstm.sqhsts[12] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[12] = (         short *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned long )0;
    sqlstm.sqharc[12] = (unsigned long  *)0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (unsigned char  *)&pTpRevODTable->heure_fichier;
    sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[13] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[13] = (         short *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned long )0;
    sqlstm.sqharc[13] = (unsigned long  *)0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (unsigned char  *)&pTpRevODTable->scx;
    sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[14] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[14] = (         short *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned long )0;
    sqlstm.sqharc[14] = (unsigned long  *)0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
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
    if (sqlca.sqlcode < 0) sql_error("INSERT IN TPREV_OD en erreur",0);
}


    /* EXEC SQL COMMIT WORK; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 15;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )80;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("INSERT IN TPREV_OD en erreur",0);
}


    cout<<"t";
  }
  cout<<endl;
  cout<<DonneHeure()<<" Fin insert dans TPREV_OD, totRevenu="<<totalRevenu<<" totPas="<<totalPassagers<<endl;
}



void YmRevMapTpOD::InsertTPREVOD()
{
  int totalRevenu = 0;
  int totalPassagers = 0;
  cout<<DonneHeure()<<" Ecriture dans dans TPREV_OD"<<endl;
  
  /* EXEC SQL WHENEVER SQLERROR DO sql_error  ("INSERT IN TPREV_OD en erreur", 0); */ 

  MapTpODType::iterator iPos = _MapTpOD.begin();
  MapTpODType::iterator iFin = _MapTpOD.end();

  YmRevTpOD* pTpOD;
  nbInBulk = MAX_NB_TPREVOD;
  int i = 0;
  int nbl = 0;
  while (iPos!=iFin)
  {
     pTpOD =iPos->second;
     if (pTpOD->getTypeFlag() != 2)
     {
	
	 
       pTpRevODTable[i].tranche_no = pTpOD->getTrancheNo();
	 
       strcpy (pTpRevODTable[i].dpt_date, pTpOD->getDptDate());
       strcpy ((char*)pTpRevODTable[i].orig.arr, pTpOD->getOrig().c_str());
       pTpRevODTable[i].orig.len = pTpOD->getOrig().size();
       strcpy ((char*)pTpRevODTable[i].dest.arr, pTpOD->getDest().c_str());
       pTpRevODTable[i].dest.len = pTpOD->getDest().size();
       strcpy ((char*)pTpRevODTable[i].class_of_service.arr, pTpOD->getClassOfService().c_str());
       pTpRevODTable[i].class_of_service.len = pTpOD->getClassOfService().size();
	  //DM7978 - JLA - Ajout du num_palier
	   pTpRevODTable[i].num_palier = pTpOD->getNumPalier();  
       pTpRevODTable[i].nest_level = pTpOD->getNestLevel();
//DM5882.1 :sous-contingentement ( scx ) pour nestlevel =0
       pTpRevODTable[i].scx = pTpOD->getScx();
//

       strcpy (pTpRevODTable[i].date_od, pTpOD->getDateOd());
       pTpRevODTable[i].nb_voyageurs = pTpOD->getNbVoyageurs();
       pTpRevODTable[i].market_id = 0;
       pTpRevODTable[i].revenu = pTpOD->getRevenu();
       pTpRevODTable[i].type_flag = pTpOD->getTypeFlag();
       strcpy (pTpRevODTable[i].date_fichier, pTpOD->getDateFichier());
       pTpRevODTable[i].heure_fichier = pTpOD->getHeureFichier();

       totalPassagers += pTpOD->getNbVoyageurs();
       totalRevenu += pTpOD->getRevenu();
       i++;
       nbl ++;
     }
     iPos++;

     if (i == nbInBulk)
     {
	 	  //DM7978 - JLA - Ajout du num_palier
		 
       /* EXEC SQL FOR :nbInBulk INSERT INTO TPREV_OD
         ( TRANCHE_NO, DPT_DATE, ORIG, DEST, CLASS_OF_SERVICE, NUM_PALIER, NEST_LEVEL, DATE_OD, NB_VOYAGEURS,
          MARKET_ID, REVENU, TYPE_FLAG, DATE_FICHIER, HEURE_FICHIER, SCX)
         values (:pTpRevODTable); */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 12;
       sqlstm.arrsiz = 15;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.stmt = "insert INTO TPREV_OD ( TRANCHE_NO , DPT_DATE , ORIG , \
DEST , CLASS_OF_SERVICE , NUM_PALIER , NEST_LEVEL , DATE_OD , NB_VOYAGEURS , M\
ARKET_ID , REVENU , TYPE_FLAG , DATE_FICHIER , HEURE_FICHIER , SCX ) values ( \
:s1 ,:s2 ,:s3 ,:s4 ,:s5 ,:s6 ,:s7 ,:s8 ,:s9 ,:s10 ,:s11 ,:s12 ,:s13 ,:s14 ,:s1\
5  ) ";
       sqlstm.iters = (unsigned int  )nbInBulk;
       sqlstm.offset = (unsigned int  )95;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlstm.sqhstv[0] = (unsigned char  *)&pTpRevODTable->tranche_no;
       sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[0] = (         int  )sizeof(struct TPREV_OD);
       sqlstm.sqindv[0] = (         short *)0;
       sqlstm.sqinds[0] = (         int  )0;
       sqlstm.sqharm[0] = (unsigned long )0;
       sqlstm.sqharc[0] = (unsigned long  *)0;
       sqlstm.sqadto[0] = (unsigned short )0;
       sqlstm.sqtdso[0] = (unsigned short )0;
       sqlstm.sqhstv[1] = (unsigned char  *)pTpRevODTable->dpt_date;
       sqlstm.sqhstl[1] = (unsigned long )11;
       sqlstm.sqhsts[1] = (         int  )sizeof(struct TPREV_OD);
       sqlstm.sqindv[1] = (         short *)0;
       sqlstm.sqinds[1] = (         int  )0;
       sqlstm.sqharm[1] = (unsigned long )0;
       sqlstm.sqharc[1] = (unsigned long  *)0;
       sqlstm.sqadto[1] = (unsigned short )0;
       sqlstm.sqtdso[1] = (unsigned short )0;
       sqlstm.sqhstv[2] = (unsigned char  *)&pTpRevODTable->orig;
       sqlstm.sqhstl[2] = (unsigned long )8;
       sqlstm.sqhsts[2] = (         int  )sizeof(struct TPREV_OD);
       sqlstm.sqindv[2] = (         short *)0;
       sqlstm.sqinds[2] = (         int  )0;
       sqlstm.sqharm[2] = (unsigned long )0;
       sqlstm.sqharc[2] = (unsigned long  *)0;
       sqlstm.sqadto[2] = (unsigned short )0;
       sqlstm.sqtdso[2] = (unsigned short )0;
       sqlstm.sqhstv[3] = (unsigned char  *)&pTpRevODTable->dest;
       sqlstm.sqhstl[3] = (unsigned long )8;
       sqlstm.sqhsts[3] = (         int  )sizeof(struct TPREV_OD);
       sqlstm.sqindv[3] = (         short *)0;
       sqlstm.sqinds[3] = (         int  )0;
       sqlstm.sqharm[3] = (unsigned long )0;
       sqlstm.sqharc[3] = (unsigned long  *)0;
       sqlstm.sqadto[3] = (unsigned short )0;
       sqlstm.sqtdso[3] = (unsigned short )0;
       sqlstm.sqhstv[4] = (unsigned char  *)&pTpRevODTable->class_of_service;
       sqlstm.sqhstl[4] = (unsigned long )5;
       sqlstm.sqhsts[4] = (         int  )sizeof(struct TPREV_OD);
       sqlstm.sqindv[4] = (         short *)0;
       sqlstm.sqinds[4] = (         int  )0;
       sqlstm.sqharm[4] = (unsigned long )0;
       sqlstm.sqharc[4] = (unsigned long  *)0;
       sqlstm.sqadto[4] = (unsigned short )0;
       sqlstm.sqtdso[4] = (unsigned short )0;
       sqlstm.sqhstv[5] = (unsigned char  *)&pTpRevODTable->num_palier;
       sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[5] = (         int  )sizeof(struct TPREV_OD);
       sqlstm.sqindv[5] = (         short *)0;
       sqlstm.sqinds[5] = (         int  )0;
       sqlstm.sqharm[5] = (unsigned long )0;
       sqlstm.sqharc[5] = (unsigned long  *)0;
       sqlstm.sqadto[5] = (unsigned short )0;
       sqlstm.sqtdso[5] = (unsigned short )0;
       sqlstm.sqhstv[6] = (unsigned char  *)&pTpRevODTable->nest_level;
       sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[6] = (         int  )sizeof(struct TPREV_OD);
       sqlstm.sqindv[6] = (         short *)0;
       sqlstm.sqinds[6] = (         int  )0;
       sqlstm.sqharm[6] = (unsigned long )0;
       sqlstm.sqharc[6] = (unsigned long  *)0;
       sqlstm.sqadto[6] = (unsigned short )0;
       sqlstm.sqtdso[6] = (unsigned short )0;
       sqlstm.sqhstv[7] = (unsigned char  *)pTpRevODTable->date_od;
       sqlstm.sqhstl[7] = (unsigned long )11;
       sqlstm.sqhsts[7] = (         int  )sizeof(struct TPREV_OD);
       sqlstm.sqindv[7] = (         short *)0;
       sqlstm.sqinds[7] = (         int  )0;
       sqlstm.sqharm[7] = (unsigned long )0;
       sqlstm.sqharc[7] = (unsigned long  *)0;
       sqlstm.sqadto[7] = (unsigned short )0;
       sqlstm.sqtdso[7] = (unsigned short )0;
       sqlstm.sqhstv[8] = (unsigned char  *)&pTpRevODTable->nb_voyageurs;
       sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[8] = (         int  )sizeof(struct TPREV_OD);
       sqlstm.sqindv[8] = (         short *)0;
       sqlstm.sqinds[8] = (         int  )0;
       sqlstm.sqharm[8] = (unsigned long )0;
       sqlstm.sqharc[8] = (unsigned long  *)0;
       sqlstm.sqadto[8] = (unsigned short )0;
       sqlstm.sqtdso[8] = (unsigned short )0;
       sqlstm.sqhstv[9] = (unsigned char  *)&pTpRevODTable->market_id;
       sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[9] = (         int  )sizeof(struct TPREV_OD);
       sqlstm.sqindv[9] = (         short *)0;
       sqlstm.sqinds[9] = (         int  )0;
       sqlstm.sqharm[9] = (unsigned long )0;
       sqlstm.sqharc[9] = (unsigned long  *)0;
       sqlstm.sqadto[9] = (unsigned short )0;
       sqlstm.sqtdso[9] = (unsigned short )0;
       sqlstm.sqhstv[10] = (unsigned char  *)&pTpRevODTable->revenu;
       sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[10] = (         int  )sizeof(struct TPREV_OD);
       sqlstm.sqindv[10] = (         short *)0;
       sqlstm.sqinds[10] = (         int  )0;
       sqlstm.sqharm[10] = (unsigned long )0;
       sqlstm.sqharc[10] = (unsigned long  *)0;
       sqlstm.sqadto[10] = (unsigned short )0;
       sqlstm.sqtdso[10] = (unsigned short )0;
       sqlstm.sqhstv[11] = (unsigned char  *)&pTpRevODTable->type_flag;
       sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[11] = (         int  )sizeof(struct TPREV_OD);
       sqlstm.sqindv[11] = (         short *)0;
       sqlstm.sqinds[11] = (         int  )0;
       sqlstm.sqharm[11] = (unsigned long )0;
       sqlstm.sqharc[11] = (unsigned long  *)0;
       sqlstm.sqadto[11] = (unsigned short )0;
       sqlstm.sqtdso[11] = (unsigned short )0;
       sqlstm.sqhstv[12] = (unsigned char  *)pTpRevODTable->date_fichier;
       sqlstm.sqhstl[12] = (unsigned long )11;
       sqlstm.sqhsts[12] = (         int  )sizeof(struct TPREV_OD);
       sqlstm.sqindv[12] = (         short *)0;
       sqlstm.sqinds[12] = (         int  )0;
       sqlstm.sqharm[12] = (unsigned long )0;
       sqlstm.sqharc[12] = (unsigned long  *)0;
       sqlstm.sqadto[12] = (unsigned short )0;
       sqlstm.sqtdso[12] = (unsigned short )0;
       sqlstm.sqhstv[13] = (unsigned char  *)&pTpRevODTable->heure_fichier;
       sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[13] = (         int  )sizeof(struct TPREV_OD);
       sqlstm.sqindv[13] = (         short *)0;
       sqlstm.sqinds[13] = (         int  )0;
       sqlstm.sqharm[13] = (unsigned long )0;
       sqlstm.sqharc[13] = (unsigned long  *)0;
       sqlstm.sqadto[13] = (unsigned short )0;
       sqlstm.sqtdso[13] = (unsigned short )0;
       sqlstm.sqhstv[14] = (unsigned char  *)&pTpRevODTable->scx;
       sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[14] = (         int  )sizeof(struct TPREV_OD);
       sqlstm.sqindv[14] = (         short *)0;
       sqlstm.sqinds[14] = (         int  )0;
       sqlstm.sqharm[14] = (unsigned long )0;
       sqlstm.sqharc[14] = (unsigned long  *)0;
       sqlstm.sqadto[14] = (unsigned short )0;
       sqlstm.sqtdso[14] = (unsigned short )0;
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
       if (sqlca.sqlcode < 0) sql_error("INSERT IN TPREV_OD en erreur",0);
}


       /* EXEC SQL COMMIT WORK; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 12;
       sqlstm.arrsiz = 15;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )170;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
       if (sqlca.sqlcode < 0) sql_error("INSERT IN TPREV_OD en erreur",0);
}


       cout<<"t";
       i = 0;
     }
  }
  if (i)
  { // On insere le reliquat
    nbInBulk = i;

		  //DM7978 - JLA - Ajout du num_palier
    /* EXEC SQL FOR :nbInBulk INSERT INTO TPREV_OD
         ( TRANCHE_NO, DPT_DATE, ORIG, DEST, CLASS_OF_SERVICE, NUM_PALIER, NEST_LEVEL, DATE_OD, NB_VOYAGEURS,
          MARKET_ID, REVENU, TYPE_FLAG, DATE_FICHIER, HEURE_FICHIER, SCX)
         values (:pTpRevODTable); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 15;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert INTO TPREV_OD ( TRANCHE_NO , DPT_DATE , ORIG , DES\
T , CLASS_OF_SERVICE , NUM_PALIER , NEST_LEVEL , DATE_OD , NB_VOYAGEURS , MARK\
ET_ID , REVENU , TYPE_FLAG , DATE_FICHIER , HEURE_FICHIER , SCX ) values ( :s1\
 ,:s2 ,:s3 ,:s4 ,:s5 ,:s6 ,:s7 ,:s8 ,:s9 ,:s10 ,:s11 ,:s12 ,:s13 ,:s14 ,:s15  \
) ";
    sqlstm.iters = (unsigned int  )nbInBulk;
    sqlstm.offset = (unsigned int  )185;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&pTpRevODTable->tranche_no;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)pTpRevODTable->dpt_date;
    sqlstm.sqhstl[1] = (unsigned long )11;
    sqlstm.sqhsts[1] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&pTpRevODTable->orig;
    sqlstm.sqhstl[2] = (unsigned long )8;
    sqlstm.sqhsts[2] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&pTpRevODTable->dest;
    sqlstm.sqhstl[3] = (unsigned long )8;
    sqlstm.sqhsts[3] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&pTpRevODTable->class_of_service;
    sqlstm.sqhstl[4] = (unsigned long )5;
    sqlstm.sqhsts[4] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqharc[4] = (unsigned long  *)0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&pTpRevODTable->num_palier;
    sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[5] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqharc[5] = (unsigned long  *)0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&pTpRevODTable->nest_level;
    sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[6] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqharc[6] = (unsigned long  *)0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)pTpRevODTable->date_od;
    sqlstm.sqhstl[7] = (unsigned long )11;
    sqlstm.sqhsts[7] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqharc[7] = (unsigned long  *)0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)&pTpRevODTable->nb_voyageurs;
    sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[8] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqharc[8] = (unsigned long  *)0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)&pTpRevODTable->market_id;
    sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[9] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[9] = (         short *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqharc[9] = (unsigned long  *)0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)&pTpRevODTable->revenu;
    sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[10] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[10] = (         short *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqharc[10] = (unsigned long  *)0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (unsigned char  *)&pTpRevODTable->type_flag;
    sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[11] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[11] = (         short *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned long )0;
    sqlstm.sqharc[11] = (unsigned long  *)0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (unsigned char  *)pTpRevODTable->date_fichier;
    sqlstm.sqhstl[12] = (unsigned long )11;
    sqlstm.sqhsts[12] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[12] = (         short *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned long )0;
    sqlstm.sqharc[12] = (unsigned long  *)0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (unsigned char  *)&pTpRevODTable->heure_fichier;
    sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[13] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[13] = (         short *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned long )0;
    sqlstm.sqharc[13] = (unsigned long  *)0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (unsigned char  *)&pTpRevODTable->scx;
    sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[14] = (         int  )sizeof(struct TPREV_OD);
    sqlstm.sqindv[14] = (         short *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned long )0;
    sqlstm.sqharc[14] = (unsigned long  *)0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
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
    if (sqlca.sqlcode < 0) sql_error("INSERT IN TPREV_OD en erreur",0);
}


    /* EXEC SQL COMMIT WORK; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 15;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )260;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("INSERT IN TPREV_OD en erreur",0);
}


    cout<<"t";
  }
  cout<<endl;
  cout<<DonneHeure()<<" Fin insert "<<nbl<<" lignes dans TPREV_OD, totRevenu="<<totalRevenu<<" totPas="<<totalPassagers<<endl;
}

// Mise à jour de rev_segments pour avoir tranche_no en phase avec TPREV_OD
void YmRevMapTpOD::UpdateRevSegments()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

       		int inoTrancheFetch=-1;
		int inoTrainFetch;
       		/* varchar vdatedpt_date[11]; */ 
struct { unsigned short len; unsigned char arr[11]; } vdatedpt_date;

    	/* EXEC SQL END DECLARE SECTION; */ 

	
	/* EXEC SQL WHENEVER SQLERROR DO sql_error("UPDATE REV SEGMENT en erreur", 0); */ 


	/* EXEC SQL DECLARE curs CURSOR FOR 
		SELECT MIN(b.TRANCHE_NO),b.TRAIN_NO, b.DPT_DATE 
		FROM TPREV_NON_TRAITE a,REV_TRANCHES_LEGS b 
		WHERE a.IS_TRAIN = 1 AND b.TRAIN_NO =a.TRANCHE_NO AND a.DPT_DATE =b.DPT_DATE GROUP BY b.TRANCHE_NO,b.TRAIN_NO, b.DPT_DATE; */ 


	/* EXEC SQL OPEN curs; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0007;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )275;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("UPDATE REV SEGMENT en erreur",0);
}


	while(1)
	{	
	//EXEC SQL WHENEVER NOT FOUND DO break;
	/* EXEC SQL WHENEVER SQLERROR  DO break; */ 

	  
	/* EXEC SQL FETCH curs INTO :inoTrancheFetch, :inoTrainFetch, :vdatedpt_date; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )290;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqfoff = (         int )0;
 sqlstm.sqfmod = (unsigned int )2;
 sqlstm.sqhstv[0] = (unsigned char  *)&inoTrancheFetch;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&inoTrainFetch;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&vdatedpt_date;
 sqlstm.sqhstl[2] = (unsigned long )13;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
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
 if (sqlca.sqlcode < 0) break;
}


		
		if (inoTrancheFetch == -1)
		{
			break;
		}

		/*if (inoTrancheFetch >= 0)
		{
			cout<<"tranche no = "<< inoTrancheFetch << '\n' << endl;
			cout<<"train no = "<< inoTrainFetch << '\n' << endl;
			cout<<"dpt_date = "<< vdatedpt_date.arr << endl;
		}*/

	
	/* EXEC SQL UPDATE REV_SEGMENTS SET TRANCHE_NO=:inoTrancheFetch WHERE TRAIN_NO = :inoTrainFetch AND DATE_DEPART=:vdatedpt_date; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "update REV_SEGMENTS SET TRANCHE_NO = :b0 WHERE TRAIN_NO = :b\
1 AND DATE_DEPART = :b2 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )317;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&inoTrancheFetch;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&inoTrainFetch;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&vdatedpt_date;
 sqlstm.sqhstl[2] = (unsigned long )13;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
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
 if (sqlca.sqlcode < 0) break;
}


	//EXEC SQL WHENEVER SQLERROR DO sql_error((char *)"Erreur Update TRANCHE_NO d'un train IC SRO dans REV_SEGMENTS", 0);
	}
	/* EXEC SQL WHENEVER SQLERROR DO sql_error("UPDATE REV SEGMENT en erreur", 0); */ 

	/* EXEC SQL CLOSE curs; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )344;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("UPDATE REV SEGMENT en erreur",0);
}


}

void YmRevMapTpOD::InsertTPREVNONTRAITE()
{
  int totalRevenu = 0;
  int totalPassagers = 0;
  cout<<DonneHeure()<<" Ecriture dans dans TPREV_NON_TRAITE"<<endl;
  
  /* EXEC SQL WHENEVER SQLERROR DO sql_error  ("INSERT IN TPREV_NON_TRAITE en erreur", 0); */ 

  MapTpODType::iterator iPos = _MapTpOD.begin();
  MapTpODType::iterator iFin = _MapTpOD.end();

  YmRevTpOD* pTpOD;
  nbInBulk = MAX_NB_TPREVOD;
  int i = 0;
  int nbl = 0;
  while (iPos!=iFin)
  {
     pTpOD =iPos->second;
     if (pTpOD->getTypeFlag() == 2)
     {
		
	   
       pTpRevNTTable[i].tranche_no = pTpOD->getTrancheNo();
       strcpy (pTpRevNTTable[i].dpt_date, pTpOD->getDptDate());
	
	   
       strcpy ((char*)pTpRevNTTable[i].orig.arr, pTpOD->getOrig().c_str());
       pTpRevNTTable[i].orig.len = pTpOD->getOrig().size();
       strcpy ((char*)pTpRevNTTable[i].dest.arr, pTpOD->getDest().c_str());
       pTpRevNTTable[i].dest.len = pTpOD->getDest().size();
       strcpy ((char*)pTpRevNTTable[i].class_of_service.arr, pTpOD->getClassOfService().c_str());
       pTpRevNTTable[i].class_of_service.len = pTpOD->getClassOfService().size();
	   //DM7978 - JLA - Ajout du num_palier
	   pTpRevNTTable[i].num_palier = pTpOD->getNumPalier();
       pTpRevNTTable[i].nest_level = pTpOD->getNestLevel();
//DM5882.1 :sous-contingentement ( scx ) pour nestlevel =0
       pTpRevNTTable[i].scx = pTpOD->getScx();
       strcpy (pTpRevNTTable[i].date_od, pTpOD->getDateOd());
       pTpRevNTTable[i].nb_voyageurs = pTpOD->getNbVoyageurs();
       pTpRevNTTable[i].revenu = pTpOD->getRevenu();
       strcpy (pTpRevNTTable[i].date_fichier, pTpOD->getDateFichier());
       pTpRevNTTable[i].heure_fichier = pTpOD->getHeureFichier();
//DT23805 JRO -IC SRO - Ajout flag ISNOTRAIN
		pTpRevNTTable[i].isTrain = pTpOD->getIsTrain(); 
       totalPassagers += pTpOD->getNbVoyageurs();
       totalRevenu += pTpOD->getRevenu();
       i++;
       nbl ++;
     }
     iPos++;
     if (i == nbInBulk)
     {
	 //DM7978 - JLA - Ajout du num_palier 
	// JRO -IC SRO - DT 23805 - Ajout de la colonne flag IS_TRAIN
       /* EXEC SQL FOR :nbInBulk INSERT INTO TPREV_NON_TRAITE
         (TRANCHE_NO, DPT_DATE, ORIG, DEST, CLASS_OF_SERVICE, NUM_PALIER, NEST_LEVEL, DATE_OD, NB_VOYAGEURS,
          REVENU, DATE_FICHIER, HEURE_FICHIER, SCX, IS_TRAIN)
         values (:pTpRevNTTable); */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 12;
       sqlstm.arrsiz = 15;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.stmt = "insert INTO TPREV_NON_TRAITE ( TRANCHE_NO , DPT_DATE ,\
 ORIG , DEST , CLASS_OF_SERVICE , NUM_PALIER , NEST_LEVEL , DATE_OD , NB_VOYAG\
EURS , REVENU , DATE_FICHIER , HEURE_FICHIER , SCX , IS_TRAIN ) values ( :s1 ,\
:s2 ,:s3 ,:s4 ,:s5 ,:s6 ,:s7 ,:s8 ,:s9 ,:s10 ,:s11 ,:s12 ,:s13 ,:s14  ) ";
       sqlstm.iters = (unsigned int  )nbInBulk;
       sqlstm.offset = (unsigned int  )359;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlstm.sqhstv[0] = (unsigned char  *)&pTpRevNTTable->tranche_no;
       sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[0] = (         int  )sizeof(struct TPREV_NON_TRAITE);
       sqlstm.sqindv[0] = (         short *)0;
       sqlstm.sqinds[0] = (         int  )0;
       sqlstm.sqharm[0] = (unsigned long )0;
       sqlstm.sqharc[0] = (unsigned long  *)0;
       sqlstm.sqadto[0] = (unsigned short )0;
       sqlstm.sqtdso[0] = (unsigned short )0;
       sqlstm.sqhstv[1] = (unsigned char  *)pTpRevNTTable->dpt_date;
       sqlstm.sqhstl[1] = (unsigned long )11;
       sqlstm.sqhsts[1] = (         int  )sizeof(struct TPREV_NON_TRAITE);
       sqlstm.sqindv[1] = (         short *)0;
       sqlstm.sqinds[1] = (         int  )0;
       sqlstm.sqharm[1] = (unsigned long )0;
       sqlstm.sqharc[1] = (unsigned long  *)0;
       sqlstm.sqadto[1] = (unsigned short )0;
       sqlstm.sqtdso[1] = (unsigned short )0;
       sqlstm.sqhstv[2] = (unsigned char  *)&pTpRevNTTable->orig;
       sqlstm.sqhstl[2] = (unsigned long )8;
       sqlstm.sqhsts[2] = (         int  )sizeof(struct TPREV_NON_TRAITE);
       sqlstm.sqindv[2] = (         short *)0;
       sqlstm.sqinds[2] = (         int  )0;
       sqlstm.sqharm[2] = (unsigned long )0;
       sqlstm.sqharc[2] = (unsigned long  *)0;
       sqlstm.sqadto[2] = (unsigned short )0;
       sqlstm.sqtdso[2] = (unsigned short )0;
       sqlstm.sqhstv[3] = (unsigned char  *)&pTpRevNTTable->dest;
       sqlstm.sqhstl[3] = (unsigned long )8;
       sqlstm.sqhsts[3] = (         int  )sizeof(struct TPREV_NON_TRAITE);
       sqlstm.sqindv[3] = (         short *)0;
       sqlstm.sqinds[3] = (         int  )0;
       sqlstm.sqharm[3] = (unsigned long )0;
       sqlstm.sqharc[3] = (unsigned long  *)0;
       sqlstm.sqadto[3] = (unsigned short )0;
       sqlstm.sqtdso[3] = (unsigned short )0;
       sqlstm.sqhstv[4] = (unsigned char  *)&pTpRevNTTable->class_of_service;
       sqlstm.sqhstl[4] = (unsigned long )5;
       sqlstm.sqhsts[4] = (         int  )sizeof(struct TPREV_NON_TRAITE);
       sqlstm.sqindv[4] = (         short *)0;
       sqlstm.sqinds[4] = (         int  )0;
       sqlstm.sqharm[4] = (unsigned long )0;
       sqlstm.sqharc[4] = (unsigned long  *)0;
       sqlstm.sqadto[4] = (unsigned short )0;
       sqlstm.sqtdso[4] = (unsigned short )0;
       sqlstm.sqhstv[5] = (unsigned char  *)&pTpRevNTTable->num_palier;
       sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[5] = (         int  )sizeof(struct TPREV_NON_TRAITE);
       sqlstm.sqindv[5] = (         short *)0;
       sqlstm.sqinds[5] = (         int  )0;
       sqlstm.sqharm[5] = (unsigned long )0;
       sqlstm.sqharc[5] = (unsigned long  *)0;
       sqlstm.sqadto[5] = (unsigned short )0;
       sqlstm.sqtdso[5] = (unsigned short )0;
       sqlstm.sqhstv[6] = (unsigned char  *)&pTpRevNTTable->nest_level;
       sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[6] = (         int  )sizeof(struct TPREV_NON_TRAITE);
       sqlstm.sqindv[6] = (         short *)0;
       sqlstm.sqinds[6] = (         int  )0;
       sqlstm.sqharm[6] = (unsigned long )0;
       sqlstm.sqharc[6] = (unsigned long  *)0;
       sqlstm.sqadto[6] = (unsigned short )0;
       sqlstm.sqtdso[6] = (unsigned short )0;
       sqlstm.sqhstv[7] = (unsigned char  *)pTpRevNTTable->date_od;
       sqlstm.sqhstl[7] = (unsigned long )11;
       sqlstm.sqhsts[7] = (         int  )sizeof(struct TPREV_NON_TRAITE);
       sqlstm.sqindv[7] = (         short *)0;
       sqlstm.sqinds[7] = (         int  )0;
       sqlstm.sqharm[7] = (unsigned long )0;
       sqlstm.sqharc[7] = (unsigned long  *)0;
       sqlstm.sqadto[7] = (unsigned short )0;
       sqlstm.sqtdso[7] = (unsigned short )0;
       sqlstm.sqhstv[8] = (unsigned char  *)&pTpRevNTTable->nb_voyageurs;
       sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[8] = (         int  )sizeof(struct TPREV_NON_TRAITE);
       sqlstm.sqindv[8] = (         short *)0;
       sqlstm.sqinds[8] = (         int  )0;
       sqlstm.sqharm[8] = (unsigned long )0;
       sqlstm.sqharc[8] = (unsigned long  *)0;
       sqlstm.sqadto[8] = (unsigned short )0;
       sqlstm.sqtdso[8] = (unsigned short )0;
       sqlstm.sqhstv[9] = (unsigned char  *)&pTpRevNTTable->revenu;
       sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[9] = (         int  )sizeof(struct TPREV_NON_TRAITE);
       sqlstm.sqindv[9] = (         short *)0;
       sqlstm.sqinds[9] = (         int  )0;
       sqlstm.sqharm[9] = (unsigned long )0;
       sqlstm.sqharc[9] = (unsigned long  *)0;
       sqlstm.sqadto[9] = (unsigned short )0;
       sqlstm.sqtdso[9] = (unsigned short )0;
       sqlstm.sqhstv[10] = (unsigned char  *)pTpRevNTTable->date_fichier;
       sqlstm.sqhstl[10] = (unsigned long )11;
       sqlstm.sqhsts[10] = (         int  )sizeof(struct TPREV_NON_TRAITE);
       sqlstm.sqindv[10] = (         short *)0;
       sqlstm.sqinds[10] = (         int  )0;
       sqlstm.sqharm[10] = (unsigned long )0;
       sqlstm.sqharc[10] = (unsigned long  *)0;
       sqlstm.sqadto[10] = (unsigned short )0;
       sqlstm.sqtdso[10] = (unsigned short )0;
       sqlstm.sqhstv[11] = (unsigned char  *)&pTpRevNTTable->heure_fichier;
       sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[11] = (         int  )sizeof(struct TPREV_NON_TRAITE);
       sqlstm.sqindv[11] = (         short *)0;
       sqlstm.sqinds[11] = (         int  )0;
       sqlstm.sqharm[11] = (unsigned long )0;
       sqlstm.sqharc[11] = (unsigned long  *)0;
       sqlstm.sqadto[11] = (unsigned short )0;
       sqlstm.sqtdso[11] = (unsigned short )0;
       sqlstm.sqhstv[12] = (unsigned char  *)&pTpRevNTTable->scx;
       sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[12] = (         int  )sizeof(struct TPREV_NON_TRAITE);
       sqlstm.sqindv[12] = (         short *)0;
       sqlstm.sqinds[12] = (         int  )0;
       sqlstm.sqharm[12] = (unsigned long )0;
       sqlstm.sqharc[12] = (unsigned long  *)0;
       sqlstm.sqadto[12] = (unsigned short )0;
       sqlstm.sqtdso[12] = (unsigned short )0;
       sqlstm.sqhstv[13] = (unsigned char  *)&pTpRevNTTable->isTrain;
       sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[13] = (         int  )sizeof(struct TPREV_NON_TRAITE);
       sqlstm.sqindv[13] = (         short *)0;
       sqlstm.sqinds[13] = (         int  )0;
       sqlstm.sqharm[13] = (unsigned long )0;
       sqlstm.sqharc[13] = (unsigned long  *)0;
       sqlstm.sqadto[13] = (unsigned short )0;
       sqlstm.sqtdso[13] = (unsigned short )0;
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
       if (sqlca.sqlcode < 0) sql_error("INSERT IN TPREV_NON_TRAITE en erreur",0);
}


       /* EXEC SQL COMMIT WORK; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 12;
       sqlstm.arrsiz = 15;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )430;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
       if (sqlca.sqlcode < 0) sql_error("INSERT IN TPREV_NON_TRAITE en erreur",0);
}


       cout<<"t";
       i = 0;
     }
  }
  //EXEC SQL WHENEVER SQLERROR DO sql_error  ("INSERT IN TPREV_NON_TRAITE en erreur", 0);
  if (i)
  { // On insere le reliquat
    nbInBulk = i;
	//DM7978 - JLA - Ajout du num_palier
	//DT23805 JRO -IC SRO - Ajout flag IS_TRAIN
    /* EXEC SQL FOR :nbInBulk INSERT INTO TPREV_NON_TRAITE
         (TRANCHE_NO, DPT_DATE, ORIG, DEST, CLASS_OF_SERVICE, NUM_PALIER, NEST_LEVEL, DATE_OD, NB_VOYAGEURS,
          REVENU, DATE_FICHIER, HEURE_FICHIER, SCX, IS_TRAIN)
         values (:pTpRevNTTable); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 15;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert INTO TPREV_NON_TRAITE ( TRANCHE_NO , DPT_DATE , OR\
IG , DEST , CLASS_OF_SERVICE , NUM_PALIER , NEST_LEVEL , DATE_OD , NB_VOYAGEUR\
S , REVENU , DATE_FICHIER , HEURE_FICHIER , SCX , IS_TRAIN ) values ( :s1 ,:s2\
 ,:s3 ,:s4 ,:s5 ,:s6 ,:s7 ,:s8 ,:s9 ,:s10 ,:s11 ,:s12 ,:s13 ,:s14  ) ";
    sqlstm.iters = (unsigned int  )nbInBulk;
    sqlstm.offset = (unsigned int  )445;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&pTpRevNTTable->tranche_no;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )sizeof(struct TPREV_NON_TRAITE);
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)pTpRevNTTable->dpt_date;
    sqlstm.sqhstl[1] = (unsigned long )11;
    sqlstm.sqhsts[1] = (         int  )sizeof(struct TPREV_NON_TRAITE);
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&pTpRevNTTable->orig;
    sqlstm.sqhstl[2] = (unsigned long )8;
    sqlstm.sqhsts[2] = (         int  )sizeof(struct TPREV_NON_TRAITE);
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&pTpRevNTTable->dest;
    sqlstm.sqhstl[3] = (unsigned long )8;
    sqlstm.sqhsts[3] = (         int  )sizeof(struct TPREV_NON_TRAITE);
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&pTpRevNTTable->class_of_service;
    sqlstm.sqhstl[4] = (unsigned long )5;
    sqlstm.sqhsts[4] = (         int  )sizeof(struct TPREV_NON_TRAITE);
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqharc[4] = (unsigned long  *)0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&pTpRevNTTable->num_palier;
    sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[5] = (         int  )sizeof(struct TPREV_NON_TRAITE);
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqharc[5] = (unsigned long  *)0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&pTpRevNTTable->nest_level;
    sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[6] = (         int  )sizeof(struct TPREV_NON_TRAITE);
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqharc[6] = (unsigned long  *)0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)pTpRevNTTable->date_od;
    sqlstm.sqhstl[7] = (unsigned long )11;
    sqlstm.sqhsts[7] = (         int  )sizeof(struct TPREV_NON_TRAITE);
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqharc[7] = (unsigned long  *)0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)&pTpRevNTTable->nb_voyageurs;
    sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[8] = (         int  )sizeof(struct TPREV_NON_TRAITE);
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqharc[8] = (unsigned long  *)0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)&pTpRevNTTable->revenu;
    sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[9] = (         int  )sizeof(struct TPREV_NON_TRAITE);
    sqlstm.sqindv[9] = (         short *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqharc[9] = (unsigned long  *)0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)pTpRevNTTable->date_fichier;
    sqlstm.sqhstl[10] = (unsigned long )11;
    sqlstm.sqhsts[10] = (         int  )sizeof(struct TPREV_NON_TRAITE);
    sqlstm.sqindv[10] = (         short *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqharc[10] = (unsigned long  *)0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (unsigned char  *)&pTpRevNTTable->heure_fichier;
    sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[11] = (         int  )sizeof(struct TPREV_NON_TRAITE);
    sqlstm.sqindv[11] = (         short *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned long )0;
    sqlstm.sqharc[11] = (unsigned long  *)0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (unsigned char  *)&pTpRevNTTable->scx;
    sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[12] = (         int  )sizeof(struct TPREV_NON_TRAITE);
    sqlstm.sqindv[12] = (         short *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned long )0;
    sqlstm.sqharc[12] = (unsigned long  *)0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (unsigned char  *)&pTpRevNTTable->isTrain;
    sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[13] = (         int  )sizeof(struct TPREV_NON_TRAITE);
    sqlstm.sqindv[13] = (         short *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned long )0;
    sqlstm.sqharc[13] = (unsigned long  *)0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
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
    if (sqlca.sqlcode < 0) sql_error("INSERT IN TPREV_NON_TRAITE en erreur",0);
}


    /* EXEC SQL COMMIT WORK; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 15;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )516;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("INSERT IN TPREV_NON_TRAITE en erreur",0);
}


    cout<<"t";
  }
  cout<<endl;
  cout<<DonneHeure()<<" Fin insert "<<nbl<<" lignes dans TPREV_NON_TRAITE, totRevenu="<<totalRevenu<<" totPas="<<totalPassagers<<endl;
}
