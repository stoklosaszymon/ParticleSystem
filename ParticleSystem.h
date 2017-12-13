#pragma once
#include "Particle.h"
#include <memory>

class ParticleSystem
{
public:
	ParticleSystem(int);
	~ParticleSystem();
	void										createParticles(int);
	void										updatePosition(float);
	void										mouseMove();
	float										Distance(sf::Vector2f& v1, sf::Vector2f& v2);
	bool										btnPressed;
	
	std::vector<std::unique_ptr<Particle>>		particles;

	sf::Vector2f								mousePosition;
};