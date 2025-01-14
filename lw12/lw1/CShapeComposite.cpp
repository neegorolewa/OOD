#include "CShapeComposite.h"
#include "CCircle.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include <algorithm>

CShapeComposite::CShapeComposite(const CShapeComposite& other)
{
    for (const auto& shape : other.m_figures)
    {
        if (auto circle = std::dynamic_pointer_cast<CCircle>(shape))
        {
            m_figures.push_back(std::make_shared<CCircle>(*circle));
        }
        else if (auto rectangle = std::dynamic_pointer_cast<CRectangle>(shape))
        {
            m_figures.push_back(std::make_shared<CRectangle>(*rectangle));
        }
        else if (auto triangle = std::dynamic_pointer_cast<CTriangle>(shape))
        {
            m_figures.push_back(std::make_shared<CTriangle>(*triangle));
        }
        else if (auto composite = std::dynamic_pointer_cast<CShapeComposite>(shape))
        {
            m_figures.push_back(std::make_shared<CShapeComposite>(*composite));
        }
    }
}

std::vector<std::shared_ptr<IShape>> CShapeComposite::GetShapes() const
{
    return m_figures;
}

bool CShapeComposite::ContainsPoint(const sf::Vector2f& point) const
{
    for (const auto& shape : m_figures)
    {
        if (shape->ContainsPoint(point))
        {
            return true;
        }
    }
    return false;
}

void CShapeComposite::Draw(sf::RenderWindow& window) const
{
    for (const auto& shape : m_figures)
    {
        shape->Draw(window);
    }
}

void CShapeComposite::DrawSelection(sf::RenderWindow& window) const
{
    for (const auto& shape : m_figures)
    {
        shape->DrawSelection(window);
    }
}

void CShapeComposite::SetSelected(bool selected)
{
    m_selected = selected;

    for (auto& shape : m_figures)
    {
        shape->SetSelected(selected);
    }
}

bool CShapeComposite::IsSelected() const
{
    return m_selected;
}

void CShapeComposite::Move(const sf::Vector2f& offset)
{
    for (auto& shape : m_figures)
    {
        shape->Move(offset);
    }
}

void CShapeComposite::Add(std::shared_ptr<IShape> shape)
{
    m_figures.push_back(shape);
}

void CShapeComposite::Remove(std::shared_ptr<IShape> shape)
{
    m_figures.erase(std::remove(m_figures.begin(), m_figures.end(), shape), m_figures.end());
}

void CShapeComposite::GroupSelected()
{
    auto composite = std::make_shared<CShapeComposite>();
    for (auto it = m_figures.begin(); it != m_figures.end();)
    {
        if ((*it)->IsSelected())
        {
            composite->Add(*it);
            it = m_figures.erase(it);
        }
        else
        {
            ++it;
        }
    }
    if (!composite->m_figures.empty())
    {
        m_figures.push_back(composite);
    }
}

void CShapeComposite::UngroupSelected()
{
    for (auto it = m_figures.begin(); it != m_figures.end();)
    {
        if (auto composite = std::dynamic_pointer_cast<CShapeComposite>(*it); composite && composite->IsSelected())
        {
            for (auto& shape : composite->m_figures)
            {
                m_figures.push_back(shape);
            }
            it = m_figures.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

std::string CShapeComposite::ToString() const
{
    return "CompositeShape";
}