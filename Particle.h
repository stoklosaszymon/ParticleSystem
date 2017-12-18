#include <SFML\Graphics.hpp>
#include <GL/glut.h>

class Particle
{
public:
	Particle();
	~Particle();

	float								getMass();
	sf::Vector2f						getFullForce();
	sf::Vector2f						getPosition();
	sf::Vector2f						getSpeed();
	void								setMass(float mass);
	void								update(float dt);
	void								addForce(sf::Vector2f);
	void								clearForce();

	void								draw(sf::RenderTarget& target, sf::RenderStates states);

private:

	float m_mass;
	
	sf::Vector2f						v_force;
	sf::Vector2f						speed;
	sf::Vector2f						m_position;
	sf::Vector2f						prev_position;

};
