
//## Module: YmRevMapClassMapping
//SFD
//  Name:    YmRevMapClassMapping.h
//  Author:  PL. FLORENT
//  Desc:    description de la map des classes mapping
//EFD



#ifndef YmRevMapClassMapping_h
#define YmRevMapClassMapping_h 1

//standard includes
#include <map>
#include <string>

//application includes
#include <YmRevClassMapping.h>

typedef map<string, YmRevClassMapping*, less<string> > MapClassMappingType;

class YmRevMapClassMapping
  {
  public:
   YmRevMapClassMapping();
   ~YmRevMapClassMapping();

   int init(); //initialisation de la map a partir de la base
   YmRevClassMapping* isInMap(string szClassMapping); //retourne pointeur si OK, NULL sinon

  private:
   MapClassMappingType _MapClassMapping;
  };

#endif
