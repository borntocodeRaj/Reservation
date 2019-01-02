#pragma ident "%Z% FileName: $RCSfile: YmRevDeviceType.cpp,v $ Version: $Revision: 1.3 $ Date: $Date: 2006/03/06 09:24:53 $ %Z %"

//## Module: YmRevDeviceType
//SFD
//  Name:    YmRevDeviceType.cpp
//  Author:  JM. Grugeaux
//  Desc:    contenu de la classe qui mappe la table des device Type : REV_DEVICE_TYPES
//EFD

using namespace std;

#include <YmRevDeviceType.h>

YmRevDeviceType::YmRevDeviceType(string szDeviceType, string szGroupeDevice)
{
_szDeviceType=szDeviceType;
_szGroupeDevice=szGroupeDevice;
}

