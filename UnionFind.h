
#ifndef PROJECT_UNIONFIND_H
#define PROJECT_UNIONFIND_H

#include "Array.h"
#include <cassert>
#include "exceptions.h"



template <class T>
class UnionFind {


    class UnionNode{
    public:
        int union_index;
        UnionNode* union_father;
        int amount_of_children;
        UnionNode(const int& union_find_index, UnionNode* UF_parent = nullptr) : union_index(union_find_index), union_father(UF_parent), amount_of_children(0){}

    };

    Array<UnionNode*> union_element_array;
    Array<T*> union_group_array;
    int amount_of_elements;

public:

    UnionFind(const int& number_of_elements = 0) : amount_of_elements(number_of_elements){
        union_element_array = Array<UnionNode*>(number_of_elements);
        union_group_array = Array<T*>(number_of_elements);

        for(int i = 0; i < number_of_elements; i++){
            union_element_array[i] = new UnionNode(i, nullptr);
            union_group_array[i] = new T();
        }
    }

    UnionFind(const UnionFind& union_find_to_copy){
        amount_of_elements = union_find_to_copy.amount_of_elements;
        union_element_array = Array<UnionNode*>(amount_of_elements);
        union_group_array = Array<T*>(amount_of_elements);

        for(int i = 0; i < amount_of_elements; i++){
            union_element_array[i] = new UnionNode(i, nullptr);
            union_group_array[i] = new T(*(union_find_to_copy.union_group_array[i]));
        }

        for(int i = 0; i < amount_of_elements; i ++){
            UnionNode* uf_iterator = union_find_to_copy.union_element_array[i]->union_father;
            UnionNode* uf_root = nullptr;
            while(uf_iterator != nullptr){
                uf_root = uf_iterator;
                uf_iterator = uf_root->union_father;
            }
            if(uf_root != nullptr) {
                union_element_array[i]->union_father = union_element_array[uf_root->union_index];
                union_element_array[uf_root->union_index]->amount_of_children++;
                T* temp = union_group_array[i];
                union_group_array[i] = union_group_array[uf_root->union_index];
                delete temp;
            }
        }
    }

    ~UnionFind(){
        for(int i = 0; i < amount_of_elements; i++){
            if(union_element_array[i]->union_father == nullptr){
                delete union_group_array[i];
            }
        }
        for(int i = 0; i < amount_of_elements; i++){
            delete union_element_array[i];
        }
    }

    UnionFind& operator=(const UnionFind& uf_to_copy){

        for(int i = 0; i < amount_of_elements; i++){
            if(union_element_array[i]->union_father == nullptr){
                delete union_group_array[i];
            }
        }
        for(int i = 0; i < amount_of_elements; i++){
            delete union_element_array[i];
        }

        amount_of_elements = uf_to_copy.amount_of_elements;
        union_element_array = Array<UnionNode*>(amount_of_elements);
        union_group_array = Array<T*>(amount_of_elements);

        for(int i = 0; i < amount_of_elements; i++){
            union_element_array[i] = new UnionNode(i, nullptr);
            union_group_array[i] = new T(uf_to_copy.union_group_array[i]);
        }

        for(int i = 0; i < amount_of_elements; i ++){
            UnionNode* uf_iter = uf_to_copy.union_element_array[i]->union_father;
            UnionNode* uf_root = nullptr;
            while(uf_iter != nullptr){
                uf_root = uf_iter;
                uf_iter = uf_root->union_father;
            }
            if(uf_root != nullptr) {
                union_element_array[i]->union_father = union_element_array[uf_root->union_index];
                union_element_array[uf_root->union_index]->amount_of_children++;
                T* temp = union_group_array[i];
                union_group_array[i] = union_group_array[uf_root->union_index];
                delete temp;
            }
        }
    }

    T* find(const int& uf_index){
        if (uf_index > amount_of_elements || uf_index < 0){
            throw IllegalIndex();
        }
        Array<UnionNode*> nodes_needed_to_connect = Array<UnionNode*>(amount_of_elements);
        UnionNode* uf_iter = union_element_array[uf_index];
        int uf_number_of_children = 0;

        while(uf_iter->union_father != nullptr){
            nodes_needed_to_connect[uf_number_of_children] = uf_iter;
            uf_number_of_children++;
            uf_iter = uf_iter->union_father;
        }

        while(uf_number_of_children > 0){
            nodes_needed_to_connect[uf_number_of_children - 1]->union_father = uf_iter;
            union_group_array[nodes_needed_to_connect[uf_number_of_children - 1]->union_index] = union_group_array[uf_iter->union_index];
            uf_number_of_children--;
        }

        return union_group_array[uf_iter->union_index];
    }


    int unite(const int& index1, const int& index2){
        UnionNode* root_of_first = union_element_array[index1];
        UnionNode* root_of_second = union_element_array[index2];

        while(root_of_first->union_father != nullptr){
            root_of_first = root_of_first->union_father;
        }

        while(root_of_second->union_father != nullptr){
            root_of_second = root_of_second->union_father;
        }

        UnionNode* bigger_root;
        UnionNode* smaller_root;

        if(root_of_second == root_of_first){
            throw UnionFailed();
        }

        if(root_of_first->amount_of_children > root_of_second->amount_of_children){
            bigger_root = root_of_first;
            smaller_root = root_of_second;
        }
        else{
            bigger_root = root_of_second;
            smaller_root = root_of_first;
        }

        smaller_root->union_father = bigger_root;
        bigger_root->amount_of_children += 1 + smaller_root->amount_of_children;
        T* temp = union_group_array[smaller_root->union_index];
        union_group_array[smaller_root->union_index] = union_group_array[bigger_root->union_index];
        delete temp;

        return bigger_root->union_index;
    }
};



#endif //PROJECT_UNIONFIND_H
