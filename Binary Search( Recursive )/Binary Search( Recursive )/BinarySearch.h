


#include <vector>
using namespace std;

class BinarySearch
{
public:
    BinarySearch( int );
    int binarySearch( string ) const;
    void autoSearch( int );
    void displayElements() const;
private:
    int size;
    vector< string > data;
    void displaySubElement( int, int ) const;
};
