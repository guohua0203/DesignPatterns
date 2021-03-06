// Visitor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "header.h"

class FloppyDisk;
class Chassis;
class EquipmentVisitor;

class Equipment {
public:
	virtual int netPrice() = 0; 

	virtual int discountPrice() = 0;

	virtual void accept(EquipmentVisitor*) = 0; 

protected:
	// protected constructor indicates there will be sub-class;
	Equipment() {
		// implementation;
	}
};

class EquipmentVisitor{
public:
	virtual void visitFloppyDisk(FloppyDisk* fd) {
		// do noting as sub-class will implement it;
	}

	virtual void visitChassis(Chassis* c) {
		// do nothing as sub-class will implement it;
	}
};

class FloppyDisk : public Equipment {
public:
	FloppyDisk() : Equipment() {
		//implementation;
	}

	int netPrice() {
		return 100;
	}

	int discountPrice() {
		return 80;
	}

	void accept(EquipmentVisitor* visitor) {
		visitor->visitFloppyDisk(this);
	}
};

class Chassis : public Equipment {
public:
	Chassis() : Equipment() {
		// implementation;
	}

	void accept(EquipmentVisitor* visitor) {
		visitor->visitChassis(this);
	}

	int netPrice() {
		return 200;
	}

	int discountPrice() {
		return 175;
	}
};

class PricingVisitor : public EquipmentVisitor {
public:
	PricingVisitor() {
		// implementation;
	}

	void visitFloppyDisk(FloppyDisk* e) {
		m_total = e->netPrice();
		cout << "Floppy Disk Price is: " << m_total << endl;
	}

	void visitChassis(Chassis* e) {
		m_total = e->discountPrice();
		cout << "Chassis Price is : " << m_total << endl;
	}

private:
	int m_total;
};

class InventoryVisitor : public EquipmentVisitor {
public:
	InventoryVisitor() {
		// implementation;
	}

	void visitFloppyDisk(FloppyDisk* e) {
		cout << "Inventory Visitor visit FloppyDisk" << endl;
	}

	void visitChassis(Chassis* e) {
		cout << "Inventory Visitor visit Chassis" << endl;
	}
};

int main()
{
	FloppyDisk* fd = new FloppyDisk();
	Chassis* ch = new Chassis();
	PricingVisitor* pv = new PricingVisitor();
	InventoryVisitor* iv = new InventoryVisitor();

	fd->accept(pv);
	fd->accept(iv);
	ch->accept(pv);
	ch->accept(iv);
    return 0;
}

