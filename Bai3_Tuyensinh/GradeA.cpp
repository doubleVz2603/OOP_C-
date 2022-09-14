
#include "Candidate.h"
using namespace std;
class GradeA : public Candidate
{
public:
    GradeA(int ID, int levelPriority, string fullName, string address)
        : Candidate(ID, levelPriority, fullName, address) {}
};