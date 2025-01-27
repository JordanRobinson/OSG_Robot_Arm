#include "StdAfx.h"
#include <windows.h>
#include <iostream>
#include <osgFX/Scribe>
#include <osg/MatrixTransform>
#include "jrOSGRotator.h"

jrOSGRotator::jrOSGRotator(void) {}


jrOSGRotator::~jrOSGRotator(void) {}

void jrOSGRotator::rotate(osg::Node* node, const std::string name, const double angle) {
	osg::Group* parent = node->getParent(0);

	osg::MatrixTransform* transform = new osg::MatrixTransform;

	const osg::Vec3d axis(0, 0, -1);
	transform->setMatrix(osg::Matrix::rotate(angle, axis));
	transform->setName(name);
	transform->addChild(node);
	parent->replaceChild(node, transform);
}

void jrOSGRotator::rotate(osg::Node* node, double angle, osg::Vec3d axis) {
	osg::MatrixTransform* matrixTrans = dynamic_cast<osg::MatrixTransform*>(node);

	osg::Group* parent = node->getParent(0);

	osg::Vec3d trans = dynamic_cast<osg::MatrixTransform*>(parent)->getMatrix().getTrans();
	trans.x() *= -1;
	trans.y() *= -1;
	trans.z() *= -1;

	osg::Matrix matrix = osg::Matrix::translate(trans) * osg::Matrix::rotate(angle, axis);

	matrixTrans->setMatrix(matrix);
}
