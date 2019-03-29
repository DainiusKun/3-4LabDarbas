#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct St
{
    string Vardas, Pavarde;
    double *ND, E, R, M;
}*s, *temp;
void burbulas(double Mas[], int n);
int main()
{
    int n, k = 1;
    double nd;
    string VidM[2]={"Galutinis (Vid.)", "Galutinis (Med.)"}, VM;
    cout << "Kiek yra studentu Jusu grupeje?\n";
    while(!(cin >> n))
    {
        cout << "Neteisingai ivedete studentu skaiciu, bandykite dar karta." << endl;
        cin.clear();
        cin.ignore(256,'\n');
    }
    s = new St[n];
    temp = new St[n];
    //Pagrindinis skaiciavimas
    for (int i = 0; i < n; i++)
    {
        cout << "Irasykite " << i+1 << "-ojo studento varda ir pavarde.\n";
        cin >> s[i].Vardas;
        cin >> s[i].Pavarde;
        s[i].ND = new double[k];
        cout << "Irasykite " << i+1 << "-ojo studento namu darbu rezultatus. Irase 0 arba skaiciu >10 baigisis ivedimas.\n";
        cin >> nd;
        while(nd>0 && nd<11)
        {
            s[i].ND[k-1]=nd;
            temp[i].ND = new double[k];
            temp[i].ND[k-1]=s[i].ND[k-1];
            delete(s-> ND);
            k++;
            s[i].ND = new double[k];
            for(int p = 0; p < k; p++)
            {
             s[i].ND[p]=temp[i].ND[p];
            }
            delete(temp-> ND);
            cin >> nd;
        }
        k--;
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
            for(int y = 0; y < k ; y++)
            {
                s[i].R=s[i].R+(s[i].ND[y]);
            }
            s[i].R=s[i].R/k*0.4+s[i].E*0.6;
        //Rikiavimas
        burbulas(s -> ND, k);
        if(k==1)
        {
            s[i].M=(s[i].ND[k-1]+s[i].E)/2;
        }
        else
        {
            if(k%2==0)
            {
                s[i].M=((s[i].ND[k-2/2-1]+s[i].ND[k-1/2])*0.5+s[i].E)*0.5;
            }
            else
            {
                s[i].M=(s[i].ND[k-1/2-1]+s[i].E)/2;
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
    delete(s);
    return 0;
}
void burbulas(double mas[], int n)
{
   for (int i = 0; i < n-1; i++)
       for (int j = 0; j < n-i-1; j++)
           if (mas[j] > mas[j+1])
              swap(mas[j], mas[j+1]);
}
