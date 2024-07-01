////
//// Created by Vasile George on 04.04.2024.
////
//
//#ifndef LAB6OOP_VECTOR_H
//#define LAB6OOP_VECTOR_H
//#include "Film.h"
//#include <iostream>
//
//typedef Film type;
//
//template
//template <typename type> class Iterator;
//
//template <typename type>
//class vector {
//private:
//    type* elems;
//    int size;
//    int capacity;
//public:
//    vector();
//    vector(const vector& v);
//    ~vector();
//    void operator=(const vector& v);
//    void push_back(type e);
//    int size() const;
//    int get_capacity() const;
//    type get_elem(int i) const;
//    void set_elem(int i, type e);
//    void clear();
//    void resize();
//    void delete_elem(int i);
//    void swap(int i, int j);
//
//    friend class Iterator<type>;
//    Iterator<type> begin();
//    Iterator<type> end();
//
//};
//
//
//template <typename type>
//void vector<type>::swap_elem(int i, int j) {
//    type aux = this->elems[i];
//    this->elems[i] = this->elems[j];
//    this->elems[j] = aux;
//}
//
//template <typename type>
//void vector<type>::delete_elem(int i) {
//    for(int j = i; j < this->size - 1; j++)
//        this->elems[j] = this->elems[j + 1];
//    this->size--;
//}
//
//template <typename type>
//vector<type>::vector():size{0}, capacity{2}, elems{new type[2]} {
//}
//
//template <typename type>
//vector<type>::vector(const vector<type> &v) {
//    this->size = v.size;
//    this->capacity = v.capacity;
//    this->elems = new type[this->capacity];
//    for (int i = 0; i < this->size; i++)
//        this->elems[i] = v.elems[i];
//}
//
//template <typename type>
//vector<type>::~vector() {
//    delete[] this->elems;
//}
//
//template <typename type>
//void vector<type>::operator=(const vector &v) {
//    if (this == &v)
//        return;
//    this->size = v.size;
//    this->capacity = v.capacity;
//    delete[] this->elems;
//    this->elems = new type[this->capacity];
//    for (int i = 0; i < this->size; i++)
//        this->elems[i] = v.elems[i];
//}
//
//template <typename type>
//void vector<type>::push_back(type e) {
//    if (this->size == this->capacity)
//        this->resize();
//    this->elems[this->size++] = e;
//}
//
//template <typename type>
//void vector<type>::resize(){
//    this->capacity *= 2;
//    type* new_elems = new type[this->capacity];
////    Iterator<type> it = this->begin();
////    for(int i = 0; it.valid(); ++it, i++)
////        new_elems[i] = *it;
//    for(int i = 0; i < this->size; i++)
//        new_elems[i] = this->elems[i];
//
//    delete[] this->elems;
//    this->elems = new_elems;
//}
//
//template <typename type>
//int vector<type>::get_size() const{
//    return this->size;
//}
//
//template <typename type>
//type vector<type>::get_elem(int i) const{
//    return this->elems[i];
//}
//
//template <typename type>
//void vector<type>::set_elem(int i, type e) {
//    this->elems[i] = e;
//}
//
//template <typename type>
//void vector<type>::clear() {
//    this->size = 0;
//    this->capacity = 2;
//    delete[] this->elems;
//}
//
//template <typename type>
//int vector<type>::get_capacity() const {
//    return this->capacity;
//}
//
//
//
//template <typename type>
//Iterator<type> vector<type>::begin() {
//    return Iterator<type>{*this, 0};
//}
//
//template <typename type>
//Iterator<type> vector<type>::end() {
//    return Iterator<type>{*this, this->size};
//}
//
//
//template <typename type>
//class Iterator {
//private:
//    vector<type>& v;
//    int poz;
//public:
//    friend class vector<type>;
//    Iterator(vector<type>& v, int poz);
//    void operator++();
//    bool operator!=(const Iterator& it);
//    type operator*();
//    bool operator==(const Iterator& it);
//    ~Iterator();
//    bool valid();
//};
//
//template <typename type>
//Iterator<type>::Iterator(vector<type> &v, int poz):v{v}, poz{poz} {
//}
//template <typename type>
//bool Iterator<type>::operator==(const Iterator &it) {
//    return this->poz == it.poz;
//}
//
//template<typename type>
//void Iterator<type>::operator++() {
//    if(this->valid())
//        this->poz++;
//}
//template<typename type>
//bool Iterator<type>::operator!=(const Iterator &it) {
//    return this->poz != it.poz;
//}
//template<typename type>
//type Iterator<type>::operator*() {
//    return this->v.get_elem(this->poz);
//}
//
//template<typename type>
//Iterator<type>::~Iterator() {
//    this->poz = 0;
//}
//
//template<typename type>
//bool Iterator<type>::valid() {
//    return this->poz < this->v.size();
//}
//
//
//
//#endif
//
