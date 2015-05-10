ling
====

### Features
- LINQ tests in C++11. Based on code by Stanisław Adaszewski
- Tiny. 30 LOC. Header-only.
- Cross platform.
- zlib/libpng licensed

### Todo
- Add missing (all) queries
- Remove dependences

### Sample
```c++
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

    std::cout << ling::select().from(x).where(surname == "Lorem").count(1) << std::endl;

    ling::select().from(x).where(name == surname).into(y);
    for( auto &it : y ) {
        std::cout << it.name << " " << it.surname << " " << it.thirdname << std::endl;
    }
}
```
