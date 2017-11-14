#ifndef __ROS_NODE_H_
#define __ROS_NODE_H_

/* ros */
#include <ros.h>
/* inlcude ros message types*/
#include <std_msgs/Int8.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Twist.h>
/* inlcude ros related class */
//#include <examples/class.h>
#include <sensors/encoder/encoder.h>
#include <sensors/imu/imu_mpu9250.h>
//define the duty
#define MAX_DUTY 54000 //forward
#define NEU_DUTY 40500 //neutral mid
#define MIN_DUTY 27000 //backward

class RosNode
{
public:
	RosNode(ros::NodeHandle* nh)
{
		/* ros node initialize */
		nh_ = nh;

		/* ros publisher initialize */
		radioflag_pub_ = new ros::Publisher("radioflag",&radioflag_msg);
		odom_pub_ = new ros::Publisher("odometry/raw",&odom_msg);
		//publish the msgs
		nh_->advertise(*radioflag_pub_);
		nh_->advertise(*odom_pub_);

		/* ros subscriber initialize */


};
	~RosNode(){};

	/* ros node handle */
	ros::NodeHandle  *nh_;
	/* ros publisher */
	ros::Publisher* radioflag_pub_; //radioflag_pub_
	ros::Publisher* odom_pub_;  //odometry pub: twist message
	/*  ros msgs */
	std_msgs::Int8 radioflag_msg;
	geometry_msgs::Twist odom_msg;

private:
	/* aim linear and angular speed */
	float aim_linear_spd = 0;
	float aim_angular_spd = 0;
	uint16_t LMotor_duty = NEU_DUTY;
	uint16_t RMotor_duty = NEU_DUTY;
	//to avoid fall down, the acceleration and brake need to be very slow
	//reduce the Kp_l and encrease the Kd_l

	/* ros subscibers */

	/* ros call back function */

};
#endif

