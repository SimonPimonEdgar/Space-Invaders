# C++ Kurs Space Invaders von Simon Hemkentokrax und Lotta Kroos

Kompilierung:
Die Makefile muss noch angepasst werden, sodass der Pfad für SRCDIR, der Pfad zu den .cpp-Dateien in Zeile 13, sowie der Pfad zum Include-Ordner mit den Header-Dateien in Zeile 2 korrekt eingerichtet sind. 
Falls dies nicht der Fall ist, könnte eine Fehlermeldung wie folgt auftreten: "No rule to make target 'abc.cpp', needed by 'abc.o'. Stop."

Um die Tests zu kompilieren, wählen Sie das Build-Target tests, und für das Spiel wählen Sie game. Danach wird entweder eine Datei namens tests oder game erstellt.

Ausführen:
Um das Programm auszuführen, muss lediglich eine der beiden Dateien im Terminal gestartet werden.

Ablauf:
    Test: Nach dem Ausführen der Datei erhalten Sie im Terminal eine Rückmeldung darüber, ob einer der Tests fehlgeschlagen ist.

    Game: Nach dem Start des Spiels wird im Terminal die Spielfläche erstellt, und Sie befinden sich im Startbildschirm. Mit der Taste 1 kann das Spiel begonnen werden. Mit der Taste 2 gelangen Sie in die Einstellungen, wo Sie die Steuerung des Raumschiffs ändern können.

    Die Steuerung:
    Das Raumschiff kann mit den Pfeiltasten nach oben, unten, rechts oder links bewegt werden. Schüsse werden mit der Leertaste abgegeben.

    Ablauf des Spiels:
    Das Spiel besteht aus 3 Leveln, die unendlich oft wiederholt werden können. Nach dem Tod eines jeden Aliens erhöht sich die Geschwindigkeit der verbleibenden Aliens, wodurch diese auch häufiger schießen. Diese Erhöhung nimmt mit jedem Level zu und wird, ebenso wie der Score, nicht zurückgesetzt.

    Spezielle Alienvarianten:

    Tank: Diese Variante hat, anders als die normalen Aliens, 2 Trefferpunkte und wird mit einem 'B' dargestellt.
    Elite: Diese Variante kann doppelt so oft schießen wie die anderen Aliens und besitzt ebenfalls 2 Trefferpunkte. Sie wird mit einem 'C' dargestellt.
    
    Medipack:
    Durch das Einsammeln eines Medipacks erhält der Spieler ein zusätzliches Leben. Wenn die Anzahl der Leben des Spielers mehr als 3 beträgt, wird diese ins nächste Level übernommen.

    Hindernisse:
    In jedem Level befinden sich 1 bis 3 Hindernisse. Diese können dem Spieler als Deckung dienen, blockieren jedoch auch die Schüsse des Spielers. Jedes Hindernis hat 3 Trefferpunkte und kann nur von den Aliens beschädigt werden.



