/* This file is part of COVISE.

You can use it under the terms of the GNU Lesser General Public License
version 2.1 or later, see lgpl-2.1.txt.

* License: LGPL 2+ */
#ifndef OSC_OBJECT_VARIABLE_H
#define OSC_OBJECT_VARIABLE_H

#include <oscExport.h>
#include <oscMemberValue.h>
#include <oscMember.h>

#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/util/XMLString.hpp>

namespace OpenScenario
{
    template<typename T>
    class OPENSCENARIOEXPORT oscObjectVariable: public oscMember 
    {
    protected:
        T valueT;
    public:
        oscObjectVariable(){type = oscMemberValue::OBJECT; valueT=NULL;};
        bool initialize(xercesc::DOMAttr *){return false;};
        T operator->(){return valueT;};
        const oscObjectBase* getObject() const {return valueT;};
        void setValue(oscObjectBase *t){valueT = dynamic_cast<T>(t);};
        bool exists() const {return valueT!=NULL;};
        bool writeToDOM(xercesc::DOMElement *currentElement, xercesc::DOMDocument *document)
        {
            if(valueT !=NULL)
            {
                xercesc::DOMElement *memberElement;
                memberElement = document->createElement(xercesc::XMLString::transcode(name.c_str()));
                currentElement->appendChild(memberElement);
                valueT->writeToDOM(memberElement,document);
            }
            return true;
        };
        oscMemberValue::MemberTypes getValueType() const {return type;};
            
    };
    
}


#endif //OSC_OBJECT_VARIABLE_H
