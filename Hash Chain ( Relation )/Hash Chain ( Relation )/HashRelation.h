//
//  HashRelation.h
//  Hash Chain ( Relation )
//
//  Created by 林仁鴻 on 2018/5/6.
//  Copyright © 2018年 林仁鴻. All rights reserved.
//

#ifndef HashRelation_h
#define HashRelation_h

#include "List.h"

using namespace std;

class HashRelation
{
    const static int hashSize = 100;
public:
    HashRelation( int = 10 );
    void insert( string );
    int search( string );
    void autoSearch( int );
    void print();
    
private:
    List< string > *elements;
    string *data;
    int dataSize;
    
};



HashRelation::HashRelation( int size )
:dataSize( size )
{
    elements = new List< string >[ hashSize ];
    data = new string[ dataSize ];
    
    for( int i = 0; i < dataSize; i++ )
    {
        data[ i ] = "";
        for( int j = 0; j < 6; j++ )
        {
            if( rand() % 2 == 0 )
                data[ i ] += (char)( rand() % 26 + 'a' );
            else
                data[ i ] += (char)( rand() % 26 + 'A' );
        }
        this->insert( data[ i ] );
    }
}


void HashRelation::insert( string value )
{
    int hashNumber = 0;
    for( int i = 0; i < value.size(); i++ )
        hashNumber += (int)value[ i ];
    hashNumber %= hashSize;
    elements[ hashNumber ].insertAtBack(value);
    
}


int HashRelation::search( string value )
{
    int hashNumber = 0;
    for( int i = 0; i < value.size(); i++ )
        hashNumber += (int)value[ i ];
    hashNumber %= hashSize;
    
    
    ListNode< string > *currentPtr = elements[ hashNumber ].firstPtr;
    bool isExist = false;
    
    
    while( currentPtr != 0 && isExist == false )
    {
        if( currentPtr->data == value )
            isExist = true;
        
        currentPtr = currentPtr->nextPtr;
    }
    
    if( isExist )
        return hashNumber;
    else
        return -1;
    
}


void HashRelation::autoSearch( int count )
{
    int randomIndex;
    cout << "Have " << dataSize << " elements!" << endl;
    for( int i = 0; i < count; i++  )
    {
        randomIndex = rand() % dataSize;
        search( data[ randomIndex ] );
//        if ( search( data[ randomIndex ] ) != -1 )
//            cout << "Yes " << data[ randomIndex ] << endl;
    }
    cout << "Done" << endl;
}


void HashRelation::print()
{
    for( int i = 0; i < hashSize; i++ )
    {
        cout << i << endl;
        elements[ i ].print();
    }
}


#endif /* HashRelation_h */
