#define BOOST_TEST_MODULE Exercise_2_1

#include <boost/test/unit_test.hpp>

#include <boost/static_assert.hpp>

#include <boost/type_traits/is_compound.hpp>

template < typename _ArgC, 
           typename _ArgA, 
           typename _ArgB >
struct replace_type
{
        BOOST_STATIC_ASSERT(boost::is_compound < _ArgC > ::value);
};

BOOST_AUTO_TEST_CASE(exercise_2_1)
{
        
}