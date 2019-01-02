//---------------------------------------------------------------------------------------------------------
// Lecture des donness RESAVEN placee dans le vecteur par EcrireVec
// Nicolas PINAUD
// --------------------------------------------------------------------------------------------------------

#ifndef YmRevLireVec_h
#define YmRevLireVec_h 1


#include <YmRevGlobal.h>

class YmRevLireVec
{
  public:
  YmRevLireVec() ;
  ~YmRevLireVec();

  void Start();

  private:

  // Fait delete sur tous les YmRevTcn* contenu dans bufVTcn et vide ce vecteur.
  void purgeBufTcn();

  // place MAX_NBTCN_IN_BUF YmTcnRev* dans bufVTcn (ou moins si g_VTcn en contient moins)
  int  fillBufTcn();

  // compte le nombre de YmRevPassagersParcours et YmRevSegment dans bufVTcn,
  // mais arrete de compte lorsque l'on atteind la limite des tableaux utilise pour les insert.
  // Renvoi le nombre de YmRevTcn qu'il faut effectivement conserve dans bufVTcn
  int countPaPaSegInBuf (int& nbPaPa, int& nbSeg);

  // Insertion dans la table REV_SEGMENTS
  void InsertSegment();

  // Insertion dans la table REV_PASSAGERS_PARCOURS
  void InsertPassagersParcours();
  void InsertFbcPassagersParcours();

  // Insertion dans la table REV_TCN
  void InsertTCN();

  // Ajout dans la Map d'insertion dans TPREV_OD
  //JRO - IC SRO - DT 23805 - Ajout du flag isTrain
  void AddInMapTpOD (YmRevPassagersParcours* pPasPar, YmRevSegments* pSegment, int isTrain);

  vector<YmRevTcn *> bufVTcn;

  int nbTCNtotal;
  int nbPPtotal;
  int nbSEGtotal;
};

#endif
