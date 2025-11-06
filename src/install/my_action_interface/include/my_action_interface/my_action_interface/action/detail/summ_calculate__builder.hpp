// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_action_interface:action/SummCalculate.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_action_interface/action/summ_calculate.hpp"


#ifndef MY_ACTION_INTERFACE__ACTION__DETAIL__SUMM_CALCULATE__BUILDER_HPP_
#define MY_ACTION_INTERFACE__ACTION__DETAIL__SUMM_CALCULATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_action_interface/action/detail/summ_calculate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_action_interface
{

namespace action
{

namespace builder
{

class Init_SummCalculate_Goal_b
{
public:
  explicit Init_SummCalculate_Goal_b(::my_action_interface::action::SummCalculate_Goal & msg)
  : msg_(msg)
  {}
  ::my_action_interface::action::SummCalculate_Goal b(::my_action_interface::action::SummCalculate_Goal::_b_type arg)
  {
    msg_.b = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_action_interface::action::SummCalculate_Goal msg_;
};

class Init_SummCalculate_Goal_a
{
public:
  Init_SummCalculate_Goal_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SummCalculate_Goal_b a(::my_action_interface::action::SummCalculate_Goal::_a_type arg)
  {
    msg_.a = std::move(arg);
    return Init_SummCalculate_Goal_b(msg_);
  }

private:
  ::my_action_interface::action::SummCalculate_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_action_interface::action::SummCalculate_Goal>()
{
  return my_action_interface::action::builder::Init_SummCalculate_Goal_a();
}

}  // namespace my_action_interface


namespace my_action_interface
{

namespace action
{

namespace builder
{

class Init_SummCalculate_Result_success
{
public:
  Init_SummCalculate_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_action_interface::action::SummCalculate_Result success(::my_action_interface::action::SummCalculate_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_action_interface::action::SummCalculate_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_action_interface::action::SummCalculate_Result>()
{
  return my_action_interface::action::builder::Init_SummCalculate_Result_success();
}

}  // namespace my_action_interface


namespace my_action_interface
{

namespace action
{

namespace builder
{

class Init_SummCalculate_Feedback_left_to_result
{
public:
  Init_SummCalculate_Feedback_left_to_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_action_interface::action::SummCalculate_Feedback left_to_result(::my_action_interface::action::SummCalculate_Feedback::_left_to_result_type arg)
  {
    msg_.left_to_result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_action_interface::action::SummCalculate_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_action_interface::action::SummCalculate_Feedback>()
{
  return my_action_interface::action::builder::Init_SummCalculate_Feedback_left_to_result();
}

}  // namespace my_action_interface


namespace my_action_interface
{

namespace action
{

namespace builder
{

class Init_SummCalculate_SendGoal_Request_goal
{
public:
  explicit Init_SummCalculate_SendGoal_Request_goal(::my_action_interface::action::SummCalculate_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::my_action_interface::action::SummCalculate_SendGoal_Request goal(::my_action_interface::action::SummCalculate_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_action_interface::action::SummCalculate_SendGoal_Request msg_;
};

class Init_SummCalculate_SendGoal_Request_goal_id
{
public:
  Init_SummCalculate_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SummCalculate_SendGoal_Request_goal goal_id(::my_action_interface::action::SummCalculate_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_SummCalculate_SendGoal_Request_goal(msg_);
  }

private:
  ::my_action_interface::action::SummCalculate_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_action_interface::action::SummCalculate_SendGoal_Request>()
{
  return my_action_interface::action::builder::Init_SummCalculate_SendGoal_Request_goal_id();
}

}  // namespace my_action_interface


namespace my_action_interface
{

namespace action
{

namespace builder
{

class Init_SummCalculate_SendGoal_Response_stamp
{
public:
  explicit Init_SummCalculate_SendGoal_Response_stamp(::my_action_interface::action::SummCalculate_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::my_action_interface::action::SummCalculate_SendGoal_Response stamp(::my_action_interface::action::SummCalculate_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_action_interface::action::SummCalculate_SendGoal_Response msg_;
};

class Init_SummCalculate_SendGoal_Response_accepted
{
public:
  Init_SummCalculate_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SummCalculate_SendGoal_Response_stamp accepted(::my_action_interface::action::SummCalculate_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_SummCalculate_SendGoal_Response_stamp(msg_);
  }

private:
  ::my_action_interface::action::SummCalculate_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_action_interface::action::SummCalculate_SendGoal_Response>()
{
  return my_action_interface::action::builder::Init_SummCalculate_SendGoal_Response_accepted();
}

}  // namespace my_action_interface


namespace my_action_interface
{

namespace action
{

namespace builder
{

class Init_SummCalculate_SendGoal_Event_response
{
public:
  explicit Init_SummCalculate_SendGoal_Event_response(::my_action_interface::action::SummCalculate_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::my_action_interface::action::SummCalculate_SendGoal_Event response(::my_action_interface::action::SummCalculate_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_action_interface::action::SummCalculate_SendGoal_Event msg_;
};

class Init_SummCalculate_SendGoal_Event_request
{
public:
  explicit Init_SummCalculate_SendGoal_Event_request(::my_action_interface::action::SummCalculate_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_SummCalculate_SendGoal_Event_response request(::my_action_interface::action::SummCalculate_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SummCalculate_SendGoal_Event_response(msg_);
  }

private:
  ::my_action_interface::action::SummCalculate_SendGoal_Event msg_;
};

class Init_SummCalculate_SendGoal_Event_info
{
public:
  Init_SummCalculate_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SummCalculate_SendGoal_Event_request info(::my_action_interface::action::SummCalculate_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SummCalculate_SendGoal_Event_request(msg_);
  }

private:
  ::my_action_interface::action::SummCalculate_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_action_interface::action::SummCalculate_SendGoal_Event>()
{
  return my_action_interface::action::builder::Init_SummCalculate_SendGoal_Event_info();
}

}  // namespace my_action_interface


namespace my_action_interface
{

namespace action
{

namespace builder
{

class Init_SummCalculate_GetResult_Request_goal_id
{
public:
  Init_SummCalculate_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_action_interface::action::SummCalculate_GetResult_Request goal_id(::my_action_interface::action::SummCalculate_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_action_interface::action::SummCalculate_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_action_interface::action::SummCalculate_GetResult_Request>()
{
  return my_action_interface::action::builder::Init_SummCalculate_GetResult_Request_goal_id();
}

}  // namespace my_action_interface


namespace my_action_interface
{

namespace action
{

namespace builder
{

class Init_SummCalculate_GetResult_Response_result
{
public:
  explicit Init_SummCalculate_GetResult_Response_result(::my_action_interface::action::SummCalculate_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::my_action_interface::action::SummCalculate_GetResult_Response result(::my_action_interface::action::SummCalculate_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_action_interface::action::SummCalculate_GetResult_Response msg_;
};

class Init_SummCalculate_GetResult_Response_status
{
public:
  Init_SummCalculate_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SummCalculate_GetResult_Response_result status(::my_action_interface::action::SummCalculate_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_SummCalculate_GetResult_Response_result(msg_);
  }

private:
  ::my_action_interface::action::SummCalculate_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_action_interface::action::SummCalculate_GetResult_Response>()
{
  return my_action_interface::action::builder::Init_SummCalculate_GetResult_Response_status();
}

}  // namespace my_action_interface


namespace my_action_interface
{

namespace action
{

namespace builder
{

class Init_SummCalculate_GetResult_Event_response
{
public:
  explicit Init_SummCalculate_GetResult_Event_response(::my_action_interface::action::SummCalculate_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::my_action_interface::action::SummCalculate_GetResult_Event response(::my_action_interface::action::SummCalculate_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_action_interface::action::SummCalculate_GetResult_Event msg_;
};

class Init_SummCalculate_GetResult_Event_request
{
public:
  explicit Init_SummCalculate_GetResult_Event_request(::my_action_interface::action::SummCalculate_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_SummCalculate_GetResult_Event_response request(::my_action_interface::action::SummCalculate_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SummCalculate_GetResult_Event_response(msg_);
  }

private:
  ::my_action_interface::action::SummCalculate_GetResult_Event msg_;
};

class Init_SummCalculate_GetResult_Event_info
{
public:
  Init_SummCalculate_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SummCalculate_GetResult_Event_request info(::my_action_interface::action::SummCalculate_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SummCalculate_GetResult_Event_request(msg_);
  }

private:
  ::my_action_interface::action::SummCalculate_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_action_interface::action::SummCalculate_GetResult_Event>()
{
  return my_action_interface::action::builder::Init_SummCalculate_GetResult_Event_info();
}

}  // namespace my_action_interface


namespace my_action_interface
{

namespace action
{

namespace builder
{

class Init_SummCalculate_FeedbackMessage_feedback
{
public:
  explicit Init_SummCalculate_FeedbackMessage_feedback(::my_action_interface::action::SummCalculate_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::my_action_interface::action::SummCalculate_FeedbackMessage feedback(::my_action_interface::action::SummCalculate_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_action_interface::action::SummCalculate_FeedbackMessage msg_;
};

class Init_SummCalculate_FeedbackMessage_goal_id
{
public:
  Init_SummCalculate_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SummCalculate_FeedbackMessage_feedback goal_id(::my_action_interface::action::SummCalculate_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_SummCalculate_FeedbackMessage_feedback(msg_);
  }

private:
  ::my_action_interface::action::SummCalculate_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_action_interface::action::SummCalculate_FeedbackMessage>()
{
  return my_action_interface::action::builder::Init_SummCalculate_FeedbackMessage_goal_id();
}

}  // namespace my_action_interface

#endif  // MY_ACTION_INTERFACE__ACTION__DETAIL__SUMM_CALCULATE__BUILDER_HPP_
