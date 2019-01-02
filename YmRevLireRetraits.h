//---------------------------------------------------------------------------------------------------------
// lecture des donness retraits
// Jean-Michel GRUGEAUX
// --------------------------------------------------------------------------------------------------------

#ifndef YmRevLireRetraits_h
#define YmRevLireRetraits_h 1


#include <YmRevGlobal.h>

//Contrairement a LireVec et LireAnnu, cette classe n'est pas un thread.
//Elle doit etre activee a la fin de EcrireVec.

class YmRevLireRetraits
{
  public:
  YmRevLireRetraits() ;
  ~YmRevLireRetraits();

  void Start();

  private:
  int  fillBufRetrait();
  void UpdateRetraits();

  int nbRetraits;

};

#endif
