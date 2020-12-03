#include <iostream>
#include <fstream> //irankis darbui su bylomis
using namespace std;

void duomenuNuskaitymas(int &kiekis, int Z[], int W[]);
void duomenuSpausdinimas(int W[]);

int main()
{
    int kiekisBalsu;
    int Z[kiekisBalsu];
    int KZ[kiekisBalsu];
    duomenuNuskaitymas(kiekisBalsu, Z, KZ);
    duomenuSpausdinimas(KZ);

    return 0;
}

void duomenuNuskaitymas (int &kiekis, int Z[], int W[])
{
  ifstream in("balsavimo_duomenys.txt");
  int laikinas;
  kiekis=0;
  while(!in.eof())
    {
      in>>laikinas;
      kiekis++;
    }
    in.seekg(0);

    for(int i = 0; i<kiekis;i++)
    {
        in>>Z[i];
    }

    for(int j=0; j<11; j++)
    {
        W[j]=0;
        for(int i=0; i<kiekis; i++)
        {
            if(Z[i]==j+1){W[j]++;}
        }
        in>>W[j];
    }
     in.close();

}
void duomenuSpausdinimas(int W[])
{
    ofstream out("balsavimo_lentele.txt");
    out<<"Kandidato nr."<<" "<<"Balsu kiekis"<<endl;
    for(int j=0; j<10; j++)
    {
      if( W[j]!=0 ) out<<"      "<<j+1<<"            "<<W[j]<<"\n";
    }
    out<<endl;
    out.close();
}
