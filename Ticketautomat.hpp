
#include<string>
#include<iostream>
/**
* Die Klasse Ticketautomat dient zur Speicherung der Haltstellennamen,die Entfernung der Haltestellen und der Preis des Fahrkarte
*
*/
class Ticketautomat
{
public:
        Ticketautomat(std::string a,int b,int c);
        std::string gethaltstelle() const;
        int getentfernung() const;
        int getpreis()const;

private:
        std::string Haltstelle; ///Haltstellenname
        int const Entfernung;  ///Anzahel der Haltstellen bis zur Zielhaltestelle
        int  Geldproentfernung; ///preis der Fahrkarte
};

