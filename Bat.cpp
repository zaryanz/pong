#include "Bat.h"

Bat::Bat(float startX, float startY)
{
    m_Position.x = startX;
    m_Position.y = startY;

    m_Shape.setSize(sf::Vector2f(50,5));
    m_Shape.setPosition(m_Position);
    m_Shape.setFillColor(Color::White);
}

FloatRect Bat::getPosition()
{
    return m_Shape.getGlobalBounds();
}

RectangleShape Bat::getShape()
{
    return m_Shape;
}

void Bat::moveLeft()
{
    m_IsMovingLeft = true;
}

void Bat::moveRight()
{
    m_IsMovingRight = true;
}

void Bat::stopLeft()
{
    m_IsMovingLeft = false;
}

void Bat::stopRight()
{
    m_IsMovingRight = false;
}

void Bat::update(Time dt)
{
    if(m_IsMovingRight) {
        m_Position.x += m_Speed * dt.asSeconds();
    }
    if(m_IsMovingLeft) {
        m_Position.x -= m_Speed * dt.asSeconds();
    }
    m_Shape.setPosition(m_Position);
}


