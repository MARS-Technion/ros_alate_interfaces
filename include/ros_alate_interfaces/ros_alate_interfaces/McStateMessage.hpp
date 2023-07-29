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

#ifndef _ROS_ALATE_INTERFACES_MC_STATE_MESSAGE_H_
#define _ROS_ALATE_INTERFACES_MC_STATE_MESSAGE_H_

#include <NeMALA/MessagePropertyTree.h>

namespace ros_alate_interfaces {

//--------------------------------------------------------
// 						Class McStateMessage
//--------------------------------------------------------

/*
 * A message class depicting the Mission Control Module (MCM) states:
 */
class McStateMessage : public NeMALA::MessagePropertyTree
{
public:

	//-------------- Constants --------------------
	typedef enum
	{
		McStateNone=0,
		McStateInit,
		McStateStandby,
		McStateTakingoff,
		McStatePerformingMission,
		McStateLanding,
		McStateManual,
		McStateReturnToLaunch,
		McStateNoError,
		McStateError
	}McStateEnum;


	//-------------------------- Methods ------------------------------------
	/*
	 * Init class variables.
	 * Publishers should use this function.
	 */
	McStateMessage(McStateEnum eState):m_eState(eState){}

	/*
	 * Build a message from a property tree.
	 * Subscribers should use this function.
	 * @param pt: The property tree received from a publisher which translated to message.
	 */
	McStateMessage(NeMALA::Proptree pt):
		m_eState((McStateEnum)pt.get<double>("State")){}

	~McStateMessage(){}

	/*
	 * Synchronize the private members of this class
	 */
	void BuildMessage()
	{
		AddElementNumber("State", m_eState);
	}

	/*
	 * Getters in order to return the member variables of this class.
	 * The subscribers use this function.
	 */
	McStateEnum GetValue() const {return m_eState;}

	std::string GetName()
	{
		std::string strResult;
		switch(m_eState)
		{
			case McStateNone:
				strResult = "None";
				break;
			case McStateInit:
				strResult = "Init";
				break;
			case McStateStandby:
				strResult = "Standby";
				break;
			case McStateTakingoff:
				strResult = "Takingoff";
				break;
			case McStatePerformingMission:
				strResult = "Mission";
				break;
			case McStateLanding:
				strResult = "Landing";
				break;
			case McStateManual:
				strResult = "Manual";
				break;
			case McStateReturnToLaunch:
				strResult = "Return to Launch";
				break;
			case McStateNoError:
				strResult = "No Error";
				break;
			case McStateError:
				strResult = "Error!";
				break;
			default:
				strResult = "Unknown State!";
				break;
		}
		return strResult;
	}

private:
	 //-------------- Variables --------------------
	McStateEnum m_eState;
};

} //namespace ros_alate_interfaces

#endif /* _ROS_ALATE_INTERFACES_MC_STATE_MESSAGE_H_ */
