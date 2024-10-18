#include <iostream>
#include <Porcentaje.hpp>
#include <list>

int mian1(){
    

    porcentaje foco1;
    porcentaje foco2;
    porcentaje foco3;

    foco1.Incrementar(10);
    foco1.Incrementar(10);
    foco1.Disminuir(4);

    std::cout
    <<"foco 1:"
    <<foco1.Imprimir()
    <<std::endl;

return 0;
}

