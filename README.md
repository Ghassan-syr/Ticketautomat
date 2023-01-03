# Ticketautomat

![image](https://user-images.githubusercontent.com/64756855/210440557-afd841ab-2518-4402-9fbb-79cf1a502609.png)


* Im programm wurde ein Ticketautomat für den ¨ OPNV der Stadt ¨”Le“ simuliert.
”Le“.

*  Bim Starten wird der
Automat mit Hilfe einer Datei parametrisiert. Die Daten werden beim Programmstart einmal
eingespeichert und im RAM gespeichert .

*  Die erste Zeile enthält die Kosten in der Einheit ”Geld“ pro Entfernung in der ersten Zeile steht. 

*  In der zweiten Zeile steht die Zahl der Haltestellen.


*  Dann folgen zwei Zeilen pro Haltestelle. Die erste mit dem Namen, die zweite mit der Entfernung.

*  Nach dem Einlesen fragt das programm den Benutzer nach der gewunschtenZielhaltestelle. Der
Automat gibt den Preis des Tickets aus und bittet den Benutzer den Betrag zu zahlen. In dem
Programm gibt der Benutzer dann den Geldbetrag ein, den er in den Automaten wirft (z.B. 112).
Der Automat ermittelt dann das Ruckgeld. Dafür hat der Automat ein Rückgeldreservoir mit 
Scheinen in der Gr¨oße: 100Geld, 50Geld, 20Geld, 10Geld, 5Geld, 2Geld, 1Geld. Der Automat ist
initial (beim Programmstart) mit zwei Scheinen je Sorte aufgefullt . Der Automat veruscht
nun das Restgeld zurückzugeben, indem er zuerst große, dann immer kleinere Scheine zurüuckgibt.
Ist zu wenig Geld im Automaten, so erscheint eine Fehlermeldung , sodass der Kunde erneut
einen Geldbetrag eingeben kann oder den Vorgang abbrechen kann.
Bei erfolgreichem Kauf wird ein Ticket ausgedruckt  und zur neuen Eingabe aufgefordert
.
