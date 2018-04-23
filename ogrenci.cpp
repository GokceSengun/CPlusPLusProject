#include "ogrenci.h"

Ogrenci::Ogrenci():Varlik(5,15)
{
    //ctor
    setOtur(false);
    ciz();
}

Ogrenci::~Ogrenci()
{
    //dtor
    sil();
}
void Ogrenci::ciz()
{
    cout<<termcolor::red;
    cout<<termcolor::on_cyan;
    if(getOtur())
    {
    termcolor::gotoxy(getX(),getY()  );cout<<"   ";
    termcolor::gotoxy(getX(),getY()+1);cout<<"   ";
    termcolor::gotoxy(getX(),getY()+2);cout<<" "<<char(1)<<" ";
    termcolor::gotoxy(getX(),getY()+3);cout<<"< >";
    }
    else
    {
    termcolor::gotoxy(getX(),getY()  );cout<<" "<<char(1)<<" ";
    termcolor::gotoxy(getX(),getY()+1);cout<<"/|\\";
    termcolor::gotoxy(getX(),getY()+2);cout<<" |";
    termcolor::gotoxy(getX(),getY()+3);cout<<"/ \\";
    }

}
void Ogrenci::sil()
{
    cout<<termcolor::yellow;
    cout<<termcolor::on_cyan;
    termcolor::gotoxy(getX(),getY()  );cout<<"   ";
    termcolor::gotoxy(getX(),getY()+1);cout<<"   ";
    termcolor::gotoxy(getX(),getY()+2);cout<<"   ";
    termcolor::gotoxy(getX(),getY()+3);cout<<"   ";

}
void Ogrenci::setOtur(bool durum)
{
    mOtur =durum;
    ciz();
}
bool Ogrenci::getOtur()
{
    return mOtur;
}
void Ogrenci::setZipla(bool durum)
{
    mZipla=durum;
}
bool Ogrenci::getZipla()
{
    return mZipla;

}
void Ogrenci::setYuksel(bool durum)
{
    mYuksel=durum;

}
bool Ogrenci::getYuksel()
{
    return mYuksel;
}
