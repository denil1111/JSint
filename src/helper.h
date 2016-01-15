#ifndef HELPER_H_
#define HELPER_H_

#include "utils.h"

template <typename T>
std::vector<T>* concat(std::vector<T>* v1, std::vector<T>* v2) {
    int l1 = v1->size();
    int l2 = v2->size();
    std::vector<T>* v = new std::vector<T>(l1 + l2);
    for (int i=0; i<l1; i++) v->at(i) = v1->at(i);
    for (int i=0; i<l2; i++) v->at(i+l1) = v2->at(i);
    return v;
}

template <typename T>
std::vector<T>* concat(T t, std::vector<T>* v2) {
	int l2 = v2->size();
	std::vector<T>* v = new std::vector<T>(1 + l2);
	v->at(0) = t;
	for (int i=0; i<l2; i++) v->at(i+1) = v2->at(i);
	return v;
}

#endif
