#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <systemc.h>
#include <string>

// TODO
SC_MODULE(stateMachine){
    sc_in <char> input;
    sc_in <bool> clk;

    enum base {Start, G, GA, GAA, GAAG};
    base current_state;

    int counter, Acounter, pos;

    void process(){
        // std::cout << "Inside process" << std::endl;
        // std::cout << "Current state: " << current_state << std::endl;
        // std::cout << "Input: " << input.read() << std::endl;
        // std::cout << std::endl;

        pos++;
        switch (current_state)
        {
        case Start:
            if (input.read() == 'G')
            {
                Acounter = 0;
                current_state = G;
            }
            break;
        
        case G:
            if (input.read() == 'A')
            {
                current_state = GA;
            }
            else if (input.read() == 'G')
            {
                current_state = G;
            }
            else if ( (input.read() == 'T') || (input.read() == 'C') )
            {
                current_state = Start;
            }
            break;

        case GA:
            if (input.read() == 'A')
            {
                current_state = GAA;
            }
            // if it's G then it will just stay in G
            else if (input.read() == 'G')
            {
                current_state = G;
            }
            else
            {
                current_state = Start;
            }
            break;

        case GAA:
            if (input.read() == 'G')
            {
                current_state = GAAG;
            }
            else if (input.read() == 'A')
            {
                current_state = GAA; // Task .3 
                Acounter++;
            }
            else
            {
                current_state = Start;
            }
            break;

        case GAAG:
            std::cout << "GAA" << std::string(Acounter, 'A') << "G" << std::endl;

            counter++;
            std::cout << "Number of occurences: " << counter << std::endl;
            std::cout << "From Character number " << pos-4-Acounter << " to " << pos <<std::endl;
            std::cout << std::endl;

            if (input.read() == 'G')
            {
                current_state = G;
            }
            else
            {
                current_state = Start;
            }
            break;
        default:
            current_state = Start;
            std::cout << "Default" << std::endl;
            counter = 0; pos = 0;
            break;
        }
    }

    SC_CTOR(stateMachine){
        SC_METHOD(process);
        sensitive << clk.pos();
        current_state = Start;
        counter = 0; pos = 0; Acounter= 0;
        dont_initialize();
    }
};
#endif // STATE_MACHINE_H


