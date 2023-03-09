#ifndef __IntArray_h
#define __IntArray_h
#include <cassert>

class IntArray					// Formato de declaração de classe.
{
private:
	int _capacity;
	int _size;
	int* _data;
	void resize();
	int* Find(int value) const;

public:
	IntArray()					// Declaração de um método construtor. Ele precisa inicializar os atributos da classe
	{
		_capacity = _size = 0;
		_data = nullptr;		// nullptr é uma palavra reservada para nulo de ponteiro
	}
	IntArray(int capacity)
	{
		assert(capacity > 0);	// assert está visivel em modo depuração
		_capacity = capacity;
		_size = 0;
		_data = new int[capacity];	// new chama o malloc. Esse int se torna um ponteiro devido o new
	};
	~IntArray()					// É chamado para destruir algo da classe. A sua definição da chamada de um destrutor é um ~ sem argumentos
	{
		delete []_data;			// É necessário desalocar o espaço da memória que ele ocupou
	}

	void Add(int value)
	{
		_data[_size++] = value;	// É sinônimo de this->_data[this->_size++] = value;

		if(_size == _capacity)
			resize();
	}

	auto Contains(int value) const
	{
		return Find(value != nullptr);
	}

	bool Remove(int value);

	auto Size() const
	{
		return _size;
	}

	void Clear()
	{
		delete []_data;
		_data = nullptr;
		_size = _capacity = 0;
	}

};//a, b;						// Se colocado a e b indica que são IntArray

#endif
