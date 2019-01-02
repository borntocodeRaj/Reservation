#pragma ident "%Z% FileName: $RCSfile: YmRevMapDeviceType.h,v $ Version: $Revision: 1.4 $ Date: $Date: 2006/11/24 13:50:52 $ %Z %"

//## Module: YmRevMapDeviceType
//SFD
//  Name:    YmRevMapDeviceType.h
//  Author:  JM. Grugeaux
//  Desc:    description de la map des codes tarifs
//EFD



#ifndef YmRevMapDeviceType_h
#define YmRevMapDeviceType_h 1

//standard includes
#include <map>
#include <string>

//application includes
#include <YmRevDeviceType.h>

typedef map<string, YmRevDeviceType*, less<string> > MapDeviceTypeType;

class YmRevMapDeviceType
  {
  public:
   YmRevMapDeviceType();
   ~YmRevMapDeviceType();

   int init(); //initialisation de la map a partir de la base
   bool isInMap(string szDeviceType); //retourne TRUE si trouve, FALSE sinon
   YmRevDeviceType* findInMap(string szDeviceType); //retourne pointeur si OK, NULL sinon

  private:
   MapDeviceTypeType _MapDeviceType;
  };

#endif
