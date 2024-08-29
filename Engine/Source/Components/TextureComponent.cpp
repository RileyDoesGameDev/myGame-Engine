#include "TextureComponent.h"
#include "Renderer/Renderer.h"
#include "Framework/Actor.h"
#include "Resorce/ResourseManager.h"

#include "Engine.h"

FACTORY_REGISTER(TextureComponent);
void TextureComponent::Read(const json_t& value)
{
	READ_DATA(value, Source);
	READ_DATA(value, textureName);
}
void TextureComponent::Write(json_t& value)
{
}
void TextureComponent::Initialize()
{
	if (!textureName.empty())
	{
		texture = ResourceManager::Instance().Get<Texture>(textureName, owner->scene->engine->GetRenderer());
	}

	if (texture && Source.w == 0 && Source.h == 0)
	{
		Source.x = 0;
		Source.y = 0;
		Source.w = static_cast<int>(texture->GetSize().x);
		Source.h = static_cast<int>(texture->GetSize().y);

	}

}

void TextureComponent::Update(float dt)
{
	
}

void TextureComponent::draw(Renderer& renderer)
{
	Transform transform = owner->transform;
	renderer.DrawTexture(texture, transform, Source);
}
