#pragma once
#include <cstdint>
#include <sstream>
#include <string>
#include <iomanip>
#include "SFML/Graphics.hpp"

class IShape
{
public:

    virtual bool ContainsPoint(const sf::Vector2f& point) const = 0;
    
    virtual void DrawSelection(sf::RenderWindow& window) const = 0;
    
    virtual void SetSelected(bool selected) = 0;
    
    virtual bool IsSelected() const = 0;
    
    virtual void Move(const sf::Vector2f& offset) = 0;
	
    virtual std::string ToString() const = 0;

	virtual void Draw(sf::RenderWindow& window) const = 0;
};