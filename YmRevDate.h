//## Module: YmRevDate
//SFD
// Name:   YmRevDate.h
// Author: JM. Grugeaux
// Desc:   Realisation d'une classe CDate adapte a nos besoins
//EDF

#ifndef YmRevDate_h
#define YmRevDate_h 1
using namespace std;
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string>
extern char* DonneHeure(); // renvoi l'heure sous forme HH:MI:SS
extern int   DonneIntHeure(); //renvoi l'hure sous forme hh*100 + mi
extern char* ConvertAAAAMMJJ (string& szAAAAMMJJ); // Converti AAAAMMJJ en JJ/MM/AAAA

class YmDate 
{
  public:
  YmDate();	// Default constructor, initialise avec la date du jour
  YmDate(const YmDate& aYmDate); // Copie constructor;
  YmDate(std::string& szAAAAMMJJ); // Construit et initialise une date a partir d'une string au format AAAAMMJJ
                              // ou au format JJ/MM/AAAA. la diferentition se fait sur la longueur de la string
  YmDate(int annee, int mois, int jour); // Construit et initialise une date a partir anne mois jour
  ~YmDate() {;}

  std::string& PrintFrench(string& scible, bool fullyear = true); // renvoi scible, format JJ/MM/AAAA si fullyear = true, 
					     		     //  au format JJ/MM/AA sinon
  std::string& PrintUS(string& scible, bool fullyear = true);     // renvoi scible, format MM/DD/YYYY si fullyear = true,
				             		     //	au format MM/DD/YY sinon
  std::string& PrintOracle(string& scible, bool fullyear = true); // renvoi scible, format YYYY/MM/DD si fullyear = true,
				             		     //	au format YY/MM/DD sinon
  std::string& PrintResaven (string& cible, bool fullyear = true); //renvoi scible, format YYYYMMDD si fullyear = true,
                                                             // au format YYMMDD sinon
  char* PrintFrench(char* sbuf, bool fullyear = true);	     // idem mais avec un char*
  char* PrintUS(char* sbuf, bool fullyear = true);	     // idem mais avec un char*
  char* PrintOracle(char* sbuf, bool fullyear = true);	     // idem mais avec un char*
  char* PrintResaven(char* sbuf, bool fullyear = true);	     // idem mais avec un char*

  std::string sub;

  int WeekDay(bool bMondayFirst = true); // renvoi le jour de semaine entre 1 et 7
					 // Lundi = 1 si bMondayFirst vrai, Dimanche = 1 sinon
  int YearDay();	// renvoi le nombre de jour depuis le debut de l'annee
  int DaysFrom70();    // renvoi le nombre de jour depuis le 01/01/1970
  int year();		// renvoi l'annee
  int month();		// renvoi le mois
  int day();		// renvoi le jour du mois
  YmDate& operator=(const YmDate& aYmDate);
  bool operator==(const YmDate& aYmDate);
  bool operator!=(const YmDate& aYmDate);
  bool operator>=(const YmDate& aYmDate);
  bool operator<=(const YmDate& aYmDate);
  bool operator>(const YmDate& aYmDate);
  bool operator<(const YmDate& aYmDate);
  YmDate& operator+=(int nbjour);
  YmDate& operator-=(int nbjour);
  YmDate& operator++();
  YmDate& operator--();
  /*
  YmDate& operator++(int);
  YmDate& operator--(int);
  YmDate& operator+(int);
  YmDate& operator-(int);
  */

  private:
  char* AllPrint (char* sbuf, int typrint, bool fullyear);
  time_t _nbseconds;
  struct tm _datetime;
};

#endif
