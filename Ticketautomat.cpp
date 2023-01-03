#include "Ticketautomat.hpp"
#include<string>
#include<streambuf>

/**
* Der konstruktor initialisiert ein Objekt mit der Eigenschaft der Fahrkarte
*/
        Ticketautomat::Ticketautomat(std::string a,int b,int c):
            Haltstelle(a),Entfernung(b),Geldproentfernung(c){}
/**
* die Methode gethaltstelle gibt die Haltstellenamen züruck
*
* @return weist der Wert von der Eigenschaft 'Haltstelle' des Objektes zu
*/
             std::string Ticketautomat::gethaltstelle() const
             {
               return Haltstelle;
             }
/**
* Die Methode gibt die Anzahl der Haltstellen bis zum Zielhaltestelle
*
* @return weist zu,wie fern die Zielhatstelle ist
*/
            int Ticketautomat::getentfernung() const
              {
                return Entfernung;
              }
/**
* Die Methode getpreis gibt die Preis der Fahrkarte züruck
*
* @return weist der Wert von der Eigenschaft Geldproentfernung zu
*/
            int Ticketautomat::getpreis() const
                {
                  return Geldproentfernung;
                }

