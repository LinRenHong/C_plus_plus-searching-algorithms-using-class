

#ifndef LISTNODE_H
#define LISTNODE_H



template< typename NODETYPE > class List;
class HashRelation;

template< typename NODETYPE >
class ListNode
{
    friend class List< NODETYPE >;
    friend class HashRelation;

public:
    ListNode( const NODETYPE & );
    NODETYPE getData() const;
private:
    NODETYPE data;
    ListNode< NODETYPE > *nextPtr;
};


template< typename NODETYPE >
ListNode< NODETYPE >::ListNode( const NODETYPE &info )
    :data( info ), nextPtr( 0 )
{

}


template< typename NODETYPE >
NODETYPE ListNode< NODETYPE >::getData() const
{
    return data;
}

#endif
