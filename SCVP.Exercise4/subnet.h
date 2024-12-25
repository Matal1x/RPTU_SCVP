#ifndef SUBNET_H
#define SUBNET_H

#include <systemc.h>

#include "place.h"
#include "transition.h"

// Subnet:
// TODO
SC_MODULE(subnet){
    public:
        sc_port<placeInterface> input;
        sc_port<placeInterface> output;

        SC_CTOR(subnet) :  ACTIVE(0), ACT("ACT"), RD("RD"), PRE("PRE"), WR("WR"){

            ACT.in.bind(input); ACT.out.bind(ACTIVE); ACT.inhibitors.bind(ACTIVE);
            RD.in.bind(ACTIVE); RD.out.bind(ACTIVE);
            PRE.in.bind(ACTIVE); PRE.out.bind(output);
            WR.in.bind(ACTIVE); WR.out.bind(ACTIVE);

            SC_THREAD(process);

        }
        
        void process(){
            return;
        };

        place<1,1> ACTIVE;
        transition<1,1,0> RD, PRE, WR;
        transition<1,1,1> ACT;
};
#endif // SUBNET_H
