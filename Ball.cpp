#include <SFML/Graphics.hpp>
#include "Ball.h"

Ball::Ball(float startX, float startY)
{
    m_Position.x = startX;
    m_Position.y = startY;

    m_Shape = RectangleShape(sf::Vector2f(10,10));
    m_Shape.setPosition(m_Position);
}

RectangleShape Ball::getShape()
{
    return m_Shape;
}

FloatRect Ball::getPosition()
{
    return m_Shape.getGlobalBounds();
}

void Ball::reboundSides()
{
    m_DirectionX = -m_DirectionX;
}

void Ball::reboundTopOrBat()
{
    m_DirectionY = -m_DirectionY;
}

void Ball::reboundBottom()
{
    m_Position.y = 0;
    m_Position.x = 500;
    m_DirectionY = -m_DirectionY;
}

void Ball::update(Time dt)
{
    m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();
    m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();

    m_Shape.setPosition(m_Position);
}