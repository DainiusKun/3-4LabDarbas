#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
struct St
{
    string Vardas, Pavarde;
    int *ND, E;
    double R, M;
}*s, *temp;
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
        s[i].ND = new int[nd];
    }

    delete(s -> ND);
    for(int i = 0; i < n; i++)
        {
            cout << "Irasykite " << i+1 << "-ojo studento varda ir pavarde." << endl;
            cin >> s[i].Vardas;
            cin >> s[i].Pavarde;
            for(int j = 0; j < nd ; j++)
            {
               cout << "Irasykite " << j+1 << "-ojo namu darbu rezultatus." << endl;
               cin >> s[i].ND[j];
            }
            cout << "Irasykite " << i+1 << "-ojo studento egzamino rezultatus." << endl;
            cin >> s[i].E;
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

