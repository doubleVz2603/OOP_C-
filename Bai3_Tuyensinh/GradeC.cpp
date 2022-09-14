
#include "Candidate.h"
using namespace std;
class GradeC : public Candidate
{
public:
    GradeC(int ID, int levelPriority, string fullName, string address)
        : Candidate(ID, levelPriority, fullName, address) {}
};