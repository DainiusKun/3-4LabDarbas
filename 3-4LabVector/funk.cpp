#include "funk.h"
#include "struct.h"
void menu()
{
    int n, sk = 0, k = 0;
    double d;
    string VidM[2]={"Galutinis (Vid.)", "Galutinis (Med.)"}, VM;
    cout << "Ar norite skaityti duomenis is failo, ar norite irasyti ranka?\n";
    cin >> VM;
    while(!(VM=="Failo" || VM=="failo" || VM=="Ranka" || VM=="ranka"))
    {
                cout << "Failo ar ranka?" << endl;
                cin >> VM;
    }
    if(VM=="Failo" || VM == "failo")
    {
        vector<St> s(2);
        int t = 0;
        string word = "";
        const char FL[] = "kursiokai.txt";
        ifstream fd(FL);
        vector<string> vec;
        stringstream ss;
        getline(fd, VM);
        while(getline(fd, VM, '\n'))
        {
            ss.str(VM);
            while(ss >> word)
            {
                vec.push_back(word);
            }
            s[t].Vardas=vec[k];
            k++;
            s[t].Pavarde=vec[k];
            k++;
            for(int j = 0; j < 5; j++)
            {
                d=stod(vec[k]);
                s[t].ND.push_back(d);
                k++;
            }
            d=stod(vec[k]);
            s[t].E=d;
            t++;
            k=0;
            vec.clear();
            ss.clear();
        }
        fd.close();
        for (int x = 0; x < 2; x++)
        {
//////////////////////////Vidurkio skaiciavimas
            for(int y = 0; y < s[x].ND.size() ; y++)
            {
                s[x].R=s[x].R+(s[x].ND[y]);
            }
                s[x].R=s[x].R/s[x].ND.size()*0.4+s[x].E*0.6;
/////////////////////////Mediana
            if(s[x].ND.size()==1)
            {
                s[x].M=s[x].ND[s[x].ND.size()-1];
            }
            else
            {
                if(s[x].ND.size()%2==0)
                {
                    s[x].M=(s[x].ND[s[x].ND.size()-2/2-1]+s[x].ND[s[x].ND.size()-1/2])*0.5;
                }
                else
                {
                    s[x].M=(s[x].ND[s[x].ND.size()-1/2-1]);
                }
            }
//////////////Eilutes pabaiga
        }
            for (int i = 0; i <2-1; i++)
        {
            for (int j=i+1; j < 2; j++)
            {
                if(s[j].Vardas < s[i].Vardas) swap(s[j], s[i]);
            }
        }
        cout << "Ka noretumete pamatyti,rezultatus pagal pazymiu vidurki ar mediana?\n";
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
            for(int j = 0; j < 2; j++)
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
            for(int j = 0; j < 2; j++)
            {
                cout << left << setw(11)<< s[j].Vardas << setw(13) << s[j].Pavarde << setw(16) << right << setprecision(2) << fixed << s[j].M << endl;
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
            vector<St> s(n);
            //Pagrindinis skaiciavimas
            for (int i = 0; i < n; i++)
            {
                cout << "Irasykite " << i+1 << "-ojo studento varda ir pavarde.\n";
                cin >> s[i].Vardas;
                cin >> s[i].Pavarde;
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
                        s[i].ND.push_back(rand()%10+1);
                    }
                    s[i].E=rand()%10+1;
                    //Vidurkio skaiciavimas
                    for(int y = 0; y < s[i].ND.size() ; y++)
                    {
                        s[i].R=s[i].R+(s[i].ND[y]);
                    }
                    s[i].R=s[i].R/s[i].ND.size()*0.4+s[i].E*0.6;
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
                    if(VM=="Ne" || VM =="ne")
                    {
                        cout << "Irasykite " << i+1 << "-ojo studento namu darbu rezultatus. Irase 0 arba skaiciu >10 baigisis ivedimas.\n";
                        cin >> k;
                        while(k!=0)
                        {
                            s[i].ND.push_back(k);
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
//////////////////////////Vidurkio skaiciavimas
                        for(int y = 0; y < s[i].ND.size() ; y++)
                        {
                            s[i].R=s[i].R+(s[i].ND[y]);
                        }
                        s[i].R=s[i].R/s[i].ND.size()*0.4+s[i].E*0.6;
/////////////////////////Mediana
                        if(s[i].ND.size()==1)
                        {
                            s[i].M=s[i].ND[s[i].ND.size()-1];
                        }
                        else
                        {
                            if(s[i].ND.size()%2==0)
                            {
                                s[i].M=(s[i].ND[s[i].ND.size()-2/2-1]+s[i].ND[s[i].ND.size()-1/2])*0.5;
                            }
                            else
                            {
                                s[i].M=(s[i].ND[s[i].ND.size()-1/2-1]);
                            }
                        }
//////////////////////////Eilutes pabaiga
                    }
                }
            }
            for (int i = 0; i <n-1; i++)
            {
                for (int j=i+1; j < n; j++)
                {
                    if(s[j].Vardas < s[i].Vardas) swap(s[j], s[i]);
                }
            }
            cout << "Ka noretumete pamatyti, rezultatus pagal pazymiu vidurki ar mediana?\n";
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
        }
    }
}
