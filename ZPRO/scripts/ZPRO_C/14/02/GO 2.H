#ifndef __GO_H__
#define __GO_H__
class GO
{
	int barva;
public:
	GO(int bar);
	virtual void Nakresli() = 0;
	int GetBarva();
	void SetBarva(int bar);
};
#endif