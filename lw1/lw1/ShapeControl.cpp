#include "ShapeControl.h"
#include "ShapeDecorator.h"
#include "CTriangleMathDecorator.h"
#include "CRectangleMathDecorator.h"
#include "CCircleMathDecorator.h"
#include "fstream"
#include "regex"
#include <iostream>

std::regex pattern(R"(\s*([A-Za-z]+)\s*:\s*(P1\s*=\s*(\d+)\s*,\s*(\d+)\s*;\s*P2\s*=\s*(\d+)\s*,\s*(\d+)\s*(;\s*P3\s*=\s*(\d+)\s*,\s*(\d+))?|C\s*=\s*(\d+)\s*,\s*(\d+)\s*;\s*R\s*=\s*(\d+)))");

void ShapeControl::ReadInfo(const std::string& fileName)
{
	std::ifstream input(fileName);
	if (!input.is_open())
	{
		std::cout << "Error input file" << std::endl;
		return;
	}

	std::string line;
	while (std::getline(input, line))
	{
		if (line.empty())
		{
			continue;
		}

			std::shared_ptr<IShape> shape = ConstructShape(line);

		if (shape != nullptr)
		{
			m_shapes.emplace_back(shape);
		}
	}
}

std::shared_ptr<IShape> ShapeControl::ConstructShape(const std::string& line)
{
	std::shared_ptr<IShape> shape = ShapeCreator::CreateShape(line);

	return shape;
}


void ShapeControl::PrintInfo(const std::string& fileName)
{
	std::ofstream output(fileName);
	if (!output.is_open())
	{
		std::cout << "Error output file" << std::endl;
		return;
	}

	for (auto& shape : m_shapes)
	{
		if (shape->ToString() == CCircle::NAME)
		{
			shape = std::make_shared<CCircleMathDecorator>(std::move(shape));
		}
		if (shape->ToString() == CRectangle::NAME)
		{
			shape = std::make_shared<CRectangleMathDecorator>(std::move(shape));
		}
		if (shape->ToString() == CTriangle::NAME)
		{
			shape = std::make_shared<CTriangleMathDecorator>(std::move(shape));
		}
	}

	for (auto const& shape : m_shapes)
	{
		output << shape->ToString() << std::endl;
	}

	output.close();
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
