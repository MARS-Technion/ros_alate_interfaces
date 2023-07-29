/*
Copyright 2023 David Dovrat

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef _ROS_ALATE_INTERFACES_6DOF_MESSAGE_H_
#define _ROS_ALATE_INTERFACES_6DOF_MESSAGE_H_

#include <NeMALA/MessagePropertyTree.h>

namespace ros_alate_interfaces {

//--------------------------------------------------------
// 					Class Vector6Message
//--------------------------------------------------------

/*
 * A message class depicting 6 DOF coordinates:
 */
class Vector6Message : public NeMALA::MessagePropertyTree
{
public:

	//-------------- Type Definitions --------------------

	typedef struct
	{
		double dX;
		double dY;
		double dZ;
		double dYaw;
		double dPitch;
		double dRoll;
	}Coordinate;

	//-------------------------- Methods ------------------------------------
	/*
	 * Init class variables.
	 * Publishers should use this function.
	 */
	Vector6Message(double dX, double dY, double dZ, double dYaw, double dPitch, double dRoll):
		m_dX(dX), m_dY(dY), m_dZ(dZ), m_dYaw(dYaw), m_dPitch(dPitch), m_dRoll(dRoll)
	{}
	Vector6Message(Coordinate &coordinate):
		m_dX(coordinate.dX), m_dY(coordinate.dY), m_dZ(coordinate.dZ),
		m_dYaw(coordinate.dYaw), m_dPitch(coordinate.dPitch), m_dRoll(coordinate.dRoll)
	{}

	/*
	 * Build a message from a property tree.
	 * Subscribers should use this function.
	 * @param pt: The property tree received from a publisher which translated to message.
	 */
	Vector6Message(NeMALA::Proptree pt):
		m_dX(pt.get<double>("X")),
		m_dY(pt.get<double>("Y")),
		m_dZ(pt.get<double>("Z")),
		m_dYaw(pt.get<double>("Yaw")),
		m_dPitch(pt.get<double>("Pitch")),
		m_dRoll(pt.get<double>("Roll"))
	{}

	~Vector6Message(){}

	/*
	 * Synchronize the private members of this class
	 */
	void BuildMessage()
	{
		AddElementNumber("X", m_dX);
		AddElementNumber("Y", m_dY);
		AddElementNumber("Z", m_dZ);
		AddElementNumber("Yaw", m_dYaw);
		AddElementNumber("Pitch", m_dPitch);
		AddElementNumber("Roll", m_dRoll);

	}

	/*
	 * Getters in order to return the member variables of this class.
	 * The subscribers use this function.
	 */
	double GetX() const {return m_dX;}
	double GetY() const {return m_dY;}
	double GetZ() const {return m_dZ;}
	double GetYaw() const {return m_dYaw;}
	double GetPitch() const {return m_dPitch;}
	double GetRoll() const {return m_dRoll;}

	/*
	 * Setters in order to set the member variables of this class.
	 * The publishers use this function.
	 */
	void SetX(double dX){m_dX = dX;}
	void SetY(double dY){m_dY = dY;}
	void SetZ(double dZ){m_dZ = dZ;}
	void SetYaw(double dYaw){m_dYaw = dYaw;}
	void SetPitch(double dPitch){m_dPitch = dPitch;}
	void SetRoll(double dRoll){m_dRoll = dRoll;}

private:
	 //-------------- Variables --------------------
	double m_dX;
	double m_dY;
	double m_dZ;
	double m_dYaw;
	double m_dPitch;
	double m_dRoll;
};

} // ros_alate_interfaces

#endif // _ROS_ALATE_INTERFACES_6DOF_MESSAGE_H_
