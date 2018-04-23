#include "engel.h"

Engel::Engel():Varlik(78,16)
{
    //ctor
    ciz();
}

Engel::~Engel()
{
    //dtor
    sil();
}
void Engel::ciz()
{
    cout<<termcolor::yellow;
    cout<<termcolor::on_blue;
    termcolor::gotoxy(getX(),getY()  );cout<<"###";
    termcolor::gotoxy(getX(),getY()+1);cout<<"###";
    termcolor::gotoxy(getX(),getY()+2);cout<<"###";

}
void Engel::sil()
{
    cout<<termcolor::yellow;
    cout<<termcolor::on_cyan;
    termcolor::gotoxy(getX(),getY()  );cout<<"   ";
    termcolor::gotoxy(getX(),getY()+1);cout<<"   ";
    termcolor::gotoxy(getX(),getY()+2);cout<<"   ";

}
