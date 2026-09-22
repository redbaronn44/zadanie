#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class Osoba {
string imie;
string nazwisko;
int wiek;

public:
// Wczytywanie danych z pliku do obiektu
void wczytajZPliku(ifstream& plik) {
plik >> imie >> nazwisko >> wiek;
}

// Zapisywanie danych z obiektu do pliku
void zapiszDoPliku(ofstream& plik) {
plik << imie << " " << nazwisko << " " << wiek << endl;
}

// Metody zwracające wartości pól (gettery)
string pobierzImie() { return imie; }
string pobierzNazwisko() { return nazwisko; }
int pobierzWiek() { return wiek; }

// Wyświetlanie danych w konsoli
void wypisz() {
cout << imie << " " << nazwisko << " " << wiek << endl;
}
};

int main() {
Osoba uczniowie[30];

// Otwieranie plików
ifstream plikWejsciowy("StartFile.txt");
ofstream plikWyjsciowy("ResultFile.txt");

// Sprawdzenie poprawności otwarcia plików
if (!plikWejsciowy) {
cout << "Nie mozna otworzyc pliku StartFile.txt!" << endl;
return 1;
}

if (!plikWyjsciowy) {
cout << "Nie mozna utworzyc pliku ResultFile.txt!" << endl;
return 1;
}

// Wczytanie 30 uczniów z pliku
for (int i = 0; i < 30; i++) {
uczniowie[i].wczytajZPliku(plikWejsciowy);
}

// Sortowanie według nazwiska (alfabetycznie)
sort(uczniowie, uczniowie + 30, [](Osoba& a, Osoba& b) {
return a.pobierzNazwisko() < b.pobierzNazwisko();
});

// Wyświetlenie posortowanych uczniów w konsoli
cout << "Posortowani uczniowie:" << endl;
for (int i = 0; i < 30; i++) {
uczniowie[i].wypisz();
}

// Zapis do pliku wynikowego
for (int i = 0; i < 30; i++) {
uczniowie[i].zapiszDoPliku(plikWyjsciowy);
}

// Zamknięcie plików
plikWejsciowy.close();
plikWyjsciowy.close();

cout << "Dane zostaly posortowane i zapisane." << endl;

return 0;
}