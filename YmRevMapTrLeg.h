#pragma ident "%Z% FileName: $RCSfile: YmRevMapTrLeg.h,v $ Version: $Revision: 1.4 $ Date: $Date: 2009/02/20 13:10:57 $ %Z %"

//## Module: YmRevMapTrLeg
//SFD
//  Name:    YmRevMapTrLeg.h
//  Author:  JM. Grugeaux
//  Desc:    description de la map des tranche leg
//EFD



#ifndef YmRevMapTrLeg_h
#define YmRevMapTrLeg_h 1

//standard includes
#include <map>
#include <string>

typedef struct TrLeg {
	char dpt_date_tr[11];
        short indic_tgv;
       };

typedef map<string, TrLeg, less<string> > MapTrLegType;

class YmRevMapTrLeg
  {
  public:
   YmRevMapTrLeg();
   ~YmRevMapTrLeg();

   int init(); //initialisation de la map a partir de la base
   TrLeg InMap(int tranche_no, string leg_orig, string leg_dest, char* date_depart); //retourne une structure TrLeg MHUE 11/09/06
  			// Si non trouve renvoi un TrLeg Dummy : dpt_date_tr = "01/01/2000", indic_tgv = 2;

     TrLeg InMap(int tranche_no, string leg_orig, string leg_dest, char* date_depart, int isTrain); //JRO - IC SRO- DT 23805 - version surcharg� dans le cas ou le flag
	 //isTrain a une importance dans la recherche dans la map
	 // JRO IC SRO - ANO 87361 m�thode qui r�cup�re un num�ro de tranche dans la table REV_TRANCHES_LEGS pour un dpt_date et un num�ro de train donn�e
	 int getNoTranche(int NoTrain, char dpt_date[11]);
  private:
   MapTrLegType _MapTrLeg;
  };

#endif
