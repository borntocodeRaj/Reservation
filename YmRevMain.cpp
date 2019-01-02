
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
           char  filnam[13];
};
static const struct sqlcxp sqlfpn =
{
    12,
    "YmRevMain.pc"
};


static unsigned int sqlctx = 340987;


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
   unsigned char  *sqhstv[4];
   unsigned long  sqhstl[4];
            int   sqhsts[4];
            short *sqindv[4];
            int   sqinds[4];
   unsigned long  sqharm[4];
   unsigned long  *sqharc[4];
   unsigned short  sqadto[4];
   unsigned short  sqtdso[4];
} sqlstm = {12,4};

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
5,0,0,1,0,0,31,99,0,0,0,0,0,1,0,
20,0,0,2,92,0,4,136,0,0,2,1,0,1,0,1,97,0,0,2,97,0,0,
43,0,0,0,0,0,58,258,0,0,1,1,0,1,0,3,109,0,0,
62,0,0,0,0,0,27,260,0,0,4,4,0,1,0,1,97,0,0,1,97,0,0,1,10,0,0,1,10,0,0,
93,0,0,4,132,0,2,341,0,0,0,0,0,1,0,
108,0,0,5,0,0,29,343,0,0,0,0,0,1,0,
123,0,0,6,142,0,2,345,0,0,0,0,0,1,0,
138,0,0,7,0,0,29,347,0,0,0,0,0,1,0,
153,0,0,8,127,0,2,349,0,0,0,0,0,1,0,
168,0,0,9,0,0,29,351,0,0,0,0,0,1,0,
183,0,0,10,0,0,24,354,0,0,1,1,0,1,0,1,97,0,0,
202,0,0,11,186,0,2,356,0,0,2,2,0,1,0,1,97,0,0,1,3,0,0,
225,0,0,12,0,0,29,359,0,0,0,0,0,1,0,
240,0,0,13,79,0,2,361,0,0,2,2,0,1,0,1,97,0,0,1,3,0,0,
263,0,0,14,0,0,24,448,0,0,1,1,0,1,0,1,97,0,0,
282,0,0,15,0,0,24,452,0,0,1,1,0,1,0,1,97,0,0,
301,0,0,16,0,0,24,456,0,0,1,1,0,1,0,1,97,0,0,
320,0,0,17,0,0,24,459,0,0,1,1,0,1,0,1,97,0,0,
339,0,0,18,0,0,24,464,0,0,1,1,0,1,0,1,97,0,0,
358,0,0,19,0,0,30,473,0,0,0,0,0,1,0,
373,0,0,0,0,0,59,474,0,0,1,1,0,1,0,3,109,0,0,
};


#pragma ident "%Z% FileName: $RCSfile: YmRevMain.pc,v $ Version: $Revision: 1.58 $ Date: $Date: 2012/05/22 13:25:59 $ %Z %"

//## Module: YmRevMain
//SFD
//  Name:    YmRevMain.cpp
//  Authors:  M. Hue / PL. Florent
//  Desc:    main de l'application et gestion des retours d'erreur oracle
//EFD

using namespace std;

//standard includes
#include <stdlib.h>
#include </usr/lib/oracle/11.2/client64/precomp/public/sqlca.h>
#include <iostream>
#include <unistd.h>     // Pour le sleep,
//application includes
#include <YmRevGlobal.h>
#include <YmRevDate.h>

#include <YmRevLireVec.h>
#include <YmRevEcrireVec.h>
#include <YmRevLireAnnu.h>


#include <YmRevLireRetraits.h>
#include <YmRevAnnuTpOD.h>
#include <YmRevTpNonTraite.h>
#include <YmRevTpFBCNonTraite.h>

// CONSTANTES pour VERSION
static string szNumVersion = "3.2.0 64 bits Oracle11";
#define VERSION_INTERNE "3.2.0.0"

// VARIABLES GLOBALES
YmRevMapTarifs g_MapTarifs;
YmRevMapTypePassager g_MapTypePassager;
//YmRevMapDeviceType g_MapDeviceType;
YmRevMapClassMapping g_MapClassMapping;
YmRevMapTrNonYield g_MapTrNonYield;
YmRevMapTrLeg g_MapTrLeg;
YmRevMapTpOD  g_MapTpOD;
YmRevMapTpFBC  g_MapTpFBC;
YmRevInfoBatch g_InfoBatch;
YmRevMapTypeEquipement g_MapTypeEquipement; //JRO DT23805 IC SRO
YmRevMapDeviceType g_MapDeviceType;
YmDate g_dateMinTranche; //date de la premiere tranche a prendre en compte MHUE 11/09/06
YmDate g_dateMinNestLevel; //date du premier fichier avec nest level MHUE 11/09/06

/* EXEC SQL BEGIN DECLARE SECTION; */ 

sql_context ctxRevMain; 
/* EXEC SQL END DECLARE SECTION; */ 


// vecteurs de stockage des Tcn, Annulations, Retraits
vector<YmRevTcn *> g_VTcn;
vector<YmRevAnnulation *> g_VAnnulation;
vector<YmRevRetraits *> g_VRetraits;

// Vecteurs de stockage des codes équipements pour TGV et CORAIL en base
vector<string> ListCodeEquipement; //JRO DT23805 IC SRO 
bool g_EcrireVecEnCours; // Boolean de synchronisation des Threads EcrireVec et LireVec
                         // sur l'utilisation du vecteur d'echange. Mis a jour par EcrireVec et teste par LireVec
int g_NbThreadLecteur;   // Nombre de Thread lecteur actifs
//base REV
char g_UserName[20];
char g_Password[32];
char g_OwnerBase[20];

//base OP
char g_OpUserName[20];
char g_OpPassword[32];
char g_OpSid[20];

char g_Client[3];
char g_szDateFichier[11]; // date de lancement de l'appli au format dd/mm/aaaa
char g_szDateFichierShort[9]; // date de lancement de l'appli au format dd/mm/aa
char g_CmptList[10];//chaine des compartiments  pouvant etre rencontres
int  g_HeureFichier;      // heure de lancement de l'appli au format hh*100 + mi.
int  g_ForcerFichier;     // si 1, on ne controle pas que la date/heure du resaven soit superieure
                                 // a celui du precedent traitement. Vaut 0 sinon.
int  g_TraceEcrireVec;    // Si == 1, dump de ce qui a ete lu
int  g_TestCanaux;    // Si == 1, on test les canaux.
int  g_Retention;     // duree de retention des donnee dans TPREV_NON_TRAITE et TPREV_FBC_NON_TRAITE
int  g_forceFBC;      // forcage du traitement FBC sur SNCF (debug purpose)


void sql_error(char *szMessErr, int iFatalError)
/**********************************/
// traitement des erreurs ORACLE
// iFatalError=1 => exit 9
// iFatalError=0 => continuer
/**********************************/
{
char szMess[71];
cerr << "FATAL: " << szMessErr << "\n";
strncpy(szMess,sqlca.sqlerrm.sqlerrmc,sqlca.sqlerrm.sqlerrml);
szMess[sqlca.sqlerrm.sqlerrml]='\0';
cerr << szMess << "\n";
/* EXEC SQL ROLLBACK WORK; */ 

{
struct sqlexd sqlstm;
sqlstm.sqlvsn = 12;
sqlstm.arrsiz = 0;
sqlstm.sqladtp = &sqladt;
sqlstm.sqltdsp = &sqltds;
sqlstm.iters = (unsigned int  )1;
sqlstm.offset = (unsigned int  )5;
sqlstm.cud = sqlcud0;
sqlstm.sqlest = (unsigned char  *)&sqlca;
sqlstm.sqlety = (unsigned short)4352;
sqlstm.occurs = (unsigned int  )0;
sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


if ((!strncmp(szMess,"ORA-01089",9)) || (!strncmp(szMess,"ORA-03114",9)) || (!strncmp(szMess,"ORA-01002",9) )) 
{
cerr << "Abandon du traitement\n"; 
exit(9);
} 
    
if (iFatalError)
    exit(9);
}

void sql_warn (char* szMessErr, int numtcn, int &nbTot)
{
   char szMess[71];
   cerr << "ERROR INSERT: " << szMessErr << " tcn_number: "<<numtcn<<"\n";
   strncpy(szMess,sqlca.sqlerrm.sqlerrmc,sqlca.sqlerrm.sqlerrml);
   szMess[sqlca.sqlerrm.sqlerrml]='\0';
   cerr << szMess << "\n";
   nbTot--;
}

void ctrl_date_entete_fichier(char *szDate)
/************************/
// controle de validite de la date-heure lue dans entete du fichier Resaven (format DDMMYYYYHH24MI)
// si format incorrect ou valeur de date incoherente => exit 9 fin du programme
//
/************************/
{
/* EXEC SQL CONTEXT USE :ctxRevMain; */ 

/* EXEC SQL BEGIN DECLARE SECTION; */ 

  char vDate[13];
/* EXEC SQL END DECLARE SECTION; */ 

  char szMess[71];
  sprintf(szMess,"ERREUR DATE ENTETE FICHIER INCORRECTE : %s format DDMMYYYYHH24MI",szDate);
  strcpy(vDate,szDate);
   cout<<"date : "<<szDate<<endl;
  /* EXEC SQL WHENEVER SQLERROR DO sql_error (szMess,1); */ 

/* EXEC SQL SELECT TO_CHAR(TO_DATE(:vDate,'DDMMYYYYHH24MI'),'DDMMYYYYHH24MI') INTO :vDate FROM DUAL; */ 

{
struct sqlexd sqlstm;
sqlstm.sqlvsn = 12;
sqlstm.arrsiz = 2;
sqlstm.sqladtp = &sqladt;
sqlstm.sqltdsp = &sqltds;
sqlstm.stmt = "select TO_CHAR ( TO_DATE ( :b0 , 'DDMMYYYYHH24MI' ) , 'DDMMYY\
YYHH24MI' ) INTO :b0 FROM DUAL ";
sqlstm.iters = (unsigned int  )1;
sqlstm.offset = (unsigned int  )20;
sqlstm.selerr = (unsigned short)1;
sqlstm.cud = sqlcud0;
sqlstm.sqlest = (unsigned char  *)&sqlca;
sqlstm.sqlety = (unsigned short)4352;
sqlstm.occurs = (unsigned int  )0;
sqlstm.sqhstv[0] = (unsigned char  *)vDate;
sqlstm.sqhstl[0] = (unsigned long )13;
sqlstm.sqhsts[0] = (         int  )0;
sqlstm.sqindv[0] = (         short *)0;
sqlstm.sqinds[0] = (         int  )0;
sqlstm.sqharm[0] = (unsigned long )0;
sqlstm.sqadto[0] = (unsigned short )0;
sqlstm.sqtdso[0] = (unsigned short )0;
sqlstm.sqhstv[1] = (unsigned char  *)vDate;
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
if (sqlca.sqlcode < 0) sql_error(szMess,1);
}


}



int main(int argc, char **argv)
{
int iRet;
/* EXEC SQL BEGIN DECLARE SECTION; */ 

//base REV
 char szUserName[20];
 char szPassword[32];

 //base OP
 char szOpUserName[20];
 char szOpPassword[32];
 
 
 char DatePrecFichier[11];
 int  HeurePrecFichier;
 char DynamicTruncate[64];
 
 char bdd[20];
/* EXEC SQL END DECLARE SECTION; */ 

if ( argc < 9 )
        {
        cerr << "Revenus version " + szNumVersion<<endl<<endl;
        cerr << "Usage: Revenus REV_OWNERBASE REV_USER REV_PASSWORD REV_SID OP_USER OP_PASSWORD OP_SID NomduFichierACharger [/f] [/t]" << endl;
        cerr << "/f : option pour forcer le passage d'un fichier resaven anterieur au precedent traite"<<endl;
        cerr << "/t : option pour activer le test des canaux par rapport au contenu de rev_device_types"<<endl;
		cerr << "/traceVec  : option pour activer le dump des donnees lues "<<endl;
        return 1;
        }

g_ForcerFichier = 0;
g_TestCanaux = 0;
g_TraceEcrireVec = 0;
g_forceFBC = 0;
if (argc >= 10)
{
  if (!strcmp (argv[9], "/f"))
    g_ForcerFichier = 1;
  else if (!strcmp (argv[9], "/traceVec"))
    g_TraceEcrireVec = 1;
  else if (!strcmp (argv[9], "/t"))
    g_TestCanaux = 1;
  else if (!strcmp (argv[9], "/b"))
    g_forceFBC = 1;
  else
  {
    cerr << "Option inconnue :"<<argv[9]<<endl;
    return 1;
  }
}
if (argc >= 11)
{
  if (!strcmp (argv[10], "/f"))
    g_ForcerFichier = 1;
  else if (!strcmp (argv[10], "/traceVec"))
    g_TraceEcrireVec = 1;
  else if (!strcmp (argv[10], "/t"))
    g_TestCanaux = 1;
  else if (!strcmp (argv[10], "/b"))
    g_forceFBC = 1;
  else
  {
    cerr << "Option inconnue :"<<argv[10]<<endl;
    return 1;
  }
}
if (argc >= 12)
{
  if (!strcmp (argv[11], "/f"))
    g_ForcerFichier = 1;
  else if (!strcmp (argv[11], "/traceVec"))
    g_TraceEcrireVec = 1;
  else if (!strcmp (argv[11], "/t"))
    g_TestCanaux = 1;
  else if (!strcmp (argv[11], "/b"))
    g_forceFBC = 1;
  else
  {
    cerr << "Option inconnue :"<<argv[11]<<endl;
    return 1;
  }
}

const char *szSid=0;
if (!(szSid=getenv("TWO_TASK")))
   {
   cerr << "FATAL: TWO_TASK not set \n";
   return(2);
   }
if (strcmp(szSid,argv[4]))
   {
   cerr << "FATAL: La base " << argv[4] << " n est pas la base par defaut (" << szSid << ")\n";
   exit(10);
   }


//REV
strcpy(g_OwnerBase,argv[1]);
strcpy(szUserName,argv[2]);
strcpy(szPassword,argv[3]);
strcpy (g_UserName, szUserName); 
strcpy (g_Password, szPassword);

//OP
strcpy(szOpUserName,argv[5]);//JRO DT23805 - ICSRO - Connexion base OP
strcpy(szOpPassword,argv[6]);//JRO DT23805 - ICSRO - Connexion base OP
strcpy (g_OpUserName, szOpUserName);//JRO DT23805 - ICSRO - Connexion base OP
strcpy (g_OpPassword, szOpPassword);//JRO DT23805 - ICSRO - Connexion base OP
strcpy(g_OpSid, argv[7]);//JRO DT23805 - ICSRO - Connexion base OP





/* EXEC SQL WHENEVER SQLERROR DO sql_error("ouverture base de donnees REVENU impossible",1); */ 




/* EXEC SQL CONTEXT ALLOCATE :ctxRevMain; */ 

{
struct sqlexd sqlstm;
sqlstm.sqlvsn = 12;
sqlstm.arrsiz = 2;
sqlstm.sqladtp = &sqladt;
sqlstm.sqltdsp = &sqltds;
sqlstm.stmt = "";
sqlstm.iters = (unsigned int  )1;
sqlstm.offset = (unsigned int  )43;
sqlstm.cud = sqlcud0;
sqlstm.sqlest = (unsigned char  *)&sqlca;
sqlstm.sqlety = (unsigned short)4352;
sqlstm.occurs = (unsigned int  )0;
sqlstm.sqhstv[0] = (unsigned char  *)&ctxRevMain;
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
if (sqlca.sqlcode < 0) sql_error("ouverture base de donnees REVENU impossible",1);
}


/* EXEC SQL CONTEXT USE :ctxRevMain; */ 

/* EXEC SQL CONNECT :szUserName IDENTIFIED BY :szPassword; */ 

{
struct sqlexd sqlstm;
sqlstm.sqlvsn = 12;
sqlstm.arrsiz = 4;
sqlstm.sqladtp = &sqladt;
sqlstm.sqltdsp = &sqltds;
sqlstm.iters = (unsigned int  )10;
sqlstm.offset = (unsigned int  )62;
sqlstm.cud = sqlcud0;
sqlstm.sqlest = (unsigned char  *)&sqlca;
sqlstm.sqlety = (unsigned short)4352;
sqlstm.occurs = (unsigned int  )0;
sqlstm.sqhstv[0] = (unsigned char  *)szUserName;
sqlstm.sqhstl[0] = (unsigned long )20;
sqlstm.sqhsts[0] = (         int  )20;
sqlstm.sqindv[0] = (         short *)0;
sqlstm.sqinds[0] = (         int  )0;
sqlstm.sqharm[0] = (unsigned long )0;
sqlstm.sqadto[0] = (unsigned short )0;
sqlstm.sqtdso[0] = (unsigned short )0;
sqlstm.sqhstv[1] = (unsigned char  *)szPassword;
sqlstm.sqhstl[1] = (unsigned long )32;
sqlstm.sqhsts[1] = (         int  )32;
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
sqlstm.sqlcmax = (unsigned int )100;
sqlstm.sqlcmin = (unsigned int )2;
sqlstm.sqlcincr = (unsigned int )1;
sqlstm.sqlctimeout = (unsigned int )0;
sqlstm.sqlcnowait = (unsigned int )0;
sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
if (sqlca.sqlcode < 0) sql_error("ouverture base de donnees REVENU impossible",1);
}


//EXEC SQL ENABLE THREADS;


cout<<"BATCH TRAITEMENT UNITAIRE DES DONNEES REVENUS.   VERSION " + szNumVersion<<endl;


// JRO DT23805 IC SRO
ListCodeEquipement=g_MapTypeEquipement.getCodeEquipementCorailTgv();


  
iRet=g_InfoBatch.init();
if (iRet<0) { cerr << "FATAL - table Info Batch vide";  exit(10); }

//DM6609: PLF 08/11/10 : Liste des compartiments
string szCmptList = g_InfoBatch.getAssocData("CMPTLIST");
if (szCmptList == (string)"")
 {
  cerr << "FATAL - manque CMPTLIST dans REV_INFO_BATCH\n"; exit(10);
  }
else
  strcpy (g_CmptList, szCmptList.c_str());
cout<<"CMPTLIST="<<g_CmptList<<endl;

//MHUE 11/09/06
string szdateMinTranche=g_InfoBatch.getAssocData ("DATE_MIN_TRANCHE");
if (szdateMinTranche==(string)"")
   {
   cerr << "FATAL - manque DATE_MIN_TRANCHE dans REV_INFO_BATCH\n"; exit(10);
   }
g_dateMinTranche=YmDate(szdateMinTranche);
if (g_dateMinTranche.year()==1900)
   {
   cerr << "FATAL - mauvais format de DATE_MIN_TRANCHE dans REV_INFO_BATCH\n"; exit(10);
   }
string szdateMinNestLevel=g_InfoBatch.getAssocData ("DATE_MIN_NESTLEVEL");
if (szdateMinNestLevel==(string)"")
   {
   cerr << "FATAL - manque DATE_MIN_NESTLEVEL dans REV_INFO_BATCH\n"; exit(10);
   }
g_dateMinNestLevel=YmDate(szdateMinNestLevel);
if (g_dateMinNestLevel.year()==1900)
   {
   cerr << "FATAL - mauvais format de DATE_MIN_NESTLEVEL dans REV_INFO_BATCH\n"; exit(10);
   }
string szClient = g_InfoBatch.getAssocData("CLIENT");
if (szClient == (string)"")
  strcpy (g_Client, "SN"); // valeur par defaut
else
  strcpy (g_Client, szClient.c_str());
cout<<"CLIENT="<<g_Client<<endl;

string szRetention = g_InfoBatch.getAssocData("RETENTION");
if (szRetention == (string)"")
  g_Retention = 3; // valeur par defaut
else
{
  g_Retention = atoi (szRetention.c_str());
  if (g_Retention == 0)
  {
    cout<<"RETENTION incorrecte "<<szRetention<<" valeur 3 par defaut"<<endl;
    cerr<<"RETENTION incorrecte "<<szRetention<<" valeur 3 par defaut"<<endl;
    g_Retention = 3;
  }
}
cout<<"RETENTION="<<g_Retention<<endl;

//MHUE 11/09/06

string sEtat = g_InfoBatch.getAssocData ("STATUS");
if (sEtat != "FINI")
{
  string sDateHeurePrec;
  sDateHeurePrec = g_InfoBatch.getAssocData ("LAST_RESAVEN");
  cout <<DonneHeure()<<" ATTENTION : traitement precedent "<<sDateHeurePrec<<" non termine, purge en cours"<<endl;

  HeurePrecFichier = 100 * atoi (sDateHeurePrec.substr (11, 2).c_str())
                       + atoi (sDateHeurePrec.substr (14, 2).c_str());
  strcpy (DatePrecFichier, sDateHeurePrec.substr (0, 10).c_str());
  cout <<DonneHeure()<<" Purge de REV_SEGMENTS"<<endl;
  /* EXEC SQL DELETE FROM REV_SEGMENTS where (TCN_NUMBER, DATE_PAIEMENT) IN
  (SELECT TCN_NUMBER_AT, DATE_PAIEMENT_AT FROM REV_TCN_A_TRAITER); */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "delete FROM REV_SEGMENTS where ( TCN_NUMBER , DATE_PAIEMENT\
 ) IN ( SELECT TCN_NUMBER_AT , DATE_PAIEMENT_AT FROM REV_TCN_A_TRAITER ) ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )93;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ouverture base de donnees REVENU impossible",1);
}


  /* EXEC SQL COMMIT; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )108;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ouverture base de donnees REVENU impossible",1);
}


  cout <<DonneHeure()<<" Purge de REV_PASSAGERS_PARCOURS"<<endl;
  /* EXEC SQL DELETE FROM REV_PASSAGERS_PARCOURS where (TCN_NUMBER, DATE_PAIEMENT) IN
  (SELECT TCN_NUMBER_AT, DATE_PAIEMENT_AT FROM REV_TCN_A_TRAITER); */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "delete FROM REV_PASSAGERS_PARCOURS where ( TCN_NUMBER , DAT\
E_PAIEMENT ) IN ( SELECT TCN_NUMBER_AT , DATE_PAIEMENT_AT FROM REV_TCN_A_TRAIT\
ER ) ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )123;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ouverture base de donnees REVENU impossible",1);
}


  /* EXEC SQL COMMIT; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )138;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ouverture base de donnees REVENU impossible",1);
}


  cout <<DonneHeure()<<" Purge de REV_TCN"<<endl;
  /* EXEC SQL DELETE FROM REV_TCN where (TCN_NUMBER, DATE_PAIEMENT) IN
  (SELECT TCN_NUMBER_AT, DATE_PAIEMENT_AT FROM REV_TCN_A_TRAITER); */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "delete FROM REV_TCN where ( TCN_NUMBER , DATE_PAIEMENT ) IN\
 ( SELECT TCN_NUMBER_AT , DATE_PAIEMENT_AT FROM REV_TCN_A_TRAITER ) ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )153;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ouverture base de donnees REVENU impossible",1);
}


  /* EXEC SQL COMMIT; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )168;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ouverture base de donnees REVENU impossible",1);
}


  cout <<DonneHeure()<<" Truncate REV_TCN_A_TRAITER"<<endl;
  sprintf (DynamicTruncate, "TRUNCATE TABLE %s.REV_TCN_A_TRAITER", g_OwnerBase);
  /* EXEC SQL EXECUTE IMMEDIATE :DynamicTruncate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )183;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)DynamicTruncate;
  sqlstm.sqhstl[0] = (unsigned long )64;
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
  if (sqlca.sqlcode < 0) sql_error("ouverture base de donnees REVENU impossible",1);
}


  cout <<DonneHeure()<<" Purge de REV_ANNULATION_ECHANGE"<<endl;
  /* EXEC SQL DELETE FROM REV_ANNULATION_ECHANGE where (TCN_ANNULE, DATE_TCN) IN
  (SELECT TCN_NUMBER_AA, DATE_PAIEMENT_AA FROM REV_TCN_A_ANNULER
   WHERE DATE_FICHIER = :DatePrecFichier AND HEURE_FICHIER = :HeurePrecFichier); */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "delete FROM REV_ANNULATION_ECHANGE where ( TCN_ANNULE , DAT\
E_TCN ) IN ( SELECT TCN_NUMBER_AA , DATE_PAIEMENT_AA FROM REV_TCN_A_ANNULER WH\
ERE DATE_FICHIER = :b0 AND HEURE_FICHIER = :b1 ) ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )202;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)DatePrecFichier;
  sqlstm.sqhstl[0] = (unsigned long )11;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&HeurePrecFichier;
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
  if (sqlca.sqlcode < 0) sql_error("ouverture base de donnees REVENU impossible",1);
}


  /* EXEC SQL COMMIT; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )225;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ouverture base de donnees REVENU impossible",1);
}


  cout <<DonneHeure()<<" Purge de REV_TCN_A_ANNULER"<<endl;
  /* EXEC SQL DELETE FROM REV_TCN_A_ANNULER 
  WHERE DATE_FICHIER = :DatePrecFichier AND HEURE_FICHIER = :HeurePrecFichier; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "delete FROM REV_TCN_A_ANNULER WHERE DATE_FICHIER = :b0 AND \
HEURE_FICHIER = :b1 ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )240;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)DatePrecFichier;
  sqlstm.sqhstl[0] = (unsigned long )11;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&HeurePrecFichier;
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
  if (sqlca.sqlcode < 0) sql_error("ouverture base de donnees REVENU impossible",1);
}


  g_ForcerFichier = 1;
}

iRet=g_MapTarifs.init();
if ((iRet<0) && (strcmp(g_Client,"TH"))) { cerr << "FATAL - liste des tarifs vide"<<endl;  exit(10); }

iRet=g_MapTypePassager.init();
if ((iRet<0) && (strcmp(g_Client,"TH"))) { cerr << "FATAL - liste des typePassager vide"<<endl;  exit(10); }

iRet=g_MapClassMapping.init();
if ((iRet<0) && (strcmp(g_Client,"TH"))) { cerr << "FATAL - liste des ClassMapping vide"<<endl;  exit(10); }

iRet=g_MapDeviceType.init();
if (iRet<0) { cerr << "FATAL - liste des DeviceType vide"<<endl;  exit(10); }

cout<<DonneHeure()<<" Lecture Map Tranche non yield"<<endl;
iRet=g_MapTrNonYield.init(); 

cout<<DonneHeure()<<" Lecture Map Tranche Leg"<<endl;
iRet=g_MapTrLeg.init(); 
if (iRet<0) { cerr << "WARNING - liste des tranche / leg vide !!";}

cout<<DonneHeure()<<" Debut traitement fichier resaven"<<endl;
g_InfoBatch.setAssocData ("STATUS", "EN COURS");

g_NbThreadLecteur = 0;

// FIXME_NPI: Possible traitement du CR137 - Serialisation des traitements d'ecriture, lecture et annulation des vecteurs
//YmRevThreadEcrireVec* pThreadFillVec = new YmRevThreadEcrireVec(argv[8]); //JRO DT23805 IC SRO - AJOUT CONNEXION OP
//YmRevThreadLireVec* pThreadReadVec = new YmRevThreadLireVec();
//YmRevThreadLireAnnu* pThreadReadAnnu = new YmRevThreadLireAnnu();
//g_EcrireVecEnCours = true;
//pThreadFillVec->go();
//
//// FIXME_VME: Possible traitement du CR137 en commentant la ligne if (g_TraceEcrireVec)
////if (g_TraceEcrireVec)
////{ // Si debug lecture du Resaven, on attend la fin avant de lancer l'ecriture en base.
//  while (g_EcrireVecEnCours)
//    sleep(6);
////}
//
//pThreadReadVec->go();
//
////JMG 02/01/08, on attend la fin de EcrireVec avant de lancer traitement des annulations,
//// car depuis que les annulations sont passe en mode sous structure, elle doivent etre cree lors de la lecture de la
//// sous structure 00 et eventuellement complete en lecture de la sous structure 04.
//// mais pour cela, il ne faut pas que le pointeur sur l'annulation puisse avoir ete consomme par le thread de lecture
//// du vecteur des annulations.
//while (g_EcrireVecEnCours)
//  sleep(6);
//pThreadReadAnnu->go();
//// Si on abandonne la recuperation des codes gares origine et destination dans rev_annulation_echange,i
//// on pourra supprimer le while (g_EcrireVecEnCours) sleep(6); ci-dessus.
//while (g_NbThreadLecteur)
//  sleep(6);
cout<<DonneHeure()<<" EcrireVec"<<endl;
YmRevEcrireVec EcrireVec(argv[8]);
EcrireVec.Start();
cout<<DonneHeure()<<" LireVec"<<endl;
YmRevLireVec LireVec;
LireVec.Start();
cout<<DonneHeure()<<" LireAnnu"<<endl;
YmRevLireAnnu LireAnnu;
LireAnnu.Start();
////////////////////////////////////////////

cout<<"Nombre de compensation tarifaire trouves:"<<g_MapTarifs.getNbFindMapTarif()<<endl;
cout<<"Nombre de compensation par type passager trouves:"<<g_MapTypePassager.getNbFindMapTyPa()<<endl;
//Prise en compte des retraits
YmRevLireRetraits LireRetraits;
LireRetraits.Start();

//Prise en compte des annulations dans g_MapTpOD et g_MapTpFBC
YmRevAnnuTpOD AnnuTpOD;
AnnuTpOD.TraiteAnnuTpOD();

//Recopie de TPREV_NON_TRAITER dans g_MapTpOD
YmRevTpNonTraite TpNonTraite;
TpNonTraite.RecupTpNonTraite();

//Recopie de TPREV_FBC_NON_TRAITER dans g_MapTpFBC
YmRevTpFBCNonTraite TpFBCNonTraite;
TpFBCNonTraite.RecupTpFBCNonTraite();

sprintf (DynamicTruncate, "TRUNCATE TABLE %s.TPREV_OD", g_OwnerBase);
/* EXEC SQL EXECUTE IMMEDIATE :DynamicTruncate; */ 

{
struct sqlexd sqlstm;
sqlstm.sqlvsn = 12;
sqlstm.arrsiz = 4;
sqlstm.sqladtp = &sqladt;
sqlstm.sqltdsp = &sqltds;
sqlstm.stmt = "";
sqlstm.iters = (unsigned int  )1;
sqlstm.offset = (unsigned int  )263;
sqlstm.cud = sqlcud0;
sqlstm.sqlest = (unsigned char  *)&sqlca;
sqlstm.sqlety = (unsigned short)4352;
sqlstm.occurs = (unsigned int  )0;
sqlstm.sqhstv[0] = (unsigned char  *)DynamicTruncate;
sqlstm.sqhstl[0] = (unsigned long )64;
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
if (sqlca.sqlcode < 0) sql_error("ouverture base de donnees REVENU impossible",1);
}

 // fait ici pour grouper tous les truncates dans le main.
g_MapTpOD.InsertTPREVOD();
g_MapTpOD.UpdateRevSegments();
sprintf (DynamicTruncate, "TRUNCATE TABLE %s.TPREV_FBC_OD", g_OwnerBase);
/* EXEC SQL EXECUTE IMMEDIATE :DynamicTruncate; */ 

{
struct sqlexd sqlstm;
sqlstm.sqlvsn = 12;
sqlstm.arrsiz = 4;
sqlstm.sqladtp = &sqladt;
sqlstm.sqltdsp = &sqltds;
sqlstm.stmt = "";
sqlstm.iters = (unsigned int  )1;
sqlstm.offset = (unsigned int  )282;
sqlstm.cud = sqlcud0;
sqlstm.sqlest = (unsigned char  *)&sqlca;
sqlstm.sqlety = (unsigned short)4352;
sqlstm.occurs = (unsigned int  )0;
sqlstm.sqhstv[0] = (unsigned char  *)DynamicTruncate;
sqlstm.sqhstl[0] = (unsigned long )64;
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
if (sqlca.sqlcode < 0) sql_error("ouverture base de donnees REVENU impossible",1);
}

 // fait ici pour grouper tous les truncates dans le main.
g_MapTpFBC.InsertTPREVFBC();
AnnuTpOD.SupprAnnuTraitees();
sprintf (DynamicTruncate, "TRUNCATE TABLE %s.TPREV_NON_TRAITE", g_OwnerBase);
/* EXEC SQL EXECUTE IMMEDIATE :DynamicTruncate; */ 

{
struct sqlexd sqlstm;
sqlstm.sqlvsn = 12;
sqlstm.arrsiz = 4;
sqlstm.sqladtp = &sqladt;
sqlstm.sqltdsp = &sqltds;
sqlstm.stmt = "";
sqlstm.iters = (unsigned int  )1;
sqlstm.offset = (unsigned int  )301;
sqlstm.cud = sqlcud0;
sqlstm.sqlest = (unsigned char  *)&sqlca;
sqlstm.sqlety = (unsigned short)4352;
sqlstm.occurs = (unsigned int  )0;
sqlstm.sqhstv[0] = (unsigned char  *)DynamicTruncate;
sqlstm.sqhstl[0] = (unsigned long )64;
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
if (sqlca.sqlcode < 0) sql_error("ouverture base de donnees REVENU impossible",1);
}

 // fait ici pour grouper tous les truncates dans le main.
g_MapTpOD.InsertTPREVNONTRAITE();
sprintf (DynamicTruncate, "TRUNCATE TABLE %s.TPREV_FBC_NON_TRAITE", g_OwnerBase);
/* EXEC SQL EXECUTE IMMEDIATE :DynamicTruncate; */ 

{
struct sqlexd sqlstm;
sqlstm.sqlvsn = 12;
sqlstm.arrsiz = 4;
sqlstm.sqladtp = &sqladt;
sqlstm.sqltdsp = &sqltds;
sqlstm.stmt = "";
sqlstm.iters = (unsigned int  )1;
sqlstm.offset = (unsigned int  )320;
sqlstm.cud = sqlcud0;
sqlstm.sqlest = (unsigned char  *)&sqlca;
sqlstm.sqlety = (unsigned short)4352;
sqlstm.occurs = (unsigned int  )0;
sqlstm.sqhstv[0] = (unsigned char  *)DynamicTruncate;
sqlstm.sqhstl[0] = (unsigned long )64;
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
if (sqlca.sqlcode < 0) sql_error("ouverture base de donnees REVENU impossible",1);
}

 // fait ici pour grouper tous les truncates dans le main.
g_MapTpFBC.InsertTPREVFBCNONTRAITE();
g_MapTpOD.Clear();
g_MapTpFBC.Clear();
sprintf (DynamicTruncate, "TRUNCATE TABLE %s.REV_TCN_A_TRAITER", g_OwnerBase);
/* EXEC SQL EXECUTE IMMEDIATE :DynamicTruncate; */ 

{
struct sqlexd sqlstm;
sqlstm.sqlvsn = 12;
sqlstm.arrsiz = 4;
sqlstm.sqladtp = &sqladt;
sqlstm.sqltdsp = &sqltds;
sqlstm.stmt = "";
sqlstm.iters = (unsigned int  )1;
sqlstm.offset = (unsigned int  )339;
sqlstm.cud = sqlcud0;
sqlstm.sqlest = (unsigned char  *)&sqlca;
sqlstm.sqlety = (unsigned short)4352;
sqlstm.occurs = (unsigned int  )0;
sqlstm.sqhstv[0] = (unsigned char  *)DynamicTruncate;
sqlstm.sqhstl[0] = (unsigned long )64;
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
if (sqlca.sqlcode < 0) sql_error("ouverture base de donnees REVENU impossible",1);
}

 // fait ici pour grouper tous les truncates dans le main.

g_InfoBatch.setAssocData ("STATUS", "FINI");
cout<<DonneHeure()<<" Fin traitement resaven"<<endl;

  /* Fermeture de la connection avec la base REV */
  /* EXEC SQL WHENEVER SQLERROR DO sql_error("LiberationMain-fermeture database impossible pour le Main ",0); */ 


  /* EXEC SQL CONTEXT USE :ctxRevMain; */ 

  /* EXEC SQL COMMIT WORK RELEASE; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )358;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt(&ctxRevMain, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("LiberationMain-fermeture database impossible pour le Main ",0);
}


  /* EXEC SQL CONTEXT FREE :ctxRevMain; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )373;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&ctxRevMain;
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
  if (sqlca.sqlcode < 0) sql_error("LiberationMain-fermeture database impossible pour le Main ",0);
}


return 0;
}
