# 4.2 Unit Tests

## 4.2 A)  Nutzen von Unit Tests für die eben erstellten Klassen

Als erste Aufgabe sollen sie die Lösung von Aufgabe 4.1 und die dort per Hand durchgeführten Tests in Unit Tests der Boost umsetzen.


* In `customer.cpp`: Ersetzen sie die Beispielaufrufe in der `main` Methode durch Unit-Tests. Dafür müssen sie eine neue `BOOST_AUTO_TEST_CASE( test_customer )
{ ... }` Umgebung einführen.
* Und die bisherige `main` entfernen oder auskommentieren.
* Aufruf make: `make customer`.

## Aufgabe 4.2 B) Erstellen von Unit Tests für eine Funktion

Für eine vorgegebene Funktionalität wurden automatisch (durch ChatGPT als Werkzeug, Kommunikation mit ChatGPT am 28.4.2023, Prompts unten angegeben) zwei Implementierungen erstellt in `closestsum_dp.cpp` und `closestsum_simple.cpp`.

Diese sollen getestet werden.


<div class="alert alert-warning">
<b>ToDo</b>: 

* Versuchen sie zuerst zu verstehen, was diese Funktionen genau tun und wie sie es genau umsetzen durch Inspektion des Codes.
* Schreiben sie in Boost Unit tests, die diese beiden Funktionen überprüfen und testen, ob sie die gegebene Aufgabenstellung erfüllen.
* Aufruf make: `make closestsum_dp` bzw. `make closestsum_simple`.

## Aufruf

Dies Programm sollen sie im Terminal (auch möglich auf dem Jupyterhub) kompilieren lassen und aufrufen.

1. Kompilieren Sie Ihr Programm mit Hilfe des `Makefile`: `make simpletest` als Beispiel, bzw. `make closestsum_dp`, `make closestsum_simple`

2. Ausführen: `./simpletest` bzw. analog für die anderen erstellten Programme.