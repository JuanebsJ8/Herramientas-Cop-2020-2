#define CATCH_CONFIG_MAIN 
#include "catch2/catch.hpp"

#include "header.h"

TEST_CASE ("All tests", "[Main]"){
    
    CONFIG config;
    config.read("init_data.txt");

    std::mt19937 gen(config.seed);
    std::uniform_int_distribution<int> dis_move(0, 1);
    std::uniform_int_distribution<int> dis_particle(0,config.nmolecules-1);
    std::uniform_int_distribution<int> dis_location(-config.latticesize/2, config.latticesize/2 - 1);
    std::unifrom_int_distribution<int> dis_hole(-config.holesize/2, config.holesize/2);
    
    Vec_p Particles(config.nmolecules);
    Vec_i Cells(config.gridsize*config.gridsize,0);
    
    int x = 0, y = 0, m = 0;

    for (int i = 0; i < config.nmolecules; i++){

        x = dis_location(gen);
        y = dis_location(gen);

        Particles[i].position[0] = x;
        Particles[i].position[1] = y;
        m = Particles[i].Getcell(config);
        Cells[m] += 1;

  

    SECTION ("Cells conditions"){

        int sum = 0;     //La suma de todas las casillas debe dar el número de particulas

        for (int i = 0; i < config.gridsize*config.gridsize; i++){

            sum += Cells[i];

        }

        REQUIRE (sum == config.nmolecules);

        Particles[0].position[0] = -config.latticesize/2;    //Esquina inferior izquierda del grid
        Particles[0].position[1] = -config.latticesize/2;

        m = Particles[0].Getcell(config);

        REQUIRE (m == 0);

        Particles[0].position[0] = config.latticesize/2 - 1;    //Esquina superior derecha del grid
        Particles[0].position[1] = config.latticesize/2 - 1;

        m = Particles[0].Getcell(config);

        REQUIRE (m == config.gridsize*config.gridsize - 1);

        int random_particle = 0, step = 0, direction = 0;

        for (int t = 0; t <= 50; t++){

            random_particle = dis_particle(gen);     
            step = dis_move(gen)*2 - 1;  
            direction = dis_move(gen);

            Particles[random_particle].Move(step, direction, config, Cells);
            
        }

        sum = 0;

        for (int i = 0; i < config.gridsize*config.gridsize; i++){

            sum += Cells[i];

        }

        REQUIRE (sum == config.nmolecules);
        
    }

    SECTION ("Entropy conditions"){

        double Entropy = 0;

        for (int i = 0; i < config.gridsize*config.gridsize; i++){

            Cells[i] = 0;

        }

        for (int i = 0; i < config.nmolecules; i++){

            Particles[i].position[0] = 0;
            Particles[i].position[1] = 0;
            m = Particles[i].Getcell(config);
            Cells[m] += 1;

        }

        Entropy = entropy(config, Cells);

        REQUIRE (Entropy == 0);

    }
    
}
