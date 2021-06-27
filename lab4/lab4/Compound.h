#include "CBody.h"
#include <vector>

using namespace std;

class CCompound final :
	public CBody
{
public:
	CCompound(const vector<CBody*>& compoundBody);
	double GetDensity() const override;
	double GetVolume() const override;
	double GetMass() const override;
	string GetStringUniqParams() const final;
	void AddBody(CBody& body);
	~CCompound();
private:
	vector<CBody*> m_bodies;
};