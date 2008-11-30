/*
 *	server/zone/objects/tangible/wearables/Wearable.h generated by engine3 IDL compiler 0.55
 */

#ifndef WEARABLE_H_
#define WEARABLE_H_

#include "engine/orb/DistributedObjectBroker.h"

class CreatureObject;

class Player;

class TangibleObject;

#include "../TangibleObject.h"

class Wearable : public TangibleObject {
public:
	Wearable(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, bool eqp = false);

	Wearable(CreatureObject* creature, unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, bool eqp = false);

	Wearable(CreatureObject* creature, unsigned int tempCRC, const UnicodeString& n, const String& tempn, bool eqp = false);

protected:
	Wearable(DummyConstructorParameter* param);

	virtual ~Wearable();

	friend class WearableHelper;
};

class WearableImplementation;

class WearableAdapter : public TangibleObjectAdapter {
public:
	WearableAdapter(WearableImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

};

class WearableHelper : public DistributedObjectClassHelper, public Singleton<WearableHelper> {
	static WearableHelper* staticInitializer;

public:
	WearableHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<WearableHelper>;
};

#include "../TangibleObjectImplementation.h"

class WearableServant : public TangibleObjectImplementation {
public:
	Wearable* _this;

public:
	WearableServant(unsigned long long oid, int tp);
	virtual ~WearableServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*WEARABLE_H_*/
