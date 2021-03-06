// prototype.cpp : Defines the entry point for the console application.
//

#include "header.h"

// RecordFactory call Record clone to create Record; 
// (once using Record to parameterize RecordFactory);

class Record {
public:
	// has to be pointer; otherwise cannot define override functions;
	virtual Record* clone() = 0;
};

class CarRecord : public Record{
	string m_id;
public:
	CarRecord(const string& id) : m_id(id) {};
	CarRecord* clone() override{
		return this;
	}
};

class PersonRecord : public Record {
	string m_name;
public:
	PersonRecord(const string& name) : m_name(name) {};
	PersonRecord * clone () override{
		return this;
	}
};

class RecordFactory {
	Record* m_record;
public:
	RecordFactory(Record* const record) { m_record = record; };
	Record * createRecord() {
		return m_record->clone();
	}
};

int main()
{
	CarRecord* carRecord = new CarRecord("Benz");
	PersonRecord* personRecord = new PersonRecord("Tom");

	RecordFactory rf(carRecord);
	Record* newRecord = rf.createRecord();

	RecordFactory rf2(personRecord);
	Record* newRecord2 = rf2.createRecord();

    return 0;
}

