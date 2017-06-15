#include "PolyLine.h"



PolyLine::PolyLine()
{
	m_vertices.setPrimitiveType(sf::PrimitiveType::LinesStrip);
	m_color = sf::Color::White;
	//m_vertices.append(sf::Vertex());
}


PolyLine::~PolyLine()
{
}

inline void PolyLine::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	// apply the entity's transform -- combine it with the one that was passed by the caller
	states.transform *= getTransform(); // getTransform() is defined by sf::Transformable

										// apply the texture
	states.texture = &m_texture;

	// you may also override states.shader or states.blendMode if you want

	// draw the vertex array
	//target.draw(&m_vertices[0], m_vertices.size(), m_drawType, states);
	target.draw(m_vertices, states);
}
