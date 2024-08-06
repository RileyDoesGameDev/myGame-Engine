#pragma once
#include "../Recorse/Recorce.h"

#include <SDL_ttf.h>
#include <string>


class Font : public Resource
{
public:
	Font() = default;
	~Font();
	friend class Text;

	bool Create(std::string name, ...) override;
	bool Load(const std::string& name, int fontSize);

private:
	_TTF_Font* m_ttfFont{ nullptr };

	
};