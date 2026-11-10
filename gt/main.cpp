#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class osoba {
private:
int wiek;
string imie;
string nazwisko;

public:
osoba() : wiek(18), imie("Ivan"), nazwisko("Kovalenko") {

}


void wprowadz() {
cout << "Podaj imie: ";
cin >> imie;
cout << "Podaj nazwisko: ";
cin >> nazwisko;
cout << "Podaj wiek: ";
cin >> wiek;
}


void wypisz() {
cout << imie << " " << nazwisko << " " << wiek << endl;
}


string pobierzImie() { return imie; }
string pobierzNazwisko() { return nazwisko; }
int pobierzWiek() { return wiek; }

void ustawDane(string i, string n, int w) {
imie = i;
nazwisko = n;
wiek = w;
}
};

class klasa {
public:
osoba t[3];


void wprowadz() {
for (int i = 0; i < 3; i++) {
cout << "\n--- Osoba " << i + 1 << " ---" << endl;
t[i].wprowadz();
}
}

void wypisz() {
cout << "\n=== LISTA OSOB ===" << endl;
for (int i = 0; i < 3; i++) {
cout << i + 1 << ". ";
t[i].wypisz();
}
}


void zapisz() {
ofstream plik("baza.txt");
if (plik.is_open()) {
for (int i = 0; i < 3; i++) {
plik << t[i].pobierzImie() << " "
<< t[i].pobierzNazwisko() << " "
<< t[i].pobierzWiek() << endl;
}
plik.close();
cout << "\n[+] Zapisano do pliku baza.txt" << endl;
} else {
cout << "Blad otwarcia pliku do zapisu!" << endl;
}
}

void wczytaj() {
ifstream plik("baza.txt");
if (plik.is_open()) {
string imie, nazwisko;
int wiek;
int idx = 0;
while (plik >> imie >> nazwisko >> wiek && idx < 3) {
t[idx].ustawDane(imie, nazwisko, wiek);
idx++;
}
plik.close();
cout << "\n[+] Wczytano dane z pliku baza.txt" << endl;
} else {
cout << "Blad otwarcia pliku do odczytu!" << endl;
}
}
};

int main() {
klasa k;
k.wprowadz();
k.wypisz();
k.zapisz();
k.wczytaj();
k.wypisz();

return 0;
}
