#include<iostream>
#include<string>

class Computer {
public:
	virtual void create() = 0;
	virtual Computer* clone() = 0;
};

template <class T>
class CloneComputer : public Computer {
public:
	virtual Computer* clone() {
		return new T(dynamic_cast<T&>(*this));
	}
};

class Desktop : public CloneComputer <Desktop> {
	void create() {
		std::cout << "Seleccion de componentes. Componentes para Desktop seleccionados" << std::endl;
		std::cout << "Ensamblado de componentes. Componentes para Desktop ensamblados" << std::endl;
		std::cout << "Instalacion y configuracion de Software. Software para Desktop istalado y configurado" << std::endl;
		std::cout << "Empaquetado del computador. Desktop empaquetado" << std::endl;
		std::cout << "Desktop Creada" << std::endl;
		std::cout << "   " << std::endl;
	}
};

class Laptop : public CloneComputer <Laptop> {
	void create() {
		std::cout << "Seleccion de componentes. Componentes para Laptop seleccionados" << std::endl;
		std::cout << "Ensamblado de componentes. Componentes para Laptop ensamblados" << std::endl;
		std::cout << "Instalacion y configuracion de Software. Software para Laptop istalado y configurado" << std::endl;
		std::cout << "Empaquetado del computador. Laptop empaquetado" << std::endl;
		std::cout << "Laptop Creada" << std::endl;
		std::cout << "   " << std::endl;
	}
};

class Netbook : public CloneComputer <Netbook> {
	void create() {
		std::cout << "Seleccion de componentes. Componentes para Netbook seleccionados" << std::endl;
		std::cout << "Ensamblado de componentes. Componentes para Netbook ensamblados" << std::endl;
		std::cout << "Instalacion y configuracion de Software. Software para Netbook istalado y configurado" << std::endl;
		std::cout << "Empaquetado del computador. Netbook empaquetado" << std::endl;
		std::cout << "Netbook Creada" << std::endl;
		std::cout << "   " << std::endl;
	}
};

class Tablet : public CloneComputer <Tablet> {
	void create() {
		std::cout << "Seleccion de componentes. Componentes para Tablet seleccionados" << std::endl;
		std::cout << "Ensamblado de componentes. Componentes para Tablet ensamblados" << std::endl;
		std::cout << "Instalacion y configuracion de Software. Software para Tablet istalado y configurado" << std::endl;
		std::cout << "Empaquetado del computador. Tablet empaquetado" << std::endl;
		std::cout << "Tablet Creada" << std::endl;
		std::cout << "   " << std::endl;
	}
};

class Creator {
public:
	virtual Computer* factoryMethod(std::string) = 0;

	Computer* createProduct(std::string type) {
		Computer* myComputer = factoryMethod(type);
		myComputer->create();
		return myComputer;
	}
};

class ComputerCreator :public Creator {
private:
	ComputerCreator(void) {}
	static ComputerCreator* instance;
		

public:	
	static ComputerCreator *getInstance() {
		if (instance == NULL)
			instance = new ComputerCreator();

		return instance;
		}


	Computer* factoryMethod(std::string type) {
		if (type == "Laptop") {
			return new Laptop;
		}
		else if (type == "Desktop") {
			return new Desktop;
		}
		else if (type == "Netbook") {
			return new Netbook;
		}
		else if (type == "Tablet") {
			return new Tablet;
		}
	}
};
ComputerCreator* ComputerCreator::instance = 0;

int main() {

	//Creator* cliente = new ComputerCreator();
	//ComputerCreator* cliente = ComputerCreator::getInstance();
	//Computer* miProducto = cliente->createProduct("Tablet");

	Desktop De;
	Laptop La;
	Computer* co = De.clone();
	co->create();
	Computer* com = La.clone();
	com->create();

	return 0;

}