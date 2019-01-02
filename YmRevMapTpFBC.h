#pragma ident "%Z% FileName: $RCSfile: YmRevMapTpFBC.h,v $ Version: $Revision: 1.1 $ Date: $Date: 2008/02/14 17:44:03 $ %Z %"

//## Module: YmRevMapTpFBC
//SFD
//  Name:    YmRevMapTpFBC.h
//  Author:  JM. Grugeaux
//  Desc:    description de la map des tprev_fbc
//EFD



#ifndef YmRevMapTpFBC_h
#define YmRevMapTpFBC_h 1

//standard includes
#include <map>
#include <string>

#include <YmRevTpFBC.h>

typedef map<string, YmRevTpFBC* , less<string> > MapTpFBCType;

class YmRevMapTpFBC
  {
  public:
   YmRevMapTpFBC();
   ~YmRevMapTpFBC();

   // test si un YmRevTpFBC correspondant aux parametre existe deja dans la map.
   // La date est passe au format "dd/mm/yyyy"
   YmRevTpFBC* isInMap(int tranche_no, char* date_od, string orig, string dest, string fare_basis_code);
                      //retourne un pointeur sur YmRevTpFBC si deja present
   void Add (YmRevTpFBC* pTpFBC);

   void Clear(); // Vidage de la Map

   void InsertAndPurge(); // Insertion de la Map dans la table TPREV_OD et purge de la Map
   void InsertTPREVFBC();
   void InsertTPREVFBCNONTRAITE();

  private:
   MapTpFBCType _MapTpFBC;
  };

#endif
