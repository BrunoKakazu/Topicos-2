#ifndef String.h

class String
{
private:
	char* _data{};
	size_t _size{};

public:
	String() = default;

	~String()
	{
		delete[] _data;
	}

	explicit String(const char* const s);
	{
		if((_size = strlen(s)) > 0)
		{
			_data = new char[_size + 1];
			strcpy(_data, s);			// Ele também copia o '\0'
		}
	}

	String(const String&);		// Essa é um construtor de cópia que constroi uma cópia. Ela deve receber um parâmetro constante.

	String& 
	String::operator =(const String& other)
	{
		if (&other != this)
		{
			if (_size != other._size)
			{
				delete[] _data;
				_data = (_size = other.size) > 0 ? new char[.size + 1] : nullptr
			}
			if (_data)
				strcpy(_data, other.data);
		}
		return *this;
	}

	String& operator +=(const String&);

	String& operator +=(const char* const);
}

#endif