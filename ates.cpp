#include "ates.h"

Ates::Ates(int x,int y):Varlik (x,y)
{
    //ctor
    ciz();

}

Ates::~Ates()
{
    //dtor
    sil();
}
void Ates::ciz()
{
    cout<<termcolor::dark;
    cout<<termcolor::on_cyan;
    termcolor::gotoxy(getX(),getY()  );cout<<"*";
}
void Ates::sil()
{
    cout<<termcolor::white;///istersem silerim bosluðun rengi olmaz.
    cout<<termcolor::on_cyan;
    termcolor::gotoxy(getX(),getY()  );cout<<"   ";
}
