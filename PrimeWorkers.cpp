#include <algorithm>
#include <future>
#include <list>
#include <iostream>
#include <vector>

using InputType = std::vector< unsigned int >;
using OutputType = std::list< unsigned int >;

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

OutputType FindPrimes( const InputType& numbers )
{
    OutputType primeList;

    for ( auto it = numbers.begin(); it != numbers.end(); it++ )
        if ( IsPrimeNumber( *it ) )
            primeList.push_back( *it );

    primeList.sort();

    return primeList;
}

OutputType GetAllPrimesInVector( const InputType& input )
{
    auto halfSize = input.size() / 2;
    InputType firstHalf( input.begin(), input.begin() + halfSize );
    InputType secondHalf( input.begin() + halfSize, input.end() );

    std::future< OutputType > futureOne = std::async( FindPrimes, firstHalf );
    std::future< OutputType > futureTwo = std::async( FindPrimes, secondHalf );

    auto output = futureOne.get();
    output.merge( futureTwo.get() );

    return output;
}

int main()
{
    InputType input;

    for ( auto i = 100; i >= 0; i-- )
        input.push_back( i );

    auto output = GetAllPrimesInVector( input );

    std::cout << "Output size is " << output.size() << std::endl;

    for ( auto it = output.begin(); it != output.end(); it++ )
        std::cout << *it << std::endl;
}
