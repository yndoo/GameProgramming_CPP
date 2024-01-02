#pragma once

class NameUnit
{
public:
	void SetName(const char* _Name);
	char* GetName() {
		return Name;
	}

protected:
	char Name[100] = "None";
};

