#include <unistd.h>
#include <systemc.h>

#include "kpn.h"


/* Do not forget that these are implemented as SC_THREAD,
    meaning that they would die if they reach the end of the code.
      Hence, using an infinite loop is necessary */


// ADD THINGS HERE
template <unsigned int depth>
void kpn<depth>::Add(){
    unsigned int ValueA, ValueC;
    while(true){
         /* Reading from the two FIFOs */
        a.read(ValueA); c.read(ValueC);
        /* Sumiing them up */
        ValueA += ValueC;
        /* Writing the sum to the third FIFO */
        b.write(ValueA);
    }   
}

template <unsigned int depth>
void kpn<depth>::Split(){
    unsigned int ValueB;
    while (true){
        /* Reading from the FIFO 'b' */
        b.read(ValueB);
        /* Copying the read value to the two FIFOs 'a' and 'b' */
        a.write(ValueB); d.write(ValueB);
        /* Writing the read value to the output 'e' */
        e.write(ValueB);

        cout << "Value of e:    " << e << endl;
        counter++;
        if (counter >=10){
            sc_stop();
        }
    }
}

template <unsigned int depth>
void kpn<depth>::Delay(){
    unsigned int ValueD;

    while(true){
        /* Reading the value from the FIFO 'd' */
        d.read(ValueD);
        /* Writing the read value to FIFO 'c' */
        c.write(ValueD);
    }
}