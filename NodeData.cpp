//
//  NodeData.cpp
//  Program2
//
//  Created by Kemba Konteh on 1/26/20.
//  Copyright © 2020 Kemba Konteh. All rights reserved.
//

#include "NodeData.h"

//------------------- constructors/destructor  -------------------------------
NodeData::NodeData() { data = ""; }                         // default

NodeData::~NodeData() { }            // needed so strings are deleted properly

NodeData::NodeData(const NodeData& nd) { data = nd.data; }  // copy

NodeData::NodeData(const string& s) { data = s; }    // cast string to NodeData

//------------------------- operator= ----------------------------------------
NodeData& NodeData::operator=(const NodeData& rhs) {
    if (this != &rhs) {
        data = rhs.data;
    }
    return *this;
}

//------------------------- operator==,!= ------------------------------------
bool NodeData::operator==(const NodeData& rhs) const {
    return data == rhs.data;
}

bool NodeData::operator!=(const NodeData& rhs) const {
    return data != rhs.data;
}

//------------------------ operator<,>,<=,>= ---------------------------------
bool NodeData::operator<(const NodeData& rhs) const {
    return data < rhs.data;
}

bool NodeData::operator>(const NodeData& rhs) const {
    return data > rhs.data;
}

bool NodeData::operator<=(const NodeData& rhs) const {
    return data <= rhs.data;
}

bool NodeData::operator>=(const NodeData& rhs) const {
    return data >= rhs.data;
}

//------------------------------ setData -------------------------------------
// returns true if the data is set, false when bad data, i.e., is eof

bool NodeData::setData(istream& infile) {
    getline(infile, data);
    return !infile.eof();       // eof function is true when eof char is read
}

//-------------------------- operator<< --------------------------------------
ostream& operator<<(ostream& output, const NodeData& nd) {
    output << nd.data;
    return output;
}
