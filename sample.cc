#include <cassert>
#include <vector>
#include <string>
#include <iostream>

#include "ling.hpp"

struct R {
    std::string name, surname, thirdname;
    int first, second, third;
};

int main()
{
    std::vector<R> x, y;
    x.push_back( {"Test", "Lorem", "Amet", 1,2,3} );
    x.push_back( {"Test", "Ipsum", "Lorem", 1,2,3} );
    x.push_back( {"Dolor", "Dolor", "Ipsum", 1,2,3} );
    x.push_back( {"Test", "Lorem", "Adpiscin", 1,2,3} );

    auto name = ling::param(&R::name);
    auto surname = ling::param(&R::surname);

    assert( ("verify bind implementation", (name == "Test" && surname == "Lorem")(x[0]) ) );

    ling::select().from(x).where(name == surname).into(y);

    for( auto &it : y ) {
        std::cout << it.name << " " << it.surname << " " << it.thirdname << std::endl;
    }

    std::cout << ling::select().from(x).where(surname == "Lorem").count(1) << std::endl;
}
