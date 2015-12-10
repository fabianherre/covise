/* This file is part of COVISE.

You can use it under the terms of the GNU Lesser General Public License
version 2.1 or later, see lgpl-2.1.txt.

* License: LGPL 2+ */
#ifndef OSC_MANEUVER_REF_ACTOR_H
#define OSC_MANEUVER_REF_ACTOR_H
#include <oscExport.h>
#include <oscObjectBase.h>
#include <oscObjectVariable.h>
#include <oscNamedObject.h>
#include <oscNamedPriority.h>
#include <oscStartConditionRef.h>
#include <oscEndConditionRef.h>
#include <oscCancelConditionRef.h>
#include <oscCatalogRef.h>
#include <oscManeuver.h>


namespace OpenScenario {

/// \class This class represents a generic OpenScenario Object
class OPENSCENARIOEXPORT oscManeuverRefActor: public oscNamedPriority
{
public:
    oscManeuverRefActor()
    {
	   OSC_OBJECT_ADD_MEMBER(startCondition,"oscStartConditionRef");
	   OSC_OBJECT_ADD_MEMBER(endCondition,"oscEndConditionRef");
       OSC_OBJECT_ADD_MEMBER(cancelCondition,"oscCancelConditionRef");
	   OSC_OBJECT_ADD_MEMBER(catalogRef,"oscCatalogRef");
       OSC_OBJECT_ADD_MEMBER(maneuver,"oscManeuver");

    };
	oscStartConditionRefMember startCondition;
    oscEndConditionRefMember endCondition;
    oscCancelConditionRefMember cancelCondition;
    oscCatalogRefMember catalogRef;
    oscManeuverMember maneuver;
};

typedef oscObjectVariable<oscManeuverRefActor *>oscManeuverRefActorMember;

}

#endif //OSC_MANEUVER_REF_ACTOR_H