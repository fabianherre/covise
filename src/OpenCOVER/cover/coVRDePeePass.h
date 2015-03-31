/* This file is part of COVISE.

   You can use it under the terms of the GNU Lesser General Public License
   version 2.1 or later, see lgpl-2.1.txt.

 * License: LGPL 2+ */
/*
  Steffen Frey
  Fachpraktikum Graphik-Programmierung 2007
  Institut fuer Visualisierung und Interaktive Systeme
  Universitaet Stuttgart
 */

#ifndef _coVRDePeePASS_H_
#define _coVRDePeePASS_H_

#include <map>
#include <osg/Node>
#include <osg/Camera>
#include <osg/Group>
#include <util/coExport.h>

namespace opencover
{
/*!
  MapMode specifies the kind of texture maps that can be generated for later
  usage
 */
enum MapMode {NORMAL_DEPTH_MAP, COLOR_MAP, EDGE_MAP, NOISE_MAP};

/*!
  coVRDePeePass can be seen as a mera data structure and typically used by 
  the class coVRDePee. It represents one depth peeling pass and is initialized
  by functions in the coVRDePee class, but cleans itself up.
  Please note, that no texture generation mode is allowed to appear twice
*/
class COVEREXPORT coVRDePeePass
{
 public:
  /*!
    Constructor
   */
  coVRDePeePass();
  
  /*!
    Desctructor cleans the whole depth peeling pass
   */
  ~coVRDePeePass();
  
  /*!
    Make data structure ready for incorporating a new rendering pass
   */
  void newRenderPass(MapMode mapMode);
  
  /*!
    Clean up the specified rendering pass
   */
  void remRenderPass(MapMode mapMode);
  
  osg::ref_ptr<osg::Group> root;
  std::map<MapMode, osg::ref_ptr<osg::Camera> > Cameras;
  std::map<MapMode, osg::ref_ptr<osg::Group> > settingNodes;
};
}
#endif
