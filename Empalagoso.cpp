#include<iostream>
#include<string>

class Pastel {
private:
	std::string tipo;
	std::string ingredientes;
	//Motor* motor;

public:
	std::string getTipo() {
		return tipo;
	}
	void setTipo(std::string _tipo) {
		tipo = _tipo;
	}
	void setIngredientes(std::string ingredientes_) {
		ingredientes = ingredientes_;
	}
};

class pasTipo {
private:
	std::string nombre;
	std::string ingredientes;
public:
	void setNombre(std::string _nombre) {
		nombre = _nombre;
	}
	std::string getNombre() {
		return nombre;
	}
	void setIngreientes(std::string _ingredientes) {
		ingredientes = _ingredientes;
	}
	std::string getIngredientes() {
		return ingredientes;
	}
};

class Builder {
protected:
	Pastel* pastel;
public:
	Pastel* getPastel{
		return pastel;
	}
		void createPastel() {
		pastel = new Pastel();
	}
	virtual void buildPastel() = 0;
};

class BuilderTresLeches : public Builder {
	void buildTL() {
		pasTipo* tresleches = new pasTipo();
		tresleches->setNombre("Tres Leches");
		tresleches->setIngreientes("Leche, huevo, mantequilla");
		pastel->setTipo(tresleches->getNombre());
		pastel->setIngredientes(tresleches->getIngredientes());
	}
};

class BuilderSacher : public Builder {
	void buildSac() {
		pasTipo* sacher = new pasTipo();
		sacher->setNombre("Sacher");
		sacher->setIngreientes("Chocolate, frutas, merengue");
		pastel->setTipo(sacher->getNombre());
		pastel->setIngredientes(sacher->getIngredientes());
	}
};

class BuilderImposible : public Builder {
	void buildImp() {
		pasTipo* impo = new pasTipo();
		impo->setNombre("Imposible");
		impo->setIngreientes("Chocolate, frutas, merengue");
		pastel->setTipo(impo->getNombre());
		pastel->setIngredientes(impo->getIngredientes());
	}
};

class Director {
private:
	Builder* builder;
public:
	void setBuilder(Builder* bd) {
		builder = bd;
	}
	Pastel* getPastel() {
		return builder->getPastel();
	}
	void construct() {

	}
};

class Sucursal {
public:
	virtual void create() = 0;
	virtual Sucursal* clone() = 0;
};

template <class T>
class CloneSucursal : public Sucursal {
public:
	virtual Sucursal* clone() {
		return new T(dynamic_cast<T&>(*this));
	}
};

class CDMX : public CloneSucursal <CDMX> {
	void create() {
		std::cout << "Batiendo ingredientes" << std::endl;
		std::cout << "Amasando ingredientes" << std::endl;
		std::cout << "Horneando pastel" << std::endl;
		std::cout << "Decorando Pastel" << std::endl;
		std::cout << "Pastel de tres leches empacado" << std::endl;
		std::cout << "   " << std::endl;
	}
};

class Ags : public CloneSucursal <Ags> {
	void create() {
		std::cout << "Batiendo ingredientes" << std::endl;
		std::cout << "Amasando ingredientes" << std::endl;
		std::cout << "Horneando pastel" << std::endl;
		std::cout << "Decorando Pastel" << std::endl;
		std::cout << "Pastel sacher empacado" << std::endl;
		std::cout << "   " << std::endl;
	}
};

class Creator {
public:
	virtual Sucursal* factoryMethod(std::string) = 0;

	Sucursal* createProduct(std::string type) {
		Sucursal* miSucu = factoryMethod(type);
		miSucu->create();
		return miSucu;
	}
};

class SucuCreator :public Creator {
private:
	SucuCreator(void) {}
	static SucuCreator* instance;


public:
	static SucuCreator *getInstance() {
		if (instance == NULL)
			instance = new SucuCreator();

		return instance;
	}


	Sucursal* factoryMethod(std::string type) {
		if (type == "Tres Leches") {
			return new Ags;
		}
		else if (type == "Sacher") {
			return new CDMX;
		}
		else if (type == "Imposible") {
			return new CDMX;
		}
	}
};
SucuCreator* SucuCreator::instance = 0;

int main() {

	//Creator* cliente = new ComputerCreator();
	//ComputerCreator* cliente = ComputerCreator::getInstance();
	//Computer* miProducto = cliente->createProduct("Tablet");

	CDMX IMP;
	Ags TL;
	Sucursal* pa = IMP.clone();
	pa->create();
	Sucursal* pas = TL.clone();
	pas->create();

	return 0;

}