#include <cstudio>
#include <cstring>

/*int
sum(cont int* s, int a)
{
	int s{};

	for (int i = 0; i < n; ++i)
		s += a[i];
	return s;
}

float
sum(const float* a, int n)
{
	float s{};

	for (int i = 0; i < n; ++i)
		s += a[i];
	return s;
}*/


template <typename T>
auto // ou T
sum (const T* a, int n) // -> T // isso indica que no final desta função você está definindo o seu tipo como T
{
	T s{};	// Nesta parte está contruindo um objeto no formato default

	for (int i = 0; i < n; ++i)
		s += a[i];
	return s;
}

template <typename T, typename iterador>
auto
sum(iterador it, iterador end)
{
	decltype(*it) s{};
	
	while(it != end)
		s+= *it++;
	return s;
}

template <typename T>
inline auto
equals(T a, T b)
{
	return a == b;
}

template <typename T>
auto
contains(const T* a, int n, const T value)
{
	for (int i = 0; i < n; ++i)
		if (equals(a[i], value))
			return true;
	return false;
}

/*template <>		// Especialização de um template
inline auto
equals<const char*>(const char* a, const char* b)
{
	return !strcmp(a, b);
}*/

inline auto		// Neste caso, essa função é aceitada
equals(const char* a, const char* b)
{
	return !strcmp(a, b);
}

template <typename T>	// Template a ser melhorado
inline void
swap(T& a, T& b)
{
	auto temp = a;

	a = b;
	b = temp;
}

template <int N>
inline int
fat()
{
	return N * fat<N - 1>();
}

inline constexpr int
cfat(int n)
{
	return n == 0 ? 1 : n * cfat(n - 1);
}

template <>
inline int
fat<0>()
{
	return 1;
}


void
f()
{
	int ia[10] = {fat<3>(), fat<4>(), fat<1>()};
	float fa[10];
	auto is = sum<int>(ia, ia + 3);
	auto fs = sum<float>(fa, fa + 1);
	auto ir = sum<int>(ia, ia + 3);
	auto ok = contains(ia, 10, 3);

	const char* sa[]("FACOM", "TCII", "C++")

	if(contains(sa, 3, "FACOM"))
		puts("FOUND")
}
