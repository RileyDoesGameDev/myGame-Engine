#pragma once
#include "../Resorce/Resorce.h"

#include <SDL_ttf.h>
#include <string>


class Font : public Resource
{
public:
	Font() = default;
	~Font();
	friend class Text;

	bool Create(std::string name, ...) override;
	bool Load(const std::string& filename, int fontSize);
	friend class Text;
private:
	_TTF_Font* m_ttfFont{ nullptr };

	
};