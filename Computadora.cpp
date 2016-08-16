#include<iostream>
#include<string>

class Desktop {
private:
	std::string name;
public:
	void create(std::string nombre) {
		setName(nombre);
		std::cout << nombre << " creada" << std::endl;
		std::cout << "Seleccion de componentes. Completado" << std::endl;
		std::cout << "Ensamblado de componentes. Completado" << std::endl;
		std::cout << "instalacion y configuracion de Software. Completado" << std::endl;
		std::cout << "Empaquetado del computador. Completado" << std::endl;
	}

	void setName(std::string _nombre) {
		name = _nombre;
	}
	std::string getNamee() {
		return name;
	}
};

class Laptop {
private:
	std::string name;
public:
	void create(std::string nombre) {
		setName(nombre);
		std::cout << nombre << " creada" << std::endl;;
		std::cout << "Seleccion de componentes. Completado" << std::endl;
		std::cout << "Ensamblado de componentes. Completado" << std::endl;
		std::cout << "instalacion y configuracion de Software. Completado" << std::endl;
		std::cout << "Empaquetado del computador. Completado" << std::endl;
	}

	void setName(std::string _nombre) {
		name = _nombre;
	}
	std::string getNamee() {
		return name;
	}
};

class Netbook {
private:
	std::string name;
public:
	void create(std::string nombre) {
		setName(nombre);
		std::cout << nombre << " creada" << std::endl;
		std::cout << "Seleccion de componentes. Completado" << std::endl;
		std::cout << "Ensamblado de componentes. Completado" << std::endl;
		std::cout << "instalacion y configuracion de Software. Completado" << std::endl;
		std::cout << "Empaquetado del computador. Completado" << std::endl;
	}

	void setName(std::string _nombre) {
		name = _nombre;
	}
	std::string getNamee() {
		return name;
	}
};

class Tablet {
private:
	std::string name;
public:
	void create(std::string nombre) {
		setName(nombre);
		std::cout << nombre << " creada" << std::endl;
		std::cout << "Seleccion de componentes. Completado" << std::endl;
		std::cout << "Ensamblado de componentes. Completado" << std::endl;
		std::cout << "instalacion y configuracion de Software. Completado" << std::endl;
		std::cout << "Empaquetado del computador. Completado" << std::endl;
	}

	void setName(std::string _nombre) {
		name = _nombre;
	}
	std::string getNamee() {
		return name;
	}
};

int main() {
	Laptop desk;
	desk.create("Laptop");
	return 0;
}