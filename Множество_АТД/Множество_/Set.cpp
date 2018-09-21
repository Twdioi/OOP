#include "Set.h"


Set::Set()
{
}

Set::Set(const vector <float> &s)
{
	set_S(s);
}

Set::~Set()
{
}

void Set::set_S(const vector <float> &s)
{	
	bool flag = true;

	for (auto &s1 : s)
	{
		if (S.size() == 0) S.push_back(s1);
		for (auto &s2 : S)
			if (s1 == s2) 
			{
				flag = false;
				break;
			}

		if (flag) S.push_back(s1);
		flag = true;
	}
}

vector <float> Set::get_S() const
{
	return S;
}

void Set::sort_S()
{
	if (!sorted)
		sort(S.begin(), S.end(), less<float>());
	sorted = true;
}

bool Set::empty() const
{
	bool flag = false;

	if (this->size() == 0) flag = true;

	return flag;
}

unsigned int Set::size() const
{
	return S.size();
}

void Set::insert(const float num)
{
	bool flag = true;

	if (num <= 0) throw sign_ex = 1;
	if (num - floor(num) > 0) throw type_ex = 0;
	
	for (auto &s : S)
	{
		if (s == num) flag = false;
	}

	if (flag) S.push_back(num);
}

void Set::exclusion(const float num)
{
	bool flag = true;

	if (S.size() == 0) throw size_ex = 0;
	
	for (auto &s : S)
		if (s == num)
		{
			float tmp;
			tmp = S.back();
			s = tmp;
			S.pop_back();
			flag = false;
			break;
		}

	if (flag) throw elem_ex = 1;
}

Set Set::operator+(const Set &s) const
{	
	bool flag = true;
	vector <float> tmp(this->get_S());

	for (auto &s2 : s.get_S())
	{
		for (auto &s1 : this->get_S())
			if (s1 == s2)
			{
				flag = false;
				break;
			}

		if (flag) tmp.push_back(s2);
		flag = true;
	}

	return Set(tmp);
}

Set Set::operator-(const Set &s) const
{
	bool flag = true;

	vector <float> tmp;

	for (auto &s1 : this->get_S())
	{
		for (auto &s2 : s.get_S())
			if (s1 == s2)
				flag = false;

		if (flag) tmp.push_back(s1);
		flag = true;
	}

	return Set(tmp);
}

Set Set::operator*(const Set &s) const
{
	bool flag = true;

	vector <float> tmp;

	for (auto &s1 : this->get_S())
	{
		for (auto &s2 : s.get_S())
			if (s1 == s2)
			{
				flag = true;
				break;
			}
			else flag = false;

		if (flag) tmp.push_back(s1);
	}

	return Set(tmp);
}

bool Set::operator==(const Set & s) const
{
	bool flag = false;

	float size(0);

	if (this->get_S().size() != s.get_S().size())
		flag = false;
	else
	{
		for (auto &s1 : this->get_S())
			for (auto &s2 : s.get_S())
				if (s1 == s2)
				{
					size++;
					break;
				}
	}

	if (size == this->get_S().size()) flag = true;

	return flag;
}

bool Set::operator<=(const Set &s) const
{
	bool flag = false;
	float size(0);

	for (auto &s1 : this->get_S())
		for (auto &s2 : s.get_S())
		{
			if (s1 == s2)
			{
				size++;
				break;
			}
		}
	
	if (size == this->get_S().size()) flag = true;

	return flag;
}

bool Set::operator>=(const Set &s) const
{
	bool flag = false;
	float size(0);

	for (auto &s2 : s.get_S())
		for (auto &s1 : this->get_S())
		{
			if (s1 == s2)
			{
				size++;
				break;
			}
		}

	if (size == s.get_S().size()) flag = true;

	return flag;
}

bool Set::operator[](const float num) const
{
	bool flag = false;

	for (auto &s : this->get_S())
		if (s == num) flag = true;

	return flag;
}