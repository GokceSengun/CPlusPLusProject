#include "varlik.h"

Varlik::Varlik()
{
    //ctor
    setX(5);
    setY(10);
}

Varlik::~Varlik()
{
    //dtor
    sil();
}
Varlik::Varlik(int x,int y)
{
    setX(x);
    setY(y);

}
void Varlik::ciz()
{
    ///çocuklar çizecek
}
void Varlik::sil()
{
    ///çocuklar silecek
}
void Varlik::hareketEt(int dx,int dy)
{
    sil();
    setX(getX()+dx); ///mX +=dx;
    setY(getY()+dy); ///mY +=dy;
    ciz();

}
void Varlik::setX(int x)
{
    mX=x>0&& x<81? x:mX; ///&& ve demek
    /*
    if(x>0 && x<81)
        mX=x;
    */
}
int Varlik::getX()
{
    return mX;
}
void Varlik::setY(int y)
{
    mY=y>0&& y<25? y:mY;
}
int Varlik::getY()
{
    return mY;
}
