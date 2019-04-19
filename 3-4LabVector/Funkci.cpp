#include "funk.h"
#include "struct.h"
void apdorojimas(deque <St> &s, const char FV[], int n);
void Rezultatai(St &temp);
void VRik(deque <St> &s, int n);
void Ekranas(deque <St> &s, int n, string VM);
void ProtingiIrNe(deque <St> &s, int n, string VM);
bool VardTik(const St &a, const St &b);
void programa()
{
    int n, k = 0;
    St temp;
    string VM;
    cout << "Ar norite skaityti duomenis is failo, ar norite irasyti ranka?\n";
    cin >> VM;
    while(!(VM=="Failo" || VM=="failo" || VM=="Ranka" || VM=="ranka"))
    {
        cout << "Failo ar ranka?" << endl;
        cin >> VM;
    }
    if(VM=="Failo" || VM == "failo")
    {
        cout << "Kiek studentu grupeje? 10, 100, 1000, 10000 ar 100000?\n";
        while(!(cin >> n))
        {
            cout << "10, 100, 1000, 10000 ar 100000?\n";
            cin.clear();
            cin.ignore(256,'\n');
        }
        deque<St> s;
        const char FL2[] = "10.txt";
        const char FL3[] = "100.txt";
        const char FL4[] = "1000.txt";
        const char FL5[] = "10000.txt";
        const char FL6[] = "100000.txt";
        while(!(n==10 || n==100 || n==1000 || n == 10000 || n == 100000))
        {
            cout << "10, 100, 1000, 10000 ar 100000?\n";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> n;
        }
        auto start = std::chrono::high_resolution_clock::now(); // Spartos analizes pradzia
        if(n==10) apdorojimas(s,FL2,n);
        if(n==100) apdorojimas(s,FL3,n);
        if(n==1000) apdorojimas(s,FL4,n);
        if(n==10000) apdorojimas(s,FL5,n);
        if(n==100000) apdorojimas(s,FL6,n);
        auto end = std::chrono::high_resolution_clock::now(); // Pabaiga.
        duration<double> diff = end-start; // Skirtumas (s)
        cout << n <<" elementu apdorojimas uztruko: " << diff.count() << " s\n";
        start = std::chrono::high_resolution_clock::now(); // Spartos analizes pradzia
        VRik(s, n);
        end = std::chrono::high_resolution_clock::now(); // Pabaiga.
        diff = end-start; // Skirtumas (s)
        cout << n <<" elementu rikiavimas uztruko: " << diff.count() << " s\n";
        cout << "Ar norite rasyti i failus, ar i ekrana?\n";
        cin >> VM;
        while(!(VM=="Failus" || VM=="failus" || VM=="Ekrana" || VM=="ekrana"))
        {
            cout << "Failus ar ekrana?" << endl;
            cin >> VM;
        }
        if(VM=="Ekrana" || VM == "ekrana")
        {
            Ekranas(s, n, VM);
        }
        else
        {
            if(VM =="Failus" || VM == "failus")
            {
                ProtingiIrNe(s, n, VM);
            }
        }
    }
    else
    {
        if(VM=="Ranka" || VM == "ranka")
        {
            cout << "Kiek yra studentu Jusu grupeje?\n";
            while(!(cin >> n))
            {
                cout << "Neteisingai ivedete studentu skaiciu, bandykite dar karta." << endl;
                cin.clear();
                cin.ignore(256,'\n');
            }
            deque <St> s(n);
            //Pagrindinis skaiciavimas
            for (int i = 0; i < n; i++)
            {
                cout << "Irasykite " << i+1 << "-ojo studento varda ir pavarde.\n";
                cin >> temp.Vardas;
                cin >> temp.Pavarde;
                cout << "Ar norite atsitiktiniu rezultatu?\n";
                cin >> VM;
                while(!(VM=="Taip" || VM=="taip" || VM=="Ne" || VM=="ne"))
                {
                cout << "Taip ar ne?" << endl;
                cin >> VM;
                }
                if(VM=="Taip" || VM=="taip")
                {
                    k=rand();
                    for(int g = 0; g < k; g++)
                    {
                        temp.ND.push_back(rand()%10+1);
                    }
                    temp.E=rand()%10+1;
                    Rezultatai(temp);
                    s.push_back(temp);
                }
                else
                {
                    if(VM=="Ne" || VM =="ne")
                    {
                        cout << "Irasykite " << i+1 << "-ojo studento namu darbu rezultatus. Irase 0 arba skaiciu >10 baigsis ivedimas.\n";
                        while(!(cin >> k))
                        {
                            cout << "Teisingai irasykite namu darbu rezultatus." << endl;
                            cin.clear();
                            cin.ignore(256,'\n');
                        }
                        while(k>0 && k < 11)
                        {
                            temp.ND.push_back(k);
                            cin >> k;
                            while(!(cin))
                            {
                                cout << "Teisingai irasykite namu darbu rezultatus." << endl;
                                cin.clear();
                                cin.ignore(256,'\n');
                            }
                        }
                        while(temp.ND.size()==0)
                        {
                            while(!(k>0 && k < 11))
                            {
                                cout << "Irasykite bent viena rezultata." << endl;
                                cin >> k;
                            }
                            temp.ND.push_back(k);
                        }
                        cout << "Irasykite " << i+1 << "-ojo studento egzamino rezultata.\n";
                        while(!(cin >> temp.E))
                        {
                            cout << "Teisingai irasykite " << i+1 << "-ojo studento egzamino rezultata." << endl;
                            cin.clear();
                            cin.ignore(256,'\n');
                        }
                        while(temp.E<0 || temp.E>10)
                        {
                            cout << "Teisingai irasykite " << i+1 << "-ojo studento egzamino rezultata." << endl;
                            cin.clear();
                            cin.ignore(256,'\n');
                            cin >> temp.E;
                        }
                        Rezultatai(temp);
                        s.push_back(temp);
                    }
                }
            }
            Ekranas(s, n, VM);
        }
    }
}
void apdorojimas(deque <St> &s, const char FV[], int n)
{
    ifstream fd(FV);
    if(fd.is_open())
    {
        St temp;
        int k = 0;
        double d;
        string linija;
        string word = "";
        vector <string> vec;
        stringstream ss;
        getline(fd, linija);
        while(getline(fd, linija, '\n'))
        {
            ss.str(linija);
            while(ss >> word)
            {
                vec.push_back(word);
            }
            temp.Vardas=vec[k];
            k++;
            temp.Pavarde=vec[k];
            k++;
            for(int j = 0; j < vec.size()-3; j++)
            {
                d=stod(vec[k]);
                temp.ND.push_back(d);
                k++;
            }
            d=stod(vec[k]);
            temp.E=d;
            Rezultatai(temp);
            k=0;
            s.push_back(temp);
            vec.clear();
            ss.clear();
            temp.ND.clear();
        }
        fd.close();
    }
    else
    {
        if(fd.fail())cout << "Neturite tinkamo failo.\n";
    }
}
void Rezultatai(St &temp)
{
    for(int i = 0; i < temp.ND.size(); i++ )
    {
        temp.R = temp.R+temp.ND[i];
    }
    temp.R = temp.R/temp.ND.size()*0.4+temp.E*0.6;
    if(temp.ND.size()==1)
    {
        temp.M=temp.ND[temp.ND.size()-1];
    }
    else
    {
        if(temp.ND.size()%2==0)
        {
            temp.M=(temp.ND[temp.ND.size()-2/2-1]+temp.ND[temp.ND.size()-1/2])*0.5;
        }
        else
        {
            temp.M=(temp.ND[temp.ND.size()-1/2-1]);
        }
    }
}
void VRik(deque <St> &s, int n)
{
    sort(s.begin(), s.end(), VardTik);
}
bool VardTik(const St &a, const St &b)
{
    if(a.Vardas == b.Vardas) return a.Pavarde < b.Pavarde;
    return a.Vardas < b.Pavarde;
}
void Ekranas(deque <St> &s, int n, string VM)
{
    cout << "Ka noretumete pamatyti,rezultatus pagal pazymiu vidurki ar mediana?\n";
    cin >> VM;
    while(!(VM=="Vidurki" || VM=="vidurki" || VM=="Mediana" || VM=="mediana"))
    {
        cout << "Vidurki ar mediana?" << endl;
        cin >> VM;
    }
    if(VM=="Vidurki" || VM=="vidurki")
    {
        cout << left << setw(11)<< "Vardas" << setw(13) << "Pavarde" << setw(17) << "Galutinis (Vid.)";
        cout.fill('-');
        cout.width(41);
        cout << "\n";
        cout.fill(' ');
        cout << "\n";
        for(int j = 0; j < n; j++)
        {
            cout << left << setw(11)<< s.front().Vardas << setw(13) << s.front().Pavarde << setw(16) << right << setprecision(2) << fixed << s.front().R << endl;
            s.pop_front();
        }
    }
    if(VM=="Mediana" || VM=="mediana")
    {
        cout << left << setw(11)<< "Vardas" << setw(13) << "Pavarde" << setw(17) << "Galutinis (Med.)";
        cout.fill('-');
        cout.width(41);
        cout << "\n";
        cout.fill(' ');
        cout << "\n";
        for(int j = 0; j < n; j++)
        {
            cout << left << setw(11)<< s.front().Vardas << setw(13) << s.front().Pavarde << setw(16) << right << setprecision(2) << fixed << s.front().M << endl;
            s.pop_front();
        }
    }
}
void ProtingiIrNe(deque <St> &s, int n, string VM)
{
    ofstream fr("Vargsai.txt");
    ofstream fg("Protingi.txt");
    deque <St> Vargsai;
    deque <St> Protingi;
    cout << "Ka noretumete pamatyti,rezultatus pagal pazymiu vidurki ar mediana?\n";
    cin >> VM;
    while(!(VM=="Vidurki" || VM=="vidurki" || VM=="Mediana" || VM=="mediana"))
    {
        cout << "Vidurki ar mediana?" << endl;
        cin >> VM;
    }
    if(VM == "Vidurki" || VM == "vidurki")
    {
        auto start = std::chrono::high_resolution_clock::now(); // Spartos analizes pradzia
        for (int i = 0; i <n; i++)
        {
            if(s.back().R>=5)
            {
                Protingi.push_back(s.back());
                s.pop_back();
            }
            else
            {
                Vargsai.push_back(s.back());
                s.pop_back();
            }
        }
        auto end = std::chrono::high_resolution_clock::now(); // Pabaiga.
        duration<double> diff = end-start; // Skirtumas (s)
        cout << n <<" elementu rusiavimas uztruko: " << diff.count() << " s\n";
        start = std::chrono::high_resolution_clock::now(); // Spartos analizes pradzia
            fr << left << setw(11)<< "Vardas" << setw(13) << "Pavarde" << setw(17) << "Galutinis (Vid.)";
            fr.fill('-');
            fr.width(41);
            fr << "\n";
            fr.fill(' ');
            fr << "\n";
            while(Vargsai.size()!=0)
            {
                fr << left << setw(11)<< Vargsai.back().Vardas << setw(13) << Vargsai.back().Pavarde << setw(16) << right << setprecision(2) << fixed << Vargsai.back().R << endl;
                Vargsai.pop_back();
            }
            fr.close();
            fg << left << setw(11)<< "Vardas" << setw(13) << "Pavarde" << setw(17) << "Galutinis (Vid.)";
            fg.fill('-');
            fg.width(41);
            fg << "\n";
            fg.fill(' ');
            fg << "\n";
            while(Protingi.size()!=0)
            {
                fg << left << setw(11)<< Protingi.back().Vardas << setw(13) << Protingi.back().Pavarde << setw(16) << right << setprecision(2) << fixed << Protingi.back().R << endl;
                Protingi.pop_back();
            }
            fg.close();
        end = std::chrono::high_resolution_clock::now(); // Pabaiga.
        diff = end-start; // Skirtumas (s)
        cout << n <<" elementu rasymas uztruko: " << diff.count() << " s\n";
    }
    if(VM== "Mediana" || VM == "mediana")
    {
        auto start = std::chrono::high_resolution_clock::now(); // Spartos analizes pradzia
        for (int i = 0; i <n; i++)
        {
            if(s.back().M>=5)
            {
                Protingi.push_back(s.back());
                s.pop_back();
            }
            else
            {
                Vargsai.push_back(s.back());
                s.pop_back();
            }
        }
        auto end = std::chrono::high_resolution_clock::now(); // Pabaiga.
        duration<double> diff = end-start; // Skirtumas (s)
        cout << n <<" elementu rusiavimas uztruko: " << diff.count() << " s\n";
        start = std::chrono::high_resolution_clock::now(); // Spartos analizes pradzia
            fr << left << setw(11)<< "Vardas" << setw(13) << "Pavarde" << setw(17) << "Galutinis (Vid.)";
            fr.fill('-');
            fr.width(41);
            fr << "\n";
            fr.fill(' ');
            fr << "\n";
            while(Vargsai.size()!=0)
            {
                fr << left << setw(11)<< Vargsai.back().Vardas << setw(13) << Vargsai.back().Pavarde << setw(16) << right << setprecision(2) << fixed << Vargsai.back().M << endl;
                Vargsai.pop_back();
            }
            fr.close();
            fg << left << setw(11)<< "Vardas" << setw(13) << "Pavarde" << setw(17) << "Galutinis (Vid.)";
            fg.fill('-');
            fg.width(41);
            fg << "\n";
            fg.fill(' ');
            fg << "\n";
            while(Protingi.size()!=0)
            {
                fg << left << setw(11)<< Protingi.back().Vardas << setw(13) << Protingi.back().Pavarde << setw(16) << right << setprecision(2) << fixed << Protingi.back().M << endl;
                Protingi.pop_back();
            }
            fg.close();
        end = std::chrono::high_resolution_clock::now(); // Pabaiga.
        diff = end-start; // Skirtumas (s)
        cout << n <<" elementu rasymas uztruko: " << diff.count() << " s\n";
    }
}
