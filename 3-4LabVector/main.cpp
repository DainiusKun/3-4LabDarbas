#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
struct St
{
    string Vardas, Pavarde;
    double E, R, M;
    vector <double> ND;
    void rik();
}s;
int main()
{
    int n, nd=0, k;
    string VidM[2]={"Galutinis (Vid.)", "Galutinis (Med.)"}, VM;
    cout << "Kiek yra studentu Jusu grupeje?\n";
    while(!(cin >> n))
    {
        cout << "Neteisingai ivedete studentu skaiciu, bandykite dar karta." << endl;
        cin.clear();
        cin.ignore(256,'\n');
    }
    vector<St> s(n);
    //Pagrindinis skaiciavimas
    for (int i = 0; i < n; i++)
    {
        cout << "Irasykite " << i+1 << "-ojo studento varda ir pavarde.\n";
        cin >> s[i].Vardas;
        cin >> s[i].Pavarde;
        cout << "Ar norite atsitiktiniu rezultatu?\n";
        cin >> VM;
        if(VM=="Taip" || VM=="taip")
        {
            k=rand();
            for(int g = 0; g < k; g++)
            {
                s[i].ND.push_back(rand()%10+1);
            }
            s[i].E=rand()%10+1;
            //Vidurkio skaiciavimas
            for(int y = 0; y < k ; y++)
            {
                s[i].R=s[i].R+(s[i].ND[y]);
            }
            s[i].R=s[i].R/k*0.4+s[i].E*0.6;
            //Mediana
            if(k==1)
            {
                s[i].M=s[i].ND[k-1]*0.4+s[i].E*0.6;
            }
            else
            {
                if(k%2==0)
                {
                        s[i].M=(s[i].ND[k-2/2-1]+s[i].ND[k-1/2])*0.5*0.4+s[i].E*0.6;
                }
                else
                {
                    s[i].M=(s[i].ND[k-1/2-1])*0.4+s[i].E*0.6;
                }
            }

        }
        else
        {
        cout << "Irasykite " << i+1 << "-ojo studento namu darbu rezultatus. Irase 0 arba skaiciu >10 baigsis ivedimas.\n";
        cin >> k;
        while(k!=0)
        {
            s[i].ND.push_back(k);
            nd++;
            cin >> k;
        }
        cout << "Irasykite " << i+1 << "-ojo studento egzamino rezultata.\n";
        while(!(cin >> s[i].E))
                {
                cout << "Teisingai irasykite " << i+1 << "-ojo studento egzamino rezultata." << endl;
                cin.clear();
                cin.ignore(256,'\n');
                }
            while(s[i].E<0 || s[i].E>10)
            {
                cout << "Teisingai irasykite " << i+1 << "-ojo studento egzamino rezultata." << endl;
                cin >> s[i].E;
            }
        //Vidurkio skaiciavimas
            for(int y = 0; y < nd ; y++)
            {
                s[i].R=s[i].R+(s[i].ND[y]);
            }
            s[i].R=s[i].R/nd*0.4+s[i].E*0.6;
        //Mediana
        if(k==1)
        {
            s[i].M=s[i].ND[k-1];
        }
        else
        {
            if(k%2==0)
            {
                s[i].M=(s[i].ND[k-2/2-1]+s[i].ND[k-1/2])*0.5;
            }
            else
            {
                s[i].M=(s[i].ND[k-1/2-1]);
            }
        }
        }
    }
    cout << "Ka noretumete pamatyti, pazymiu vidurki ar mediana?\n";
    cin >> VM;
    while(!(VM=="Vidurki" || VM=="vidurki" || VM=="Mediana" || VM=="mediana"))
    {
        cout << "Vidurki ar mediana?" << endl;
        cin >> VM;
    }
    if(VM=="Vidurki" || VM=="vidurki")
    {
        cout << left << setw(11)<< "Vardas" << setw(13) << "Pavarde" << setw(17) << VidM[0];
        cout.fill('-');
        cout.width(41);
        cout << "\n";
        cout.fill(' ');
        cout << "\n";
        for(int j = 0; j < n; j++)
        {
            cout << left << setw(11)<< s[j].Vardas << setw(13) << s[j].Pavarde << setw(16) << right << setprecision(2) << fixed << s[j].R << endl;
        }
    }
    if(VM=="Mediana" || VM=="mediana")
    {
        cout << left << setw(11)<< "Vardas" << setw(13) << "Pavarde" << setw(17) << VidM[1];
        cout.fill('-');
        cout.width(41);
        cout << "\n";
        cout.fill(' ');
        cout << "\n";
        for(int j = 0; j < n; j++)
        {
            cout << left << setw(11)<< s[j].Vardas << setw(13) << s[j].Pavarde << setw(16) << right << setprecision(2) << fixed << s[j].M << endl;
        }
    }
    return 0;
}
void St::rik()
{
    sort(ND.begin(),ND.end());
}
