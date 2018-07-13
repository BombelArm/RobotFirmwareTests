Prototyp Rdzenia robota.
Posiada podstawowa komunikacje, oraz sterowanie silnikami krokowymi na podstawie zadanego polozenia
Komunikacja przez UART (usb)
Po kazdej linijce, nalezy wyslac znak '\n' (NL)
Szybkosc komunikacji: 115200
Lista Komend:
SYN - nawiazanie komunikacji. Oczekiwac SYN-ACK.
ACK - Potwierdzenie Potwierdzenia. Po zakonczeniu handshake'u. Dostepne sa dodatkowe komendy.

MOT_INIT - Oczekiwac OK. Nastepne 4 pakiety oznaczaja odpowiednio Numer Silnika[0-2], Martwa strefa [0.1-0.05], Przyspieszenie [1000-15000], Okres_Minimalny [200-1000] 
w zaleznosci od stawu i mikrostepu nalezy dobrac dobre wartosci.
Aby wywolac przypisanie, nalezy Wyslac FIN
Przyklad inicjalizacji:
MOT_INIT
1
0.01
10000
200
FIN

SYS_INFO - Zwraca polozenie poszczegolnych stawow.

MSP - Motor Set Position. Oczekiwac OK.
Ustawia dany staw na "legalne" miejsce.
Jesli miejsce nie jest legalne nie zostanie wykonana.
(jest jednak mozliwosc kolizji z podstawa lub podlozem.)
Oczekuje 2 pakietow oraz FIN. Odpowiednio Numer Silnika[0-2], Pozycja w radianach{max pozycja zalezy od stawu]
Przyklad uzycia:
MSP
1
0.5
FIN

PING - Zwraca Ping (keepalive)

REST - Wylacza silniki, wentylatory pozostaja wlaczone/zostaja wlaczone.

HOME - Ustawia ramie do pozycji spoczynkowej.

// Uruchamianie przybijania pieczatek //
wpisac kolejno
SYN
ACK
INIT_ALL (poczekac az ramie sie wypionuje)
TEST (rozpoczecie trajektorii, uwaga aby zlecic wykonanie innego ruchu nalezy najpierw wylaczyc trajektorie, inaczej po wykonaniu zleconego ruchu, ramie zacznie wykonywac kolejny ruch z trajektorii)
TEST_STOP (zakonczenie trajektorii)




