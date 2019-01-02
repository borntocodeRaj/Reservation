//---------------------------------------------------------------------------------------------------------
// Lecture des donness RESAVEN placee dans le vecteur par EcrireVec
// Nicolas PINAUD
// --------------------------------------------------------------------------------------------------------

#ifndef YmRevLireAnnu_h
#define YmRevLireAnnu_h 1


#include <YmRevGlobal.h>

class YmRevLireAnnu
{
  public:
  YmRevLireAnnu() ;
  ~YmRevLireAnnu();

  void Start();

  private:

  // Fait delete sur tous les YmRevAnnulation* contenu dans bufVAnnu et vide ce vecteur.
  void purgeBufAnnu();

  // place MAX_NBTCN_IN_BUF YmRevAnnulation* dans bufVAnnu (ou moins si g_VAnnulation en contient moins)
  int  fillBufAnnu();

  // Insertion dans la table REV_ANNULATION_ECHANGE
  void InsertAnnulation();

  vector<YmRevAnnulation *> bufVAnnu;
  
  int nbAnnuTotal;
};

#endif
