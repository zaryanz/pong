#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "Bat.h"
#include "Ball.h"
using namespace sf;

int main() {

    VideoMode vm(640, 480);
    RenderWindow window(vm, "Pong");

    Bat bat(640/2, 400);

    Ball ball(640/2, 0);

    Text hud;
    Font font;
    font.loadFromFile("fonts/DS-DIGI.TTF");
    hud.setFont(font);
    hud.setCharacterSize(25);
    hud.setFillColor(Color::White);
    hud.setPosition(20, 10);

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

        if (Keyboard::isKeyPressed(Keyboard::Key::Right) && bat.getPosition().left + 50 < 640) {
            bat.moveRight();
        } else {
            bat.stopRight();
        }

        if (Keyboard::isKeyPressed(Keyboard::Key::Left) && bat.getPosition().left > 0) {
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

        std::stringstream ss;
        ss << "Score: " << score << " Lives: " << lives;
        hud.setString(ss.str());

        if(ball.getPosition().left < 0 || ball.getPosition().left + 10 > window.getSize().x) {
            ball.reboundSides();
        }

        if(ball.getPosition().intersects(bat.getPosition())) {
            score++;
            ball.reboundBat();
            ball.incrementSpeed();
        }

        if(ball.getPosition().top < 0) {
            ball.reboundTop();
        }

        if(ball.getPosition().top > 500.0f) {
            lives--;
            ball.reboundBottom();
        }

        if(lives == 0) {
            lives = 3;
            score = 0;
            ball.resetSpeed();
        }

        /*********
          draw
         *********/
        window.clear();
        window.draw(hud);
        window.draw(bat.getShape());
        window.draw(ball.getShape());
        window.display();
    }
    return 0;
}