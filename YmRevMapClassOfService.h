//## Module: YmRevMapClassOfService
//SFD
//  Name:    YmRevMapClassOfService.h
//  Author:  PL.FLORENT 
//  Desc:    description de la map des classes de service 
//EFD





#ifndef YmRevMapClassOfService_h
#define YmRevMapClassOfService_h 1

//standard includes
#include <map>
#include <string>

//application includes
#include <YmRevClassOfService.h>

typedef multimap<string, YmRevClassOfService*, less<string> > MapClassOfServiceType;

class YmRevMapClassOfService
  {
  public:
   YmRevMapClassOfService();
   ~YmRevMapClassOfService();
   int getNbFindMapClOfSe() { return nbFindMapClOfSe; }
   int getSize() { return _MapClassOfService.size();}


   int init(); //initialisation de la map a partir de la base
   YmRevClassOfService* isInMap(string sClassOfService, YmDate DateDepart);
   //retourne pointeur si OK, NULL sinon

  private:
   MapClassOfServiceType _MapClassOfService;
   int nbFindMapClOfSe; // debug, compteur de fois ou on a trouve une compensation
  };

#endif
