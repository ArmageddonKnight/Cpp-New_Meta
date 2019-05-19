#define BOOST_TEST_MODULE Exercise_2_1

#include <boost/test/unit_test.hpp>

#include "polymorphic_downcast.hpp"

BOOST_AUTO_TEST_CASE(exercise_2_2)
{
        struct A
        {
                virtual ~A() noexcept {}
        };
        struct B : A {};
        B b;
        A * a_ptr = &b;
        polymorphic_downcast < B * > (a_ptr);
        A & a_ref =  b;
        polymorphic_downcast < B & > (a_ref);
}
