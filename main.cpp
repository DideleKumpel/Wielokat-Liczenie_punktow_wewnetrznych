#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;



struct punkt{
    int x,y;
};

bool porownajKat(punkt& p1, punkt& p2, punkt& centrum);

class wielokat{
    punkt centrumMasy;
    double polePowierzni; //pole liczmy za pomoca shoelace formula
    int punktyWScianach;
    int PunktyWWielokacie;
public:
    int LiczbaPunktow;
    vector<punkt> punkty;
    void ObliczCentrumMasy();
    void SortujPunkty(); //sortuje podane punkty przeciwnie do wskazowek zegara sortowanie te jest potrzebne do wykorzytsania shoelace formula
    void obliczPunktyWScinach();
    void obliczPole();
    void ObliczPunktyWWielokacie();
    int PodajPunktyWWielokacie(); // korzytsa
    void Licz();
};



int main() {
    vector<vector<int>> kopiaPunkty (1, vector<int> (2));
    int LiczbaTestow=0;
    cin>>LiczbaTestow;
    vector<wielokat> Wielokaty (LiczbaTestow);
    for(int i=0; i<LiczbaTestow; i++)
    {
        cin>>Wielokaty[i].LiczbaPunktow;
        vector<punkt> kopiaPunkty (Wielokaty[i].LiczbaPunktow);
        cin.ignore();
        for(int k=0; k<Wielokaty[i].LiczbaPunktow; k++)
        {
            string PunktyWString;
            getline(cin, PunktyWString);
            int SzukajOd=0, gdzieSpace=0;
            string pomocnicza;
            gdzieSpace = PunktyWString.find(' ');
            pomocnicza.insert(0, PunktyWString, 0, gdzieSpace);
            kopiaPunkty[k].x=(stoi(pomocnicza));
            pomocnicza.clear();
            SzukajOd = gdzieSpace + 1;
            gdzieSpace = PunktyWString.find(' ', SzukajOd);
            pomocnicza.insert(0, PunktyWString, SzukajOd, gdzieSpace - SzukajOd);
            kopiaPunkty[k].y=(stoi(pomocnicza));
        }
        Wielokaty[i].punkty=kopiaPunkty;

    }
    return 0;
}

void wielokat::ObliczCentrumMasy() {
    double sumX=0, sumY=0;
    for(int i=0; i<LiczbaPunktow; i++)
    {
        sumX+=punkty[i].x;
        sumY+=punkty[i].y;

    }
    centrumMasy.x=sumX/LiczbaPunktow;
    centrumMasy.y=sumY/LiczbaPunktow;
}

void wielokat::obliczPole()
{
    int sum1=0, sum2=0;
    for(int i=0; i<LiczbaPunktow-1; i++)
    {
        sum1+=punkty[i].x*punkty[i+1].y;
        sum2+=punkty[i].y*punkty[i+1].x;
    }
    sum1+=punkty[LiczbaPunktow-1].x*punkty[0].y;
    sum2+=punkty[LiczbaPunktow-1].y*punkty[0].x;
    polePowierzni=0.5*abs(sum1-sum2);
}

void wielokat::obliczPunktyWScinach() {
    punktyWScianach=0;
    for(int i=0; i<LiczbaPunktow-1; i++)
    {
            punktyWScianach+=gcd(punkty[i+1].x-punkty[i].x, punkty[i+1].y-punkty[i].y);
    }
    punktyWScianach+=gcd(punkty[LiczbaPunktow-1].x-punkty[0].x, punkty[LiczbaPunktow-1].y-punkty[0].y);
}

void wielokat::SortujPunkty() {
    sort(punkty.begin(), punkty.end(), [&](punkt& p1, punkt& p2) {
        return porownajKat(p1, p2, centrumMasy);
    });
}

bool porownajKat(punkt& p1, punkt& p2, punkt& centrum) {
    double kat1 = atan2(p1.y - centrum.y, p1.x - centrum.x);
    double kat2 = atan2(p2.y - centrum.y, p2.x - centrum.x);
    return kat1 < kat2;
}

void wielokat::ObliczPunktyWWielokacie()
{

}
int wielokat::PodajPunktyWWielokacie()
{

}

void wielokat::Licz()
{
    ObliczCentrumMasy();
    SortujPunkty();
    obliczPole();
    obliczPunktyWScinach();
    ObliczPunktyWWielokacie();
}