#include <iostream>
#include <vector>
#include "table.h"
#include "entry.h"

Table::Table(unsigned int max_entries):max_entries(max_entries){
	for (int i = 0; i < max_entries; i++){
		p.push_back(new vec);	
	}		
}

Table::Table(unsigned int entries, std::istream& input){
	"stub";
}

void Table::put(unsigned int key, std::string data){
	"stub";
}

void Table::put(Entry e){
	"stub";
}

std::string Table::get(unsigned int key) const {
	return "stub";
}

bool Table::remove(unsigned int key){
	return false;
}

std::ostream& operator<< (std::ostream& out, const Table& t){
	return out;
}
