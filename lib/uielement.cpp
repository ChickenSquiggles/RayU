#include "uielement.h"

std::vector<UiElement*>* UiElement::getChildren()
{
    return &this->Children;
}

RetVec4 UiElement::getPosSize()
{
    Vector2 parentPos {0, 0};
    Vector2 parentSize {
        (float)GetScreenWidth(),
        (float)GetScreenHeight()
    };

    if (Parent)
    {
        RetVec4 p = Parent->getPosSize();
        parentPos  = p.Pos;
        parentSize = p.Size;
    }

    Vector2 finalPosition {
        parentPos.x + parentSize.x * Position.X.Scale + Position.X.Offset,
        parentPos.y + parentSize.y * Position.Y.Scale + Position.Y.Offset
    };

    Vector2 finalSize {
        parentSize.x * Size.X.Scale + Size.X.Offset,
        parentSize.y * Size.Y.Scale + Size.Y.Offset
    };

    finalPosition.x -= finalSize.x * AnchorPoint.x;
    finalPosition.y -= finalSize.y * AnchorPoint.y;

    return {finalPosition, finalSize};
}


void UiElement::parent(UiElement *p) 
{
    if (p == Parent)
        return;
    
    if (Parent)
        std::erase(Parent->Children, this);

    Parent = p;

    if (Parent)
        Parent->Children.push_back(this);
}

void UiElement::backendRender() {}
void UiElement::render() 
{
    backendRender();
    
    for (UiElement *child : Children) 
    {
        child->render();
    }
}