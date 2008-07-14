/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASTREAMWRITER_TECHNIQUE_H__
#define __COLLADASTREAMWRITER_TECHNIQUE_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAElementWriter.h"
#include <map>

namespace COLLADA
{

    //---------------------------------------------------------------
    /** A class to add an Asset to the stream*/

    class Technique : public ElementWriter
    {

    private:

        /** Used to close the current @a \<technique\> tag */
        TagCloser mTechniqueCloser;

        /** Manages a map with the currently opened child elements */
        std::map<String, TagCloser*> mOpenChildElements;

    public:
        /** Constructor that sets the stream the asset should be written to*/
        Technique ( StreamWriter* streamWriter ) : ElementWriter ( streamWriter ) {}

        /** Opens the technique tag */
        void openTechnique ( const String &profile, const String &xmlns="" );

        /** Adds a parameter to the technique */
        void addParameter ( const String &paramName, const String &value="" );

        /** Adds a parameter to the technique */
        void addParameter ( const String &paramName, const int &value );

        /** Adds a parameter to the technique */
        void addParameter ( const String &paramName, const double &value );

        /** Adds a parameter to the technique */
        void addParameter ( const String &paramName, const bool &value );

        /** Adds a parameter to the technique */
        void addMatrixParameter ( const String &paramName, const double matrix[][4] ) const;

        /** Opens a tag with the given name and adds the TagCloser to the child element into a map */
        void addChildElement ( const String &childElementName );

        /** Closes the tag with the given name, if it is open */
        void closeChildElement ( const String &childElementName );

        /** Closes the technique tag */
        void closeTechnique();

    };

} //namespace COLLADA


#endif //__COLLADASTREAMWRITER_TECHNIQUE_H__

