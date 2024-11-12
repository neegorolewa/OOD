#include "ShapeControl.h"

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

    bool isDragging = false;
    sf::Vector2f dragStart;

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                    bool shiftPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);

                    for (auto& shape : m_shapes)
                    {
                        if (shape->ContainsPoint(mousePos))
                        {
                            if (shiftPressed)
                            {
                                shape->SetSelected(!shape->IsSelected());
                            }
                            else
                            {
                                for (auto& s : m_shapes)
                                {
                                    s->SetSelected(false);
                                }
                                shape->SetSelected(true);
                            }
                            isDragging = true;
                            dragStart = mousePos;
                            break;
                        }
                    }
                }
            }
            else if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    isDragging = false;
                }
            }
            else if (event.type == sf::Event::MouseMoved)
            {
                if (isDragging)
                {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
                    sf::Vector2f offset = mousePos - dragStart;
                    for (auto& shape : m_shapes)
                    {
                        if (shape->IsSelected())
                        {
                            shape->Move(offset);
                        }
                    }
                    dragStart = mousePos;
                }
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::G && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
                {
                    std::cout << "Grouping selected shapes..." << std::endl;
                    for (auto& shape : m_shapes)
                    {
                        if (auto composite = std::dynamic_pointer_cast<CShapeComposite>(shape); composite)
                        {
                            composite->GroupSelected();
                        }
                    }
                }
                else if (event.key.code == sf::Keyboard::U && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
                {
                    std::cout << "Ungrouping selected shapes..." << std::endl;
                    for (auto& shape : m_shapes)
                    {
                        if (auto composite = std::dynamic_pointer_cast<CShapeComposite>(shape); composite)
                        {
                            composite->UngroupSelected();
                        }
                    }
                }
            }
        }

        window.clear(sf::Color::White);

        for (auto const& shape : m_shapes)
        {
            shape->Draw(window);
            if (shape->IsSelected())
            {
                shape->DrawSelection(window);
            }
        }

        window.display();
    }
}
