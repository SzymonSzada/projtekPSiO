#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Gra.h"
#include "RedCar.h"

int main() 
{
    //init game engine
    Gra gra;


    //game loop
    while(gra.running()) 
    {
        //update
        gra.update();
        // render
        gra.render(); 

    }
    

    return 0;
}