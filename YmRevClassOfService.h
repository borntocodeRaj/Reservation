//## Module: YmRevClassOfService
//SFD
//  Name:    YmRevClassOfService.h
//  Author:  PL.FLORENT
//  Desc:    description de la classe qui mappe la table des plages de ClassOfService 
//EFD




#ifndef YmRevClassOfService_h
#define YmRevClassOfService_h 1

#include <string>
#include <YmRevDate.h>

class YmRevClassOfService
  {
  public:
   YmRevClassOfService( string szClassOfService, YmDate startDate, YmDate endDate);
   ~YmRevClassOfService() {;}

   string& get_ClassOfService() { return _szClassOfService; }
   YmDate get_startDate() { return _startDate; }
   YmDate get_endDate() { return _endDate; }

  private:
   string _szClassOfService;
   YmDate _startDate;
   YmDate _endDate;
  };

#endif

