#pragma once
#include "IShape.h"
class CShapeComposite : public IShape
{
public:
    CShapeComposite() = default;
    CShapeComposite(const CShapeComposite& other);

    void Add(std::shared_ptr<IShape> shape);

    void Remove(std::shared_ptr<IShape> shape);

    void GroupSelected();

    void UngroupSelected();

    //---------------------------------------------------//

    std::vector<std::shared_ptr<IShape>> GetShapes() const;

    virtual bool ContainsPoint(const sf::Vector2f& point) const override;

    virtual void DrawSelection(sf::RenderWindow& window) const override;

    virtual void SetSelected(bool selected) override;

    virtual bool IsSelected() const override;

    virtual void Move(const sf::Vector2f& offset) override;

    virtual std::string ToString() const override;

    virtual void Draw(sf::RenderWindow& window) const override;

private:
    std::vector<std::shared_ptr<IShape>> m_figures;

    bool m_selected = false;
};

