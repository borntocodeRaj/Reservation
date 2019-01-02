#pragma ident "%Z% FileName: $RCSfile: YmRevDeviceType.h,v $ Version: $Revision: 1.3 $ Date: $Date: 2006/03/06 09:24:53 $ %Z %"
//## Module: YmRevDeviceType
//SFD
//  Name:    YmRevDeviceType.h
//  Author:  M. Hue
//  Desc:    description de la classe qui mappe la table des plages des device Type : REV_DEVICE_TYPES
//EFD



#ifndef YmRevDeviceType_h
#define YmRevDeviceType_h 1

#include <string>

class YmRevDeviceType
  {
  public:
   YmRevDeviceType(string szDeviceType, string szGroupeDevice);
   ~YmRevDeviceType() {;}

   string& get_DeviceType() { return _szDeviceType; }
   string& get_GroupeDevice() { return _szGroupeDevice; }

  private:
   string _szDeviceType;
   string _szGroupeDevice;
  };

#endif

