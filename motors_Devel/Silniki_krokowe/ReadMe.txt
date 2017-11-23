Ogólenie to projekt jest napisany pod STM32 F401 ponieważ nie posiadam F411 i nie miałem jak sprawdzić na nim.

Są trzy zmienne wejściowe od szybkości oborotu:
int Okres_silnika_0
int Okres_silnika_1
int Okres_silnika_2
zmiana ich wartosci powoduje zmiane ilosci cykli licznika.
Kod był sprawdzony na interruptcie, który był wywoływany cyklicznie z częstotliwością
12,5 kHz. Moj silnik krokowy zaczynał przeskakiwać przy okresie mniejszym od 30. Podanie wartości 0 skutkuje zatrzymaniem silnika.


//////////////////////////////////////////////////////////////////////////////////////
Zmienne sterujące kierunkiem:
int Kierunek_obrotu_0
int Kierunek_obrotu_1
int Kierunek_obrotu_2

Dla wartości 0 silnik kręci się w jedną strone dla wartości 1 w drugą.