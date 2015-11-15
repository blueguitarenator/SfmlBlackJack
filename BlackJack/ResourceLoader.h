#pragma once
#include <SFML/Graphics.hpp>

class ResourceLoader
{
public:
	ResourceLoader();
	~ResourceLoader();

	// fonts
	static const std::string ARCON_FONT;
	static const std::string REISLING_FONT;

	// PNGs
	static const std::string FELT;
	static const std::string CHIPS;
	static const std::string CARD_BACK;

	void loadFont(sf::Font& font, const std::string& fontName);
	void loadTexture(sf::Texture& texture, const std::string& filename);
};

