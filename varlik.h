#ifndef VARLIK_H
#define VARLIK_H
#include<iostream>
#include"termcolor.hpp"
using namespace std;


class Varlik
{
    public:
        Varlik();
        Varlik(int x,int y);
        virtual void ciz(); ///ata class yerine cocugumdaký fonksiyonu çaðýrsýn bir nevi ezmek de denir.
        virtual void sil();
        void hareketEt(int dx,int dy);
        void setX(int x);
        int getX();
        void setY(int y);
        int getY();
        virtual ~Varlik();

    protected:
        int mX;
        int mY;


    private:

};

#endif // VARLIK_H
