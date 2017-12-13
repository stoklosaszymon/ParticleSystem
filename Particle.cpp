#include "Particle.h"



Particle::Particle() : m_mass(50), m_position(rand() % 1400, rand() % 1000) {

}


Particle::~Particle()
{
}

void Particle::setMass(float mass)
{
	m_mass = mass;
}

float Particle::getMass()
{
	return m_mass;
}

void Particle::update(float dt)
{
	prev_position = m_position;
	m_position = m_position + speed*(float)dt + 0.5f * getFullForce() / m_mass*(float)pow(dt, 2);
	speed = (m_position - prev_position) / (float)dt;
	particle.position = m_position;
	clearForce();
}

sf::Vector2f Particle::getPosition()
{
	return m_position;
}


void Particle::addForce(sf::Vector2f force) {
	v_force += force;
}

sf::Vector2f Particle::getFullForce() {
	return v_force;
}

void Particle::clearForce() {
	v_force = sf::Vector2f(0.0, 0.0);
}