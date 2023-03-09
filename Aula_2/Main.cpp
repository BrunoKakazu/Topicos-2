#include "IntArray.h"

int main()
{
	IntArray a;			//Classe não ocupa espaço, porém o objeto ocupa. Logo ele irá alocar memória na main. Como não está sendo passado nada, então está sendo criado uma classe do tipo default, logo não há nada nela.

	for(int i=1; i<10;++i)
		a.add(i);

	return 0;
}
