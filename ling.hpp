// LINQ tests in C++11. Based on code by Stanisław Adaszewski
// r-lyeh, zlib/libpng licensed

#pragma once
#include <boost/bind.hpp>

namespace ling
{
    template<class SrcContainer, class Expr> struct select_from_where {
        const SrcContainer &m_C;
        const Expr &m_Expr;

        template<class DstContainer> void into(DstContainer &d) {
            for( const auto &it : m_C ) {
                if( m_Expr(it) ) d.push_back(it);
            }
        }

        template<class Integer> Integer count(Integer) {
            Integer res(0);
            for( const auto &it : m_C ) {
                res += m_Expr(it);
            }
            return res;
        }
    };

    template<class SrcContainer> struct select_from {
        const SrcContainer &m_C;
        template<class Expr> select_from_where<SrcContainer, Expr> where(const Expr &e) {
            return select_from_where<SrcContainer, Expr>{m_C, e};
        }
    };

    struct select {
        template<class SrcContainer> select_from<SrcContainer> from(const SrcContainer &c) {
            return select_from<SrcContainer>{c};
        }
    };

    template<typename T>
    static inline auto param( T &&t ) -> decltype(boost::bind(t,_1)) {
        return boost::bind(t,_1);
    }
}
