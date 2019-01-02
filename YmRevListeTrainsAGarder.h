#pragma ident "%Z% FileName: $RCSfile: YmRevListeTrainsAGarder.h,v $ Version: $Revision: 1.1 $ Date: $Date: 2006/02/24 15:33:26 $ %Z %"

//## Module: YmRevListeTrainsAGarder
//SFD
//  Name:    YmRevListeTrainsAGarder.h
//  Author:  M. Hue
//  Desc:    description de la liste des trains a garder
//EFD



#ifndef YmRevListeTrainsAGarder_h
#define YmRevListeTrainsAGarder_h 1

//standard includes
#include <list>

//application includes
#include <YmRevTrainsAGarder.h>

class YmRevListeTrainsAGarder
  {
  public:
   YmRevListeTrainsAGarder();
   ~YmRevListeTrainsAGarder();

   int init(); //initialisation de la liste a partir de la base
   int isInListe(int iNumTrain); //retourne 1 si train dans une plage, 0 sinon

  private:
   list<YmRevTrainsAGarder *> _ListeTrainsAGarder;
  };

#endif
