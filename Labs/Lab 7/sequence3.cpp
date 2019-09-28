//Levi Sutton 

#include "sequence3.h"
#include <cstdlib>

using namespace main_savitch_5;

sequence::sequence(){
    head_ptr = NULL;
    tail_ptr = NULL;
    cursor = NULL;
    precursor = NULL;
    many_nodes = 0;
}
sequence::sequence(const sequence& source){
    many_nodes = source.many_nodes;
    list_copy(source.head_ptr, head_ptr, tail_ptr);
    node* val;
    val = source.head_ptr;
    precursor = head_ptr;

    if(source.cursor == NULL){
        if(source.precursor == NULL){
            cursor = NULL;
            precursor = NULL;
        }
        else{
            precursor = tail_ptr;
            cursor = NULL;
        }
    }
    else{
        if(source.precursor == NULL){
            cursor = head_ptr;
            precursor = NULL;
        }
        else{
            while(val != source.precursor){
                val = val -> link();
                precursor = precursor -> link();
            }
            cursor = precursor -> link();
        }
    }
}
sequence::~sequence(){
    list_clear(head_ptr);
}

void sequence::start(){
    cursor = head_ptr;
    precursor = NULL;
}
void sequence::advance(){
    if(is_item()){
        precursor = cursor;
        cursor = cursor -> link();
    }
    else{
        start();
    }
}
void sequence::insert(const sequence::value_type& entry){
    if(is_item()){
        if(precursor != NULL){
            list_insert(precursor, entry);
            cursor = precursor -> link();
        }
        else{
            list_head_insert(head_ptr, entry);
            precursor = NULL;
            cursor = head_ptr;
        }
    }
    else{
        if(many_nodes == 0){
            list_head_insert(head_ptr, entry);
            precursor = NULL;
            cursor = head_ptr;
            tail_ptr = head_ptr;
        }
        else{
            list_head_insert(head_ptr, entry);
            precursor = NULL;
            cursor = head_ptr;
        }
    }
    many_nodes++;
}
void sequence::attach(const sequence::value_type& entry){
    if(is_item()){
        if(cursor -> link() == NULL){
            list_insert(cursor, entry);
            precursor = cursor;
            cursor = cursor -> link();
            tail_ptr = cursor;
        }
        else{
            list_insert(cursor, entry);
            precursor = cursor;
            cursor = cursor -> link();
        }
    }
    else{
        if(many_nodes == 0){
            list_head_insert(head_ptr, entry);
            precursor = NULL;
            cursor = head_ptr;
            tail_ptr = head_ptr;
        }
        else{
            precursor = tail_ptr;
            list_insert(tail_ptr, entry);
            tail_ptr = tail_ptr -> link();
            cursor = tail_ptr;
        }
    }
    many_nodes++;
}
void sequence::operator=(const sequence& source){
    many_nodes = source.many_nodes;
    list_copy(source.head_ptr, head_ptr, tail_ptr);
    node* val;
    val = source.head_ptr;
    precursor = head_ptr;

    if(source.cursor == NULL){
        if(source.precursor == NULL){
            cursor = NULL;
            precursor = NULL;
        }
        else{
            precursor = tail_ptr;
            cursor = NULL;
        }
    }
    else{
        if(source.precursor == NULL){
            cursor = head_ptr;
            precursor = NULL;
        }
        else{
            while(val != source.precursor){
                val = val -> link();
                precursor = precursor -> link();
            }
            cursor = precursor -> link();
        }
    }
}
void sequence::remove_current(){
    if(is_item()){
        many_nodes--;
        
        if(precursor == NULL){
            list_head_remove(head_ptr);
            cursor = head_ptr;
        }
        else{
            cursor = cursor -> link();
            list_remove(precursor);
        }
    }
}
sequence::value_type sequence::current() const {
    return cursor -> data();
}