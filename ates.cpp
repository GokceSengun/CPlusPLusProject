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
    cout<<termcolor::white;///istersem silerim boslu�un rengi olmaz.
    cout<<termcolor::on_cyan;
    termcolor::gotoxy(getX(),getY()  );cout<<"   ";
}
