//imprimir los valores de la funcion de legendre entre 0 y 10 y en pasos de 0.1
#include <cmath>
#include <iostream>
int main()
{
    const double XMIN=0.0,XMAX=10.0;
        const int N=2;
        std::cout.precision(15);std::cout.setf(std::ios::scientific);
    for(double x=XMIN; x<=XMAX; x=x+0.01){
        std::cout<<'x'<<"\t"<<std::legendre(N,x)<<'\n';
    }
    return 0;
}
