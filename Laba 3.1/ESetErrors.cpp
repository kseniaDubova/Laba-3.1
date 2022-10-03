//
//  ESetErrors.cpp
//  Laba 3.1
//
//  Created by Ксения Дубова on 14.09.2022.
//

#include "ESetErrors.hpp"
EUnpossibal::EUnpossibal() {};
void EUnpossibal:: print_error() const
{
    cout <<"Operation is unpossibal"<<endl;
}

EUncorrectIndex::EUncorrectIndex() {};
void EUncorrectIndex:: print_error() const
{
    cout <<"Uncorrect index"<<endl;
}
