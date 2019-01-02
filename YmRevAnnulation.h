#ifndef YmRevAnnulation_h
#define YmRevAnnulation_h 1

#include <string>


class YmRevAnnulation
{
public:
YmRevAnnulation();
~YmRevAnnulation();

// Initialisation des caracteristiques d'une Annulation a partir d'une ligne de code enregistrement '07'sans ss
void initAnnulation07(char *buff);

// Initialisation des caracteristiques d'une Annulation a partir d'une ligne de code enregistrement '07' ss 00
void initAnnulation0700(char *buff);

// Initialisation des caracteristiques d'une Annulation a partir d'une ligne de code enregistrement '07' ss 04
void initAnnulation0704(char *buff);

// Initialisation des caracteristiques d'une Annulation a partir d'une ligne de code enregistrement '09'
void initAnnulation09(char *buff);

// Rajout de l'Annulation dans le Vecteur global des Annulations 
void alimenterVecteurAnnulation();


inline unsigned int getTcnAnnule() { return _tcnAnnule ; }
inline void setTcnAnnule(unsigned int tcnAnnule_) { _tcnAnnule=tcnAnnule_ ; }
inline string& getDateTcn() { return _dateTcn ; }
inline void setDateTcn(string &dateTcn_) { _dateTcn=dateTcn_ ; }
inline string& getDateOperation() { return _dateOperation ; }
inline void setDateOperation(string &dateOperation_) { _dateOperation=dateOperation_ ; }
inline string& getHeureOperation() { return _heureOperation ; }
inline void setHeureOperation(string &heureOperation_) { _heureOperation=heureOperation_ ; }
inline unsigned int getMontantTcn() { return _montantTcn ; }
inline void setMontantTcn(unsigned int montantTcn_) { _montantTcn=montantTcn_ ; }
inline unsigned int getMontantRembourse() { return _montantRembourse ; }
inline void setMontantRembourse(unsigned int montantRembourse_) { _montantRembourse=montantRembourse_ ; }
inline unsigned int getMontantRetenues() { return _montantRetenues ; }
inline void setMontantRetenues(unsigned int montantRetenues_) { _montantRembourse=montantRetenues_ ; }
inline string& getStationOrigine() { return _stationOrigine ; }
inline void setStationOrigine(string &stationOrigine_) { _stationOrigine=stationOrigine_ ; }
inline string& getStationDestination() { return _stationDestination ; }
inline void setStationDestination(string &stationDestination_ ) { _stationDestination=stationDestination_ ;  }

private:
unsigned int 	_tcnAnnule;
string 	_dateTcn;
string 	_dateOperation;
string 	_heureOperation;
unsigned int 	_montantTcn;
unsigned int 	_montantRembourse;
unsigned int 	_montantRetenues;
string 	_stationOrigine;
string 	_stationDestination;
};

#endif
