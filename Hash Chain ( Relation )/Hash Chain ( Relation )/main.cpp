//
//  main.cpp
//  Hash Chain ( Relation )
//
//  Created by 林仁鴻 on 2018/5/6.
//  Copyright © 2018年 林仁鴻. All rights reserved.
//

#include <iostream>
#include <ctime>
#include "HashRelation.h"

using namespace std;

int main(int argc, const char * argv[]) {
    HashRelation h( 5000 );
    string searchInt;
    int position;
    
//    clock_t start, end;
//    double cpu_time_used;
//
//    for( int i = 50000; i <= 600000; i += 50000 )
//    {
//        HashRelation h(i);
//        start = clock();
//        h.autoSearch(100000);
//        end = clock();
//        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
//
//        cout << "Time = " << cpu_time_used << endl;
//    }
    
    
    h.print();

    cout << "\nPlease enter an word (-1 to quit): ";
    cin >> searchInt;
    cout << endl;

    while( searchInt != "-1" )
    {

        position = h.search( searchInt );

        if( position == -1 )
            cout << "The word " << searchInt << " was not found.\n";
        else
            cout << "The word " << searchInt
            << " was found in position " << position << ".\n";

        cout << "\n\nPlease enter an word (-1 to quit): ";
        cin >> searchInt;
        cout << endl;
    }
    
    
}
