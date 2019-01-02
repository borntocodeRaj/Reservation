#pragma ident "%Z% FileName: $RCSfile: YmRevMapTpOD.h,v $ Version: $Revision: 1.5 $ Date: $Date: 2009/02/02 10:41:09 $ %Z %"

//## Module: YmRevMapTpOD
//SFD
//  Name:    YmRevMapTpOD.h
//  Author:  JM. Grugeaux
//  Desc:    description de la map des tprev_od
//EFD



#ifndef YmRevMapTpOD_h
#define YmRevMapTpOD_h 1

//standard includes
#include <map>
#include <string>

#include <YmRevTpOD.h>

typedef map<string, YmRevTpOD* , less<string> > MapTpODType;

class YmRevMapTpOD
  {
  public:
   YmRevMapTpOD();
   ~YmRevMapTpOD();

   // test si un YmRevTpOD correspondant aux parametre existe deja dans la map.
   // La date est passe au format "dd/mm/yyyy"
   // JRO - DT23805 - IC SRO - Ajout du flag isTrain
   YmRevTpOD* isInMap(int tranche_no, char* date_od, string orig, string dest, string class_of_service, int num_palier,
                      int nest_level,int scx, int isTrain); //retourne un pointeur sur YmRevTpOD si deja present

   void Add (YmRevTpOD* pTpOD);

   void Clear(); // Vidage de la Map

   void InsertAndPurge(); // Insertion de la Map dans la table TPREV_OD et purge de la Map
   void InsertTPREVOD();
   void InsertTPREVNONTRAITE();
   void UpdateRevSegments();

  private:
   MapTpODType _MapTpOD;
  };

#endif
