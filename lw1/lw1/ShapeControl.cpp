#include "ShapeControl.h"

void ShapeControl::ConstructShape(const std::string& line)
{
	std::shared_ptr<IShape> shape = ShapeCreator::CreateShape(line);

	m_shapes.emplace_back(shape);
}

void ShapeControl::DrawShapes()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH_WINDOW, HEIGHT_WINDOW), NAME_WINDOW);

	while (window.isOpen())
	{
		sf::Event event{};
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear(sf::Color::White);

		for (auto const& shape : m_shapes)
		{
			shape->Draw(window);
		}

		window.display();
	}
}
