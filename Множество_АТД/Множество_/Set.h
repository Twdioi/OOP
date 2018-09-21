#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Set {

	vector <float> S;
	bool sorted;
	
public:
	Set();

	Set(const vector <float> &s);

	~Set();

	void set_S(const vector <float> &s);

	vector <float> get_S() const;

	void sort_S();

	bool empty() const;

	unsigned int size() const;

	void insert(const float num);

	void exclusion(const float num);

	Set operator+(const Set &s) const;

	Set operator-(const Set &s) const;

	Set operator*(const Set &s) const;
	
	bool operator==(const Set &s) const;

	bool operator<=(const Set &s) const;

	bool operator>=(const Set &s) const;

	bool operator[](const float num) const;

	int size_ex;
	int elem_ex;
	int sign_ex;
	int type_ex;
};