//
//  main.cpp
//  Binary Search( Recursive )
//
//  Created by 林仁鴻 on 2018/5/6.
//  Copyright © 2018年 林仁鴻. All rights reserved.
//

#include <iostream>
#include "BinarySearch.h"
using namespace std;

int main()
{
    //    string searchInt;
    //    int position;
    
    string searchString;
    clock_t start, end;
    double cpu_time_used;
    
    for( int i = 50000; i <= 600000; i += 50000 )
    {
        BinarySearch searchVector( i );
        start = clock();
        searchVector.autoSearch(1000000);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        
        cout << "Time = " << cpu_time_used << endl;
    }
    
    //    BinarySearch searchVector ( 25 );
    //    searchVector.displayElements();
    //
    //    cout << "\nPlease enter an integer value (-1 to quit): ";
    //    cin >> searchInt;
    //    cout << endl;
    //
    //    while( searchInt != "-1" )
    //    {
    //
    //        position = searchVector.binarySearch( searchInt );
    //
    //        if( position == -1 )
    //            cout << "The integer " << searchInt << " was not found.\n";
    //        else
    //            cout << "The integer " << searchInt
    //            << "was found in position " << position << ".\n";
    //
    //        cout << "\n\nPlease enter an integer value (-1 to quit): ";
    //        cin >> searchInt;
    //        cout << endl;
    //    }

}
