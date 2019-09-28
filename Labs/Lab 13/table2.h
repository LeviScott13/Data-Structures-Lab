// FILE: table2.h
// TEMPLATE CLASS PROVIDED: Table<RecordType>
//   This class is a container template class for a Table of records.
//   The template parameter, RecordType, is the data type of the records in the
//   Table. It may any type with a default constructor, a copy constructor,
//   an assignment operator, and an integer member variable called key.
//
// CONSTRUCTOR for the Table<RecordType> template class:
//   Table( )
//     Postcondition: The Table has been initialized as an empty Table.
//
// MODIFICATION MEMBER FUNCTIONS for the Table<RecordType> class:
//   void insert(const RecordType& entry)
//     Precondition: entry.key >= 0
//     Postcondition: If the table already had a record with a key equal to
//     entry.key, then that record is replaced by entry. Otherwise, entry has
//     been added as a new record of the Table.
//
//   void remove(int key)
//     Postcondition: If a record was in the Table with the specified key, then
//     that record has been removed; otherwise the table is unchanged.
//
// CONSTANT MEMBER FUNCTIONS for the Table<RecordType> class:
//   bool is_present(const Item& target) const
//     Postcondition: The return value is true if there is a record in the
//     Table with the specified key. Otherwise, the return value is false.
//
//   void find_location(int key, bool& found,
//     typename std::list<RecordType>::iterator& location) const
//     Postcondition: If a record is in the Table with the specified key, then
//     found is true and location is set to an iterator access the record.
//     Otherwise found is false and the result contains garbage.
//
//   size_t size( ) const
//     Postcondition: Return the total number of records in the
//     Table.
//

#ifndef TABLE2_H
#define TABLE2_H
#include <cstdlib>    // Provides size_t
#include <list>
#include <iostream>

namespace main_savitch_12B
{
  template <typename RecordType>
    class table
  {
  public:
    // MEMBER CONSTANT
    static const std::size_t NUM_BUCKETS = 10;
    // CONSTRUCTORS AND DESTRUCTOR
    table( );
    // MODIFICATION MEMBER FUNCTIONS
    void insert(const RecordType& entry);
    void remove(int key);
    // CONSTANT MEMBER FUNCTIONS
    bool is_present(int key) const;
    RecordType get_record (int key) const;
    std::size_t size( ) const;
    template <typename U>
    friend std::ostream& operator << (std::ostream& output,
				      const table<U>& t);
  private:
    std::list<RecordType> data[NUM_BUCKETS];
    // HELPER MEMBER FUNCTION
    std::size_t hash(int key) const;
    void find_location(int key, bool& found,
		       typename std::list<RecordType>::iterator&
		       location);
    
  };

}

#include "table2.template" // Include the implementation

#endif
