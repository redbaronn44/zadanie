include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class Osoba {
    string imie;
    string nazwisko;
    int wiek;

public:
    void wczytajZPliku(ifstream& plik) {
        plik >> imie >> nazwisko >> wiek;
    }

    void zapiszDoPliku(ofstream& plik) {
        plik << imie << " " << nazwisko << " " << wiek << endl;
    }

    string pobierzNazwisko() { return nazwisko; }

    void wypisz() {
        cout << imie << " " << nazwisko << " " << wiek << endl;
    }
};

int main() {
    Osoba uczniowie[30];

    ifstream plikWejsciowy("StartFile.txt");
    ofstream plikWyjsciowy("ResultFile.txt");

    if (!plikWejsciowy) {
        cout << "Nie mozna otworzyc pliku StartFile.txt!" << endl;
        return 1;
    }

    if (!plikWyjsciowy) {
        cout << "Nie mozna utworzyc pliku ResultFile.txt!" << endl;
        return 1;
    }

    for (int i = 0; i < 30; i++) {
        uczniowie[i].wczytajZPliku(plikWejsciowy);
    }

    // Sortowanie według nazwiska (alfabetycznie)
    sort(uczniowie, uczniowie + 30, [](Osoba& a, Osoba& b) {
        return a.pobierzNazwisko() < b.pobierzNazwisko();
    });

    cout << "Posortowani uczniowie:" << endl;
    for (int i = 0; i < 30; i++) {
        uczniowie[i].wypisz();
        uczniowie[i].zapiszDoPliku(plikWyjsciowy);
    }

    plikWejsciowy.close();
    plikWyjsciowy.close();

    cout << "Dane zostaly posortowane i zapisane do ResultFile.txt" << endl;

    return 0;
}