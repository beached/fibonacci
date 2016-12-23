#include <cassert>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <limits>
#include <string>
#include <boost/multiprecision/cpp_dec_float.hpp>

using real_t = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<10240>>;

real_t operator"" _R( long double d ) {
	return real_t{ d };
}

real_t get_fibonacci( uintmax_t const n ) {
	// Use Binet's formula, limited n to decimal for perf increase
	if( n < 1 ) {
		return 0.0_R;
	}
	static auto const sqrt_five = sqrt( 5.0_R );
	static auto const b_part = 0.5_R + 0.5_R * sqrt_five;
	static auto const c_part = 0.5_R - 0.5_R * sqrt_five;
	
	auto const b = pow( b_part, n );
	auto const c = pow( c_part, n );
	return round( (b - c)/sqrt_five );
}

int main( int argc, char **argv ) { 
	assert( argc == 2 );
	auto n = strtoull( argv[1], 0, 10 );
	std::cout << n << ": " << std::setprecision(std::numeric_limits<real_t>::max_digits10) << get_fibonacci( n ) << '\n';
	return EXIT_SUCCESS;
}

