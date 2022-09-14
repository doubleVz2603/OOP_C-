

#include "Candidate.h"
using namespace std;
class GradeB : public Candidate
{
public:
    GradeB(int ID, int levelPriority, string fullName, string address)
        : Candidate(ID, levelPriority, fullName, address) {}
};
