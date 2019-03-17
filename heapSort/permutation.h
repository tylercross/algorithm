#ifndef PERMUTATION_H_INCLUDED
#define PERMUTATION_H_INCLUDED



#include <ctime>
#include <cstdlib>


int *Permutation3(int N) {

    int *a = new int[N];
    int  a_i;

    for (a_i = 0; a_i < N; ++a_i)
        a[a_i] = a_i + 1;

    for (a_i = 0; a_i < N; ++a_i) {
        std::swap(a[a_i], a[std::rand() % (a_i + 1)]);
    }

    return a;
}




#endif // PERMUTATION_H_INCLUDED
