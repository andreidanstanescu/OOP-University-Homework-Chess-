#include "Mutari.h"


template<typename T>
T& Mutari<T>::LastMove(){
    try{
        if(vf<0)
            throw My_Exception("Joc neinceput\n");
    }
    catch(My_Exception& e)
    {
        std::cout<<e.what()<<'\n';
    }
    return s[vf];
}


template<typename T>
void Mutari<T>::Reverse(sf::Event& event)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        --vf;
}

template<typename T>
void Mutari<T>::AddMove(const T&x)
{
    std::logic_error e("50 Move Rule !");
    if(vf==N-1)
        throw e;
    s[++vf]=x;
}


