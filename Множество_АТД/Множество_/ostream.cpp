#include "ostream.h"

ostream& operator<<(ostream &out, const Set s)
{
	out << "{ ";
	for (auto &s : s.get_S())
	{
		out << s << " ";
	}
	out << "}" << endl;

	return out;
}