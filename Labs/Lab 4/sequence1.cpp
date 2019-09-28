#include "sequence1.h"
#include <cassert>
#include <iostream>
using namespace std;

namespace main_savitch_3{

const sequence::size_type sequence:: CAPACITY;

typedef double value_type;
typedef std::size_t size_type;
static const size_type CAPACITY = 30;
        
sequence::sequence(){

    current_index = 0;
    used = 0;
}

void sequence::start(){
    current_index= 0;
}
`
void sequence::advance(){
    if (is_item()== true)
    {
        current_index++;
    }
}
void sequence::insert(const value_type& entry){
    int i;
    assert (size()< CAPACITY);
    if (is_item() == false){
        current_index=0;
    }
    for (i= used; i>current_index; i--){
        data[i] = data [i-1];
    }
    data[current_index]= entry;
    used++;
}
void sequence::attach(const value_type& entry){
    int i;
    assert (size()< CAPACITY);

    if (is_item() == false){
        data[used-1]= entry;
    }
    for (i= used; i> current_index; i++){
        data[i]= data[i+1];
    }
    data[current_index]= entry;
    used++;
}
void sequence::remove_current(){
    int i;
    assert(is_item()== true);
    
    for (i= current_index + 1; i< used - 1; i++){
        data [i]= data[i+1];
        used--;
    }
}
sequence::size_type sequence::size() const{
    return used;
}
bool sequence::is_item() const {

    if(current_index < used){
        return true;
    }
}
sequence::value_type sequence::current() const{
    return data[current_index];
}
}