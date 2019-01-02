//## Module: YmRevClassMapping
//SFD
//  Name:    YmRevClassMapping.h
//  Author:  M. Hue
//  Desc:    description de la classe qui mappe la table des plages des ClassMapping : SC_CLASS_MAPPING
//EFD



#ifndef YmRevClassMapping_h
#define YmRevClassMapping_h 1

#include <string>

class YmRevClassMapping
  {
  public:
   YmRevClassMapping(string szClassOrig, string szClassDest);
   ~YmRevClassMapping() {;}

   string& get_ClassOrig() { return _szClassOrig; }
   string& get_ClassDest() { return _szClassDest; }

  private:
   string _szClassOrig;
   string _szClassDest;
  };

#endif

