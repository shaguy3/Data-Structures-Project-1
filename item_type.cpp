#include "item_type.h"

ItemType::ItemType() :
    var(0), next(nullptr) {}

ItemType::ItemType(int _var) :
    var(_var), next(nullptr) {}

ItemType::~ItemType() {}