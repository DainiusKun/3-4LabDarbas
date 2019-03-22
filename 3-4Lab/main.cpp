#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
struct St
{
    string Vardas, Pavarde;
    double *ND, E;
    double R, M;
<<<<<<< HEAD
}*s;
void burbulas(double Mas[], int n);
=======
}*s, *temp;
>>>>>>> parent of 6459567... Mediana_0.1.2
int main()
{
    int n, nd;
    string VidM[2]={"Galutinis (Vid.)", "Galutinis (Med.)"};
    cout << "Kiek yra studentu Jusu grupeje?" << endl;
    cin >> n;
    s = new St[n];
    delete(s);
    s[n].R={0};
    cout << "Kiek namu darbu uzdavete?" << endl;
    cin >> nd;
    for (int i = 0; i < n; i++)
    {
        s[i].ND = new double[nd];
    }

    delete(s -> ND);
    for(int i = 0; i < n; i++)
        {
            cout << "Irasykite " << i+1 << "-ojo studento varda ir pavarde." << endl;
            cin >> s[i].Vardas;
            cin >> s[i].Pavarde;
<<<<<<< HEAD
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
                        f = 0;
                    }
                }
                else
                {
                        cout << "Teisingai irasykite " << i+1 << "-ojo studento varda" << endl;
                        cin >> s[i].Vardas;
                        f=0;
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
                while(!(cin >> s[i].ND[j]) || (!(s[i].ND[j]>0 && s[i].ND[j]<11)))
                {
                cout << "Teisingai irasykite " << i+1 << "-ojo namu darbu rezultatus." << endl;
                cin.clear();
                cin.ignore(256,'\n');
                }
            }
            cout << "Irasykite " << i+1 << "-ojo studento egzamino rezultatus." << endl;
            while(!(cin >> s[i].E)||(!(s[i].E>0 && s[i].E<11)))
            {
                cout << "Teisingai irasykite " << i+1 << "-ojo studento egzamino rezultatus." << endl;
                cin.clear();
                cin.ignore(256,'\n');
            }

=======
            for(int j = 0; j < nd ; j++)
            {
               cout << "Irasykite " << j+1 << "-ojo namu darbu rezultatus." << endl;
               cin >> s[i].ND[j];
            }
            cout << "Irasykite " << i+1 << "-ojo studento egzamino rezultatus." << endl;
            cin >> s[i].E;
>>>>>>> parent of 6a0affb... 0.1.3V
        }
        for(int x = 0; x < n; x++)
        {
            for(int y = 0; y < nd; y++)
            {
                s[x].R=s[x].R+(s[x].ND[y])*0.4;
            }
            s[x].R=s[x].R/nd+s[x].E*0.6;
        }
        cout << left << setw(11)<< "Vardas" << setw(13) << "Pavarde" << setw(17) << "Galutinis (Vid.)";
        cout.fill('-');
        cout.width(41);
        cout << "\n";
        cout.fill(' ');
        cout << "\n";
        for(int j = 0; j < n; j++)
        {
            cout << left << setw(11)<< s[j].Vardas << setw(13) << s[j].Pavarde << setw(16) << right << setprecision(2) << fixed << s[j].R << endl;
        }
    return 0;
}
<<<<<<< HEAD
void burbulas(double Mas[], int n)
{
   for (int i = 0; i < n-1; i++)
=======
>>>>>>> parent of 6459567... Mediana_0.1.2

