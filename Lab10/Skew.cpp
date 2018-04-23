#include "Skew.hpp"

Skew::Skew() { this->_root = nullptr; }

Skew::~Skew() { this->_delete(this->_root); }

bool Skew::_shouldSwap(Node *target) { return true; }
