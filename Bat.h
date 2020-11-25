#include <SFML/Graphics.hpp>
using namespace sf;

class Bat {
private:
    Vector2f m_Position;
    RectangleShape m_Shape;
    float m_Speed = 500.0f;

    // movement state
    bool m_IsMovingRight = false;
    bool m_IsMovingLeft = false;

public:
    Bat(float startX, float startY);

    FloatRect getPosition();
    RectangleShape getShape();

    void moveLeft();
    void moveRight();
    void stopLeft();
    void stopRight();
    void update(Time dt);

};
