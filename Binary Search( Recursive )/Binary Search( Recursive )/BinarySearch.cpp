

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "BinarySearch.h"
using namespace std;


BinarySearch::BinarySearch( int vectorSize )
{
    size = ( vectorSize > 0 ? vectorSize : 10 );
    srand( time( 0 ) );
    
    
    //data = new string[ size ];
    data = vector< string >(size);
    
    for( int i = 0; i < size; i++ )
    {
        data[ i ] = "";
        for( int j = 0; j < 6; j++ )
        {
            if( rand() % 2 == 0 )
                data[ i ] += (char)( rand() % 26 + 'a' );
            else
                data[ i ] += (char)( rand() % 26 + 'A' );
        }
    }


    sort( data.begin(), data.end() );
}


int BinarySearch::binarySearch( string searchElement ) const
{
    int low = 0;
    int high = size - 1;
    int middle = ( low + high + 1 ) / 2;
    int location = -1;

    do
    {

//        displaySubElement( low, high );
//
//        for( int i = 0; i < middle; i++ )
//            cout << "   ";
//
//        cout << " * " << endl;

        if( searchElement == data[ middle ] )
            location = middle;
        else if ( searchElement < data[ middle ] )
            high = middle - 1;
        else
            low = middle + 1;

        middle = ( low + high + 1 ) / 2;
    } while( ( low <= high ) && ( location == -1 ) );

    return location;
}


void BinarySearch::autoSearch( int count )
{
    int randomIndex;
    cout << "Have " << size << " elements!" << endl;
    for( int i = 0; i < count; i++  )
    {
        randomIndex = rand() % size;
        binarySearch( data[ randomIndex ] );
        //        if ( search( data[ randomIndex ] ) != -1 )
        //            cout << "Yes " << data[ randomIndex ] << endl;
    }
    cout << "Done" << endl;
}


void BinarySearch::displayElements() const
{
    displaySubElement( 0, size - 1 );
}


void BinarySearch::displaySubElement( int low, int high ) const
{
    for( int i = 0; i < low; i++ )
        cout << "   ";
    for( int i = low; i <= high; i++ )
        cout << data[ i ] << " ";


    cout << endl;
}
