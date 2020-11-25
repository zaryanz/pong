#include <SFML/Graphics.hpp>
#include "Bat.h"
#include "Ball.h"
using namespace sf;

int main() {

    VideoMode vm(640, 480);
    RenderWindow window(vm, "Pong");

    Bat bat(640/2, 400);

    Ball ball(640/2, 0);

    int lives = 3;
    int score = 0;

    Clock clock;

    while(window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        /*********
         handle input
         *********/
        if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
            window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
            bat.moveRight();
        } else {
            bat.stopRight();
        }

        if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
            bat.moveLeft();
        } else {
            bat.stopLeft();
        }


        /*********
          update
         *********/
        Time dt = clock.restart();
        bat.update(dt);
        ball.update(dt);

        if(ball.getPosition().left < 0 || ball.getPosition().left + 10 > window.getSize().x) {
            ball.reboundSides();
        }

        if(ball.getPosition().intersects(bat.getPosition())) {
            ball.reboundTopOrBat();
        }

        if(ball.getPosition().top < 0) {
            ball.reboundTopOrBat();
        }

        /*********
          draw
         *********/
        window.clear();
        window.draw(bat.getShape());
        window.draw(ball.getShape());
        window.display();
    }
    return 0;
}