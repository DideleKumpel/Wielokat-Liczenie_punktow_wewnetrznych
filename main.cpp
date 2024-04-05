#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct wielokat{
    int LiczbaPunktow=0;
    vector<vector<int>> punkty;
};

int main() {
    vector<vector<int>> kopiaPunkty (1, vector<int> (2));
    int LiczbaTestow=0;
    cin>>LiczbaTestow;
    vector<wielokat> Wielokaty (LiczbaTestow);
    for(int i=0; i<LiczbaTestow; i++)
    {
        cin>>Wielokaty[i].LiczbaPunktow;
        vector<vector<int>> kopiaPunkty (Wielokaty[i].LiczbaPunktow , vector<int> (2));
        cin.ignore();
        for(int k=0; k<Wielokaty[i].LiczbaPunktow; k++)
        {
            string PunktyWString;
            getline(cin, PunktyWString);
            int SzukajOd=0, gdzieSpace=0;
            string pomocnicza;
            gdzieSpace = PunktyWString.find(' ');
            pomocnicza.insert(0, PunktyWString, 0, gdzieSpace);
            kopiaPunkty[k][0]=(stoi(pomocnicza));
            pomocnicza.clear();
            SzukajOd = gdzieSpace + 1;
            gdzieSpace = PunktyWString.find(' ', SzukajOd);
            pomocnicza.insert(0, PunktyWString, SzukajOd, gdzieSpace - SzukajOd);
            kopiaPunkty[k][1]=(stoi(pomocnicza));
        }
        Wielokaty[i].punkty=kopiaPunkty;
    }
    return 0;
}


/*NOTATKI
 * do obliczenia punktow gorzystany z wzór Picka https://pl.wikipedia.org/wiki/Wzór_Picka
 * Pole liczymy z SHOELANCE ALGORYTM https://www.101computing.net/the-shoelace-algorithm/
 * Liczbe punkty nalezace do scianek wielokatu z gcd(x2 - x1, y2 - y1)+1 where A=(x1, y1), B=(x2, y2) https://stackoverflow.com/questions/23729244/algorithm-to-calculate-the-number-of-lattice-points-in-a-polygon
 * przekształacmy wzor picka i wyliczamy ilosc punktow w srodku
 */