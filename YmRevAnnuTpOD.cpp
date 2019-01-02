
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
    "YmRevAnnuTpOD.pc"
};


static unsigned int sqlctx = 5455915;


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
   unsigned char  *sqhstv[13];
   unsigned long  sqhstl[13];
            int   sqhsts[13];
            short *sqindv[13];
            int   sqinds[13];
   unsigned long  sqharm[13];
   unsigned long  *sqharc[13];
   unsigned short  sqadto[13];
   unsigned short  sqtdso[13];
} sqlstm = {12,13};

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

 static const char *sq0012 = 
"SELECT s . tranche_no , s . origine_seg , s . destination_seg , s . class_of\
_service , s . nest_level , s . num_palier , to_char ( s . date_depart , 'dd/m\
m/yyyy' ) , s . revenu , p . nombre_passagers , p . fare_basis_code , s . pp_n\
um , p . pp_num , s . scx FROM REV_SEGMENTS s , REV_PASSAGERS_PARCOURS p , REV\
_TCN_A_ANNULER a WHERE s . tcn_number = a . tcn_number_aa and s . date_paiemen\
t = a . date_paiement_aa and p . tcn_number = a . tcn_number_aa and p . date_p\
aiement = a . date_paiement_aa            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4130,1,0,0,
5,0,0,1,137,0,5,41,0,0,0,0,0,1,0,
20,0,0,2,0,0,29,45,0,0,0,0,0,1,0,
35,0,0,3,251,0,2,49,0,0,0,0,0,1,0,
50,0,0,4,0,0,29,56,0,0,0,0,0,1,0,
65,0,0,5,88,0,4,67,0,0,3,2,0,1,0,1,97,0,0,1,3,0,0,2,97,0,0,
92,0,0,6,230,0,4,69,0,0,3,2,0,1,0,2,3,0,0,1,97,0,0,1,3,0,0,
119,0,0,7,209,0,2,75,0,0,2,2,0,1,0,1,97,0,0,1,3,0,0,
142,0,0,8,88,0,2,80,0,0,2,2,0,1,0,1,97,0,0,1,3,0,0,
165,0,0,9,0,0,29,82,0,0,0,0,0,1,0,
180,0,0,10,228,0,5,131,0,0,0,0,0,1,0,
195,0,0,11,242,0,5,135,0,0,0,0,0,1,0,
210,0,0,12,508,0,9,148,0,2049,0,0,0,1,0,
225,0,0,12,0,0,13,160,0,0,13,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,
3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
292,0,0,12,0,0,15,241,0,0,0,0,0,1,0,
307,0,0,13,0,0,29,242,0,0,0,0,0,1,0,
};


#pragma ident "%Z% FileName: $RCSfile: YmRevAnnuTpOD.pc,v $ Version: $Revision: 1.17 $ Date: $Date: 2009/02/20 13:10:57 $ %Z %"

//## Module: YmRevAnnuTpOD
//SFD
//  Name:    YmRevAnnuTpOD.cpp
//  Author:  JM. Grugeaux
//  Desc:    prise en compte annulation dans g_MapTpOD
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
#include <YmRevAnnuTpOD.h>
#include <YmRevMess.h>

//## Configuration du contexte de base JRO IC SRO DT 23805
extern sql_context ctxRevMain;
/* EXEC SQL CONTEXT USE :ctxRevMain; */ 


YmRevAnnuTpOD::YmRevAnnuTpOD()
  {
  }

YmRevAnnuTpOD::~YmRevAnnuTpOD()
  {
  }

void YmRevAnnuTpOD::SupprAnnuTraitees()
{
    cout<<DonneHeure()<<" Debut SupprAnnuTraiter : update ANNULE dans REV_TCN"<<endl;
    /* EXEC SQL WHENEVER SQLERROR DO sql_error((char *)"Erreur Update ANNULE dans REV_TCN",0); */ 

    /* EXEC SQL UPDATE REV_TCN SET ANNULE = 1
             WHERE (tcn_number, date_paiement) in
            ( SELECT tcn_number_aa, date_paiement_aa
              FROM REV_TCN_A_ANNULER); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 0;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "update REV_TCN SET ANNULE = 1 WHERE ( tcn_number , date_p\
aiement ) in ( SELECT tcn_number_aa , date_paiement_aa FROM REV_TCN_A_ANNULER \
) ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("Erreur Update ANNULE dans REV_TCN",0);
}


    /* EXEC SQL COMMIT; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 0;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )20;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("Erreur Update ANNULE dans REV_TCN",0);
}



    cout<<DonneHeure()<<"                        : Delete dans REV_TCN_A_ANNULER"<<endl;
    /* EXEC SQL WHENEVER SQLERROR DO sql_error((char *)"Erreur Delete dans REV_TCN_A_ANNULER",0); */ 

    /* EXEC SQL DELETE FROM REV_TCN_A_ANNULER
             WHERE (tcn_number_aa, date_paiement_aa) in
           ( SELECT a.tcn_number_aa, a.date_paiement_aa
             FROM REV_TCN_A_ANNULER a, REV_TCN t
             WHERE a.tcn_number_aa = t.tcn_number and
                   a.date_paiement_aa = t.date_paiement); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 0;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "delete FROM REV_TCN_A_ANNULER WHERE ( tcn_number_aa , dat\
e_paiement_aa ) in ( SELECT a . tcn_number_aa , a . date_paiement_aa FROM REV_\
TCN_A_ANNULER a , REV_TCN t WHERE a . tcn_number_aa = t . tcn_number and a . d\
ate_paiement_aa = t . date_paiement ) ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )35;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("Erreur Delete dans REV_TCN_A_ANNULER",0);
}



    /* EXEC SQL COMMIT; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 0;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )50;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("Erreur Delete dans REV_TCN_A_ANNULER",0);
}



    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    char date_limite[11];
    char date_purge[9];
    int countAnnuAPurger;
    int retention;
    /* EXEC SQL END DECLARE SECTION; */ 


    strcpy (date_limite, g_szDateFichier);
    retention = g_Retention;
    /* EXEC SQL SELECT TO_CHAR(TO_DATE (:date_limite, 'dd/mm/yyyy') -:retention,'dd/mm/yy') into :date_purge FROM DUAL; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 3;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select TO_CHAR ( TO_DATE ( :b0 , 'dd/mm/yyyy' ) - :b1 , '\
dd/mm/yy' ) into :b2 FROM DUAL ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )65;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)date_limite;
    sqlstm.sqhstl[0] = (unsigned long )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&retention;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)date_purge;
    sqlstm.sqhstl[2] = (unsigned long )9;
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
    if (sqlca.sqlcode < 0) sql_error("Erreur Delete dans REV_TCN_A_ANNULER",0);
}


   // Nombre  ANNULATION non traite deux jours apres leur apparition. A purger 
    /* EXEC SQL SELECT count(*) into :countAnnuAPurger FROM REV_ANNULATION_ECHANGE
             WHERE (tcn_annule, date_tcn) in
           ( SELECT a.tcn_number_aa, a.date_paiement_aa
             FROM REV_TCN_A_ANNULER a
             WHERE a.date_fichier < TO_DATE (:date_limite, 'dd/mm/yyyy') -:retention); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 3;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select count ( * ) into :b0 FROM REV_ANNULATION_ECHANGE W\
HERE ( tcn_annule , date_tcn ) in ( SELECT a . tcn_number_aa , a . date_paieme\
nt_aa FROM REV_TCN_A_ANNULER a WHERE a . date_fichier < TO_DATE ( :b1 , 'dd/mm\
/yyyy' ) - :b2 ) ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )92;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&countAnnuAPurger;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)date_limite;
    sqlstm.sqhstl[1] = (unsigned long )11;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&retention;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
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
    if (sqlca.sqlcode < 0) sql_error("Erreur Delete dans REV_TCN_A_ANNULER",0);
}


    // Elimination des ANNULATION non traite deux jours apres leur apparition. Ce doit etre des non yielde
    /* EXEC SQL DELETE FROM REV_ANNULATION_ECHANGE
             WHERE (tcn_annule, date_tcn) in
           ( SELECT a.tcn_number_aa, a.date_paiement_aa
             FROM REV_TCN_A_ANNULER a
             WHERE a.date_fichier < TO_DATE (:date_limite, 'dd/mm/yyyy') -:retention); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 3;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "delete FROM REV_ANNULATION_ECHANGE WHERE ( tcn_annule , d\
ate_tcn ) in ( SELECT a . tcn_number_aa , a . date_paiement_aa FROM REV_TCN_A_\
ANNULER a WHERE a . date_fichier < TO_DATE ( :b0 , 'dd/mm/yyyy' ) - :b1 ) ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )119;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)date_limite;
    sqlstm.sqhstl[0] = (unsigned long )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&retention;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
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
    if (sqlca.sqlcode < 0) sql_error("Erreur Delete dans REV_TCN_A_ANNULER",0);
}


    /* EXEC SQL DELETE FROM REV_TCN_A_ANNULER
             WHERE date_fichier < TO_DATE (:date_limite, 'dd/mm/yyyy') -:retention; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 3;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "delete FROM REV_TCN_A_ANNULER WHERE date_fichier < TO_DAT\
E ( :b0 , 'dd/mm/yyyy' ) - :b1 ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )142;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)date_limite;
    sqlstm.sqhstl[0] = (unsigned long )11;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&retention;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
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
    if (sqlca.sqlcode < 0) sql_error("Erreur Delete dans REV_TCN_A_ANNULER",0);
}


    /* EXEC SQL COMMIT; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 3;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )165;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("Erreur Delete dans REV_TCN_A_ANNULER",0);
}


   //Message informant sur le nombre d'annulation a purger apres :retention jours de TP_REV_ANNULATION_ECHANGE
    YmRevMess rMess((char*)"batch_unitaire", (char*)"YmRevAnnuTpOD",(char*)"SupprAnnuTraites",(char*)"revenus");
    char sMessText[180];
    sprintf(sMessText,"Nb Annulations anterieures a %s purgees car non traitees apres %d jours : %d",
            date_purge,retention,countAnnuAPurger);
    rMess.envoiMess(78,(char *)sMessText,YmRevMess::INF);
    cout<<DonneHeure()<<" Fin SupprAnnuTraiter"<<endl;
  }





// Met a jour les date_tcn dans les tables rev_annulation_echange et rev_tcn_a_annuler
// pour les lignes ou la date_tcn est egale a '01/01/2000', la valeur dummy.
// La date est prise dans rev_tcn en prenant la date max pour le TCN de meme numero.
// Ensuite:
// Lecture en base les infos annulations et met a jour la Map d'insertion vers la table TPREV_OD
// ainsi que la map d'insertion vers la table TPREV_FBC_OD

int YmRevAnnuTpOD::TraiteAnnuTpOD() // Fait le boulot, renvoi le nombre de lignes traite
  {
    int iNb=0;
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

       int     tranche_no;
       /* varchar origine_seg[6]; */ 
struct { unsigned short len; unsigned char arr[6]; } origine_seg;

       /* varchar destination_seg[6]; */ 
struct { unsigned short len; unsigned char arr[6]; } destination_seg;

       /* varchar class_of_service[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } class_of_service;

	   //DM 7978 - JLA - Ajout Num_Palier
	   int     num_palier;
       /* varchar fare_basis_code[9]; */ 
struct { unsigned short len; unsigned char arr[9]; } fare_basis_code;

       short   inull_fare = -1;
       int     nest_level;
       char    date_depart[11];
       int     revenu;
       int     nombre_passagers;
       short   inull_revenu = -1;
       short   inull_scx = -1;
       int     spp_num;
       int     ppp_num;
//PLF 07/07/2008: DM5882.1 :rajout sous-contingentement ( scx ) pour nestlevel =0
       int     scx;
    /* EXEC SQL END DECLARE SECTION; */ 

    
    /* EXEC SQL WHENEVER SQLERROR DO sql_error((char *)"Erreur prise en compte annulations",0); */ 


    // Avant recuperation des annulation, recuperation de la date TCN pour les annulations ou elle
    // n'est pas indique
    /* EXEC SQL UPDATE REV_ANNULATION_ECHANGE set DATE_TCN =
           ( SELECT NVL(max (date_paiement), to_date ('01/01/2000', 'dd/mm/yyyy')) FROM REV_TCN
             WHERE tcn_number = tcn_annule) 
            WHERE date_tcn = to_date('01/01/2000', 'dd/mm/yyyy'); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 3;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "update REV_ANNULATION_ECHANGE set DATE_TCN = ( SELECT NVL\
 ( max ( date_paiement ) , to_date ( '01/01/2000' , 'dd/mm/yyyy' ) ) FROM REV_\
TCN WHERE tcn_number = tcn_annule ) WHERE date_tcn = to_date ( '01/01/2000' , \
'dd/mm/yyyy' ) ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )180;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("Erreur prise en compte annulations",0);
}


    /* EXEC SQL UPDATE REV_TCN_A_ANNULER set DATE_PAIEMENT_AA =
           ( SELECT NVL(max (date_paiement), to_date ('01/01/2000', 'dd/mm/yyyy')) FROM REV_TCN
             WHERE tcn_number = tcn_number_aa) 
            WHERE date_paiement_aa = to_date('01/01/2000', 'dd/mm/yyyy'); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 3;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "update REV_TCN_A_ANNULER set DATE_PAIEMENT_AA = ( SELECT \
NVL ( max ( date_paiement ) , to_date ( '01/01/2000' , 'dd/mm/yyyy' ) ) FROM R\
EV_TCN WHERE tcn_number = tcn_number_aa ) WHERE date_paiement_aa = to_date ( '\
01/01/2000' , 'dd/mm/yyyy' ) ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )195;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("Erreur prise en compte annulations",0);
}


			
	//DM 7978 - JLA - ajout de Num_Palier
    /* EXEC SQL DECLARE cAnnu CURSOR FOR
         SELECT s.tranche_no, s.origine_seg, s.destination_seg, s.class_of_service, s.nest_level, s.num_palier,
                to_char (s.date_depart, 'dd/mm/yyyy'), s.revenu, p.nombre_passagers, p.fare_basis_code,
                s.pp_num, p.pp_num ,s.scx
         FROM REV_SEGMENTS s, REV_PASSAGERS_PARCOURS p, REV_TCN_A_ANNULER a
         WHERE s.tcn_number = a.tcn_number_aa and s.date_paiement = a.date_paiement_aa and
               p.tcn_number = a.tcn_number_aa and p.date_paiement = a.date_paiement_aa; */ 

    /* EXEC SQL OPEN cAnnu ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 3;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0012;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )210;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("Erreur prise en compte annulations",0);
}



    cout<<DonneHeure()<<" Debut prise en compte annulation"<<endl;
    int totAnnuRev = 0;
    int totAnnuPas = 0;
    int multippnum = 0;
    
    /* EXEC SQL WHENEVER NOT FOUND DO break; */ 

    string sOrig, sDest, sClass, sFare;
    while(1)
    {
	   //DM 7978 - JLA - Ajout Num_Palier
       /* EXEC SQL FETCH cAnnu INTO :tranche_no, :origine_seg, :destination_seg, :class_of_service,
                                 :nest_level, :num_palier, :date_depart, :revenu:inull_revenu, :nombre_passagers,
                                 :fare_basis_code:inull_fare, spp_num, ppp_num, :scx:inull_scx ; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 12;
       sqlstm.arrsiz = 13;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )225;
       sqlstm.selerr = (unsigned short)1;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlstm.sqfoff = (         int )0;
       sqlstm.sqfmod = (unsigned int )2;
       sqlstm.sqhstv[0] = (unsigned char  *)&tranche_no;
       sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[0] = (         int  )0;
       sqlstm.sqindv[0] = (         short *)0;
       sqlstm.sqinds[0] = (         int  )0;
       sqlstm.sqharm[0] = (unsigned long )0;
       sqlstm.sqadto[0] = (unsigned short )0;
       sqlstm.sqtdso[0] = (unsigned short )0;
       sqlstm.sqhstv[1] = (unsigned char  *)&origine_seg;
       sqlstm.sqhstl[1] = (unsigned long )8;
       sqlstm.sqhsts[1] = (         int  )0;
       sqlstm.sqindv[1] = (         short *)0;
       sqlstm.sqinds[1] = (         int  )0;
       sqlstm.sqharm[1] = (unsigned long )0;
       sqlstm.sqadto[1] = (unsigned short )0;
       sqlstm.sqtdso[1] = (unsigned short )0;
       sqlstm.sqhstv[2] = (unsigned char  *)&destination_seg;
       sqlstm.sqhstl[2] = (unsigned long )8;
       sqlstm.sqhsts[2] = (         int  )0;
       sqlstm.sqindv[2] = (         short *)0;
       sqlstm.sqinds[2] = (         int  )0;
       sqlstm.sqharm[2] = (unsigned long )0;
       sqlstm.sqadto[2] = (unsigned short )0;
       sqlstm.sqtdso[2] = (unsigned short )0;
       sqlstm.sqhstv[3] = (unsigned char  *)&class_of_service;
       sqlstm.sqhstl[3] = (unsigned long )5;
       sqlstm.sqhsts[3] = (         int  )0;
       sqlstm.sqindv[3] = (         short *)0;
       sqlstm.sqinds[3] = (         int  )0;
       sqlstm.sqharm[3] = (unsigned long )0;
       sqlstm.sqadto[3] = (unsigned short )0;
       sqlstm.sqtdso[3] = (unsigned short )0;
       sqlstm.sqhstv[4] = (unsigned char  *)&nest_level;
       sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[4] = (         int  )0;
       sqlstm.sqindv[4] = (         short *)0;
       sqlstm.sqinds[4] = (         int  )0;
       sqlstm.sqharm[4] = (unsigned long )0;
       sqlstm.sqadto[4] = (unsigned short )0;
       sqlstm.sqtdso[4] = (unsigned short )0;
       sqlstm.sqhstv[5] = (unsigned char  *)&num_palier;
       sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[5] = (         int  )0;
       sqlstm.sqindv[5] = (         short *)0;
       sqlstm.sqinds[5] = (         int  )0;
       sqlstm.sqharm[5] = (unsigned long )0;
       sqlstm.sqadto[5] = (unsigned short )0;
       sqlstm.sqtdso[5] = (unsigned short )0;
       sqlstm.sqhstv[6] = (unsigned char  *)date_depart;
       sqlstm.sqhstl[6] = (unsigned long )11;
       sqlstm.sqhsts[6] = (         int  )0;
       sqlstm.sqindv[6] = (         short *)0;
       sqlstm.sqinds[6] = (         int  )0;
       sqlstm.sqharm[6] = (unsigned long )0;
       sqlstm.sqadto[6] = (unsigned short )0;
       sqlstm.sqtdso[6] = (unsigned short )0;
       sqlstm.sqhstv[7] = (unsigned char  *)&revenu;
       sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[7] = (         int  )0;
       sqlstm.sqindv[7] = (         short *)&inull_revenu;
       sqlstm.sqinds[7] = (         int  )0;
       sqlstm.sqharm[7] = (unsigned long )0;
       sqlstm.sqadto[7] = (unsigned short )0;
       sqlstm.sqtdso[7] = (unsigned short )0;
       sqlstm.sqhstv[8] = (unsigned char  *)&nombre_passagers;
       sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[8] = (         int  )0;
       sqlstm.sqindv[8] = (         short *)0;
       sqlstm.sqinds[8] = (         int  )0;
       sqlstm.sqharm[8] = (unsigned long )0;
       sqlstm.sqadto[8] = (unsigned short )0;
       sqlstm.sqtdso[8] = (unsigned short )0;
       sqlstm.sqhstv[9] = (unsigned char  *)&fare_basis_code;
       sqlstm.sqhstl[9] = (unsigned long )11;
       sqlstm.sqhsts[9] = (         int  )0;
       sqlstm.sqindv[9] = (         short *)&inull_fare;
       sqlstm.sqinds[9] = (         int  )0;
       sqlstm.sqharm[9] = (unsigned long )0;
       sqlstm.sqadto[9] = (unsigned short )0;
       sqlstm.sqtdso[9] = (unsigned short )0;
       sqlstm.sqhstv[10] = (unsigned char  *)&spp_num;
       sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[10] = (         int  )0;
       sqlstm.sqindv[10] = (         short *)0;
       sqlstm.sqinds[10] = (         int  )0;
       sqlstm.sqharm[10] = (unsigned long )0;
       sqlstm.sqadto[10] = (unsigned short )0;
       sqlstm.sqtdso[10] = (unsigned short )0;
       sqlstm.sqhstv[11] = (unsigned char  *)&ppp_num;
       sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[11] = (         int  )0;
       sqlstm.sqindv[11] = (         short *)0;
       sqlstm.sqinds[11] = (         int  )0;
       sqlstm.sqharm[11] = (unsigned long )0;
       sqlstm.sqadto[11] = (unsigned short )0;
       sqlstm.sqtdso[11] = (unsigned short )0;
       sqlstm.sqhstv[12] = (unsigned char  *)&scx;
       sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[12] = (         int  )0;
       sqlstm.sqindv[12] = (         short *)&inull_scx;
       sqlstm.sqinds[12] = (         int  )0;
       sqlstm.sqharm[12] = (unsigned long )0;
       sqlstm.sqadto[12] = (unsigned short )0;
       sqlstm.sqtdso[12] = (unsigned short )0;
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
       if (sqlca.sqlcode < 0) sql_error("Erreur prise en compte annulations",0);
}


       if (inull_revenu == -1)
         revenu = 0;
       if (inull_scx == -1)
         scx = 0;
       if (spp_num != ppp_num)
         multippnum ++;
       else
       {
         iNb++;
         origine_seg.arr[origine_seg.len] = '\0';
         destination_seg.arr[destination_seg.len] = '\0';
         class_of_service.arr[class_of_service.len] = '\0';
         if (inull_fare == -1)
           sFare = "";
         else
         {
           fare_basis_code.arr[fare_basis_code.len] = '\0';
           sFare = (char*)fare_basis_code.arr;
         }
         date_depart[10] = 0;  // coup de securite.
         sOrig = (char*)origine_seg.arr;
         sDest = (char*)destination_seg.arr;
         sClass = (char*)class_of_service.arr;

         totAnnuRev += revenu;
         totAnnuPas += nombre_passagers;

         YmRevTpOD* pTpOD;
// PLF 07/07/2008: DM5882.1 :rajout sous-contingentement ( scx ) pour nestlevel =0
//JRO - IC SRO - DT23805 - Ajouter du flag isTrain valant 0 car le no tranche vient de la table REV_SEGMENT 

         pTpOD = g_MapTpOD.isInMap (tranche_no, date_depart, sOrig, sDest, sClass, num_palier , nest_level,scx, 0);
         if (pTpOD)
         {
           pTpOD->addRevenu (-revenu);
           pTpOD->addPassagers (-nombre_passagers);
         }
         else
         {
           TrLeg aTrLeg = g_MapTrLeg.InMap (tranche_no, sOrig, sDest, date_depart); //MHUE 11/09/06
//MHUE 11/09/06
           string aTrLeg_dpt_date_tr_part = aTrLeg.dpt_date_tr;
                     
           if ((aTrLeg.indic_tgv!=2) && (YmDate(aTrLeg_dpt_date_tr_part) >= g_dateMinTranche))
              {
			  //JRO - IC SRO - DT23805 - Ajouter du flag isTrain valant 0 car le no tranche vient de la table REV_SEGMENT 
			  
              pTpOD = new YmRevTpOD (tranche_no, aTrLeg.dpt_date_tr, sOrig, sDest, sClass, num_palier, nest_level,
                                  date_depart, -nombre_passagers, -revenu, aTrLeg.indic_tgv, g_szDateFichier,
                                  g_HeureFichier,scx,0);
              g_MapTpOD.Add (pTpOD);
              }
//MHUE 11/09/06
         }

         if (!sFare.empty())
         {
           YmRevTpFBC* pTpFBC;
           pTpFBC = g_MapTpFBC.isInMap (tranche_no, date_depart, sOrig, sDest, sFare);
           if (pTpFBC)
           {
             pTpFBC->addRevenu (-revenu);
             pTpFBC->addPassagers (-nombre_passagers);
           }
           else
           {
             TrLeg aTrLeg = g_MapTrLeg.InMap (tranche_no, sOrig, sDest, date_depart); //MHUE 11/09/06
             string aTrLeg_dpt_date_tr_part1 = aTrLeg.dpt_date_tr;
             if ((aTrLeg.indic_tgv!=2) && (YmDate(aTrLeg_dpt_date_tr_part1) >= g_dateMinTranche))
             {
                pTpFBC = new YmRevTpFBC (tranche_no, aTrLeg.dpt_date_tr, sOrig, sDest, sFare,
                                  date_depart, -nombre_passagers, -revenu, 1, g_szDateFichier);
                g_MapTpFBC.Add (pTpFBC);
             }
           }
         }
       }
    }
    /* EXEC SQL CLOSE cAnnu ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )292;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("Erreur prise en compte annulations",0);
}


    /* EXEC SQL COMMIT; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )307;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("Erreur prise en compte annulations",0);
}


    cout<<DonneHeure()<<" Fin prise en compte: "<<iNb<<" segments annules, NbPassagers="<<totAnnuPas<<" TotRevenu="<<totAnnuRev<<endl;
    cout<<"                Multippnum = "<<multippnum<<endl;
    return iNb;
}



