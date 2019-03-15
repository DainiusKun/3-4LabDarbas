#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
    string Vardas[30], Pavarde[30];
    int n;
    float ND[30], E[30], R[30];
    cout << "Kiek yra studentu Jusu grupeje?" << endl;
    cin >> n;
    if (n>30) cout << "Jus turite per daug studentu vienai grupei." << endl;
    else
    {
        for(int i = 0; i < n; i++)
        {
            cout << "Irasykite " << i+1 << "-ojo studento varda ir pavarde." << endl;
            cin >> Vardas[i];
            cin >> Pavarde[i];
            cout << "Irasykite " << i+1 << "-ojo studento namu darbu rezultatus." << endl;
            cin >> ND[i];
            cout << "Irasykite " << i+1 << "-ojo studento egzamino rezultatus." << endl;
            cin >> E[i];
            R[i]=0.4*ND[i]+0.6*E[i];
        }
        cout << left << setw(11)<< "Vardas" << setw(13) << "Pavarde" << setw(17) << "Galutinis (Vid.)";
        cout.fill('-');
        cout.width(41);
        cout << "\n";
        cout.fill(' ');
        cout << "\n";
        for(int j = 0; j < n; j++)
        {
            cout << left << setw(11)<< Vardas[j] << setw(13) << Pavarde[j] << setw(16) << right << setprecision(2) << fixed << R[j] << endl;
        }

    }
    return 0;
}
