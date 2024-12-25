#include <systemc.h>

#include "place.h"
#include "transition.h"
#include "subnet.h"

// Custom Interfaces, Ports and Channels
/*
void place::addTokens(unsigned int n)
{
    tokens += n;
}
void place::removeTokens(unsigned int n)
{
    tokens -= n;
}


unsigned int place::testTokens()
{
    return this->tokens;
}
*/

// Custom Interfaces, Ports and Channels
/*
SC_MODULE(toplevel){
    public:
        SC_CTOR(toplevel) : p1(1), p2(0), t1("t1"), t2("t2"){

            t1.in.bind(p1); t1.out.bind(p2);
            t2.in.bind(p2); t2.out.bind(p1);
            SC_THREAD(process);
        }
        
        place p1,p2;
        transition t1,t2;

        void process()
        {
            while (true)
            {
                wait(10, SC_NS);
                t1.fire();
                wait(10, SC_NS);
                t1.fire();
                wait(10, SC_NS);
                t2.fire();
                sc_stop();
            }
        }
};
*/

//  Multiports and Templated Channel
/*
SC_MODULE(toplevel){
    public:
        SC_CTOR(toplevel) : p1(1), p2(0), p3(0), p4(0), t1("t1"), t2("t2"), t3("t3"){

            t1.in.bind(p1);     t1.out.bind(p2);     t1.out.bind(p3);
            t2.in.bind(p2);  t2.in.bind(p4);      t2.out.bind(p1);
            t3.in.bind(p3);     t3.out.bind(p4);
            SC_THREAD(process);
        }
        
        place<1,1> p1,p2,p3,p4;
        transition<1,2> t1;
        transition<2,1> t2;
        transition<1,1> t3;
       void process()
        {
            while (true)
            {
                wait(10, SC_NS);
                t1.fire();
                wait(10, SC_NS);
                t2.fire();
                wait(10, SC_NS);
                t3.fire();
                wait(10, SC_NS);
                t2.fire();
                sc_stop();
            }
        }
};
*/

// Templated Channel and Modelling a Single Memory Bank
template<unsigned int Win, unsigned int Wout> // Do not forget to add the template and remove the default values
void place<Win, Wout>::addTokens() // Also don't forget to add the template next to the class
{
    tokens += Win;
}
template<unsigned int Win, unsigned int Wout>
void place<Win, Wout>::removeTokens()
{
    tokens -= Wout;
}
template<unsigned int Win, unsigned int Wout>
bool place<Win, Wout>::testTokens()
{
    return (tokens >= Wout);
}

// Modelling a Single Memory Bank
/*
SC_MODULE(toplevel){
    public:
        SC_CTOR(toplevel) : IDLE(1), ACTIVE(0), ACT("ACT"), RD("RD"), PRE("PRE"), WR("WR"){

            ACT.in.bind(IDLE); ACT.out.bind(ACTIVE);
            RD.in.bind(ACTIVE); RD.out.bind(ACTIVE);
            PRE.in.bind(ACTIVE); PRE.out.bind(IDLE);
            WR.in.bind(ACTIVE); WR.out.bind(ACTIVE);
            SC_THREAD(process);
        }
        
        place<1,1> IDLE, ACTIVE;
        transition<1,1> ACT, RD, PRE, WR;
        void process()
        {
            while (true)
            {
 
                wait(10, SC_NS);
                ACT.fire();
                wait(10, SC_NS);
                ACT.fire();
                wait(10, SC_NS);
                RD.fire();
                wait(10, SC_NS);
                WR.fire();
                wait(10, SC_NS);
                PRE.fire();
                wait(10, SC_NS);
                ACT.fire();
                sc_stop();
            }
        }
};
*/

// Implementation of Inhibitor Arcs & Building Hierarchical PNs
SC_MODULE(toplevel){
    public:
    place<1,1> IDLE;
    subnet s1, s2;

     SC_CTOR(toplevel) : IDLE(2), s1("s1"), s2("s2"){
        s1.input.bind(IDLE); s1.output.bind(IDLE);
        s2.input.bind(IDLE); s2.output.bind(IDLE);

        SC_THREAD(process);
     }
    void process()
     {
        while (true)
        {
            wait(10, SC_NS);
            s1.ACT.fire();
            wait(10, SC_NS);
            s1.ACT.fire();
            wait(10, SC_NS);
            s1.RD.fire();
            wait(10, SC_NS);
            s1.WR.fire();
            wait(10, SC_NS);
            s1.PRE.fire();
            wait(10, SC_NS);
            s1.ACT.fire();
            wait(10, SC_NS);
            s2.ACT.fire();
            wait(10, SC_NS);
            s2.ACT.fire();
            wait(10, SC_NS);
            s1.PRE.fire();
            wait(10, SC_NS);
            s2.PRE.fire();
            wait(10, SC_NS);
            sc_stop();
        }
    }
};
int sc_main(int, char**)
{
    // TODO
    toplevel t("top_level");
    sc_start();
    return 0;
}
