#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>


int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(900, 900), "My window");

    // create some shapes
    sf::CircleShape circle(100.0);
    circle.setPosition(100.0, 300.0);
    circle.setFillColor(sf::Color(100, 250, 50));

    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));
    rectangle.setPosition(500.0, 400.0);
    rectangle.setFillColor(sf::Color(100, 50, 250));

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle.setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle.setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle.setOutlineColor(sf::Color::Magenta);
    triangle.setOutlineThickness(5);
    triangle.setPosition(600.0, 100.0);

    sf::ConvexShape hex;
    hex.setPointCount(6);
    hex.setPoint(0, sf::Vector2f(60.0, 0.0));
    hex.setPoint(1, sf::Vector2f(20.0, 60.0));
    hex.setPoint(2, sf::Vector2f(60.0, 120.0));
    hex.setPoint(3, sf::Vector2f(120.0, 120.0));
    hex.setPoint(4, sf::Vector2f(160.0, 60.0));
    hex.setPoint(5, sf::Vector2f(120.0, 0.0));
    hex.setOutlineColor(sf::Color::Red);
    hex.setOutlineThickness(7);
    hex.setPosition(600.0, 600.0);

    sf::Clock timer;
    int rectangle_velocity_x = 50
       ,rectangle_velocity_y = 150
       ,rectangle_angular_velocity = 15
       ;

    // run the program as long as the window is open
    while (window.isOpen())
     {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle);
        window.draw(hex);

        sf::Time elapsed = timer.restart();
//        std::cout << elapsed.asMicroseconds() << std::endl;

        rectangle.move(elapsed.asSeconds()*rectangle_velocity_x, elapsed.asSeconds()*rectangle_velocity_y);
        rectangle.rotate(elapsed.asSeconds()*rectangle_angular_velocity);

        sf::FloatRect rectangle_bounds = rectangle.getGlobalBounds();
//        std::cout << rectangle_bounds.top << " " << rectangle_bounds.left << " " ;
        std::cout << rectangle_bounds.width << " " << rectangle_bounds.height << std::endl;


        if(rectangle_bounds.height+rectangle_bounds.top>=900)
         {
          rectangle_velocity_y *= -1;
          rectangle.setFillColor(sf::Color(rand() % 256,rand() % 256,rand() % 256));
         }

        if(rectangle_bounds.top<=0)
         {
          rectangle_velocity_y *= -1;
          rectangle.setFillColor(sf::Color(rand() % 256,rand() % 256,rand() % 256));
         }


        if(rectangle_bounds.left<=0)
         {
          rectangle_velocity_x *= -1;
          rectangle.setFillColor(sf::Color(rand() % 256,rand() % 256,rand() % 256));
         }

        if(rectangle_bounds.left+rectangle_bounds.width>=900)
         {
          rectangle_velocity_x *= -1;
          rectangle.setFillColor(sf::Color(rand() % 256,rand() % 256,rand() % 256));
         }

        // end the current frame
        window.display();


     }

    return 0;
}
