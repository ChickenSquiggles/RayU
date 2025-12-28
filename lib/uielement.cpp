#include "uielement.h"

void UiElement::render() {
    backendRender();
    if (!Children.empty()) {
        for (UiElement *child : Children) {
            child->render();
        }
    }
}

void UiElement::backendRender() {
    printf("you cant do that");
}

RetVec4 UiElement::getPosSize() {
    Vec2 absPos;
    Vec2 absSize;
    if (Parent == nullptr) {
        absPos.x = Position.X.Scale * GetScreenWidth() + Position.X.Offset;
        absPos.y = Position.Y.Scale * GetScreenHeight() + Position.Y.Offset;
        absSize.x = Size.X.Scale * GetScreenWidth() + Size.X.Offset;
        absSize.y = Size.Y.Scale * GetScreenHeight() + Size.Y.Offset;
        absPos.x -= absSize.x*AnchorPoint.x;
        absPos.y -= absSize.y*AnchorPoint.y;
    } else {
        const RetVec4 pPosSize = Parent->getPosSize();

        absPos.x = pPosSize.Pos.x + pPosSize.Size.x * Position.X.Scale + Position.X.Offset;
        absPos.y = pPosSize.Pos.y + pPosSize.Size.y * Position.Y.Scale + Position.Y.Offset;

        absSize.x = pPosSize.Size.x * Size.X.Scale + Size.X.Offset;
        absSize.y = pPosSize.Size.y * Size.Y.Scale + Size.Y.Offset;

        absPos.x -= absSize.x*AnchorPoint.x;
        absPos.y -= absSize.y*AnchorPoint.y;
    }
    return RetVec4{absPos, absSize};
}

void UiElement::parent(UiElement *p) {
    if (Parent != nullptr) {
        std::erase(p->Children, this);
    }
    Parent = p;
    p->Children.push_back(this);
}