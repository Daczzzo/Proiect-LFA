#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
int stareinit,starifin[10];
char cuvant[20];
int v[100],k;
ifstream f("date.in");
struct tranzitie
{
    int actual;
    char car;
    int urm;
}tranz[20];
void automat(int stareact,char cuvant[20],int n,int nrfin)
{
    int i,OK=0; char s[20];
    if(cuvant[0]==NULL)
    {
        for(i=0;i<nrfin;i++)
            if(stareact==starifin[i])
            {
                v[k]=1;
                k++;
                OK=1;
            }
        if(OK==0)
        {
            v[k]=0;
            k++;
        }
    }
    for(i=0;i<n;i++)
        if(tranz[i].actual==stareact && cuvant[0]==tranz[i].car)
          { strcpy(s,cuvant+1);
              automat(tranz[i].urm,s,n,nrfin);}

}
int main()
{   int n,nrfin;
    cout<<"Introduceti starea initiala:";
    cin>>stareinit;
    cout<<"Introduceti cate stari finale aveti:";
    cin>>nrfin;
    cout<<"Introduceti starile finale:";
    int i,OK=0;
    for(i=0;i<nrfin;i++)
        cin>>starifin[i];
    f>>n;
    for(i=0;i<n;i++)
    {
        f>>tranz[i].actual;
        f>>tranz[i].car;
        f>>tranz[i].urm;
    }
    cout<<"Introduceti cuvantul:"<<endl;
    cin>>cuvant;
    cout<<endl;
    automat(stareinit,cuvant,n,nrfin);
    for(i=0;i<k;i++)
        if(v[i]==1 && OK==0)
    {
        OK=1;
        cout<<"cuvantul apartine"<<endl;
    }
    if(OK==0)
        cout<<"cuvantul nu apartine";
    return 0;
}
