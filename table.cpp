#include <iostream>
#include <vector>
#include "table.h"
#include "entry.h"

Table::Table(unsigned int max_entries):max_entries(max_entries){
	v[max_entries];
	for (int i = 0; i < max_entries; i++){
		std::vector<Entry> p;
		v.push_back(p);
	}
}

Table::Table(unsigned int entries, std::istream& input){
	std::string line;
	getline(input, line);
	for (int i = 0; i < entries; i++){
		std::vector<Entry> p;
		v.push_back(p);
		int index = stoi(line);
		Entry e;
		e.set_key(index);
		e.set_data(line);
		index = index % 100;
		v[index].push_back(e);
		getline(input, line);
	}
}

void Table::put(unsigned int key, std::string data){
	Entry e;
	e.set_key(key);
	e.set_data(data);
	key = key % 100;
	v[key].push_back(e);
}

void Table::put(Entry e){
	unsigned int value = e.get_key();
	value = value % 100;
	v[value].push_back(e);
}

std::string Table::get(unsigned int key) const {
	int index = key % 100;
	int okey;
	std::string str;
	for(int i = 0; i < v[index].size(); i++){
		okey = v[index][i].get_key();
		str = v[index][i].get_data();
		if (key == okey) break;
		if (i == v[index].size() - 1) str = "stub";
	}
	return str;
}

bool Table::remove(unsigned int key){
	int index = key % 100;
	for (int i = 0; i < v[index].size(); i++){
		if (v[index][i].get_key() == key){
			v.erase(v.begin() + i);
			return true;
		}
	}
	return false;
}

std::ostream& operator<< (std::ostream& out, const Table& t){
	return out;
}
