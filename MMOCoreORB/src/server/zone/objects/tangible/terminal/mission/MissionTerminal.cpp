/*
 *	server/zone/objects/tangible/terminal/mission/MissionTerminal.cpp generated by engine3 IDL compiler 0.55
 */

#include "MissionTerminal.h"

#include "MissionTerminalImplementation.h"

#include "../../../player/Player.h"

#include "../../../creature/shuttle/ShuttleCreature.h"

#include "../Terminal.h"

/*
 *	MissionTerminalStub
 */

MissionTerminal::MissionTerminal(unsigned long long objid, float x, float z, float y, int pId, int tmsk) : Terminal(DummyConstructorParameter::instance()) {
	_impl = new MissionTerminalImplementation(objid, x, z, y, pId, tmsk);
	_impl->_setStub(this);
}

MissionTerminal::MissionTerminal(DummyConstructorParameter* param) : Terminal(param) {
}

MissionTerminal::~MissionTerminal() {
}

int MissionTerminal::getPlanetId() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		return method.executeWithSignedIntReturn();
	} else
		return ((MissionTerminalImplementation*) _impl)->getPlanetId();
}

int MissionTerminal::getTerminalMask() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		return method.executeWithSignedIntReturn();
	} else
		return ((MissionTerminalImplementation*) _impl)->getTerminalMask();
}

int MissionTerminal::useObject(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(player);

		return method.executeWithSignedIntReturn();
	} else
		return ((MissionTerminalImplementation*) _impl)->useObject(player);
}

/*
 *	MissionTerminalAdapter
 */

MissionTerminalAdapter::MissionTerminalAdapter(MissionTerminalImplementation* obj) : TerminalAdapter(obj) {
}

Packet* MissionTerminalAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertSignedInt(getPlanetId());
		break;
	case 7:
		resp->insertSignedInt(getTerminalMask());
		break;
	case 8:
		resp->insertSignedInt(useObject((Player*) inv->getObjectParameter()));
		break;
	default:
		return NULL;
	}

	return resp;
}

int MissionTerminalAdapter::getPlanetId() {
	return ((MissionTerminalImplementation*) impl)->getPlanetId();
}

int MissionTerminalAdapter::getTerminalMask() {
	return ((MissionTerminalImplementation*) impl)->getTerminalMask();
}

int MissionTerminalAdapter::useObject(Player* player) {
	return ((MissionTerminalImplementation*) impl)->useObject(player);
}

/*
 *	MissionTerminalHelper
 */

MissionTerminalHelper* MissionTerminalHelper::staticInitializer = MissionTerminalHelper::instance();

MissionTerminalHelper::MissionTerminalHelper() {
	className = "MissionTerminal";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void MissionTerminalHelper::finalizeHelper() {
	MissionTerminalHelper::finalize();
}

DistributedObject* MissionTerminalHelper::instantiateObject() {
	return new MissionTerminal(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* MissionTerminalHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new MissionTerminalAdapter((MissionTerminalImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	MissionTerminalServant
 */

MissionTerminalServant::MissionTerminalServant(unsigned int objCRC, unsigned long long objid, const UnicodeString& n, const String& tempn, float x, float z, float y, int TerminalType) : TerminalImplementation(objCRC, objid, n, tempn, x, z, y, TerminalType) {
	_classHelper = MissionTerminalHelper::instance();
}

MissionTerminalServant::~MissionTerminalServant() {
}

void MissionTerminalServant::_setStub(DistributedObjectStub* stub) {
	_this = (MissionTerminal*) stub;
	TerminalServant::_setStub(stub);
}

DistributedObjectStub* MissionTerminalServant::_getStub() {
	return _this;
}

