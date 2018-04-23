#include "dusman.h"

Dusman::Dusman()
{
    //ctor
    setX(79);
    setY(rand()%14+1);
    ciz();
}

Dusman::~Dusman()
{
    //dtor
    sil();

}
void Dusman::ciz()
{
    cout<<termcolor::blue;
    cout<<termcolor::on_cyan;
    termcolor::gotoxy(getX(),getY()  );cout<<"((";
    termcolor::gotoxy(getX(),getY()+1);cout<<"((";

}
void Dusman::sil()
{
    cout<<termcolor::yellow;
    cout<<termcolor::on_cyan;
    termcolor::gotoxy(getX(),getY()  );cout<<"   ";
    termcolor::gotoxy(getX(),getY()+1);cout<<"   ";

}
