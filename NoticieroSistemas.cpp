#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Subject {
	vector < class Observer * > views;
	int value;
public:
	void attach(Observer *obser) {
		views.push_back(obser);
	}
	void setVal(int val) {
		value = val;
		notify();
	}
	int getVal() {
		return value;
	}
	void notify();
};

class Observer {
	Subject *sujeto;
	string mensaje;
	string persona;
public:
	Observer(Subject *suj, string per, string men) {
		sujeto = suj;
		persona = per;
		mensaje = men;
		sujeto->attach(this);
	}
	virtual void update() = 0;
protected:
	Subject *getSubject() {
		return sujeto;
	}
	string getPersona() {
		return persona;
	}
	string getMensaje() {
		return mensaje;
	}
};

void Subject::notify() {
	for (int i = 0; i < views.size(); i++)
		views[i]->update();
}

class ConcreteObserverMVS : public Observer {
public:
	ConcreteObserverMVS(Subject *suj, string persona, string mensaje) : Observer(suj, persona, mensaje) {}
	void update() {
		string v = getMensaje();
		string p = getPersona();
		cout << "Noticias MVS informa. " << p << " acaba de publicar lo siguiente: '" << v << "'" << endl;
		cout << endl;
	}
};

class ConcreteObserverTelevisa : public Observer {
public:
	ConcreteObserverTelevisa(Subject *suj, string persona, string mensaje) : Observer(suj, persona, mensaje) {}
	void update() {
		string v = getMensaje();
		string p = getPersona();
		cout << "Noticieros Televisa. " << p <<  " publico: '" << v << "'" << endl;
		cout << endl;
	}
};

class ConcreteObserverAzteca : public Observer {
public:
	ConcreteObserverAzteca(Subject *suj, string persona, string mensaje) : Observer(suj, persona, mensaje) {}
	void update() {
		string v = getMensaje();
		string p = getPersona();
		cout << "Azteca Noticias. " << p << " publico lo siguiente en su cuenta oficial: '" << v <<  "'" << endl;
		cout << endl;
	}
};

class ConcreteObserverRadioF : public Observer {
public:
	ConcreteObserverRadioF(Subject *suj, string persona, string mensaje) : Observer(suj, persona, mensaje) {}
	void update() {
		string v = getMensaje();
		string p = getPersona();
		cout << "Radio Formula informa. " << p << " hizo la siguiente publicacion '" << v << "'" << endl;
		cout << endl;
	}
};

class ConcreteObserverCNN : public Observer {
public:
	ConcreteObserverCNN(Subject *suj, string persona, string mensaje) : Observer(suj, persona, mensaje) {}
	void update() {
		string v = getMensaje();
		string p = getPersona();
		cout << "CNN. " << p << " acaba de publicar lo siguiente: '" << v << "'" << endl;
		cout << endl;
	}
};

/*class PNie {
	string nombre;
	string mensajes;
public:
	void Pers(string nom, string men) {
		nombre = nom;
		mensajes = men;
		Subject PNieto;
		ConcreteObserverMVS observador1(&PNieto, nombre, mensajes);
		ConcreteObserverTelevisa observador2(&PNieto, nombre, mensajes);
		ConcreteObserverAzteca observador3(&PNieto, nombre, mensajes);
		ConcreteObserverRadioF observador4(&PNieto, nombre, mensajes);
		PNieto.setVal(14);
	}
};*/

int main() {
	
	string persona;
	Subject PNieto;
	Subject HClin;
	Subject Trump;
	while (persona != "salir") {

		cout << "Quien eres?  Debe escribir: Nieto, Hilary o Trump.  Para salir escribir 'salir'" << endl;
			cin >> persona;
			cout << endl;

			if (persona == "Nieto") {
				string publicacion;
				string name = "EPN";
				cout << "Que desea publicar Lord P. Nieto?" << endl;
				cin >> publicacion;
				cout << endl;
				ConcreteObserverMVS observador1(&PNieto, name, publicacion);
				ConcreteObserverTelevisa observador2(&PNieto, name, publicacion);
				ConcreteObserverAzteca observador3(&PNieto, name, publicacion);
				ConcreteObserverRadioF observador4(&PNieto, name, publicacion);
				PNieto.setVal(14);
				//PNie(name, publicacion);
			}
			else if (persona == "Hilary") {
				string publicacion;
				string name = "Hilary Clinton";
				cout << "Que desea publicar seniora Clinton?" << endl;
				cin >> publicacion;
				cout << endl;
				ConcreteObserverMVS observador1(&HClin, name, publicacion);
				ConcreteObserverTelevisa observador2(&HClin, name, publicacion);
				ConcreteObserverAzteca observador3(&HClin, name, publicacion);
				ConcreteObserverRadioF observador(&HClin, name, publicacion);
				ConcreteObserverCNN observador5(&HClin, name, publicacion);
				HClin.setVal(14);
			}
			else if (persona == "Trump") {
				string publicacion;
				string name = "Trump";
				cout << "Que desea publicar su peluquin senior Trump?" << endl;
				cin >> publicacion;
				cout << endl;
				ConcreteObserverMVS observador1(&Trump, name, publicacion);
				ConcreteObserverTelevisa observador2(&Trump, name, publicacion);
				ConcreteObserverAzteca observador3(&Trump, name, publicacion);
				ConcreteObserverRadioF observador(&Trump, name, publicacion);
				ConcreteObserverCNN observador5(&Trump, name, publicacion);
				Trump.setVal(14);
			}
	}

}