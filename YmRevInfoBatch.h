#pragma ident "%Z% FileName: $RCSfile: YmRevInfoBatch.h,v $ Version: $Revision: 1.1 $ Date: $Date: 2006/03/28 17:22:35 $ %Z %"

//## Module: YmRevInfoBatch
//SFD
//  Name:    YmRevInfoBatch.h
//  Author:  JM. Grugeaux
//  Desc:    Lecture et mise a jour rev_info_batch
//EFD



#ifndef YmRevInfoBatch_h
#define YmRevInfoBatch_h 1

//standard includes
#include <map>
#include <string>

typedef map<string, string, less<string> > InfoBatchType;

class YmRevInfoBatch
  {
  public:
   YmRevInfoBatch();
   ~YmRevInfoBatch();

   int init(); //initialisation de la map a partir de la base
   string getAssocData (string key_info); // renvoi la valeur associe a la clef key_info. Vide si non trouve
   void setAssocData (string key_info, string assoc_data); // met a jour la Map en memoire, et aussi la table rev_info_batch

  private:
   InfoBatchType _InfoBatch;
  };

#endif
