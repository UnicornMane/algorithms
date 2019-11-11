#include <iostream>
#include <string>
void simpleCountingSort(std::string A, size_t N)

{

	size_t frequency[256];

	for (size_t i = 0; i < N; i++) {

		frequency[A[i]]++;

	}

	size_t position = 0;

	for (unsigned char number = 0; number <= 255; number++) {

		for (size_t i = 0; i < frequency[number]; i++) {

			A[position] = number;

			position++;

		}

	}

}
int main()
{

}
//питон:
/*
def SimpleCountingSort(A):
	scope = max(A) + 1
	C = [0] * scope
	for x in A:
		C[x] += 1
	A[:] = []
	for number in range(scope):
		A += [number] * C[number]
*/