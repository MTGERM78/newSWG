/*
 *	server/zone/objects/tangible/pharmaceutical/StimPack.cpp generated by engine3 IDL compiler 0.55
 */

#include "StimPack.h"

#include "StimPackImplementation.h"

#include "../../scene/SceneObject.h"

#include "../../creature/CreatureObject.h"

#include "../../player/Player.h"

#include "../TangibleObject.h"

#include "Pharmaceutical.h"

/*
 *	StimPackStub
 */

StimPack::StimPack(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn) : Pharmaceutical(DummyConstructorParameter::instance()) {
	_impl = new StimPackImplementation(oid, tempCRC, n, tempn);
	_impl->_setStub(this);
}

StimPack::StimPack(CreatureObject* creature, unsigned int tempCRC, const UnicodeString& n, const String& tempn) : Pharmaceutical(DummyConstructorParameter::instance()) {
	_impl = new StimPackImplementation(creature, tempCRC, n, tempn);
	_impl->_setStub(this);
}

StimPack::StimPack(DummyConstructorParameter* param) : Pharmaceutical(param) {
}

StimPack::~StimPack() {
}

void StimPack::generateAttributes(SceneObject* obj) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(obj);

		method.executeWithVoidReturn();
	} else
		((StimPackImplementation*) _impl)->generateAttributes(obj);
}

int StimPack::calculatePower(CreatureObject* creature) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(creature);

		return method.executeWithSignedIntReturn();
	} else
		return ((StimPackImplementation*) _impl)->calculatePower(creature);
}

void StimPack::setEffectiveness(float eff) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addFloatParameter(eff);

		method.executeWithVoidReturn();
	} else
		((StimPackImplementation*) _impl)->setEffectiveness(eff);
}

float StimPack::getEffectiveness() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		return method.executeWithFloatReturn();
	} else
		return ((StimPackImplementation*) _impl)->getEffectiveness();
}

/*
 *	StimPackAdapter
 */

StimPackAdapter::StimPackAdapter(StimPackImplementation* obj) : PharmaceuticalAdapter(obj) {
}

Packet* StimPackAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		generateAttributes((SceneObject*) inv->getObjectParameter());
		break;
	case 7:
		resp->insertSignedInt(calculatePower((CreatureObject*) inv->getObjectParameter()));
		break;
	case 8:
		setEffectiveness(inv->getFloatParameter());
		break;
	case 9:
		resp->insertFloat(getEffectiveness());
		break;
	default:
		return NULL;
	}

	return resp;
}

void StimPackAdapter::generateAttributes(SceneObject* obj) {
	return ((StimPackImplementation*) impl)->generateAttributes(obj);
}

int StimPackAdapter::calculatePower(CreatureObject* creature) {
	return ((StimPackImplementation*) impl)->calculatePower(creature);
}

void StimPackAdapter::setEffectiveness(float eff) {
	return ((StimPackImplementation*) impl)->setEffectiveness(eff);
}

float StimPackAdapter::getEffectiveness() {
	return ((StimPackImplementation*) impl)->getEffectiveness();
}

/*
 *	StimPackHelper
 */

StimPackHelper* StimPackHelper::staticInitializer = StimPackHelper::instance();

StimPackHelper::StimPackHelper() {
	className = "StimPack";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void StimPackHelper::finalizeHelper() {
	StimPackHelper::finalize();
}

DistributedObject* StimPackHelper::instantiateObject() {
	return new StimPack(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* StimPackHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new StimPackAdapter((StimPackImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	StimPackServant
 */

StimPackServant::StimPackServant(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, int mptype) : PharmaceuticalImplementation(oid, tempCRC, n, tempn, mptype) {
	_classHelper = StimPackHelper::instance();
}

StimPackServant::StimPackServant(CreatureObject* creature, unsigned int tempCRC, const UnicodeString& n, const String& tempn, int mptype) : PharmaceuticalImplementation(creature, tempCRC, n, tempn, mptype) {
	_classHelper = StimPackHelper::instance();
}

StimPackServant::~StimPackServant() {
}

void StimPackServant::_setStub(DistributedObjectStub* stub) {
	_this = (StimPack*) stub;
	PharmaceuticalServant::_setStub(stub);
}

DistributedObjectStub* StimPackServant::_getStub() {
	return _this;
}

