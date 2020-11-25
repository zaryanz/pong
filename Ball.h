#include <SFML/Graphics.hpp>
using namespace sf;

class Ball {
private:
    Vector2f m_Position;
    RectangleShape m_Shape;
    float m_Speed = 700.0f;

    float m_DirectionX = 0.2f;
    float m_DirectionY = 0.2f;

public:
    Ball(float startX, float startY);
    RectangleShape getShape();
    FloatRect getPosition();

    void reboundSides();
    void reboundTop();
    void reboundBat();
    void reboundBottom();
    void resetSpeed();
    void incrementSpeed();
    void update(Time dt);
};
