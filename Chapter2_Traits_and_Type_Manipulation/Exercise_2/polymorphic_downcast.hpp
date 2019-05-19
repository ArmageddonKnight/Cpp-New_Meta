#pragma once

#include <cassert>
#include <boost/type_traits/add_pointer.hpp>
#include <boost/type_traits/remove_reference.hpp>

template < typename Target, 
           typename Source >
inline Target polymorphic_downcast(Source * x)
{
        assert(dynamic_cast < Target > (x) == x);
        return  static_cast < Target > (x);
}

template < typename Target,
           typename Source >
inline Target polymorphic_downcast(Source & x)
{
        assert(dynamic_cast < 
                boost::add_pointer_t <
                        boost::remove_reference_t <
                                Target
                        >
                > > (&x) == (&x));
        return  static_cast < Target > (x);
}
