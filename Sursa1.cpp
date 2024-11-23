#include<iostream>
#include<string>

using namespace std;

class Masina {
private: 
	const int id;
	static int nrMasini;
	string marca;
	int nrComponente;
	float* preturi;
public: 
	Masina() :id(++nrMasini) {
		this->marca = "Necunoscuta";
		this->nrComponente = 0;
		this->preturi = nullptr;
	}

	Masina(string _marca, int nrComponente, const float* preturi) :id(++nrMasini) {
		marca = _marca;
		this->nrComponente = nrComponente;
		this->preturi = new float[nrComponente];
		for (int i = 0; i < nrComponente; i++) {
			this->preturi[i] = preturi[i];
		}
	}

	int getNrComponente() {
		return this->nrComponente;
	}

	void setNrComponente(int nrComponente) {
		if (nrComponente > 0) {
			this->nrComponente = nrComponente;
		}
		else {
			throw new exception();
		}
	}

	float* getPreturi() const {
		float* vectorPreturi = new float[this->nrComponente];
		for (int i = 0; i < this->nrComponente; i++) {
			vectorPreturi[i] = this->preturi[i];
		}
		return vectorPreturi;
	}

	void setPreturi(float* noulVectorPreturi, int nouaDimensiune) {
		setNrComponente(nouaDimensiune);
		if (this->preturi != nullptr) {
			delete[] this->preturi;
		}
		this->preturi = new float[nouaDimensiune];
		for (int i = 0; i < nouaDimensiune; i++) {
			this->preturi[i] = noulVectorPreturi[i];
		}
		delete[] noulVectorPreturi;
	}

	~Masina() {
		if (this->preturi != nullptr) {
			delete[] this->preturi;
		}
	}

	virtual void afisare() {
		cout << "Masina cu marca " << this->marca << " este cu ardere interna." << endl;
	}

	void afisareMasina() {
		cout << this->id << ". Masina cu marca " << this->marca;
		if (this->nrComponente > 0) {
			cout << " are " << this->nrComponente << " componente cu urmatoarele preturi:";
			if (this->preturi != nullptr) {
				for (int i = 0; i < this->nrComponente; i++) {
					cout << " " << this->preturi[i];
				}
			}
		}
		cout << endl;
	}

};

int main() {
	float* param = new float[2] {45, 67};
	Masina m1("Audi", 2, param);//nu este recomandata initializarea inline
	
	m1.afisare();
}