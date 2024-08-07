#pragma once
#include "Component.h"
class RenderComponent : public Component
{
public:

	virtual void draw(class Renderer& renderer) = 0;


};