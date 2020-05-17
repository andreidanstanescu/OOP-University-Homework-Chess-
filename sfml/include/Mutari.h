#ifndef MUTARI_H
#define MUTARI_H
#include "My_Exception.h"
#include "table.h"

const int N=1e7;

template<typename T>
class Mutari
{
int vf; //ca un fel de varful stivei
int nrm;
T s[N];
    public:
        Mutari(){
            vf=-1;
            nrm=0;
        };
        T& LastMove();

        Mutari& operator++()
        {
            ++nrm;
            return *this;
        }

        template<typename U>
        Mutari operator++(U)
        {
            Mutari<T> aux(*this);
            ++(*this);
            return aux;
        }

        Mutari& operator--()
        {
            nrm=0;
            return *this;
        }

        bool check_draw()
        {
            if(nrm==50)
                return 1;
            return 0;
        }

        void Reverse(sf::Event& event);
        void AddMove(const T& x);

        ~Mutari(){
        };

};

#endif // MUTARI_H
