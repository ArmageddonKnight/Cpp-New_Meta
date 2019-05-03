#define BOOST_TEST_MODULE Exercise_2_0

#include <boost/test/unit_test.hpp>

#include <boost/static_assert.hpp>

#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/add_reference.hpp>
#include <boost/type_traits/conditional.hpp>
#include <boost/type_traits/is_reference.hpp>
#include <boost/type_traits/is_same.hpp>

template < typename _Arg >
struct add_const_ref
{
        typedef boost::conditional_t <
                boost::is_reference < _Arg > ::value,
                _Arg,
                boost::add_reference_t < 
                        boost::add_const_t < _Arg > 
                >
        > type;
};

BOOST_AUTO_TEST_CASE(exercise_2_0)
{
        BOOST_STATIC_ASSERT(
                boost::is_same < 
                        typename add_const_ref < int & > ::type,
                        int & 
                > ::value);
        BOOST_STATIC_ASSERT(
                boost::is_same < 
                        typename add_const_ref < int   > ::type,
                        const int & 
                > ::value);
}
