#include <iostream>
#include <vector>

bool IsPrimeNumber( unsigned int number )
{
    auto isPrime = true;

    if ( number == 0 || number == 1 )
        isPrime = false;

    for ( auto i = 2u; i < number; i++ )
        if ( number % i == 0 )
            isPrime = false;

    return isPrime;
}

int main()
{
    std::vector< unsigned int > input;

    for ( auto i = 0; i <= 100; i++ )
        input.push_back( i );

    for ( auto it = input.begin(); it != input.end(); it++)
    {
        if ( IsPrimeNumber( *it ) )
            std::cout << *it << std::endl;
    }
}
