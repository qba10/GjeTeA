//============================================================================
// Name        : GjeTeA.cpp
// Author      : Piotr Piórkowski, Mateusz Nojek
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <SFML/Graphics.hpp>
#include <cmath>

int main()
{
  //ddd
    sf::RenderWindow okno( sf::VideoMode( 320, 240 ), "Kurs SFML 2.0 - http://cpp0x.pl" );
    sf::Clock stoper;
    while( okno.isOpen() )
    {
        sf::Event event;
        while( okno.pollEvent( event ) )
        {
            if( event.type == sf::Event::Closed )
                 okno.close();

        } //while
        okno.clear();



        okno.display();
    } //while
    return 0;
}
