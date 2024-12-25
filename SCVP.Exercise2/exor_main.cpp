#include <systemc.h>

#include "stim.h"
#include "exor.h"
#include "mon.h"

int sc_main(int, char**)
{
    sc_signal<bool> sigA, sigB, sigZ;
    sc_clock clk("clk", 10, SC_NS);

    stim Stim1("Stimulus");
    Stim1.A(sigA);
    Stim1.B(sigB);
    Stim1.Clk(clk);

    exor DUT("exor");
    DUT.A(sigA);
    DUT.B(sigB);
    DUT.Z(sigZ);

    Monitor mon("Monitor");
    mon.A(sigA);
    mon.B(sigB);
    mon.Z(sigZ);
    mon.Clk(clk);

    // Task 3        
    // sc_trace_file* Tf;
    // Tf = sc_create_vcd_trace_file("traces");
    // sc_trace(Tf, sigA, "Signal-A");
    // sc_trace(Tf, sigB, "Signal-B");
    // sc_trace(Tf, sigZ, "Signal-Z");
    // sc_start(); // run forever
    // sc_close_vcd_trace_file(Tf);


    sc_trace_file* Tf;
    Tf = sc_create_vcd_trace_file("tracesT4");
    sc_trace(Tf, sigA, "Signal-A");
    sc_trace(Tf, sigB, "Signal-B");
    sc_trace(Tf, sigZ, "Signal-Z");
    sc_trace(Tf, clk, "Clock");
    sc_start(); // run forever
    sc_close_vcd_trace_file(Tf);

    
    return 0;
}
