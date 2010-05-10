// SulGeomSphere.h

#ifndef __SULGEOMSPHERE_H__
#define __SULGEOMSPHERE_H__

#include "SulGeomBase.h"

class CSulGeomSphere : public CSulGeomBase
{

public:
				CSulGeomSphere( float radius=1.0f, osg::Vec3 pos=osg::Vec3(0,0,0)  );

protected:
	void		createDrawable();

private:
	float		m_radius;
	osg::Vec3	m_pos;
	osg::Vec4	m_color;
};

#endif // __SULGEOMSPHERE_H__