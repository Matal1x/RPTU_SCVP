#ifndef EXOR_H
#define EXOR_H

#include <systemc.h>

#include "nand.h"

// TODO: Insert your code here
SC_MODULE(exor) {
    sc_in<bool> A, B;
    sc_out<bool> Z;

    sc_signal<bool> sig1, sig2, sig3;

    nand nanda, nandb, nandc, nandd;

    SC_CTOR(exor) : nanda("nanda"), nandb("nandb"), nandc("nandc"), nandd("nandd") {
        nanda.A(A);
        nanda.B(B);
        nanda.Z(sig1);

        nandb.A(A);
        nandb.B(sig1);
        nandb.Z(sig2);

        nandc.A(sig1);
        nandc.B(B);
        nandc.Z(sig3);

        nandd.A(sig2);
        nandd.B(sig3);
        nandd.Z(Z);
    }
};
#endif // EXOR_H
