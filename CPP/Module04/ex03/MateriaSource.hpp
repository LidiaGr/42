//
// Created by Temple Tarsha on 12/18/20.
//

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

private:
	AMateria *_materials[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource & src);
	~MateriaSource();

	MateriaSource & operator=(const MateriaSource & rhs);

	void learnMateria(AMateria *);
	AMateria *createMateria(std::string const &type);
};


#endif
