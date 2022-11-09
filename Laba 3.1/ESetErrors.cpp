
#include "ESetErrors.hpp"


EUnpossibal::EUnpossibal() {};

void EUnpossibal:: print_error() const
{
    cout << "Operation is unpossibal" << endl;
}

EUncorrectIndex::EUncorrectIndex() {};

void EUncorrectIndex:: print_error() const
{
    cout << "Uncorrect index" << endl;
}

//
//template class Vector<float>;
//template class Vector<short>;
//template class Vector<char>;
//template class Vector<bool>;
