#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
struct St
{
    string Vardas, Pavarde;
    int *ND, E;
    double R, M;
}*s, *temp;
void burbulas(int Mas[], int n);
int main()
{
    int n, nd, f = 0, tik;
    string VidM[2]={"Galutinis (Vid.)", "Galutinis (Med.)"}, VM;
    cout << "Kiek yra studentu Jusu grupeje?" << endl;
    while(!(cin >> n))
    {
        cout << "Neteisingai ivedete studentu skaiciu, bandykite dar karta." << endl;
        cin.clear();
        cin.ignore(256,'\n');
    }
    s = new St[n];
    delete(s);
    s[n].R={0};
    s[n].M={0};
    cout << "Kiek namu darbu uzdavete?" << endl;

    while(!(cin >> nd))
    {
        cout << "Neteisingai ivedete namu darbu skaiciu, bandykite dar karta." << endl;
        cin.clear();
        cin.ignore(256,'\n');
    }
    for (int i = 0; i < n; i++)
    {
        s[i].ND = new int[nd];
    }
    delete(s -> ND);
    for(int i = 0; i < n; i++)
        {
            cout << "Irasykite " << i+1 << "-ojo studento varda ir pavarde." << endl;
            cin >> s[i].Vardas;
            cin >> s[i].Pavarde;
            //Tikrina ar varde nera skaitmenu ir ar tik viena didzioji raide
            do
            {
                if(s[i].Vardas[0]>='A' && s[i].Vardas[0]<='Z')
                {
                    f++;
                    for(int t = 0; t < sizeof(s[i].Vardas)/sizeof(string)+1; t++)
                    {
                        if((s[i].Vardas[t]>='a' && s[i].Vardas[t]<='z'))
                        {
                            f++;
                        }

                    }
                    if(f==sizeof(s[i].Vardas)/sizeof(string)+1) tik = 1;
                    else
                    {
                        cout << "Teisingai irasykite " << i+1 << "-ojo studento varda" << endl;
                        cin >> s[i].Vardas;
                    }
                }
                else
                {
                        cout << "Teisingai irasykite " << i+1 << "-ojo studento varda" << endl;
                        cin >> s[i].Vardas;
                }
            }while(tik!=1);
            tik = 0;
            f = 0;
            //Tikrina ar pavardeje yra tik 1 didzioji raide ir ar nera skaimenu
            do
            {
                if(s[i].Pavarde[0]>='A' && s[i].Pavarde[0]<='Z')
                {
                    f++;
                    for(int t = 0; t < sizeof(s[i].Pavarde)/sizeof(string)+1; t++)
                    {
                        if((s[i].Pavarde[t]>='a' && s[i].Pavarde[t]<='z'))
                        {
                            f++;
                        }

                    }
                    if(f==sizeof(s[i].Pavarde)/sizeof(string)+1) tik = 1;
                    else
                    {
                        cout << "Teisingai irasykite " << i+1 << "-ojo studento pavarde" << endl;
                        cin >> s[i].Pavarde;
                        f = 0;
                    }
                }
                else
                {
                        cout << "Teisingai irasykite " << i+1 << "-ojo studento varda" << endl;
                        cin >> s[i].Pavarde;
                        f = 0;
                }
            }while(tik!=1);
            for(int j = 0; j < nd ; j++)
            {
               cout << "Irasykite " << j+1 << "-ojo namu darbu rezultatus." << endl;
               cin >> s[i].ND[j];
                while(!(s[i].ND[j]>0 && s[i].ND[j]<11))
                {
                cout << "Teisingai irasykite " << i+1 << "-ojo namu darbu rezultatus." << endl;
                cin >> s[i].E;
                }
            }
            cout << "Irasykite " << i+1 << "-ojo studento egzamino rezultatus." << endl;
            cin >> s[i].E;
            while(!(s[i].E>0 && s[i].E<11))
            {
                cout << "Teisingai irasykite " << i+1 << "-ojo studento egzamino rezultatus." << endl;
                cin >> s[i].E;
            }

        }
        //Vidurkio skaièiavimas
        for(int x = 0; x < n; x++)
        {
            for(int y = 0; y < nd; y++)
            {
                s[x].R=s[x].R+(s[x].ND[y])*0.4;
            }
            s[x].R=s[x].R/nd+s[x].E*0.6;
        }
        //Medianos skaièiavimas
        burbulas(s -> ND,n);
        if(nd==1)
        {
            for(int i = 0; i < n; i++)
            {
                s[i].M=(s[i].ND[nd-1]+s[i].E)/2;
            }
        }
        else
        {
            if(nd%2==0)
            {
                for(int i = 0; i < n; i++)
                {
                    s[i].M=((s[i].ND[nd/2-1]+s[i].ND[nd/2])*0.5+s[i].E)*0.5;
                }
            }
            else
            {
                for(int i = 0; i < n; i++)
                {
                    s[i].M=(s[i].ND[nd/2-1]+s[i].E)/2;
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
void burbulas(int Mas[], int n)
{
   for (int i = 0; i < n-1; i++)

       for (int j = 0; j < n-i-1; j++)
           if (Mas[j] > Mas[j+1])
              swap(Mas[j], Mas[j+1]);
}
