#include <random>
#include <iostream>

int main(void)
{
    std::mt19937 gen(0);
    std::uniform_real_distribution<double>dis(0,1);
    std::cout << dis(gen)<<  "\n";
    for (int ii=0;ii<=999;ii++){
        std::cout<<dis(gen)<<"\n";
    }
    return 0;
}
