#pragma once
#include <SFML\Graphics.hpp>
class PolyLine : public sf::Drawable, public sf::Transformable
{
public:

	PolyLine();

	~PolyLine();

	// add functions to play with the entity's geometry / colors / texturing...
	
	sf::VertexArray m_vertices;
private:

	
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	//std::vector<sf::VertexArray> m_vertices;
	//sf::PrimitiveType m_drawType;
	sf::Texture m_texture;
	sf::Color m_color;
};