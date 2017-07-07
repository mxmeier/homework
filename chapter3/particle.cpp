#include <iostream>
#include <unique_id>
#include <string>
#include <constants>


class vector
{

};

class position
{

};

class direction
{

};

class four_momentum
{

};

enum class ParticleType
{
	Mu = 11,
	MuBar = -11,
};

class particle
{
    /** A particle.
     *
     * 4-momentum, spin, position, mass, charge, pdg_encoding,
     * name, unique_id, magnetic_charge, lifetime
     */
public:
	particle(ParticleType type){
		switch(type){
			case ParticleType::Mu:
				name = "Mu";
				mass = MASS_MU;
				charge = -1;
				lifetime = LIFETIME_MU;
				break;
			case ParticleType::MuBar:
				name = "MuBar";
				mass = MASS_MU;
				charge = 1;
				lifetime = LIFETIME_MU;
				break;
		}
	}
private:
	std::string name;
	double mass;
	int charge;
	double lifetime;
};


class sim_particle : particle
{

};

class reco_particle : particle
{

};