#include "Renderer.h"
#include "Texture.h"
#include "Math/Transform.h"
#include "Math/Vector2.h"
#include <iostream>

bool Renderer::Initialize()
{
		// initialize SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
			return false;
		}
		// initialize TTF SDL
		if (TTF_Init() < 0)
		{
			std::cerr << "Error initializing SDL TTF: " << SDL_GetError() << std::endl;
			return false;
		}



		// initialize Image SDL, supports BMP, JPG, and PNG
		if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == 0)
		{
			std::cerr << "Error initializing SDL Image: " << SDL_GetError() << std::endl;
			return false;
		}




		return true;
}

void Renderer::Shutdown()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	TTF_Quit();
}

bool Renderer::CreateWindow(std::string title, int width, int height)
{
	m_width = width;
	m_height = height;

	 m_window = SDL_CreateWindow(title.c_str(),
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width, height,
		SDL_WINDOW_SHOWN);
	if (m_window == nullptr)
	{
		std::cerr << "Error creating SDL window: " << SDL_GetError() << std::endl;
		SDL_Quit();
		IMG_Quit();
		return 1;

	}
	// create renderer
	 m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	return true;
}

void Renderer::BegineFrame()
{
	SDL_RenderClear (m_renderer);
}

void Renderer::EndFrame()
{
	SDL_RenderPresent(m_renderer);
}

void Renderer::SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	SDL_SetRenderDrawColor(m_renderer, r, g, b,a);
}

void Renderer::DrawLine(int x1, int y1, int x2, int y2)
{
	SDL_RenderDrawLine(m_renderer, x1,y1,x2,y2);
}

void Renderer::DrawLine(float x1, float y1, float x2, float y2)
{
	SDL_RenderDrawLineF (m_renderer, x1, y1, x2, y2);
}

void Renderer::DrawPoint(int x, int y)
{
	SDL_RenderDrawPoint(m_renderer, x, y);
}

void Renderer::DrawPoint(float x, float y)
{
	SDL_RenderDrawPointF(m_renderer, x, y);
}

void Renderer::DrawRect(int x, int y, int w, int h)
{
	SDL_Rect rect{x,y,w,h};
	SDL_RenderFillRect(m_renderer, &rect);
}

void Renderer::DrawRect(float x, float y, float w, float h)
{
	SDL_FRect rect{ x,y,w,h };
	SDL_RenderFillRectF(m_renderer, &rect);
}

void Renderer::DrawTexture(std::weak_ptr<Texture>texture, float x, float y, float angle)
{
	
	Vector2 size = texture.lock()->GetSize();

		SDL_FRect destRect;
	destRect.x = x - size.x * 0.5f;
	destRect.y = y - size.y * 0.5f;
	destRect.w = size.x;
	destRect.h = size.y;

	// https://wiki.libsdl.org/SDL2/SDL_RenderCopyExF
	SDL_RenderCopyExF(m_renderer, texture.lock()->m_texture, NULL, &destRect, angle, NULL, SDL_FLIP_NONE);
}

void Renderer::DrawTexture(std::weak_ptr<Texture>texture, const Transform& transform, bool hflip)
{
	Vector2 size = texture.lock()->GetSize() * transform.scale;

	SDL_FRect destRect;
	destRect.x = transform.position.x;
	destRect.y = transform.position.y;
	destRect.w = size.x;
	destRect.h = size.y;

	// https://wiki.libsdl.org/SDL2/SDL_RenderCopyExF
	SDL_RenderCopyExF(m_renderer, texture.lock()->m_texture, NULL, &destRect, transform.rotation, NULL, (hflip) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);

}

void Renderer::DrawTexture(std::weak_ptr<Texture> texture, const Transform& transform, Rect& source, bool hflip)
{
	Vector2 size = Vector2{ source.w, source.h } *transform.scale;

	SDL_FRect destRect;
	destRect.x = transform.position.x;
	destRect.y = transform.position.y;
	destRect.w = size.x;
	destRect.h = size.y;

	// https://wiki.libsdl.org/SDL2/SDL_RenderCopyExF
	SDL_RenderCopyExF(m_renderer, texture.lock()->m_texture,(SDL_Rect*)&source, &destRect, transform.rotation, NULL, (hflip) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

