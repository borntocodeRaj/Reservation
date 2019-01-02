#pragma ident "%Z% FileName: $RCSfile: YmRevMapTrNonYield.h,v $ Version: $Revision: 1.3 $ Date: $Date: 2009/02/20 13:10:57 $ %Z %"

//## Module: YmRevMapTrNonYield
//SFD
//  Name:    YmRevMapTrNonYield.h
//  Author:  M. Hue
//  Desc:    description de la map de la relation classe de service/classe de controle (nest level)
//EFD



#ifndef YmRevMapTrNonYield_h
#define YmRevMapTrNonYield_h 1

//standard includes
#include <map>
#include <string>

//application includes
#include <YmRevTrNonYield.h>

typedef map<string, YmRevTrNonYield*, less<string> > mapTrNonYieldType;

class YmRevMapTrNonYield
  {
  public:
   YmRevMapTrNonYield(){;};
   ~YmRevMapTrNonYield();

   int init(); //lecture des donnees dans les tables THALES
   short isInMap(int lTrancheNo_,  YmDate& DptDate_); //isInMap si trancheNo existe pour date D, D-1 ou D+1
						     // retour =0 is pas trouve, 1 si OK

  private:
   mapTrNonYieldType _MapTrNonYield;
  };

#endif
