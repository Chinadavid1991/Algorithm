#include <iostream>
#include "ListTable.h"
using namespace std;
int main() {
    ListTable table(128);
    for(int ix = 0;ix < 1000;ix++){
        table.add(ix,std::to_string(ix));
    }
    cout << table.get(100) << endl;
    return 0;
}
