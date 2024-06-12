# Aufgabe 3.2 

## Aufgabe C: Zugriffszeiten auf Container

Testen sie nun die Zugriffszeiten auf verschiedene sequentielle Container (`vector`, `list`, `deque`). Machen sie sich dazu auch einmal vertraut, wie diese unterschiedlich umgesetzt sind (siehe [Referenz](https://en.cppreference.com/w/cpp/container) oder [hier in der WWU Übersicht](https://cppvorlesung.wwu.de/lecture/stl/containers.html).)

Nutzen sie den Code von oben zur Ermittlung von Laufzeiten und vergleichen sie die drei verschiedenen Typen für:

* `push_back`: einfügen am Ende des Containers,
* `resize`: Größe anpassen,
* `insert`: an einer beliebigen Stelle einfügen.

## Aufruf

1. Kompilieren: `g++ -std=c++20 -o contcomp container_comparison.cpp`

2. Ausführen: `./contcomp`

## Übersicht Ergebnisse: Verwendung sequentielle Containers -- Übersicht 

| **Aufgabe**                              | **`std::vector`** | **`std::deque`** | **`std::list`** |
|------------------------------------------|-------------------|------------------|-----------------|
| Einfügen/entfernen Element vorne        | langsam           | schnell          | schnell         |
| Einfügen/entfernen Element hinten       | super schnell     | sehr schnell     | schnell         |
| Indizierter Zugriff                      | super schnell     | schnell          | nicht möglich  |
| Einfügen/entfernen Element in der Mitte | langsam           | schnell          | sehr schnell    |
| Speichernutzung                          | gering            | hoch             | hoch            |
| Verbinden (splicing, joining)            | langsam           | sehr langsam     | schnell         |
| Stabilität (iterators, concurrency)     | schlecht          | sehr schlecht    | gut             |


## Link zu weiteren Materialien

Alle Materialien werden auf den Servern der WWU gehostet. 

* Die im Kurs präsentierten Slides sind [hier](https://www.uni-muenster.de/AISystems/courses/CPP/slides) zu finden. Hierin werden grundlegende Konzepte eingeführt und veranschaulicht.
* Ansonsten organisiert [dies jupyterbook](https://www.uni-muenster.de/AISystems/courses/CPP/site/html/intro.html) die verschiedenen Aufgaben und Tasks (größere, zusammenhängende Programmieraufgabe).