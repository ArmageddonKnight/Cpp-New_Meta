#define BOOST_TEST_MODULE Exercise_2_1

#include <boost/test/unit_test.hpp>
#include <boost/static_assert.hpp>

#include "replace_type.hpp"

BOOST_AUTO_TEST_CASE(exercise_2_1)
{
        BOOST_STATIC_ASSERT(
                boost::is_same < 
                        replace_type_t < 
                                void *, 
                                void, 
                                int 
                        >,
                        int *
                > ::value);
        BOOST_STATIC_ASSERT(
                boost::is_same <
                        replace_type_t < 
                                int const * [10],
                                int const,
                                long
                        >,
                        long * [10]
                > ::value);
        BOOST_STATIC_ASSERT(
                boost::is_same <
                        replace_type_t <
                                char & (*)(),
                                char &,
                                long &
                        >,
                        long & (*)()
                > ::value);
}
