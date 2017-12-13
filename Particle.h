#include <SFML\Graphics.hpp>

class Particle
{
public:
	Particle();
	~Particle();

	float								getMass();
	sf::Vector2f						getFullForce();
	sf::Vector2f						getPosition();
	void								setMass(float mass);
	void								update(float dt);
	void								addForce(sf::Vector2f);
	void								clearForce();

	sf::Vertex							particle;
		

private:

	float m_mass;
	
	sf::Vector2f						v_force;
	sf::Vector2f						speed;
	sf::Vector2f						m_position;
	sf::Vector2f						prev_position;

};
