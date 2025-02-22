## Templated Channel and Modelling a Single Memory Bank
 template<unsigned int Win, unsigned int Wout> // Do not forget to add the template and remove the default values
 void place<Win, Wout>::addTokens() // Also don't forget to add the template next to the class
 {
     tokens += Win;
 }

## SC_THREAD
they would die if they reach the end of the code.
Hence, using an infinite loop is necessary

## TLM
#### LT
 Target inherits from sc_module and tlm::tlm_fw_transport_if<>
 and has tSocket:
 
    class memory: sc_module, tlm::tlm_fw_transport_if<>{
        public:
            tlm::tlm_target_socket<> tSocket;
            SC_CTOR(memory) : tSocket("tSocket")
            {
            tSocket.bind(*this);
            }
    }

 Initiator inherits from sc_module and tlm::tlm_bw_transport_if<>
 and has iSocket

    class processor : public sc_module, tlm::tlm_bw_transport_if<>
    {
        public:
	        tlm::tlm_initiator_socket<> iSocket;
    }


 BOTH have dummy functions that have to be implemented


 Interconnect inherits from sc_module, tlm::tlm_bw_transport_if<> and tlm::tlm_fw_transport_if<>
 and has both tSocket and Isocket:

    class bus: sc_module, tlm::tlm_bw_transport_if<>, tlm::tlm_fw_transport_if<>{
        public:
            tlm::tlm_initiator_socket<> iSocket[I];
            tlm::tlm_target_socket<> tSocket[T];

            SC_CTOR(bus)
            {
                for (int i=0; i<I; i++){
                    iSocket[i].bind(*this);
                }          
                for (int t=0; t<T; t++){
                    tSocket[t].bind(*this);
                }
            }
    }

<!-- ROADMAP -->
## Roadmap
#### Exercise-1
- [ ] TODO
- [X] DONE
<p align="right">(<a href="#top">back to top</a>)</p>

#### Exercise-2
- [ ] TODO
- [X] DONE
<p align="right">(<a href="#top">back to top</a>)</p>

#### Exercise-3
- [ ] TODO
- [X] DONE
<p align="right">(<a href="#top">back to top</a>)</p>

#### Exercise-4
- [ ] TODO
- [X] DONE
<p align="right">(<a href="#top">back to top</a>)</p>

#### Exercise-5
- [ ] TODO
- [X] DONE
<p align="right">(<a href="#top">back to top</a>)</p>

#### Exercise-6
- [ ] TODO
- [X] DONE
<p align="right">(<a href="#top">back to top</a>)</p>

#### Exercise-7
- [ ] TODO
- [X] DONE
<p align="right">(<a href="#top">back to top</a>)</p>

#### Exercise-8
- [ ] TODO
- [X] DONE
<p align="right">(<a href="#top">back to top</a>)</p>

<!-- CONTACT -->
## Contact

<!-- Your Name - email@example.com -->
- Mohamed ASLAOUI - aslaoui.mohamed@edu.rptu.de 
<p align="right">(<a href="#top">back to top</a>)</p>