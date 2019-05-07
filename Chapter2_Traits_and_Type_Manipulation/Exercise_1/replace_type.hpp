#pragma once

#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/conditional.hpp>
#include <boost/type_traits/add_pointer.hpp>
#include <boost/type_traits/add_lvalue_reference.hpp>
#include <boost/type_traits/add_rvalue_reference.hpp>

template < typename _ArgC, typename _ArgA, typename _ArgB >
struct replace_type
{
        typedef boost::conditional_t < 
                boost::is_same < _ArgC, _ArgA > ::value,
                _ArgB, _ArgC
        > type;
}; // Primary Base Template

template < typename _ArgC, typename _ArgA, typename _ArgB >
using replace_type_t = typename replace_type < _ArgC, _ArgA, _ArgB > ::type;

template < typename _ArgC, typename _ArgA, typename _ArgB >
struct replace_type < _ArgC * , _ArgA, _ArgB >
{
        typedef boost::conditional_t <
                boost::is_same < _ArgC * , _ArgA > ::value,
                _ArgB, 
                boost::add_pointer_t < 
                        replace_type_t <
                                _ArgC, _ArgA, _ArgB
                        >
                >
        > type;
}; // Partial Specialization - Pointer

template < typename _ArgC, typename _ArgA, typename _ArgB >
struct replace_type < _ArgC & , _ArgA, _ArgB >
{
        typedef boost::conditional_t <
                boost::is_same < _ArgC & , _ArgA > ::value,
                _ArgB, 
                boost::add_lvalue_reference_t < 
                        replace_type_t <
                                _ArgC, _ArgA, _ArgB
                        >
                >
        > type;
}; // Partial Specialization - LValue Reference

template < typename _ArgC, typename _ArgA, typename _ArgB >
struct replace_type < _ArgC &&, _ArgA, _ArgB >
{
        typedef boost::conditional_t <
                boost::is_same < _ArgC &&, _ArgA > ::value,
                _ArgB, 
                boost::add_rvalue_reference_t < 
                        replace_type_t <
                                _ArgC, _ArgA, _ArgB
                        >
                >
        > type;
}; // Partial Specialization - RValue Reference

template < typename _ArgC, typename _ArgA, typename _ArgB, size_t N >
struct replace_type < _ArgC [N], _ArgA, _ArgB >
{
        typedef boost::conditional_t <
                boost::is_same < _ArgC [N], _ArgA > ::value,
                _ArgB,
                replace_type_t < _ArgC, _ArgA, _ArgB > 
        > type [N];
}; // Partial Specialization - Array

template < typename _ArgC, typename _ArgA, typename _ArgB, typename ..._VArg >
struct replace_type < _ArgC (*)(_VArg...), _ArgA, _ArgB >
{
        typedef boost::conditional_t <
                boost::is_same < _ArgC (*)(_VArg...), _ArgA > ::value,
                _ArgB,
                replace_type_t < _ArgC, _ArgA, _ArgB > 
        > (*type)(replace_type_t < _VArg, _ArgA, _ArgB > ...); 
}; // Partial Specialization - Function Pointer
