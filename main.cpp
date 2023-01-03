#include <iostream>
#include<fstream>
#include<string>
#include<streambuf>
#include<vector>
#include<string.h>
#include "Ticketautomat.hpp"

void print(std::vector<Ticketautomat>&eingabe);
int Haltstellepruefen(const std::vector<Ticketautomat>Haltstellen,std::string Ziel);
std::string Einzahlunggroesserpreis(int Preis,int Einzahlung);
void einlesen(std::vector<Ticketautomat>&uebergabe);


/**
* Die Funktion einlesen lädt die Datei Le.txt und dient zur Speicherung die Daten in der Klasse Ticketautomat
* durch Erweiterung die Vektor'uebergabe'.
*
* @param uebergabe speichert die Daten aus der Datei Le.txt in der Klasse ab.
*
* @var Distanz ist die Konstante Anzahl der Haltstellen und dient zur Berechnung der Preis für jedes Objekt.
* @var Geld ist  konstante Tarif pro Distanze.
* @var t dient zur Umwandlung von string to int.
* @var Preis ist Preis für die Fahrkarte.
* @var Entfernung ist die Entfernung des Ortes.
*/
void einlesen(std::vector<Ticketautomat>&uebergabe)
{


    int Distanz,Geld,Preis,Entfernung;
    std::string haltstelle="";
    std::string t="";
    std::ifstream le("Le.txt");
    getline(le,t);
    Geld=atoi(t.c_str());
    getline(le,t);
    Distanz=atoi(t.c_str());

while(le)
    {
      ///Die Haltstelle und die Entfernung des Ortes werden abwechselnd gespeichert
      getline(le,t);
      haltstelle=t;
      getline(le,t);
      Entfernung=atoi(t.c_str()) ;
      Preis=Geld/Distanz *Entfernung;
      ///Erstellung ein neues Objekt vom Typ Ticketautomat
      Ticketautomat temp(haltstelle,Entfernung,Preis);
      ///Erweiterung die Vektor uebergabe
      uebergabe.push_back(temp);
    }
    le.close();
}
/**
* Die Funktion print gibt die Haltestellen an das Bildschirm aus und fragt die Kunde nch der Zielhaltestelle
* Die Funktion print ruft die Methode gethalstelle auf,gibt die Haltstellennamen aller Objkte der Klasse züruck
* und fragt die Kunde nach der Zielhaltestellle
*
* @param eingabe bezeichnet aller Objekte der Klasse Ticketautomat
*/
void print(std::vector<Ticketautomat>&eingabe)
{
    std::cout<<"____________***willkommen***___________________\n";
    std::cout<<"Die Haltstellen sind: "<<std::endl;
    ///eine for Schleife läuft über alle Objekte der Klasse
    for(size_t i=0;i<eingabe.size();i++)
        {
           ///hier wird die Methode gethaltstelle,die die Fuktion die Haltstellennamen züruck gibt,aufgerufen
           std::cout<<eingabe[i].gethaltstelle()<<'\n';
        }
        std::cout<<"Bitte geben Sie Ihre Zielhaltestelle ein: "<<'\n';
}
/**

* Das Hauptprogramm zeigt der Kunde die Haltstellenname,fragt die Kunde nach der Zielhaltestelle,prüft die
* Zielhaltestelle,gibt die Preis der Fahrkarte aus und durch mehrere Fallunterscheidung wird die Einzahlung
* der Kunde geprüft.Im Hauptprogramm kann die Kunde auch den Vorgang in bestimmten Fällen den Vorgang abbrechen
* oder einen neuen Betrag eingeben.
*
* @var Haltstellen ist ein Vektor und dient zur Erstellung neue Objekte vom Typ Ticketautomat.
* @var Einzahlung ist der Betrag,der von der Kunde bezahlt ist.
* @var Preis ist die Kosten der Fahrkarte und dient zum prüfen,ob die Ziel der Kunde in der Klasse abgespeichert ist.
* @var Einzahlungzustand speichert die Rückgabegeld für die Kunde und dient zur Unterscheidung,ob das
* rückgabegeld im Automat für die Erstattung der Rückgabe ausreichen oder nicht.
* @var Haltstellen bezeichnet alle objekte der Klasse Ticketautomat.
* @var Ziel ist die Zielhaltestelle der Kunde
* @var Vorgang dinet zur Fallunterscheidung,ob die Kunde der bezahlvorgang fortsetzen oder abbrechen will.
* @var Kosten speichert zwischenzeitlich den Betrag,der von der Kunde bezahlt wurde.
* @var pruef dient zur Fallunterscheidung,ob die Kunde in bestimmten Fällen den vorgang abbrechen oder erneut zahlen will.
*
*/
int main()
{
  int Preis,Einzahlung;
  Preis=0; 
 std::string Einzahlungzustand,Ziel,Vorgang,kosten;
  std::vector<Ticketautomat>Haltstellen;
  ///für die Erstellung neue Objekte durch die vordifenierten Datei Le.txt
  einlesen(Haltstellen);
  bool pruef=true;
  while(std::cin)
  {
    if(pruef==true)
    {
      ///gibt die Haltstellennamen ans Bildschirm aus
      print(Haltstellen);
      std::getline(std::cin,Ziel);
      Preis=Haltstellepruefen(Haltstellen,Ziel);
    }
    ///Preis ist null,also die Zielhaltestelle ist nicht gefunden
    if(Preis==0)
      {
        std::cout<<"Die Haltstellename stimmt nicht.Bitte geben Sie die Haltestelle erneut"<<std::endl;
      }else
        {
           ///Das Ziel der Kunde ist gefunden
           std::cout<<"Ihr Ticket kostet: "<<Preis<<" Geld "<<std::endl;
           std::cout<<"Bitte zahlen Sie ein: "<<std::endl;
           std::getline(std::cin,kosten);
           ///string to int umwandeln,damit man mit int vergleichen kann
           Einzahlung=atoi(kosten.c_str());

           if(Einzahlung==Preis)
              {
                ///pruef ist true==Die haltstellen werden wieder ausgegeben
                std::cout<<"Ihre Ticket wird gedrueckt.Gute Reise"<<std::endl;
                pruef=true;
              }
                if(Einzahlung<Preis)
                 {
                   std::cout<<"Ihre Zahlung reicht leider nicht aus."<<std::endl;
                   std::cout<<"Wenn Sie erneut zahlen wollen geben Sie bitte 'erneut zahlen' ein"<<std::endl;
                   std::cout<<"Wenn Sie abbrechen wollen geben Sie bitte 'abbrechen' ein"<<std::endl;
                   std::getline(std::cin,Vorgang);
                      ///hat Die Kunde 'erneut zahlen' eingegeben,dann wird pruef false zugewiesen
                      ///Die Preis der Fahtkarte wird wieder ausgegeben
                      if(Vorgang=="erneut zahlen")
                        {
                          pruef=false;
                        }else
                           {
                             ///hat die Kunde 'abbrehen' eingegeben,dann wird pruef true zugewiesen
                             ///Die Haltstellennamen werden wieder ausgegeben
                             pruef=true;
                           }
                  }
                     if(Einzahlung>Preis)
                     {
                        ///Funktionaufruf zum Prüfen,ob die Rückgabe für die Kunde möglich ist
                        ///Die Erstattung der Rückgabe hängt von der Funktion Einzahlunggroesserpreis
                        ///im Fall,dass das Geld im Automat nicht reicht,kann die Kunde den Vorgang abbrechen oder erneut zahlen
                        Einzahlungzustand=Einzahlunggroesserpreis(Preis,Einzahlung);
                        if(Einzahlungzustand=="Leider reicht das Geld im Automat nicht")
                         {
                           std::cout<<"Das Geld im Automat reicht leider nicht aus"<<std::endl;
                           std::cout<<"Wenn Sie erneut zahlen wollen geben Sie bitte 'erneut zahlen' ein"<<std::endl;
                           std::cout<<"Wenn Sie abbrechen wollen geben Sie bitte 'abbrechen' ein"<<std::endl;
                           std::getline(std::cin,Vorgang);
                           if(Vorgang=="erneut zahlen")
                            {
                              pruef=false;
                            }else
                               {
                                 pruef=true;
                               }
                          }else
                           {
                             ///Das Geld im Automat reichen aus
                             ///pruef wird true zugewesen
                             ///Die Haltstellen werden wieder ausgegeben
                             std::cout<<"Bitte Entnehmen Sie ihr Geld "<<Einzahlungzustand<<"\nGute Reise"<<std::endl;
                             pruef=true;

                           }
                    }
           }
    }
}

/**
* Die Funktion Haltstellepruefen prüft,ob die eingegebene Haltestelle in der Klasse abgespeischert ist
* @var Haltstellen bezeichnet alle Objekte der Klasse Ticketautomat.
* @var Preis ist die Preis der Fahrkarte.
*
* @param ziel ist die eingegebene Zielhaltestelle von der Kunde.
*
* @return preis die Funktion gibt die kosten der Fahrkarte züruck.
*/
int   Haltstellepruefen( std::vector<Ticketautomat>Haltstellen,std::string ziel)
{
int Preis;
Preis=0;
    for(size_t i=0;i<Haltstellen.size();i++)
   {  ///Die Eigenschaft Haltstelle wird mit dem Ziel verglichen
      if(ziel==Haltstellen.at(i).gethaltstelle())
      {
        Preis= Haltstellen.at(i).getpreis();
        break;
      }else
        {
         ///Die Haltstelle ist nicht gefunden
         Preis=0;
        }
   }
    return Preis;
}
/**
* Die Funktion Einzahlunggroesserpreis prüft ob die rückgabe für die Kunde möglich ist oder nicht
* und das hängt von den Geldscheinen,die im Automat sind.
*
* @var Rueckgabegeld bezeichnet die Scheine,die zur verfügung sind.
* @var j  ist die Differenz zwischen der Preis und der Einzahlung.
* @var zueruckgabe bezeichnet das Rückgeld für die Kunde.
*
* @param Preis ist die Preis der Fahrkarte.
* @param Einzahlung ist der Betrag,der von der Kunde bezahlt ist.

* @return zueruckgabe gibt das Rückgeld züruck,wenn die Scheine im Automat ausreichen
* @return "Leider reicht das Geld im Automat nicht",wenn die Scheine im Automat nicht ausreichen,um die Ruckgabe zu erstatten
*
*/
std::string Einzahlunggroesserpreis(int Preis,int Einzahlung)
{
    std::vector<int>Rueckgabegeld{100,100,50,50,20,20,10,10,5,5,2,2,1,1};
    int j=Einzahlung-Preis;
    std::string zueruckgabe;
    ///Die for Schleife läuft über alle Elemnte der vektor Rueckgabegeld
    ///und zieht jedes mal ein Schein von der Differnz ab,wenn der Schein
    ///kleiner Differenz ist
    for(size_t i=0;i<Rueckgabegeld.size();i++)

      {
        if(Rueckgabegeld.at(i)<=j)
        {
           j=j-Rueckgabegeld.at(i);
           ///int to string umwandeln
           zueruckgabe+=std::to_string(Rueckgabegeld.at(i))+"  ";
        }
      }
        ///Die Differenz zwischen Einzahlung und Preis beträgt null,also die Rückgabe ist möglich
        if(j==0)
        {
          return zueruckgabe;
        }else
         {
           return "Leider reicht das Geld im Automat nicht";
         }
}





