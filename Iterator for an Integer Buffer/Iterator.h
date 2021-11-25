#pragma once

class Iterator {
public:
	virtual void first() = 0;
	virtual void next() = 0;
	virtual int currentItem() = 0;
	virtual bool isDone() = 0;
};