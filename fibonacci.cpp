#include <cassert>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <limits>
#include <string>
#include <boost/multiprecision/cpp_dec_float.hpp>

using real_t = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<10000>>;

real_t operator"" _R( long double d ) {
	return real_t{ d };
}

real_t get_fibonacci( uintmax_t const n ) {
	// Use Binet's formula, limited n to decimal for perf increase
	if( n < 1 ) {
		return 0.0_R;
	}
	static real_t const sqrt_five = sqrt( 5.0_R );
	static real_t const a_part = (1.0_R + sqrt_five) / 2.0_R;
	static real_t const b_part = (1.0_R - sqrt_five) / 2.0_R;
	
	real_t const a = pow( a_part, n );
	real_t const b = pow( b_part, n );
	return round( (a - b)/sqrt_five );
}

int main( int argc, char **argv ) { 
//	assert( argc == 2 );
//
//	auto n = strtoull( argv[1], 0, 10 );
	uint64_t n = 1234567;
	std::cout << n << ": " << std::setprecision(std::numeric_limits<real_t>::max_digits10) << get_fibonacci( n ) << '\n';
	return EXIT_SUCCESS;
}

