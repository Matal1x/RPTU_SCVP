#ifndef PLACE_H
#define PLACE_H

#include <systemc.h>

// <=v2
/*
class placeInterface : public sc_interface
{
public:
    virtual void addTokens(unsigned int n) = 0;
    virtual void removeTokens(unsigned int n) = 0;
    virtual unsigned int testTokens() = 0;
};

class place : public placeInterface {

    public:
        unsigned int tokens;

        void addTokens(unsigned int n);
        void removeTokens(unsigned int n);
        unsigned int testTokens();

        place(int t) : tokens(t){}
};
*/

class placeInterface : public sc_interface
{
public:
    virtual void addTokens() = 0;
    virtual void removeTokens() = 0;
    virtual bool testTokens() = 0;
};

template<unsigned int Win = 1, unsigned int Wout = 1>
class place : public placeInterface {

    public:
        unsigned int tokens;

        void addTokens();
        void removeTokens();
        bool testTokens();

        place(int t) : tokens(t){}
};


#endif