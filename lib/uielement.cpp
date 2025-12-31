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
void UiElement::parent(UiElement& p) 
{
    if (&p == Parent)
        return;
    
    if (Parent)
        std::erase(Parent->Children, this);

    Parent = &p;

    if (Parent)
        Parent->Children.push_back(this);
}

// RayU user should never need backendRender. render and backendRender are seperated so calling children's render doesn't need to be in every element's render function.
void UiElement::backendRender() {}
void UiElement::render() 
{
    backendRender();
    
    for (UiElement *child : Children)
        child->render();
}