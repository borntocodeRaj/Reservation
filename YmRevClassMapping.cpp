
//## Module: YmRevClassMapping
//SFD
//  Name:    YmRevClassMapping.cpp
//  Author:  PL. FLORENT
//  Desc:    contenu de la classe qui mappe la table des ClassMapping : SC_CLASS_MAPPING
//EFD

using namespace std;

#include <YmRevClassMapping.h>

YmRevClassMapping::YmRevClassMapping(string szClassOrig, string szClassDest)
{
_szClassOrig=szClassOrig;
_szClassDest=szClassDest;
}

