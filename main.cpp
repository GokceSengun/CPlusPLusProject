#include <iostream>
#include<conio.h>
#include<cstdlib>
#include<time.h>
#include<vector>
#include"engel.h"
#include"varlik.h"
#include"ogrenci.h"
#include"ates.h"
#include"dusman.h"

using namespace std;
void ekran()
{
    for(int i=1;i<81;i++)
    {

        for (int j=1;j<19;j++)
        {
            cout<<termcolor::white;
            cout<<termcolor::on_cyan;
            termcolor::gotoxy(i,j);

            cout<<" ";

        }
    }
    for(int i=1;i<81;i++)
    {

        for (int j=19;j<25;j++)
        {
            cout<<termcolor::white;
            cout<<termcolor::on_green;
            termcolor::gotoxy(i,j);
            cout<<char(176);
        }
    }
}
int puan=0; ///c zaten kendiliğinden 0 degerini verir ama sen yine de sıfıra esitle.
int main()
{
    srand(time(NULL));
    ekran();
    Engel *hoca = NULL;///new Engel
    Ogrenci *Tarkan = new Ogrenci;

    unsigned long int frame =1;
    int engelZamani= rand()%10+1;
    int tus ;
    int hainZamani =rand()%10+5;
    vector <Dusman *>Hainler;
    vector <Dusman *>::iterator kostok;

    vector<Ates *>Atesler;
    vector<Ates *>::iterator mermi; ///iteratörün içindeki bir tane elemandýr


    while(tus!=27) ///esc ye basýlmadýðý sürece devam
    {
        if(kbhit())
        {
            tus=getch();
            if(tus=='A' || tus=='a')
            {
                Tarkan ->hareketEt(-1,0);
            }
            else if(tus=='D' || tus=='d')
            {
                if(Tarkan->getX()<41)
                    Tarkan->hareketEt(1,0);
            }
            else if(tus=='S' || tus=='s')
            {
                    Tarkan->setOtur(!Tarkan->getOtur());
            }
            else if(tus=='W' || tus=='w')
            {
                if(Tarkan->getZipla()==false)
                {
                    Tarkan->setZipla(true);
                    Tarkan->setYuksel(true);
                }
            }

            else if (tus==32) ///boþluðun kodu
            {
                Ates *disu =new Ates(Tarkan ->getX()+3,Tarkan->getY()+1);
                Atesler.push_back(disu);

            }
        }
        ///bize düþman lazým
            if(frame%hainZamani==0)
            {
                Dusman * ahtapot;
                ahtapot =new Dusman;
                Hainler.push_back(ahtapot);
            }

        ///engel yoksa ve zamaný geldiyse engel olustur.
        if(hoca==NULL && frame%engelZamani==0)
        {
            hoca = new Engel;
        }
        ///engel ilerlet
        if (hoca!=NULL) ///engel varsa hareket et
        {
            hoca ->hareketEt(-1,0);
            if (hoca->getX()<2)///sola gel engeli sil
            {
                delete hoca ;
                hoca= NULL;
                engelZamani= rand()%20+5;
                puan+=20;
            }
        }
        ///zipla
        if(Tarkan-> getZipla()==true)
        {
            if (Tarkan ->getYuksel())
            {

                Tarkan->hareketEt(0,-1);
                if(Tarkan -> getY()<3)
                {
                    Tarkan ->setYuksel(false);
                }

            }else
            { ///alçalýyorsa
                Tarkan->hareketEt(0,1);
                if(Tarkan -> getY()>14)
                {
                    Tarkan ->setZipla(false);
                }
            }
        }
        ///dusmanlari ilerlet
        for(kostok=Hainler.begin();kostok!=Hainler.end();kostok++)
        {
            (*kostok) -> hareketEt(-1,0);
            //cout << "a";
        }

        ///ateşleri ilerlet
        for(mermi=Atesler.begin();mermi<Atesler.end();mermi++)
        {
            (*mermi) -> hareketEt(1,0);
        }
        ///çarpýsma testi
            ///dusman vs ates
            kostok=Hainler.begin();
            while(kostok!=Hainler.end())
            {
                bool carpti =false;
                mermi=Atesler.begin();
                while(mermi !=Atesler.end())
                {

                    if((*mermi) ->getX()>= (*kostok) -> getX()&&
                       (*mermi) -> getY()>=(*kostok) -> getY()&&
                       (*mermi) -> getY()>=(*kostok) -> getY()+2)
                    {
                        ///çarptı
                        delete *mermi;
                        Atesler.erase(mermi);///ateşler vektörünün içinden iteratör siliniyor.
                        delete *kostok;
                        Hainler.erase(kostok);
                        carpti=true;
                        puan+= 10;
                        break;
                    }
                    else
                        mermi++;
                }
                    if(!carpti)
                        kostok++;
            }

            ///düsman kontrol
        kostok=Hainler.begin();
        while(kostok!=Hainler.end())
        {
            if((*kostok)->getX()<2)
            {
                delete *kostok;
                Hainler.erase(kostok);
            }
            else
                kostok++;
        }
            ///mermi kotrolü
        mermi=Atesler.begin();
        while(mermi!=Atesler.end())
        {
            if((*mermi)-> getX()>79)
            {
                delete *mermi; ///nesneyi sil
                Atesler.erase(mermi);///vectorden kalan iþaretçi
            }
            else
                mermi++;
        }
        ///engele çarpan mermi kontrol
        if(hoca!=NULL)
        {
            mermi=Atesler.begin();
            while(mermi!=Atesler.end())
            {
                if((*mermi)-> getX()>=hoca ->getX()&&(*mermi)->getY()>=hoca -> getY())
                {
                    delete *mermi; ///nesneyi sil
                    Atesler.erase(mermi);///vectorden kalan iþaretçi
                }
                else
                    mermi++;
        }
        }
        ///ölelim mi
        ///engele çarptıysam öl
        if(hoca!=NULL &&
           Tarkan ->getX()+3>=hoca ->getX()&&
           Tarkan ->getX()<=hoca ->getX()+3&&
           Tarkan ->getY()+4>=hoca ->getY())
           {

               cout<<"\nGAME OVER \n";
               break;
           }
           ///düşmana carptıysa öl
           kostok=Hainler.begin();
           while(kostok!=Hainler.end())
           {
               if(Tarkan ->getX()+3>=(*kostok)->getX()&&
                  Tarkan ->getX()<=(*kostok)->getX()+2&&
                  Tarkan ->getY()+4>=(*kostok)->getY()&&
                  Tarkan ->getY()<=(*kostok)->getY()+2)
               {
                   return 0;
               }
               else
                kostok++;

           }

        Sleep(50);
        frame ++;
        cout<<termcolor::white;
        termcolor::on_grey;
        termcolor::gotoxy(1,25);
        cout<<"Frame"<<frame;
        termcolor::gotoxy(1,1);
        cout<<"Puan:"<<puan;
    }
    return 0;
}
