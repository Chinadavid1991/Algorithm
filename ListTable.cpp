//
// Created by feng on 2020/12/17.
//

#include "ListTable.h"
using namespace std;
void testListTable(){
    ListTable table(1024);
    for(int ix = 0;ix < 100000;ix++){
        table.add(ix,std::to_string(ix));
    }
    cout << table.get(100) << endl;
}