#pragma ident "%Z% FileName: $RCSfile: YmRevAnnuTpOD.h,v $ Version: $Revision: 1.3 $ Date: $Date: 2006/04/14 10:19:20 $ %Z %"

//## Module: YmRevAnnuTpOD
//SFD
//  Name:    YmRevAnnuTpOD.h
//  Author:  JM. Grugeaux
//  Desc:    Prise en compte des annulation dans g_MapTpOD
//EFD



#ifndef YmRevAnnuTpOD_h
#define YmRevAnnuTpOD_h 1

//standard includes
#include <map>
#include <string>


class YmRevAnnuTpOD
  {
  public:
   YmRevAnnuTpOD();
   ~YmRevAnnuTpOD();

   // Met a jour les date_tcn dans les tables rev_annulation_echange et rev_tcn_a_annuler
   // pour les lignes ou la date_tcn est egale a '01/01/2000', la valeur dummy.
   // La date est prise dans rev_tcn en prenant la date max pour le TCN de meme numero.
   // Ensuite:
   // Lecture en base les infos annulations et met a jour la Map d'insertion vers la table TPREV_OD
   int TraiteAnnuTpOD();

   void SupprAnnuTraitees(); //Supprime de la table rev_tcn_a_annuler les annulations prise en compte

  };

#endif
