#ifndef YMREVGLOBAL_H
#define YMREVGLOBAL_H
// SCCS Version
#pragma ident "%Z% FileName: $RCSfile: YmRevGlobal.h,v $ Version: $Revision: 1.22 $ Date: $Date: 2012/05/22 13:25:59 $ %Z%"
#include <vector>
#include <cstring>
#include <cstdlib>
#include <YmRevMapTarifs.h>
#include <YmRevMapTypePassager.h>
#include <YmRevMapDeviceType.h>
#include <YmRevMapClassMapping.h>
#include <YmRevTcn.h>
#include <YmRevAnnulation.h>
#include <YmRevRetraits.h>
#include <YmRevMapTrNonYield.h>
#include <YmRevMapTrLeg.h>
#include <YmRevMapTpOD.h>
#include <YmRevMapTpFBC.h>
#include <YmRevInfoBatch.h>
#include <YmRevMapTypeEquipement.h>
#include <stdio.h>
#include </usr/lib/oracle/11.2/client64/precomp/public/sqlca.h>
#include <iostream>
// Threads includes
#ifdef POSIX_THREAD
 #include <pthread.h>
#else
 #include <thread.h>
#endif

#ifdef POSIX_THREAD
 #define LOCK_MUTEX(s) pthread_mutex_lock(s)
 #define UNLOCK_MUTEX(s) pthread_mutex_unlock(s)
 #define THR_SELF() pthread_self()
#else
 #define LOCK_MUTEX(s) mutex_lock(s)
 #define UNLOCK_MUTEX(s) mutex_unlock(s)
 #define THR_SELF() thr_self()
#endif

#ifdef POSIX_THREAD
  pthread_mutex_t g_MutexVTcn;
  pthread_mutex_t g_MutexVAnnulation;
  pthread_mutex_t g_MutexVRetraits;
#else
  mutex_t g_MutexVTcn;
  mutex_t g_MutexVAnnulation;
  mutex_t g_MutexVRetraits;
#endif
extern char g_CmptList[10];//chaine des compartiments  pouvant etre rencontres
extern char g_UserName[20];
extern char g_Password[32];
extern char g_OpUserName[20];//JRO DT23805 - ICSRO - Connexion base OP     Password de la base OP
extern char g_OpPassword[32];//JRO DT23805 - ICSRO - Connexion base OP     Password de la base OP
extern char g_OpSid[20];//JRO DT23805 - ICSRO - Connexion base OP     Password de la base OP

extern char g_OwnerBase[20];
extern char g_Client[3];
extern char g_szDateFichier[11]; // date de lancement de l'appli au format dd/mm/aaaa
extern char g_szDateFichierShort[9]; // date de lancement de l'appli au format dd/mm/aa
extern int  g_HeureFichier;      // heure de lancement de l'applu au format hh*100 + mi.
extern int  g_ForcerFichier;     // si 1, on ne controle pas que la date/heure du resaven soit superieure
                                 // a celui du precedent traitement. Vaut 0 sinon.
extern int  g_TraceEcrireVec;    // Si == 1, dump de ce qui a ete lu
extern int  g_TestCanaux;    // Si == 1, on test les canaux.
extern int  g_Retention;     // duree de retention dans la table TPREV_NON_TRAITE et TPREV_FBC_NON_TRAITE
extern int  g_forceFBC;	     // Pour forcer traitement FBC en environnement SNCF (debug purpose)
extern  void sql_error(char *, int);
extern void ctrl_date_entete_fichier(char *);

extern void sql_warn (char* szMessErr, int numtcn, int &nbTot); // affiche erreur et numero tcn et decremente nbTot

extern YmRevMapTarifs g_MapTarifs;
extern YmRevMapTypePassager g_MapTypePassager;
extern YmRevMapClassMapping g_MapClassMapping;
extern YmRevMapTrNonYield g_MapTrNonYield;
extern YmRevMapTrLeg g_MapTrLeg;	// map en memoire de la table REV_TRANCHES_LEGS // JRO DT 23805 avec no de tranches
extern YmRevMapTrLeg g_MapTrLegTrainNo;	// map en memoire de la table REV_TRANCHES_LEGS // JRO DT 23805 avec no de trains
extern YmRevMapTpOD  g_MapTpOD;		// map de preparation d'insertion dans la table TPREV_OD
extern YmRevMapTpFBC  g_MapTpFBC;	// map de preparation d'insertion dans la table TPREV_FBC_OD
extern YmRevInfoBatch  g_InfoBatch;	// map representant la table rev_info_batch
extern YmRevMapDeviceType g_MapDeviceType;
extern YmRevMapTypeEquipement g_MapTypeEquipement; //types equipement en base OP JRO DT23805 IC SRO
extern bool g_EcrireVecEnCours; // Boolean de synchronisation des Threads EcrireVec et LireVec
			 // sur l'utilisation du vecteur d'echange. Mis a jour par EcrireVec et teste par LireVec
extern int g_NbThreadLecteur;   // Nombre de Thread lecteur actifs

// vecteurs de stockage des Tcn, Annulations, Retraits
extern vector<YmRevTcn *> g_VTcn;
extern vector<YmRevAnnulation *> g_VAnnulation;
extern vector<YmRevRetraits *> g_VRetraits;
// Vecteurs de stockage des codes équipements pour TGV et CORAIL en base
extern vector<string> ListCodeEquipement; //JRO DT23805 IC SRO 

extern YmDate g_dateMinTranche; // date de la premiere tranche a prendre en compte MHUE 11/09/06
extern YmDate g_dateMinNestLevel; //date du premier fichier avec nest level MHUE 11/09/06

#endif
