#include "uielement.h"

std::vector<UiElement*>* UiElement::getChildren()
{
    return &this->Children;
}

RetVec4 UiElement::getPosSize()
{
    Vector2 parentPos {0, 0};
    Vector2 parentSize = getDimensions();

    // use parents shit if there is one
    if (Parent)
    {
        RetVec4 p = Parent->getPosSize();
        parentPos  = p.Pos;
        parentSize = p.Size;
    }

    // actual positions
    Vector2 finalPosition = parentPos + (parentSize * Position.getScales()) + Position.getOffsets();
    Vector2 finalSize = parentSize * Size.getScales() + Size.getOffsets();

    // anchor point stuff
    finalPosition -= (finalSize * AnchorPoint);

    return {finalPosition, finalSize};
}

// Remove old parent, if new parent is not nullptr, add self to parent's children
void UiElement::parent(std::optional<std::reference_wrapper<UiElement>> p)
{
    if (Parent)
        std::erase(Parent->Children, this);

    if (p.has_value())
    {
        Parent = &p->get();
        Parent->Children.push_back(this);
    }
    else
    {
        Parent = nullptr;
    }
}

// RayU user should never need backendRender. render and backendRender are seperated so calling children's render doesn't need to be in every element's render function.
void UiElement::backendRender() {}
void UiElement::render() 
{
    backendRender();
    
    if (forceCalculation || onClick || onHoverStart || onHoverEnd)
    {
        Vector2 mousePos = GetMousePosition();

        RetVec4 ultimatePosition = getPosSize();

        if (
                mousePos.x <= ultimatePosition.Pos.x + ultimatePosition.Size.x && mousePos.x >= ultimatePosition.Pos.x
            &&  mousePos.y <= ultimatePosition.Pos.y + ultimatePosition.Size.y && mousePos.y >= ultimatePosition.Pos.y
        )
        {
            if (onClick && IsMouseButtonPressed(0))
            {
                onClick();
            }
            if (!hovering)
            {
                hovering = true;
                if (onHoverStart)
                    onHoverStart();
            }
        }
        else
        {
            if (hovering)
            {
                hovering = false;
                if (onHoverEnd)
                    onHoverEnd();
            }
        }
    }

    for (UiElement *child : Children)
        child->render();
}