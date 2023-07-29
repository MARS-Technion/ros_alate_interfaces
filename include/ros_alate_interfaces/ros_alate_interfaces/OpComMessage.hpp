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

#ifndef _ROS_ALATE_INTERFACES_OPERATOR_COMMAND_MESSAGE_H_
#define _ROS_ALATE_INTERFACES_OPERATOR_COMMAND_MESSAGE_H_

#include <NeMALA/MessagePropertyTree.h>

namespace ros_alate_interfaces {

//--------------------------------------------------------
// 						Class OpComMessage
//--------------------------------------------------------

/*
 * A message class encapsulating an operator command:
 */
class OpComMessage : public NeMALA::MessagePropertyTree
{
public:

	//-------------- Constants --------------------
	typedef enum
	{
		OpCommandNone=0,
		OpCommandTakeoff,
		OpCommandLand,
		OpCommandGoHome,
		OpCommandSetDirection,
		OpCommandAux
	}OpCommandEnum;


	//-------------------------- Methods ------------------------------------
	/*
	 * Init class variables.
	 * Publishers should use this function.
	 */
	OpComMessage(OpCommandEnum eCommand):m_eCommand(eCommand){}

	/*
	 * Build a message from a property tree.
	 * Subscribers should use this function.
	 * @param pt: The property tree received from a publisher which translated to message.
	 */
	OpComMessage(NeMALA::Proptree pt):
		m_eCommand((OpCommandEnum)pt.get<double>("Command")){}

	~OpComMessage(){}

	/*
	 * Synchronize the private members of this class
	 */
	void BuildMessage()
	{
		AddElementNumber("Command", m_eCommand);
	}

	/*
	 * Getters in order to return the member variables of this class.
	 * The subscribers use this function.
	 */
	OpCommandEnum GetValue() {return m_eCommand;}

private:
	 //-------------- Variables --------------------
	OpCommandEnum m_eCommand;
};

} // namespace ros_alate_interfaces


#endif /* _ROS_ALATE_INTERFACES_OPERATOR_COMMAND_MESSAGE_H_ */
