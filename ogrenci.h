#ifndef OGRENCI_H
#define OGRENCI_H

#include "varlik.h"


class Ogrenci : public Varlik
{
    public:
        Ogrenci();
        ~Ogrenci();
        void ciz();
        void sil();
        void setOtur(bool durum);
        bool getOtur();
        void setZipla(bool durum);
        bool getZipla();
        void setYuksel(bool durum);
        bool getYuksel();


    protected:

    private:
        bool mOtur;
        bool mZipla;
        bool mYuksel;

};

#endif // OGRENCI_H
