#ifndef __GO_H__
#define __GO_H__
class GO
{
	int barva;
public:
	GO(int bar);
	virtual void Nakresli();
	int GetBarva();
	void SetBarva(int bar);
	void Blikej();
};
#endif