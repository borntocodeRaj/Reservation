//---------------------------------------------------------------------------------------------------------
// Ecriture dans le vecteur des record lus dans RESAVEN
// Nicolas PINAUD
// --------------------------------------------------------------------------------------------------------

#ifndef YmRevEcrireVec_h
#define YmRevEcrireVec_h 1

#include <YmRevDate.h>
#include <YmRevTypePassager.h>
#include <iomanip>
#include <locale>
#include <sstream>
//DT33254 ajout de la structure Booking
struct Booking
{
	int numPalierBooking;
	string classOfServiceBooking;
	int UpgHan;
};

class YmRevEcrireVec
{
  public:
  YmRevEcrireVec(char* NomFichier) ;
  ~YmRevEcrireVec() {;};

  void Start();

  int lireFichierResaven();

  private:
  char _NomFichier[256];
  char _NomFichier_court[256];
  string _dateBang;

  // Numero de ligne du fichier
  int _iNumeroLigneFichier;

  // pointeurs sur les classes Tcn, PassagersParcours, Annulation et Retraits
  
  YmRevTcn * _pTcn;
  YmRevPassagersParcours * _pPassagersParcours;
  YmRevSegments * _pSegments;
  YmRevAnnulation * _pAnnulation;
  YmRevRetraits * _pRetraits;
  

  // tableau temporaire de stockage des pointeurs 'Segments' a rattacher a un 'PassagersParcours' d'un 'Tcn'
  YmRevSegments * _pSegTemp[8];
  int _iSegTemp;

  // Permet de savoir si un train est un auto train (=1) ou non (=0)
  int _iAuto;

  // 
  int _PresenceSousStructure08;

  // Nombre de PassagersParcours d'un Tcn
  int _iNbPassagersParcours;

  //Distance totale des segments d'un parcours
  int _iTotalDistanceSegmentsParcours;

  // Date max des Segments d'un Tcn
  int _lDateMax;
  string _strDateMax;

  // Date et Heure de l'Entete du Fichier 
  string _strDateEntete;
  string _strHeureEntete;

  // Flag indiquant l'absence d'une Classe de service dans la Map ClassOfService + sa presence dans la Map ClassMapping
  // Si le Flag est positionee a 1 et que le parcours n'est pas international (pas ligne a sous-structure 06 derriere la ligne a
  // sous structure 04) strockage de 1 message WARNING dans SC_MESSAGE_LOG 
  int _iFlagAbsenceClassOfService;

  bool _isTGVorCORAIL;
  
  // TDR - Anomalie 90705 Indique si le tcn a au moins un tcn CORAIL ou TGV
  bool _isTCNHasTGVorCORAIL;
 
  // Traitement PassagersParcours avec ligne de structure 04 uniquement
  // iNumLigne04 = numero de ligne du Fichier correspondant a la ligne 04 traitee
  // HRI, 05/03/2015 : on a besoin du palier du segment FCEN94-02 afin de l'utiliser pour FCEN04-04 (qui n'en dispose pas)
  //void TraiterPassagersParcoursSansInternational(char * sLigne04,int iNumLigne04);FF
  //DT33254 l'ajout du paramètre StructBooking
  void TraiterPassagersParcoursSansInternational(char * sLigne04,int iNumLigne04, long numPalierSegment, Booking &F);
  // Traitement PassagersParcours avec lignes de structure 04 et 06 (parcours international) 
  // iNumLigne04 = numero de ligne du Fichier correspondant a la ligne 04 traitee
  // HRI, 05/03/2015 : on a besoin du palier du segment FCEN94-02 afin de l'utiliser pour FCEN04-04 (qui n'en dispose pas)
  //void TraiterPassagersParcoursAvecInternational(char * sLigne04,char * sLigne06,int iNumLigne04);
  //DT33254 l'ajout du paramètre StructBooking
  void TraiterPassagersParcoursAvecInternational(char * sLigne04,char * sLigne06,int iNumLigne04, long numPalierSegment, Booking StructBooking);

  // Traitement des segments d'un PassagersParcours
  // iNumLigne04 = numero de ligne du Fichier correspondant a la ligne 04 traitee (ligne 04 suivant les segments traites)

 
  void TraiterSegments(double ldMontantTaxation,int liSegEff, YmRevTypePassager * pTypePassager,int iNumLigne04);

  // Initialisation des Membres relatifs a la lecture du fichier Resaven
  void InitialiserMembresPourLectureFichierResaven();

  // Initialisation du tableau temporaire de pointeurs de segments a affecter au PassagersParcours en cours 
  void InitialiserTableauPointeursSegments();

  // Gestion de fin de Tcn lorsque le dernier PassagerParcours etait represente sans ligne de structure 06
  // iNumLigne04 = numero de ligne du Fichier correspondant a la derniere ligne 04 traitee
  // iNumLigne00 = numero de ligne du Fichier correspondant a la derniere ligne 00 traitee (ligne du Tcn precedent)

  // HRI, 05/03/2015 : on a besoin du palier du segment FCEN94-02 afin de l'utiliser pour FCEN04-04 (qui n'en dispose pas)
  //void GestionFinTcn(int struc_prec, char * sLigne04,int iNumLigne04,int iNumLigne00);
  void GestionFinTcn(int struc_prec, char * sLigne04,int iNumLigne04,int iNumLigne00, long numPalierSegment, Booking StructBooking);

  // Utilisation des Date et Heure de l'entete du fichier Resaven (ligne de code enregistrement '01')
  void GestionDatesIssuesFichierResaven(char * sLigne);

  // Comparaison du code equipement avec codes CORAIL et TGV en base JRO DT23805 IC SRO
  bool VerificationCodeEquipementResaven(std::string CodeEquipementResaven);

  // Gestion globale des lignes du fichier Resaven
  void GestionLignesFichierResaven(FILE *inf);

  // Affichage des Vecteurs et Listes constituees pour le chargement dans la base de donnees
  void AffichageListesConstituees();

  // Annulation d'un pointeur de segment dans la liste des pointeurs de segments temporaires d'un PassagersParcours
  void AnnulationSegmentTemporairePrecedent();

  // Initialisation d'un nouveau Tcn
  void InitialisationNouveauTcn(char * sLigne);

  // Initialisation d'un nouveau pointeur de segment dans la liste des pointeurs de segments temporaires d'un PassagersParcours
  // HRI, 05/03/2015 : on recupere le palier du segment FCEN94-02 afin de l'utiliser pour FCEN04-04 (qui n'en dispose pas)
  // void InitialisationNouveauSegmentTemporaire(char * sLigne);
  void InitialisationNouveauSegmentTemporaire(char *sLigne, long& numpalierRet, Booking *StructBooking);

  char* existenceCompart(char c);
};

#endif
