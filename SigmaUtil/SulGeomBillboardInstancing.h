// SulGeomBillboardInstancing.h

#ifndef __SULGEOMBILLBOARDINSTANCING_H__
#define __SULGEOMBILLBOARDINSTANCING_H__

#include "SulGeomBase.h"
#include "SulTypes.h"

class CSulGeomBillboardInstancing :  public CSulGeomBase
{
public:
					CSulGeomBillboardInstancing( Sigma::uint32 numInstances, float sizeMultiplier=1.0f );

protected:
	void			createDrawable();

private:
	Sigma::uint32	m_numInstances;
	float			m_sizeMultiplier;
};

#endif // __SULGEOMBILLBOARDINSTANCING_H__