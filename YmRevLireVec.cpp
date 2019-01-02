
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
    "YmRevLireVec.pc"
};


static unsigned int sqlctx = 2731523;


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
   unsigned char  *sqhstv[27];
   unsigned long  sqhstl[27];
            int   sqhsts[27];
            short *sqindv[27];
            int   sqinds[27];
   unsigned long  sqharm[27];
   unsigned long  *sqharc[27];
   unsigned short  sqadto[27];
   unsigned short  sqtdso[27];
} sqlstm = {12,27};

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
5,0,0,0,0,0,58,200,0,0,1,1,0,1,0,3,109,0,0,
24,0,0,0,0,0,27,202,0,0,4,4,0,1,0,1,97,0,0,1,10,0,0,1,10,0,0,1,10,0,0,
55,0,0,2,0,0,29,229,0,0,0,0,0,1,0,
70,0,0,3,0,0,30,233,0,0,0,0,0,1,0,
85,0,0,0,0,0,59,234,0,0,1,1,0,1,0,3,109,0,0,
104,0,0,4,698,0,3,542,0,0,27,27,0,1,0,1,3,0,0,1,97,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
1,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,97,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,3,0,
0,1,9,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,9,0,0,1,
3,0,0,1,97,0,0,1,3,0,0,
227,0,0,5,0,0,29,549,0,0,0,0,0,1,0,
242,0,0,6,0,0,31,559,0,0,0,0,0,1,0,
257,0,0,7,698,0,3,570,0,0,27,27,0,1,0,1,3,0,0,1,97,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
1,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,97,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,3,0,
0,1,9,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,9,0,0,1,
3,0,0,1,97,0,0,1,3,0,0,
380,0,0,8,0,0,29,578,0,0,0,0,0,1,0,
395,0,0,9,419,0,3,688,0,0,14,14,0,1,0,1,3,0,0,1,97,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
1,9,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,9,0,0,
466,0,0,10,0,0,29,693,0,0,0,0,0,1,0,
481,0,0,11,0,0,31,703,0,0,0,0,0,1,0,
496,0,0,12,419,0,3,712,0,0,14,14,0,1,0,1,3,0,0,1,97,0,0,1,9,0,0,1,9,0,0,1,3,0,
0,1,9,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,9,0,0,
567,0,0,13,0,0,29,718,0,0,0,0,0,1,0,
582,0,0,14,129,0,3,814,0,0,4,4,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
613,0,0,15,252,0,3,818,0,0,9,9,0,1,0,1,3,0,0,1,97,0,0,1,3,0,0,1,9,0,0,1,97,0,0,
1,9,0,0,1,97,0,0,1,3,0,0,1,9,0,0,
664,0,0,16,0,0,29,824,0,0,0,0,0,1,0,
679,0,0,17,0,0,31,834,0,0,0,0,0,1,0,
694,0,0,18,129,0,3,842,0,0,4,4,0,1,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,
725,0,0,19,252,0,3,849,0,0,9,9,0,1,0,1,3,0,0,1,97,0,0,1,3,0,0,1,9,0,0,1,97,0,0,
1,9,0,0,1,97,0,0,1,3,0,0,1,9,0,0,
776,0,0,20,0,0,29,856,0,0,0,0,0,1,0,
};


//---------------------------------------------------------------------------------------------------------
// Lecture des donness RESAVEN placee dans le vecteur par EcrireVec
// --------------------------------------------------------------------------------------------------------

using namespace std;

#include <iostream>
#include </usr/lib/oracle/11.2/client64/precomp/public/sqlca.h>
#include <unistd.h>
#include <YmRevGlobal.h>
#include <YmRevLireVec.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//## Configuration du contexte de base JRO IC SRO DT 23805
extern sql_context ctxRevMain;
/* EXEC SQL CONTEXT USE :ctxRevMain; */ 


/* EXEC SQL BEGIN DECLARE SECTION; */ 


#define MAX_NBTCN_IN_BUF 1000
#define MAX_NBPAP_IN_BUF 2000
#define MAX_NBSEG_IN_BUF 4000

int nbTcnInBuf;
int nbPaPaInBuf;
int nbSegInBuf;

//JRO IC SRO DT23805 - 
int NoTranche_db;


struct REV_SEGMENTS {
        int tcn_number;
        char date_paiement[11];
        /* varchar tarif_type[7]; */ 
struct { unsigned short len; unsigned char arr[7]; } tarif_type;

        /* varchar class_of_service[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } class_of_service;

		//DM7978 - JLA - Ajout du palier
		int num_palier;
        int pp_num;
        int segment_num;
        /* varchar origine_seg[6]; */ 
struct { unsigned short len; unsigned char arr[6]; } origine_seg;

        /* varchar destination_seg[6]; */ 
struct { unsigned short len; unsigned char arr[6]; } destination_seg;

        int longueur_seg;
        char date_resa[11];
        /* varchar canal_reservation[4]; */ 
struct { unsigned short len; unsigned char arr[4]; } canal_reservation;

        int nest_level;
        int train_no;
        int tranche_no;
        /* varchar tranche_carrier_code[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } tranche_carrier_code;

        char date_depart[11];
        int heure_depart;
        char date_arrive[11];
        int heure_arrive;
        int niveau_social;
        int montant_resa;
        int montant_supplement;
        /* varchar type_equipement[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } type_equipement;

        int revenu;
        char date_max_depart[11];
        int scx;
      } pRevSegmentTable[MAX_NBSEG_IN_BUF];

struct REV_SEGMENTS pRevSegmentSingle[1];

struct REV_SEGMENTS_IND {
        short tcn_number_ind;
        short date_paiement_ind;
        short tarif_type_ind;
        short class_of_service_ind;
		//DM7978 - JLA - Ajout du palier
		short num_palier_ind;
        short pp_num_ind;
        short segment_num_ind;
        short origine_seg_ind;
        short destination_seg_ind;
        short longueur_seg_ind;
        short date_resa_ind;
        short canal_reservation_ind;
        short nest_level_ind;
        short train_no_ind;
        short tranche_no_ind;
        short tranche_carrier_code_ind;
        short date_depart_ind;
        short heure_depart_ind;
        short date_arrive_ind;
        short heure_arrive_ind;
        short niveau_social_ind;
        short montant_resa_ind;
        short montant_supplement_ind;
        short type_equipement_ind;
        short revenu_ind;
        short date_max_depart_ind;
        short scx_ind;
      } pRevSegmentTableInd[MAX_NBSEG_IN_BUF];

struct REV_SEGMENTS_IND pRevSegmentSingleInd[1];

struct REV_PASSAGERS_PARCOURS {
        int tcn_number;
        char date_paiement[11];
        /* varchar tarif_type[7]; */ 
struct { unsigned short len; unsigned char arr[7]; } tarif_type;

        /* varchar class_of_service[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } class_of_service;

        int pp_num;
        /* varchar passager_type[7]; */ 
struct { unsigned short len; unsigned char arr[7]; } passager_type;

        /* varchar code_tarif[5]; */ 
struct { unsigned short len; unsigned char arr[5]; } code_tarif;

        int nombre_passagers;
        int montant_unit_transport;
        int surtaxe_origine;
        int surtaxe_destination;
        int montant_domestique;
        char date_max_depart[11];
        /* varchar fare_basis_code[9]; */ 
struct { unsigned short len; unsigned char arr[9]; } fare_basis_code;

      } pRevPasParTable[MAX_NBPAP_IN_BUF];

struct REV_PASSAGERS_PARCOURS pRevPasParSingle[1];

struct REV_PASSAGERS_PARCOURS_IND {
        short tcn_number_ind;
        short date_paiement_ind;
        short tarif_type_ind;
        short class_of_service_ind;
        short pp_num_ind;
        short passager_type_ind;
        short code_tarif_ind;
        short nombre_passagers_ind;
        short montant_unit_transport_ind;
        short surtaxe_origine_ind;
        short surtaxe_destination_ind;
        short montant_domestique_ind;
        short date_max_depart_ind;
        short fare_basis_code_ind;
      } pRevPasParTableInd[MAX_NBPAP_IN_BUF];

struct REV_PASSAGERS_PARCOURS_IND pRevPasParSingleInd[1];

struct REV_TCN {
        int tcn_number;
        char date_paiement[11];
        int heure_paiement;
        /* varchar canal_paiement[4]; */ 
struct { unsigned short len; unsigned char arr[4]; } canal_paiement;

        char date_emission_physique[11];
        /* varchar canal_emission[4]; */ 
struct { unsigned short len; unsigned char arr[4]; } canal_emission;

        char date_max_depart[11];
        int annule;
        // DM7979 segmentation client taille 7 + zéro binaire \0
        /* varchar codeFCE[8]; */ 
struct { unsigned short len; unsigned char arr[8]; } codeFCE;

      } pRevTcnTable[MAX_NBTCN_IN_BUF];

struct REV_TCN pRevTcnSingle[1];

struct REV_TCN_IND {
        short tcn_number_ind;
        short date_paiement_ind;
        short heure_paiement_ind;
        short canal_paiement_ind;
        short date_emission_physique_ind;
        short canal_emission_ind;
        short date_max_depart_ind;
        short annule_ind;
        // DM7979 segmentation client taille 7 + zéro binaire \0
        short codeFCE_ind;
      } pRevTcnTableInd[MAX_NBTCN_IN_BUF];

struct REV_TCN_IND pRevTcnSingleInd[1];

struct REV_TCN_A_TRAITER {
        int tcn_number;
        char date_paiement[11];
        char date_fichier[11];
        int heure_fichier;
     } pRevTcnATraiterTable[MAX_NBTCN_IN_BUF];

struct REV_TCN_A_TRAITER pRevTcnATraiterSingle[1];

char connectstringLireVec[55];
sql_context ctxLireVec;
/* EXEC SQL END DECLARE SECTION; */ 




YmRevLireVec::YmRevLireVec()
{
  nbTCNtotal = 0;
  nbPPtotal = 0;
  nbSEGtotal = 0;
}

YmRevLireVec::~YmRevLireVec()
{
}

void YmRevLireVec::Start()
{
  // FIXME_NPI: Complement de la trace pour analyse plus fine du CR137 - A SUPPRIMER QUAND LE PROBLEME SERA RESOLU
  //cout <<DonneHeure()<<" Debut Lire Vecteurs"<<endl;

  sprintf (connectstringLireVec, "%s/%s", g_UserName, g_Password);
  /* EXEC SQL WHENEVER SQLERROR DO sql_error ((char*)"Pb YmRevLireVec", 0); */ 

  /* EXEC SQL CONTEXT ALLOCATE :ctxLireVec; */ 

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
  sqlstm.sqhstv[0] = (unsigned char  *)&ctxLireVec;
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
  if (sqlca.sqlcode < 0) sql_error("Pb YmRevLireVec",0);
}


  /* EXEC SQL CONTEXT USE :ctxLireVec; */ 

  /* EXEC SQL CONNECT :connectstringLireVec; */ 

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
  sqlstm.sqhstv[0] = (unsigned char  *)connectstringLireVec;
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
  sqlcxt(&ctxLireVec, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("Pb YmRevLireVec",0);
}


  while (g_EcrireVecEnCours || g_VTcn.size())
  { // On teste a la fois size et Ecriture en cours, au cas ou LireVec irai plus vite que EcrireVec
    purgeBufTcn();
	
    LOCK_MUTEX (&g_MutexVTcn);
    fillBufTcn();

    UNLOCK_MUTEX (&g_MutexVTcn);
    nbTcnInBuf = countPaPaSegInBuf (nbPaPaInBuf, nbSegInBuf);
    if (nbTcnInBuf)
    {
		
      //cout <<".";
      LOCK_MUTEX (&g_MutexVTcn);
      g_VTcn.erase (g_VTcn.begin(), g_VTcn.begin()+nbTcnInBuf);
      // rappel erase supprime entre first inclu et last exclu.
      UNLOCK_MUTEX (&g_MutexVTcn);
	 
      InsertTCN();
	
      InsertPassagersParcours();

      InsertSegment();
    }
    else
      sleep(6); // On attend un peu qu'il y ai du taf.
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
    sqlcxt(&ctxLireVec, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("Pb YmRevLireVec",0);
}


  }
 // cout<<endl;
//  cout<<DonneHeure()<<" Fin LireVec  TCN:"<<nbTCNtotal<<"  PassagersParcours:"<<nbPPtotal<<"  Segments:"<<nbSEGtotal<<endl;
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
  sqlcxt(&ctxLireVec, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("Pb YmRevLireVec",0);
}


  /* EXEC SQL CONTEXT FREE :ctxLireVec; */ 

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
  sqlstm.sqhstv[0] = (unsigned char  *)&ctxLireVec;
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
  if (sqlca.sqlcode < 0) sql_error("Pb YmRevLireVec",0);
}


  return;
}

 // Fait delete sur tous les YmRevTcn* contenu dans bufVTcn et vide ce vecteur.
void YmRevLireVec::purgeBufTcn()
{
  // FIXME_NPI: Complement de la trace pour analyse plus fine du CR137 - A SUPPRIMER QUAND LE PROBLEME SERA RESOLU
  //cout <<DonneHeure()<<" Debut purgeBufTcn"<<endl;
  
  int i;
  YmRevTcn* pRevTcn;
  for (i=0; i < bufVTcn.size(); i++)
  {
    pRevTcn = bufVTcn[i];
    delete pRevTcn;
  }
  bufVTcn.clear();
  
  // FIXME_NPI: Complement de la trace pour analyse plus fine du CR137 - A SUPPRIMER QUAND LE PROBLEME SERA RESOLU
  //cout <<DonneHeure()<<" Fin purgeBufTcn"<<endl;
}

//place MAX_NBTCN_IN_BUF YmRevTcn* dans le vecteur local bufVTcn (ou moins si g_VTcn en contient moins)
int YmRevLireVec::fillBufTcn()
{
  // FIXME_NPI: Complement de la trace pour analyse plus fine du CR137 - A SUPPRIMER QUAND LE PROBLEME SERA RESOLU
  //cout <<DonneHeure()<<" Debut fillBufTcn"<<endl;
  
  int maxrec = MAX_NBTCN_IN_BUF;
  if (g_VTcn.size() < MAX_NBTCN_IN_BUF)
    maxrec = g_VTcn.size();
  bufVTcn.assign (g_VTcn.begin(), g_VTcn.begin()+maxrec);
  return maxrec;
  
  // FIXME_NPI: Complement de la trace pour analyse plus fine du CR137 - A SUPPRIMER QUAND LE PROBLEME SERA RESOLU
  //cout <<DonneHeure()<<" Fin fillBufTcn"<<endl;
}

// compte le nombre de YmRevPassagersParcours et YmRevSegment dans bufVTcn, 
// mais arrete de compte lorsque l'on atteind la limite des tableaux utilise pour les insert.
// Renvoi le nombre de YmRevTcn qu'il faut effectivement conserve dans bufVTcn
int YmRevLireVec::countPaPaSegInBuf (int& nbPaPa, int& nbSeg)
{
  // FIXME_NPI: Complement de la trace pour analyse plus fine du CR137 - A SUPPRIMER QUAND LE PROBLEME SERA RESOLU
  // cout <<DonneHeure()<<" Debut countPaPaSegInBuf"<<endl;
  
  int i;
  YmRevTcn* pRevTcn;
  YmRevPassagersParcours* pPasPar;
  nbPaPa = nbSeg = 0;
  for (i=0; i < bufVTcn.size(); i++)
  {
    pRevTcn = bufVTcn[i];
    list<YmRevPassagersParcours *>::iterator iPosPa = pRevTcn->_listePassagersParcours.begin();
    list<YmRevPassagersParcours *>::iterator iFinPa = pRevTcn->_listePassagersParcours.end();
    while (iPosPa!=iFinPa)
    {
      pPasPar = *iPosPa;
      iPosPa++;
      nbPaPa++;
      nbSeg += pPasPar->_listeSegments.size();
      if ((nbSeg >= MAX_NBSEG_IN_BUF) || (nbPaPa >= MAX_NBPAP_IN_BUF))
      {
        nbSeg -= pPasPar->_listeSegments.size();
        nbPaPa --;
        // on enleve de bufVTcn les TCN exedentaires
        bufVTcn.erase (bufVTcn.begin()+i, bufVTcn.end());
		
		// FIXME_NPI: Complement de la trace pour analyse plus fine du CR137 - A SUPPRIMER QUAND LE PROBLEME SERA RESOLU
		//cout <<DonneHeure()<<" Fin countPaPaSegInBuf (TCN excendaires)"<<endl;
		
        return i;
      }
    }
  }
  
  // FIXME_NPI: Complement de la trace pour analyse plus fine du CR137 - A SUPPRIMER QUAND LE PROBLEME SERA RESOLU
  //cout <<DonneHeure()<<" Fin countPaPaSegInBuf (fin normale)"<<endl;
  
  return i;
}

void YmRevLireVec::InsertSegment()
{
  // FIXME_NPI: Complement de la trace pour analyse plus fine du CR137 - A SUPPRIMER QUAND LE PROBLEME SERA RESOLU
  //cout <<DonneHeure()<<" Debut InsertSegment"<<endl;
  
  memset (pRevSegmentTable, 0, sizeof(pRevSegmentTable));
  memset (pRevSegmentTableInd, 0, sizeof(pRevSegmentTableInd));
  int i, k;
  YmRevTcn* pRevTcn;
  YmRevPassagersParcours* pPasPar;
  YmRevSegments* pSegment;
  char datemaxdepart[11];
  string lstrdatetemp;

  k = 0;
  for (i=0; i < bufVTcn.size(); i++)
  {
    pRevTcn = bufVTcn[i];
    //
    lstrdatetemp=pRevTcn->getDateMaxDepart().substr(6,2)+'/'+pRevTcn->getDateMaxDepart().substr(4,2)+'/'+pRevTcn->getDateMaxDepart().substr(0,4);
    strcpy (datemaxdepart,lstrdatetemp.c_str() );
    //
    list<YmRevPassagersParcours *>::iterator iPosPa = pRevTcn->_listePassagersParcours.begin();
    list<YmRevPassagersParcours *>::iterator iFinPa = pRevTcn->_listePassagersParcours.end();
    int ppnum = 0;
    while (iPosPa!=iFinPa)
    {
      pPasPar = *iPosPa;
      iPosPa++;
      list<YmRevSegments *>::iterator iPosSeg = pPasPar->_listeSegments.begin();
      list<YmRevSegments *>::iterator iFinSeg = pPasPar->_listeSegments.end();
      while (iPosSeg!=iFinSeg)
      {
		//JRO IC SRO - DT 23805 - Ajout d'un flag isTRAIN initialisé à 0
		int isTrain=0;
		
        pSegment = *iPosSeg;
        iPosSeg++;
      

        pRevSegmentTable[k].tcn_number = pSegment->getTcnNumber(); 
    

        lstrdatetemp=pSegment->getDatePaiement().substr(6,2)+'/'+pSegment->getDatePaiement().substr(4,2)+'/'+pSegment->getDatePaiement().substr(0,4);
        strcpy (pRevSegmentTable[k].date_paiement,lstrdatetemp.c_str() );
        //
	

        strcpy ((char*)pRevSegmentTable[k].tarif_type.arr, pSegment->getTarifType().c_str());
        pRevSegmentTable[k].tarif_type.len = pSegment->getTarifType().size();

		

        pRevSegmentTable[k].pp_num = ppnum;
        pRevSegmentTable[k].segment_num = pSegment->getSegmentNum(); 

        strcpy ((char*)pRevSegmentTable[k].origine_seg.arr, pSegment->getOrigineSeg().c_str());
        pRevSegmentTable[k].origine_seg.len = pSegment->getOrigineSeg().size();

        strcpy ((char*)pRevSegmentTable[k].destination_seg.arr, pSegment->getDestinationSeg().c_str());
        pRevSegmentTable[k].destination_seg.len = pSegment->getDestinationSeg().size();

        pRevSegmentTable[k].longueur_seg = pSegment->getLongueurSeg(); 

        if (pSegment->getDateResa().empty())
          pRevSegmentTableInd[k].date_resa_ind = -1;
        else
        {
          //
          lstrdatetemp=pSegment->getDateResa().substr(6,2)+'/'+pSegment->getDateResa().substr(4,2)+'/'+pSegment->getDateResa().substr(0,4);
          strcpy (pRevSegmentTable[k].date_resa,lstrdatetemp.c_str() );
          //
        } 

        if (pSegment->getCanalReservation().empty())
        {
          pRevSegmentTableInd[k].canal_reservation_ind = -1;
        }
        else
        {
          strcpy ((char*)pRevSegmentTable[k].canal_reservation.arr, pSegment->getCanalReservation().c_str());
          pRevSegmentTable[k].canal_reservation.len = pSegment->getCanalReservation().size();
        }

        //DT33254

        if(pSegment->getUpgHan()==0 || (pSegment->getUpgHan()!=1 && pSegment->getUpgHan()!=2 )){
          strcpy ((char*)pRevSegmentTable[k].class_of_service.arr, pSegment->getClassOfService().c_str());
          pRevSegmentTable[k].class_of_service.len = pSegment->getClassOfService().size();
          //DM7978 - JLA - Ajout du palier
          pRevSegmentTable[k].num_palier = pSegment->getNumPalier();
        }
        else
        {
          strcpy ((char*)pRevSegmentTable[k].class_of_service.arr, pSegment->getClasseBooking().c_str());
          pRevSegmentTable[k].class_of_service.len = pSegment->getClasseBooking().size();
            pRevSegmentTable[k].num_palier = pSegment->getPalierBooking();       
        }


   
		pRevSegmentTable[k].nest_level = pSegment->getNestLevel(); 
		
        pRevSegmentTable[k].train_no = pSegment->getTrainNo(); 
		
		// JRO IC SRO DT 23805 Récupération de la date de départ
        lstrdatetemp=pSegment->getDateDepart().substr(6,2)+'/'+pSegment->getDateDepart().substr(4,2)+'/'+pSegment->getDateDepart().substr(0,4);
        strcpy (pRevSegmentTable[k].date_depart,lstrdatetemp.c_str() );

		//JRO IC SRO DT 23805

		if (pSegment->getTrancheNo() == 0) 
		{
			
			
			//Si le train a un  No de tranche en base OP correspondant à son numéro de train
			//JRO IC SRO - ANO 87361 - getNoTranche est mtn une méthode de YmRevMapTrLeg
			if (g_MapTrLeg.getNoTranche(pRevSegmentTable[k].train_no, pRevSegmentTable[k].date_depart)!=0)
			{
			
				pRevSegmentTable[k].tranche_no = g_MapTrLeg.getNoTranche(pRevSegmentTable[k].train_no, pRevSegmentTable[k].date_depart);
				pSegment->setTrancheNo(g_MapTrLeg.getNoTranche(pRevSegmentTable[k].train_no, pRevSegmentTable[k].date_depart));
			}
			
			else 
			{
				
			
				
				pRevSegmentTable[k].tranche_no = pRevSegmentTable[k].train_no;
				pSegment->setTrancheNo(pRevSegmentTable[k].train_no);
				
				//Mise à jour du flag isTrain
				isTrain = 1 ; 
			}
		}
        else{
	
			  pRevSegmentTable[k].tranche_no = pSegment->getTrancheNo();
			//FIN JRO IC SRO DT 23805
		}
		
			

		
		
        strcpy ((char*)pRevSegmentTable[k].tranche_carrier_code.arr, pSegment->getTrancheCarrierCode().c_str());
		
        pRevSegmentTable[k].tranche_carrier_code.len = pSegment->getTrancheCarrierCode().size();
        
        lstrdatetemp=pSegment->getDateDepart().substr(6,2)+'/'+pSegment->getDateDepart().substr(4,2)+'/'+pSegment->getDateDepart().substr(0,4);
        strcpy (pRevSegmentTable[k].date_depart,lstrdatetemp.c_str() );
        //


        pRevSegmentTable[k].heure_depart = atoi (pSegment->getHeureDepart().c_str());
        //cout << "        date Arrivee : " << pSegment->getDateArrivee() << endl;
        //cout << "        date max depart : " << pRevTcn->getDateMaxDepart() << endl;  
		//cout << "        heure depart : " << pSegment->getHeureDepart() << endl;  
		//cout << "        heure arrivee : " << pSegment->getHeureArrivee() << endl;  
        //cout << " date max depart convertie en datemaxdepart : " << datemaxdepart << endl;
        //
		if (pSegment->getDateArrivee().empty())
          pRevSegmentTableInd[k].date_arrive_ind = -1;
        else
        {
		  lstrdatetemp=pSegment->getDateArrivee().substr(6,2)+'/'+pSegment->getDateArrivee().substr(4,2)+'/'+pSegment->getDateArrivee().substr(0,4);
          strcpy (pRevSegmentTable[k].date_arrive,lstrdatetemp.c_str() );
		}
        //
	
		if (pSegment->getHeureArrivee().empty())
          pRevSegmentTableInd[k].heure_arrive_ind = -1;
		else
		{
		  pRevSegmentTable[k].heure_arrive = atoi (pSegment->getHeureArrivee().c_str());
		}

        //DM 7978 - JLA - Changement pas Niveau social
        if (pSegment->getNiveauSocial().empty())
          pRevSegmentTableInd[k].niveau_social_ind = -1;
        else
          pRevSegmentTable[k].niveau_social = atoi (pSegment->getNiveauSocial().c_str()); 
		//DM 7978 - JLA - Fin
        if (pSegment->getMontantResa() == 0) 
          pRevSegmentTableInd[k].montant_resa_ind = -1;
        else
          pRevSegmentTable[k].montant_resa = pSegment->getMontantResa(); 

        if (pSegment->getMontantSupplement() == 0) 
          pRevSegmentTableInd[k].montant_supplement_ind = -1;
        else
          pRevSegmentTable[k].montant_supplement = pSegment->getMontantSupplement(); 

        if (pSegment->getTypeEquipement().empty())
          pRevSegmentTableInd[k].type_equipement_ind = -1;
        else
        {
          strcpy ((char*)pRevSegmentTable[k].type_equipement.arr, pSegment->getTypeEquipement().c_str());
          pRevSegmentTable[k].type_equipement.len = pSegment->getTypeEquipement().size();
        }

        if (pSegment->getRevenu() == 0) 
          pRevSegmentTableInd[k].revenu_ind = -1;
        else
          pRevSegmentTable[k].revenu = pSegment->getRevenu(); 

        strcpy (pRevSegmentTable[k].date_max_depart, datemaxdepart);
//DM5882.1 :sous-contingentement ( scx ) pour nestlevel =0
        if (pSegment->getScx() == 0)
          pRevSegmentTableInd[k].scx_ind = -1;
        else
          pRevSegmentTable[k].scx = pSegment->getScx();
//

        AddInMapTpOD (pPasPar, pSegment,isTrain);

        k++;
	
      } // boucle sur les segments
      ppnum++;
    } // boucle sur les passagersParcours
  } // boucle sur les TCN
//DM7978 - JLA - Ajout du palier
  /* EXEC SQL WHENEVER SQLERROR GOTO err_segment_insert; */ 

  /* EXEC SQL FOR :nbSegInBuf INSERT INTO REV_SEGMENTS 
       (TCN_NUMBER, DATE_PAIEMENT, TARIF_TYPE, CLASS_OF_SERVICE, NUM_PALIER, PP_NUM, SEGMENT_NUM, ORIGINE_SEG, DESTINATION_SEG,
        LONGUEUR_SEG, DATE_RESA, CANAL_RESERVATION, NEST_LEVEL, TRAIN_NO, TRANCHE_NO, TRANCHE_CARRIER_CODE,
        DATE_DEPART, HEURE_DEPART, DATE_ARRIVEE, HEURE_ARRIVEE, niveau_social, MONTANT_RESA, MONTANT_SUPPLEMENT,
        TYPE_EQUIPEMENT, REVENU, DATE_MAX_DEPART, SCX)
       values (:pRevSegmentTable indicator :pRevSegmentTableInd); */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "insert INTO REV_SEGMENTS ( TCN_NUMBER , DATE_PAIEMENT , TAR\
IF_TYPE , CLASS_OF_SERVICE , NUM_PALIER , PP_NUM , SEGMENT_NUM , ORIGINE_SEG ,\
 DESTINATION_SEG , LONGUEUR_SEG , DATE_RESA , CANAL_RESERVATION , NEST_LEVEL ,\
 TRAIN_NO , TRANCHE_NO , TRANCHE_CARRIER_CODE , DATE_DEPART , HEURE_DEPART , D\
ATE_ARRIVEE , HEURE_ARRIVEE , niveau_social , MONTANT_RESA , MONTANT_SUPPLEMEN\
T , TYPE_EQUIPEMENT , REVENU , DATE_MAX_DEPART , SCX ) values ( :s1:s2 ,:s3:s4\
 ,:s5:s6 ,:s7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 ,:\
s21:s22 ,:s23:s24 ,:s25:s26 ,:s27:s28 ,:s29:s30 ,:s31:s32 ,:s33:s34 ,:s35:s36 \
,:s37:s38 ,:s39:s40 ,:s41:s42 ,:s43:s44 ,:s45:s46 ,:s47:s48 ,:s49:s50 ,:s51:s5\
2 ,:s53:s54  ) ";
  sqlstm.iters = (unsigned int  )nbSegInBuf;
  sqlstm.offset = (unsigned int  )104;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&pRevSegmentTable->tcn_number;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[0] = (         short *)&pRevSegmentTableInd->tcn_number_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)pRevSegmentTable->date_paiement;
  sqlstm.sqhstl[1] = (unsigned long )11;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[1] = (         short *)&pRevSegmentTableInd->date_paiement_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&pRevSegmentTable->tarif_type;
  sqlstm.sqhstl[2] = (unsigned long )9;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[2] = (         short *)&pRevSegmentTableInd->tarif_type_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&pRevSegmentTable->class_of_service;
  sqlstm.sqhstl[3] = (unsigned long )5;
  sqlstm.sqhsts[3] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[3] = (         short *)&pRevSegmentTableInd->class_of_service_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&pRevSegmentTable->num_palier;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[4] = (         short *)&pRevSegmentTableInd->num_palier_ind;
  sqlstm.sqinds[4] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&pRevSegmentTable->pp_num;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[5] = (         short *)&pRevSegmentTableInd->pp_num_ind;
  sqlstm.sqinds[5] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&pRevSegmentTable->segment_num;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[6] = (         short *)&pRevSegmentTableInd->segment_num_ind;
  sqlstm.sqinds[6] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&pRevSegmentTable->origine_seg;
  sqlstm.sqhstl[7] = (unsigned long )8;
  sqlstm.sqhsts[7] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[7] = (         short *)&pRevSegmentTableInd->origine_seg_ind;
  sqlstm.sqinds[7] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&pRevSegmentTable->destination_seg;
  sqlstm.sqhstl[8] = (unsigned long )8;
  sqlstm.sqhsts[8] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[8] = (         short *)&pRevSegmentTableInd->destination_seg_ind;
  sqlstm.sqinds[8] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&pRevSegmentTable->longueur_seg;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[9] = (         short *)&pRevSegmentTableInd->longueur_seg_ind;
  sqlstm.sqinds[9] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)pRevSegmentTable->date_resa;
  sqlstm.sqhstl[10] = (unsigned long )11;
  sqlstm.sqhsts[10] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[10] = (         short *)&pRevSegmentTableInd->date_resa_ind;
  sqlstm.sqinds[10] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&pRevSegmentTable->canal_reservation;
  sqlstm.sqhstl[11] = (unsigned long )6;
  sqlstm.sqhsts[11] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[11] = (         short *)&pRevSegmentTableInd->canal_reservation_ind;
  sqlstm.sqinds[11] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&pRevSegmentTable->nest_level;
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[12] = (         short *)&pRevSegmentTableInd->nest_level_ind;
  sqlstm.sqinds[12] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&pRevSegmentTable->train_no;
  sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[13] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[13] = (         short *)&pRevSegmentTableInd->train_no_ind;
  sqlstm.sqinds[13] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqharc[13] = (unsigned long  *)0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&pRevSegmentTable->tranche_no;
  sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[14] = (         short *)&pRevSegmentTableInd->tranche_no_ind;
  sqlstm.sqinds[14] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqharc[14] = (unsigned long  *)0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&pRevSegmentTable->tranche_carrier_code;
  sqlstm.sqhstl[15] = (unsigned long )5;
  sqlstm.sqhsts[15] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[15] = (         short *)&pRevSegmentTableInd->tranche_carrier_code_ind;
  sqlstm.sqinds[15] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqharc[15] = (unsigned long  *)0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)pRevSegmentTable->date_depart;
  sqlstm.sqhstl[16] = (unsigned long )11;
  sqlstm.sqhsts[16] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[16] = (         short *)&pRevSegmentTableInd->date_depart_ind;
  sqlstm.sqinds[16] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqharc[16] = (unsigned long  *)0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&pRevSegmentTable->heure_depart;
  sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[17] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[17] = (         short *)&pRevSegmentTableInd->heure_depart_ind;
  sqlstm.sqinds[17] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqharc[17] = (unsigned long  *)0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)pRevSegmentTable->date_arrive;
  sqlstm.sqhstl[18] = (unsigned long )11;
  sqlstm.sqhsts[18] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[18] = (         short *)&pRevSegmentTableInd->date_arrive_ind;
  sqlstm.sqinds[18] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqharc[18] = (unsigned long  *)0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)&pRevSegmentTable->heure_arrive;
  sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[19] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[19] = (         short *)&pRevSegmentTableInd->heure_arrive_ind;
  sqlstm.sqinds[19] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqharc[19] = (unsigned long  *)0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)&pRevSegmentTable->niveau_social;
  sqlstm.sqhstl[20] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[20] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[20] = (         short *)&pRevSegmentTableInd->niveau_social_ind;
  sqlstm.sqinds[20] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqharc[20] = (unsigned long  *)0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)&pRevSegmentTable->montant_resa;
  sqlstm.sqhstl[21] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[21] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[21] = (         short *)&pRevSegmentTableInd->montant_resa_ind;
  sqlstm.sqinds[21] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqharc[21] = (unsigned long  *)0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)&pRevSegmentTable->montant_supplement;
  sqlstm.sqhstl[22] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[22] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[22] = (         short *)&pRevSegmentTableInd->montant_supplement_ind;
  sqlstm.sqinds[22] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqharc[22] = (unsigned long  *)0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)&pRevSegmentTable->type_equipement;
  sqlstm.sqhstl[23] = (unsigned long )5;
  sqlstm.sqhsts[23] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[23] = (         short *)&pRevSegmentTableInd->type_equipement_ind;
  sqlstm.sqinds[23] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqharc[23] = (unsigned long  *)0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)&pRevSegmentTable->revenu;
  sqlstm.sqhstl[24] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[24] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[24] = (         short *)&pRevSegmentTableInd->revenu_ind;
  sqlstm.sqinds[24] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqharc[24] = (unsigned long  *)0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)pRevSegmentTable->date_max_depart;
  sqlstm.sqhstl[25] = (unsigned long )11;
  sqlstm.sqhsts[25] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[25] = (         short *)&pRevSegmentTableInd->date_max_depart_ind;
  sqlstm.sqinds[25] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqharc[25] = (unsigned long  *)0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)&pRevSegmentTable->scx;
  sqlstm.sqhstl[26] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[26] = (         int  )sizeof(struct REV_SEGMENTS);
  sqlstm.sqindv[26] = (         short *)&pRevSegmentTableInd->scx_ind;
  sqlstm.sqinds[26] = (         int  )sizeof(struct REV_SEGMENTS_IND);
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqharc[26] = (unsigned long  *)0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt(&ctxLireVec, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto err_segment_insert;
}


  nbSEGtotal += nbSegInBuf;
  /* EXEC SQL COMMIT WORK; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )227;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt(&ctxLireVec, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto err_segment_insert;
}


  return;

err_segment_insert:
  cerr << "ERROR BULK INSERT SEGMENT: \n";
  char szMess[71];
  strncpy(szMess,sqlca.sqlerrm.sqlerrmc,sqlca.sqlerrm.sqlerrml);
  szMess[sqlca.sqlerrm.sqlerrml]='\0';
  cerr << szMess << "\n";
  /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

  /* EXEC SQL ROLLBACK WORK; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )242;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt(&ctxLireVec, &sqlctx, &sqlstm, &sqlfpn);
}



  //cout<<"insertion ligne a ligne de "<<nbSegInBuf<<" SEGMENTS"<<endl;
  int j = 0;
  for (j = 0; j < nbSegInBuf; j++)
  {
  //DM7978 - JLA - Ajout du palier
    /* EXEC SQL WHENEVER SQLERROR DO sql_warn ("SEGMENTS", pRevSegmentTable[j].tcn_number, nbSEGtotal); */ 

    pRevSegmentSingle[0] = pRevSegmentTable[j];
    pRevSegmentSingleInd[0] = pRevSegmentTableInd[j];

    /* EXEC SQL FOR 1 INSERT INTO REV_SEGMENTS 
       (TCN_NUMBER, DATE_PAIEMENT, TARIF_TYPE, CLASS_OF_SERVICE, NUM_PALIER, PP_NUM, SEGMENT_NUM, ORIGINE_SEG, DESTINATION_SEG,
        LONGUEUR_SEG, DATE_RESA, CANAL_RESERVATION, NEST_LEVEL, TRAIN_NO, TRANCHE_NO, TRANCHE_CARRIER_CODE,
        DATE_DEPART, HEURE_DEPART, DATE_ARRIVEE, HEURE_ARRIVEE, niveau_social, MONTANT_RESA, MONTANT_SUPPLEMENT,
        TYPE_EQUIPEMENT, REVENU, DATE_MAX_DEPART, SCX)
       values (:pRevSegmentSingle indicator :pRevSegmentSingleInd); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 27;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert INTO REV_SEGMENTS ( TCN_NUMBER , DATE_PAIEMENT , T\
ARIF_TYPE , CLASS_OF_SERVICE , NUM_PALIER , PP_NUM , SEGMENT_NUM , ORIGINE_SEG\
 , DESTINATION_SEG , LONGUEUR_SEG , DATE_RESA , CANAL_RESERVATION , NEST_LEVEL\
 , TRAIN_NO , TRANCHE_NO , TRANCHE_CARRIER_CODE , DATE_DEPART , HEURE_DEPART ,\
 DATE_ARRIVEE , HEURE_ARRIVEE , niveau_social , MONTANT_RESA , MONTANT_SUPPLEM\
ENT , TYPE_EQUIPEMENT , REVENU , DATE_MAX_DEPART , SCX ) values ( :s1:s2 ,:s3:\
s4 ,:s5:s6 ,:s7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19:s20 \
,:s21:s22 ,:s23:s24 ,:s25:s26 ,:s27:s28 ,:s29:s30 ,:s31:s32 ,:s33:s34 ,:s35:s3\
6 ,:s37:s38 ,:s39:s40 ,:s41:s42 ,:s43:s44 ,:s45:s46 ,:s47:s48 ,:s49:s50 ,:s51:\
s52 ,:s53:s54  ) ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )257;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&pRevSegmentSingle->tcn_number;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[0] = (         short *)&pRevSegmentSingleInd->tcn_number_ind;
    sqlstm.sqinds[0] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)pRevSegmentSingle->date_paiement;
    sqlstm.sqhstl[1] = (unsigned long )11;
    sqlstm.sqhsts[1] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[1] = (         short *)&pRevSegmentSingleInd->date_paiement_ind;
    sqlstm.sqinds[1] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&pRevSegmentSingle->tarif_type;
    sqlstm.sqhstl[2] = (unsigned long )9;
    sqlstm.sqhsts[2] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[2] = (         short *)&pRevSegmentSingleInd->tarif_type_ind;
    sqlstm.sqinds[2] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&pRevSegmentSingle->class_of_service;
    sqlstm.sqhstl[3] = (unsigned long )5;
    sqlstm.sqhsts[3] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[3] = (         short *)&pRevSegmentSingleInd->class_of_service_ind;
    sqlstm.sqinds[3] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&pRevSegmentSingle->num_palier;
    sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[4] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[4] = (         short *)&pRevSegmentSingleInd->num_palier_ind;
    sqlstm.sqinds[4] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqharc[4] = (unsigned long  *)0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&pRevSegmentSingle->pp_num;
    sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[5] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[5] = (         short *)&pRevSegmentSingleInd->pp_num_ind;
    sqlstm.sqinds[5] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqharc[5] = (unsigned long  *)0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&pRevSegmentSingle->segment_num;
    sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[6] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[6] = (         short *)&pRevSegmentSingleInd->segment_num_ind;
    sqlstm.sqinds[6] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqharc[6] = (unsigned long  *)0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)&pRevSegmentSingle->origine_seg;
    sqlstm.sqhstl[7] = (unsigned long )8;
    sqlstm.sqhsts[7] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[7] = (         short *)&pRevSegmentSingleInd->origine_seg_ind;
    sqlstm.sqinds[7] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqharc[7] = (unsigned long  *)0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)&pRevSegmentSingle->destination_seg;
    sqlstm.sqhstl[8] = (unsigned long )8;
    sqlstm.sqhsts[8] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[8] = (         short *)&pRevSegmentSingleInd->destination_seg_ind;
    sqlstm.sqinds[8] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqharc[8] = (unsigned long  *)0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)&pRevSegmentSingle->longueur_seg;
    sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[9] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[9] = (         short *)&pRevSegmentSingleInd->longueur_seg_ind;
    sqlstm.sqinds[9] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqharc[9] = (unsigned long  *)0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)pRevSegmentSingle->date_resa;
    sqlstm.sqhstl[10] = (unsigned long )11;
    sqlstm.sqhsts[10] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[10] = (         short *)&pRevSegmentSingleInd->date_resa_ind;
    sqlstm.sqinds[10] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqharc[10] = (unsigned long  *)0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (unsigned char  *)&pRevSegmentSingle->canal_reservation;
    sqlstm.sqhstl[11] = (unsigned long )6;
    sqlstm.sqhsts[11] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[11] = (         short *)&pRevSegmentSingleInd->canal_reservation_ind;
    sqlstm.sqinds[11] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[11] = (unsigned long )0;
    sqlstm.sqharc[11] = (unsigned long  *)0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (unsigned char  *)&pRevSegmentSingle->nest_level;
    sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[12] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[12] = (         short *)&pRevSegmentSingleInd->nest_level_ind;
    sqlstm.sqinds[12] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[12] = (unsigned long )0;
    sqlstm.sqharc[12] = (unsigned long  *)0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (unsigned char  *)&pRevSegmentSingle->train_no;
    sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[13] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[13] = (         short *)&pRevSegmentSingleInd->train_no_ind;
    sqlstm.sqinds[13] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[13] = (unsigned long )0;
    sqlstm.sqharc[13] = (unsigned long  *)0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (unsigned char  *)&pRevSegmentSingle->tranche_no;
    sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[14] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[14] = (         short *)&pRevSegmentSingleInd->tranche_no_ind;
    sqlstm.sqinds[14] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[14] = (unsigned long )0;
    sqlstm.sqharc[14] = (unsigned long  *)0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (unsigned char  *)&pRevSegmentSingle->tranche_carrier_code;
    sqlstm.sqhstl[15] = (unsigned long )5;
    sqlstm.sqhsts[15] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[15] = (         short *)&pRevSegmentSingleInd->tranche_carrier_code_ind;
    sqlstm.sqinds[15] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[15] = (unsigned long )0;
    sqlstm.sqharc[15] = (unsigned long  *)0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (unsigned char  *)pRevSegmentSingle->date_depart;
    sqlstm.sqhstl[16] = (unsigned long )11;
    sqlstm.sqhsts[16] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[16] = (         short *)&pRevSegmentSingleInd->date_depart_ind;
    sqlstm.sqinds[16] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[16] = (unsigned long )0;
    sqlstm.sqharc[16] = (unsigned long  *)0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (unsigned char  *)&pRevSegmentSingle->heure_depart;
    sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[17] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[17] = (         short *)&pRevSegmentSingleInd->heure_depart_ind;
    sqlstm.sqinds[17] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[17] = (unsigned long )0;
    sqlstm.sqharc[17] = (unsigned long  *)0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (unsigned char  *)pRevSegmentSingle->date_arrive;
    sqlstm.sqhstl[18] = (unsigned long )11;
    sqlstm.sqhsts[18] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[18] = (         short *)&pRevSegmentSingleInd->date_arrive_ind;
    sqlstm.sqinds[18] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[18] = (unsigned long )0;
    sqlstm.sqharc[18] = (unsigned long  *)0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (unsigned char  *)&pRevSegmentSingle->heure_arrive;
    sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[19] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[19] = (         short *)&pRevSegmentSingleInd->heure_arrive_ind;
    sqlstm.sqinds[19] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[19] = (unsigned long )0;
    sqlstm.sqharc[19] = (unsigned long  *)0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (unsigned char  *)&pRevSegmentSingle->niveau_social;
    sqlstm.sqhstl[20] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[20] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[20] = (         short *)&pRevSegmentSingleInd->niveau_social_ind;
    sqlstm.sqinds[20] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[20] = (unsigned long )0;
    sqlstm.sqharc[20] = (unsigned long  *)0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (unsigned char  *)&pRevSegmentSingle->montant_resa;
    sqlstm.sqhstl[21] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[21] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[21] = (         short *)&pRevSegmentSingleInd->montant_resa_ind;
    sqlstm.sqinds[21] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[21] = (unsigned long )0;
    sqlstm.sqharc[21] = (unsigned long  *)0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (unsigned char  *)&pRevSegmentSingle->montant_supplement;
    sqlstm.sqhstl[22] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[22] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[22] = (         short *)&pRevSegmentSingleInd->montant_supplement_ind;
    sqlstm.sqinds[22] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[22] = (unsigned long )0;
    sqlstm.sqharc[22] = (unsigned long  *)0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (unsigned char  *)&pRevSegmentSingle->type_equipement;
    sqlstm.sqhstl[23] = (unsigned long )5;
    sqlstm.sqhsts[23] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[23] = (         short *)&pRevSegmentSingleInd->type_equipement_ind;
    sqlstm.sqinds[23] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[23] = (unsigned long )0;
    sqlstm.sqharc[23] = (unsigned long  *)0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (unsigned char  *)&pRevSegmentSingle->revenu;
    sqlstm.sqhstl[24] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[24] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[24] = (         short *)&pRevSegmentSingleInd->revenu_ind;
    sqlstm.sqinds[24] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[24] = (unsigned long )0;
    sqlstm.sqharc[24] = (unsigned long  *)0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (unsigned char  *)pRevSegmentSingle->date_max_depart;
    sqlstm.sqhstl[25] = (unsigned long )11;
    sqlstm.sqhsts[25] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[25] = (         short *)&pRevSegmentSingleInd->date_max_depart_ind;
    sqlstm.sqinds[25] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[25] = (unsigned long )0;
    sqlstm.sqharc[25] = (unsigned long  *)0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (unsigned char  *)&pRevSegmentSingle->scx;
    sqlstm.sqhstl[26] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[26] = (         int  )sizeof(struct REV_SEGMENTS);
    sqlstm.sqindv[26] = (         short *)&pRevSegmentSingleInd->scx_ind;
    sqlstm.sqinds[26] = (         int  )sizeof(struct REV_SEGMENTS_IND);
    sqlstm.sqharm[26] = (unsigned long )0;
    sqlstm.sqharc[26] = (unsigned long  *)0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt(&ctxLireVec, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_warn("SEGMENTS",(pRevSegmentTable[j].tcn_number),nbSEGtotal);
}


    nbSEGtotal ++;
  }
  /* EXEC SQL COMMIT WORK; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )380;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt(&ctxLireVec, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_warn("SEGMENTS",(pRevSegmentTable[j].tcn_number),nbSEGtotal);
}


  
  // FIXME_NPI: Complement de la trace pour analyse plus fine du CR137 - A SUPPRIMER QUAND LE PROBLEME SERA RESOLU
  // cout <<DonneHeure()<<" Fin InsertSegment"<<endl;
}


// Insertion dans la table REV_PASSAGERS_PARCOURS avec FBC
void YmRevLireVec::InsertPassagersParcours()
{
  // FIXME_NPI: Complement de la trace pour analyse plus fine du CR137 - A SUPPRIMER QUAND LE PROBLEME SERA RESOLU
  // cout <<DonneHeure()<<" Debut InsertPassagersParcours"<<endl;
  
  memset (pRevPasParTable, 0, sizeof(pRevPasParTable));
  memset (pRevPasParTableInd, 0, sizeof(pRevPasParTableInd));
  int i, k;
  YmRevTcn* pRevTcn;
  YmRevPassagersParcours* pPasPar;
  char datemaxdepart[11];
  string lstrdatetemp;
  k = 0;
  for (i=0; i < bufVTcn.size(); i++)
  {
    pRevTcn = bufVTcn[i];
    //
    lstrdatetemp=pRevTcn->getDateMaxDepart().substr(6,2)+'/'+pRevTcn->getDateMaxDepart().substr(4,2)+'/'+pRevTcn->getDateMaxDepart().substr(0,4);
    strcpy (datemaxdepart,lstrdatetemp.c_str() );
    //

    list<YmRevPassagersParcours *>::iterator iPosPa = pRevTcn->_listePassagersParcours.begin();
    list<YmRevPassagersParcours *>::iterator iFinPa = pRevTcn->_listePassagersParcours.end();
    string szTarifType;
    int ppnum = 0;
    while (iPosPa!=iFinPa)
    {
      pPasPar = *iPosPa;
      iPosPa++;
      pRevPasParTable[k].tcn_number = pPasPar->getTcnNumber(); 
      //
      lstrdatetemp=pPasPar->getDatePaiement().substr(6,2)+'/'+pPasPar->getDatePaiement().substr(4,2)+'/'+pPasPar->getDatePaiement().substr(0,4);
      strcpy (pRevPasParTable[k].date_paiement,lstrdatetemp.c_str() );
      //


      strcpy ((char*)pRevPasParTable[k].tarif_type.arr, pPasPar->getTarifType().c_str());
      pRevPasParTable[k].tarif_type.len = pPasPar->getTarifType().size();



        //DT33254

        if(pPasPar->getUpgHan()==0 || (pPasPar->getUpgHan()!=1 && pPasPar->getUpgHan()!=2 )){
          strcpy ((char*)pRevPasParTable[k].class_of_service.arr, pPasPar->getClassOfService().c_str());
          pRevPasParTable[k].class_of_service.len = pPasPar->getClassOfService().size();
        }else{
          strcpy ((char*)pRevPasParTable[k].class_of_service.arr, pPasPar->getClasseBooking().c_str());
          pRevPasParTable[k].class_of_service.len = pPasPar->getClasseBooking().size();
        }

      pRevPasParTable[k].pp_num = ppnum;
      ppnum++;

      strcpy ((char*)pRevPasParTable[k].passager_type.arr, pPasPar->getPassagerType().c_str());
      pRevPasParTable[k].passager_type.len = pPasPar->getPassagerType().size();

      if (pPasPar->getCodeTarif().empty())
        pRevPasParTableInd[k].code_tarif_ind = -1;
      else
      {
        strcpy ((char*)pRevPasParTable[k].code_tarif.arr, pPasPar->getCodeTarif().c_str());
        pRevPasParTable[k].code_tarif.len = pPasPar->getCodeTarif().size();
      }

      if ((pPasPar->getFareBasisCode().empty()) || (!strcmp (g_Client, "SN") && !g_forceFBC))
        pRevPasParTableInd[k].fare_basis_code_ind = -1;
      else
      {
        strcpy ((char*)pRevPasParTable[k].fare_basis_code.arr, pPasPar->getFareBasisCode().c_str());
        pRevPasParTable[k].fare_basis_code.len = pPasPar->getFareBasisCode().size();
      }

      pRevPasParTable[k].nombre_passagers = pPasPar->getNombrePassagers(); 
      
      if (pPasPar->getMontantUnitTransport() == 0)
        pRevPasParTableInd[k].montant_unit_transport_ind = -1;
      else
        pRevPasParTable[k].montant_unit_transport = pPasPar->getMontantUnitTransport(); 

      if (pPasPar->getSurtaxeOrigine() == 0)
        pRevPasParTableInd[k].surtaxe_origine_ind = -1;
      else
        pRevPasParTable[k].surtaxe_origine = pPasPar->getSurtaxeOrigine(); 

      if (pPasPar->getSurtaxeDestination() == 0)
        pRevPasParTableInd[k].surtaxe_destination_ind = -1;
      else
        pRevPasParTable[k].surtaxe_destination = pPasPar->getSurtaxeDestination(); 

      if (pPasPar->getMontantDomestique() == 0)
        pRevPasParTableInd[k].montant_domestique_ind = -1;
      else
        pRevPasParTable[k].montant_domestique = pPasPar->getMontantDomestique(); 

      strcpy (pRevPasParTable[k].date_max_depart, datemaxdepart);

      k++;
    } //boucle sur passagersParcours
  } // boucle sur TCN

  /* EXEC SQL WHENEVER SQLERROR GOTO err_paspar_insert; */ 

  /* EXEC SQL FOR :nbPaPaInBuf INSERT INTO REV_PASSAGERS_PARCOURS 
       (TCN_NUMBER, DATE_PAIEMENT, TARIF_TYPE, CLASS_OF_SERVICE, PP_NUM, PASSAGER_TYPE, CODE_TARIF, NOMBRE_PASSAGERS,
        MONTANT_UNIT_TRANSPORT, SURTAXE_ORIGINE, SURTAXE_DESTINATION, MONTANT_DOMESTIQUE, DATE_MAX_DEPART, FARE_BASIS_CODE)
       values (:pRevPasParTable indicator :pRevPasParTableInd); */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "insert INTO REV_PASSAGERS_PARCOURS ( TCN_NUMBER , DATE_PAIE\
MENT , TARIF_TYPE , CLASS_OF_SERVICE , PP_NUM , PASSAGER_TYPE , CODE_TARIF , N\
OMBRE_PASSAGERS , MONTANT_UNIT_TRANSPORT , SURTAXE_ORIGINE , SURTAXE_DESTINATI\
ON , MONTANT_DOMESTIQUE , DATE_MAX_DEPART , FARE_BASIS_CODE ) values ( :s1:s2 \
,:s3:s4 ,:s5:s6 ,:s7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s19\
:s20 ,:s21:s22 ,:s23:s24 ,:s25:s26 ,:s27:s28  ) ";
  sqlstm.iters = (unsigned int  )nbPaPaInBuf;
  sqlstm.offset = (unsigned int  )395;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&pRevPasParTable->tcn_number;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
  sqlstm.sqindv[0] = (         short *)&pRevPasParTableInd->tcn_number_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)pRevPasParTable->date_paiement;
  sqlstm.sqhstl[1] = (unsigned long )11;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
  sqlstm.sqindv[1] = (         short *)&pRevPasParTableInd->date_paiement_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&pRevPasParTable->tarif_type;
  sqlstm.sqhstl[2] = (unsigned long )9;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
  sqlstm.sqindv[2] = (         short *)&pRevPasParTableInd->tarif_type_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&pRevPasParTable->class_of_service;
  sqlstm.sqhstl[3] = (unsigned long )5;
  sqlstm.sqhsts[3] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
  sqlstm.sqindv[3] = (         short *)&pRevPasParTableInd->class_of_service_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&pRevPasParTable->pp_num;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
  sqlstm.sqindv[4] = (         short *)&pRevPasParTableInd->pp_num_ind;
  sqlstm.sqinds[4] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&pRevPasParTable->passager_type;
  sqlstm.sqhstl[5] = (unsigned long )9;
  sqlstm.sqhsts[5] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
  sqlstm.sqindv[5] = (         short *)&pRevPasParTableInd->passager_type_ind;
  sqlstm.sqinds[5] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&pRevPasParTable->code_tarif;
  sqlstm.sqhstl[6] = (unsigned long )7;
  sqlstm.sqhsts[6] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
  sqlstm.sqindv[6] = (         short *)&pRevPasParTableInd->code_tarif_ind;
  sqlstm.sqinds[6] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&pRevPasParTable->nombre_passagers;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
  sqlstm.sqindv[7] = (         short *)&pRevPasParTableInd->nombre_passagers_ind;
  sqlstm.sqinds[7] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&pRevPasParTable->montant_unit_transport;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
  sqlstm.sqindv[8] = (         short *)&pRevPasParTableInd->montant_unit_transport_ind;
  sqlstm.sqinds[8] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&pRevPasParTable->surtaxe_origine;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
  sqlstm.sqindv[9] = (         short *)&pRevPasParTableInd->surtaxe_origine_ind;
  sqlstm.sqinds[9] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqharc[9] = (unsigned long  *)0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&pRevPasParTable->surtaxe_destination;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
  sqlstm.sqindv[10] = (         short *)&pRevPasParTableInd->surtaxe_destination_ind;
  sqlstm.sqinds[10] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqharc[10] = (unsigned long  *)0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&pRevPasParTable->montant_domestique;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
  sqlstm.sqindv[11] = (         short *)&pRevPasParTableInd->montant_domestique_ind;
  sqlstm.sqinds[11] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqharc[11] = (unsigned long  *)0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)pRevPasParTable->date_max_depart;
  sqlstm.sqhstl[12] = (unsigned long )11;
  sqlstm.sqhsts[12] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
  sqlstm.sqindv[12] = (         short *)&pRevPasParTableInd->date_max_depart_ind;
  sqlstm.sqinds[12] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqharc[12] = (unsigned long  *)0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&pRevPasParTable->fare_basis_code;
  sqlstm.sqhstl[13] = (unsigned long )11;
  sqlstm.sqhsts[13] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
  sqlstm.sqindv[13] = (         short *)&pRevPasParTableInd->fare_basis_code_ind;
  sqlstm.sqinds[13] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
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
  sqlcxt(&ctxLireVec, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto err_paspar_insert;
}


  nbPPtotal += nbPaPaInBuf;
  /* EXEC SQL COMMIT WORK; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )466;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt(&ctxLireVec, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto err_paspar_insert;
}


  return;

err_paspar_insert:
  cerr << "ERROR BULK INSERT PASSAGERS PARCOURS: \n";
  char szMess[71];
  strncpy(szMess,sqlca.sqlerrm.sqlerrmc,sqlca.sqlerrm.sqlerrml);
  szMess[sqlca.sqlerrm.sqlerrml]='\0';
  cerr << szMess << "\n";
  /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

  /* EXEC SQL ROLLBACK WORK; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )481;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt(&ctxLireVec, &sqlctx, &sqlstm, &sqlfpn);
}



  //cout<<"insertion ligne a ligne de "<<nbPaPaInBuf<<" PASSAGERS PARCOURS"<<endl;
  int j = 0;
  for (j = 0; j < nbPaPaInBuf; j++)
  {
    /* EXEC SQL WHENEVER SQLERROR DO sql_warn ("PASSAGERS_PARCOURS", pRevPasParTable[j].tcn_number, nbPPtotal); */ 

    pRevPasParSingle[0] = pRevPasParTable[j];
    pRevPasParSingleInd[0] = pRevPasParTableInd[j];
    /* EXEC SQL FOR 1 INSERT INTO REV_PASSAGERS_PARCOURS 
       (TCN_NUMBER, DATE_PAIEMENT, TARIF_TYPE, CLASS_OF_SERVICE, PP_NUM, PASSAGER_TYPE, CODE_TARIF, NOMBRE_PASSAGERS,
        MONTANT_UNIT_TRANSPORT, SURTAXE_ORIGINE, SURTAXE_DESTINATION, MONTANT_DOMESTIQUE, DATE_MAX_DEPART, FARE_BASIS_CODE)
       values (:pRevPasParSingle indicator :pRevPasParSingleInd); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 27;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert INTO REV_PASSAGERS_PARCOURS ( TCN_NUMBER , DATE_PA\
IEMENT , TARIF_TYPE , CLASS_OF_SERVICE , PP_NUM , PASSAGER_TYPE , CODE_TARIF ,\
 NOMBRE_PASSAGERS , MONTANT_UNIT_TRANSPORT , SURTAXE_ORIGINE , SURTAXE_DESTINA\
TION , MONTANT_DOMESTIQUE , DATE_MAX_DEPART , FARE_BASIS_CODE ) values ( :s1:s\
2 ,:s3:s4 ,:s5:s6 ,:s7:s8 ,:s9:s10 ,:s11:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18 ,:s\
19:s20 ,:s21:s22 ,:s23:s24 ,:s25:s26 ,:s27:s28  ) ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )496;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&pRevPasParSingle->tcn_number;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
    sqlstm.sqindv[0] = (         short *)&pRevPasParSingleInd->tcn_number_ind;
    sqlstm.sqinds[0] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)pRevPasParSingle->date_paiement;
    sqlstm.sqhstl[1] = (unsigned long )11;
    sqlstm.sqhsts[1] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
    sqlstm.sqindv[1] = (         short *)&pRevPasParSingleInd->date_paiement_ind;
    sqlstm.sqinds[1] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&pRevPasParSingle->tarif_type;
    sqlstm.sqhstl[2] = (unsigned long )9;
    sqlstm.sqhsts[2] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
    sqlstm.sqindv[2] = (         short *)&pRevPasParSingleInd->tarif_type_ind;
    sqlstm.sqinds[2] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&pRevPasParSingle->class_of_service;
    sqlstm.sqhstl[3] = (unsigned long )5;
    sqlstm.sqhsts[3] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
    sqlstm.sqindv[3] = (         short *)&pRevPasParSingleInd->class_of_service_ind;
    sqlstm.sqinds[3] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&pRevPasParSingle->pp_num;
    sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[4] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
    sqlstm.sqindv[4] = (         short *)&pRevPasParSingleInd->pp_num_ind;
    sqlstm.sqinds[4] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqharc[4] = (unsigned long  *)0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&pRevPasParSingle->passager_type;
    sqlstm.sqhstl[5] = (unsigned long )9;
    sqlstm.sqhsts[5] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
    sqlstm.sqindv[5] = (         short *)&pRevPasParSingleInd->passager_type_ind;
    sqlstm.sqinds[5] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqharc[5] = (unsigned long  *)0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&pRevPasParSingle->code_tarif;
    sqlstm.sqhstl[6] = (unsigned long )7;
    sqlstm.sqhsts[6] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
    sqlstm.sqindv[6] = (         short *)&pRevPasParSingleInd->code_tarif_ind;
    sqlstm.sqinds[6] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqharc[6] = (unsigned long  *)0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)&pRevPasParSingle->nombre_passagers;
    sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[7] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
    sqlstm.sqindv[7] = (         short *)&pRevPasParSingleInd->nombre_passagers_ind;
    sqlstm.sqinds[7] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqharc[7] = (unsigned long  *)0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)&pRevPasParSingle->montant_unit_transport;
    sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[8] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
    sqlstm.sqindv[8] = (         short *)&pRevPasParSingleInd->montant_unit_transport_ind;
    sqlstm.sqinds[8] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqharc[8] = (unsigned long  *)0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)&pRevPasParSingle->surtaxe_origine;
    sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[9] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
    sqlstm.sqindv[9] = (         short *)&pRevPasParSingleInd->surtaxe_origine_ind;
    sqlstm.sqinds[9] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqharc[9] = (unsigned long  *)0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)&pRevPasParSingle->surtaxe_destination;
    sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[10] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
    sqlstm.sqindv[10] = (         short *)&pRevPasParSingleInd->surtaxe_destination_ind;
    sqlstm.sqinds[10] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqharc[10] = (unsigned long  *)0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (unsigned char  *)&pRevPasParSingle->montant_domestique;
    sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[11] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
    sqlstm.sqindv[11] = (         short *)&pRevPasParSingleInd->montant_domestique_ind;
    sqlstm.sqinds[11] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
    sqlstm.sqharm[11] = (unsigned long )0;
    sqlstm.sqharc[11] = (unsigned long  *)0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (unsigned char  *)pRevPasParSingle->date_max_depart;
    sqlstm.sqhstl[12] = (unsigned long )11;
    sqlstm.sqhsts[12] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
    sqlstm.sqindv[12] = (         short *)&pRevPasParSingleInd->date_max_depart_ind;
    sqlstm.sqinds[12] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
    sqlstm.sqharm[12] = (unsigned long )0;
    sqlstm.sqharc[12] = (unsigned long  *)0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (unsigned char  *)&pRevPasParSingle->fare_basis_code;
    sqlstm.sqhstl[13] = (unsigned long )11;
    sqlstm.sqhsts[13] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS);
    sqlstm.sqindv[13] = (         short *)&pRevPasParSingleInd->fare_basis_code_ind;
    sqlstm.sqinds[13] = (         int  )sizeof(struct REV_PASSAGERS_PARCOURS_IND);
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
    sqlcxt(&ctxLireVec, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_warn("PASSAGERS_PARCOURS",(pRevPasParTable[j].tcn_number),nbPPtotal);
}


    nbPPtotal ++;
  }
  /* EXEC SQL COMMIT WORK; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )567;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt(&ctxLireVec, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_warn("PASSAGERS_PARCOURS",(pRevPasParTable[j].tcn_number),nbPPtotal);
}


  
  // FIXME_NPI: Complement de la trace pour analyse plus fine du CR137 - A SUPPRIMER QUAND LE PROBLEME SERA RESOLU
  // cout <<DonneHeure()<<" Fin InsertPassagersParcours"<<endl;
}

// Insertion dans la table REV_TCN
void YmRevLireVec::InsertTCN()
{
  // FIXME_NPI: Complement de la trace pour analyse plus fine du CR137 - A SUPPRIMER QUAND LE PROBLEME SERA RESOLU
  //cout <<DonneHeure()<<" Debut InsertTCN"<<endl;
  
  memset (pRevTcnTable, 0, sizeof(pRevTcnTable));
  memset (pRevTcnTableInd, 0, sizeof(pRevTcnTableInd));
  memset (pRevTcnATraiterTable, 0, sizeof(pRevTcnATraiterTable));
  int i, k;
  string lstrdatetemp;
  YmRevTcn* pRevTcn;
  k = 0;
  for (i=0; i < bufVTcn.size(); i++)
  {
    pRevTcn = bufVTcn[i];

	
    pRevTcnATraiterTable[k].tcn_number = pRevTcn->getTcnNumber(); 

    //

    lstrdatetemp=pRevTcn->getDatePaiement().substr(6,2)+'/'+pRevTcn->getDatePaiement().substr(4,2)+'/'+pRevTcn->getDatePaiement().substr(0,4);
    strcpy (pRevTcnATraiterTable[k].date_paiement,lstrdatetemp.c_str() );
    
	
    strcpy (pRevTcnATraiterTable[k].date_fichier, g_szDateFichier);
    pRevTcnATraiterTable[k].heure_fichier = g_HeureFichier;

    pRevTcnTable[k].tcn_number = pRevTcn->getTcnNumber(); 
    //
    strcpy (pRevTcnTable[k].date_paiement,lstrdatetemp.c_str() );
    //

    pRevTcnTable[k].heure_paiement = atoi (pRevTcn->getHeurePaiement().c_str()); 

	
    strcpy ((char*)pRevTcnTable[k].canal_paiement.arr, pRevTcn->getCanalPaiement().c_str());
    pRevTcnTable[k].canal_paiement.len = pRevTcn->getCanalPaiement().size();


    if (pRevTcn->getDateEmissionPhysique().empty())
      pRevTcnTableInd[k].date_emission_physique_ind = -1;
    else
    {
      //
      lstrdatetemp=pRevTcn->getDateEmissionPhysique().substr(6,2)+'/'+pRevTcn->getDateEmissionPhysique().substr(4,2)+'/'+pRevTcn->getDateEmissionPhysique().substr(0,4);
      strcpy (pRevTcnTable[k].date_emission_physique,lstrdatetemp.c_str() );
      //
    }

    if (pRevTcn->getCanalEmission().empty())
      pRevTcnTableInd[k].canal_emission_ind = -1;
    else
    {
      strcpy ((char*)pRevTcnTable[k].canal_emission.arr, pRevTcn->getCanalEmission().c_str());
      pRevTcnTable[k].canal_emission.len = pRevTcn->getCanalEmission().size();
    }
    //
	

	if (!pRevTcn->getDateMaxDepart().empty())
	{
		lstrdatetemp=pRevTcn->getDateMaxDepart().substr(6,2)+'/'+pRevTcn->getDateMaxDepart().substr(4,2)+'/'+pRevTcn->getDateMaxDepart().substr(0,4);
		strcpy (pRevTcnTable[k].date_max_depart,lstrdatetemp.c_str() );
	}
	else {
	
		strcpy (pRevTcnTable[k].date_max_depart,"" );
    
	}//
	

    pRevTcnTableInd[k].annule_ind = -1;
   
    // DM7979 segmentation client : ajout code FCE
    if (pRevTcn->getCodeFCE().empty())
      pRevTcnTableInd[k].codeFCE_ind = -1;
    else
    {
      strcpy ((char*)pRevTcnTable[k].codeFCE.arr, pRevTcn->getCodeFCE().c_str());
      pRevTcnTable[k].codeFCE.len = pRevTcn->getCodeFCE().size();
    }
  
	
    k++;
  }

 
  /* EXEC SQL WHENEVER SQLERROR GOTO err_tcn_insert; */ 

  /* EXEC SQL FOR :nbTcnInBuf INSERT INTO REV_TCN_A_TRAITER
       (TCN_NUMBER_AT, DATE_PAIEMENT_AT, DATE_FICHIER, HEURE_FICHIER)
       values (:pRevTcnATraiterTable); */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "insert INTO REV_TCN_A_TRAITER ( TCN_NUMBER_AT , DATE_PAIEME\
NT_AT , DATE_FICHIER , HEURE_FICHIER ) values ( :s1 ,:s2 ,:s3 ,:s4  ) ";
  sqlstm.iters = (unsigned int  )nbTcnInBuf;
  sqlstm.offset = (unsigned int  )582;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&pRevTcnATraiterTable->tcn_number;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct REV_TCN_A_TRAITER);
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)pRevTcnATraiterTable->date_paiement;
  sqlstm.sqhstl[1] = (unsigned long )11;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct REV_TCN_A_TRAITER);
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)pRevTcnATraiterTable->date_fichier;
  sqlstm.sqhstl[2] = (unsigned long )11;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct REV_TCN_A_TRAITER);
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&pRevTcnATraiterTable->heure_fichier;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(struct REV_TCN_A_TRAITER);
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
  sqlcxt(&ctxLireVec, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto err_tcn_insert;
}



  /* EXEC SQL FOR :nbTcnInBuf INSERT INTO REV_TCN
        // DM7979 segmentation client : Ajout champ FCE
       (TCN_NUMBER, DATE_PAIEMENT, HEURE_PAIEMENT, CANAL_PAIEMENT, DATE_EMISSION_PHYSIQUE, CANAL_EMISSION,
        DATE_MAX_DEPART, ANNULE, FCE)
       values (:pRevTcnTable indicator :pRevTcnTableInd); */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "insert INTO REV_TCN ( TCN_NUMBER , DATE_PAIEMENT , HEURE_PA\
IEMENT , CANAL_PAIEMENT , DATE_EMISSION_PHYSIQUE , CANAL_EMISSION , DATE_MAX_D\
EPART , ANNULE , FCE ) values ( :s1:s2 ,:s3:s4 ,:s5:s6 ,:s7:s8 ,:s9:s10 ,:s11:\
s12 ,:s13:s14 ,:s15:s16 ,:s17:s18  ) ";
  sqlstm.iters = (unsigned int  )nbTcnInBuf;
  sqlstm.offset = (unsigned int  )613;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&pRevTcnTable->tcn_number;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct REV_TCN);
  sqlstm.sqindv[0] = (         short *)&pRevTcnTableInd->tcn_number_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct REV_TCN_IND);
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)pRevTcnTable->date_paiement;
  sqlstm.sqhstl[1] = (unsigned long )11;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct REV_TCN);
  sqlstm.sqindv[1] = (         short *)&pRevTcnTableInd->date_paiement_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct REV_TCN_IND);
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&pRevTcnTable->heure_paiement;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(struct REV_TCN);
  sqlstm.sqindv[2] = (         short *)&pRevTcnTableInd->heure_paiement_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct REV_TCN_IND);
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&pRevTcnTable->canal_paiement;
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )sizeof(struct REV_TCN);
  sqlstm.sqindv[3] = (         short *)&pRevTcnTableInd->canal_paiement_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct REV_TCN_IND);
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)pRevTcnTable->date_emission_physique;
  sqlstm.sqhstl[4] = (unsigned long )11;
  sqlstm.sqhsts[4] = (         int  )sizeof(struct REV_TCN);
  sqlstm.sqindv[4] = (         short *)&pRevTcnTableInd->date_emission_physique_ind;
  sqlstm.sqinds[4] = (         int  )sizeof(struct REV_TCN_IND);
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&pRevTcnTable->canal_emission;
  sqlstm.sqhstl[5] = (unsigned long )6;
  sqlstm.sqhsts[5] = (         int  )sizeof(struct REV_TCN);
  sqlstm.sqindv[5] = (         short *)&pRevTcnTableInd->canal_emission_ind;
  sqlstm.sqinds[5] = (         int  )sizeof(struct REV_TCN_IND);
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)pRevTcnTable->date_max_depart;
  sqlstm.sqhstl[6] = (unsigned long )11;
  sqlstm.sqhsts[6] = (         int  )sizeof(struct REV_TCN);
  sqlstm.sqindv[6] = (         short *)&pRevTcnTableInd->date_max_depart_ind;
  sqlstm.sqinds[6] = (         int  )sizeof(struct REV_TCN_IND);
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&pRevTcnTable->annule;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(struct REV_TCN);
  sqlstm.sqindv[7] = (         short *)&pRevTcnTableInd->annule_ind;
  sqlstm.sqinds[7] = (         int  )sizeof(struct REV_TCN_IND);
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&pRevTcnTable->codeFCE;
  sqlstm.sqhstl[8] = (unsigned long )10;
  sqlstm.sqhsts[8] = (         int  )sizeof(struct REV_TCN);
  sqlstm.sqindv[8] = (         short *)&pRevTcnTableInd->codeFCE_ind;
  sqlstm.sqinds[8] = (         int  )sizeof(struct REV_TCN_IND);
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
  sqlcxt(&ctxLireVec, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto err_tcn_insert;
}


  nbTCNtotal += nbTcnInBuf;
  /* EXEC SQL COMMIT WORK; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )664;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt(&ctxLireVec, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto err_tcn_insert;
}


  return;
          
err_tcn_insert:
  cerr << "ERROR BULK INSERT TCN: \n";
  char szMess[71];
  strncpy(szMess,sqlca.sqlerrm.sqlerrmc,sqlca.sqlerrm.sqlerrml);
  szMess[sqlca.sqlerrm.sqlerrml]='\0';
  cerr << szMess << "\n";
  /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

  /* EXEC SQL ROLLBACK WORK; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )679;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt(&ctxLireVec, &sqlctx, &sqlstm, &sqlfpn);
}



  //cout<<"insertion ligne a ligne de "<<nbTcnInBuf<<" TCN"<<endl;
  int j = 0;
  for (j = 0; j < nbTcnInBuf; j++)
  {
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    pRevTcnATraiterSingle[0] = pRevTcnATraiterTable[j];
    /* EXEC SQL FOR 1 INSERT INTO REV_TCN_A_TRAITER
       (TCN_NUMBER_AT, DATE_PAIEMENT_AT, DATE_FICHIER, HEURE_FICHIER)
       values (:pRevTcnATraiterSingle); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 27;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert INTO REV_TCN_A_TRAITER ( TCN_NUMBER_AT , DATE_PAIE\
MENT_AT , DATE_FICHIER , HEURE_FICHIER ) values ( :s1 ,:s2 ,:s3 ,:s4  ) ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )694;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&pRevTcnATraiterSingle->tcn_number;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )sizeof(struct REV_TCN_A_TRAITER);
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)pRevTcnATraiterSingle->date_paiement;
    sqlstm.sqhstl[1] = (unsigned long )11;
    sqlstm.sqhsts[1] = (         int  )sizeof(struct REV_TCN_A_TRAITER);
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)pRevTcnATraiterSingle->date_fichier;
    sqlstm.sqhstl[2] = (unsigned long )11;
    sqlstm.sqhsts[2] = (         int  )sizeof(struct REV_TCN_A_TRAITER);
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&pRevTcnATraiterSingle->heure_fichier;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )sizeof(struct REV_TCN_A_TRAITER);
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
    sqlcxt(&ctxLireVec, &sqlctx, &sqlstm, &sqlfpn);
}


    
    /* EXEC SQL WHENEVER SQLERROR DO sql_warn ("TCN", pRevTcnTable[j].tcn_number, nbTCNtotal); */ 

    pRevTcnSingle[0] = pRevTcnTable[j];
    pRevTcnSingleInd[0] = pRevTcnTableInd[j];
    /* EXEC SQL FOR 1 INSERT INTO REV_TCN 
        // DM7979 segmentation client : Ajout champ FCE
       (TCN_NUMBER, DATE_PAIEMENT, HEURE_PAIEMENT, CANAL_PAIEMENT, DATE_EMISSION_PHYSIQUE, CANAL_EMISSION,
        DATE_MAX_DEPART, ANNULE, FCE)
       values (:pRevTcnSingle indicator :pRevTcnSingleInd); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 27;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert INTO REV_TCN ( TCN_NUMBER , DATE_PAIEMENT , HEURE_\
PAIEMENT , CANAL_PAIEMENT , DATE_EMISSION_PHYSIQUE , CANAL_EMISSION , DATE_MAX\
_DEPART , ANNULE , FCE ) values ( :s1:s2 ,:s3:s4 ,:s5:s6 ,:s7:s8 ,:s9:s10 ,:s1\
1:s12 ,:s13:s14 ,:s15:s16 ,:s17:s18  ) ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )725;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&pRevTcnSingle->tcn_number;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )sizeof(struct REV_TCN);
    sqlstm.sqindv[0] = (         short *)&pRevTcnSingleInd->tcn_number_ind;
    sqlstm.sqinds[0] = (         int  )sizeof(struct REV_TCN_IND);
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)pRevTcnSingle->date_paiement;
    sqlstm.sqhstl[1] = (unsigned long )11;
    sqlstm.sqhsts[1] = (         int  )sizeof(struct REV_TCN);
    sqlstm.sqindv[1] = (         short *)&pRevTcnSingleInd->date_paiement_ind;
    sqlstm.sqinds[1] = (         int  )sizeof(struct REV_TCN_IND);
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&pRevTcnSingle->heure_paiement;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )sizeof(struct REV_TCN);
    sqlstm.sqindv[2] = (         short *)&pRevTcnSingleInd->heure_paiement_ind;
    sqlstm.sqinds[2] = (         int  )sizeof(struct REV_TCN_IND);
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&pRevTcnSingle->canal_paiement;
    sqlstm.sqhstl[3] = (unsigned long )6;
    sqlstm.sqhsts[3] = (         int  )sizeof(struct REV_TCN);
    sqlstm.sqindv[3] = (         short *)&pRevTcnSingleInd->canal_paiement_ind;
    sqlstm.sqinds[3] = (         int  )sizeof(struct REV_TCN_IND);
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)pRevTcnSingle->date_emission_physique;
    sqlstm.sqhstl[4] = (unsigned long )11;
    sqlstm.sqhsts[4] = (         int  )sizeof(struct REV_TCN);
    sqlstm.sqindv[4] = (         short *)&pRevTcnSingleInd->date_emission_physique_ind;
    sqlstm.sqinds[4] = (         int  )sizeof(struct REV_TCN_IND);
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqharc[4] = (unsigned long  *)0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&pRevTcnSingle->canal_emission;
    sqlstm.sqhstl[5] = (unsigned long )6;
    sqlstm.sqhsts[5] = (         int  )sizeof(struct REV_TCN);
    sqlstm.sqindv[5] = (         short *)&pRevTcnSingleInd->canal_emission_ind;
    sqlstm.sqinds[5] = (         int  )sizeof(struct REV_TCN_IND);
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqharc[5] = (unsigned long  *)0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)pRevTcnSingle->date_max_depart;
    sqlstm.sqhstl[6] = (unsigned long )11;
    sqlstm.sqhsts[6] = (         int  )sizeof(struct REV_TCN);
    sqlstm.sqindv[6] = (         short *)&pRevTcnSingleInd->date_max_depart_ind;
    sqlstm.sqinds[6] = (         int  )sizeof(struct REV_TCN_IND);
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqharc[6] = (unsigned long  *)0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)&pRevTcnSingle->annule;
    sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[7] = (         int  )sizeof(struct REV_TCN);
    sqlstm.sqindv[7] = (         short *)&pRevTcnSingleInd->annule_ind;
    sqlstm.sqinds[7] = (         int  )sizeof(struct REV_TCN_IND);
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqharc[7] = (unsigned long  *)0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)&pRevTcnSingle->codeFCE;
    sqlstm.sqhstl[8] = (unsigned long )10;
    sqlstm.sqhsts[8] = (         int  )sizeof(struct REV_TCN);
    sqlstm.sqindv[8] = (         short *)&pRevTcnSingleInd->codeFCE_ind;
    sqlstm.sqinds[8] = (         int  )sizeof(struct REV_TCN_IND);
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
    sqlcxt(&ctxLireVec, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_warn("TCN",(pRevTcnTable[j].tcn_number),nbTCNtotal);
}


    nbTCNtotal ++;
  }
  /* EXEC SQL COMMIT WORK; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )776;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt(&ctxLireVec, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_warn("TCN",(pRevTcnTable[j].tcn_number),nbTCNtotal);
}


  
  // FIXME_NPI: Complement de la trace pour analyse plus fine du CR137 - A SUPPRIMER QUAND LE PROBLEME SERA RESOLU
  // cout <<DonneHeure()<<" Fin InsertTCN"<<endl;
}
// JRO -IC SRO - DT 23805 - Ajout flag is train en paramètre de la fonction
void YmRevLireVec::AddInMapTpOD (YmRevPassagersParcours* pPasPar, YmRevSegments* pSegment, int isTrain)
{
  // FIXME_NPI: Complement de la trace pour analyse plus fine du CR137 - A SUPPRIMER QUAND LE PROBLEME SERA RESOLU
  
  
  YmRevTpOD* pTpOD;
  string lstrdatetemp;
  //
  lstrdatetemp=pSegment->getDateDepart().substr(6,2)+'/'+pSegment->getDateDepart().substr(4,2)+'/'+pSegment->getDateDepart().substr(0,4);
  

        //DT33254

        if(pSegment->getUpgHan()==0 || (pSegment->getUpgHan()!=1 && pSegment->getUpgHan()!=2 )){
            pTpOD = g_MapTpOD.isInMap (pSegment->getTrancheNo(), (char *)lstrdatetemp.c_str() ,
           pSegment->getOrigineSeg(), pSegment->getDestinationSeg(),
           pSegment->getClassOfService(), pSegment->getNumPalier(), pSegment->getNestLevel(), pSegment->getScx(), isTrain);
        }else{
            pTpOD = g_MapTpOD.isInMap (pSegment->getTrancheNo(), (char *)lstrdatetemp.c_str() ,
           pSegment->getOrigineSeg(), pSegment->getDestinationSeg(),
           pSegment->getClasseBooking(), pSegment->getPalierBooking(), pSegment->getNestLevel(), pSegment->getScx(), isTrain);
        }

  if (pTpOD)
  {
	
    pTpOD->addRevenu (pSegment->getRevenu());
    pTpOD->addPassagers (pPasPar->getNombrePassagers());
  }
  else
  {
  
    TrLeg aTrLeg = g_MapTrLeg.InMap (pSegment->getTrancheNo(), pSegment->getOrigineSeg(), 
					pSegment->getDestinationSeg(), //MHUE 11/09/06
                                       (char *)lstrdatetemp.c_str(), //JRO DT 23805 IC SRO - Ajout isTrain
									   isTrain );
									   
	
      //DT33254
          if(pSegment->getUpgHan()==0 || (pSegment->getUpgHan()!=1 && pSegment->getUpgHan()!=2 )){
              pTpOD = new YmRevTpOD (pSegment->getTrancheNo(), aTrLeg.dpt_date_tr, pSegment->getOrigineSeg(),
                     pSegment->getDestinationSeg(),pSegment->getClassOfService(), pSegment->getNumPalier(),
                     pSegment->getNestLevel(), (char* )lstrdatetemp.c_str() , 
               pPasPar->getNombrePassagers(), pSegment->getRevenu(), aTrLeg.indic_tgv,
                     g_szDateFichier, g_HeureFichier, pSegment->getScx(), isTrain);
        }else{
            pTpOD = new YmRevTpOD (pSegment->getTrancheNo(), aTrLeg.dpt_date_tr, pSegment->getOrigineSeg(),
                     pSegment->getDestinationSeg(),pSegment->getClasseBooking(), pSegment->getPalierBooking(),
                     pSegment->getNestLevel(), (char* )lstrdatetemp.c_str() , 
               pPasPar->getNombrePassagers(), pSegment->getRevenu(), aTrLeg.indic_tgv,
                     g_szDateFichier, g_HeureFichier, pSegment->getScx(), isTrain);
        }
	
	
	
    g_MapTpOD.Add (pTpOD);
  }

  // meme chose avec TpFBC
  YmRevTpFBC* pTpFBC;
  string sFare = pPasPar->getFareBasisCode();
  if (!sFare.empty())
  {
    pTpFBC = g_MapTpFBC.isInMap ((int)pSegment->getTrancheNo(), (char *)lstrdatetemp.c_str() ,
			     pSegment->getOrigineSeg(), pSegment->getDestinationSeg(), sFare);
    if (pTpFBC)
    {
      pTpFBC->addRevenu (pSegment->getRevenu());
      pTpFBC->addPassagers (pPasPar->getNombrePassagers());
    }
    else
    {
      TrLeg aTrLeg = g_MapTrLeg.InMap ((int)pSegment->getTrancheNo(), pSegment->getOrigineSeg(), 
					pSegment->getDestinationSeg(), //MHUE 11/09/06
                                       (char *)lstrdatetemp.c_str() );
      pTpFBC = new YmRevTpFBC ((int)pSegment->getTrancheNo(), aTrLeg.dpt_date_tr, pSegment->getOrigineSeg(),
                             pSegment->getDestinationSeg(), sFare, (char* )lstrdatetemp.c_str() , 
			     pPasPar->getNombrePassagers(), pSegment->getRevenu(), aTrLeg.indic_tgv, g_szDateFichier);
      g_MapTpFBC.Add (pTpFBC);
    }
  }
  
  // FIXME_NPI: Complement de la trace pour analyse plus fine du CR137 - A SUPPRIMER QUAND LE PROBLEME SERA RESOLU
  //cout <<DonneHeure()<<" Fin AddInMapTpOD"<<endl;
}
