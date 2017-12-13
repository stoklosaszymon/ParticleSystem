#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(int ammount)
{
	createParticles(ammount);
}


ParticleSystem::~ParticleSystem()
{

}

void ParticleSystem::createParticles(int ammount)
{
	for (int i = 0; i < ammount; i++)
	{
		particles.push_back( std::make_unique<Particle>() );
	}
}

void ParticleSystem::updatePosition(float dt) {
	for (auto &particle : particles) {
		particle->update(dt);
	}
}

void ParticleSystem::mouseMove() {
	if (btnPressed) {
		for (auto &particle : particles) {
			particle->addForce((mousePosition - particle->getPosition()) / pow(Distance(particle->getPosition(), mousePosition), 2));
		}
	}
}


float ParticleSystem::Distance(sf::Vector2f& v1, sf::Vector2f& v2)
{
	return sqrt(pow((v2.x - v1.x), 2) + pow((v2.y - v1.y), 2));
}