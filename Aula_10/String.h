#ifndef String.h

class String
{
private:
	static constexpr size_t MAX_BUFFER = 16;

	char* _data{};
	size_t _size{};

	union		// Ela é como uma classe, porém o tamanho do objeto não é a soma do tamanho dos atributos e sim daquele que é maior.
	{
		size_t _capacity;
		char _buffer[MAX_BUFFER];
	};

	auto isShort() const
	{
		return _size < MAX_BUFFER;
	}

public:
	String() :
		_size{};
		_data{_buffer}
		{

		}

	~String()
	{
		if(!isShort())
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

	String::String(const char* const s)
	{
		if((_size = strlen(s)) > 0)
		{
			if(isShort())
				_data = _buffer;
			else
			{
				_capacity = (_size/MAX_BUFFER + 1) * MAX_BUFFER;
				_data = new char[_capacity + 1];
			}
			strcpy(_data, s);
		}
	}

	String& 
	String::operator =(const String& other)
	{
		if (&other != this)
		{
			if (_size != other._size)
			{
				delete[] _data;
				_data = (_size = other.size) > 0 ? new char[_size + 1] : nullptr
			}
			if (_data)
				strcpy(_data, other.data);
		}
		return *this;
	}

	String& operator +=(const String&);

	String& operator +=(const char* const);

	auto capacity() const
	{
		return isShort() ? MAX_BUFFER -1 : _capacity;
	}
}

#endif