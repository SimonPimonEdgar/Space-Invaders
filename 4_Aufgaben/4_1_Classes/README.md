# 4.1 Klassen

In dieser Aufgabe soll eine Klasse `Account` erzeugt werden: Diese soll intern den aktuellen Kontostand vorhalten und Zugriffsmethoden zur Einzahlung, zum Abheben und zum Transfer sowie zum Abruf des Kontostandes bereitstellen.

<div class="alert alert-warning">
<b>ToDo</b>: 

* Legen Sie eine Datei `customer.cpp` an.
* Implementieren Sie die Klasse Account in der
Datei `customer.cpp`.

</div>


* Überlegen Sie sich dabei sinnvolle Parameter für die
Funktionen `deposit`, `withdraw` und `transfer`.
* Beachten Sie, dass Überweisungen ausschließlich auf
andere Konten durchgeführt werden können.
* Fügen Sie einen Konstruktor hinzu, mit dem ein
Account mit Startguthaben angelegt werden kann.
* Implementieren Sie in der Datei `customer.cpp` eine
`main`-Funktion und testen Sie die Klasse Account.

## Aufruf

Dies Programm sollen sie im Terminal (auch möglich auf dem Jupyterhub) kompilieren und aufrufen.

1. Kompilieren Sie Ihr Programm mit `g++ -std=c++20 -Wall -Wextra -pedantic -o customer customer.cpp`

2. Ausführen: `./customer`

[Direkter Link zum Git und JupyterHub](https://jupyterhub.wwu.de/hub/user-redirect/git-pull?repo=https%3A%2F%2Fzivgitlab.uni-muenster.de%2Fschillma%2Fcppcourse&urlpath=lab%2Ftree%2Fcppcourse%2F&branch=main). 

## Test

Zum Testen der Funktion sind ein paar Beispielaufrufe angegeben:

```
int main() {
  std::cout << std::boolalpha;

  Account a{ 25 };
  a.deposit( 75 );
  a.deposit( 50 );
  std::cout << (a.balance() == 150) << std::endl; // true 
  std::cout << a.withdraw( 25 )  << std::endl; // 25
  std::cout << (a.balance() ==  125) << std::endl; // true
  std::cout << a.withdraw( 150 ) << std::endl; // 0

  Account b{ a };
  std::cout << a.transfer( 50, a) << std::endl; // false
  std::cout << a.transfer( 126, b ) << std::endl; // false
  std::cout << a.transfer( 125, b ) << std::endl; // true 
  std::cout << (a.balance() == 0) << std::endl; // true 
  std::cout << (b.balance() == 250) << std::endl; // true 
}
```

## Aufgabenteil B) Vererbung

* Implementieren Sie eine Klasse `Person` mit einem Namen und einem Alter in einer Datei `person.cpp`.
* Implementieren Sie die Klasse `Customer` nun abgeleitet von `Person`. Die Klasse erbt so und soll dazu einen `Account` und eine ID (z. B. `unsigned int`) besitzen.
* Fügen Sie in beiden Klassen eine Funktion `print` hinzu, die den Zustand des Objekts (Werte aller Attribute) ausgibt.

## Aufgabenteil C) Multiple Inheritance

C++ bietet die Möglichkeit zum erben von mehreren Oberklassen. Dies kann zu Problemen führen, zum Beispiel, wenn diese Methoden mit gleicher Signatur enthalten. Allgemein ist in solchen Fällen immer einmal zu prüfen, ob dies nicht besser durch Definition von Interfaces oder abstrakte Oberklassen gelöst werden kann. 

## Link zu weiteren Materialien

Alle Materialien werden auf den Servern der WWU gehostet. 

* Die im Kurs präsentierten Slides sind [hier](https://www.uni-muenster.de/AISystems/courses/CPP/slides) zu finden. Hierin werden grundlegende Konzepte eingeführt und veranschaulicht.
* Ansonsten organisiert [dies jupyterbook](https://www.uni-muenster.de/AISystems/courses/CPP/site/html/intro.html) die verschiedenen Aufgaben und Tasks (größere, zusammenhängende Programmieraufgabe).