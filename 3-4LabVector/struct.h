#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
struct St
{
    string Vardas, Pavarde;
    double E, R, M;
    list <double> ND;
    void rik();
    void vidurkis();
};
void St::rik()
{
    sort(ND.begin(),ND.end());
}
#endif // STRUCT_H_INCLUDED
